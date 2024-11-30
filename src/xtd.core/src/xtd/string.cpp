#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../include/xtd/string.hpp"
#include "../../include/xtd/typeof.hpp"
#include "../../include/xtd/argument_exception.hpp"
#include "../../include/xtd/convert_string.hpp"
#include "../../include/xtd/format_exception.hpp"
#include "../../include/xtd/hash_code.hpp"
#include "../../include/xtd/is.hpp"
#include "../../include/xtd/null_pointer_exception.hpp"
//#include "../../include/xtd/collections/generic/hasher.hpp"
#include "../../include/xtd/diagnostics/stack_frame.hpp"
#include <iomanip>

using namespace xtd;
using namespace xtd::collections::generic;

string xtd::to_ustring(int val) {
  return string::format("{}", val);
}

string xtd::to_ustring(unsigned val) {
  return string::format("{}", val);
}

string xtd::to_ustring(long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(unsigned long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(long long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(unsigned long long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(float val) {
  return string::format("{}", val);
}

string xtd::to_ustring(double val) {
  return string::format("{}", val);
}

string xtd::to_ustring(long double val) {
  return string::format("{}", val);
}
