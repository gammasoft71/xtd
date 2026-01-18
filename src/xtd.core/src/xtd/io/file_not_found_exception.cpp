#include "../../../include/xtd/io/file_not_found_exception.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

file_not_found_exception::file_not_found_exception(const stack_frame& stack_frame) : io_exception {stack_frame} {
  error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));
}

file_not_found_exception::file_not_found_exception(const optional<string>& message, const stack_frame& stack_frame) : io_exception {message, stack_frame}, defined_message_ {message.has_value()} {
  error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));
}

file_not_found_exception::file_not_found_exception(const optional<string>& message, const optional<string>& file_name, const stack_frame& stack_frame) : io_exception {message, stack_frame}, file_name_{file_name}, defined_message_ {message.has_value()} {
  error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));
}

auto file_not_found_exception::file_name() const noexcept -> const optional<string>& {
  return file_name_;
}

auto file_not_found_exception::message() const noexcept -> const string& {
  if (defined_message_ || !file_name_.has_value()) return exception::message();
  message_ = string::format("Could not load file '{}'. The system cannot find the file specified.", file_name_.value());
  return message_;
}

/// @todo remove deprecated in version 0.4.0
/// @{
file_not_found_exception::file_not_found_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame), defined_message_ {true} {
  error_code(error);
}

file_not_found_exception::file_not_found_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame), defined_message_ {true} {
  error_code(error);
  this->help_link(help_link);
}

file_not_found_exception::file_not_found_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));
}

file_not_found_exception::file_not_found_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(message, stack_frame), defined_message_ {true} {
  error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));
}

file_not_found_exception::file_not_found_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame), defined_message_ {true} {
  error_code(error);
}

file_not_found_exception::file_not_found_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame), defined_message_ {true} {
  error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));
  this->help_link(help_link);
}

file_not_found_exception::file_not_found_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame), defined_message_ {true} {
  error_code(error);
  this->help_link(help_link);
}
/// @}
