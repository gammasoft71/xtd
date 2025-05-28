#include "../../../include/xtd/literals/time_span.hpp"
#include "../../../include/xtd/time_span.hpp"

using namespace xtd;

time_span xtd::literals::operator""_h(unsigned long long h) {
  return xtd::time_span::from_hours(h);
}

time_span xtd::literals::operator""_m(unsigned long long m) {
  return xtd::time_span::from_minutes(m);
}

time_span xtd::literals::operator""_min(unsigned long long min) {
  return xtd::time_span::from_minutes(min);
}

time_span xtd::literals::operator""_ms(unsigned long long ms) {
  return xtd::time_span::from_milliseconds(ms);
}

time_span xtd::literals::operator""_ns(unsigned long long ns) {
  return xtd::time_span::from_nanoseconds(ns);
}

time_span xtd::literals::operator""_s(unsigned long long s) {
  return xtd::time_span::from_seconds(s);
}

time_span xtd::literals::operator""_t(unsigned long long t) {
  return xtd::time_span {xtd::ticks(t)};
}

time_span xtd::literals::operator""_us(unsigned long long us) {
  return xtd::time_span::from_microseconds(us);
}

time_span xtd::literals::operator""_ts(const char* s, xtd::size n) {
  return time_span::parse(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
time_span xtd::literals::operator""_ts(const char8* s, xtd::size n) {
  return time_span::parse(string {s});
}
#endif

time_span xtd::literals::operator""_ts(const char16* s, xtd::size n) {
  return time_span::parse(string {s});
}

time_span xtd::literals::operator""_ts(const char32* s, xtd::size n) {
  return time_span::parse(string {s});
}

time_span xtd::literals::operator""_ts(const wchar* s, xtd::size n) {
  return time_span::parse(string {s});
}
