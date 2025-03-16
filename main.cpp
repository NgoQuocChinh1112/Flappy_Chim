#include <iostream>
#include "graphic.h"
#include "bird.h"
#include "pipe.h"
#include "phong_chu.h"

using namespace std;

int main(int argc, char* argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);
    SDL_Texture* background = loadTexture("background.png", renderer);
    int bgX = 0;
    SDL_Texture* ground = loadTexture("ground.png", renderer);
    int gr_X = 0;
    SDL_Texture* birdTexture = loadTexture("bird.png", renderer);
    SDL_Texture* gameover = loadTexture("gameover.png", renderer);
    SDL_Rect overRect = {75, 100, 250, 125};

    Bird bird;
    initBird(bird);
    float Count = 0;
    vector<Pipe> pipes;
    initScore(renderer);

    bool running = true;
    bool start = false;
    SDL_Event event ;

    while(running){
        SDL_Rect bgRect1 = {bgX, 0, 400, 600};
        SDL_Rect bgRect2 = {bgX+400, 0, 400, 600};
        bgX -=3;
        if(bgX <= -400) bgX = 0;
        SDL_RenderCopy(renderer, background, NULL, &bgRect1);
        SDL_RenderCopy(renderer, background, NULL, &bgRect2);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) running = false;
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
                bird.vtoc -= 10.0f;
                start = true;
            }
        }
        if(start) updateBird(bird);
        renderBird(renderer, birdTexture, bird, Count);

        if(pipes.empty() || pipes.back().pipe_x < 200){
           CreatePipe(pipes, renderer);
        }
        if(start){
            int Size = pipes.size();
            updatePipes(pipes, Size);
            renderPipes(renderer, pipes);
        }
        SDL_Rect grRect1 = {gr_X, 500, 420, 100};
        SDL_Rect grRect2 = {gr_X+400, 500, 420, 100};
        gr_X -=3;
        if(gr_X <= -400) gr_X = 0;
        SDL_RenderCopy(renderer, ground, NULL, &grRect1);
        SDL_RenderCopy(renderer, ground, NULL, &grRect2);

        renderScore(renderer);
        for(auto &tmp : pipes){
            if(bird.x > tmp.pipe_x + BIRD_WIDTH && !tmp.pass){
                increaseScore();
                tmp.pass = true;
            }
        }
        if(bird.y > 560 || bird.y < 0){
            SDL_RenderCopy(renderer, gameover, NULL, &overRect);
            SDL_RenderPresent(renderer);
            break;
        }
        SDL_Rect Rect_tmp = {bird.x, bird.y, BIRD_WIDTH, BIRD_HEIGHT};
        if(KiemTraVaCham(Rect_tmp, pipes)){
            SDL_RenderCopy(renderer, gameover, NULL, &overRect);
            SDL_RenderPresent(renderer);
            break;
        }
        if(KTVaChamMatDat(Rect_tmp, grRect1, grRect2)){
            SDL_RenderCopy(renderer, gameover, NULL, &overRect);
            SDL_RenderPresent(renderer);
            break;
        }
        SDL_RenderPresent(renderer);
    }
    waitUntilKeyPressed();
    closeScore();
    for(Pipe tmp : pipes){
        SDL_DestroyTexture(tmp.pipe1);
        SDL_DestroyTexture(tmp.pipe2);
    }
    SDL_DestroyTexture(gameover);
    SDL_DestroyTexture(birdTexture);
    SDL_DestroyTexture(background);

    quitSDL(window, renderer);

    return 0;
}
