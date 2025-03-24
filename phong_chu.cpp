#include "phong_chu.h"
#include "graphic.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int score = 0;
TTF_Font* font = nullptr;
string HIGHSCORE_FILE = "highscore.txt";

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
void resetScore(){
    score = 0;
}
void renderScore(SDL_Renderer* renderer, int x, int y){
    SDL_Color white = {255, 255, 255};
    string scoreText = to_string(score);

    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText.c_str(), white);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = {x, y, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
void closeScore(){
    TTF_CloseFont(font);
    TTF_Quit();
}

int loadHighScore(){
    ifstream file(HIGHSCORE_FILE);
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}
void saveHighScore(int score) {
    ofstream file(HIGHSCORE_FILE);
    if (file.is_open()) {
        file << score;
        file.close();
    }
}
int FindScoreBest(){
    int HighScore_old = loadHighScore();
    int Score_new = score;
    if(Score_new > HighScore_old) {
        saveHighScore(Score_new);
        return Score_new;
    }
    return HighScore_old;
}
