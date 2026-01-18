#include "../../../include/xtd/io/file_format_exception.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

file_format_exception::file_format_exception(const stack_frame& stack_frame) : format_exception(default_message(), stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

file_format_exception::file_format_exception(const std::optional<string>& message, const stack_frame& stack_frame) : format_exception(message.value_or(default_message()), stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

/// @todo remove deprecated in version 0.4.0
/// @{
file_format_exception::file_format_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
}

file_format_exception::file_format_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
  this->help_link(help_link);
}

file_format_exception::file_format_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

file_format_exception::file_format_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : format_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

file_format_exception::file_format_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

file_format_exception::file_format_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
}

file_format_exception::file_format_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
  this->help_link(help_link);
}

file_format_exception::file_format_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

auto file_format_exception::default_message() noexcept -> string {
  return "Input file or data stream does not conform to the expected file format specification.";
}
/// @}
