#pragma once

#include <string>

namespace blehware::pipe {
    void create_pipe(const std::string& pipe_path);

    void delete_pipe(const std::string& pipe_path);

    bool pipe_exists(const std::string& pipe_path);

    void write_to_pipe(const std::string& pipe_path, const std::string& message);

    std::string read_from_pipe(const std::string& pipe_path);
}