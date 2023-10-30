#include "utilities.hpp"

namespace blehware::utilities {
    std::vector<std::string> split_string(const std::string &string_to_split, const std::string &delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0, end;

        while ((end = string_to_split.find(delimiter, start)) != std::string::npos) {
            tokens.push_back(string_to_split.substr(start, end - start));
            start = end + delimiter.length();
        }

        tokens.push_back(string_to_split.substr(start));

        return tokens;
    }

    std::string join_string(const std::vector<std::string> &strings_to_join, const std::string &delimiter) {
        std::string joined_string;

        for (size_t i = 0; i < strings_to_join.size(); i++) {
            joined_string += strings_to_join[i];

            if (i != strings_to_join.size() - 1) {
                joined_string += delimiter;
            }
        }

        return joined_string;
    }
}