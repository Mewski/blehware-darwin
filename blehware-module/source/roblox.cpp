#include "roblox.hpp"

#include <dobby.h>

#include "pipe.hpp"
#include "utilities.hpp"

namespace blehware::roblox {
    void initialize() {
        reinterpret_cast<std::int64_t(*)()>(blehware::roblox::rebase(blehware::addresses::GET_TASK_SCHEDULER))();
        asm("mov %0, x8" : "=r" (blehware::roblox::task_scheduler));
        
        blehware::pipe::write_to_pipe("/tmp/blehware-pipe", blehware::utilities::number_to_hex(blehware::roblox::task_scheduler));
    }
}