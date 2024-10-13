#include "../../../include/xtd/io/drive_not_found_exception.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

drive_not_found_exception::drive_not_found_exception(const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND));
}

drive_not_found_exception::drive_not_found_exception(const optional<string>& message, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND));
}

drive_not_found_exception::drive_not_found_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

drive_not_found_exception::drive_not_found_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND));
  this->help_link(help_link);
}

drive_not_found_exception::drive_not_found_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

drive_not_found_exception::drive_not_found_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND));
}

drive_not_found_exception::drive_not_found_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND));
}

drive_not_found_exception::drive_not_found_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

drive_not_found_exception::drive_not_found_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND));
  this->help_link(help_link);
}

drive_not_found_exception::drive_not_found_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
