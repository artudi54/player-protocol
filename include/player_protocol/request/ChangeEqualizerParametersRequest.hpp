#pragma once
#include <player_protocol/Message.hpp>
#include <player_protocol/EqualizerParameters.hpp>

namespace player_protocol::request {
    class ChangeEqualizerParametersRequest : public Message {
    public:
        ChangeEqualizerParametersRequest();
        explicit ChangeEqualizerParametersRequest(const EqualizerParameters &parameters);

        [[nodiscard]] MessageType getMessageType() const override;
        [[nodiscard]] std::uint32_t serialize(char *data) const override;
        void deserialize(const char *data) override;
        void visit(MessageVisitor& visitor) const override;

        [[nodiscard]] const EqualizerParameters &getParameters() const;
        void setParameters(const EqualizerParameters &parameters);

    private:
        EqualizerParameters parameters;
    };
}