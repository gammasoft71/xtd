#include "../../include/xtd/call_once.h"
#include "../../include/xtd/console.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/system_exception.h"
#include "../../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;

system_exception::system_exception(const xtd::diagnostics::stack_frame& info) : exception(info) {
  error_code(make_error_code(h_results::COR_E_SYSTEM));
}

system_exception::system_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(make_error_code(h_results::COR_E_SYSTEM));
}

system_exception::system_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(error);
}

system_exception::system_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(make_error_code(h_results::COR_E_SYSTEM));
  this->help_link(help_link);
}

system_exception::system_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(error);
  this->help_link(help_link);
}

system_exception::system_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : exception(default_message(), info) {
  error_code(make_error_code(h_results::COR_E_SYSTEM));
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(make_error_code(h_results::COR_E_SYSTEM));
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(error);
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(make_error_code(h_results::COR_E_SYSTEM));
  this->help_link(help_link);
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
  error_code(error);
  this->help_link(help_link);
}

const char* system_exception::default_message() const noexcept {
  return "System error."_t;
}
