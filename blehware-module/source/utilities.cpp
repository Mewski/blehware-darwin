#include "utilities.hpp"

#include <sstream>

namespace blehware::utilities {
    std::string number_to_hex(std::uint64_t number) {
        std::stringstream stream;
        stream << std::hex << number;
        return "0x" + stream.str();
    }
}