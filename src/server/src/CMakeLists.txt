# Check platform
include(${MSMP_FUNCTIONS}/check_platform.cmake)
check_platform()

# Include shared headers
include_directories(${MSMP_SHARED_INCLUDES_ALL})

# Recurse glob for source files
file(GLOB_RECURSE MSMP_SERVER_SOURCES *.cpp)

# Build executable
add_executable(MSMP_SERVER ${MSMP_SERVER_SOURCES})

# Link shared library
target_link_libraries(MSMP_SERVER MSMP_SHARED)