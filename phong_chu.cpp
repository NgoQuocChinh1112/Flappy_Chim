#include "phong_chu.h"
#include <iostream>
#include <string>

using namespace std;

int score = 0;
TTF_Font* font = nullptr;

bool initScore(SDL_Renderer* renderer) {
    if (TTF_Init() == -1) {
        cout << "SDL_ttf khong khoi tao duoc! Error: " << TTF_GetError() << endl;
        return false;
    }
    font = TTF_OpenFont("flappy-font.ttf", 40);
    if (!font) {
        cout << "khong load duoc file! Error: " << TTF_GetError() << endl;
        return false;
    }
    return true;
}
void increaseScore(){
    score ++;
}
void renderScore(SDL_Renderer* renderer){
    SDL_Color white = {255, 255, 255};
    string scoreText = to_string(score);

    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText.c_str(), white);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = {190, 50, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, nullptr, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
void closeScore(){
    TTF_CloseFont(font);
    TTF_Quit();
}
