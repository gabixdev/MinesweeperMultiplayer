#pragma once

// Include the config
#include "shared/shared_config.hpp"

// Basic includes
#include <cstdio>
#include <string>
#include <iostream>
#include <inttypes.h>

#include <spdlog/spdlog.h>

// Basic functions
namespace MSMP
{
    const std::string &GetMSMPVersion();

    constexpr const uint32_t GetMSMPVersionNumber() {
        return (MSMP_VERSION_MAJOR << 20) | (MSMP_VERSION_MINOR << 10) | MSMP_VERSION_PATCH;
    }
}