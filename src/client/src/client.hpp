#pragma once

#include <SDL.h>
#include "msmp_client.hpp"

namespace MSMP::Client
{
    // Type declaration
    class Client;

    typedef std::shared_ptr<Client> ClientT;

    // Dependencies
    class Graphics;

    // Class body
    class Client
    {
        private:
            bool runningState = false;
            bool closeRequested = false;
            std::shared_ptr<Graphics> graphics = nullptr;

            void HandleEvent(const SDL_Event &event);

        public:
            void Start();

            void Update();

            void CleanUp();

            void RequestClose();

            bool IsRunning();

            // STATIC INSTANCE ACCESS
            static void Set(ClientT client);

            static ClientT Get();
    };
}