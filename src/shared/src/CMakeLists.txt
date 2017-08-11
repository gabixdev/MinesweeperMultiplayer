# Check platform
include(${MSMP_FUNCTIONS}/check_platform.cmake)
check_platform()

# Include headers
include_directories(${MSMP_SHARED_INCLUDES_ALL})

# Recurse glob for source files
file(GLOB_RECURSE MSMP_SHARED_SOURCES *.cpp)

# Build static library
add_library(MSMP_SHARED STATIC ${MSMP_SHARED_SOURCES})

# Static link libgcc and libstdc++
target_link_libraries(MSMP_SHARED -static-libgcc -static-libstdc++)