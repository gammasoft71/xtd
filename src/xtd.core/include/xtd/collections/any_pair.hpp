/// @file
/// @brief Contains xtd::collections::any_pair alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "dictionary_entry.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Implements a xtd::collections::generic::key_value_pair with the key and the value strongly typed to be std::any.
    /// ```cpp
    /// using any_pair = xtd::collections::dictionary_entry;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/any_pair>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @deprecated Replaced by xtd::collections::dictionary_entry - Will be removed in version 0.4.0.
    using any_pair [[deprecated("Replaced by xtd::collections::dictionary_entry - Will be removed in version 0.4.0.")]] = xtd::collections::dictionary_entry;
  }
}
