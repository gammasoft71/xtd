#include "../../include/xtd/globalization/culture_info.hpp"
#include "../../include/xtd/to_string.hpp"
#include "../../include/xtd/string.hpp"

namespace xtd {
  xtd::string to_string(const char* value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const char8* value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const char16* value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const char32* value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  xtd::string to_string(const wchar* value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const std::string& value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const xtd::string& value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value.chars(), loc);
  }
  
  xtd::string to_string(const std::u8string& value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const std::u16string& value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const std::u32string& value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }
  
  xtd::string to_string(const std::wstring& value, const xtd::string& fmt, const std::locale& loc) {
    return __string_formatter(fmt.chars(), value, loc);
  }

  xtd::string to_string(const std::locale& value, const xtd::string& fmt, const std::locale& loc) {
    return "locale {" + value.name() + "}";
  }
}
