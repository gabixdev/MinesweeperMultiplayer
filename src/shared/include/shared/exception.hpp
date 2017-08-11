#pragma once

#include "msmp_shared.hpp"

#ifdef MSMP_DEBUG
    #define MSMP_THROW(message) throw MSMP::MSException(message + ". \nDebug: LINE: " + __LINE__ + ", FILE: " + __FILE__)
#else
    #define MSMP_THROW(message) throw MSMP::MSException(message)
#endif

#define MSMP_THROW_DETAILED(message, detail)\
    {\
        std::string buf(message);\
        buf.append("\n");\
        buf.append(detail);\
        MSMP_THROW(buf);\
    }

namespace MSMP
{
    class MSException
    {
        private:
            std::string message;

        public:
            MSException();

            MSException(std::string message);

            MSException(const char *message);

            void PrintError() const;
    };
}