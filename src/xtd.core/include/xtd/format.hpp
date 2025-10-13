/// @file
/// @brief Contains xtd::format methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "globalization/culture_info.hpp"
#include "string.hpp"
#include "u8string.hpp"
#include "u16string.hpp"
#include "u32string.hpp"
#include "wstring.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::string format(const xtd::string& fmt, args_t&& ... args) {return xtd::string::format(fmt, std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::u8string format(const xtd::u8string& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::u16string format(const xtd::u16string& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::u32string format(const xtd::u32string& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::wstring format(const xtd::wstring& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}
  
  /// @cond
  template<class ...args_t>
  xtd::string format(const char* fmt, args_t&& ... args) {return xtd::string::format(std::string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::u8string format(const char8_t* fmt, args_t&& ... args) {return xtd::string::format(std::u8string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::u16string format(const char16_t* fmt, args_t&& ... args) {return xtd::string::format(std::u16string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::u32string format(const char32_t* fmt, args_t&& ... args) {return xtd::string::format(std::u32string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::wstring format(const wchar_t* fmt, args_t&& ... args) {return xtd::string::format(std::wstring {fmt}, std::forward<args_t>(args)...);}
  /// @endcond

  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::string format(const xtd::globalization::culture_info& culture, const xtd::string& fmt, args_t&& ... args) {return xtd::string::format(culture, fmt, std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::u8string format(const xtd::globalization::culture_info& culture, const xtd::u8string& fmt, args_t&& ... args) {return xtd::string::format(culture, fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::u16string format(const xtd::globalization::culture_info& culture, const xtd::u16string& fmt, args_t&& ... args) {return xtd::string::format(culture, fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::u32string format(const xtd::globalization::culture_info& culture, const xtd::u32string& fmt, args_t&& ... args) {return xtd::string::format(culture, fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class ...args_t>
  xtd::wstring format(const xtd::globalization::culture_info& culture, const xtd::wstring& fmt, args_t&& ... args) {return xtd::string::format(culture, fmt.to_string(), std::forward<args_t>(args)...);}
  
  /// @cond
  template<class ...args_t>
  xtd::string format(const xtd::globalization::culture_info& culture, const char* fmt, args_t&& ... args) {return xtd::string::format(culture, std::string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::u8string format(const xtd::globalization::culture_info& culture, const char8_t* fmt, args_t&& ... args) {return xtd::string::format(culture, std::u8string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::u16string format(const xtd::globalization::culture_info& culture, const char16_t* fmt, args_t&& ... args) {return xtd::string::format(culture, std::u16string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::u32string format(const xtd::globalization::culture_info& culture, const char32_t* fmt, args_t&& ... args) {return xtd::string::format(culture, std::u32string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::wstring format(const xtd::globalization::culture_info& culture, const wchar_t* fmt, args_t&& ... args) {return xtd::string::format(culture, std::wstring {fmt}, std::forward<args_t>(args)...);}
  /// @endcond
}
