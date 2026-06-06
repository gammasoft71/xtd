/// @file
/// @brief Contains xtd::forms::flat_button_appearance class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
    /// ```cpp
    /// #include <xtd/forms/flat_button_appearance>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class flat_button_appearance : public xtd::object, public xtd::iequatable<flat_button_appearance> {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::flat_button_appearance class.
      flat_button_appearance();
      /// @}
      
      /// @cond
      flat_button_appearance(const flat_button_appearance& other);
      auto operator =(const flat_button_appearance&) -> flat_button_appearance&;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the color of the border around the button.
      /// @return A xtd::drawing::color structure representing the color of the border around the button.
      [[nodiscard]] auto border_color() const noexcept -> std::optional<xtd::drawing::color>;
      /// @brief Sets the color of the border around the button.
      /// @param value A xtd::drawing::color structure representing the color of the border around the button.
      /// @return Current xtd::forms::flat_button_appearance.
      auto border_color(const xtd::drawing::color& value) -> flat_button_appearance&;
      /// @brief Resets the color of the border around the button.
      /// @param xtd::null.
      /// @return Current xtd::forms::flat_button_appearance.
      auto border_color(xtd::null_ptr) -> flat_button_appearance&;
      
      /// @brief Gets a value that specifies the radius, in pixels, of the border around the button.
      /// @return An int32 representing the radius, in pixels, of the border around the button.
      [[nodiscard]] auto border_radius() const noexcept -> std::optional<xtd::int32>;
      /// @brief Sets a value that specifies the radius, in pixels, of the border around the button.
      /// @param value An int32 representing the radius, in pixels, of the border around the button.
      /// @return Current xtd::forms::flat_button_appearance.
      auto border_radius(xtd::int32 value) -> flat_button_appearance&;
      /// @brief Resets a value that specifies the radius, in pixels, of the border around the button.
      /// @param xtd::null.
      /// @return Current xtd::forms::flat_button_appearance.
      auto border_radius(xtd::null_ptr) -> flat_button_appearance&;
      
      /// @brief Gets a value that specifies the size, in pixels, of the border around the button.
      /// @return An int32 representing the size, in pixels, of the border around the button.
      [[nodiscard]] auto border_size() const noexcept -> std::optional<xtd::int32>;
      /// @brief Sets a value that specifies the size, in pixels, of the border around the button.
      /// @param value An int32 representing the size, in pixels, of the border around the button.
      /// @return Current xtd::forms::flat_button_appearance.
      auto border_size(xtd::int32 value) -> flat_button_appearance&;
      /// @brief Resets a value that specifies the size, in pixels, of the border around the button.
      /// @param xtd::null.
      /// @return Current xtd::forms::flat_button_appearance.
      auto border_size(xtd::null_ptr) -> flat_button_appearance&;
      
      /// @brief Gets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      [[nodiscard]] auto checked_back_color() const noexcept -> std::optional<xtd::drawing::color>;
      /// @brief Sets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @param value A xtd::drawing::color structure representing the color of the client area of the button.structure representing the color of the client area of the button.
      /// @return Current xtd::forms::flat_button_appearance.
      auto checked_back_color(const xtd::drawing::color& value) -> flat_button_appearance&;
      /// @brief Resets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @param xtd::null.
      /// @return Current flat_button_appearance.
      auto checked_back_color(xtd::null_ptr) -> flat_button_appearance&;
      
      /// @brief Gets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      [[nodiscard]] auto mouse_down_back_color() const noexcept -> std::optional<xtd::drawing::color>;
      /// @brief Sets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @param value A xtd::drawing::color structure representing the color of the client area of the button.
      /// @return Current xtd::forms::flat_button_appearance.
      auto mouse_down_back_color(const xtd::drawing::color& value) -> flat_button_appearance&;
      /// @brief Resets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @param xtd::null.
      /// @return Current xtd::forms::flat_button_appearance.
      auto mouse_down_back_color(xtd::null_ptr) -> flat_button_appearance&;
      
      /// @brief Gets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      [[nodiscard]] auto mouse_over_back_color() const noexcept -> std::optional<xtd::drawing::color>;
      /// @brief Sets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @param value A xtd::drawing::color structure representing the color of the client area of the button.
      /// @return Current xtd::forms::flat_button_appearance.
      auto mouse_over_back_color(const xtd::drawing::color& value) -> flat_button_appearance&;
      /// @brief Resets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @param xtd::null.
      /// @return Current xtd::forms::flat_button_appearance.
      auto mouse_over_back_color(xtd::null_ptr) -> flat_button_appearance&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const flat_button_appearance& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}

