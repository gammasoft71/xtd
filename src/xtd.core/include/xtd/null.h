/// @file
/// @brief Contains xtd::null pointer valiue.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include "core_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a null pointer value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/null>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// ```cpp
  /// xtd::uptr<foo_class> foo = xtd::new_uptr<foo_class>();
  /// ...
  /// foo = null; // release the unique pointer.
  /// ```
  /// @ingroup xtd_core types
  extern core_export_ std::nullptr_t null;
}
