#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__format_exception.h"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/argument_out_of_range_exception.h"

void __litterals_argument_out_of_range_exception() {
  throw xtd::argument_out_of_range_exception(caller_info_);
}
