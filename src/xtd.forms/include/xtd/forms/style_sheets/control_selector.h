/// @file
/// @brief Contains xtd::forms::style_sheets::control_selector class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box_data.h"
#include "text_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The control data allows you to specify the box and color of a control.
      /// @code
      /// class forms_export_ control_selector : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::control_selector
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ control_selector : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::control_selector class.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        control_selector() = default;

        control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::forms::style_sheets::color_property& background_color, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::forms::style_sheets::color_property& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font);
        control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::forms::style_sheets::image_value& background_image, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::forms::style_sheets::color_property& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font);

        /// @cond
        control_selector(const control_selector&) = default;
        control_selector(control_selector&&) = default;
        control_selector& operator=(const control_selector&) = default;
        /// @endcond
        
        /// @brief Gets the box of the control.
        /// @return The box of the control.
        virtual const xtd::forms::style_sheets::box_data& box() const noexcept;
        /// @brief Gets the box of the control.
        /// @return The box of the control.
        virtual xtd::forms::style_sheets::box_data& box() noexcept;

        /// @brief Gets the box of the control.
        /// @return The box of the control.
        virtual const xtd::forms::style_sheets::text_data& text() const noexcept;
        /// @brief Gets the box of the control.
        /// @return The box of the control.
        virtual xtd::forms::style_sheets::text_data& text() noexcept;

      private:
        xtd::forms::style_sheets::box_data box_;
        xtd::forms::style_sheets::text_data text_;
      };
    }
  }
}
