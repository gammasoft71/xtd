#include "../../../include/xtd/literals/ip_address.hpp"
#include "../../../include/xtd/net/ip_address.hpp"

using namespace xtd;
using namespace xtd::net;

auto xtd::literals::operator""_ip(const char* s, usize n) -> ip_address {
  return ip_address::parse(string {s});
}

auto xtd::literals::operator""_ip(const char8* s, usize n) -> ip_address {
  return ip_address::parse(string {s});
}

auto xtd::literals::operator""_ip(const char16* s, usize n) -> ip_address {
  return ip_address::parse(string {s});
}

auto xtd::literals::operator""_ip(const char32* s, usize n) -> ip_address {
  return ip_address::parse(string {s});
}

auto xtd::literals::operator""_ip(const wchar* s, usize n) -> ip_address {
  return ip_address::parse(string {s});
}
