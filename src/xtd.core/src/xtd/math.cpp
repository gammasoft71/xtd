#include "../../include/xtd/math.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/overflow_exception.h"
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std;
using namespace xtd;

namespace {
}

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

llong_t math::abs(llong_t value) {
  if (value == numeric_limits<llong_t>::lowest()) throw xtd::overflow_exception(csf_);
  return value < 0 ? -value : value;
}

double math::acos(double value) {
  return std::acos(value);
}

double math::asin(double value) {
  return std::asin(value);
}

double math::atan(double value) {
  return std::atan(value);
}

double math::atan2(double y, double x) {
  return is_infinity(y) && is_infinity(x) ? NaN : std::atan2(y, x);
}

int64_t math::big_mul(int32_t a, int32_t b) {
  return as<int64_t>(a) * as<int64_t>(b);
}

decimal math::ceiling(decimal value) {
  return std::ceil(value);
}

double math::ceiling(double value) {
  return std::ceil(value);
}

double math::cos(double value) {
  return std::cos(value);
}

double math::cosh(double value) {
  return std::cosh(value);
}

double math::degrees_to_radians(double degrees) {
  return degrees * (math::pi / 180);
}

int32_t math::div_rem(int32_t dividend, int32_t divisor, int32_t& remainder) {
  remainder = dividend % divisor;
  return dividend / divisor;
}

int64_t math::div_rem(int64_t dividend, int64_t divisor, int64_t& remainder) {
  remainder = dividend % divisor;
  return dividend / divisor;
}

double math::exp(double value) {
  return std::exp(value);
}

double math::ieee_remainder(double dividend, double divisor) {
  return divisor == 0 ? NaN : dividend - (divisor * math::round(dividend / divisor));
}

decimal_t math::floor(decimal_t value) {
  return std::floor(value);
}

double math::floor(double value) {
  return std::floor(value);
}

bool math::is_infinity(double value) {
  return is_negative_infinity(value) || is_positive_infinity(value);
}

bool math::is_negative_infinity(double value) {
  return value <= negative_infinity;
}

bool math::is_positive_infinity(double value) {
  return value >= positive_infinity;
}

bool math::is_NaN(double value) {
  return value != value;
}

double math::log(double value) {
  return std::log(value);
}

double math::log(double a, double newBase) {
  if (a < 0 || newBase < 0 || (a != 1 && newBase == 0) || (a != 1 && math::is_positive_infinity(newBase)) || math::is_NaN(a) || math::is_NaN(newBase) || newBase == 1) return math::NaN;
  if ((a == 0 && 0 < newBase && newBase < 1) || (math::is_positive_infinity(a) && newBase > 1)) return math::positive_infinity;
  if ((a == 0 && newBase > 1) || (math::is_positive_infinity(a) && 0 < newBase && newBase < 1)) return math::negative_infinity;
  return (math::log(a) / math::log(newBase));
}

double math::log10(double value) {
  return std::log10(value);
}

double math::radians_to_degrees(double radians) {
  return radians * (180 / math::pi);
}

decimal_t math::round(decimal_t value) {
  return math::round(value, 0);
}

decimal_t math::round(decimal_t value, int32_t decimals) {
  decimal_t muliplicator = 1;
  for (int32_t index = 0; index < decimals; index++)
    muliplicator *= 10;
  return math::floor((value * muliplicator) + 0.5) / muliplicator;
}

double math::round(double value) {
  return math::round(value, 0);
}

double math::round(double value, int32_t decimals) {
  double muliplicator = 1;
  for (int32_t index = 0; index < decimals; index++)
    muliplicator *= 10;
  return math::floor((value * muliplicator) + 0.5) / muliplicator;
}
