/// @file
/// @brief Contains xtd::forms::style_sheets::label_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class label_data : public xtd::object {
      public:
        label_data() = default;
        label_data(const xtd::forms::style_sheets::box_data& box, const std::shared_ptr<xtd::drawing::brush>& color) : box_(box), color_(color) {}
        
        /// @cond
        label_data(const label_data&) = default;
        label_data(label_data&&) = default;
        label_data& operator=(const label_data&) = default;
        /// @endcond
        
        const xtd::forms::style_sheets::box_data& box() const noexcept {return box_;}
        const std::shared_ptr<xtd::drawing::brush>& color() const noexcept {return color_;}
        
      private:
        xtd::forms::style_sheets::box_data box_;
        std::shared_ptr<xtd::drawing::brush> color_;
      };
    }
  }
}
