/// @file
/// @brief Contains xtd::forms::renderer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include <xtd/delegate.h>
#include <xtd/object.h>
#include <xtd/strings.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/rectangle.h>
#include "../forms_export.h"
#include "text_format_flags.h"
#include "visual_styles/check_box_state.h"
#include "visual_styles/push_button_state.h"
#include "visual_styles/radio_button_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides control renderers methods.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ renderer : public object {
    public:
      using button_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const std::string&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::push_button_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      using check_box_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const std::string&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::check_box_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      using radio_button_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const std::string&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::radio_button_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;

      renderer() = default;
      explicit renderer(const std::string& name) : name_(name) {}
      /// @cond
      renderer(const renderer&) = default;
      renderer& operator=(const renderer&) = default;
      bool operator==(const renderer& value) const {return name_ == value.name_;}
      bool operator!=(const renderer& value) const {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const renderer& theme) noexcept {return os << theme.to_string();}
      /// @endcond
      
      virtual const std::string& name() const {return name_;}
      renderer& name(const std::string& name) {
        name_ = name;
        return *this;
      }
      
      button_renderer button_render() const  {return button_renderer_;}
      void button_render(button_renderer button_renderer) {button_renderer_ = button_renderer;}
      
      check_box_renderer check_box_render() const  {return check_box_renderer_;}
      void check_box_render(check_box_renderer check_box_renderer) {check_box_renderer_ = check_box_renderer;}
      
      radio_button_renderer radio_button_render() const  {return radio_button_renderer_;}
      void radio_button_render(radio_button_renderer radio_button_renderer) {radio_button_renderer_ = radio_button_renderer;}
      
      void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {button_renderer_(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}
      void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {check_box_renderer_(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}
      void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {radio_button_renderer_(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}

      std::string to_string() const noexcept override {
        if (!name_.empty()) return xtd::strings::format("{}, name: {}", strings::full_class_name(*this), name_);
        return xtd::strings::format(xtd::strings::full_class_name(*this));
      }

      static const renderer empty;
      
    protected:
      
    private:
      static void default_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void default_check_box_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void default_radio_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);

      std::string name_;
      button_renderer button_renderer_ = button_renderer(default_button_renderer);
      check_box_renderer check_box_renderer_ = check_box_renderer(default_check_box_renderer);
      radio_button_renderer radio_button_renderer_ = radio_button_renderer(default_radio_button_renderer);
    };
  }
}
