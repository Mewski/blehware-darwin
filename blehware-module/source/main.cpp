#include <string>
#include <thread>
#include <iostream>

#include "globals.hpp"
#include "offsets.hpp"
#include "pipe.hpp"
#include "roblox.hpp"

void blehware_main() {
    blehware::pipe::create_pipe("/tmp/blehware-pipe");

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    blehware::roblox::initialize();
}

__attribute__((constructor)) void dylib_main(int argc, const char **argv) {
    if (argc < 1 || !std::string(argv[0]).ends_with("RobloxPlayer")) {
        return;
    }

    blehware::globals::initialize();

    std::thread(blehware_main).detach();
}