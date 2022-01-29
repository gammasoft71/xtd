/// @file
/// @brief Contains xtd::forms::style_sheets::ibox_model class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include <xtd/iequatable.h>
#include <xtd/interface.h>
#include "border_color.h"
#include "border_radius.h"
#include "border_style.h"
#include "border_width.h"
#include "background_image.h"
#include "../padding.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The box data allows you to specify the margin, borders, padding, background color, width and height of a box.
      /// @code
      /// class ibox_model : public xtd::iequatable<ibox_model>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::ibox_model
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets interfaces
      /// @remarks This class is used by xtd::forms::style_sheets::box_renderer.
      /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
      class ibox_model interface_ {
      public:
        /// @name Properties
        
        /// @{
        /// @brief Gets the background color is used to add background effects to the box.
        /// @return The background color is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual const xtd::drawing::color& background_color() const noexcept = 0;
        /// @brief Sets the background color is used to add background effects to the box.
        /// @param value The background color is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void background_color(const xtd::drawing::color& value) noexcept = 0;

        /// @brief Gets the background image is used to add background effects to the box.
        /// @return The background image is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual const xtd::forms::style_sheets::background_image& background_image() const noexcept = 0;
        /// @brief Sets the background image is used to add background effects to the box.
        /// @param value The background image is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void background_image(const xtd::forms::style_sheets::background_image& value) noexcept = 0;
        
        /// @brief Gets the color is used to set the color of the borders.
        /// @return The color is used to set the color of the borders.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual const xtd::forms::style_sheets::border_color& border_color() const noexcept = 0;
        /// @brief Sets the color is used to set the color of the borders.
        /// @param value The color is used to set the color of the borders.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void border_color(const xtd::forms::style_sheets::border_color& value) noexcept = 0;
        
        /// @brief Gets the radius is used to add rounded borders to an element.
        /// @return The radius is used to add rounded borders to an element.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual xtd::forms::style_sheets::border_radius border_radius() const noexcept = 0;
        /// @brief Sets the radius is used to add rounded borders to an element.
        /// @param value The radius is used to add rounded borders to an element.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void border_radius(xtd::forms::style_sheets::border_radius value) noexcept = 0;
        
        /// @brief Gets the style specifies what kind of borders to display.
        /// @return The style specifies what kind of borders to display.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual xtd::forms::style_sheets::border_style border_style() const noexcept = 0;
        /// @brief Sets the style specifies what kind of borders to display.
        /// @param value The style specifies what kind of borders to display.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void border_style(xtd::forms::style_sheets::border_style value) noexcept = 0;
        
        /// @brief Gets the width specifies the width of the borders.
        /// @return The width specifies the width of the borders.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual xtd::forms::style_sheets::border_width border_width() const noexcept = 0;
        /// @brief Sets the width specifies the width of the border.
        /// @param value The width specifies the width of the border.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void border_width(xtd::forms::style_sheets::border_width value) noexcept = 0;

        /// @brief Gets the height of the box.
        /// @return The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual std::optional<int32_t> height() const noexcept = 0;
        /// @brief Sets the height of the box.
        /// @return The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void height(const std::optional<int32_t>& value) noexcept = 0;

        /// @brief Gets the area outside the border.
        /// @return The area outside the border.
        /// @remarks The margin is transparent.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual const xtd::forms::padding& margin() const noexcept = 0;
        /// @brief Sets the area outside the border.
        /// @param value The area outside the border.
        /// @remarks The margin is transparent.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void margin(const xtd::forms::padding& value) noexcept = 0;

        /// @brief Gets the area area around the content.
        /// @return The area around the content.
        /// @remarks The padding is transparent.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual const xtd::forms::padding& padding() const noexcept = 0;
        /// @brief Sets the area area around the content.
        /// @param value The area around the content.
        /// @remarks The padding is transparent.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void padding(const xtd::forms::padding& value) noexcept = 0;

        /// @brief Gets the width of the box.
        /// @return The width of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual std::optional<int32_t> width() const noexcept = 0;
        /// @brief Sets the width of the box.
        /// @param value The width of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        virtual void width(std::optional<int32_t> value) noexcept = 0;
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Gets the computed boder rectangle from specified bounds.
        /// @param bounds The bounds use to compute the borfder rectangle with this box instance.
        /// @return The computed boder rectangle from specified bounds.
        /// @remarks The border rectangle is euqual to bounds rectangle minus margin.
        virtual xtd::drawing::rectangle get_border_rectangle(const xtd::drawing::rectangle& bounds) const noexcept = 0;

        /// @brief Gets the computed fill rectangle from specified bounds.
        /// @param bounds The bounds use to compute the fill rectangle with this box instance.
        /// @return The computed boder rectangle from specified bounds.
        /// @remarks The fill rectangle is euqual to border rectangle minus border width.
        /// @remarks The fill rectangle is euqual to content rectangle plus padding.
        virtual xtd::drawing::rectangle get_fill_rectangle(const xtd::drawing::rectangle& bounds) const noexcept = 0;

        /// @brief Gets the computed content rectangle from specified bounds.
        /// @param bounds The bounds use to compute the content rectangle with this box instance.
        /// @return The content boder rectangle from specified bounds.
        /// @remarks The content rectangle is euqual to fill rectangle minus padding.
        /// @remarks The content rectangle is euqual to border rectangle minux border width minus padding.
        virtual xtd::drawing::rectangle get_content_rectangle(const xtd::drawing::rectangle& bounds) const noexcept = 0;
        /// @}
      };
    }
  }
}
