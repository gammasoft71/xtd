/// @file
/// @brief Contains xtd::enum_collection.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/key_value_pair.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a pair of an enum_t value and a string of an enum of type enum_t.
  /// @par Header
  /// ```cpp
  /// #include <xtd/enum_collection>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks For more information about enumeration, see [enum class](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/enum_class) guide.
  template<typename enum_t>
  using enum_collection = std::vector<xtd::collections::generic::key_value_pair<enum_t, xtd::ustring>>;
}
