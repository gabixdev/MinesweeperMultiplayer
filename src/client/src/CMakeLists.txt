# Include shared headers
include_directories(${MSMP_SHARED_INCLUDES_ALL})

# Recurse glob for source files
file(GLOB_RECURSE MSMP_CLIENT_SOURCES *.cpp)

# Build executable
add_executable(MSMP_CLIENT ${MSMP_CLIENT_SOURCES})

# Link shared library
target_link_libraries(MSMP_CLIENT MSMP_SHARED)