/// @file
/// @brief Contains xtd::forms::tool_bar container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include "button.h"
#include "border_style.h"
#include "image_list.h"
#include "panel.h"
#include "tool_bar_button.h"
#include "tool_bar_separator.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows toolbar.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms  menus_and_toolbars
    /// @par Examples
    /// The following code example demonstrate the use of tool_bar control.
    /// @include tool_bar.cpp
    class forms_export_ tool_bar : public control {
      class tool_bar_button_control : public xtd::forms::button {
      public:
        tool_bar_button_control() = default;
        
        void tool_bar_item(tool_bar_item_ref value) {tool_bar_item_ = value;}
        
      protected:
        void on_click(const xtd::event_args& e) override {
          xtd::forms::button::on_click(e);
          if (tool_bar_item_.has_value()) tool_bar_item_.value().get().perform_click();
        }
        
      private:
        std::optional<tool_bar_item_ref> tool_bar_item_;
      };
      
      class tool_bar_separator_control : public xtd::forms::control {
      public:
        tool_bar_separator_control() = default;
      protected:
        void on_paint(paint_event_args& e) override;
      };
      
    public:
      using tool_bar_item_collection = xtd::forms::layout::arranged_element_collection<tool_bar_item_ref>;
      
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of tool_bar class.
      tool_bar();
      /// @}

      /// @name Properties
      
      /// @{
      const xtd::forms::image_list& image_list() const;
      xtd::forms::image_list& image_list();
      xtd::forms::tool_bar& image_list(const xtd::forms::image_list& value);
      
      xtd::drawing::size default_size() const override;
      
      const tool_bar_item_collection& items() const;
      tool_bar_item_collection& items();
      /// @}
      
    protected:
      /// @name Protetced methods
      
      /// @{
      void on_paint(xtd::forms::paint_event_args& e) override;
      /// @}

      /// @cond
      /// @endcond

    private:
      void fill();
      
      void on_item_added(size_t pos, tool_bar_item_ref item);
      
      void on_item_updated(size_t pos, tool_bar_item_ref item);
      
      void on_item_removed(size_t pos, tool_bar_item_ref item);

      struct data {
        forms::border_style border_style;
        xtd::forms::image_list image_list;
        tool_bar_item_collection items;
        std::vector<std::shared_ptr<xtd::forms::control>> tool_bar_items;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
