#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../include/xtd/forms/message.h"

using namespace xtd;
using namespace xtd::forms;

intptr message::hwnd() const noexcept {return hwnd_;}

void message::hwnd(intptr value) {hwnd_ = value;}

intptr message::lparam() const noexcept {return lparam_;}

void message::lparam(intptr value) {lparam_ = value;}

uint32 message::msg() const noexcept {return msg_;}

void message::msg(uint32 value) {msg_ = value;}

intptr message::result() const noexcept {return result_;}

void message::result(intptr value) {result_ = value;}

intptr message::wparam() const noexcept {return wparam_;}

void message::wparam(intptr value) {wparam_ = value;}

intptr message::handle() const noexcept {return handle_;}

void message::handle(intptr value) {handle_ = value;}

message message::create(intptr hwnd, int32 msg, intptr wparam, intptr lparam) {return message(hwnd, msg, wparam, lparam);}

message message::create(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result) {return message(hwnd, msg, wparam, lparam, result);}
message message::create(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result, intptr handle) {return message(hwnd, msg, wparam, lparam, result, handle);}

ustring message::to_string() const noexcept {
  return ustring::format("msg=0x{:X4} ({}), hwnd=0x{:X}, wparam=0x{:X}, lparam=0x{:X}, result=0x{:X}", msg_, native::control::message_to_string(msg_), hwnd_, wparam_, lparam_, result_);
}

message::message(intptr hwnd, int32 msg, intptr wparam, intptr lparam) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam) {
  ++id_;
}

message::message(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam), result_(result) {
  ++id_;
}

message::message(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result, intptr handle) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam), result_(result), handle_(handle) {
  ++id_;
}
