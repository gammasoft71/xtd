/// @file
/// @brief Contains xtd::forms::flat_button_appearance class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/color>
#include <xtd/optional>
#include <xtd/iequatable>
#include <xtd/object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides properties that specify the appearance of xtd::forms::button controls whose xtd::forms::flat_style is xtd::forms::flat_style::flat.
    /// @par Header
    /// @code #include <xtd/forms/flat_button_appearance> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class flat_button_appearance : public object, public xtd::iequatable<flat_button_appearance> {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::flat_button_appearance class.
      flat_button_appearance();
      /// @}
      
      /// @cond
      flat_button_appearance(const flat_button_appearance& other);
      flat_button_appearance(flat_button_appearance&&) = default;
      flat_button_appearance& operator =(const flat_button_appearance&);
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the color of the border around the button.
      /// @return A xtd::drawing::color structure representing the color of the border around the button.
      std::optional<xtd::drawing::color> border_color() const noexcept;
      /// @brief Sets the color of the border around the button.
      /// @param color A xtd::drawing::color structure representing the color of the border around the button.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& border_color(const xtd::drawing::color& color);
      /// @brief Resets the color of the border around the button.
      /// @param color nullptr.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& border_color(std::nullptr_t color);
      
      /// @brief Gets a value that specifies the radius, in pixels, of the border around the button.
      /// @return An int32 representing the radius, in pixels, of the border around the button.
      std::optional<int32> border_radius() const noexcept;
      /// @brief Sets a value that specifies the radius, in pixels, of the border around the button.
      /// @param size An int32 representing the radius, in pixels, of the border around the button.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& border_radius(int32 radius);
      /// @brief Resets a value that specifies the radius, in pixels, of the border around the button.
      /// @param size nullptr.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& border_radius(std::nullptr_t radius);
      
      /// @brief Gets a value that specifies the size, in pixels, of the border around the button.
      /// @return An int32 representing the size, in pixels, of the border around the button.
      std::optional<int32> border_size() const noexcept;
      /// @brief Sets a value that specifies the size, in pixels, of the border around the button.
      /// @param size An int32 representing the size, in pixels, of the border around the button.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& border_size(int32 size);
      /// @brief Resets a value that specifies the size, in pixels, of the border around the button.
      /// @param size nullptr.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& border_size(std::nullptr_t size);
      
      /// @brief Gets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      std::optional<xtd::drawing::color> checked_back_color() const noexcept;
      /// @brief Sets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @param color A xtd::drawing::color structure representing the color of the client area of the button.structure representing the color of the client area of the button.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& checked_back_color(const xtd::drawing::color& color);
      /// @brief Resets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @param color nullptr.
      /// @return Current flat_button_appearance.
      flat_button_appearance& checked_back_color(std::nullptr_t color);
      
      /// @brief Gets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      std::optional<xtd::drawing::color> mouse_down_back_color() const noexcept;
      /// @brief Sets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @param color A xtd::drawing::color structure representing the color of the client area of the button.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& mouse_down_back_color(const xtd::drawing::color& color);
      /// @brief Resets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @param color nullptr.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& mouse_down_back_color(std::nullptr_t color);
      
      /// @brief Gets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      std::optional<xtd::drawing::color> mouse_over_back_color() const noexcept;
      /// @brief Sets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @param color A xtd::drawing::color structure representing the color of the client area of the button.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& mouse_over_back_color(const xtd::drawing::color& color);
      /// @brief Resets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @param color nullptr.
      /// @return Current xtd::forms::flat_button_appearance.
      flat_button_appearance& mouse_over_back_color(std::nullptr_t color);
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const flat_button_appearance& other) const noexcept override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}

