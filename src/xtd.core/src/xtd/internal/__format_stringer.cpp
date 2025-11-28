#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__format_stringer.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/iformatable.hpp"
#include "../../../include/xtd/string.hpp"

using namespace xtd;
using namespace xtd::globalization;

std::string __iformatable_to_string(const iformatable& value) noexcept {
  return value.to_string("", culture_info::current_culture());
}

std::ostream& operator <<(std::ostream& os, const char8* str) {
  return os << string(str);
}

std::ostream& operator <<(std::ostream& os, const char16* str) {
  return os << string(str);
}

std::ostream& operator <<(std::ostream& os, const char32* str) {
  return os << string(str);
}

std::ostream& operator <<(std::ostream& os, const wchar* str) {
  return os << string(str);
}

std::string __format_stringer_to_std_string(const char& c) {
  return string(c, 1);
}

std::string __format_stringer_to_std_string(const char8& c) {
  return string(std::u8string(c, 1));
}

std::string __format_stringer_to_std_string(const char16& c) {
  return string(std::u16string(c, 1));
}

std::string __format_stringer_to_std_string(const char32& c) {
  return string(std::u32string(1, c));
}

std::string __format_stringer_to_std_string(const wchar& c) {
  return string(std::wstring(c, 1));
}

std::string __format_stringer_to_std_string(const char* str) {
  return str;
}

std::string __format_stringer_to_std_string(const char8* str) {
  return string(str);
}

std::string __format_stringer_to_std_string(const char16* str) {
  return string(str);
}

std::string __format_stringer_to_std_string(const char32* str) {
  return string(str);
}

std::string __format_stringer_to_std_string(const wchar* str) {
  return string(str);
}

std::string __format_stringer_to_std_string(const std::string& str) {
  return str;
}

std::string __format_stringer_to_std_string(const string& str) {
  return str;
}

std::string __format_stringer_to_std_string(const std::u8string& str) {
  return string(str);
}

std::string __format_stringer_to_std_string(const std::u16string& str) {
  return string(str);
}

std::string __format_stringer_to_std_string(const std::u32string& str) {
  return string(str);
}

std::string __format_stringer_to_std_string(const std::wstring& str) {
  return string(str);
}
