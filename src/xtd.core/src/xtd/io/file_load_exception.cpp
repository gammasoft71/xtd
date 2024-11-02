#include "../../../include/xtd/io/file_load_exception.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

file_load_exception::file_load_exception(const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FILELOAD));
}

file_load_exception::file_load_exception(const optional<string>& message, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FILELOAD));
}

file_load_exception::file_load_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

file_load_exception::file_load_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FILELOAD));
  this->help_link(help_link);
}

file_load_exception::file_load_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

file_load_exception::file_load_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FILELOAD));
}

file_load_exception::file_load_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FILELOAD));
}

file_load_exception::file_load_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

file_load_exception::file_load_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FILELOAD));
  this->help_link(help_link);
}

file_load_exception::file_load_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
