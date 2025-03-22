#include "game.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* background;
SDL_Texture* ground;
SDL_Texture* birdTexture;
SDL_Texture* gameover;
SDL_Texture* ChuLogo;
SDL_Texture* RePlay1;
SDL_Texture* RePlay2;
SDL_Texture* Exit1;
SDL_Texture* Exit2;
SDL_Texture* Play1;
SDL_Texture* Play2;
SDL_Texture* Quit1;
SDL_Texture* Quit2;

Bird bird;
vector<Pipe> pipes;
SDL_Rect overRect = {75, 100, 250, 125};

int bgX = 0, gr_X = 0;
float Count = 0;
bool running = true, start = false;

bool KiemTraToaDoChuot(int mouseX, int mouseY, SDL_Rect button) {
    return (mouseX >= button.x && mouseX <= button.x + button.w &&
            mouseY >= button.y && mouseY <= button.y + button.h);
}
void RePlayOrExit(bool &TraVe){
    SDL_Rect RePlayRect = {50, 350, 100, 50};
    SDL_Rect ExitRect = {250, 350, 100, 50};

    int h = 0, k = 0;

    bool Run = true;
    SDL_Event c;

    while(Run){
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if(KiemTraToaDoChuot(mouseX, mouseY, RePlayRect)) SDL_RenderCopy(renderer, RePlay2, NULL, &RePlayRect);
        else SDL_RenderCopy(renderer, RePlay1, NULL, &RePlayRect);

        if(KiemTraToaDoChuot(mouseX, mouseY, ExitRect)) SDL_RenderCopy(renderer, Exit2, NULL, &ExitRect);
        else SDL_RenderCopy(renderer, Exit1, NULL, &ExitRect);

        if(SDL_PollEvent(&c)){
            if (c.type == SDL_QUIT){
                closeGame();
            }
            else if(c.type == SDL_MOUSEBUTTONDOWN) {
                    int clickX = c.button.x;
                    int clickY = c.button.y;

                    if (KiemTraToaDoChuot(clickX, clickY, RePlayRect)) {
                        TraVe = true;
                        break;
                    }
                    else if(KiemTraToaDoChuot(clickX, clickY, ExitRect)) {
                        TraVe = false;
                        break;
                    }
            }
        }
        SDL_RenderPresent(renderer);
    }
}

void initGame() {
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    renderer = createRenderer(window);
    background = loadTexture("bgDay.png", renderer);
    ground = loadTexture("baseLong.png", renderer);
    birdTexture = loadTexture("bird.png", renderer);
    gameover = loadTexture("gameover.png", renderer);
    ChuLogo = loadTexture("LogoChuFlappyBird.png", renderer);
    RePlay1 = loadTexture("RePlay1.png", renderer);
    RePlay2 = loadTexture("RePlay2.png", renderer);
    Exit1 = loadTexture("Exit1.png", renderer);
    Exit2 = loadTexture("Exit2.png", renderer);
    Play1 = loadTexture("Play1.png", renderer);
    Play2 = loadTexture("Play2.png", renderer);
    Quit1 = loadTexture("Quit1.png", renderer);
    Quit2 = loadTexture("Quit2.png", renderer);

    initBird(bird);
    initScore(renderer);
}
void resetGame(){
    initBird(bird);
    pipes.clear();
    Count = 0;
    bgX = 0;
    gr_X = 0;
    start = false;
}
void Menugame(){
    bool Trave;
    SDL_Rect grRect = {0, 500, 400, 100};
    SDL_Rect ChuLogoRect = {50, 50, 300, 100};
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderCopy(renderer, ground, NULL, &grRect);
    SDL_RenderCopy(renderer, ChuLogo, NULL, &ChuLogoRect);
    SDL_Rect PlayRect = {150, 250, 100, 50};
    SDL_Rect QuitRect = {150, 350, 100, 50};

    int h = 0, k = 0;

    bool Run = true;
    SDL_Event c;

    while(Run){
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if(KiemTraToaDoChuot(mouseX, mouseY, PlayRect)) SDL_RenderCopy(renderer, Play2, NULL, &PlayRect);
        else SDL_RenderCopy(renderer, Play1, NULL, &PlayRect);

        if(KiemTraToaDoChuot(mouseX, mouseY, QuitRect)) SDL_RenderCopy(renderer, Quit2, NULL, &QuitRect);
        else SDL_RenderCopy(renderer, Quit1, NULL, &QuitRect);

        if(SDL_PollEvent(&c)){
            if (c.type == SDL_QUIT){
                closeGame();
            }
            else if(c.type == SDL_MOUSEBUTTONDOWN) {
                    int clickX = c.button.x;
                    int clickY = c.button.y;

                    if (KiemTraToaDoChuot(clickX, clickY, PlayRect)) {
                        Trave = true;
                        break;
                    }
                    else if(KiemTraToaDoChuot(clickX, clickY, QuitRect)) {
                        Trave = false;
                        break;
                    }
            }
        }
        SDL_RenderPresent(renderer);
    }
    if(Trave) runGame();
    else closeGame();
}
void runGame(){
    SDL_Event event ;
    while(running){
        SDL_Rect bgRect1 = {bgX, 0, 400, 600};
        SDL_Rect bgRect2 = {bgX+400, 0, 400, 600};
        bgX -=3;
        if(bgX <= -400) bgX = 0;
        SDL_RenderCopy(renderer, background, NULL, &bgRect1);
        SDL_RenderCopy(renderer, background, NULL, &bgRect2);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) closeGame();
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
        SDL_Rect Rect_tmp = {bird.x, bird.y, BIRD_WIDTH, BIRD_HEIGHT};
        if(KiemTraVaCham(Rect_tmp, pipes) || KTVaChamMatDat(Rect_tmp, grRect1, grRect2) || bird.y < 0){
            SDL_RenderCopy(renderer, gameover, NULL, &overRect);
            SDL_RenderPresent(renderer);
            SDL_Delay(700);
            bool TraVe;
            RePlayOrExit(TraVe);
            if(TraVe){
                resetGame();
                resetScore();
            }
            else {
                resetGame();
                resetScore();
                Menugame();
            }
        }
        SDL_RenderPresent(renderer);
    }
}

void closeGame(){
    closeScore();
    for (Pipe tmp : pipes) {
        SDL_DestroyTexture(tmp.pipe1);
        SDL_DestroyTexture(tmp.pipe2);
    }
    SDL_DestroyTexture(gameover);
    SDL_DestroyTexture(birdTexture);
    SDL_DestroyTexture(background);
    quitSDL(window, renderer);
}
