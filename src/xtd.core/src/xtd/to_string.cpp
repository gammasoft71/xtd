#include "../../include/xtd/to_string"
#include "../../include/xtd/ustring"

using namespace std;

namespace xtd {
  std::string to_string(const char* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
#if defined(__cpp_lib_char8_t)
  std::string to_string(const char8* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
#endif
  
  std::string to_string(const char16* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const char32* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  std::string to_string(const wchar* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const std::string& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const xtd::ustring& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
#if defined(__cpp_lib_char8_t)
  std::string to_string(const std::u8string& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
#endif
  
  std::string to_string(const std::u16string& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const std::u32string& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const std::wstring& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
}
