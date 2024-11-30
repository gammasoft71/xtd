#include "../../include/xtd/invalid_operation_exception.hpp"
#include "../../include/xtd/literals.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

invalid_operation_exception::invalid_operation_exception(const stack_frame& stack_frame) : system_exception(std::nullopt, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INVALIDOPERATION));
}

invalid_operation_exception::invalid_operation_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INVALIDOPERATION));
}

/// @todo remove deprecated in version 0.4.0
/// @{
invalid_operation_exception::invalid_operation_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
}

invalid_operation_exception::invalid_operation_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INVALIDOPERATION));
  this->help_link(help_link);
}

invalid_operation_exception::invalid_operation_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

invalid_operation_exception::invalid_operation_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INVALIDOPERATION));
}

invalid_operation_exception::invalid_operation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INVALIDOPERATION));
}

invalid_operation_exception::invalid_operation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
}

invalid_operation_exception::invalid_operation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INVALIDOPERATION));
  this->help_link(help_link);
}

invalid_operation_exception::invalid_operation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
/// @}
