/// @file
/// @brief Contains xtd::forms::style_sheets::color_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/rectangle.h>
#include "../../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The color data allow you to specify the style, colors and gradient mode.
      /// @code
      /// class forms_export_ color_data : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::color_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::color_renderer.
      class forms_export_ color_data : public xtd::iequatable<color_data>, public xtd::object {
      public:
        static const color_data empty;
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_data class.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                     | Default value                                         |
        /// |----------------------------------------------|-------------------------------------------------------|
        /// | xtd::forms::style_sheets::color_data::style  | xtd::forms::style_sheets::color_type::solid          |
        /// | xtd::forms::style_sheets::color_data::colors | An array with one color : xtd::drawing::color::black) |
        /// | xtd::forms::style_sheets::color_data::angle  | 90                                                    |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        color_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_data class with specified color.
        /// @param color The colors specifies what colors to display.
        /// | Property                                     | Default value                                         |
        /// |----------------------------------------------|-------------------------------------------------------|
        /// | xtd::forms::style_sheets::color_data::style  | xtd::forms::style_sheets::color_type::solid          |
        /// | xtd::forms::style_sheets::color_data::angle  | 90                                                    |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::color_type::color, only the first color is used.
        color_data(const xtd::drawing::color& color);
        /// @}

        /// @cond
        color_data(const color_data&) = default;
        color_data(color_data&&) = default;
        color_data& operator=(const color_data&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the colors specifies what colors to display.
        /// @return The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::color_type::color, only the first color is used.
        const xtd::drawing::color& color() const noexcept;
        /// @brief Sets the colors specifies what colors to display.
        /// @param value The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::color_type::color, only the first color is used.
        void color(const xtd::drawing::color& value) noexcept;
        /// @}

        /// @name Methods
        
        /// @{
        bool equals (const object& other) const noexcept override {return is<color_data>(other) ? equals(static_cast<const color_data&>(other)) : false;}
        bool equals (const color_data& other) const noexcept override {return color_ == other.color_ && empty_ == other.empty_;}

        /// @brief Creates a xtd::forms::style_sheets::color_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::color_data object.
        /// @param result The xtd::forms::style_sheets::color_data class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, color_data& result);

        /// @brief Creates a xtd::drawing::brush from specified color data and rectangle.
        /// @param color Contains color data.
        /// @param rect The xtd::drawing::rectangle neeed for linear gradient brush
        /// @return New instance of brush.
        static xtd::drawing::solid_brush make_brush(const xtd::forms::style_sheets::color_data& color);

        /// @brief Creates a xtd::forms::style_sheets::color_data object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::color_data object.
        /// @return The xtd::forms::style_sheets::color_data class that this method creates.
        /// @exception xtd::argument_exception The text is not a xtd::forms::style_sheets::color_data object.
        static color_data parse(const xtd::ustring& text);

        xtd::ustring to_string() const noexcept override;
        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::color_data object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::color_data object.
        xtd::ustring to_css() const noexcept;

        
        static std::vector<xtd::ustring> split_colors(const xtd::ustring& text);
        
        /// @brief Creates a xtd::forms::style_sheets::color_data object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::color_data object.
        /// @param result The xtd::forms::style_sheets::color_data class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool try_parse(const xtd::ustring& text, color_data& result);
        /// @}

      private:
        color_data(bool empty) : empty_(true) {}
         static xtd::ustring color_to_string(const xtd::drawing::color& color);
        static ustring remove_key(const xtd::ustring& text);
        static bool try_parse_hash_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_named_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_rgb_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_rgba_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_argb_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_hsv_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_hsva_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_ahsv_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_hsl_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_hsla_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_ahsl_color(const xtd::ustring& text, color_data& result);
        static bool try_parse_system_color(const xtd::ustring& text, color_data& result);
        
        xtd::drawing::color color_ = xtd::drawing::color::transparent;
        bool empty_ = false;
      };
    }
  }
}
