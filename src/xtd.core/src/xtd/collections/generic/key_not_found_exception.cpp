#include "../../../../include/xtd/collections/generic/key_not_found_exception.hpp"
#include "../../../../include/xtd/literals.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

key_not_found_exception::key_not_found_exception(const stack_frame& stack_frame) : system_exception(std::nullopt, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_KEYNOTFOUND));
}

key_not_found_exception::key_not_found_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_KEYNOTFOUND));
}
