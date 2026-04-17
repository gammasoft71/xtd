/// @file
/// @brief Contains xtd::size_of methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "usize.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Used to obtain the size in bytes of the object representation of type or expression.
  /// @par Examples
  /// ```cpp
  /// // Get the size of a type :
  /// xtd::usize size1 = xtd::size_of<int>();
  ///
  /// int i = 42;
  /// // Get the size of an object :
  /// xtd::usize size2 = xtd::size_of(i);
  /// ```
  /// @remarks The size_of operator cannot be overloaded.
  template<typename type_t>
  auto size_of() noexcept -> xtd::usize {return sizeof(type_t);}
  /// @brief Used to obtain the size in bytes of the object representation of type or expression.
  /// @par Examples
  /// ```cpp
  /// // Get the size of a type :
  /// xtd::usize size1 = xtd::size_of<int>();
  ///
  /// int i = 42;
  /// // Get the size of an object :
  /// xtd::usize size2 = xtd::size_of(i);
  /// ```
  /// @remarks The size_of operator cannot be overloaded.
  xtd::usize size_of(const auto& value) noexcept {return sizeof(value);}
  /// @brief Used to obtain the size in bytes of the object representation of type or expression.
  /// @par Examples
  /// ```cpp
  /// // Get the size of a type :
  /// xtd::usize size1 = xtd::size_of<int>();
  ///
  /// int i = 42;
  /// // Get the size of an object :
  /// xtd::usize size2 = xtd::size_of(i);
  /// ```
  /// @remarks The size_of operator cannot be overloaded.
  inline xtd::usize size_of(const xtd::type& value) noexcept {return sizeof(value);}
}
