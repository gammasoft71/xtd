/// @file
/// @brief Contains xtd::println methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "print.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the current line terminator to the file output stream using the specified format information.
  /// @param file A file output stream.
  inline void println(FILE* file) {xtd::print(file, environment::new_line());}
  
  /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the file output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param file A file output stream.
  /// @param value The value to write,
  template<class arg_t>
  void println(FILE* file, arg_t&& value) {
    xtd::print(file, value);
    xtd::print(file, environment::new_line());
  }
  
  /// @cond
  template<class type_t>
  void println(FILE* file, const std::initializer_list<type_t>& il) {
    xtd::print(file, il);
    xtd::print(file, environment::new_line());
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const xtd::string& fmt, args_t&& ... values) {
    xtd::print(file, fmt, std::forward<args_t>(values)...);
    xtd::print(file, environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char* fmt, args_t&& ... values) {
    xtd::print(file, fmt, std::forward<args_t>(values)...);
    xtd::print(file, environment::new_line());
  }
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char8_t* fmt, args_t&& ... values) {
    xtd::print(file, fmt, std::forward<args_t>(values)...);
    xtd::print(file, environment::new_line());
  }
#endif
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char16_t* fmt, args_t&& ... values) {
    xtd::print(file, fmt, std::forward<args_t>(values)...);
    xtd::print(file, environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const char32_t* fmt, args_t&& ... values) {
    xtd::print(file, fmt, std::forward<args_t>(values)...);
    xtd::print(file, environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(FILE* file, const wchar_t* fmt, args_t&& ... values) {
    xtd::print(file, fmt, std::forward<args_t>(values)...);
    xtd::print(file, environment::new_line());
  }
  
  /// @brief Writes the current line terminator to the output stream using the specified format information.
  /// @param os The output stream to insert data into.
  inline void println(std::ostream& os) {xtd::print(os, environment::new_line());}
  
  /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param os The output stream to insert data into.
  /// @param value The value to write,
  template<class arg_t>
  void println(std::ostream& os, arg_t&& value) {
    xtd::print(os, value);
    xtd::print(os, environment::new_line());
  }
  
  /// @cond
  template<class type_t>
  void println(std::ostream& os, const std::initializer_list<type_t>& il) {
    xtd::print(os, il);
    xtd::print(os, environment::new_line());
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const xtd::string& fmt, args_t&& ... values) {
    xtd::print(os, fmt, std::forward<args_t>(values)...);
    xtd::print(os, environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char* fmt, args_t&& ... values) {
    xtd::print(os, fmt, std::forward<args_t>(values)...);
    xtd::print(os, environment::new_line());
  }
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char8_t* fmt, args_t&& ... values) {
    xtd::print(os, fmt, std::forward<args_t>(values)...);
    xtd::print(os, environment::new_line());
  }
#endif
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char16_t* fmt, args_t&& ... values) {
    xtd::print(os, fmt, std::forward<args_t>(values)...);
    xtd::print(os, environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const char32_t* fmt, args_t&& ... values) {
    xtd::print(os, fmt, std::forward<args_t>(values)...);
    xtd::print(os, environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(std::ostream& os, const wchar_t* fmt, args_t&& ... values) {
    xtd::print(os, fmt, std::forward<args_t>(values)...);
    xtd::print(os, environment::new_line());
  }
  
  /// @brief Writes the current line terminator to the standard output stream using the specified format information.
  inline void println() {xtd::print(environment::new_line());}
  
  /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the standard output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param value The value to write,
  template<class arg_t>
  void println(arg_t&& value) {
    xtd::print(value);
    xtd::print(environment::new_line());
  }
  
  /// @cond
  template<class type_t>
  void println(const std::initializer_list<type_t>& il) {
    xtd::print(il);
    xtd::print(environment::new_line());
  }
  /// @endcond

  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const xtd::string& fmt, args_t&& ... values) {
    xtd::print(fmt, std::forward<args_t>(values)...);
    xtd::print(environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char* fmt, args_t&& ... values) {
    xtd::print(fmt, std::forward<args_t>(values)...);
    xtd::print(environment::new_line());
  }
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char8_t* fmt, args_t&& ... values) {
    xtd::print(fmt, std::forward<args_t>(values)...);
    xtd::print(environment::new_line());
  }
#endif
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char16_t* fmt, args_t&& ... values) {
    xtd::print(fmt, std::forward<args_t>(values)...);
    xtd::print(environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const char32_t* fmt, args_t&& ... values) {
    xtd::print(fmt, std::forward<args_t>(values)...);
    xtd::print(environment::new_line());
  }
  /// @brief Writes the text representation of the specified list of values, followed by the current line terminator, to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void println(const wchar_t* fmt, args_t&& ... values) {
    xtd::print(fmt, std::forward<args_t>(values)...);
    xtd::print(environment::new_line());
  }
}
