/// @file
/// @brief Contains xtd::forms::draw_item_event_args event args.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <xtd/event_args.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/drawing/system_fonts.h>
#include "control.h"
#include "draw_item_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the @verbatim draw_item @endverbatim event.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The @verbatim draw_item @endverbatim event is raised by owner draw controls, such as the xtd::forms::list_box and xtd::forms::combo_box controls. It contains all the information that is needed for the user to paint the specified item, including the item index, the xtd::drawing::rectangle, and the xtd::drawing::graphics on which the drawing should be done.
    class draw_item_event_args : public event_args {
    public:
      /// @cond
      draw_item_event_args(const draw_item_event_args&) = default;
      draw_item_event_args& operator =(const draw_item_event_args&) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::draw_item_event_args class for the specified control with the specified font, state, surface to draw on, and the bounds to draw within.
      /// @param graphics The xtd::drawing::graphics surface on which to draw.
      /// @param font The xtd::drawing::font to use, usually the parent control's Font property.
      /// @param rect The xtd::drawing::rectangle bounds to draw within.
      /// @param index The xtd::control::control_collection index value of the item that is being drawn.
      /// @param state The control's xtd::forms::drawItem_state information.
      draw_item_event_args(xtd::drawing::graphics& graphics, const xtd::drawing::font& font, const xtd::drawing::rectangle& rect, size_t index, xtd::forms::draw_item_state state) {
        data_->font = font;
        data_->graphics = &graphics;
        data_->index = index;
        data_->state = state;
      }
      /// @brief Initializes a new instance of the xtd::forms::draw_item_event_args class for the specified control with the specified font, state, foreground color, background color, surface to draw on, and the bounds to draw within.
      /// @param graphics The xtd::drawing::graphics surface on which to draw.
      /// @param font The xtd::drawing::font to use, usually the parent control's Font property.
      /// @param rect The xtd::drawing::rectangle bounds to draw within.
      /// @param index The xtd::control::control_collection index value of the item that is being drawn.
      /// @param state The control's xtd::forms::drawItem_state information.
      draw_item_event_args(xtd::drawing::graphics& graphics, const xtd::drawing::font& font, const xtd::drawing::rectangle& rect, size_t index, xtd::forms::draw_item_state state, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_core) {
        data_->back_color = back_color;
        data_->font = font;
        data_->fore_color = back_color;
        data_->graphics = &graphics;
        data_->index = index;
        data_->state = state;
      }
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the background color of the item that is being drawn.
      /// @return The background xtd::drawing::color of the item that is being drawn.
      /// @remarks If the item's state is xtd::forms::draw_item_state::selected, the xtd::forms::drawing_item_event_args::back_color is set to xtd::drawing::system_colors::highlight. If the item's state is not xtd::forms::draw_item_state::selected, the xtd::forms::draw_item_event_Args::back_color property is set to xtd::drawing::system_colors::window.
      const xtd::drawing::color& back_color() const noexcept {return data_->back_color;}
      
      /// @brief Gets the rectangle that represents the bounds of the item that is being drawn.
      /// @return The xtd::drawing::rectangle that represents the bounds of the item that is being drawn.
      const xtd::drawing::rectangle& bounds() const noexcept {return data_->bounds;}
      
      /// @brief Gets the font that is assigned to the item being drawn.
      /// @return The xtd::drawing::font that is assigned to the item being drawn.
      /// @remarks A suggested xtd::drawing::font, usually the xtd::forms::control::font property of the parent control.
      const xtd::drawing::font& font() const noexcept {return data_->font;}
      
      /// @brief Gets the foreground color of the of the item being drawn.
      /// @return The foreground xtd::drawing::color of the item being drawn.
      /// @remarks If the item's state is xtd::forms::draw_item_state::selected, the xtd::forms::drawing_item_event_args::fore_color is set to xtd::drawing::system_colors::highlight_text. If the item's state is not xtd::forms::draw_item_state::selected, the xtd::forms::drawing_item_event_args::fore_color property is set to xtd::drawing::system_colors::window.
      const xtd::drawing::color& fore_color() const noexcept {return data_->fore_color;}
      
      /// @brief Gets the graphics surface to draw the item on.
      /// @return The xtd::drawing::graphics surface to draw the item on.
      xtd::drawing::graphics& graphics() noexcept {return *data_->graphics;}
      
      /// @brief Gets the index value of the item that is being drawn.
      /// @return The numeric value that represents the xtd::forms::control::control_collection::operator[] value of the item being drawn.
      /// @remarks This property returns the xtd::forms::control::control_collection::operator[] value of the item being drawn in the xtd::forms::control::control_collection. This property can return xtd::forms::control::control_collection::npos if items were removed from the list.
      size_t index() const noexcept {return data_->index;}
      
      /// @brief Gets the state of the item being drawn.
      /// @return The xtd::forms::draw_item_state that represents the state of the item being drawn.
      /// @remarks This property value can be a combination of the xtd::forms::draw_item_state enumeration members. The members can be combined by using bitwise operators.
      xtd::forms::draw_item_state state() const noexcept {return data_->state;}
      /// @}
      
    private:
      struct data {
        xtd::drawing::color back_color;
        xtd::drawing::rectangle bounds;
        xtd::drawing::font font = xtd::drawing::system_fonts::default_font();
        xtd::drawing::color fore_color;
        xtd::drawing::graphics* graphics = nullptr;
        size_t index = xtd::forms::control::control_collection::npos;
        xtd::forms::draw_item_state state = xtd::forms::draw_item_state::none;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
