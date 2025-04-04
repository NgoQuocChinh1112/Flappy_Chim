#ifndef PHONG_CHU
#define PHONG_CHU

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "graphic.h"

extern int score;

bool initScore(SDL_Renderer* renderer);
void increaseScore();
void resetScore();
void renderScore(SDL_Renderer* renderer, int x, int y, int score);
void closeScore();
int loadHighScore();
void saveHighScore(int score);
int FindScoreBest();
void renderScore_Best(SDL_Renderer* renderer, int Y);

#endif // PHONG_CHU
