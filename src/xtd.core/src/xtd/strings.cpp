#include "../../include/xtd/strings.h"
#include "../../include/xtd/format_exception.h"

using namespace xtd;

void __throw_strings__format_exception(const std::string& message) {
  throw format_exception(message, caller_info_);
}
