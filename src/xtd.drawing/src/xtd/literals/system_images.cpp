#include "../../../include/xtd/literals/system_images.hpp"
#include "../../../include/xtd/drawing/system_images.hpp"

using namespace xtd;
using namespace xtd::drawing;

image xtd::literals::operator""_image(const char* s, xtd::size n) {
  return system_images::from_name(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
image xtd::literals::operator""_image(const char8* s, xtd::size n) {
  return system_images::from_name(string {s});
}
#endif

image xtd::literals::operator""_image(const char16* s, xtd::size n) {
  return system_images::from_name(string {s});
}

image xtd::literals::operator""_image(const char32* s, xtd::size n) {
  return system_images::from_name(string {s});
}

image xtd::literals::operator""_image(const wchar* s, xtd::size n) {
  return system_images::from_name(string {s});
}
