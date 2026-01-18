#include "../../../include/xtd/literals/time_span.hpp"
#include "../../../include/xtd/time_span.hpp"

using namespace xtd;

auto xtd::literals::operator""_h(unsigned long long h) -> time_span {
  return xtd::time_span::from_hours(static_cast<double>(h));
}

auto xtd::literals::operator""_m(unsigned long long m) -> time_span {
  return xtd::time_span::from_minutes(static_cast<double>(m));
}

auto xtd::literals::operator""_min(unsigned long long min) -> time_span {
  return xtd::time_span::from_minutes(static_cast<double>(min));
}

auto xtd::literals::operator""_ms(unsigned long long ms) -> time_span {
  return xtd::time_span::from_milliseconds(static_cast<double>(ms));
}

auto xtd::literals::operator""_ns(unsigned long long ns) -> time_span {
  return xtd::time_span::from_nanoseconds(static_cast<double>(ns));
}

auto xtd::literals::operator""_s(unsigned long long s) -> time_span {
  return xtd::time_span::from_seconds(static_cast<double>(s));
}

auto xtd::literals::operator""_t(unsigned long long t) -> time_span {
  return xtd::time_span {ticks(t)};
}

auto xtd::literals::operator""_us(unsigned long long us) -> time_span {
  return xtd::time_span::from_microseconds(static_cast<double>(us));
}

auto xtd::literals::operator""_ts(const char* s, size n) -> time_span {
  return time_span::parse(string {s});
}

auto xtd::literals::operator""_ts(const char8* s, size n) -> time_span {
  return time_span::parse(string {s});
}

auto xtd::literals::operator""_ts(const char16* s, size n) -> time_span {
  return time_span::parse(string {s});
}

auto xtd::literals::operator""_ts(const char32* s, size n) -> time_span {
  return time_span::parse(string {s});
}

auto xtd::literals::operator""_ts(const wchar* s, size n) -> time_span {
  return time_span::parse(string {s});
}
