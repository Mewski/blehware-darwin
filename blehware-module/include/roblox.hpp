#pragma once

#include "globals.hpp"
#include "macos.hpp"
#include "offsets.hpp"

namespace blehware::roblox {
    FORCEINLINE std::uintptr_t rebase(std::uintptr_t address) {
        return blehware::base_address + address;
    }

    inline std::uintptr_t task_scheduler;
    inline std::uintptr_t lua_state;

    void initialize();

    enum MessageType {
        MESSAGE_OUTPUT,
        MESSAGE_INFO,
        MESSAGE_WARNING,
        MESSAGE_ERROR,
        MESSAGE_SENSITIVE,
        MESSAGE_TYPE_MAX
    };

    template<typename... Arguments>
    void message_out(MessageType type, const char* format, Arguments... arguments) {
        reinterpret_cast<std::int64_t(*)(std::uint32_t, const char*, ...)>(roblox::rebase(blehware::addresses::MESSAGE_OUT))(type, format, arguments...);
    }
}