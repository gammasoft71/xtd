#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__parse_exception.h"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/format_exception.h"
#include "../../../include/xtd/index_out_of_range_exception.h"

void __throw_parse_formatt_exception(const std::string& message) {
  throw xtd::format_exception(message, current_stack_frame_);
}

void __throw_parse_index_out_of_range_exception() {
  throw xtd::index_out_of_range_exception(current_stack_frame_);
}
