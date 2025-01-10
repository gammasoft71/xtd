/// @file
/// @brief Contains xtd::println methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "console.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the current line terminator to the standard output stream using the specified format information.
  inline void println() {xtd::console::write_line();}
  
  /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the standard output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param value The value to write,
  template<typename arg_t>
  void println(arg_t&& value) {xtd::console::write_line(xtd::string::format("{}", value));}
  
  /// @cond
  template<class type_t>
  void println(const std::initializer_list<type_t>& il) {xtd::console::write_line(xtd::string::format("{}", il));}
  /// @endcond

  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ... args_t>
  void println(const xtd::string& fmt, args_t&& ... values) {xtd::console::write_line(xtd::string::format(fmt, std::forward<args_t>(values)...));}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ... args_t>
  void println(const char* fmt, args_t&& ... values) {xtd::console::write_line(xtd::string::format(xtd::string {fmt}, std::forward<args_t>(values)...));}
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ... args_t>
  void println(const char8_t* fmt, args_t&& ... values) {xtd::console::write_line(xtd::string::format(xtd::string {fmt}, std::forward<args_t>(values)...));}
#endif
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ... args_t>
  void println(const char16_t* fmt, args_t&& ... values) {xtd::console::write_line(xtd::string::format(xtd::string {fmt}, std::forward<args_t>(values)...));}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ... args_t>
  void println(const char32_t* fmt, args_t&& ... values) {xtd::console::write_line(xtd::string::format(xtd::string {fmt}, std::forward<args_t>(values)...));}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ... args_t>
  void println(const wchar_t* fmt, args_t&& ... values) {xtd::console::write_line(xtd::string::format(xtd::string {fmt}, std::forward<args_t>(values)...));}
}
