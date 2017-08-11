# Check platform
include(${MSMP_FUNCTIONS}/check_platform.cmake)
check_platform()

# Include shared headers
include_directories(${MSMP_SHARED_INCLUDES_ALL})

# Include client lib headers
include_directories(${MSMP_CLIENT_LIB_INCLUDES})

# Recurse glob for source files
file(GLOB_RECURSE MSMP_CLIENT_SOURCES *.cpp)

# Build executable
add_executable(MSMP_CLIENT ${MSMP_CLIENT_SOURCES})

# Link shared library
target_link_libraries(MSMP_CLIENT MSMP_SHARED)

# Link client libraries
target_link_libraries(MSMP_CLIENT MSMP_CLIENT_LIB)

# Copy the client binary
add_custom_command(
        TARGET MSMP_CLIENT POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:MSMP_CLIENT>
        ${MSMP_BIN_DIR}
)