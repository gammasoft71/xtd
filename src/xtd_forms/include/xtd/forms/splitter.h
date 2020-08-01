#pragma once
#include "control.h"
#include "splitter_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class splitter : public xtd::forms::control {
    public:
      splitter() {
        size_ = default_size();
        dock(xtd::forms::dock_style::left);
      }
      
      using xtd::forms::control::dock;
      virtual control& dock(dock_style dock) override {
        if (control::dock() != dock_style::left && control::dock() == dock_style::right && control::dock() == dock_style::top && control::dock() == dock_style::bottom) throw std::invalid_argument("splitter control must be docked left, right, top, or bottom.");
        control::dock(dock);
        cursor(default_cursor());
        if (default_width_ && (dock == dock_style::left || dock == dock_style::right)) width(3);
        if (default_width_ && (dock == dock_style::top || dock == dock_style::bottom)) height(3);
        return *this;
      }
      
      virtual int min_size() const {return min_size_;}
      virtual splitter& min_size(int min_size) {
        if (min_size_ != min_size) {
          min_size_ = min_size;
        }
        return *this;
      }
      
      virtual xtd::forms::splitter_style splitter_style() const {return splitter_style_;}
      virtual splitter& splitter_style(xtd::forms::splitter_style splitter_style) {
        if (splitter_style_ != splitter_style) {
          splitter_style_ = splitter_style;
        }
        return *this;
      }
      
      /// @brief Gets the default cusros of the control.
      /// @return A cursor that represents the default cursor of the control.
      forms::cursor default_cursor() const override {return dock_ == dock_style::left || dock_ == dock_style::right ? xtd::forms::cursors::vsplit() : xtd::forms::cursors::hsplit();}
      
      /// @brief Gets the default size of the control.
      /// @return A size that represents the default size of the control.
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
