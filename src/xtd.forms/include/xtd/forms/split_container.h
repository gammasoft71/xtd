/// @file
/// @brief Contains xtd::forms::split_container container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
    /// The following code example demonstrate the use of split_container container.
    /// @include split_container.cpp
    class forms_export_ split_container : public  xtd::forms::scrollable_control {
    public:
      /// @brief Initializes a new instance of the split_container class.
      split_container() {
        can_focus_ = false;
        size_ = default_size();
        controls().push_back_range({panel2_, splitter_, panel1_});
        arrange_children();
      }
      
      drawing::size default_size() const override {return {150, 100};}

      /// @brief Gets a value indicating the horizontal or vertical orientation of the split_container panels.
      /// @return One of the orientation values. The default is vertical.
      virtual xtd::forms::orientation orientation() const {return orientation_;}
      /// @brief Sets a value indicating the horizontal or vertical orientation of the split_container panels.
      /// @param orientation One of the orientation values. The default is vertical.
      /// @return Current split_container instance.
      virtual split_container& orientation(xtd::forms::orientation orientation) {
        if (orientation_ != orientation) {
          orientation_ = orientation;
          arrange_children();
        }
        return *this;
      }
      
      /// @brief Gets the left or top panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the left panel of the split_container. If orientation is horizontal, the top panel of the split_container.
      virtual const splitter_panel& panel1() const {return panel1_;};
      /// @brief Gets the left or top panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the left panel of the split_container. If orientation is horizontal, the top panel of the split_container.
      virtual splitter_panel& panel1() {return panel1_;};

      /// @brief Gets the right or bottom panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the right panel of the split_container. If orientation is horizontal, the bottom panel of the split_container.
      virtual const splitter_panel& panel2() const {return panel2_;};
      /// @brief Gets the right or bottom panel of the splitter_panel, depending on orientation.
      /// @return If orientation is vertical, the right panel of the split_container. If orientation is horizontal, the bottom panel of the split_container.
      virtual splitter_panel& panel2() {return panel2_;};

      /// @brief Gets the location of the splitter, in pixels, from the left or top edge of the split_container.
      /// @return An int32_t representing the location of the splitter, in pixels, from the left or top edge of the split_container. The default value is 50 pixels.
      virtual int splitter_distance() const {return splitter_distance_;}
      /// @brief Sets the location of the splitter, in pixels, from the left or top edge of the split_container.
      /// @param splitter_distance An int32_t representing the location of the splitter, in pixels, from the left or top edge of the split_container. The default value is 50 pixels.
      /// @return Current split_container instance.
      virtual split_container& splitter_distance(int splitter_distance) {
        if (splitter_distance_ != splitter_distance) {
          splitter_distance_ = splitter_distance;
          if (orientation_ == xtd::forms::orientation::horizontal) panel1_.height(splitter_distance);
          else panel1_.width(splitter_distance);
        }
        return *this;
      }

      /// @brief Gets the style of the splitter.
      /// @return One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      virtual xtd::forms::splitter_style splitter_style() const {return splitter_.splitter_style();}
      /// @brief Sets the style of the splitter.
      /// @param splitter_style One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      /// @return Current split_container instance.
      virtual split_container& splitter_style(xtd::forms::splitter_style splitter_style) {
        if (splitter_.splitter_style() != splitter_style) {
          splitter_.splitter_style(splitter_style);
        }
        return *this;
      }
      
      /// @brief Gets or sets the width of the splitter in pixels.
      /// @return An int32_t representing the width of the splitter, in pixels. The default is four pixels.
      /// @remarks Use the splitter_width property to change the width of the splitter itself, not the split_container.
      virtual int splitter_width() const {return splitter_width_;}
      /// @brief Gets or sets the width of the splitter in pixels.
      /// @param splitter_width An int32_t representing the width of the splitter, in pixels. The default is four pixels.
      /// @return Current split_container instance.
      /// @remarks Use the splitter_width property to change the width of the splitter itself, not the split_container.
      virtual split_container& splitter_width(int splitter_width) {
        if (splitter_width_ != splitter_width) {
          splitter_width_ = splitter_width;
          arrange_children();
        }
        return *this;
      }
      
    protected:
      void on_resize(const event_args& e) override {
        xtd::forms::scrollable_control::on_resize(e);
      }
      
    private:
      void arrange_children() {
        if (orientation_ == xtd::forms::orientation::vertical) {
          panel1_.dock(xtd::forms::dock_style::left);
          panel1_.width(splitter_distance_);
          splitter_.dock(xtd::forms::dock_style::left);
          splitter_.width(splitter_width_);
        } else {
          panel1_.dock(xtd::forms::dock_style::top);
          panel1_.height(splitter_distance_);
          splitter_.dock(xtd::forms::dock_style::top);
          splitter_.height(splitter_width_);
        }
        panel2_.dock(xtd::forms::dock_style::fill);
      }
      
      xtd::forms::orientation orientation_ = xtd::forms::orientation::vertical;
      splitter_panel panel1_;
      splitter splitter_;
      splitter_panel panel2_;
      int splitter_distance_ = 50;
      //int splitter_increment_ = 1;
      int splitter_width_ = 4;
    };
  }
}
