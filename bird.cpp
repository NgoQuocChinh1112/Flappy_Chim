#include "bird.h"
#include "graphic.h"

using namespace std;

void initBird(Bird &bird){
    bird.x = 150;
    bird.y = 250;
    bird.vtoc = 0;
}
void updateBird(Bird &bird){
    bird.vtoc += 0.3;
    bird.y +=bird.vtoc;
}
void renderBird(SDL_Renderer* renderer, SDL_Texture* birdTexture, Bird &bird, float &Count){
    double angle = bird.vtoc*5;
    if(angle > 40) angle = 40;
    if(angle < -40) angle = -40;
    SDL_Rect birdRect = {bird.x, bird.y, BIRD_WIDTH, BIRD_HEIGHT};
    SDL_Rect birdFrames[4] = {
        {0, 0, BIRD_WIDTH, BIRD_HEIGHT},
        {0, BIRD_HEIGHT, BIRD_WIDTH, BIRD_HEIGHT},
        {0, BIRD_HEIGHT*2, BIRD_WIDTH, BIRD_HEIGHT},
        {0, BIRD_HEIGHT*3, BIRD_WIDTH, BIRD_HEIGHT}
    };
    int Count_Copy = (int)Count;
    Count += 0.5;
    SDL_RenderCopyEx(renderer, birdTexture, &birdFrames[Count_Copy], &birdRect, angle, NULL, SDL_FLIP_NONE);
    if(Count >= 3) Count = 0;
}
