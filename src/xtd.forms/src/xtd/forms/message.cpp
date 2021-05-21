#include <xtd/strings.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../include/xtd/forms/message.h"

using namespace xtd;
using namespace xtd::forms;

int32_t message::counter_ = 0;

std::string message::to_string() const {
  return strings::format("msg=0x{:X4} ({}), hwnd=0x{:X}, wparam=0x{:X}, lparam=0x{:X}, result=0x{:X}", msg_, native::control::message_to_string(msg_), hwnd_, wparam_, lparam_, result_);
}
