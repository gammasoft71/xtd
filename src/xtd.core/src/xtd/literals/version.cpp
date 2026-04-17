#include "../../../include/xtd/literals/version.hpp"
#include "../../../include/xtd/version.hpp"

using namespace xtd;

auto xtd::literals::operator""_vers(const char* s, usize n) -> version {
  return version::parse(string {s});
}

auto xtd::literals::operator""_vers(const char8* s, usize n) -> version {
  return version::parse(string {s});
}

auto xtd::literals::operator""_vers(const char16* s, usize n) -> version {
  return version::parse(string {s});
}

auto xtd::literals::operator""_vers(const char32* s, usize n) -> version {
  return version::parse(string {s});
}

auto xtd::literals::operator""_vers(const wchar* s, usize n) -> version {
  return version::parse(string {s});
}
