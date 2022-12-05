/// @file
/// @brief Contains xtd::forms::split_container container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "orientation.h"
#include "scrollable_control.h"
#include "splitter.h"
#include "splitter_panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a control consisting of a movable bar that divides a container's display area into two resizable panels.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrates the use of split_container container.
    /// @include split_container.cpp
    class forms_export_ split_container : public  xtd::forms::scrollable_control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the split_container class.
      split_container();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating the horizontal or vertical orientation of the split_container panels.
      /// @return One of the orientation values. The default is vertical.
      virtual xtd::forms::orientation orientation() const noexcept;
      /// @brief Sets a value indicating the horizontal or vertical orientation of the split_container panels.
      /// @param orientation One of the orientation values. The default is vertical.
      /// @return Current split_container instance.
      virtual split_container& orientation(xtd::forms::orientation orientation);
      
      /// @brief Gets the left or top panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the left panel of the split_container. If orientation is horizontal, the top panel of the split_container.
      virtual const splitter_panel& panel1() const noexcept;
      /// @brief Gets the left or top panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the left panel of the split_container. If orientation is horizontal, the top panel of the split_container.
      virtual splitter_panel& panel1() noexcept;
      
      /// @brief Gets the right or bottom panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the right panel of the split_container. If orientation is horizontal, the bottom panel of the split_container.
      virtual const splitter_panel& panel2() const noexcept;
      /// @brief Gets the right or bottom panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the right panel of the split_container. If orientation is horizontal, the bottom panel of the split_container.
      virtual splitter_panel& panel2() noexcept;
      
      /// @brief Gets the location of the splitter, in pixels, from the left or top edge of the split_container.
      /// @return An int32_t representing the location of the splitter, in pixels, from the left or top edge of the split_container. The default value is 50 pixels.
      virtual int32_t splitter_distance() const noexcept;
      /// @brief Sets the location of the splitter, in pixels, from the left or top edge of the split_container.
      /// @param splitter_distance An int32_t representing the location of the splitter, in pixels, from the left or top edge of the split_container. The default value is 50 pixels.
      /// @return Current split_container instance.
      virtual split_container& splitter_distance(int32_t splitter_distance);
      
      /// @brief Gets the style of the splitter.
      /// @return One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      virtual xtd::forms::splitter_style splitter_style() const noexcept;
      /// @brief Sets the style of the splitter.
      /// @param splitter_style One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      /// @return Current split_container instance.
      virtual split_container& splitter_style(xtd::forms::splitter_style splitter_style);
      
      /// @brief Gets or sets the width of the splitter in pixels.
      /// @return An int32_t representing the width of the splitter, in pixels. The default is four pixels.
      /// @remarks Use the splitter_width property to change the width of the splitter itself, not the split_container.
      virtual int32_t splitter_width() const noexcept;
      /// @brief Gets or sets the width of the splitter in pixels.
      /// @param splitter_width An int32_t representing the width of the splitter, in pixels. The default is four pixels.
      /// @return Current split_container instance.
      /// @remarks Use the splitter_width property to change the width of the splitter itself, not the split_container.
      virtual split_container& splitter_width(int32_t splitter_width);
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      drawing::size default_size() const noexcept override;
      /// @}

      /// @name Protected methods
      
      /// @{
      void on_resize(const event_args& e) override;
      /// @}
      
    private:
      void arrange_children();
      
      struct data {
        xtd::forms::orientation orientation = xtd::forms::orientation::vertical;
        splitter_panel panel1;
        splitter_panel panel2;
        xtd::forms::splitter splitter;
        int32_t splitter_distance = 50;
        //int32_t splitter_increment = 1;
        int32_t splitter_width = 4;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
