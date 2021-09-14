#include "../../include/xtd/math.h"
#include "../../include/xtd/overflow_exception.h"
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std;
using namespace xtd;

decimal_t math::abs(decimal_t value) {
  return value < 0 ? -value : value;
}

double math::abs(double value) {
  return value < 0 ? -value : value;
}

float math::abs(float value) {
  return value < 0 ? -value : value;
}

int16_t math::abs(int16_t value) {
  if (value == numeric_limits<int16_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

int32_t math::abs(int32_t value) {
  if (value == numeric_limits<int32_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

int64_t math::abs(int64_t value) {
  if (value == numeric_limits<int64_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

sbyte_t math::abs(sbyte_t value) {
  if (value == numeric_limits<sbyte_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}
