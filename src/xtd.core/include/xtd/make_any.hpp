/// @file
/// @brief Contains xtd::any_cast alias on [xtd::any_cast](https://www.cppreference.com/w/cpp/utility/any/any_cast.html) operators.
#pragma once
#include "any.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Creates an xtd::any object containing an object of type type_t, passing the provided arguments to type_t's constructor.
  /// @par Header
  /// ```cpp
  /// #include <xtd/<make_any>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param args The arguments needed by type_t constructor.
  /// @return An xtd::any object created.
  template<class type_t, class... args_t>
  xtd::any make_any(args_t&&... args) {
    return std::make_any<type_t>(std::forward<args_t>(args)...);
  }
  
  /// @brief Creates an xtd::any object containing an object of type type_t, passing the provided arguments to type_t's constructor.
  /// @par Header
  /// ```cpp
  /// #include <xtd/<make_any>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param il The std::initializer_list needed by type_t constructor.
  /// @param args The arguments for type_t needed by constructor.
  /// @return An xtd::any object created.
  template<class type_t, class il_type_t, class... args_t>
  xtd::any make_any(std::initializer_list<il_type_t> il, args_t&&... args) {
    return std::make_any<type_t>(il, std::forward<args_t>(args)...);
  }
}
