/// @file
/// @brief Contains xtd::collections::specialized::string_pair typedef.
#pragma once
#include <string>
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
    namespace specialized {
      /// @brief Implements a std::pair with the key and the value strongly typed to be strings.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      using string_pair = std::pair<std::string, std::string>;
    }
  }
}
