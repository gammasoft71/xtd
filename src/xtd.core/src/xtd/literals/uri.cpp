#include "../../../include/xtd/literals/uri.hpp"
#include "../../../include/xtd/uri.hpp"

using namespace xtd;

auto xtd::literals::operator""_uri(const char* s, usize n) -> uri {
  return uri(string {s});
}

auto xtd::literals::operator""_uri(const char8* s, usize n) -> uri {
  return uri(string {s});
}

auto xtd::literals::operator""_uri(const char16* s, usize n) -> uri {
  return uri(string {s});
}

auto xtd::literals::operator""_uri(const char32* s, usize n) -> uri {
  return uri(string {s});
}

auto xtd::literals::operator""_uri(const wchar* s, usize n) -> uri {
  return uri(string {s});
}
