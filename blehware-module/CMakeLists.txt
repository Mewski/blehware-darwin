add_library(blehware-module SHARED
    # Source files
    source/main.cpp
)

set_target_properties(blehware-module PROPERTIES 
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# luau
target_link_libraries(blehware-module PRIVATE Luau.Compiler)
target_link_libraries(blehware-module PRIVATE Luau.VM)
target_include_directories(blehware-module PRIVATE ${ROOT_DIR}/dependencies/submodules/luau/VM/src)