#ifndef BIRD_H
#define BIRD_H

#include <SDL.h>
#include <SDL_image.h>

struct Bird{
    int x, y;
    float vtoc;
};
void resetgravity();
void initBird(Bird &bird);
void updateBird(Bird &bird);
void resetCount();
int updateFames();
void renderBird(SDL_Renderer* renderer, SDL_Texture* texture, Bird &bird, int Count_Copy);

#endif // BIRD_H
