/// @file
/// @brief Contains xtd::forms::style_sheets::ibox_model class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../padding.h"
#include "border_color.h"
#include "border_radius.h"
#include "border_style.h"
#include "border_width.h"
#include "background_image.h"
#include "margin.h"
#include "outline_color.h"
#include "outline_offset.h"
#include "outline_radius.h"
#include "outline_style.h"
#include "outline_width.h"
#include "padding.h"
#include <xtd/iequatable>
#include <xtd/interface>
#include <array>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The box model allows you to specify the margin, borders, padding, background color, width and height of a box.
      /// @code
      /// class ibox_model interface_
      /// @endcode
      /// @par Inheritance
      /// xtd::interface → xtd::forms::style_sheets::ibox_model
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/ibox_model> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets interfaces
      /// @remarks This class is used by xtd::forms::style_sheets::box_renderer.
      /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
      class ibox_model interface_ {
      public:
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the background color is used to add background effects to the box.
        /// @return The background color is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual const xtd::drawing::color& background_color() const noexcept = 0;
        
        /// @brief Gets the background image is used to add background effects to the box.
        /// @return The background image is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual const xtd::forms::style_sheets::background_image& background_image() const noexcept = 0;
        
        /// @brief Gets the color is used to set the color of the borders.
        /// @return The color is used to set the color of the borders.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual const xtd::forms::style_sheets::border_color& border_color() const noexcept = 0;
        
        /// @brief Gets the radius is used to add rounded borders to an element.
        /// @return The radius is used to add rounded borders to an element.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual xtd::forms::style_sheets::border_radius border_radius() const noexcept = 0;
        
        /// @brief Gets the style specifies what kind of borders to display.
        /// @return The style specifies what kind of borders to display.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual xtd::forms::style_sheets::border_style border_style() const noexcept = 0;
        
        /// @brief Gets the width specifies the width of the borders.
        /// @return The width specifies the width of the borders.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual xtd::forms::style_sheets::border_width border_width() const noexcept = 0;
        
        /// @brief Gets the height of the box.
        /// @return The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual std::optional<xtd::forms::style_sheets::length> height() const noexcept = 0;
        
        /// @brief Gets the area outside the border.
        /// @return The area outside the border.
        /// @remarks The margin is transparent.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual const xtd::forms::style_sheets::margin& margin() const noexcept = 0;
        
        /// @brief Gets the color is used to set the color of the outlines.
        /// @return The color is used to set the color of the outlines.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual const xtd::forms::style_sheets::outline_color& outline_color() const noexcept = 0;
        
        /// @brief Gets the ofset specifies the width of the outlines.
        /// @return The offset specifies the width of the outlines.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual xtd::forms::style_sheets::outline_offset outline_offset() const noexcept = 0;
        
        /// @brief Gets the radius is used to add rounded outline to an element.
        /// @return The radius is used to add rounded outline to an element.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual xtd::forms::style_sheets::outline_radius outline_radius() const noexcept = 0;
        
        /// @brief Gets the style specifies what kind of outlines to display.
        /// @return The style specifies what kind of outlines to display.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual xtd::forms::style_sheets::outline_style outline_style() const noexcept = 0;
        
        /// @brief Gets the width specifies the width of the outlines.
        /// @return The width specifies the width of the outlines.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual xtd::forms::style_sheets::outline_width outline_width() const noexcept = 0;
        
        /// @brief Gets the area area around the content.
        /// @return The area around the content.
        /// @remarks The padding is transparent.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual const xtd::forms::style_sheets::padding& padding() const noexcept = 0;
        
        /// @brief Gets the width of the box.
        /// @return The width of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model">Box Model</a>.
        virtual std::optional<xtd::forms::style_sheets::length> width() const noexcept = 0;
        /// @}
        
        /// @name Public Methods
        
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
        
        /// @brief Gets the computed outline rectangle from specified bounds.
        /// @param bounds The bounds use to compute the outline rectangle with this box instance.
        /// @return The computed boder rectangle from specified bounds.
        /// @remarks The outline rectangle is euqual to bounds rectangle minus margin + 1 + outline offset.
        virtual xtd::drawing::rectangle get_outline_rectangle(const xtd::drawing::rectangle& bounds) const noexcept = 0;
        
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
