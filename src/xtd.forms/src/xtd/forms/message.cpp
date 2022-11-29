#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../include/xtd/forms/message.h"

using namespace xtd;
using namespace xtd::forms;

intptr_t message::hwnd() const noexcept {return hwnd_;}

void message::hwnd(intptr_t value) {hwnd_ = value;}

intptr_t message::lparam() const noexcept {return lparam_;}

void message::lparam(intptr_t value) {lparam_ = value;}

uint32_t message::msg() const noexcept {return msg_;}

void message::msg(uint32_t value) {msg_ = value;}

intptr_t message::result() const noexcept {return result_;}

void message::result(intptr_t value) {result_ = value;}

intptr_t message::wparam() const noexcept {return wparam_;}

void message::wparam(intptr_t value) {wparam_ = value;}

intptr_t message::handle() const noexcept {return handle_;}

void message::handle(intptr_t value) {handle_ = value;}

message message::create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {return message(hwnd, msg, wparam, lparam);}

message message::create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result) {return message(hwnd, msg, wparam, lparam, result);}
message message::create(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) {return message(hwnd, msg, wparam, lparam, result, handle);}

ustring message::to_string() const noexcept {
  return ustring::format("msg=0x{:X4} ({}), hwnd=0x{:X}, wparam=0x{:X}, lparam=0x{:X}, result=0x{:X}", msg_, native::control::message_to_string(msg_), hwnd_, wparam_, lparam_, result_);
}

message::message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam) {
  id_++;
}

message::message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam), result_(result) {
  id_++;
}

message::message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) : hwnd_(hwnd), msg_(msg), wparam_(wparam), lparam_(lparam), result_(result), handle_(handle) {
  id_++;
}
