add_executable(blehware-terminal
    # Source Files
    source/pipe.cpp
    source/main.cpp

    # Header Files
    include/pipe.hpp
)

target_include_directories(blehware-terminal PRIVATE include)

set_target_properties(blehware-terminal PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)