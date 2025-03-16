#ifndef PIPE_H
#define PIPE_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Pipe{
    SDL_Texture* pipe1;
    SDL_Texture* pipe2;
    int pipe_x, pipe_y;
    bool pass ;
    Pipe(){
        pass = false;
    }
};
void CreatePipe(vector<Pipe> &pipes, SDL_Renderer* renderer);
void updatePipes(vector<Pipe> &pipes, int Size);
void renderPipes(SDL_Renderer* renderer, vector<Pipe> &pipes);
bool KiemTraVaCham(SDL_Rect &birdRect, vector<Pipe> &pipes);
bool KTVaChamMatDat(SDL_Rect &birdRect, SDL_Rect &grRect1, SDL_Rect &grRect2);

#endif // PIPE_H
