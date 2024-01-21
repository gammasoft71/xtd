#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__parse.h"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/format_exception.h"
#include "../../../include/xtd/overflow_exception.h"

void __throw_parse_format_exception(const std::string& message, const char* file, xtd::uint32 line, const char* func) {
  throw xtd::format_exception {message, {file, line, func}};
}

void __throw_parse_overflow_exception(const char* file, xtd::uint32 line, const char* func) {
  throw xtd::overflow_exception {{file, line, func}};
}
