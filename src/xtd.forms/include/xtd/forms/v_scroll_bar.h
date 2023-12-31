/// @file
/// @brief Contains xtd::forms::v_scroll_bar control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "scroll_bar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows horizontal scroll bar.
    /// @par Header
    /// @code #include <xtd/forms/v_scroll_bar> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html control_v_scroll_bar_w.png   |  @image html control_v_scroll_bar_m.png   |  @image html control_v_scroll_bar_g.png   |
    /// | Dark  |  @image html control_v_scroll_bar_wd.png  |  @image html control_v_scroll_bar_md.png  |  @image html control_v_scroll_bar_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of v_scroll_bar control.
    /// @include v_scroll_bar.cpp
    class forms_export_ v_scroll_bar : public scroll_bar {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of v_scroll_bar class.
      v_scroll_bar();
      /// @}
      
    protected:
      /// @name Protectedd properties
      
      /// @{
      xtd::forms::create_params create_params() const noexcept override;
      xtd::drawing::size default_size() const noexcept override;
      /// @}
    };
  }
}
