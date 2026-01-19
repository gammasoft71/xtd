#include "../../../include/xtd/net/web_exception.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::net;

web_exception::web_exception(const stack_frame& stack_frame) : invalid_operation_exception(std::nullopt, stack_frame) {
}

web_exception::web_exception(const std::optional<string>& message, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
}

/// @todo remove deprecated in version 0.4.0
/// @{
web_exception::web_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
}

web_exception::web_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  this->help_link(help_link);
}

web_exception::web_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

web_exception::web_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : invalid_operation_exception(stack_frame) {
}

web_exception::web_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
}

web_exception::web_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
}

web_exception::web_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  this->help_link(help_link);
}

web_exception::web_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
/// @}
