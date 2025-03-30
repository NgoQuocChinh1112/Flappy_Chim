#include "game.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* background;
SDL_Texture* ground;
SDL_Texture* Texture_Coin;
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
SDL_Texture* Comment1;
SDL_Texture* Comment2;

Bird bird;
vector<Pipe> pipes;
SDL_Rect overRect = {75, 60, 250, 125};
SDL_Rect Texture_CoinRect = {10, 33, 30, 30};
int bgX = 0, gr_X = 0;
int Count_Copy = 0;
bool running = true, start = false;

bool KiemTraToaDoChuot(int mouseX, int mouseY, SDL_Rect button) {
    return (mouseX >= button.x && mouseX <= button.x + button.w &&
            mouseY >= button.y && mouseY <= button.y + button.h);
}

void initGame() {
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    renderer = createRenderer(window);
    background = loadTexture("bgDay.png", renderer);
    ground = loadTexture("baseLong.png", renderer);
    Texture_Coin = loadTexture("texture_coin.png", renderer);
    birdTexture = loadTexture("bird.png", renderer);
    gameover = loadTexture("gameover.png", renderer);
    ChuLogo = loadTexture("LogoChuFlappyChim.png", renderer);
    RePlay1 = loadTexture("RePlay1.png", renderer);
    RePlay2 = loadTexture("RePlay2.png", renderer);
    Exit1 = loadTexture("Exit1.png", renderer);
    Exit2 = loadTexture("Exit2.png", renderer);
    Play1 = loadTexture("Play1.png", renderer);
    Play2 = loadTexture("Play2.png", renderer);
    Quit1 = loadTexture("Quit1.png", renderer);
    Quit2 = loadTexture("Quit2.png", renderer);
    Comment1 = loadTexture("comment1.png", renderer);
    Comment2 = loadTexture("comment2.png", renderer);

    initBird(bird);
    initScore(renderer);
}

