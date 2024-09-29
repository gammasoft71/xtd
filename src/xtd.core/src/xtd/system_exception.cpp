#include "../../include/xtd/call_once.h"
#include "../../include/xtd/console.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/system_exception.h"
#include "../../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;
using namespace xtd::diagnostics;

system_exception::system_exception(const stack_frame& stack_frame) : exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
}

system_exception::system_exception(const optional<string>& message, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
}

system_exception::system_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(error);
}

system_exception::system_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
  this->help_link(help_link);
}

system_exception::system_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

system_exception::system_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : exception(default_message(), stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
}

system_exception::system_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
}

system_exception::system_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(error);
}

system_exception::system_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
  this->help_link(help_link);
}

system_exception::system_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

const char* system_exception::default_message() const noexcept {
  return "System error."_t;
}
