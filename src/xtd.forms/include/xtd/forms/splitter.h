/// @file
/// @brief Contains xtd::forms::splitter control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "splitter_style.h"
#include <xtd/argument_exception.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a splitter control that enables the user to resize docked controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of splitter control.
    /// @include splitter.cpp
    class forms_export_ splitter : public xtd::forms::control {
    public:
      /// @brief Initializes a new instance of the splitter class.
      splitter() {
        size_ = default_size();
        dock(xtd::forms::dock_style::left);
      }
      
      using xtd::forms::control::dock;
      /// @brief Sets or sets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @param dock One of the dock_style values. The default is none.
      /// @return Current control.
      /// @remarks Use the dock property to define how a control is automatically resized as its parent control is resized. For example, setting dock to dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The anchor and dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the dock property in a derived class, use the base class's dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the dock property; you can override only one if needed.
      virtual control& dock(dock_style dock) override {
        if (control::dock() != dock_style::left && control::dock() == dock_style::right && control::dock() == dock_style::top && control::dock() == dock_style::bottom) throw argument_exception("splitter control must be docked left, right, top, or bottom."_t, current_stack_frame_);
        control::dock(dock);
        cursor(default_cursor());
        if (default_width_ && (dock == dock_style::left || dock == dock_style::right)) width(3);
        if (default_width_ && (dock == dock_style::top || dock == dock_style::bottom)) height(3);
        return *this;
      }
      
      /// @brief Gets the minimum distance that must remain between the splitter control and the container edge that the control is docked to.
      /// @return The minimum distance, in pixels, between the splitter control and the container edge that the control is docked to. The default is 25.
      virtual int min_size() const {return min_size_;}
      /// @brief Sets the minimum distance that must remain between the splitter control and the container edge that the control is docked to.
      /// @param min_size The minimum distance, in pixels, between the splitter control and the container edge that the control is docked to. The default is 25.
      /// @return Current splitter instance.
      virtual splitter& min_size(int min_size) {
        if (min_size_ != min_size) {
          min_size_ = min_size;
        }
        return *this;
      }
      
      /// @brief Gets the style of the splitter.
      /// @return One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      virtual xtd::forms::splitter_style splitter_style() const {return splitter_style_;}
      /// @brief Sets the style of the splitter.
      /// @param splitter_style One of xtd::forms::splitter_style values. The default is xtd::forms::splitter_style::update_children
      /// @return Current splitter instance.
      virtual splitter& splitter_style(xtd::forms::splitter_style splitter_style) {
        if (splitter_style_ != splitter_style) {
          splitter_style_ = splitter_style;
        }
        return *this;
      }
      
      forms::cursor default_cursor() const override {return dock_ == dock_style::left || dock_ == dock_style::right ? xtd::forms::cursors::vsplit() : xtd::forms::cursors::hsplit();}
      
      drawing::size default_size() const override {return {3, 3};}
      
    protected:
      void on_mouse_down(const mouse_event_args& e) override {
        control::on_mouse_down(e);
        mouse_down_location = control::dock() == dock_style::left || control::dock() == dock_style::right ? cursor::position().x() : cursor::position().y();
        if (parent().has_value()) {
          for(size_t index = 0; index < parent().value().get().controls().size(); index++) {
            if (parent().value().get().controls()[index].get() == *this) {
              if (index > 0) previous_control_cursor_ = (previous_control_ = &parent().value().get().controls()[index - 1].get())->cursor();
              if (index < parent().value().get().controls().size() -1) next_control_cursor_ = (next_control_ = &parent().value().get().controls()[index + 1].get())->cursor();
              break;
            }
          }
        }
        if (previous_control_) previous_control_->cursor(default_cursor());
        if (next_control_) next_control_->cursor(default_cursor());
      }
      
      void on_mouse_move(const mouse_event_args& e) override {
        control::on_mouse_move(e);
        if (previous_control_) previous_control_->cursor(default_cursor());
        if (next_control_) next_control_->cursor(default_cursor());
        if (mouse_down_location != -1 && next_control_) {
          if (splitter_style_ == splitter_style::draw_line) {
            
          } else {
            int delta_size = control::dock() == dock_style::left || control::dock() == dock_style::right ? (next_control_->width() + cursor::position().x()) : (next_control_->height() + cursor::position().y());
            int new_size = delta_size - mouse_down_location;
            if (new_size < min_size_) new_size = min_size_;
            //if (previous_control_.size()  < min_size_extra_) new_size = min_size_;
            if (control::dock() == dock_style::left || control::dock() == dock_style::right) next_control_->width(new_size);
            else next_control_->height(new_size);
            mouse_down_location = control::dock() == dock_style::left || control::dock() == dock_style::right ? cursor::position().x() : cursor::position().y();
          }
        }
      }
      
      void on_mouse_up(const mouse_event_args& e) override {
        control::on_mouse_up(e);
        if (previous_control_) previous_control_->cursor(previous_control_cursor_);
        if (next_control_) next_control_->cursor(previous_control_cursor_);
        if (mouse_down_location != -1 && parent().has_value() && next_control_) {
          int new_size = (control::dock() == dock_style::left || control::dock() == dock_style::right ? (next_control_->width() + cursor::position().x()) : (next_control_->height() + cursor::position().y())) - mouse_down_location;
          if (new_size < min_size_) new_size = min_size_;
          if (control::dock() == dock_style::left || control::dock() == dock_style::right) next_control_->width(new_size);
          else next_control_->height(new_size);
          mouse_down_location = -1;
        }
        previous_control_ = nullptr;
        next_control_ = nullptr;
      }
      
      void on_handle_created(const event_args& e) override {
        control::on_handle_created(e);
      }
      
    private:
      bool default_width_ = true;
      int min_size_ = 25;
      //int min_size_extra_ = 25;
      //int split_position_ = -1;
      int mouse_down_location = -1;
      xtd::forms::splitter_style splitter_style_ = xtd::forms::splitter_style::update_childs;
      xtd::forms::cursor previous_control_cursor_;
      xtd::forms::cursor next_control_cursor_;
      control* previous_control_ = nullptr;
      control* next_control_ = nullptr;
    };
  }
}
