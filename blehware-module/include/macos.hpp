#pragma once

#include <cstdint>

#define FORCEINLINE __attribute__((always_inline)) inline

#define NOINLINE __attribute__((noinline))

namespace blehware::macos {
    std::uintptr_t get_base_address();
}
