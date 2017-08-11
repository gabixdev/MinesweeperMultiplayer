#include "shared/logging.hpp"
#include "shared/files.hpp"

static std::shared_ptr<spdlog::logger> logger = nullptr;

void MSMP::InitLogging(const std::string &file)
{
    if (!MSMP::Files::IsDirectory("logs"))
    {
        MSMP::Files::MakeDirectory("logs");
    }

    spdlog::set_pattern("[%x %X] [%n] [%l] %v");

    // create logger
    auto rf_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/msmp_" + file + ".log", 1024 * 1024 * 5,
                                                                          99999);
    auto cl_sink = spdlog::sinks::stdout_sink_mt::instance();

    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(rf_sink);
    sinks.push_back(cl_sink);
    logger = std::make_shared<spdlog::logger>("msmp", sinks.begin(), sinks.end());

#ifdef MSMP_DEBUG
    logger->set_level(spdlog::level::trace);
#else
    logger->set_level(spdlog::level::debug)
#endif

    spdlog::register_logger(logger);
}

const std::shared_ptr<spdlog::logger> MSMP::GetLogger()
{
    return logger;
}