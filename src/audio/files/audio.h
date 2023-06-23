#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BEGINNING_PATH "../src/audio/wav/pacman_beginning.wav"
#define CHOMP_PATH "../src/audio/wav/pacman_chomp.wav"
#define DEATH_PATH "../src/audio/wav/pacman_death.wav"
#define EATFRUIT_PATH "../src/audio/wav/pacman_eatfruit.wav"
#define EATGHOST_PATH "../src/audio/wav/pacman_eatghost.wav"
#define INTERMISSION_PATH "../src/audio/wav/pacman_intermission.wav"

extern Uint8 *audio_pos; // global pointer to the audio buffer to be played
extern Uint32 audio_len; // remaining length of the sample we have to play
extern Uint8 *wav_buffer; // buffer containing our audio file
extern SDL_AudioSpec wav_spec; // the specs of our piece of music
extern Uint32 wav_length; // length of our sample

void my_audio_callback(void *userdata, Uint8 *stream, int len);
void closeAudio();
void playAudio();
void openAudioDevice(SDL_AudioSpec* wav_spec);
void setAudioCallback(SDL_AudioSpec* wav_spec);
void loadWAVFile(const char* filePath, SDL_AudioSpec* wav_spec, Uint8** wav_buffer, Uint32* wav_length);
void initializeAudio();

#endif