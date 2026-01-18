#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__format_stringer.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/iformatable.hpp"
#include "../../../include/xtd/string.hpp"

using namespace xtd;
using namespace xtd::globalization;

auto __iformatable_to_string(const iformatable& value) noexcept -> std::string {
  return value.to_string("", culture_info::current_culture());
}

auto operator <<(std::ostream& os, const char8* str) -> std::ostream& {
  return os << string(str);
}

auto operator <<(std::ostream& os, const char16* str) -> std::ostream& {
  return os << string(str);
}

auto operator <<(std::ostream& os, const char32* str) -> std::ostream& {
  return os << string(str);
}

auto operator <<(std::ostream& os, const wchar* str) -> std::ostream& {
  return os << string(str);
}

auto __format_stringer_to_std_string(const char& c) -> std::string {
  return string(c, 1);
}

auto __format_stringer_to_std_string(const char8& c) -> std::string {
  return string(std::u8string(c, 1));
}

auto __format_stringer_to_std_string(const char16& c) -> std::string {
  return string(std::u16string(c, 1));
}

auto __format_stringer_to_std_string(const char32& c) -> std::string {
  return string(std::u32string(1, c));
}

auto __format_stringer_to_std_string(const wchar& c) -> std::string {
  return string(std::wstring(c, 1));
}

auto __format_stringer_to_std_string(const char* str) -> std::string {
  return str;
}

auto __format_stringer_to_std_string(const char8* str) -> std::string {
  return string(str);
}

auto __format_stringer_to_std_string(const char16* str) -> std::string {
  return string(str);
}

auto __format_stringer_to_std_string(const char32* str) -> std::string {
  return string(str);
}

auto __format_stringer_to_std_string(const wchar* str) -> std::string {
  return string(str);
}

auto __format_stringer_to_std_string(const std::string& str) -> std::string {
  return str;
}

auto __format_stringer_to_std_string(const string& str) -> std::string {
  return str;
}

auto __format_stringer_to_std_string(const std::u8string& str) -> std::string {
  return string(str);
}

auto __format_stringer_to_std_string(const std::u16string& str) -> std::string {
  return string(str);
}

auto __format_stringer_to_std_string(const std::u32string& str) -> std::string {
  return string(str);
}

auto __format_stringer_to_std_string(const std::wstring& str) -> std::string {
  return string(str);
}
