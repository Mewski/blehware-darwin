#include <unistd.h>

#include "globals.hpp"
#include "macos.hpp"

namespace blehware::globals {
    void initialize() {
        blehware::base_address = blehware::macos::get_base_address();
    }
}