/// @file
/// @brief Contains xtd::forms::status_bar_panel_click_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "status_bar_panel"
#include <xtd/any>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::tool_bar::button_click event.
    /// @par Header
    /// @code #include <xtd/forms/status_bar_panel_click_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The event occurs whenever the user clicks on a button on a xtd::forms::tool_bar control. The xtd::forms::status_bar_panel_click_event_args::button property contains the xtd::forms::status_bar_panel with the information about the button that was clicked.
    class status_bar_panel_click_event_args : public event_args {
    public:
      /// @cond
      status_bar_panel_click_event_args(const status_bar_panel_click_event_args&) = default;
      status_bar_panel_click_event_args& operator =(const status_bar_panel_click_event_args&) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::status_bar_panel_click_event_args class.
      /// @param button The xtd::forms::status_bar_panel that was clicked.
      explicit status_bar_panel_click_event_args(const xtd::forms::status_bar_panel& panel) : panel_(panel) {}
      /// @brief Initializes a new instance of the xtd::forms::status_bar_panel_click_event_args class.
      /// @param button The xtd::forms::status_bar_panel that was clicked.
      /// @param handle An internal handle.
      status_bar_panel_click_event_args(const xtd::forms::status_bar_panel& panel, intptr handle) : panel_(panel), handle_(handle) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the xtd::forms::status_bar_panel that was clicked.
      /// @return The xtd::forms::status_bar_panel that was clicked.
      const xtd::forms::status_bar_panel& panel() const noexcept {return panel_;}
      
      /// @brief Gets internal handle.
      /// @return Internal handle.
      intptr handle() const noexcept {return handle_;}
      /// @}
      
    private:
      xtd::forms::status_bar_panel panel_;
      intptr handle_ = 0;
    };
  }
}
