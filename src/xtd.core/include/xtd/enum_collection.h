/// @file
/// @brief Contains xtd::enum_collection.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a pair of an enum_t value and a string of an enum of type enum_t.
  /// @par Header
  /// @code #include <xtd/enum_collection> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks For more information about enumeration, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/enum_class">enum class</a> guide.
  template<typename enum_t>
  using enum_collection = std::vector<std::pair<enum_t, xtd::ustring>>;
}
