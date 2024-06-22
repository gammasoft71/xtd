/// @file
/// @brief Contains xtd::object_ref alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "object.h"
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents an object reference.
  /// @par Header
  /// ```cpp
  /// #include <xtd/forms/object_ref>
  /// ```
    /// @par Namespace
  /// xtd::forms
  /// @par Library
  /// xtd.forms
  /// @ingroup xtd_core
  using object_ref = std::reference_wrapper<object>;
}
