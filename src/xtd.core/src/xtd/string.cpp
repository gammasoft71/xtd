#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../include/xtd/globalization/culture_info.hpp"
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
using namespace xtd::globalization;

string xtd::to_string(int val) {
  return string::format("{}", val);
}

string xtd::to_string(unsigned val) {
  return string::format("{}", val);
}

string xtd::to_string(long val) {
  return string::format("{}", val);
}

string xtd::to_string(unsigned long val) {
  return string::format("{}", val);
}

string xtd::to_string(long long val) {
  return string::format("{}", val);
}

string xtd::to_string(unsigned long long val) {
  return string::format("{}", val);
}

string xtd::to_string(float val) {
  return string::format("{}", val);
}

string xtd::to_string(double val) {
  return string::format("{}", val);
}

string xtd::to_string(long double val) {
  return string::format("{}", val);
}
