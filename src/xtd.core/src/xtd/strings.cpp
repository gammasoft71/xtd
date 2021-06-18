#include "../../include/xtd/strings.h"
#include "../../include/xtd/format_exception.h"

using namespace xtd;

void __throw_strings__format_exception() {
  throw format_exception(current_stack_frame_);
}

void __throw_strings__format_exception_close_bracket() {
  throw format_exception("Invalid format expression : closing bracket '{' without open bracket '}'"_t, current_stack_frame_);
}

void __throw_strings__format_exception_open_bracket() {
  throw format_exception("Invalid format expression : open bracket '}' without end bracket '{'"_t, current_stack_frame_);
}

void __throw_strings__format_exception_start_colon() {
  throw format_exception("Invalid format expression : format argument must be start by ':'"_t, current_stack_frame_);
}
