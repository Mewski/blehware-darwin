#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <filesystem>
#include <regex>
#include <unistd.h>
#include <sys/file.h>
#include <charconv>

#include "utilities.hpp"

struct Process {
    int process_id = 0;
    std::string command;
    std::string arguments;
};


std::string run_command(const std::string &command) {
    FILE *pipe = popen(command.c_str(), "r");

    std::array<char, 128> buffer = {};
    std::string data;

    while (!feof(pipe)) {
        if (fgets(buffer.data(), 128, pipe) != nullptr) {
            data += buffer.data();
        }
    }

    pclose(pipe);

    return data + "";
}

bool is_integer(const std::string& string) {
    int value;
    auto [pointer, error] = std::from_chars(string.data(), string.data() + string.size(), value);
    return error == std::errc() && pointer == string.data() + string.size();
}

Process get_roblox_process(std::vector<int> ignored_process_ids = std::vector<int>()) {
    std::string process_list = run_command("ps -exo pid,args");

    std::vector<std::string> lines = blehware::utilities::split_string(process_list, "\n");

    for (const std::string &line: lines) {
        if (line.contains("RobloxPlayer") && !line.contains("--crashHandler") && (line.contains("-ticket")) || line.ends_with("RobloxPlayer")) {
            std::vector<std::string> tokens = blehware::utilities::split_string(line, " ");

            while (!is_integer(tokens.at(0))) {
                tokens.erase(tokens.begin());
            }

            if (std::find(ignored_process_ids.begin(), ignored_process_ids.end(), std::stoi(tokens.at(0))) != ignored_process_ids.end()) {
                continue;
            }

            Process process;
            process.process_id = std::stoi(tokens.at(0));
            process.command = tokens.at(1);
            process.arguments = blehware::utilities::join_string(std::vector<std::string>(tokens.begin() + 2, tokens.end()), " ");
            return process;
        }
    }

    return {};
}

int main() {
    Process process = get_roblox_process();

    if (process.process_id != 0) {
        std::cout << "Please inject before starting Roblox.\n";
        return 1;
    }

    std::cout << "Waiting for Roblox...\n";

    while (true) {
        process = get_roblox_process();

        if (process.process_id != 0) {
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Injecting...\n";

    system(("kill " + std::to_string(process.process_id)).c_str());

    std::string command = process.command;

    std::regex url_regex(R"(https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*))");
    std::string arguments = std::regex_replace(process.arguments, url_regex, "\"$&\"");

    std::string dylib_path = std::filesystem::current_path().string() + "/blehware-module.dylib";

    if (fork() == 0) {
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        open("/dev/null", O_RDWR);
        dup(0);
        dup(0);

        execl("/bin/sh", "sh", "-c", ("DYLD_INSERT_LIBRARIES=" + dylib_path + " " + command + " " + arguments).c_str());
    }

    //system(("DYLD_INSERT_LIBRARIES=" + dylib_path + " " + command + " " + arguments).c_str());

    if (run_command("lsof -p " + std::to_string(get_roblox_process().process_id) + " | grep blehware-module.dylib") == "\n") {
        std::cout << "Failed to inject.\n";
        return 1;
    }

    std::cout << "Successfully Injected!\n";

    return 0;
}