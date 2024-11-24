/// @file
/// @brief Contains xtd::print methods.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "console.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the text representation of the specified value to the standard output stream.
  /// @tparam arg_t The type of the value to write.
  /// @param value The value to write,
  template<typename arg_t>
  void print(arg_t&& value) {xtd::console::write(xtd::string::format("{}",  value));}
  
  /// @cond
  template<typename type_t>
  void print(std::initializer_list<type_t>&& il) {xtd::console::write(xtd::string::format("{}", il));}
  /// @endcond
  
  /// @brief Writes the text representation of the specified list of values to the standard output stream using the specified format information.
  /// @tparam ...args_t Types of the values to write.
  /// @param values Values to write,
  template<typename ... args_t>
  void print(const xtd::string& fmt, args_t&& ... values) {xtd::console::write(xtd::string::format(fmt, std::forward<args_t>(values)...));}
}
