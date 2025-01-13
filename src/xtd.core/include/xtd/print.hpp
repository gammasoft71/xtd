/// @file
/// @brief Contains xtd::print methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#define __XTD_CORE_INTERNAL__
#include "internal/__print.hpp"
#undef __XTD_CORE_INTERNAL__
#include "string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the text representation of the specified value to the file output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param file A file output stream.
  /// @param value The value to write,
  /// @exceprion xtd::null_pointer_exception the `file`pointer is null.
  template<class arg_t>
  void print(FILE* file, arg_t&& value) {
    __xtd_print_with_file_write__(file, string::format("{}",  value));
  }
  
  /// @cond
  template<class type_t>
  void print(FILE* file, std::initializer_list<type_t>&& il) {
    __xtd_print_with_file_write__(file, string::format("{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exceprion xtd::null_pointer_exception the `file`pointer is null.
  template<class ...args_t>
  void print(FILE* file, const xtd::string& fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(file, string::format(fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exceprion xtd::null_pointer_exception the `file`pointer is null.
  template<class ...args_t>
  void print(FILE* file, const char* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exceprion xtd::null_pointer_exception the `file`pointer is null.
  template<class ...args_t>
  void print(FILE* file, const char8_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
#endif
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exceprion xtd::null_pointer_exception the `file`pointer is null.
  template<class ...args_t>
  void print(FILE* file, const char16_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exceprion xtd::null_pointer_exception the `file`pointer is null.
  template<class ...args_t>
  void print(FILE* file, const char32_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exceprion xtd::null_pointer_exception the `file`pointer is null.
  template<class ...args_t>
  void print(FILE* file, const wchar_t* fmt, args_t&& ... values) {
    __xtd_print_with_file_write__(file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }

  /// @brief Writes the text representation of the specified value to the output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param os The output stream to insert data into.
  /// @param value The value to write,
  template<class arg_t>
  void print(std::ostream& os, arg_t&& value) {
    __xtd_print_with_ostream_write__(os, string::format("{}",  value));
  }
  
  /// @cond
  template<class type_t>
  void print(std::ostream& os, std::initializer_list<type_t>&& il) {
    __xtd_print_with_ostream_write__(os, string::format("{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(std::ostream& os, const xtd::string& fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(os, string::format(fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(std::ostream& os, const char* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(std::ostream& os, const char8_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
#endif
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(std::ostream& os, const char16_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(std::ostream& os, const char32_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(std::ostream& os, const wchar_t* fmt, args_t&& ... values) {
    __xtd_print_with_ostream_write__(os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  
  /// @brief Writes the text representation of the specified value to the standard output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param value The value to write,
  template<class arg_t>
  void print(arg_t&& value) {print(stdout, value);}
  
  /// @cond
  template<class type_t>
  void print(std::initializer_list<type_t>&& il) {print(stdout, il);}
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(const xtd::string& fmt, args_t&& ... values) {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(const char* fmt, args_t&& ... values) {print(stdout, fmt, std::forward<args_t>(values)...);}
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(const char8_t* fmt, args_t&& ... values) {print(stdout, fmt, std::forward<args_t>(values)...);}
#endif
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(const char16_t* fmt, args_t&& ... values) {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(const char32_t* fmt, args_t&& ... values) {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<class ...args_t>
  void print(const wchar_t* fmt, args_t&& ... values) {print(stdout, fmt, std::forward<args_t>(values)...);}
  
}
