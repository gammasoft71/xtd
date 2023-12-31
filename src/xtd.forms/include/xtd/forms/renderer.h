/// @file
/// @brief Contains xtd::forms::renderer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/check_box_state.h"
#include "visual_styles/push_button_state.h"
#include "visual_styles/radio_button_state.h"
#include "../forms_export.h"
#include "text_format_flags.h"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/graphics>
#include <xtd/drawing/image>
#include <xtd/drawing/rectangle>
#include <xtd/optional>
#include <xtd/delegate>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides control renderers methods.
    /// @par Header
    /// @code #include <xtd/forms/renderer> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ renderer : public object, public xtd::iequatable<renderer> {
      struct data;
      
    public:
      /// @name Alias
      
      /// @{
      using button_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const xtd::ustring&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::push_button_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      using check_box_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const xtd::ustring&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::check_box_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      using radio_button_renderer = xtd::delegate<void(xtd::drawing::graphics, const xtd::drawing::rectangle&, const xtd::ustring&, const xtd::drawing::font&, xtd::forms::text_format_flags, const xtd::drawing::image&, const xtd::drawing::rectangle&, bool focused, xtd::forms::visual_styles::radio_button_state, const std::optional<xtd::drawing::color>&, const std::optional<xtd::drawing::color>&)>;
      /// @}
      
      /// @name Fields
      
      /// @{
      static const renderer empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      renderer();
      explicit renderer(const xtd::ustring& name);
      /// @}
      
      /// @cond
      renderer(const renderer&);
      renderer& operator =(const renderer&);
      /// @endcond
      
      /// @name Properties
      
      /// @{
      virtual const xtd::ustring& name() const;
      renderer& name(const xtd::ustring& name);
      
      button_renderer button_render() const noexcept;
      void button_render(button_renderer button_renderer);
      
      check_box_renderer check_box_render() const noexcept;
      void check_box_render(check_box_renderer check_box_renderer);
      
      radio_button_renderer radio_button_render() const noexcept;
      void radio_button_render(radio_button_renderer radio_button_renderer);
      /// @}
      
      /// @name Methods
      
      /// @{
      void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      bool equals(const renderer& value) const noexcept override;
      
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      static void default_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void default_check_box_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void default_radio_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      std::shared_ptr<data> data_;
    };
  }
}
