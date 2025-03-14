#include "pipe.h"
#include "graphic.h"

using namespace std;

void CreatePipe(vector<Pipe> &pipes, SDL_Renderer* renderer){
    Pipe newPipe ;
    newPipe.pipe_x = 800;
    newPipe.pipe_y = rand() % 200  - 400;
    newPipe.pipe1 = IMG_LoadTexture(renderer, "pipe.png");
    newPipe.pipe2 = IMG_LoadTexture(renderer, "pipe.png");
    pipes.push_back(newPipe);
}
void updatePipes(vector<Pipe> &pipes, int Size){
    for(int i = 0; i < Size;++i){
        pipes[i].pipe_x -=3;

        if(pipes[i].pipe_x < -150){
            pipes.erase(pipes.begin() + i);
            i--;
        }
    }
}
void renderPipes(SDL_Renderer* renderer, vector<Pipe> &pipes){
    for(Pipe tmp : pipes){
        SDL_Rect pipeRect1 = {tmp.pipe_x, tmp.pipe_y, PIPE_WIDTH, PIPE_HEIGHT};
        SDL_Rect pipeRect2 = {tmp.pipe_x, tmp.pipe_y+PIPE_HEIGHT + 150, PIPE_WIDTH, PIPE_HEIGHT};
        SDL_RenderCopy(renderer, tmp.pipe1, NULL, &pipeRect1);
        SDL_RenderCopy(renderer, tmp.pipe2, NULL, &pipeRect2);
    }
}
bool KiemTraVaCham(SDL_Rect &birdRect, vector<Pipe> &pipes){
    for(Pipe tmp : pipes){
        SDL_Rect pipeRect1 = {tmp.pipe_x, tmp.pipe_y, PIPE_WIDTH, PIPE_HEIGHT};
        SDL_Rect pipeRect2 = {tmp.pipe_x, tmp.pipe_y+PIPE_HEIGHT + 150, PIPE_WIDTH, PIPE_HEIGHT};

        if(SDL_HasIntersection(&birdRect, &pipeRect1) || SDL_HasIntersection(&birdRect, &pipeRect2)) return true;
    }
    return false;
}
