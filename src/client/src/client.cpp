#include <SDL.h>
#include "client.hpp"
#include "gfx.hpp"
#include "shared/exception.hpp"

namespace MSMP::Client
{
    void Client::Start()
    {
        if (this->IsRunning())
        {
            MSMP_THROW("Already running");
        }

        this->runningState = true;

        // SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            std::string buf("Failed to initialize SDL library\n");
            buf.append(SDL_GetError());
            MSMP_THROW(buf);
        }

        // graphics
        this->graphics = std::make_shared<Graphics>();
        this->graphics->Init();
    }

    void Client::Update()
    {
        if (this->closeRequested)
        {
            this->runningState = false;
            return;
        }

        SDL_Event event{};
        while (SDL_PollEvent(&event) != 0)
        {
            this->HandleEvent(event);
        }

        this->graphics->Draw();
    }


    void Client::HandleEvent(const SDL_Event &event)
    {
        if (event.type == SDL_QUIT)
        {
            this->RequestClose();
        }
    }

    void Client::CleanUp()
    {
        if (this->graphics != nullptr)
        {
            this->graphics->CleanUp();
        }

        SDL_Quit();
    }

    void Client::RequestClose()
    {
        this->closeRequested = true;
    }

    bool Client::IsRunning()
    {
        return this->runningState;
    }

    static ClientT client_instance = nullptr;

    void Client::Set(ClientT client)
    {
        if (client_instance != nullptr)
        {
            throw "already set";
        }

        client_instance = std::move(client);
    }

    ClientT Client::Get()
    {
        return client_instance;
    }
}