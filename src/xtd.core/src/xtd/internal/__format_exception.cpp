#include "../../../include/xtd/format_exception.h"
#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__format_exception.h"
#undef __XTD_CORE_INTERNAL__

void __format_exception(const std::string& message) {
  throw xtd::format_exception(message);
}
