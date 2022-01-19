/// @file
/// @brief Contains xtd::forms::style_sheets::text_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include <xtd/drawing/brush.h>
#include <xtd/drawing/string_format.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class text_data : public xtd::object {
      public:
        text_data() = default;
        text_data(const xtd::ustring& text, const std::shared_ptr<xtd::drawing::brush>& color, const xtd::drawing::string_format& format) : text_(text), color_(color), format_(format) {}
        
        /// @cond
        text_data(const text_data&) = default;
        text_data(text_data&&) = default;
        text_data& operator=(const text_data&) = default;
        /// @endcond
        
        const xtd::ustring& text() const noexcept {return text_;}
        const std::shared_ptr<xtd::drawing::brush>& color() const noexcept {return color_;}
        const xtd::drawing::string_format& format() const noexcept {return format_;}
        
      private:
        xtd::ustring text_;
        std::shared_ptr<xtd::drawing::brush> color_;
        xtd::drawing::string_format format_;
      };
    }
  }
}
