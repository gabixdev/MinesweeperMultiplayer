# Config file
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/shared/shared_config.hpp.in"
        "${CMAKE_CURRENT_BINARY_DIR}/shared/shared_config.hpp"
)

# Set the include directory
set(
        MSMP_SHARED_INCLUDES

        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}

        CACHE INTERNAL "MSMP Shared Project Includes"
)

set(
        MSMP_SHARED_INCLUDES_ALL

        ${MSMP_SHARED_INCLUDES}

        CACHE INTERNAL "MSMP Shared Project + Libraries Includes"
)