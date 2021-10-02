/// @file
/// @brief Contains xtd::forms::horizontal_layout_panel container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "horizontal_control_layout_style_collection.h"
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of horizontally aligned controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrate the use of horizontal_layout_panel container.
    /// @include horizontal_layout_panel.cpp
    class horizontal_layout_panel : public panel {
    public:
      /// @brief Initialises a new instance of horizontal layout panel class.
      horizontal_layout_panel() = default;
      
      /// @brief Gets horizontal control layout style for all child controls.
      /// @return The horizontal control layout style collection.
      const horizontal_control_layout_style_collection& control_layout_styles() const {return control_layout_styles_;}
      
      /// @brief Gets horizontal control layout style for specified child controls.
      /// @param control The control to get horizontal control layout style.
      /// @return The horizontal control layout style for the specified control.
      /// @exception xtd::argument_exception container does not contains control.
      const horizontal_control_layout_style& control_layout_style(const control_ref& control) const;
      /// @brief Sets horizontal control layout style for specified child controls.
      /// @param control The control to get horizontal control layout style.
      /// @param value The horizontal control layout style for the specified control.
      /// @exception xtd::argument_exception container does not contains control.
      horizontal_layout_panel& control_layout_style(const control_ref& control, const horizontal_control_layout_style& value);

    protected:
      void on_control_added(const xtd::forms::control_event_args& e) override;
      void on_control_removed(const xtd::forms::control_event_args& e) override;
      void on_layout(const xtd::event_args& e) override;
      
    private:
      horizontal_control_layout_style_collection control_layout_styles_;
    };
  }
}
