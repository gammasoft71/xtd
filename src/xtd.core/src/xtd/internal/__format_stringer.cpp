#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__format_stringer.h"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/ustring.h"

using namespace std;
using namespace xtd;

string __format_stringer_to_std_string(const char* str) {
  return str;
}

string __format_stringer_to_std_string(const char8_t* str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const char16_t* str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const char32_t* str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const wchar_t* str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const string& str) {
  return str;
}

string __format_stringer_to_std_string(const ustring& str) {
  return str;
}

string __format_stringer_to_std_string(const u8string& str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const u16string& str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const u32string& str) {
  return ustring(str);
}

string __format_stringer_to_std_string(const wstring& str) {
  return ustring(str);
}
