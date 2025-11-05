/// @file
/// @brief Contains xtd::collections::specialized::ordered_dictionary alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../any_object.hpp"
#include "../generic/ordered_dictionary.hpp"
#include "../../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
    namespace specialized {
      /// @brief Represents a collection of key/value pairs that are accessible by the key or index.
      /// ```cpp
      /// using ordered_dictionary = xtd::collections::generic::ordered_dictionary<xtd::any_object, xtd::any_object>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/specialized/ordered_dictionary>
      /// ```
      /// @par Namespace
      /// xtd::collections
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core specialized_collections
      using ordered_dictionary = xtd::collections::generic::ordered_dictionary<xtd::any_object, xtd::any_object>;
    }
  }
}

