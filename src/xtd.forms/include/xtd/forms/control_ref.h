/// @file
/// @brief Contains xtd::forms::control_ref typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Represents a control reference.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using control_ref = std::reference_wrapper<control>;
  }
}
