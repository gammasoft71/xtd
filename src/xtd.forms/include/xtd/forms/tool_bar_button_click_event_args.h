/// @file
/// @brief Contains xtd::forms::tool_bar_button_click_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "tool_bar_button.h"
#include <xtd/any>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::tool_bar::button_click event.
    /// @par Header
    /// @code #include <xtd/forms/tool_bar_button_click_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The event occurs whenever the user clicks on a button on a xtd::forms::tool_bar control. The xtd::forms::tool_bar_button_click_event_args::button property contains the xtd::forms::tool_bar_button with the information about the button that was clicked.
    class tool_bar_button_click_event_args : public event_args {
    public:
      /// @cond
      tool_bar_button_click_event_args(const tool_bar_button_click_event_args&) = default;
      tool_bar_button_click_event_args& operator =(const tool_bar_button_click_event_args&) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::tool_bar_button_click_event_args class.
      /// @param button The xtd::forms::tool_bar_button that was clicked.
      explicit tool_bar_button_click_event_args(const xtd::forms::tool_bar_button& button) : button_(button) {}
      /// @brief Initializes a new instance of the xtd::forms::tool_bar_button_click_event_args class.
      /// @param button The xtd::forms::tool_bar_button that was clicked.
      /// @param handle An internal handle.
      tool_bar_button_click_event_args(const xtd::forms::tool_bar_button& button, intptr handle) : button_(button), handle_(handle) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the xtd::forms::tool_bar_button that was clicked.
      /// @return The xtd::forms::tool_bar_button that was clicked.
      const xtd::forms::tool_bar_button& button() const noexcept {return button_;}
      
      /// @brief Gets internal handle.
      /// @return Internal handle.
      intptr handle() const noexcept {return handle_;}
      /// @}
      
    private:
      xtd::forms::tool_bar_button button_;
      intptr handle_ = 0;
    };
  }
}
