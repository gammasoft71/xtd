#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../include/xtd/string.h"
#include "../../include/xtd/typeof.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/convert_string.h"
#include "../../include/xtd/format_exception.h"
#include "../../include/xtd/hash_code.h"
#include "../../include/xtd/is.h"
#include "../../include/xtd/null_pointer_exception.h"
//#include "../../include/xtd/collections/generic/hasher.h"
#include "../../include/xtd/diagnostics/stack_frame.h"
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
