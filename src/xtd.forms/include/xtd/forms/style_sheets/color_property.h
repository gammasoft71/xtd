/// @file
/// @brief Contains xtd::forms::style_sheets::color_property class.
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
      /// @brief The color data allows you to specify the color of an item.
      /// @code
      /// class forms_export_ color_property : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::color_property
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::box_data.
      class forms_export_ color_property : public xtd::iequatable<color_property>, public xtd::object {
      public:
        static const color_property empty;
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_property class.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                    | Default value                      |
        /// |---------------------------------------------|------------------------------------|
        /// | xtd::forms::style_sheets::color_property::color |  xtd::drawing::color::transparent) |
        color_property() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_property class with specified color.
        /// @param color The colors specifies what colors to display.
        color_property(const xtd::drawing::color& color);
        /// @}

        /// @cond
        color_property(const color_property&) = default;
        color_property(color_property&&) = default;
        color_property& operator=(const color_property&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the colors specifies what color to display.
        /// @return The colors specifies what color to display.
        const xtd::drawing::color& color() const noexcept;
        /// @brief Sets the colors specifies what color to display.
        /// @param value The colors specifies what color to display.
        void color(const xtd::drawing::color& value) noexcept;
        /// @}

        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override {return is<color_property>(other) ? equals(static_cast<const color_property&>(other)) : false;}
        bool equals(const color_property& other) const noexcept override {return color_ == other.color_ && empty_ == other.empty_;}

        /// @brief Creates a xtd::forms::style_sheets::color_property object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::color_property object.
        /// @param result The xtd::forms::style_sheets::color_property class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, color_property& result) noexcept;
        /// @brief Creates a xtd::forms::style_sheets::color_property object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::color_property object.
        /// @param default_value The default_value is used if the specified text is invalid.
        /// @return The xtd::forms::style_sheets::color_property class that this method creates.
        /// @remarks If css_text is not a xtd::forms::sttyle_sheets::color_property, the default_value is returned.
        static color_property from_css(const xtd::ustring& css_text, const color_property& default_value) noexcept;

        /// @brief Creates a xtd::drawing::brush from specified color data and rectangle.
        /// @param color Contains color data.
        /// @return New instance of brush.
        static xtd::drawing::solid_brush make_brush(const xtd::forms::style_sheets::color_property& color);

        /// @brief Creates a xtd::forms::style_sheets::color_property object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::color_property object.
        /// @return The xtd::forms::style_sheets::color_property class that this method creates.
        /// @exception xtd::argument_exception The text is not a xtd::forms::style_sheets::color_property object.
        static color_property parse(const xtd::ustring& text);

        xtd::ustring to_string() const noexcept override;

        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::color_property object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::color_property object.
        xtd::ustring to_css() const noexcept;
        
        /// @brief Creates a xtd::forms::style_sheets::color_property object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::color_property object.
        /// @param result The xtd::forms::style_sheets::color_property class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool try_parse(const xtd::ustring& text, color_property& result) noexcept;
        /// @}

      private:
        color_property(bool empty) : empty_(true) {}
        static xtd::ustring color_to_string(const xtd::drawing::color& color);
        static ustring remove_key(const xtd::ustring& text);
        static bool try_parse_hash_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_named_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_rgb_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_rgba_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_argb_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_hsv_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_hsva_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_ahsv_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_hsl_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_hsla_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_ahsl_color(const xtd::ustring& text, color_property& result);
        static bool try_parse_system_color(const xtd::ustring& text, color_property& result);
        
        xtd::drawing::color color_ = xtd::drawing::color::transparent;
        bool empty_ = false;
      };
    }
  }
}
