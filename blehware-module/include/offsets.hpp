#pragma once

#include <cstdint>

namespace blehware {
    namespace addresses {
        inline namespace virtual_machine {
            constexpr std::uintptr_t GET_TASK_SCHEDULER = 0x10285d0a4;
            constexpr std::uintptr_t LUAU_LOAD = 0x100873a70;
            constexpr std::uintptr_t TASK_DEFER = 0x10081c4bc;
        }

        inline namespace log_service {
            constexpr std::uintptr_t MESSAGE_OUT = 0x100d14f34;
        }
    }

    namespace offsets {
        inline namespace task_scheduler {
            constexpr std::uint64_t JOBS_START = 480;
            constexpr std::uint64_t JOBS_END = 488;
            constexpr std::uint64_t JOB_NAME = 16;
        }

        inline namespace waiting_hybrid_scripts_job {
            constexpr std::uint64_t SCRIPT_CONTEXT = 472;
        }
    }

    namespace constants {
        inline namespace task_scheduler {
            constexpr std::uint64_t JOB_SIZE = 8;
        }
    }
}