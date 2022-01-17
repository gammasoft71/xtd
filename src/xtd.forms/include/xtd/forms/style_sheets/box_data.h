/// @file
/// @brief Contains xtd::forms::style_sheets::box_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "border_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class box_data : public xtd::object {
      public:
        box_data() = default;
        box_data(const xtd::forms::padding& margin, const std::array<xtd::forms::style_sheets::border_data, 4>& borders, const xtd::forms::padding& padding, const std::shared_ptr<xtd::drawing::brush>& background_color, std::optional<int32_t> width, std::optional<int32_t> height) : margin_(margin), borders_(borders), padding_(padding), background_color_(background_color), width_(width), height_(height) {}
        
        /// @cond
        box_data(const box_data&) = default;
        box_data(box_data&&) = default;
        box_data& operator=(const box_data&) = default;
        /// @endcond

        const std::shared_ptr<xtd::drawing::brush>& background_color() const noexcept {return background_color_;}
        const std::array<xtd::forms::style_sheets::border_data, 4>& borders() const noexcept {return borders_;}
        std::optional<int32_t> height() const noexcept {return height_;}
        const xtd::forms::padding& margin() const noexcept {return margin_;}
        const xtd::forms::padding& padding() const noexcept {return padding_;}
        std::optional<int32_t> width() const noexcept {return width_;}

      private:
        xtd::forms::padding margin_;
        std::array<xtd::forms::style_sheets::border_data, 4> borders_;
        xtd::forms::padding padding_;
        std::shared_ptr<xtd::drawing::brush> background_color_;
        std::optional<int32_t> width_;
        std::optional<int32_t> height_;
      };
    }
  }
}
