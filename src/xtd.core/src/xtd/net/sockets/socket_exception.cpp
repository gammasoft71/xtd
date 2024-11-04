#include "../../../../include/xtd/net/sockets/socket_exception.h"
#include "../../../../include/xtd/literals.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/socket>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::net::sockets;
using namespace xtd::diagnostics;

socket_exception::socket_exception(const stack_frame& stack_frame) : system_exception(native::socket::socket_error_to_string(static_cast<int32>(xtd::net::sockets::socket_error::success)), stack_frame) {
  error_code(h_result::make_error_code(h_result::E_FAIL));
}

socket_exception::socket_exception(int32 error_code, const xtd::diagnostics::stack_frame& stack_frame) : socket_exception(static_cast<socket_error>(error_code), stack_frame) {
}

socket_exception::socket_exception(int32 error_code, const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : socket_exception(static_cast<socket_error>(error_code), message, stack_frame) {
}

socket_exception::socket_exception(socket_error error_code, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(native::socket::socket_error_to_string(static_cast<int32>(error_code)), stack_frame), error_code_ {error_code} {
  this->error_code(h_result::make_error_code(h_result::E_FAIL));
}

socket_exception::socket_exception(xtd::net::sockets::socket_error error_code, const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame), error_code_ {error_code} {
  this->error_code(h_result::make_error_code(h_result::E_FAIL));
}

socket_exception::socket_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
}

socket_exception::socket_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::E_FAIL));
  this->help_link(help_link);
}

socket_exception::socket_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

socket_exception::socket_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::E_FAIL));
}

socket_exception::socket_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::E_FAIL));
}

socket_exception::socket_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
}

socket_exception::socket_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::E_FAIL));
  this->help_link(help_link);
}

socket_exception::socket_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

xtd::net::sockets::socket_error socket_exception::socket_error_code() const noexcept {
  return error_code_;
}
