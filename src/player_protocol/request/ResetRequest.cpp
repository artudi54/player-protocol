#include "ResetRequest.hpp"

namespace player_protocol::request {
    MessageType ResetRequest::getMessageType() const {
        return MessageType::REQUEST_RESET;
    }

    void ResetRequest::visit(MessageVisitor &visitor) const {
        visitor.handleMessage(*this);
    }
}