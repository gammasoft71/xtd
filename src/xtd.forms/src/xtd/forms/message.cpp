#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../include/xtd/forms/message.hpp"

using namespace xtd;
using namespace xtd::forms;

auto message::equals(const object& obj) const noexcept -> bool {
  return is<message>(obj) && equals(static_cast<const message&>(obj));
}

auto message::equals(const message& other) const noexcept -> bool {
  return hwnd == other.hwnd && msg == other.msg && wparam == other.wparam && lparam == other.lparam && result == other.result && __handle__ == other.__handle__;
}

auto message::get_hash_code() const noexcept -> usize {
  return hash_code::combine(hwnd, msg);
}

auto message::to_msg_string() const noexcept -> string {
  return native::control::message_to_string(msg);
}

auto message::to_string() const noexcept -> string {
  return string::format("msg=0x{:X4} ({}), hwnd=0x{:X}, wparam=0x{:X}, lparam=0x{:X}, result=0x{:X}", msg, to_msg_string(), hwnd, wparam, lparam, result);
}

auto message::create(intptr hwnd, uint32 msg, intptr wparam, intptr lparam) -> message {
  return message(hwnd, msg, wparam, lparam, 0, 0);
}

message::message(intptr hwnd, uint32 msg, intptr wparam, intptr lparam, intptr result, intptr handle) : hwnd(hwnd), msg(msg), wparam(wparam), lparam(lparam), result(result), __handle__(handle) {
}
