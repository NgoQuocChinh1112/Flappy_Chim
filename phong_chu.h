#ifndef PHONG_CHU
#define PHONG_CHU

#include <SDL.h>
#include <SDL_ttf.h>

extern int score;

bool initScore(SDL_Renderer* renderer);
void increaseScore();
void renderScore(SDL_Renderer* renderer);
void closeScore();

#endif // PHONG_CHU
