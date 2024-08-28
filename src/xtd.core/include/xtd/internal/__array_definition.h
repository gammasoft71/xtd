/// @file
/// @brief Contains array definitions.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include "../collections/generic/helpers/allocator.h"
#include "../int32.h"
#include <vector> // @todo remove line

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, there by serving as the base class for all arrays.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t>
  /// using array = std::vector<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/array>
  /// ```
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t>
  using array = std::vector<type_t>;
  //template<typename type_t = nullptr, int32 rank = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<value_t>>
  //class array;
}
