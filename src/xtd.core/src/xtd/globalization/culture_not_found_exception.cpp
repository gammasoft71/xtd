#include "../../../include/xtd/globalization/culture_not_found_exception.hpp"

using namespace xtd;
using namespace xtd::globalization;

culture_not_found_exception::culture_not_found_exception(const diagnostics::stack_frame& stack_frame) : system_exception(std::nullopt, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_KEYNOTFOUND));
}

culture_not_found_exception::culture_not_found_exception(const std::optional<string>& message, const diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_KEYNOTFOUND));
}
