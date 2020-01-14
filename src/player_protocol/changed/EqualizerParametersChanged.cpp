#include "EqualizerParametersChanged.hpp"
#include <cstring>

namespace player_protocol::changed {
    EqualizerParametersChanged::EqualizerParametersChanged()
        : parameters(){}

    EqualizerParametersChanged::EqualizerParametersChanged(const player_protocol::EqualizerParameters &parameters)
        : parameters(parameters) {}

    MessageType EqualizerParametersChanged::getMessageType() const {
        return MessageType::CHANGED_EQUALIZER_PARAMETERS;
    }

    std::uint32_t EqualizerParametersChanged::serialize(char *data) const {
        std::memcpy(data, &parameters, sizeof(EqualizerParameters));
        return sizeof(EqualizerParameters);
    }

    void EqualizerParametersChanged::deserialize(const char *data) {
        std::memcpy(&parameters, data, sizeof(EqualizerParameters));
    }

    void EqualizerParametersChanged::visit(MessageVisitor &visitor) const {
        visitor.handleMessage(*this);
    }

    const EqualizerParameters &EqualizerParametersChanged::getParameters() const {
        return parameters;
    }

    void EqualizerParametersChanged::setParameters(const EqualizerParameters &parameters) {
        this->parameters = parameters;
    }

}