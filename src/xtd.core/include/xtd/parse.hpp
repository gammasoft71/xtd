/// @file
/// @brief Contains xtd::parse methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @cond
// Workaround : Like Windows.h (with NOMINMAX defined), some includes define max as a macro and this causes compilation errors.
#if defined(_MSC_VER) && defined(max)
#  if __cplusplus < 202302L
#    pragma message("The macro `max` is defined. If you include the `Windows.h` file, please define the 'NOMINMAX' constant before including `Windows.h`. xtd will undef the `max` macro.")
#  else
#    warning "The macro `max` is defined. If you include the `Windows.h` file, please define the 'NOMINMAX' constant before including `Windows.h`. xtd will undef the `max` macro."
#  endif
#  undef max
#endif

#define __XTD_CORE_INTERNAL__
#include "internal/__parse.hpp"
#undef __XTD_CORE_INTERNAL__
/// @endcond
#include "number_styles.hpp"
#include "types.hpp"
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::string& str) {
    if (std::is_enum<value_t>::value) return __parse_enum<value_t>(str);
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found");
  }
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::string& str, const std::locale& locale) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found"); return {};}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::string& str, const std::string& fmt) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found"); return {};}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline std::string parse<std::string>(const std::string& str) {return str;}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::string& str, number_styles) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found"); return {};}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::string& str, number_styles, const std::locale& locale) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found"); return {};}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline xtd::sbyte parse<xtd::sbyte>(const std::string& str, number_styles styles) {return __parse_number<xtd::sbyte>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline char parse<char>(const std::string& str, number_styles styles) {return __parse_number<char>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned char parse<unsigned char>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned char>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline short parse<short>(const std::string& str, number_styles styles) {return __parse_number<short>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned short parse<unsigned short>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned short>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline int parse<int>(const std::string& str, number_styles styles) {return __parse_number<int>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned int parse<unsigned int>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned int>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline long parse<long>(const std::string& str, number_styles styles) {return __parse_number<long>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned long parse<unsigned long>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned long>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline long long parse<long long>(const std::string& str, number_styles styles) {return __parse_number<long long>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned long long parse<unsigned long long>(const std::string& str, number_styles styles) {return __parse_unsigned_number<unsigned long long>(str, styles);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline float parse<float>(const std::string& str, number_styles styles) {return __parse_floating_point_number<float>(str, styles, std::locale());}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline float parse<float>(const std::string& str, number_styles styles, const std::locale& locale) {return __parse_floating_point_number<float>(str, styles, locale);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline double parse<double>(const std::string& str, number_styles styles) {return __parse_floating_point_number<double>(str, styles, std::locale());}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline double parse<double>(const std::string& str, number_styles styles, const std::locale& locale) {return __parse_floating_point_number<double>(str, styles, locale);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline long double parse<long double>(const std::string& str, number_styles styles) {return __parse_floating_point_number<long double>(str, styles, std::locale());}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline long double parse<long double>(const std::string& str, number_styles styles, const std::locale& locale) {return __parse_floating_point_number<long double>(str, styles, locale);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline xtd::sbyte parse<xtd::sbyte>(const std::string& str) {return parse<xtd::sbyte>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline char parse<char>(const std::string& str) {return parse<char>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned char parse<unsigned char>(const std::string& str) {return parse<unsigned char>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline short parse<short>(const std::string& str) {return parse<short>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned short parse<unsigned short>(const std::string& str) {return parse<unsigned short>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline int parse<int>(const std::string& str) {return parse<int>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned int parse<unsigned int>(const std::string& str) {return parse<unsigned int>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline long parse<long>(const std::string& str) {return parse<long>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned long parse<unsigned long>(const std::string& str) {return parse<unsigned long>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline long long parse<long long>(const std::string& str) {return parse<long long>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline unsigned long long parse<unsigned long long>(const std::string& str) {return parse<unsigned long long>(str, number_styles::integer);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline float parse<float>(const std::string& str) {return parse<float>(str, number_styles::fixed_point);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline double parse<double>(const std::string& str) {return parse<double>(str, number_styles::fixed_point);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline long double parse<long double>(const std::string& str) {return parse<long double>(str, number_styles::fixed_point);}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline bool parse<bool>(const std::string& str) {
    std::string lower_str = str;
    while (lower_str.size() > 0 && (lower_str[0] == 9 || lower_str[0] == 10 || lower_str[0] == 11 || lower_str[0] == 12 || lower_str[0] == 13 || lower_str[0] == 32))
      lower_str.erase(0, 1);
    while (lower_str.size() > 0 && (lower_str[lower_str.size() - 1] == 9 || lower_str[lower_str.size() - 1] == 10 || lower_str[lower_str.size() - 1] == 11 || lower_str[lower_str.size() - 1] == 12 || lower_str[lower_str.size() - 1] == 13 || lower_str[lower_str.size() - 1] == 32))
      lower_str.erase(lower_str.size() - 1, 1);
    for (auto& c : lower_str)
      c = static_cast<char>(std::tolower(c));
    if (lower_str != "true" && lower_str != "1" && lower_str != "false" && lower_str != "0")  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Invalid string format");
    return lower_str == "true" || lower_str == "1";
  }
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::wstring& str) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found"); return {};}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::u16string& str) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found"); return {};}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline value_t parse(const std::u32string& str) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format, "Parse specialisation not found"); return {};}
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<char>& str, value_t& value) noexcept {
    try {
      value = parse<value_t>(str);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char16>& str, value_t& value) noexcept {
    try {
      value = parse<value_t>(str);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char32>& str, value_t& value) noexcept {
    try {
      value = parse<value_t>(str);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char8>& str, value_t& value) noexcept {
    try {
      value = parse<value_t>(str);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::wchar>& str, value_t& value) noexcept {
    try {
      value = parse<value_t>(str);
      return true;
    } catch (...) {
      return false;
    }
  }

  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<char>& str, value_t& value, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char16>& str, value_t& value, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char32>& str, value_t& value, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char8>& str, value_t& value, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::wchar>& str, value_t& value, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, locale);
      return true;
    } catch (...) {
      return false;
    }
  }

  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t, class char_t>
  inline bool try_parse(const char_t* str, value_t& value) noexcept {
    return try_parse(std::basic_string<char_t>(str), value);
  }
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t, class char_t>
  inline bool try_parse(const char_t* str, value_t& value, const std::locale& locale) noexcept {
    return try_parse(std::basic_string<char_t>(str), value, locale);
  }
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<char>& str, value_t& value, number_styles style) noexcept {
    try {
      value = parse<value_t>(str, style);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char16>& str, value_t& value, number_styles style) noexcept {
    try {
      value = parse<value_t>(str, style);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char32>& str, value_t& value, number_styles style) noexcept {
    try {
      value = parse<value_t>(str, style);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char8>& str, value_t& value, number_styles style) noexcept {
    try {
      value = parse<value_t>(str, style);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::wchar>& str, value_t& value, number_styles style) noexcept {
    try {
      value = parse<value_t>(str, style);
      return true;
    } catch (...) {
      return false;
    }
  }

  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<char>& str, value_t& value, number_styles style, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, style, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char16>& str, value_t& value, number_styles style, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, style, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char32>& str, value_t& value, number_styles style, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, style, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::char8>& str, value_t& value, number_styles style, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, style, locale);
      return true;
    } catch (...) {
      return false;
    }
  }
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t>
  inline bool try_parse(const std::basic_string<xtd::wchar>& str, value_t& value, number_styles style, const std::locale& locale) noexcept {
    try {
      value = parse<value_t>(str, style, locale);
      return true;
    } catch (...) {
      return false;
    }
  }

  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t, class char_t>
  inline bool try_parse(const char_t* str, value_t& value, number_styles style) noexcept {
    return try_parse(std::basic_string<char_t>(str), value, style);
  }
  
  /// @brief Convert a string into a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class value_t, class char_t>
  inline bool try_parse(const char_t* str, value_t& value, number_styles style, const std::locale& locale) noexcept {
    return try_parse(std::basic_string<char_t>(str), value, style, locale);
  }
}

