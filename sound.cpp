#include "sound.h"

void FlappyWing(){
    Mix_Chunk* Wing = Mix_LoadWAV("audio_wing.wav");
    Mix_PlayChannel(-1, Wing, 0);
}
