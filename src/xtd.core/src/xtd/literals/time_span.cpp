#include "../../../include/xtd/literals/time_span.hpp"
#include "../../../include/xtd/time_span.hpp"

using namespace xtd;

time_span xtd::literals::operator""_h(unsigned long long h) {
  return xtd::time_span::from_hours(static_cast<double>(h));
}

time_span xtd::literals::operator""_m(unsigned long long m) {
  return xtd::time_span::from_minutes(static_cast<double>(m));
}

time_span xtd::literals::operator""_min(unsigned long long min) {
  return xtd::time_span::from_minutes(static_cast<double>(min));
}

time_span xtd::literals::operator""_ms(unsigned long long ms) {
  return xtd::time_span::from_milliseconds(static_cast<double>(ms));
}

time_span xtd::literals::operator""_ns(unsigned long long ns) {
  return xtd::time_span::from_nanoseconds(static_cast<double>(ns));
}

time_span xtd::literals::operator""_s(unsigned long long s) {
  return xtd::time_span::from_seconds(static_cast<double>(s));
}

time_span xtd::literals::operator""_t(unsigned long long t) {
  return xtd::time_span {xtd::ticks(t)};
}

time_span xtd::literals::operator""_us(unsigned long long us) {
  return xtd::time_span::from_microseconds(static_cast<double>(us));
}

time_span xtd::literals::operator""_ts(const char* s, xtd::size n) {
  return time_span::parse(string {s});
}

time_span xtd::literals::operator""_ts(const char8* s, xtd::size n) {
  return time_span::parse(string {s});
}

time_span xtd::literals::operator""_ts(const char16* s, xtd::size n) {
  return time_span::parse(string {s});
}

time_span xtd::literals::operator""_ts(const char32* s, xtd::size n) {
  return time_span::parse(string {s});
}

time_span xtd::literals::operator""_ts(const wchar* s, xtd::size n) {
  return time_span::parse(string {s});
}
