#include "../../../include/xtd/security/security_exception.hpp"
#include "../../../include/xtd/literals.hpp"

using namespace xtd;
using namespace xtd::security;
using namespace xtd::diagnostics;

security_exception::security_exception(const stack_frame& stack_frame) : system_exception(std::nullopt, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SECURITY));
}

security_exception::security_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_SECURITY));
}
/// @}
