# Includes
include(${MSMP_FUNCTIONS}/includes.cmake)

# Prepare includes
prepare_include(MSMP_SHARED_LIB_INCLUDES)

# SPDLog
append_include(MSMP_SHARED_LIB_INCLUDES "spdlog/include")