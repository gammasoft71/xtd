#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__parse"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/argument_exception"
#include "../../../include/xtd/format_exception"
#include "../../../include/xtd/overflow_exception"

void __throw_parse_format_exception(const std::string& message) {
  throw xtd::format_exception(message, csf_);
}

void __throw_parse_overflow_exception() {
  throw xtd::overflow_exception {csf_};
}
