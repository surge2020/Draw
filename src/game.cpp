#include "game.h"

Game::Game()
{
    window = SDL_CreateWindow(
        "Draw",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        500, 500, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    running = true;
    draw = new Draw(renderer);
}

bool Game::getRunning()
{
    return running;
}

void Game::input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            draw->setPainting(true);
            break;
        case SDL_MOUSEBUTTONUP:
            draw->setPainting(false);
        case SDL_MOUSEMOTION:
            if (draw->getPainting())
                draw->paint(event.motion.x, event.motion.y);
            break;
        default:
            break;
        }
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    draw->render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}