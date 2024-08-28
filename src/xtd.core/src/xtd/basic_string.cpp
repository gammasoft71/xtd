#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../include/xtd/basic_string.h"
#include "../../include/xtd/typeof.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/argument_out_of_range_exception.h"
#include "../../include/xtd/format_exception.h"
#include "../../include/xtd/index_out_of_range_exception.h"
#include "../../include/xtd/null_pointer_exception.h"
#include "../../include/xtd/diagnostics/stack_frame.h"

using namespace xtd;

void __throw_basic_string_argument_exception(const char* file, uint32 line, const char* func) {
  throw argument_exception {{file, line, func}};
}

void __throw_basic_string_argument_out_of_range_exception(const char* file, uint32 line, const char* func) {
  throw argument_out_of_range_exception {{file, line, func}};
}

void __throw_basic_string_format_exception(const char* file, uint32 line, const char* func) {
  throw format_exception {{file, line, func}};
}

void __throw_basic_string_format_exception_close_bracket(const char* file, uint32 line, const char* func) {
  throw format_exception {"Invalid format expression : closing bracket '{' without open bracket '}'"_t, {file, line, func}};
}

void __throw_basic_string_format_exception_open_bracket(const char* file, uint32 line, const char* func) {
  throw format_exception {"Invalid format expression : open bracket '}' without end bracket '{'"_t, {file, line, func}};
}

void __throw_basic_string_format_exception_start_colon(const char* file, uint32 line, const char* func) {
  throw format_exception {"Invalid format expression : format argument must be start by ':'"_t, {file, line, func}};
}

void __throw_basic_string_index_out_of_range_exception(const char* file, xtd::uint32 line, const char* func) {
  throw index_out_of_range_exception {{file, line, func}};
}

void __throw_basic_string_null_pointer_exception(const char* file, xtd::uint32 line, const char* func) {
  throw null_pointer_exception {{file, line, func}};
}
