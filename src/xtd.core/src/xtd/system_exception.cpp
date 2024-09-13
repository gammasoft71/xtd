#include "../../include/xtd/call_once.h"
#include "../../include/xtd/console.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/system_exception.h"
#include "../../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;

system_exception::system_exception(const xtd::diagnostics::stack_frame& info) : exception(default_message(), info) {
}

system_exception::system_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info) : exception(message, info) {
}

system_exception::system_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : exception(message, error, info) {
}

system_exception::system_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, help_link, info) {
}

system_exception::system_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, error, help_link, info) {
}

system_exception::system_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : exception(default_message(), inner_exception, info) {
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : exception(message, inner_exception, info) {
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : exception(message, inner_exception, error, info) {
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, inner_exception, help_link, info) {
}

system_exception::system_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : exception(message, inner_exception, error, help_link, info) {
}

const char* system_exception::default_message() const noexcept {
  return "System error."_t;
}
