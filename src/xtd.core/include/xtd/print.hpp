/// @file
/// @brief Contains xtd::print methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

#define __XTD_CORE_INTERNAL__
#include "internal/__print.hpp"
#undef __XTD_CORE_INTERNAL__
#include "globalization/culture_info.hpp"
#include "string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the text representation of the specified value to the file output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param file A file output stream.
  /// @param value The value to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename arg_t>
  auto print(FILE* file, arg_t&& value) -> void {
    __xtd_print_with_file_write__(false, file, string::format("{}",  value));
  }
  
  /// @cond
  template<typename type_t>
  auto print(FILE* file, std::initializer_list<type_t>&& il) -> void {
    __xtd_print_with_file_write__(false, file, string::format("{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const xtd::string& fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const char* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const char8_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const char16_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const char32_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const wchar_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  
  /// @brief Writes the text representation of the specified value to the output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param os The output stream to insert data into.
  /// @param value The value to write,
  template<typename arg_t>
  auto print(std::ostream& os, arg_t&& value) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format("{}",  value));
  }
  
  /// @cond
  template<typename type_t>
  auto print(std::ostream& os, std::initializer_list<type_t>&& il) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format("{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const xtd::string& fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const char* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const char8_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const char16_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const char32_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const wchar_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  
  /// @brief Writes the text representation of the specified value to the standard output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param value The value to write,
  template<typename arg_t>
  auto print(arg_t&& value) -> void {print(stdout, value);}
  
  /// @cond
  template<typename type_t>
  auto print(std::initializer_list<type_t>&& il) -> void {print(stdout, il);}
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const xtd::string& fmt, args_t&& ... values) -> void {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const char* fmt, args_t&& ... values) -> void {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const char8_t* fmt, args_t&& ... values) -> void {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const char16_t* fmt, args_t&& ... values) -> void {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const char32_t* fmt, args_t&& ... values) -> void {print(stdout, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const wchar_t* fmt, args_t&& ... values) -> void {print(stdout, fmt, std::forward<args_t>(values)...);}
  
  /// @brief Writes the text representation of the specified value to the file output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param file A file output stream.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param value The value to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename arg_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, arg_t&& value) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, "{}",  value));
  }
  
  /// @cond
  template<typename type_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, std::initializer_list<type_t>&& il) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, "{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, const xtd::string& fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, const char* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, const char8_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, const char16_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, const char32_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the file output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param file A file output stream.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  /// @exception xtd::null_pointer_exception the `file`pointer is null.
  template<typename ...args_t>
  auto print(FILE* file, const xtd::globalization::culture_info& culture, const wchar_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_file_write__(false, file, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  
  /// @brief Writes the text representation of the specified value to the output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param os The output stream to insert data into.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param value The value to write,
  template<typename arg_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, arg_t&& value) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, "{}",  value));
  }
  
  /// @cond
  template<typename type_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, std::initializer_list<type_t>&& il) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, "{}",  il));
  }
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, const xtd::string& fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, fmt, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, const char* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, const char8_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, const char16_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, const char32_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  /// @brief Writes the text representation of the specified list of values to the output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param os The output stream to insert data into.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(std::ostream& os, const xtd::globalization::culture_info& culture, const wchar_t* fmt, args_t&& ... values) -> void {
    __xtd_print_with_ostream_write__(false, os, string::format(culture, xtd::string {fmt}, std::forward<args_t>(values)...));
  }
  
  /// @brief Writes the text representation of the specified value to the standard output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param value The value to write,
  template<typename arg_t>
  auto print(const xtd::globalization::culture_info& culture, arg_t&& value) -> void {print(stdout, culture, value);}
  
  /// @cond
  template<typename type_t>
  auto print(const xtd::globalization::culture_info& culture, std::initializer_list<type_t>&& il) -> void {print(stdout, culture, il);}
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const xtd::globalization::culture_info& culture, const xtd::string& fmt, args_t&& ... values) -> void {print(stdout, culture, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const xtd::globalization::culture_info& culture, const char* fmt, args_t&& ... values) -> void {print(stdout, culture, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const xtd::globalization::culture_info& culture, const char8_t* fmt, args_t&& ... values) -> void {print(stdout, culture, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const xtd::globalization::culture_info& culture, const char16_t* fmt, args_t&& ... values) -> void {print(stdout, culture, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const xtd::globalization::culture_info& culture, const char32_t* fmt, args_t&& ... values) -> void {print(stdout, culture, fmt, std::forward<args_t>(values)...);}
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param culture The xtd::globalization::culture_info used to print value.
  /// @param fmt A composite format string.
  /// @param values Values to write,
  template<typename ...args_t>
  auto print(const xtd::globalization::culture_info& culture, const wchar_t* fmt, args_t&& ... values) -> void {print(stdout, culture, fmt, std::forward<args_t>(values)...);}
}
