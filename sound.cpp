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
void FlappySwoosh(){
    Mix_Chunk* Swoosh = Mix_LoadWAV("audio_swoosh.wav");
    Mix_VolumeChunk(Swoosh, MIX_MAX_VOLUME);
    Mix_PlayChannel(-1, Swoosh, 0);
}
void FlappyDie(){
    Mix_Chunk* Die = Mix_LoadWAV("audio_die.wav");
    Mix_VolumeChunk(Die, MIX_MAX_VOLUME);
    Mix_PlayChannel(-1, Die, 0);
}
void SoundClick(){
    Mix_Chunk* Click = Mix_LoadWAV("Soundclick.wav");
    Mix_VolumeChunk(Click, MIX_MAX_VOLUME);
    Mix_PlayChannel(-1, Click, 0);
}
void SoundGame(){
    Mix_Music* music = Mix_LoadMUS("SoundGame.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(30);
}
void SoundMenu(){
    Mix_Music* menu = Mix_LoadMUS("Soundmenu.mp3");
    Mix_PlayMusic(menu, -1);
    Mix_VolumeMusic(128);
}
