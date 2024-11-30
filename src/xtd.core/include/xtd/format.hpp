/// @file
/// @brief Contains xtd::println methods.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
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
  template<typename ...args_t>
  xtd::string format(const xtd::string& fmt, args_t&& ... args) {return xtd::string::format(fmt, std::forward<args_t>(args)...);}
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<typename ...args_t>
  xtd::u8string format(const xtd::u8string& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}
#endif
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<typename ...args_t>
  xtd::u16string format(const xtd::u16string& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<typename ...args_t>
  xtd::u32string format(const xtd::u32string& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
  /// @param fmt A composite format string.
  /// @param args arguments list to write using format.
  /// @return string formatted.
  /// @ingroup format_parse
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<typename ...args_t>
  xtd::wstring format(const xtd::wstring& fmt, args_t&& ... args) {return xtd::string::format(fmt.to_string(), std::forward<args_t>(args)...);}

  /// @cond
  template<typename ...args_t>
  xtd::string format(const char* fmt, args_t&& ... args) {return xtd::string::format(std::string {fmt}, std::forward<args_t>(args)...);}
#if defined(__xtd__cpp_lib_char8_t)
  template<typename ...args_t>
  xtd::u8string format(const char8_t* fmt, args_t&& ... args) {return xtd::string::format(std::u8string {fmt}, std::forward<args_t>(args)...);}
#endif
  template<typename ...args_t>
  xtd::u16string format(const char16_t* fmt, args_t&& ... args) {return xtd::string::format(std::u16string {fmt}, std::forward<args_t>(args)...);}
  template<typename ...args_t>
  xtd::u32string format(const char32_t* fmt, args_t&& ... args) {return xtd::string::format(std::u32string {fmt}, std::forward<args_t>(args)...);}
  template<typename ...args_t>
  xtd::wstring format(const wchar_t* fmt, args_t&& ... args) {return xtd::string::format(std::wstring {fmt}, std::forward<args_t>(args)...);}
  /// @endcond
}
