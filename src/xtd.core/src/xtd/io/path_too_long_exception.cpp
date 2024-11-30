#include "../../../include/xtd/io/path_too_long_exception.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

path_too_long_exception::path_too_long_exception(const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_PATHTOOLONG));
}

path_too_long_exception::path_too_long_exception(const optional<string>& message, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_PATHTOOLONG));
}

/// @todo remove deprecated in version 0.4.0
/// @{
path_too_long_exception::path_too_long_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

path_too_long_exception::path_too_long_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_PATHTOOLONG));
  this->help_link(help_link);
}

path_too_long_exception::path_too_long_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

path_too_long_exception::path_too_long_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_PATHTOOLONG));
}

path_too_long_exception::path_too_long_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_PATHTOOLONG));
}

path_too_long_exception::path_too_long_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

path_too_long_exception::path_too_long_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_PATHTOOLONG));
  this->help_link(help_link);
}

path_too_long_exception::path_too_long_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
/// @}
