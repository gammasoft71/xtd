/// @file
/// @brief Contains xtd::forms::link_label class.
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
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class flat_button_appearance : public object {
    public:
      /// @brief Initializes a new instance of the xtd::forms::link_label::link class.
      flat_button_appearance() = default;
      flat_button_appearance(const flat_button_appearance&) = default;
      flat_button_appearance(flat_button_appearance&&) = default;
      flat_button_appearance& operator=(const flat_button_appearance&) = default;
      bool operator==(const flat_button_appearance& other) const {return border_color_ == other.border_color_ && border_size_ == other.border_size_ && checked_back_color_ == other.checked_back_color_ && mouse_down_back_color_ == other.mouse_down_back_color_ && mouse_over_back_color_ == other.mouse_over_back_color_;}
      bool operator!=(const flat_button_appearance& other) const {return !operator==(other);}
      /// @endcond

      std::optional<xtd::drawing::color> border_color() const;
      flat_button_appearance& border_color(const xtd::drawing::color& color);
      flat_button_appearance& border_color(nullptr_t);

      int32_t border_size() const;
      flat_button_appearance& border_size(int32_t size);
      
      std::optional<xtd::drawing::color> checked_back_color() const;
      flat_button_appearance& checked_back_color(const xtd::drawing::color& color);
      flat_button_appearance& checked_back_color(nullptr_t);

      std::optional<xtd::drawing::color> mouse_down_back_color() const;
      flat_button_appearance& mouse_down_back_color(const xtd::drawing::color& color);
      flat_button_appearance& mouse_down_back_color(nullptr_t);

      std::optional<xtd::drawing::color> mouse_over_back_color() const;
      flat_button_appearance& mouse_over_back_color(const xtd::drawing::color& color);
      flat_button_appearance& mouse_over_back_color(nullptr_t);

    private:
      std::optional<xtd::drawing::color> border_color_;
      int32_t border_size_ = 1;
      std::optional<xtd::drawing::color> checked_back_color_;
      std::optional<xtd::drawing::color> mouse_down_back_color_;
      std::optional<xtd::drawing::color> mouse_over_back_color_;
    };
  }
}

