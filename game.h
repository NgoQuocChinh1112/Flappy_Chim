#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "graphic.h"
#include "bird.h"
#include "pipe.h"
#include "phong_chu.h"
#include "sound.h"

using namespace std;

bool KiemTraToaDoChuot(int mouseX, int mouseY, SDL_Rect button);
void renderScore_Best();
void RePlayOrExit(bool &TraVe);
void initGame();
void resetGame();
void Menugame();
void runGame();

void closeGame();

#endif
