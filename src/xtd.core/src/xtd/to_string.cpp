#include "../../include/xtd/to_string.h"
#include "../../include/xtd/ustring.h"

using namespace std;

namespace xtd {
  std::string to_string(const char* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const char8_t* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const char16_t* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const char32_t* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  std::string to_string(const wchar_t* value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const std::string& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
  }
  
  std::string to_string(const xtd::ustring& value, const std::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt, value, loc);
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
