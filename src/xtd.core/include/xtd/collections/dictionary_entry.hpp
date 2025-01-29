/// @file
/// @brief Contains xtd::collections::dictionary_entry alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/key_value_pair.hpp"
#include "../any_object.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Defines a dictionary key/value pair that can be set or retrieved.
    /// ```cpp
    /// using dictionary_entry = xtd::collections::generic::key_value_pair<xtd::any_object, xtd::any_object>;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/dictionary_entry>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    using dictionary_entry = xtd::collections::generic::key_value_pair<xtd::any_object, xtd::any_object>;
  }
}
