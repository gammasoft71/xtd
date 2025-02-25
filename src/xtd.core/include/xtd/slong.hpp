/// @file
/// @brief Contains xtd::slong type.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#define __XTD_VALUE_TYPE_NATIVE__
#include <xtd/native/value_types>
#undef __XTD_VALUE_TYPE_NATIVE__
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a 32-bit or 64-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/slong>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  using slong = __slong__; // Workaround : On linux 64 bits unfortunately 'int64_t' is an alias on 'long' and not on 'long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
  /// @}
}
