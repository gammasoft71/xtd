/// @file
/// @brief Contains xtd::collections::specialized::string_vector typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include "../../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
    namespace specialized {
      /// @brief Represents a collection of strings.
      /// @par Namespace
      /// xtd::collections
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core collections
      using string_vector = std::vector<xtd::ustring>;
    }
  }
}
