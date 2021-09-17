#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__parse.h"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/format_exception.h"
#include "../../../include/xtd/overflow_exception.h"

void __throw_parse_format_exception(const std::string& message) {
  throw xtd::format_exception(message, current_stack_frame_);
}

void __throw_parse_overflow_exception() {
  throw xtd::overflow_exception(current_stack_frame_);
}
