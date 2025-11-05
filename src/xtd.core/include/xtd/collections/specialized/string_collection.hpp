/// @file
/// @brief Contains xtd::collections::specialized::string_collection alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../generic/list.hpp"
#include "../../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
    namespace specialized {
      /// @brief Represents a collection of strings.
      /// ```cpp
      /// using string_collection = xtd::collections::generic::list<xtd::string>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/specialized/string_collection>
      /// ```
      /// @par Namespace
      /// xtd::collections
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core specialized_collections
      using string_collection = xtd::collections::generic::list<xtd::string>;
    }
  }
}
