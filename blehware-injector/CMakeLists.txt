add_executable(blehware-injector
    # Source files
    source/main.cpp
)

set_target_properties(blehware-injector PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)