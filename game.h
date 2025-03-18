#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "graphic.h"
#include "bird.h"
#include "pipe.h"
#include "phong_chu.h"

using namespace std;

bool KiemTraToaDoChuot(int mouseX, int mouseY, SDL_Rect button);
void RePlayOrExit(bool &TraVe);
void initGame();
void resetGame();
void runGame();

void closeGame();

#endif
