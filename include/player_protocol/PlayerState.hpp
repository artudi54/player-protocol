#pragma once
#include <cstdint>

namespace player_protocol {
    enum class PlayerState : std::uint8_t {
        NO_SOURCE,
        STOPPED,
        PLAYING,
        PAUSED
    };
}