#include <xtd/xtd.strings.hpp>
#include "../include/xtd/forms/message.hpp"
#include "../../native/control_api.hpp"

int xtd::forms::message::counter_ = 0;

std::string xtd::forms::message::to_string() const {
  return xtd::strings::format("msg=0x{:X4} ({}), hwnd=0x{:X}, wparam=0x{:X}, lparam=0x{:X}, result=0x{:X}", this->msg_, native::control_api::message_to_string(this->msg_), this->hwnd_, this->wparam_, this->lparam_, this->result_);
}
