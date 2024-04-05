/// @file
/// @brief Contains #typeof_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"
#include "type_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace __s__ {
    template<typename type_t>
    xtd::type_object __typeof_() noexcept {
      return xtd::type_object(typeid(type_t));
    }
    
    template<typename type_t>
    xtd::type_object __typeof_(const type_t& value) noexcept {
      return xtd::type_object(typeid(value));
    }

    inline xtd::type_object __typeof_(const xtd::type& value) noexcept {
      return xtd::type_object(value);
    }
  }
  /// @endcond
  
  /// @brief Used to obtain the type object of a specified type or object.
  /// @return THe xtd::type_object that represent the type or the object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// @code
  /// // Get the type object of a type :
  /// xtd::type_object type1 = typeof_<int32>();
  ///
  /// int32 i = 42;
  /// // Get the type object of an object :
  /// xtd::type_object type2 = typeof_(i);
  /// @endcode
  /// @remarks The typeof_ operator cannot be overloaded.
#define typeof_ \
  xtd::__s__::__typeof_
}
