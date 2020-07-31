#pragma once
#include "orientation.h"
#include "scrollable_control.h"
#include "splitter.h"
#include "splitter_panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class split_container : public  xtd::forms::scrollable_control {
    public:
      split_container() {
        can_focus_ = false;
        size_ = default_size();
        controls().push_back_range({panel2_, splitter_, panel1_});
        arrange_childs();
      }
      
      drawing::size default_size() const override {return {150, 100};}
      
      virtual int splitter_distance() const {return splitter_distance_;}
      
      virtual xtd::forms::orientation orientation() const {return orientation_;}
      virtual split_container& orientation(xtd::forms::orientation orientation) {
        if (orientation_ != orientation) {
          orientation_ = orientation;
          arrange_childs();
        }
        return *this;
      }
      
      virtual xtd::forms::splitter_style splitter_style() const {return splitter_.splitter_style();}
      virtual split_container& splitter_style(xtd::forms::splitter_style splitter_style) {
        if (splitter_.splitter_style() != splitter_style) {
          splitter_.splitter_style(splitter_style);
        }
        return *this;
      }
      
      virtual int splitter_width() const {return splitter_width_;}
      virtual split_container& splitter_width(int splitter_width) {
        if (splitter_width_ != splitter_width) {
          splitter_width_ = splitter_width;
          arrange_childs();
        }
        return *this;
      }
      
      virtual const splitter_panel& panel1() const {return panel1_;};
      virtual splitter_panel& panel1() {return panel1_;};
      virtual const splitter_panel& panel2() const {return panel2_;};
      virtual splitter_panel& panel2() {return panel2_;};
      
    protected:
      void on_resize(const event_args& e) override {
        xtd::forms::scrollable_control::on_resize(e);
      }
      
    private:
      void arrange_childs() {
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
