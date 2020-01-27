#ifndef DRAW
#define DRAW

#include <vector>
#include <SDL2/SDL.h>

class Draw {
public:
    Draw(SDL_Renderer* renderer);
    void setPainting(bool b);
    bool getPainting();
    void paint(int x, int y);
    void render();
private:
    SDL_Renderer* renderer;
    bool painting;
    std::vector<SDL_Rect> pixels;
};

#endif