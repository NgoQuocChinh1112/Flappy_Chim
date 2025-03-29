#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "game.h"
#include "graphic.h"
#include "pipe.h"


void GameOver(SDL_Renderer* renderer, int Bg_X, vector<Pipe> &pipes, Bird &bird);

#endif // GAMEOVER_H
