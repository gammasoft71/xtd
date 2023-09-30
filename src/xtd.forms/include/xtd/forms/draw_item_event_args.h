/// @file
/// @brief Contains xtd::forms::draw_item_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "control.h"
#include "draw_item_state.h"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/graphics>
#include <xtd/drawing/rectangle>
#include <xtd/drawing/system_fonts>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the @verbatim draw_item @endverbatim event.
    /// @par Header
    /// @code #include <xtd/forms/draw_item_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The @verbatim draw_item @endverbatim event is raised by owner draw controls, such as the xtd::forms::list_box and xtd::forms::combo_box controls. It contains all the information that is needed for the user to paint the specified item, including the item index, the xtd::drawing::rectangle, and the xtd::drawing::graphics on which the drawing should be done.
    class forms_export_ draw_item_event_args : public event_args {
      struct data;
      
    public:
      /// @cond
      draw_item_event_args(const draw_item_event_args& other);
      draw_item_event_args& operator =(const draw_item_event_args& other);
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::draw_item_event_args class for the specified control with the specified font, state, surface to draw on, and the bounds to draw within.
      /// @param graphics The xtd::drawing::graphics surface on which to draw.
      /// @param font The xtd::drawing::font to use, usually the parent control's Font property.
      /// @param rect The xtd::drawing::rectangle bounds to draw within.
      /// @param index The xtd::control::control_collection index value of the item that is being drawn.
      /// @param state The control's xtd::forms::drawItem_state information.
      draw_item_event_args(xtd::drawing::graphics& graphics, const xtd::drawing::font& font, const xtd::drawing::rectangle& rect, size_t index, xtd::forms::draw_item_state state);
      /// @brief Initializes a new instance of the xtd::forms::draw_item_event_args class for the specified control with the specified font, state, foreground color, background color, surface to draw on, and the bounds to draw within.
      /// @param graphics The xtd::drawing::graphics surface on which to draw.
      /// @param font The xtd::drawing::font to use, usually the parent control's Font property.
      /// @param rect The xtd::drawing::rectangle bounds to draw within.
      /// @param index The xtd::control::control_collection index value of the item that is being drawn.
      /// @param state The control's xtd::forms::drawItem_state information.
      draw_item_event_args(xtd::drawing::graphics& graphics, const xtd::drawing::font& font, const xtd::drawing::rectangle& rect, size_t index, xtd::forms::draw_item_state state, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_core);
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the background color of the item that is being drawn.
      /// @return The background xtd::drawing::color of the item that is being drawn.
      /// @remarks If the item's state is xtd::forms::draw_item_state::selected, the xtd::forms::drawing_item_event_args::back_color is set to xtd::drawing::system_colors::highlight. If the item's state is not xtd::forms::draw_item_state::selected, the xtd::forms::draw_item_event_Args::back_color property is set to xtd::drawing::system_colors::window.
      const xtd::drawing::color& back_color() const noexcept;
      
      /// @brief Gets the rectangle that represents the bounds of the item that is being drawn.
      /// @return The xtd::drawing::rectangle that represents the bounds of the item that is being drawn.
      const xtd::drawing::rectangle& bounds() const noexcept;
      
      /// @brief Gets the font that is assigned to the item being drawn.
      /// @return The xtd::drawing::font that is assigned to the item being drawn.
      /// @remarks A suggested xtd::drawing::font, usually the xtd::forms::control::font property of the parent control.
      const xtd::drawing::font& font() const noexcept;
      
      /// @brief Gets the foreground color of the of the item being drawn.
      /// @return The foreground xtd::drawing::color of the item being drawn.
      /// @remarks If the item's state is xtd::forms::draw_item_state::selected, the xtd::forms::drawing_item_event_args::fore_color is set to xtd::drawing::system_colors::highlight_text. If the item's state is not xtd::forms::draw_item_state::selected, the xtd::forms::drawing_item_event_args::fore_color property is set to xtd::drawing::system_colors::window.
      const xtd::drawing::color& fore_color() const noexcept;
      
      /// @brief Gets the graphics surface to draw the item on.
      /// @return The xtd::drawing::graphics surface to draw the item on.
      xtd::drawing::graphics& graphics() noexcept;
      
      /// @brief Gets the index value of the item that is being drawn.
      /// @return The numeric value that represents the xtd::forms::control::control_collection::operator [] value of the item being drawn.
      /// @remarks This property returns the xtd::forms::control::control_collection::operator [] value of the item being drawn in the xtd::forms::control::control_collection. This property can return xtd::forms::control::control_collection::npos if items were removed from the list.
      size_t index() const noexcept;
      
      /// @brief Gets the state of the item being drawn.
      /// @return The xtd::forms::draw_item_state that represents the state of the item being drawn.
      /// @remarks This property value can be a combination of the xtd::forms::draw_item_state enumeration members. The members can be combined by using bitwise operators.
      xtd::forms::draw_item_state state() const noexcept;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
