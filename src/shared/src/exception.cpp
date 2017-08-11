#include <utility>

#include "shared/exception.hpp"

namespace MSMP
{
    MSException::MSException() : message("Unexpected exception")
    {
    }

    MSException::MSException(std::string message) : message(std::move(message))
    {
    }

    MSException::MSException(const char *message) : message(message)
    {
    }

    void MSException::PrintError() const
    {
        std::cerr
                << "Unexpected exception has occurred" << std::endl
                << "Message: " << this->message;
    }
}