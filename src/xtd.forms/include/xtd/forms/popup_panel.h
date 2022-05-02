/// @file
/// @brief Contains xtd::forms::popup_panel container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a special type of panel container that can be used for context menus, combo_box popups and more.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrates the use of popup_panel container.
    /// @include popup_panel.cpp
    class forms_export_ popup_panel : public panel {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the popup_panel class.
      popup_panel();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the control and all its child controls are displayed.
      /// @return true if the control and all its child controls are displayed; otherwise, false. The default is true.
      bool visible() const override;
      /// @brief Sets a value indicating whether the control and all its child controls are displayed.
      /// @param visible true if the control and all its child controls are displayed; otherwise, false. The default is true.
      /// @return Current control.
      control& visible(bool visible) override;
      /// @}
      
      /// @name Metthods
      
    protected:
      /// @name Protected methods
      
      /// @{
      forms::create_params create_params() const override;
      void on_layout(const event_args& e) override;
      void wnd_proc(message& message) override;

      /// @brief Processes the show window message for the control.
      /// @param message The message sent to the control.
      virtual void wm_show(message& message);
      /// @}
      
    private:
    };
  }
}
