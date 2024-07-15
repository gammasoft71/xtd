/// @file
/// @brief Contains xtd::collections::vector_list typedef.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/collection/array_list.h> - Will be removed in version 0.4.0")
#else
#  warning "Deprecated : Replaced by #include <xtd/collection/array_list.h> - Will be removed in version 0.4.0"
#endif
#include "array_list.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Represents a collection of std::any.
    /// ```cpp
    /// using vector_list = array_list
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/vector_list>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @par Examples
    /// The following example shows hows to use xtd::collections::array_list.
    /// @include array_list.cpp
    /// @deprecated Replaced by xtd::collections::array_list - Will be removed in version 0.4.0
    using vector_list [[deprecated("Replaced by xtd::collections::array_list - Will be removed in version 0.4.0")]] = array_list;
  }
}
