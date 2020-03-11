#include <xtd/strings.h>
#include <xtd/forms/native/control.hpp>
#include "../include/xtd/forms/message.hpp"

using namespace xtd;
using namespace xtd::forms;

int32_t message::counter_ = 0;

std::string message::to_string() const {
  return strings::format("msg=0x{:X4} ({}), hwnd=0x{:X}, wparam=0x{:X}, lparam=0x{:X}, result=0x{:X}", this->msg_, native::control::message_to_string(this->msg_), this->hwnd_, this->wparam_, this->lparam_, this->result_);
}
