#ifndef BIRD_H
#define BIRD_H

#include <SDL.h>
#include <SDL_image.h>

struct Bird{
    int x, y;
    double vtoc;
};
void initBird(Bird &bird);
void updateBird(Bird &bird);
void renderBird(SDL_Renderer* renderer, SDL_Texture* texture, Bird &bird, float &Count);

#endif // BIRD_H
