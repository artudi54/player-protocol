#include "PlayerStateChangedMessage.hpp"

namespace player_protocol::changed {
    PlayerStateChangedMessage::PlayerStateChangedMessage()
            : playerState(PlayerState::NO_SOURCE) {}

    PlayerStateChangedMessage::PlayerStateChangedMessage(PlayerState playerState)
        : playerState(playerState) {}

    MessageType PlayerStateChangedMessage::getMessageType() const {
        return MessageType::CHANGED_PLAYER_STATE;
    }

    std::uint32_t PlayerStateChangedMessage::serialize(char *data) const {
        data[0] = static_cast<char>(playerState);
        return 1;
    }

    void PlayerStateChangedMessage::deserialize(const char *data) {
        playerState = static_cast<PlayerState>(data[0]);
    }

    void PlayerStateChangedMessage::visit(MessageVisitor &visitor) const {
        visitor.handleMessage(*this);
    }

    PlayerState PlayerStateChangedMessage::getPlayerState() const {
        return playerState;
    }

    void PlayerStateChangedMessage::setPlayerState(PlayerState playerState) {
        this->playerState = playerState;
    }
}