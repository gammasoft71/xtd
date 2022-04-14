/// @file
/// @brief Contains xtd::forms::tool_bar_button container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "tool_bar_item.h"
#include <xtd/event.h>
#include <xtd/event_handler.h>
#include <xtd/forms/image_list.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a toolbar button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms  menus_and_toolbars
    class tool_bar_button : public tool_bar_item {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_button class.
      tool_bar_button() = default;
      explicit tool_bar_button(const xtd::ustring& text);
      tool_bar_button(const xtd::ustring& text, const xtd::event_handler& on_click);
      explicit tool_bar_button(size_t image_index);
      tool_bar_button(size_t image_index, const xtd::event_handler& on_click);
      tool_bar_button(const xtd::ustring& text, size_t image_index);
      tool_bar_button(const xtd::ustring& text, size_t image_index, const xtd::event_handler& on_click);
      /// @}
      
      /// @cond
      template<typename delegate_type>
      tool_bar_button(const xtd::ustring& text, size_t image_index, delegate_type on_click) : tool_bar_button(text, image_index, xtd::event_handler(on_click)) {}
      /// @endcond
      
      /// @name Properties
      
      /// @{
      bool enabled() const;
      tool_bar_button& enabled(bool value);

      const xtd::ustring& text() const;
      tool_bar_button& text(const xtd::ustring& value);
      
      size_t image_index() const;
      tool_bar_button& image_index(size_t value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Generates a click event for the xtd::forms::tool_bar_item.
      void perform_click() override;
      /// @}
      
      /// @name Events
      
      /// @{
      xtd::event<tool_bar_button, xtd::event_handler> click;
      /// @}
      
    protected:
      /// @name protected methods
      
      /// @{
      void on_click(const xtd::event_args& e);
      /// @}
      
    private:
      xtd::ustring text_;
      size_t image_index_ = xtd::forms::image_list::image_collection::npos;
      bool enabled_ = true;
    };
  }
}
