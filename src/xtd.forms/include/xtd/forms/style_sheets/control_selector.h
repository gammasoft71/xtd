/// @file
/// @brief Contains xtd::forms::style_sheets::control_selector class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "ibox_model.h"
#include "itext_model.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The control selector allows you to specify the box and color of a control.
      /// @code
      /// class forms_export_ control_selector : public xtd::forms::style_sheets::ibox_model, public xtd::forms::style_sheets::itext_model, public xtd::iequatable<control_selector>, public xtd::object
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::ibox_model
      /// @par Implements
      /// xtd::forms::style_sheets::ibox_model, xtd::forms::style_sheets::itext_model, xtd::iequatable <>
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::ibox_model → xtd::forms::style_sheets::control_selector
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks You need to know how the box model works.
      /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
      class forms_export_ control_selector : public xtd::forms::style_sheets::ibox_model, public xtd::forms::style_sheets::itext_model, public xtd::iequatable<control_selector>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::control_selector class.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        control_selector() = default;

        control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::drawing::color& background_color, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font);
        control_selector(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::forms::style_sheets::background_image& background_image, std::optional<int32_t> width, std::optional<int32_t> height, const xtd::drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font);
        /// @}

        /// @cond
        control_selector(const control_selector&) = default;
        control_selector(control_selector&&) = default;
        control_selector& operator=(const control_selector&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        xtd::forms::content_alignment alignment() const noexcept override;
        void alignment(xtd::forms::content_alignment value) noexcept override;
        
        const xtd::drawing::color& background_color() const noexcept override;
        void background_color(const xtd::drawing::color& value) noexcept override;

        const xtd::forms::style_sheets::background_image& background_image() const noexcept override;
        void background_image(const xtd::forms::style_sheets::background_image& value) noexcept override;

        const xtd::forms::style_sheets::border_color& border_color() const noexcept override;
        void border_color(const xtd::forms::style_sheets::border_color& value) noexcept override;
        
        xtd::forms::style_sheets::border_radius border_radius() const noexcept override;
        void border_radius(xtd::forms::style_sheets::border_radius value) noexcept override;
        
        xtd::forms::style_sheets::border_style border_style() const noexcept override;
        void border_style(xtd::forms::style_sheets::border_style value) noexcept override;
        
        xtd::forms::style_sheets::border_width border_width() const noexcept override;
        void border_width(xtd::forms::style_sheets::border_width value) noexcept override;
        
        const xtd::drawing::color& color() const noexcept override;
        void color(const xtd::drawing::color& value) noexcept override;
        
        xtd::forms::style_sheets::text_decoration decoration() const noexcept override;
        void decoration(xtd::forms::style_sheets::text_decoration value) noexcept override;
        
        const xtd::drawing::font& font() const noexcept override;
        void font(const xtd::drawing::font& value) noexcept override;

        std::optional<int32_t> height() const noexcept override;
        void height(const std::optional<int32_t>& value) noexcept override;
        
        const xtd::forms::padding& margin() const noexcept override;
        void margin(const xtd::forms::padding& value) noexcept override;

        const xtd::forms::padding& padding() const noexcept override;
        void padding(const xtd::forms::padding& value) noexcept override;

        xtd::forms::style_sheets::text_transformation transformation() const noexcept override;
        void transformation(xtd::forms::style_sheets::text_transformation value) noexcept override;

        std::optional<int32_t> width() const noexcept override;
        void width(std::optional<int32_t> value) noexcept override;
        /// @}

        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override;
        bool equals(const control_selector& other) const noexcept override;
        
        xtd::drawing::rectangle get_border_rectangle(const xtd::drawing::rectangle& bounds) const noexcept override;
        xtd::drawing::rectangle get_fill_rectangle(const xtd::drawing::rectangle& bounds) const noexcept override;
        xtd::drawing::rectangle get_content_rectangle(const xtd::drawing::rectangle& bounds) const noexcept override;
        xtd::drawing::string_format make_string_format() const noexcept override;
        /// @}

      private:
        xtd::forms::padding margin_;
        xtd::forms::style_sheets::border_style border_style_;
        xtd::forms::style_sheets::border_color border_color_;
        xtd::forms::style_sheets::border_width border_width_;
        xtd::forms::style_sheets::border_radius border_radius_;
        xtd::forms::padding padding_;
        xtd::drawing::color background_color_ = xtd::drawing::color::transparent;
        xtd::forms::style_sheets::background_image background_image_;
        std::optional<int32_t> width_;
        std::optional<int32_t> height_;
        xtd::drawing::color color_;
        xtd::forms::content_alignment alignment_ = xtd::forms::content_alignment::middle_center;
        xtd::drawing::font font_ = xtd::drawing::system_fonts::default_font();
        xtd::forms::style_sheets::text_decoration decoration_ = xtd::forms::style_sheets::text_decoration::none;
        xtd::forms::style_sheets::text_transformation transformation_ = xtd::forms::style_sheets::text_transformation::none;
      };
    }
  }
}
