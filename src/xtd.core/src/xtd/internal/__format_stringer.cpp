#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__format_stringer"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/ustring"

using namespace std;
using namespace xtd;

std::string __object_to_string(const object& value) noexcept {
  return value.to_string();
}

#if defined(__cpp_lib_char8_t)
std::ostream& operator <<(std::ostream& os, const char8* str) {
  return os << ustring(str);
}
#endif

std::ostream& operator <<(std::ostream& os, const char16* str) {
  return os << ustring(str);
}

std::ostream& operator <<(std::ostream& os, const char32* str) {
  return os << ustring(str);
}

std::ostream& operator <<(std::ostream& os, const wchar* str) {
  return os << ustring(str);
}

string __format_stringer_to_std_string(const char& c) {
  return string(1, c);
}

#if defined(__cpp_lib_char8_t)
string __format_stringer_to_std_string(const char8& c) {
  return ustring(u8string(1, c));
}
#endif

string __format_stringer_to_std_string(const char16& c) {
  return ustring(u16string(1, c));
}

string __format_stringer_to_std_string(const char32& c) {
  return ustring(u32string(1, c));
}

string __format_stringer_to_std_string(const wchar& c) {
  return ustring(wstring(1, c));
}

string __format_stringer_to_std_string(const char* str) {
  return str;
}

#if defined(__cpp_lib_char8_t)
string __format_stringer_to_std_string(const char8* str) {
  return ustring(str);
}
#endif

string __format_stringer_to_std_string(const char16* str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const char32* str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const wchar* str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const string& str) {
  return str;
}

string __format_stringer_to_std_string(const ustring& str) {
  return str;
}

#if defined(__cpp_lib_char8_t)
string __format_stringer_to_std_string(const u8string& str) {
  return ustring(str);
}
#endif

string __format_stringer_to_std_string(const u16string& str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const u32string& str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const wstring& str) {
  return ustring(str);
}
