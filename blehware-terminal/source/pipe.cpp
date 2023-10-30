#include "pipe.hpp"

#include <unistd.h>
#include <sys/stat.h>

namespace blehware::pipe {
    void create_pipe(const std::string& pipe_path) {
        mkfifo(pipe_path.c_str(), 0666);
    }

    void delete_pipe(const std::string& pipe_path) {
        unlink(pipe_path.c_str());
    }

    bool pipe_exists(const std::string& pipe_path) {
        struct stat buffer = {};
        return (stat(pipe_path.c_str(), &buffer) == 0);
    }

    void write_to_pipe(const std::string& pipe_path, const std::string& message) {
        FILE* pipe = fopen(pipe_path.c_str(), "w");
        fprintf(pipe, "%s", message.c_str());
        fclose(pipe);
    }

    std::string read_from_pipe(const std::string& pipe_path) {
        FILE* pipe = fopen(pipe_path.c_str(), "r");
        char buffer[1024];
        fgets(buffer, 1024, pipe);
        fclose(pipe);
        return std::string(buffer) + "";
    }
}