/// @file
/// @brief Contains xtd::forms::tool_bar_button container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "component.h"
#include <xtd/event.h>
#include <xtd/event_handler.h>
#include <xtd/forms/image_list.h>
#include <xtd/forms/context_menu.h>
#include <xtd/forms/tool_bar_button_style.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    class tool_bar;
    /// @endcond
    
    /// @brief Represents a toolbar button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms  menus_and_toolbars
    class tool_bar_button : public xtd::forms::component {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_button class.
      tool_bar_button() = default;
      explicit tool_bar_button(const xtd::ustring& text);
      /// @}
      
      /// @cond
      tool_bar_button(const tool_bar_button&) noexcept = default;
      tool_bar_button(tool_bar_button&&) noexcept = default;
      tool_bar_button& operator=(const tool_bar_button&) noexcept = default;
      bool operator==(const tool_bar_button& other) const noexcept {return data_ == other.data_;}
      bool operator!=(const tool_bar_button& other) const noexcept {return !operator==(other);}
      /// @endcond
      
      /// @name Properties
      
      /// @{
      std::optional<std::reference_wrapper<xtd::forms::control>> control() const;
      tool_bar_button& control(const xtd::forms::control& value);
      tool_bar_button& control(std::nullptr_t value);

      std::optional<std::reference_wrapper<xtd::forms::context_menu>> drop_down_menu() const;
      tool_bar_button& drop_down_menu(const xtd::forms::context_menu& value);
      tool_bar_button& drop_down_menu(std::nullptr_t value);

      bool enabled() const;
      tool_bar_button& enabled(bool value);
      
      size_t image_index() const;
      tool_bar_button& image_index(size_t value);

      bool pushed() const;
      tool_bar_button& pushed(bool value);
      
      const xtd::drawing::rectangle& rectangle() const;
      
      const xtd::ustring& text() const;
      tool_bar_button& text(const xtd::ustring& value);

      xtd::forms::tool_bar_button_style style() const;
      tool_bar_button& style(xtd::forms::tool_bar_button_style value);

      bool visible() const;
      tool_bar_button& visible(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      static tool_bar_button create_control(const xtd::ustring& text, const xtd::forms::control& control);
      static tool_bar_button create_control(const xtd::forms::control& control);
      static tool_bar_button create_drop_down_button(const xtd::ustring& text, const xtd::forms::context_menu& drop_down_menu);
      static tool_bar_button create_drop_down_button(size_t image_index, const xtd::forms::context_menu& drop_down_menu);
      static tool_bar_button create_drop_down_button(const xtd::ustring& text, size_t image_index, const xtd::forms::context_menu& drop_down_menu);
      static tool_bar_button create_push_button(const xtd::ustring& text);
      static tool_bar_button create_push_button(size_t image_index);
      static tool_bar_button create_push_button(const xtd::ustring& text, size_t image_index);
      static tool_bar_button create_separator();
      static tool_bar_button create_stretchable_separator();
      static tool_bar_button create_toggle_button(const xtd::ustring& text);
      static tool_bar_button create_toggle_button(size_t image_index);
      static tool_bar_button create_toggle_button(const xtd::ustring& text, size_t image_index);
      
    private:
      friend xtd::forms::tool_bar;
      struct data {
        xtd::forms::control* control = nullptr;
        std::optional<std::reference_wrapper<xtd::forms::context_menu>> drop_down_menu;
        bool enabled = true;
        size_t image_index = xtd::forms::image_list::image_collection::npos;
        xtd::drawing::image image_key;
        bool partial_push = false;
        bool pushed = false;
        xtd::drawing::rectangle rectangle;
        xtd::forms::tool_bar_button_style style = xtd::forms::tool_bar_button_style::push_button;
        std::any tag;
        xtd::ustring text;
        xtd::ustring tool_tip_text;
        bool visible = true;
        xtd::forms::tool_bar* parent = nullptr;
        intptr_t handle = 0;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
    
    /// @brief Represents a xtd::forms::tool_bar_item reference.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using tool_bar_button_ref = std::reference_wrapper<tool_bar_button>;
  }
}
