#include "../../include/xtd/access_violation_exception.h"
#include "../../include/xtd/literals.h"

using namespace xtd;
using namespace xtd::diagnostics;

access_violation_exception::access_violation_exception(const stack_frame& info) : access_violation_exception(std::nullopt, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : access_violation_exception(info) {
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}

access_violation_exception::access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info) : access_violation_exception(message, std::optional<xtd::exception> {}, info) {
}
