# Includes
include(${MSMP_FUNCTIONS}/includes.cmake)

# Prepare includes
prepare_include(MSMP_CLIENT_LIB_INCLUDES)

# Prepare dependencies
add_library(MSMP_CLIENT_LIB STATIC dummy.cpp)

# SDL2
add_subdirectory("sdl")
append_include(MSMP_CLIENT_LIB_INCLUDES "sdl/include")
target_link_libraries(MSMP_CLIENT_LIB SDL2)

# Copy SDL DLL
add_custom_command(
        TARGET MSMP_CLIENT_LIB POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL2>
        ${MSMP_BIN_DIR}
)

# Copy pthread dll when on windows
if (${MSMP_PLATFORM} MATCHES "Win")
    add_custom_command(
            TARGET MSMP_CLIENT_LIB POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${MSMP_LIB_DIR}/libwinpthread-1.dll
            ${MSMP_BIN_DIR}
    )
endif ()