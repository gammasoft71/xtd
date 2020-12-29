#include "../../include/xtd/strings.h"
#include "../../include/xtd/format_exception.h"

using namespace xtd;

void __throw_strings__format_exception() {
  throw format_exception(caller_info_);
}

void __throw_strings__format_exception_close_bracket() {
  throw format_exception("Invalid format expression : closing bracket '{' without open bracket '}'"_t, caller_info_);
}

void __throw_strings__format_exception_open_bracket() {
  throw format_exception("Invalid format expression : open bracket '}' without end bracket '{'"_t, caller_info_);
}

void __throw_strings__format_exception_start_colon() {
  throw format_exception("Invalid format expression : format argument must be start by ':'"_t, caller_info_);
}