void RePlayOrExit(bool &TraVe){
                FlappyHit();
                Mix_HaltMusic();
                FlappyDie();
                SDL_Delay(300);
    SDL_Rect bgRect_tmp1 = {bgX, 0, 400, 600};
    SDL_Rect bgRect_tmp2 = {bgX+400, 0, 400, 600};
    SDL_Rect grRect_tmp1 = {gr_X, 500, 420, 100};
    SDL_Rect grRect_tmp2 = {gr_X+400, 500, 420, 100};
    int StartY = 600, TargetY = 200;
    FlappySwoosh();
    while(StartY >= TargetY){
        SDL_RenderCopy(renderer, background, NULL, &bgRect_tmp1);
        SDL_RenderCopy(renderer, background, NULL, &bgRect_tmp2);
        renderPipes(renderer, pipes);
        renderBird(renderer, birdTexture, bird, Count_Copy);
        SDL_RenderCopy(renderer, ground, NULL, &grRect_tmp1);
        SDL_RenderCopy(renderer, ground, NULL, &grRect_tmp2);
        SDL_RenderCopy(renderer, Texture_Coin, NULL, &Texture_CoinRect);
        renderScore(renderer, 50, 30, score);
        SDL_RenderCopy(renderer, gameover, NULL, &overRect);
        SDL_RenderCopy(renderer, gameover, NULL, &overRect);
        renderScore_Best(renderer, StartY);
        if(bird.y < 500-BIRD_HEIGHT) bird.y += 15;
        StartY -= 10;
        SDL_RenderPresent(renderer);
    }
            renderScore(renderer, 138, 275, score);
            int score_best = FindScoreBest();
            renderScore(renderer, 250, 250, score_best);
            SDL_RenderPresent(renderer);
            SDL_Delay(700);
    SDL_Rect RePlayRect = {50, 420, 100, 50};
    SDL_Rect ExitRect = {250, 420, 100, 50};
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

                    if (KiemTraToaDoChuot(clickX, clickY, RePlayRect)) { SoundClick();
                        TraVe = true;
                        break;
                    }
                    else if(KiemTraToaDoChuot(clickX, clickY, ExitRect)) { FlappySwoosh();
                        TraVe = false;
                        break;
                    }
            }
        }
        SDL_RenderPresent(renderer);
    }
}
void resetGame(){
    initBird(bird);
    pipes.clear();
    resetCount();
    bgX = 0;
    gr_X = 0;
    start = false;
}
void Menugame(){
    SoundMenu();
    bool Trave;
    SDL_Rect grRect = {0, 500, 400, 100};
    SDL_Rect ChuLogoRect = {75, 40, 250, 185};

    SDL_Rect PlayRect = {150, 280, 100, 50};
    SDL_Rect QuitRect = {150, 360, 100, 50};
    SDL_Rect CommentRect = {20, 535, 30, 45};

    bool Run = true;
    SDL_Event c;

    while(Run){
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderCopy(renderer, ground, NULL, &grRect);
        SDL_RenderCopy(renderer, ChuLogo, NULL, &ChuLogoRect);
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if(KiemTraToaDoChuot(mouseX, mouseY, PlayRect)) SDL_RenderCopy(renderer, Play2, NULL, &PlayRect);
        else SDL_RenderCopy(renderer, Play1, NULL, &PlayRect);

        if(KiemTraToaDoChuot(mouseX, mouseY, QuitRect)) SDL_RenderCopy(renderer, Quit2, NULL, &QuitRect);
        else SDL_RenderCopy(renderer, Quit1, NULL, &QuitRect);

        if(KiemTraToaDoChuot(mouseX, mouseY, CommentRect)) SDL_RenderCopy(renderer, Comment2, NULL, &CommentRect);
        else SDL_RenderCopy(renderer, Comment1, NULL, &CommentRect);

        if(SDL_PollEvent(&c)){
            if (c.type == SDL_QUIT){
                closeGame();
            }
            else if(c.type == SDL_MOUSEBUTTONDOWN) {
                    int clickX = c.button.x;
                    int clickY = c.button.y;

                    if (KiemTraToaDoChuot(clickX, clickY, PlayRect)) {
                        SoundClick();
                        Trave = true;
                        Mix_HaltMusic();
                        break;
                    }
                    else if(KiemTraToaDoChuot(clickX, clickY, QuitRect)) {
                        FlappySwoosh();
                        SDL_Delay(400);
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
    SoundGame();
    SDL_Event event ;
    while(running){
        bgX -=3;
        SDL_Rect bgRect1 = {bgX, 0, 400, 600};
        SDL_Rect bgRect2 = {bgX+400, 0, 400, 600};
        if(bgX <= -400) bgX = 0;
        SDL_RenderCopy(renderer, background, NULL, &bgRect1);
        SDL_RenderCopy(renderer, background, NULL, &bgRect2);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) closeGame();
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
                bird.vtoc -= 10.0f;
                FlappyWing();
                start = true;
            }
        }
        if(start) updateBird(bird);
        Count_Copy = updateFames();
        renderBird(renderer, birdTexture, bird, Count_Copy);

        if(pipes.empty() || pipes.back().pipe_x < 200){
           CreatePipe(pipes, renderer);
        }
        if(start){
            int Size = pipes.size();
            updatePipes(pipes, Size);
            renderPipes(renderer, pipes);
        }
        gr_X -=3;
        SDL_Rect grRect1 = {gr_X, 500, 420, 100};
        SDL_Rect grRect2 = {gr_X+400, 500, 420, 100};
        if(gr_X <= -400) gr_X = 0;
        SDL_RenderCopy(renderer, ground, NULL, &grRect1);
        SDL_RenderCopy(renderer, ground, NULL, &grRect2);

        SDL_RenderCopy(renderer, Texture_Coin, NULL, &Texture_CoinRect);
        renderScore(renderer, 50, 30, score);
        for(auto &tmp : pipes){
            if(bird.x > tmp.pipe_x + BIRD_WIDTH && !tmp.pass){
                increaseScore();
                FlappyPoint();
                tmp.pass = true;
            }
        }
        SDL_Rect Rect_tmp = {bird.x, bird.y, BIRD_WIDTH, BIRD_HEIGHT};
        if(KiemTraVaCham(Rect_tmp, pipes) || KTVaChamMatDat(Rect_tmp, grRect1, grRect2) || bird.y < 0){
            bool TraVe;
            RePlayOrExit(TraVe);
            if(TraVe){
                resetGame();
                resetScore();
                SoundGame();
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
