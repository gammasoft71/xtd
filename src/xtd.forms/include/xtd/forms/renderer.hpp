/// @file
/// @brief Contains xtd::forms::renderer class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/check_box_state.hpp"
#include "visual_styles/push_button_state.hpp"
#include "visual_styles/radio_button_state.hpp"
#include "../forms_export.hpp"
#include "text_format_flags.hpp"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/graphics>
#include <xtd/drawing/image>
#include <xtd/drawing/rectangle>
#include <xtd/optional>
#include <xtd/delegate>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides control renderers methods.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/renderer>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ renderer : public object, public xtd::iequatable<renderer> {
      struct data;
      
    public:
      /// @name Public Aliases
      
      /// @{
      using button_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const xtd::string&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::push_button_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      using check_box_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const xtd::string&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::check_box_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      using radio_button_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const xtd::string&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::radio_button_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      /// @}
      
      /// @name Public Static Fields
      
      /// @{
      static const renderer empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      renderer();
      explicit renderer(const xtd::string& name);
      /// @}
      
      /// @cond
      renderer(const renderer&);
      renderer& operator =(const renderer&);
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      virtual const xtd::string& name() const;
      renderer& name(const xtd::string& name);
      
      button_renderer button_render() const noexcept;
      void button_render(button_renderer button_renderer);
      
      check_box_renderer check_box_render() const noexcept;
      void check_box_render(check_box_renderer check_box_renderer);
      
      radio_button_renderer radio_button_render() const noexcept;
      void radio_button_render(radio_button_renderer radio_button_renderer);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      using object::equals;
      bool equals(const renderer& value) const noexcept override;
      
      xtd::string to_string() const noexcept override;
      /// @}
      
    private:
      static void default_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void default_check_box_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void default_radio_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      xtd::sptr<data> data_;
    };
  }
}
