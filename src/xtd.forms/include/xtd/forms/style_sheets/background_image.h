/// @file
/// @brief Contains xtd::forms::style_sheets::background_image class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.h"
#include "image_type.h"
#include <xtd/drawing/brush>
#include <xtd/drawing/color>
#include <xtd/drawing/rectangle>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/uri>
#include <xtd/ustring>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @cond
      class style_sheet;
      /// @endcond
      
      /// @brief The image data allows you to specify the url or gradient mode.
      /// @code
      /// class forms_export_ background_image : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::background_image
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/background_image> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::ibox_model.
      class forms_export_ background_image : public xtd::iequatable<background_image>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::background_image object.
        static const background_image empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::background_image class.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                          | Default value                                         |
        /// | ------------------------------------------------- | ----------------------------------------------------- |
        /// | xtd::forms::style_sheets::background_image::angle      | 180                                                   |
        /// | xtd::forms::style_sheets::background_image::colors     | An array with one color : xtd::drawing::color::black) |
        /// | xtd::forms::style_sheets::background_image::image_type | xtd::forms::style_sheets::image_type::none            |
        /// | xtd::forms::style_sheets::background_image::url        | An empty tring ("")                                   |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        background_image() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::background_image class with specified url.
        /// @param url The url of image to display.
        /// | Property                                          | Default value                                         |
        /// | ------------------------------------------------- | ----------------------------------------------------- |
        /// | xtd::forms::style_sheets::background_image::angle      | 180                                                   |
        /// | xtd::forms::style_sheets::background_image::colors     | An array with one color : xtd::drawing::color::black) |
        /// | xtd::forms::style_sheets::background_image::image_type | xtd::forms::style_sheets::image_type::url             |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        explicit background_image(const xtd::ustring& url);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::background_image class with specified colors array.
        /// @param color The colors that specifies the color for gradient image to display.
        /// | Property                                          | Default value                                         |
        /// | ------------------------------------------------- | ----------------------------------------------------- |
        /// | xtd::forms::style_sheets::background_image::angle      | 180                                                   |
        /// | xtd::forms::style_sheets::background_image::image_type | xtd::forms::style_sheets::image_type::linera_gradient |
        /// | xtd::forms::style_sheets::background_image::url        | An empty tring ("")                                   |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        explicit background_image(const std::vector<xtd::drawing::color>& colors);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::background_image class with specified colors and angle.
        /// @param color The colors that specifies the color for gradient image to display.
        /// @param angle The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @exception xtd::argument_exception colors is less than 2.
        background_image(const std::vector<xtd::drawing::color>& colors, int32 angle);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::background_image class with specified style and colors.
        /// @param image_type The style specifies what kind of image to display.
        /// @param color The colors that specifies the color for gradient image to display.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @exception xtd::argument_exception colors is less than 2.
        /// @exception xtd::not_supported_exception if xtd::forms::style_sheets::background_image::image_type is not of xtd::forms::style_sheets::image_type::url and not xtd::forms::style_sheets::image_type::linear_gradient.
        background_image(xtd::forms::style_sheets::image_type image_type, const std::vector<xtd::drawing::color>& colors);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::background_image class with specified style, colors and angle.
        /// @param image_type The style specifies what kind of image to display.
        /// @param color The colors that specifies the color for gradient image to display.
        /// @param angle The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @exception xtd::argument_exception colors is less than 2.
        /// @exception xtd::not_supported_exception if xtd::forms::style_sheets::background_image::image_type is not of xtd::forms::style_sheets::image_type::url and not xtd::forms::style_sheets::image_type::linear_gradient.
        background_image(xtd::forms::style_sheets::image_type image_type, const std::vector<xtd::drawing::color>& colors, int32 angle);
        /// @}
        
        /// @cond
        background_image(const std::initializer_list<xtd::drawing::color>& colors);
        background_image(const background_image&) = default;
        background_image(background_image&&) = default;
        background_image& operator =(const background_image&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the angle specifies the gradient direction.
        /// @return The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        int32 angle() const noexcept;
        /// @brief Sets the angle specifies the gradient direction.
        /// @param value The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        void angle(int32 value) noexcept;
        
        /// @brief Gets the colors specifies what colors to display.
        /// @return The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        const std::vector<xtd::drawing::color>& colors() const noexcept;
        /// @brief Sets the colors that specifies what colors to display.
        /// @param value The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::image_type::color, only the first color is used.
        /// @exception xtd::argument_exception colors is less than 2.
        void colors(const std::vector<xtd::drawing::color>& value);
        
        /// @brief Gets the url of image to display.
        /// @return The url of image to display.
        const xtd::uri& url() const noexcept;
        /// @brief Sets the url of image to display.
        /// @param value The url of image to display.
        void url(const xtd::uri& value) noexcept;
        
        /// @brief Gets the image type that specifies what kind of image to display.
        /// @return The image type tht specifies what kind of image to display.
        xtd::forms::style_sheets::image_type image_type() const noexcept;
        /// @brief Sets the style specifies what kind of image to display.
        /// @param value The style specifies what kind of image to display.
        void image_type(xtd::forms::style_sheets::image_type value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const background_image& other) const noexcept override {return image_type_ == other.image_type_ && colors_ == other.colors_ && angle_ == other.angle_;}
                
        xtd::ustring to_string() const noexcept override;
        /// @}

        /// @name Static methods
        
        /// @{
        /// @brief Creates a xtd::drawing::brush from specified image data and rectangle.
        /// @param image Contains image data.
        /// @param rect The xtd::drawing::rectangle neeed for linear gradient brush
        /// @return New instance of brush.
        static std::unique_ptr<xtd::drawing::brush> make_brush(const xtd::forms::style_sheets::background_image& image, const xtd::drawing::rectangle& rect);
        /// @}

      private:
        friend class style_sheet;
        xtd::forms::style_sheets::image_type image_type_ = style_sheets::image_type::none;
        xtd::uri url_;
        std::vector<xtd::drawing::color> colors_ = {xtd::drawing::color::black, xtd::drawing::color::black};
        int32 angle_ = 180;
      };
    }
  }
}
