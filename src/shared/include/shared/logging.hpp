#pragma once

#include "msmp_shared.hpp"

#ifndef NDEBUG
    #define MSMP_DEBUG
#endif

namespace MSMP
{
    void InitLogging(const std::string &file);

    const std::shared_ptr<spdlog::logger> GetLogger();
}