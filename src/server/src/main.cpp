#include "msmp_server.hpp"
#include "shared/logging.hpp"

int main()
{
    std::cout << "Starting..." << std::endl;

    MSMP::InitLogging("server");
    auto logger = MSMP::GetLogger();

    logger->info("Staring MSMP Server v{}", MSMP::GetMSMPVersion());
    logger->info("Version number {}", MSMP::GetMSMPVersionNumber());
    logger->debug("Debug mode is enabled");
    logger->trace("Trace mode is enabled");

    return 0;
}