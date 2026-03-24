/// @file
/// @brief Contains xtd::type_of methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "string.hpp"
#include "type_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Used to obtain the type object of a specified type or object.
  /// @return THe xtd::type_object that represent the type or the object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// // Get the type object of a type :
  /// xtd::type_object type1 = type_of<int>();
  ///
  /// int i = 42;
  /// // Get the type object of an object :
  /// xtd::type_object type2 = type_of(i);
  /// ```
  /// @remarks The type_of operator cannot be overloaded.
  template<typename type_t>
  auto type_of() noexcept -> const xtd::type_object& {
    static auto instance = xtd::type_object {typeid(type_t)};
    return instance;
  }
  /// @cond
  /// @brief Used to obtain the type object of a specified type or object.
  /// @return THe xtd::type_object that represent the type or the object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// // Get the type object of a type :
  /// xtd::type_object type1 = type_of<int>();
  ///
  /// int i = 42;
  /// // Get the type object of an object :
  /// xtd::type_object type2 = type_of(i);
  /// ```
  /// @remarks The type_of operator cannot be overloaded.
  auto type_of(const auto& value) noexcept -> xtd::type_object {return xtd::type_object {typeid(value)};}
  /// @cond
  /// @brief Used to obtain the type object of a specified type or object.
  /// @return THe xtd::type_object that represent the type or the object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// // Get the type object of a type :
  /// xtd::type_object type1 = type_of<int>();
  ///
  /// int i = 42;
  /// // Get the type object of an object :
  /// xtd::type_object type2 = type_of(i);
  /// ```
  /// @remarks The type_of operator cannot be overloaded.
  inline auto type_of(const xtd::type& value) noexcept -> xtd::type_object {return xtd::type_object {value};}
}
