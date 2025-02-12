/// @file
/// @brief Contains #foreach_ keyword.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "from.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
  }
}

/// @brief The #foreach_ keyword executes a statement or a block of statements for each element in an instance of the type that implements the xtd::collections::ienumerable or xtd::collections::generic::ienumerable <type_t> interfaces.
/// ```cpp
/// #define foreach_(item, enumerable)
/// ```
/// @par Header
/// ```cpp
/// #include <xtd/foreach>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// The following example shows how to use #foreach_ keyword with an xtd::collection::generic::list <type_t> of xtd::string.
/// ```cpp
/// foreach_(const auto& item, list<string> {"one", "two", "three", "four"})
///   console::write_line(item);
/// ```
/// @remark `break` and `continue` statements are supported.
#define foreach_(item, ...) \
  if (const auto& __enumerable__ = xtd::linq::from(__VA_ARGS__); true) \
    for (auto __break__ = 0; __break__ == 0; __break__ = 1) \
      for (auto enumerator = __enumerable__.get_enumerator(); __break__ == 0 && enumerator.move_next();) \
        if (auto __continue__ = 1; __break__ == 0 && __continue__ > 0) \
          for (item = enumerator.current(); __continue__-- && ++__break__; __break__ = 0)
