#include "sound.h"

void FlappyWing(){
    Mix_Chunk* Wing = Mix_LoadWAV("audio_wing.wav");
    Mix_PlayChannel(-1, Wing, 0);
}
void FlappyPoint(){
    Mix_Chunk* Point = Mix_LoadWAV("audio_point.wav");
    Mix_PlayChannel(-1, Point, 0);
}
void FlappyHit(){
    Mix_Chunk* Hit = Mix_LoadWAV("audio_hit.wav");
    Mix_PlayChannel(-1, Hit, 0);
}
