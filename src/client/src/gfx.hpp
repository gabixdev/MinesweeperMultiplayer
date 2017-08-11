#pragma once

#include <SDL.h>
#include "msmp_client.hpp"

namespace MSMP::Client
{
    class Graphics
    {
        private:
            SDL_Window *window = nullptr;
            SDL_Renderer *renderer = nullptr;

        public:
            void Init();

            void Draw();

            void CleanUp();
    };

    typedef std::shared_ptr<Graphics> GraphicsT;
}