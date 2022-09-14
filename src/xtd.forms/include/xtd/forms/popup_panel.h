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
      /// @brief Gets ignore mouse messages
      /// @return value If true, the popup panel does not close automatically when the user clicks outside the popup panel; otherwise the popup panel will close automatically. The default value is false.
      bool ignore_mouse_messages() const;
      /// @brief Sets ignore mouse messages
      /// @param value If true, the popup panel does not close automatically when the user clicks outside the popup panel; otherwise the popup panel will close automatically. The default value is false.
      /// @return The current popup panel instance.
      popup_panel& ignore_mouse_messages(bool value);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const override;
      /// @}

      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      void on_layout(const event_args& e) override;
      void on_region_changed(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_show(message& message);
      
      bool ignore_mouse_messages_ = false;
    };
  }
}
