#include "audio.h"

Uint8 *audio_pos;
Uint32 audio_len;
Uint8 *wav_buffer;
SDL_AudioSpec wav_spec;
Uint32 wav_length;

void my_audio_callback(void *userdata, Uint8 *stream, int len) {
    if (audio_len == 0)
        return;

    len = (len > audio_len ? audio_len : len);
    SDL_memcpy(stream, audio_pos, len); // simply copy from one buffer into the other
    //SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME); // mix from one buffer into another

    audio_pos += len;
    audio_len -= len;
}

void initializeAudio() {
    // Initialize SDL audio
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "Failed to initialize SDL audio: %s\n", SDL_GetError());
        exit(1);
    }
}

void loadWAVFile(const char* filePath, SDL_AudioSpec* wav_spec, Uint8** wav_buffer, Uint32* wav_length) {
    /* Load the WAV */
    // the specs, length, and buffer of our wav are filled
    if (SDL_LoadWAV(filePath, wav_spec, wav_buffer, wav_length) == NULL) {
        fprintf(stderr, "Failed to load WAV file: %s\n", filePath);
        exit(1);
    }
}

void setAudioCallback(SDL_AudioSpec* wav_spec) {
    // Set the callback function
    wav_spec->callback = my_audio_callback;
    wav_spec->userdata = NULL;
}

void openAudioDevice(SDL_AudioSpec* wav_spec) {
    /* Open the audio device */
    if (SDL_OpenAudio(wav_spec, NULL) < 0) {
        fprintf(stderr, "Failed to open audio: %s\n", SDL_GetError());
        SDL_FreeWAV(wav_buffer);
        exit(1);
    }
}

void playAudio() {
    /* Start playing */
    SDL_PauseAudio(0);

    // Wait until we're done playing
    while (audio_len > 0) {
        SDL_Delay(100);
    }

    // Shut everything down
    SDL_CloseAudio();
    SDL_FreeWAV(wav_buffer);
}

void closeAudio() {
    // Quit SDL audio
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
    SDL_Quit();
}
