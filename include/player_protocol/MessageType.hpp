#pragma once
#include <cstdint>

namespace player_protocol {
    enum class MessageType : std::uint8_t {
        CHANGED_EQUALIZER_PARAMETERS,
        CHANGED_MEDIUM,
        CHANGED_PLAYER_STATE,
        CHANGED_TIME,
        CHANGED_VOLUME,

        REQUEST_CHANGE_EQUALIZER_PARAMETERS,
        REQUEST_CHANGE_MEDIUM,
        REQUEST_CHANGE_VOLUME,
        REQUEST_PLAYLIST,
        REQUEST_PAUSE,
        REQUEST_PLAY,
        REQUEST_RESET,
        REQUEST_SEEK,
        REQUEST_STOP,

        RESPONSE_PLAYLIST,
        RESPONSE_OK,
        RESPONSE_ERROR
    };
}
