/// @file
/// @brief Contains project_type_item_control class.
#pragma once
#include "project_type_item.h"
#include <xtd/forms/label.h>
#include <xtd/forms/picture_box.h>
#include <xtd/forms/user_control.h>

namespace xtdc_gui {
  /// @brief Represents the project_type_item_control control
  class project_type_item_control : public xtd::forms::user_control {
  public:
    /// @brief Initializes a new instance of the project_type_item_control class.
    project_type_item_control() : project_type_item_control(xtdc_gui::project_type_item {}) {}

    project_type_item_control(const xtdc_gui::project_type_item& project_type_item) : project_type_item_(project_type_item) {
      icon_.parent(*this);
      icon_.location({5, 25});
      icon_.size({40, 40});
      icon_.back_color(xtd::drawing::color::light_gray);

      name_.parent(*this);
      name_.location({50, 10});
      name_.auto_size(true);
      name_.text(project_type_item_.name());
      name_.font({name_.font(), xtd::drawing::font_style::bold});

      description_.parent(*this);
      description_.location({50, 30});
      description_.size({420, 40});
      //description_.back_color(xtd::drawing::color::black);
      description_.text(project_type_item_.description());
      
      height(90);
    }

    xtdc_gui::project_type_item project_type_item() const {return project_type_item_;}
    
  private:
    xtdc_gui::project_type_item project_type_item_;
    xtd::forms::picture_box icon_;
    xtd::forms::label name_;
    xtd::forms::label description_;
  };
}
