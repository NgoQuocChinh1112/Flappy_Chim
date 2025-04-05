#include "bird.h"
#include "graphic.h"
#include "phong_chu.h"

using namespace std;

float Count = 0;
double gravity = 0.39;

void resetgravity(){
    gravity = 0.39;
}
SDL_Rect birdFrames[4] = {
    {0, 0, BIRD_WIDTH, BIRD_HEIGHT},
    {0, BIRD_HEIGHT, BIRD_WIDTH, BIRD_HEIGHT},
    {0, BIRD_HEIGHT*2, BIRD_WIDTH, BIRD_HEIGHT},
    {0, BIRD_HEIGHT*3, BIRD_WIDTH, BIRD_HEIGHT}
};

void initBird(Bird &bird){
    bird.x = 150;
    bird.y = 250;
    bird.vtoc = 0;
}
void updateBird(Bird &bird){
    if(score == 5) gravity = 0.4;
    if(score == 10) gravity = 0.41;
    if(score == 15) gravity = 0.42;
    if(score == 20) gravity = 0.43;
    if(score == 25) gravity = 0.44;
    if(score == 30) gravity = 0.45;
    if(score == 35) gravity = 0.46;
    if(score == 40) gravity = 0.47;
    if(score == 45) gravity = 0.48;
    if(score == 50) gravity = 0.49;
    bird.vtoc += gravity;
    bird.y +=bird.vtoc;
}
void resetCount(){
    Count = 0;
}
int updateFames(){
    Count += 0.2;
    if(Count >= 3) Count = 0;
    return (int)Count;
}
void renderBird(SDL_Renderer* renderer, SDL_Texture* birdTexture, Bird &bird, int Count_Copy){
    double angle = bird.vtoc*5;
    if(angle > 50) angle = 50;
    if(angle < -50) angle = -50;
    SDL_Rect birdRect = {bird.x, bird.y, BIRD_WIDTH, BIRD_HEIGHT};
    SDL_RenderCopyEx(renderer, birdTexture, &birdFrames[Count_Copy], &birdRect, angle, NULL, SDL_FLIP_NONE);
}
