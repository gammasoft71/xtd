#include "../../../include/xtd/io/io_exception.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

io_exception::io_exception(const stack_frame& stack_frame) : system_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_IO));
}

io_exception::io_exception(const optional<string>& message, const stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_IO));
}

/// @todo remove deprecated in version 0.4.0
/// @{
io_exception::io_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
}

io_exception::io_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_IO));
  this->help_link(help_link);
}

io_exception::io_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

io_exception::io_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : system_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_IO));
}

io_exception::io_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_IO));
}

io_exception::io_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
}

io_exception::io_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_IO));
  this->help_link(help_link);
}

io_exception::io_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
// @}
