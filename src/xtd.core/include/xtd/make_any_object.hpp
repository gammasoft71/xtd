/// @file
/// @brief Contains xtd::make_any_object operator.
#pragma once
#include "any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::make_any_object operator creates a xtd::any_object object.
  /// @par Header
  /// ```cpp
  /// #include <xtd/make_any_object>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::make_any_object with xtd::version class
  /// @code
  /// any_object ver = make_any_object<version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", ver.to_string());
  /// @endcode
  template<class type_t, class ...args_t>
  any_object make_any_object(args_t&& ... args) {return any_object {type_t(args...)};}
  
  /// @cond
  template<class type_t>
  any_object make_any_object(const type_t& arg) {return any_object {arg};}
  
  template<class type_t>
  any_object make_any_object() {return any_object {type_t()};}
  /// @endcond
}
