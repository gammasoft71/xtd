/// @file
/// @brief Contains project_type_item_control class.
#pragma once
#include "project_type_item.hpp"
#include <xtd/forms/label>
#include <xtd/forms/picture_box>
#include <xtd/forms/user_control>

namespace xtdc_gui {
  /// @brief Represents the project_type_item_control control
  class project_type_item_control : public xtd::forms::user_control {
  public:
    /// @brief Initializes a new instance of the project_type_item_control class.
    project_type_item_control() : project_type_item_control(xtdc_gui::project_type_item {}) {}
    
    project_type_item_control(const xtdc_gui::project_type_item& project_type_item) : project_type_item_(project_type_item) {
      icon_.parent(*this);
      icon_.location({5, 20});
      icon_.size({40, 40});
      icon_.image(project_type_item.icon());
      //icon_.back_color(xtd::drawing::color::light_gray);
      icon_.click += {*this, &project_type_item_control::perform_click};
      icon_.double_click += {*this, &project_type_item_control::perform_double_click};
      
      name_.parent(*this);
      name_.location({50, 10});
      name_.auto_size(true);
      name_.text(project_type_item_.name());
      name_.font({name_.font(), xtd::drawing::font_style::bold});
      name_.click += {*this, &project_type_item_control::perform_click};
      name_.double_click += {*this, &project_type_item_control::perform_double_click};
      
      description_.parent(*this);
      description_.location({50, 30});
      description_.size({420, 40});
      //description_.back_color(xtd::drawing::color::black);
      description_.text(project_type_item_.description());
      description_.click += {*this, &project_type_item_control::perform_click};
      description_.double_click += {*this, &project_type_item_control::perform_double_click};
      
      height(80);
    }
    
    xtdc_gui::project_type_item project_type_item() const {return project_type_item_;}
    
  protected:
    xtd::uptr<xtd::object> clone() const override {
      auto result = xtd::new_uptr<project_type_item_control>(*this);
      if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()));
      return result;
    }
    
    void on_double_click(const xtd::event_args& e) override;
    
  private:
    void perform_click() {on_click(xtd::event_args::empty);}
    void perform_double_click() {on_double_click(xtd::event_args::empty);}
    xtdc_gui::project_type_item project_type_item_;
    xtd::forms::picture_box icon_;
    xtd::forms::label name_;
    xtd::forms::label description_;
  };
}
