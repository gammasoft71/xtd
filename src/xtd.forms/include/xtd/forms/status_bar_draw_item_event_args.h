/// @file
/// @brief Contains xtd::forms::status_bar_draw_item_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "draw_item_event_args"
#include "status_bar_panel"
#include <xtd/any>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::status_bar::draw_item event.
    /// @par Header
    /// @code #include <xtd/forms/status_bar_draw_item_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The xtd::forms::status_bar::draw_item event occurs when a visual aspect of an owner-drawn xtd::forms::status_bar_panel changes. A xtd::forms::status_bar_draw_item_event_args specifies the xtd::drawing::graphics object to use to draw the panel, the xtd::drawing::rectangle object in which to draw the panel, the panel identification number, state information about the panel, and the panel to draw. You can use the data provided by this class in an event handler for the xtd::forms::status_bar::draw_item event to create custom-drawn panels in your application's xtd::forms::status_bar control.
    class status_bar_draw_item_event_args : public draw_item_event_args {
    public:
      /// @cond
      status_bar_draw_item_event_args(const status_bar_draw_item_event_args&) = default;
      status_bar_draw_item_event_args& operator =(const status_bar_draw_item_event_args&) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::status_bar_draw_item_event_args class without specifying a background and foreground color for the xtd::forms::status_bar_panel.
      /// @param g The xtd::drawing::graphics to use to draw the xtd::forms::status_bar_panel.
      /// @param font The xtd::drawing::font used to render text.
      /// @param r The xtd::drawing::rectangle that represents the client area of the xtd::forms::status_bar_panel.
      /// @param item_id The zero-based index of the panel in the xtd::forms::status_bar::status_bar_panel_collection of the xtd::forms::status_bar control.
      /// @param item_state One of the xtd::forms::draw_item_state values that represents state information about the xtd::forms::status_bar_panel.
      /// @param panel A xtd::forms::tool_bar_panel that represents the panel to draw.
      status_bar_draw_item_event_args(xtd::drawing::graphics& g, const xtd::drawing::font& font, const xtd::drawing::rectangle& r, size_t item_id, xtd::forms::draw_item_state item_state, const xtd::forms::status_bar_panel& panel) : draw_item_event_args(g, font, r, item_id, item_state), panel_(panel) {}
      /// @brief Initializes a new instance of the xtd::forms::status_bar_draw_item_event_args class without specifying a background and foreground color for the xtd::forms::status_bar_panel.
      /// @param g The xtd::drawing::graphics to use to draw the xtd::forms::status_bar_panel.
      /// @param font The xtd::drawing::font used to render text.
      /// @param r The xtd::drawing::rectangle that represents the client area of the xtd::forms::status_bar_panel.
      /// @param item_id The zero-based index of the panel in the xtd::forms::status_bar::status_bar_panel_collection of the xtd::forms::status_bar control.
      /// @param item_state One of the xtd::forms::draw_item_state values that represents state information about the xtd::forms::status_bar_panel.
      /// @param panel A xtd::forms::tool_bar_panel that represents the panel to draw.
      /// @param handle An internal handle.
      status_bar_draw_item_event_args(xtd::drawing::graphics& g, const xtd::drawing::font& font, const xtd::drawing::rectangle& r, size_t item_id, xtd::forms::draw_item_state item_state, const xtd::forms::status_bar_panel& panel, intptr handle) : draw_item_event_args(g, font, r, item_id, item_state), panel_(panel), handle_(handle) {}
      /// @brief Initializes a new instance of the xtd::forms::status_bar_draw_item_event_args class without specifying a background and foreground color for the xtd::forms::status_bar_panel.
      /// @param g The xtd::drawing::graphics to use to draw the xtd::forms::status_bar_panel.
      /// @param font The xtd::drawing::font used to render text.
      /// @param r The xtd::drawing::rectangle that represents the client area of the xtd::forms::status_bar_panel.
      /// @param item_id The zero-based index of the panel in the xtd::forms::status_bar::status_bar_panel_collection of the xtd::forms::status_bar control.
      /// @param item_state One of the xtd::forms::draw_item_state values that represents state information about the xtd::forms::status_bar_panel.
      /// @param panel A xtd::forms::tool_bar_panel that represents the panel to draw.
      status_bar_draw_item_event_args(xtd::drawing::graphics& g, const xtd::drawing::font& font, const xtd::drawing::rectangle& r, size_t item_id, xtd::forms::draw_item_state item_state, const xtd::forms::status_bar_panel& panel, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) : draw_item_event_args(g, font, r, item_id, item_state, back_color, fore_color), panel_(panel) {}
      /// @brief Initializes a new instance of the xtd::forms::status_bar_draw_item_event_args class without specifying a background and foreground color for the xtd::forms::status_bar_panel.
      /// @param g The xtd::drawing::graphics to use to draw the xtd::forms::status_bar_panel.
      /// @param font The xtd::drawing::font used to render text.
      /// @param r The xtd::drawing::rectangle that represents the client area of the xtd::forms::status_bar_panel.
      /// @param item_id The zero-based index of the panel in the xtd::forms::status_bar::status_bar_panel_collection of the xtd::forms::status_bar control.
      /// @param item_state One of the xtd::forms::draw_item_state values that represents state information about the xtd::forms::status_bar_panel.
      /// @param panel A xtd::forms::tool_bar_panel that represents the panel to draw.
      /// @param handle An internal handle.
      status_bar_draw_item_event_args(xtd::drawing::graphics& g, const xtd::drawing::font& font, const xtd::drawing::rectangle& r, size_t item_id, xtd::forms::draw_item_state item_state, const xtd::forms::status_bar_panel& panel, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, intptr handle) : draw_item_event_args(g, font, r, item_id, item_state, back_color, fore_color), panel_(panel), handle_(handle) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the xtd::forms::tool_bar_panel to draw.
      /// @return The xtd::forms::tool_bar_panel to draw.
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
