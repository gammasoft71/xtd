#include "../../include/xtd/uri_format_exception.h"
#include "../../include/xtd/literals.h"

using namespace xtd;
using namespace xtd::diagnostics;

uri_format_exception::uri_format_exception(const stack_frame& stack_frame) : format_exception(std::nullopt, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

uri_format_exception::uri_format_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

uri_format_exception::uri_format_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
}

uri_format_exception::uri_format_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
  this->help_link(help_link);
}

uri_format_exception::uri_format_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

uri_format_exception::uri_format_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

uri_format_exception::uri_format_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

uri_format_exception::uri_format_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
}

uri_format_exception::uri_format_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
  this->help_link(help_link);
}

uri_format_exception::uri_format_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
