#include "draw.h"

Draw::Draw(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    painting = false;
}

void Draw::setPainting(bool b)
{
    painting = b;
}

bool Draw::getPainting()
{
    return painting;
}

void Draw::paint(int x, int y)
{
    SDL_Rect tempRect = {x, y, 1, 1};
    pixels.push_back(tempRect);
}

void Draw::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (SDL_Rect pixel : pixels) {
        SDL_RenderFillRect(renderer, &pixel);
    }
}