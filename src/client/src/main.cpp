#include "msmp_client.hpp"
#include "client.hpp"
#include "shared/logging.hpp"
#include "shared/exception.hpp"

#ifdef MSMP_WIN

    #include <windows.h>
    #include <fcntl.h>
    #include <cstdint>

INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
#else
int main()
#endif
{
#if defined(MSMP_WIN) && defined(MSMP_DEBUG)
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
    freopen("CON", "r", stdin);
#endif

    std::cout << "Starting..." << std::endl;

    MSMP::InitLogging("client");
    auto logger = MSMP::GetLogger();

    logger->info("Staring MSMP Client v{}", MSMP::GetMSMPVersion());
    logger->info("Version number {}", MSMP::GetMSMPVersionNumber());
    logger->debug("Debug mode is enabled");
    logger->trace("Trace mode is enabled");


    auto client = std::make_shared<MSMP::Client::Client>();
    MSMP::Client::Client::Set(client);

    try
    {
        client->Start();

        while (client->IsRunning())
        {
            client->Update();
        }
    }
    catch (MSMP::MSException &e)
    {
        e.PrintError();
    }

    client->CleanUp();

#if defined(MSMP_WIN) && defined(MSMP_DEBUG)
    std::cout << "Press any key to continue";
    getchar();
#endif

    return 0;
}