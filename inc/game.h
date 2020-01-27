#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include "draw.h"

class Game {
public:
    Game();
    bool getRunning();
    void input();
    void render();
    void clean();
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    bool running;
    Draw* draw;
};

#endif