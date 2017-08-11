#pragma once

#include "msmp_shared.hpp"

namespace MSMP::Files
{
    bool Exists(const std::string &file);

    bool IsDirectory(const std::string &file);

    bool IsFile(const std::string &file);

    bool MakeDirectory(const std::string &path);

    void StringToFile(const std::string &path, std::string file);
}