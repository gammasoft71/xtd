/// @file
/// @brief Contains xtd::forms::tool_bar_button_click_event_args event args.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <cstdint>
#include <xtd/event_args.h>
#include "tool_bar_button.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::tool_bar::button_click event.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class tool_bar_button_click_event_args : public event_args {
    public:
      /// @cond
      tool_bar_button_click_event_args(const tool_bar_button_click_event_args&) = default;
      tool_bar_button_click_event_args& operator=(const tool_bar_button_click_event_args&) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the DoWorkEventArgs class.
      /// @param argument Specifies an argument for an asynchronous operation.
      tool_bar_button_click_event_args(const xtd::forms::tool_bar_button& button) : button_(button) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      const xtd::forms::tool_bar_button& button() const {return button_;}
      /// @}
      
    private:
      xtd::forms::tool_bar_button button_;
    };
  }
}
