/// @file
/// @brief Contains xtd::forms::style_sheets::border_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/object.h>
#include <xtd/drawing/brush.h>
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class border_data : public xtd::object {
      public:
        border_data() = default;
        border_data(const std::shared_ptr<xtd::drawing::brush>& color, xtd::forms::style_sheets::border_style style, int32_t width, int32_t radius) : color_(color), style_(style), width_(width), radius_(radius) {}

        /// @cond
        border_data(const border_data&) = default;
        border_data(border_data&&) = default;
        border_data& operator=(const border_data&) = default;
        /// @endcond
        
        const std::shared_ptr<xtd::drawing::brush>& color() const noexcept {return color_;}
        xtd::forms::style_sheets::border_style style() const noexcept {return style_;}
        int32_t radius() const noexcept {return radius_;}
        int32_t width() const noexcept {return width_;}

      private:
        std::shared_ptr<xtd::drawing::brush> color_;
        xtd::forms::style_sheets::border_style style_ = xtd::forms::style_sheets::border_style::none;
        int32_t width_ = 3;
        int32_t radius_ = 10;
      };
    }
  }
}
