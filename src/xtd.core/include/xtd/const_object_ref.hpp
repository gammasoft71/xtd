/// @file
/// @brief Contains xtd::const_object_ref alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "object.hpp"
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents an object reference.
  /// @par Header
  /// ```cpp
  /// #include <xtd/forms/const_object_ref>
  /// ```
    /// @par Namespace
  /// xtd::forms
  /// @par Library
  /// xtd.forms
  /// @ingroup xtd_core
  using const_object_ref = std::reference_wrapper<const object>;
}
