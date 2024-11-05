#include "../../include/xtd/uri_template_match_exception.h"
#include "../../include/xtd/literals.h"

using namespace xtd;
using namespace xtd::diagnostics;

uri_template_match_exception::uri_template_match_exception(const stack_frame& stack_frame) : system_exception(std::nullopt, stack_frame) {
}

uri_template_match_exception::uri_template_match_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
}
