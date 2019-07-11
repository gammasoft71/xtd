#include <xtd/xtd.strings.hpp>
#include "../include/xtd/forms/message.hpp"
#include "../../native/control_api.hpp"

int xtd::forms::message::counter_ = 0;

std::string xtd::forms::message::to_string() const {
  return xtd::strings::format("msg=0x{:X4} ({,-33}) hwnd=0x{:X8} wparam=0x{:X8} lparam=0x{:X8} result=0x{:X8}", this->msg_, native::control_api::message_to_string(this->msg_), this->hwnd_, this->wparam_, this->lparam_, this->result_);
}
