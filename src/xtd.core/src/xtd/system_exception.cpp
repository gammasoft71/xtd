#include "../../include/xtd/system_exception.hpp"
#include "../../include/xtd/diagnostics/stack_trace.hpp"
#include "../../include/xtd/type_object.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

system_exception::system_exception(const stack_frame& stack_frame) : exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
}

system_exception::system_exception(const optional<string>& message, const stack_frame& stack_frame) : exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));
}

const xtd::string& system_exception::file_path() const noexcept {
  return get_last_stack_frame().get_file_name();
}

xtd::size system_exception::line_number() const noexcept {
  return get_last_stack_frame().get_file_line_number();
}

const xtd::string& system_exception::member_name() const noexcept {
  return get_last_stack_frame().get_method();
}

const xtd::string& system_exception::name() const noexcept {
  thread_local static string name;
  return (name = get_type().full_name());
}

/// @todo remove deprecated in version 0.4.0
/// @{
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

system_exception::system_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : exception(stack_frame) {
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
/// @}
