/// @file
/// @brief Contains xtd::collections::specialized::string_map typedef.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/collection/specialized/string_dictionary.h> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/collection/specialized/string_dictionary.h> - Will be removed in version 0.4.0."
#endif
#include "string_dictionary.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
    namespace specialized {
      /// @brief Represents a std::map with the key and the value strongly typed to be strings.
      /// ```cpp
      /// using string_map = std::map<xtd::string, xtd::string>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/specialized/string_map>
      /// ```
      /// @par Namespace
      /// xtd::collections
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core specialized_collections
      /// @deprecated Replaced by xtd::collections::specialized::string_dictionary - Will be removed in version 0.4.0.
      using string_map [[deprecated("Replaced by xtd::collections::specialized::string_dictionary - Will be removed in version 0.4.0.")]] = string_dictionary;
    }
  }
}

