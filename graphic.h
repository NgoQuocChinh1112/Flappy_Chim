#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;
extern const char* WINDOW_TITLE ;

extern const int BIRD_WIDTH ;
extern const int BIRD_HEIGHT ;

extern const int PIPE_WIDTH ;
extern const int PIPE_HEIGHT ;

void logErrorAndExit(const char* msg, const char* error);
SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);
SDL_Renderer* createRenderer(SDL_Window* window);
SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void renderTexture(SDL_Texture* texture, int x, int y, int width, int height, SDL_Renderer* renderer);

#endif
