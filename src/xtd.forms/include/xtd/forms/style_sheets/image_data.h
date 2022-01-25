/// @file
/// @brief Contains xtd::forms::style_sheets::image_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include <xtd/drawing/brush.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/rectangle.h>
#include "../../forms_export.h"
#include "image_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The color data allow you to specify the style, colors and gradient mode.
      /// @code
      /// class forms_export_ image_data : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::image_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::color_renderer.
      class forms_export_ image_data : public xtd::iequatable<image_data>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::image_data class.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                     | Default value                                         |
        /// |----------------------------------------------|-------------------------------------------------------|
        /// | xtd::forms::style_sheets::image_data::style  | xtd::forms::style_sheets::image_type::solid          |
        /// | xtd::forms::style_sheets::image_data::colors | An array with one color : xtd::drawing::color::black) |
        /// | xtd::forms::style_sheets::image_data::angle  | 90                                                    |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        image_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::image_data class with specified color.
        /// @param color The colors specifies what colors to display.
        /// | Property                                     | Default value                                         |
        /// |----------------------------------------------|-------------------------------------------------------|
        /// | xtd::forms::style_sheets::image_data::style  | xtd::forms::style_sheets::image_type::solid          |
        /// | xtd::forms::style_sheets::image_data::angle  | 90                                                    |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        image_data(const xtd::ustring& url);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::image_data class with specified color.
        /// @param color The colors specifies what colors to display.
        /// | Property                                     | Default value                                         |
        /// |----------------------------------------------|-------------------------------------------------------|
        /// | xtd::forms::style_sheets::image_data::style  | xtd::forms::style_sheets::image_type::solid          |
        /// | xtd::forms::style_sheets::image_data::angle  | 90                                                    |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        image_data(const std::vector<xtd::drawing::color>& colors);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::image_data class with specified style, colors and angle.
        /// @param style The style specifies what kind of color to display.
        /// @param colors The colors specifies what colors to display.
        /// @param angle The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        /// @exception xtd::argument_exception colors is empty.
        /// @exception xtd::not_supported_exception if xtd::forms::style_sheets::image_data::style is not of xtd::forms::style_sheets::image_type::solid and not xtd::forms::style_sheets::image_type::linear_gradient.
        image_data(const std::vector<xtd::drawing::color>& colors, int32_t angle);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::image_data class with specified style and colors.
        /// @param image_type The style specifies what kind of color to display.
        /// @param colors The colors specifies what colors to display.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        /// @exception xtd::argument_exception colors is empty.
        /// @exception xtd::not_supported_exception xtd::forms::style_sheets::image_data::style is not of xtd::forms::style_sheets::image_type::solid and not xtd::forms::style_sheets::image_type::linear_gradient.
        image_data(xtd::forms::style_sheets::image_type image_type, const std::vector<xtd::drawing::color>& colors);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::image_data class with specified style, colors and angle.
        /// @param image_type The style specifies what kind of color to display.
        /// @param colors The colors specifies what colors to display.
        /// @param angle The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        /// @exception xtd::argument_exception colors is empty.
        /// @exception xtd::not_supported_exception if xtd::forms::style_sheets::image_data::style is not of xtd::forms::style_sheets::image_type::solid and not xtd::forms::style_sheets::image_type::linear_gradient.
        image_data(xtd::forms::style_sheets::image_type image_type, const std::vector<xtd::drawing::color>& colors, int32_t angle);
        /// @}

        /// @cond
        image_data(const std::initializer_list<xtd::drawing::color>& colors);
        image_data(const image_data&) = default;
        image_data(image_data&&) = default;
        image_data& operator=(const image_data&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the angle specifies the gradient direction.
        /// @return The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        int32_t angle() const noexcept;
        /// @brief Sets the angle specifies the gradient direction.
        /// @param value The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        void angle(int32_t value) noexcept;

        /// @brief Gets the colors specifies what colors to display.
        /// @return The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        const std::vector<xtd::drawing::color>& colors() const noexcept;
        /// @brief Sets the colors specifies what colors to display.
        /// @param value The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        void colors(const std::vector<xtd::drawing::color>& value);

        /// @brief Gets the colors specifies what colors to display.
        /// @return The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        const xtd::ustring& url() const noexcept;
        /// @brief Sets the colors specifies what colors to display.
        /// @param value The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        void url(const xtd::ustring& value) noexcept;

        /// @brief Gets the style specifies what kind of color to display.
        /// @return The style specifies what kind of color to display.
        xtd::forms::style_sheets::image_type image_type() const noexcept;
        /// @brief Sets the style specifies what kind of color to display.
        /// @param value The style specifies what kind of color to display.
        void image_type(xtd::forms::style_sheets::image_type value) noexcept;
        /// @}

        /// @name Methods
        
        /// @{
        bool equals (const object& other) const noexcept override {return is<image_data>(other) ? equals(static_cast<const image_data&>(other)) : false;}
        bool equals (const image_data& other) const noexcept override {return image_type_ == other.image_type_ && colors_ == other.colors_ && angle_ == other.angle_;}

        /// @brief Creates a xtd::forms::style_sheets::image_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::image_data object.
        /// @param result The xtd::forms::style_sheets::image_data class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, image_data& result);

        /// @brief Creates a xtd::drawing::brush from specified color data and rectangle.
        /// @param color Contains color data.
        /// @param rect The xtd::drawing::rectangle neeed for linear gradient brush
        /// @return New instance of brush.
        static std::unique_ptr<xtd::drawing::brush> make_brush(const xtd::forms::style_sheets::image_data& color, const xtd::drawing::rectangle& rect);

        /// @brief Creates a xtd::forms::style_sheets::image_data object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::image_data object.
        /// @return The xtd::forms::style_sheets::image_data class that this method creates.
        /// @exception xtd::argument_exception The text is not a xtd::forms::style_sheets::image_data object.
        static image_data parse(const xtd::ustring& text);

        xtd::ustring to_string() const noexcept override;
        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::image_data object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::image_data object.
        xtd::ustring to_css() const noexcept;
        
        /// @brief Creates a xtd::forms::style_sheets::image_data object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::image_data object.
        /// @param result The xtd::forms::style_sheets::image_data class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool try_parse(const xtd::ustring& text, image_data& result);
        /// @}

      private:
        static xtd::ustring angle_to_string(int32_t angle);
        static xtd::ustring color_to_string(const xtd::drawing::color& color);
        static ustring remove_key(const xtd::ustring& text);
        static bool try_parse_url(const xtd::ustring& text, image_data& result);
        static std::vector<xtd::ustring> split_arguments(const xtd::ustring& text);
        static bool try_parse_linear_gradient_color(const xtd::ustring& text, image_data& result);

        xtd::forms::style_sheets::image_type image_type_ = style_sheets::image_type::none;
        xtd::ustring url_;
        std::vector<xtd::drawing::color> colors_ = {xtd::drawing::color::black, xtd::drawing::color::black};
        int32_t angle_ = 180;
      };
    }
  }
}
