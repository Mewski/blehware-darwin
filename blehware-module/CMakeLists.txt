add_library(blehware-module SHARED
    # Source files
    source/globals.cpp
    source/macos.cpp
    source/pipe.cpp
    source/roblox.cpp
    source/utilities.cpp
    source/main.cpp

    # Header files
    include/globals.hpp
    include/macos.hpp
    include/offsets.hpp
    include/pipe.hpp
    include/roblox.hpp
    include/utilities.hpp
)

target_include_directories(blehware-module PRIVATE include)

set_target_properties(blehware-module PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# luau
# target_link_libraries(blehware-module PRIVATE Luau.Compiler)
# target_link_libraries(blehware-module PRIVATE Luau.VM)
# target_include_directories(blehware-module PRIVATE ${ROOT_DIR}/dependencies/submodules/luau/VM/src)