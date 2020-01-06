#pragma once
#include <player_protocol/Message.hpp>
#include <player_protocol/PlayerState.hpp>

namespace player_protocol::changed {
    class PlayerStateChangedMessage : public Message {
    public:
        PlayerStateChangedMessage();
        explicit PlayerStateChangedMessage(PlayerState playerState);

        [[nodiscard]] MessageType getMessageType() const override;
        [[nodiscard]] std::uint32_t serialize(char *data) const override;
        void deserialize(const char *data) override;
        void visit(MessageVisitor &visitor) const override;

        [[nodiscard]] PlayerState getPlayerState() const;
        void setPlayerState(PlayerState playerState);

    private:
        PlayerState playerState;
    };
}