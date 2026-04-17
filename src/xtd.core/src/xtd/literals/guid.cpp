#include "../../../include/xtd/literals/guid.hpp"
#include "../../../include/xtd/guid.hpp"

using namespace xtd;

auto xtd::literals::operator""_guid(const char* s, usize n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const char8* s, usize n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const char16* s, usize n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const char32* s, usize n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const wchar* s, usize n) -> guid {
  return guid(string {s});
}
