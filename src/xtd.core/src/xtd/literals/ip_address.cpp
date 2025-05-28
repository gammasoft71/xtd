#include "../../../include/xtd/literals/ip_address.hpp"
#include "../../../include/xtd/net/ip_address.hpp"

using namespace xtd;
using namespace xtd::net;

ip_address xtd::literals::operator""_ip(const char* s, xtd::size n) {
  return ip_address::parse(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
ip_address xtd::literals::operator""_ip(const char8* s, xtd::size n) {
  return ip_address::parse(string {s});
}
#endif

ip_address xtd::literals::operator""_ip(const char16* s, xtd::size n) {
  return ip_address::parse(string {s});
}

ip_address xtd::literals::operator""_ip(const char32* s, xtd::size n) {
  return ip_address::parse(string {s});
}

ip_address xtd::literals::operator""_ip(const wchar* s, xtd::size n) {
  return ip_address::parse(string {s});
}
