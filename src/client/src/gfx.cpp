#include <SDL.h>

#include "gfx.hpp"
#include "client.hpp"
#include "shared/exception.hpp"

namespace MSMP::Client
{
    void Graphics::Init()
    {
        if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
        {
            MSMP_THROW_DETAILED("Failed to initialize SDL video", SDL_GetError());
        }

        this->window = SDL_CreateWindow("Ziemniaki", 100, 100, 1000, 500, SDL_WINDOW_SHOWN);

        if (this->window == nullptr)
        {
            MSMP_THROW_DETAILED("Failed to create an SDL window", SDL_GetError());
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    void Graphics::Draw()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xff, 0, 0, 0);
        SDL_RenderDrawLine(renderer, 10, 10, 20, 60);
        SDL_RenderPresent(renderer);
    }

    void Graphics::CleanUp()
    {
        if (this->renderer != nullptr)
        {
            SDL_DestroyRenderer(this->renderer);
        }

        if (this->window != nullptr)
        {
            SDL_DestroyWindow(this->window);
        }

        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}