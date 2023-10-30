add_executable(blehware-injector
    # Source files
    source/utilities.cpp
    source/main.cpp

    # Header files
    include/utilities.hpp
)

target_include_directories(blehware-injector PRIVATE include)

set_target_properties(blehware-injector PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)