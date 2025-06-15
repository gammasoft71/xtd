#include "../../include/xtd/to_string.hpp"
#include "../../include/xtd/string.hpp"

namespace xtd {
  std::string to_string(const char* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const char8* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
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
  
  std::string to_string(const xtd::string& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value.chars(), loc);
  }
  
  std::string to_string(const std::u8string& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
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
