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
    /// @cond
    class form;
    /// @endcond
    
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
        tool_bar_button_control();
        
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
        tool_bar_separator_control();
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
      /// @brief Get the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const {return data_->border_sides;}
      /// @brief Set the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual tool_bar& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual forms::border_style border_style() const {return data_->border_style;}
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current panel instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual tool_bar& border_style(forms::border_style border_style);

      dock_style dock() const override;
      control& dock(dock_style dock) override;

      const xtd::forms::image_list& image_list() const;
      xtd::forms::image_list& image_list();
      tool_bar& image_list(const xtd::forms::image_list& value);
      
      virtual bool is_system_tool_bar() const {return data_->is_system_tool_bar;}
      
      xtd::drawing::size default_size() const override;
      
      const tool_bar_item_collection& items() const;
      tool_bar_item_collection& items();
      /// @}
      
    protected:
      friend form;

      /// @name Protetced properties
      
      /// @{
      virtual tool_bar& is_system_tool_bar(bool value);
      /// @}
      
      /// @name Protetced methods
      
      /// @{
      forms::create_params create_params() const override;
      void on_handle_created(const event_args &e) override;
      void on_handle_destroyed(const event_args &e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}

    private:
      void fill();
      
      void on_item_added(size_t pos, tool_bar_item_ref item);
      void on_item_updated(size_t pos, tool_bar_item_ref item);
      void on_item_removed(size_t pos, tool_bar_item_ref item);

      void wm_click(message& message);
      
      struct data {
        forms::border_sides border_sides = forms::border_sides::all;
        forms::border_style border_style;
        xtd::forms::image_list image_list;
        tool_bar_item_collection items;
        bool is_system_tool_bar = false;
        dock_style non_system_dock = dock_style::none;
        std::vector<std::shared_ptr<xtd::forms::control>> tool_bar_items;
        std::vector<intptr_t> system_tool_bar_item_handles;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
