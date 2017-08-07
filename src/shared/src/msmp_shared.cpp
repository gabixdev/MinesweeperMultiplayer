#include "shared/msmp_shared.hpp"

const std::string &MSMP::GetMSMPVersion() {
    static const std::string version = std::string(MSMP_VERSION);
    return version;
};