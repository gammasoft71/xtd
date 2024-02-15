/// @file
/// @brief Contains xtd::forms::h_scroll_bar control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "scroll_bar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows horizontal scroll bar.
    /// @par Header
    /// @code #include <xtd/forms/h_scroll_bar> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html control_h_scroll_bar_w.png   |  @image html control_h_scroll_bar_m.png   |  @image html control_h_scroll_bar_g.png   |
    /// | Dark  |  @image html control_h_scroll_bar_wd.png  |  @image html control_h_scroll_bar_md.png  |  @image html control_h_scroll_bar_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of h_scroll_bar control.
    /// @include h_scroll_bar.cpp
    class forms_export_ h_scroll_bar : public scroll_bar {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of h_scroll_bar class.
      h_scroll_bar();
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 minimum = 0, int32 maximum = 100, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 minimum = 0, int32 maximum = 100, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      xtd::forms::create_params create_params() const noexcept override;
      xtd::drawing::size default_size() const noexcept override;
      /// @}
    };
  }
}
