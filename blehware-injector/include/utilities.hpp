#pragma once

#include <string>
#include <vector>

namespace blehware::utilities {
    std::vector<std::string> split_string(const std::string &string_to_split, const std::string &delimiter);

    std::string join_string(const std::vector<std::string> &strings_to_join, const std::string &delimiter);
}