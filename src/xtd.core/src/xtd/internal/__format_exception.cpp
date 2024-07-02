#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__format_exception.h"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/format_exception.h"
#include "../../../include/xtd/typeof.h"

void __format_exception(const xtd::type& type) {
  throw xtd::format_exception {"The `" + typeof_(type).full_name() + "` object does not inherit from `xtd::iformat` or the specialisation for the `" + typeof_(type).full_name() + "` object in the `xtd::to_string` specialisation method does not exist."};
}

void __format_exception(const std::string& message) {
  throw xtd::format_exception {message};
}
