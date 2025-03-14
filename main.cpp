#include <iostream>
#include "graphic.h"
#include "bird.h"
#include "pipe.h"

using namespace std;

int main(int argc, char* argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);
    SDL_Texture* background = loadTexture("nen_flappy_bird2.png", renderer);
    int bgX = 0;

    SDL_Texture* birdTexture = loadTexture("bird.png", renderer);
    SDL_Texture* gameover = loadTexture("gameover.png", renderer);
    SDL_Rect overRect = {200, 100, 400, 300};

    Bird bird;
    initBird(bird);
    float Count = 0;
    vector<Pipe> pipes;

    bool running = true;
    SDL_Event event ;

    while(running){
        SDL_Rect bgRect1 = {bgX, 0, 800, 600};
        SDL_Rect bgRect2 = {bgX+800, 0, 800, 600};
        bgX -=3;
        if(bgX <= -800) bgX = 0;
        SDL_RenderCopy(renderer, background, NULL, &bgRect1);
        SDL_RenderCopy(renderer, background, NULL, &bgRect2);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) running = false;
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
                bird.vtoc -= 8;
            }
        }
        updateBird(bird);
        renderBird(renderer, birdTexture, bird, Count);

        if(bird.y > 560 || bird.y < 0){
            SDL_RenderCopy(renderer, gameover, NULL, &overRect);
            SDL_RenderPresent(renderer);
            break;
        }

        if(pipes.empty() || pipes.back().pipe_x < 500){
           CreatePipe(pipes, renderer);
        }
        int Size = pipes.size();
        updatePipes(pipes, Size);
        renderPipes(renderer, pipes);

        SDL_Rect Rect_tmp = {bird.x, bird.y, BIRD_WIDTH, BIRD_HEIGHT};
        if(KiemTraVaCham(Rect_tmp, pipes)){
            SDL_RenderCopy(renderer, gameover, NULL, &overRect);
            SDL_RenderPresent(renderer);
            break;
        }
        SDL_RenderPresent(renderer);
    }

    waitUntilKeyPressed();
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
