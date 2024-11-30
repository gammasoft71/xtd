#include "../../../include/xtd/net/protocol_violation_exception.hpp"
#include "../../../include/xtd/literals.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::net;

protocol_violation_exception::protocol_violation_exception(const stack_frame& stack_frame) : invalid_operation_exception(std::nullopt, stack_frame) {
}

protocol_violation_exception::protocol_violation_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
}

/// @todo remove deprecated in version 0.4.0
/// @{
protocol_violation_exception::protocol_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
}

protocol_violation_exception::protocol_violation_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  this->help_link(help_link);
}

protocol_violation_exception::protocol_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

protocol_violation_exception::protocol_violation_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(stack_frame) {
}

protocol_violation_exception::protocol_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
}

protocol_violation_exception::protocol_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
}

protocol_violation_exception::protocol_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  this->help_link(help_link);
}

protocol_violation_exception::protocol_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
/// @}
