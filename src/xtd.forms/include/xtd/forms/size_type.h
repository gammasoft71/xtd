/// @file
/// @brief Contains xtd::forms::size_type enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how rows or columns of user interface (UI) elements should be sized relative to their container.
    /// @par Header
    /// @code #include <xtd/forms/size_type> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the size_mode property of the picture_box.
    enum class size_type {
      /// @brief The control should be automatically sized to share space with its peers.
      auto_size = 0,
      /// @brief The control should be sized to an exact number of pixels.
      absolute = 1,
      /// @brief The control should be sized as a percentage of the parent container.
      percent = 2,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::size_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::size_type> {{xtd::forms::size_type::auto_size, "auto_size"}, {xtd::forms::size_type::absolute, "absolute"}, {xtd::forms::size_type::percent, "percent"}};}
};
/// @endcond
