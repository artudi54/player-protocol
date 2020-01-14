#include "ChangeEqualizerParametersRequest.hpp"
#include <cstring>

namespace player_protocol::request {
    ChangeEqualizerParametersRequest::ChangeEqualizerParametersRequest()
        : parameters(){}

    ChangeEqualizerParametersRequest::ChangeEqualizerParametersRequest(const player_protocol::EqualizerParameters &parameters)
        : parameters(parameters) {}

    MessageType ChangeEqualizerParametersRequest::getMessageType() const {
        return MessageType::REQUEST_CHANGE_EQUALIZER_PARAMETERS;
    }

    std::uint32_t ChangeEqualizerParametersRequest::serialize(char *data) const {
        std::memcpy(data, &parameters, sizeof(EqualizerParameters));
        return sizeof(EqualizerParameters);
    }

    void ChangeEqualizerParametersRequest::deserialize(const char *data) {
        std::memcpy(&parameters, data, sizeof(EqualizerParameters));
    }

    void ChangeEqualizerParametersRequest::visit(MessageVisitor &visitor) const {
        visitor.handleMessage(*this);
    }

    const EqualizerParameters &ChangeEqualizerParametersRequest::getParameters() const {
        return parameters;
    }

    void ChangeEqualizerParametersRequest::setParameters(const EqualizerParameters &parameters) {
        this->parameters = parameters;
    }

}