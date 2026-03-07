/// @file
/// @brief Contains #typeof_ keyword.
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
  /// xtd::type_object type1 = type_of<int32>();
  ///
  /// int32 i = 42;
  /// // Get the type object of an object :
  /// xtd::type_object type2 = type_of(i);
  /// ```
  /// @remarks The type_of operator cannot be overloaded.
  template<class type_t>
  xtd::type_object type_of() noexcept {return xtd::type_object(typeid(type_t));}
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
  /// xtd::type_object type1 = type_of<int32>();
  ///
  /// int32 i = 42;
  /// // Get the type object of an object :
  /// xtd::type_object type2 = type_of(i);
  /// ```
  /// @remarks The type_of operator cannot be overloaded.
  template<class type_t>
  xtd::type_object type_of(const type_t& value) noexcept {return xtd::type_object(typeid(value));}
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
  /// xtd::type_object type1 = type_of<int32>();
  ///
  /// int32 i = 42;
  /// // Get the type object of an object :
  /// xtd::type_object type2 = type_of(i);
  /// ```
  /// @remarks The type_of operator cannot be overloaded.
  inline xtd::type_object type_of(const xtd::type& value) noexcept {return xtd::type_object(value);}
}

/// @brief Used to obtain the type object of a specified type or object.
/// @return THe xtd::type_object that represent the type or the object.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// ```cpp
/// // Get the type object of a type :
/// xtd::type_object type1 = typeof_<int32>();
///
/// int32 i = 42;
/// // Get the type object of an object :
/// xtd::type_object type2 = typeof_(i);
/// ```
/// @remarks The typeof_ operator cannot be overloaded.
#define typeof_ \
xtd::type_of
