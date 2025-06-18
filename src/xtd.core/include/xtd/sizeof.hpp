/// @file
/// @brief Contains #sizeof_ keyword.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "size.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace __s__ {
    template<class type_t>
    xtd::size __sizeof_() noexcept {
      return sizeof(type_t);
    }
    
    template<class type_t>
    xtd::size __sizeof_(const type_t& value) noexcept {
      return sizeof(value);
    }
    
    inline xtd::size __sizeof_(const xtd::type& value) noexcept {
      return sizeof(value);
    }
  }
  /// @endcond

  /// @brief Used to obtain the size in bytes of the object representation of type or expression.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// ```cpp
  /// // Get the size of a type :
  /// xtd::size size1 = sizeof_<int32>();
  ///
  /// int32 i = 42;
  /// // Get the size of an object :
  /// xtd::size size2 = sizeof_(i);
  /// ```
  /// @remarks The typeof_ operator cannot be overloaded.
  #define sizeof_ \
    xtd::__s__::__sizeof_
}
