#include <iostream>
#include <string>
#include <thread>

#include "pipe.hpp"

bool pipe_exists = true;

void read_blehware_pipe() {
    while (blehware::pipe::pipe_exists("/tmp/blehware-pipe")) {
        std::string message = blehware::pipe::read_from_pipe("/tmp/blehware-pipe");
        if (!message.empty()) {
            std::cout << message << "\n";
        }
    }

    pipe_exists = false;
}

int main() {
    std::thread(read_blehware_pipe).detach();

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        blehware::pipe::write_to_pipe("/tmp/blehware-pipe", input);

        if (!pipe_exists) {
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}