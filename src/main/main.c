#include <stdbool.h>
#include "../utils/renderer.h"
#include "game.h"
#include "input.h"
#include "level.h"
#include "../audio/files/audio.h"

int main(int argc, char** argv) {
    initializeAudio();

    // Load the WAV file
    loadWAVFile(BEGINNING_PATH, &wav_spec, &wav_buffer, &wav_length);

    // Set the audio callback
    setAudioCallback(&wav_spec);

    // Open the audio device
    openAudioDevice(&wav_spec);

    // Set our global static variables
    audio_pos = wav_buffer; // copy sound buffer
    audio_len = wav_length; // copy file length

    // Play audio
    playAudio();

    // Init SDL
    initSDL();

    // Init SDL game window
    initWindow();

    // Init game graphics
    initGraphics();

    // Start the main menu
    startMainMenu();

    // Free resources and quit SDL
    freeSDL();

    closeAudio();

    return 0;
}
