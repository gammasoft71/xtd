/// @file
/// @brief Contains xtd::forms::flat_button_appearance class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include <xtd/object.h>
#include <xtd/drawing/color.h>
#include "theme_colors.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides properties that specify the appearance of xtd::forms::button controls whose xtd::forms::flat_style is xtd::forms::flat_style::flat.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class flat_button_appearance : public object {
    public:
      /// @brief Initializes a new instance of the xtd::forms::flat_button_appearance class.
      flat_button_appearance() = default;
      /// @cond
      flat_button_appearance(const flat_button_appearance&) = default;
      flat_button_appearance(flat_button_appearance&&) = default;
      flat_button_appearance& operator=(const flat_button_appearance&) = default;
      bool operator==(const flat_button_appearance& other) const {return border_color_ == other.border_color_ && border_size_ == other.border_size_ && checked_back_color_ == other.checked_back_color_ && mouse_down_back_color_ == other.mouse_down_back_color_ && mouse_over_back_color_ == other.mouse_over_back_color_;}
      bool operator!=(const flat_button_appearance& other) const {return !operator==(other);}
      /// @endcond

      /// @brief Gets the color of the border around the button.
      /// @return A xtd::drawing::color structure representing the color of the border around the button.
      std::optional<xtd::drawing::color> border_color() const;
      /// @brief Sets the color of the border around the button.
      /// @param color A xtd::drawing::color structure representing the color of the border around the button.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& border_color(const xtd::drawing::color& color);
      /// @brief Reseets the color of the border around the button.
      /// @param color nullptr.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& border_color(nullptr_t color);

      /// @brief Gets a value that specifies the size, in pixels, of the border around the button.
      /// @return An int32_t representing the size, in pixels, of the border around the button.
      int32_t border_size() const;
      /// @brief Sets a value that specifies the size, in pixels, of the border around the button.
      /// @param size An int32_t representing the size, in pixels, of the border around the button.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& border_size(int32_t size);
      
      /// @brief Gets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      std::optional<xtd::drawing::color> checked_back_color() const;
      /// @brief Sets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @param color A xtd::drawing::color structure representing the color of the client area of the button.structure representing the color of the client area of the button.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& checked_back_color(const xtd::drawing::color& color);
      /// @brief Reseets the color of the client area of the button when the button is checked and the mouse pointer is outside the bounds of the control.
      /// @param color nullptr.
      /// @return Current flat_button_appearance.
      flat_button_appearance& checked_back_color(nullptr_t color);

      /// @brief Gets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      std::optional<xtd::drawing::color> mouse_down_back_color() const;
      /// @brief Sets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @param color A xtd::drawing::color structure representing the color of the client area of the button.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& mouse_down_back_color(const xtd::drawing::color& color);
      /// @brief Reseets the color of the client area of the button when the mouse is pressed within the bounds of the control.
      /// @param color nullptr.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& mouse_down_back_color(nullptr_t color);

      /// @brief Gets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @return A xtd::drawing::color structure representing the color of the client area of the button.
      std::optional<xtd::drawing::color> mouse_over_back_color() const;
      /// @brief Sets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @param color A xtd::drawing::color structure representing the color of the client area of the button.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& mouse_over_back_color(const xtd::drawing::color& color);
      /// @brief Reseets the color of the client area of the button when the mouse pointer is within the bounds of the control.
      /// @param color nullptr.
      /// @return Current xtd::froms::flat_button_appearance.
      flat_button_appearance& mouse_over_back_color(nullptr_t color);

    private:
      std::optional<xtd::drawing::color> border_color_;
      int32_t border_size_ = 1;
      std::optional<xtd::drawing::color> checked_back_color_;
      std::optional<xtd::drawing::color> mouse_down_back_color_;
      std::optional<xtd::drawing::color> mouse_over_back_color_;
    };
  }
}

