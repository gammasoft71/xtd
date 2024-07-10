/// @file
/// @brief Contains xtd::type type.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <typeinfo>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Stores information about a type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/type>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using type = std::type_info;
  /// @}
}
