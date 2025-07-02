/// @file
/// @brief Contains xtd::println methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__print.hpp"
#undef __XTD_CORE_INTERNAL__
#include "string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the current line terminator to the file output stream using the specified format information.
  /// @param file A file output stream.
  inline void println(FILE* file) {
    __xtd_print_with_file_write__(true, file, "");
  }
  
  /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the file output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param file A file output stream.
  /// @param value The value to write,
  template<class arg_t>
  void println(FILE* file, arg_t&& value) {
    __xtd_print_with_file_write__(true, file, string::format("{}",  value));
  }
  
  /// @cond
  template<class type_t>
  void println(FILE* file, const std::initializer_list<type_t>& il) {
    __xtd_print_with_file_write__(true, file, string::format("{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const xtd::string& fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(true, file, string::format(fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(true, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char8_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(true, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char16_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(true, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char32_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(true, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const wchar_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(true, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  
  /// @brief Writes the current line terminator to the output stream using the specified format information.
  /// @param os The output stream to insert data into.
  inline void println(std::ostream& os) {
    __xtd_print_with_ostream_write__(true, os, "");
  }
  
  /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param os The output stream to insert data into.
  /// @param value The value to write,
  template<class arg_t>
  void println(std::ostream& os, arg_t&& value) {
    __xtd_print_with_ostream_write__(true, os, string::format("{}",  value));
  }
  
  /// @cond
  template<class type_t>
  void println(std::ostream& os, const std::initializer_list<type_t>& il) {
    __xtd_print_with_ostream_write__(true, os, string::format("{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const xtd::string& fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(true, os, string::format(fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(true, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char8_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(true, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char16_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(true, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char32_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(true, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const wchar_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(true, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  
  /// @brief Writes the current line terminator to the standard output stream using the specified format information.
  inline void println() {xtd::println(stdout);}
  
  /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the standard output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param value The value to write,
  template<class arg_t>
  void println(arg_t&& value) {xtd::println(stdout, value);}
  
  /// @cond
  template<class type_t>
  void println(const std::initializer_list<type_t>& il) {xtd::println(stdout, il);}
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const xtd::string& fmt, args_t&& ... values) {xtd::println(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char* fmt, args_t&& ... values) {xtd::println(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char8_t* fmt, args_t&& ... values) {xtd::println(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char16_t* fmt, args_t&& ... values) {xtd::println(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char32_t* fmt, args_t&& ... values) {xtd::println(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const wchar_t* fmt, args_t&& ... values) {xtd::println(stdout, fmt, std::forward<args_t>(values)...);}
}
