#include "pipe.h"
#include "graphic.h"
#include "phong_chu.h"

using namespace std;

double pipeSpeed = 3;

void resetpipeSpeed(){
    pipeSpeed = 3;
}
void CreatePipe(vector<Pipe> &pipes, SDL_Renderer* renderer){
    Pipe newPipe ;
    newPipe.pipe_x = 400;
    newPipe.pipe_y = rand() % 210  - 430;
    newPipe.pipe1 = IMG_LoadTexture(renderer, "pipeTop.png");
    newPipe.pipe2 = IMG_LoadTexture(renderer, "pipeBottom.png");
    pipes.push_back(newPipe);
}
void updatePipes(vector<Pipe> &pipes, int Size){
    for(int i = 0; i < Size;++i){
        if(score == 8 ) pipeSpeed = 3.25;
        if(score == 16 ) pipeSpeed = 3.5;
        if(score == 24 ) pipeSpeed = 3.75;
        if(score == 32 ) pipeSpeed = 4;
        pipes[i].pipe_x -= pipeSpeed;

        if(pipes[i].pipe_x < -50){
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
bool KTVaChamMatDat(SDL_Rect &birdRect, SDL_Rect &grRect1, SDL_Rect &grRect2){
    if(SDL_HasIntersection(&birdRect, &grRect1) || SDL_HasIntersection(&birdRect, &grRect2)) return true;
    return false;
}
