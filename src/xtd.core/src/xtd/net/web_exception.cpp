#include "../../../include/xtd/net/web_exception.h"
#include "../../../include/xtd/literals.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::net;

web_exception::web_exception(const stack_frame& stack_frame) : invalid_operation_exception(std::nullopt, stack_frame) {
}

web_exception::web_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
}

web_exception::web_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
}

web_exception::web_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  this->help_link(help_link);
}

web_exception::web_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

web_exception::web_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(stack_frame) {
}

web_exception::web_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
}

web_exception::web_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
}

web_exception::web_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  this->help_link(help_link);
}

web_exception::web_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : invalid_operation_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
