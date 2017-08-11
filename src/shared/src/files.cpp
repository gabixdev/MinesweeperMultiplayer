#include <fstream>

#include "shared/files.hpp"

#ifdef MSMP_WIN

    #include <windows.h>

#elif defined(MSMP_UNIX)

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

#endif

namespace MSMP::Files
{
    bool Exists(const std::string &file)
    {
#ifdef MSMP_WIN
        return GetFileAttributesA(file.c_str()) != INVALID_FILE_ATTRIBUTES;
#elif MSMP_UNIX
        struct stat buffer;
        return stat(file.c_str(), &buffer) == 0;
#endif
    }

    bool IsDirectory(const std::string &file)
    {
#ifdef MSMP_WIN
        DWORD attributes = GetFileAttributesA(file.c_str());
        return (attributes != INVALID_FILE_ATTRIBUTES) && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
#elif MSMP_UNIX
        struct stat buffer;
        if(!stat(file.c_str(), &buffer))
        {
            return false;
        }
        return S_ISREG(buffer.st_mode);
#endif
    }

    bool MakeDirectory(const std::string &path)
    {
#ifdef MSMP_WIN
        return CreateDirectoryA(path.c_str(), nullptr) != 0;
#elif MSMP_UNIX
        mkdir(path.c_str(), 0700);
#endif
    }

    bool IsFile(const std::string &file)
    {
        return Exists(file) && !IsDirectory(file);
    }

    void StringToFile(const std::string &path, std::string string)
    {
        std::ofstream stream;
        stream.open(path);
        stream << string;
        stream.close();
    }
}