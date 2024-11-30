#include "../../include/xtd/uri_format_exception.hpp"
#include "../../include/xtd/literals.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

uri_format_exception::uri_format_exception(const stack_frame& stack_frame) : format_exception(std::nullopt, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}

uri_format_exception::uri_format_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : format_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_FORMAT));
}
