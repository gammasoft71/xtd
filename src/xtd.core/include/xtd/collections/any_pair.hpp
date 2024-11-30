/// @file
/// @brief Contains xtd::collections::any_pair typedef.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "generic/key_value_pair.hpp"
#include "../any.hpp"
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Implements a std::pair with the key and the value strongly typed to be std::any.
    /// ```cpp
    /// using any_pair = xtd::collections::generic::key_value_pair<std::any, std::any>
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
    using any_pair = xtd::collections::generic::key_value_pair<std::any, std::any>;
  }
}
