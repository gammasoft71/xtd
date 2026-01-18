#include "../../../include/xtd/literals/guid.hpp"
#include "../../../include/xtd/guid.hpp"

using namespace xtd;

auto xtd::literals::operator""_guid(const char* s, size n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const char8* s, size n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const char16* s, size n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const char32* s, size n) -> guid {
  return guid(string {s});
}

auto xtd::literals::operator""_guid(const wchar* s, size n) -> guid {
  return guid(string {s});
}
