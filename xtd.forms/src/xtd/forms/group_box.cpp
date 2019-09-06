#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/group_box.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/group_box.hpp"

using namespace xtd;
using namespace xtd::forms;

group_box::group_box() {
  this->make_control(*this);
  this->control::data_->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->control::data_->size_ = this->default_size();
}

group_box& group_box::operator=(const group_box& value) {
  this->control::operator=(value);
  this->data_ = value.data_;
  return *this;
}

group_box& group_box::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

forms::create_params group_box::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("GROUPBOX"); // "BUTTON" for win32
  create_params.style(create_params.style() | BS_GROUPBOX);
  
  return create_params;
}

drawing::size group_box::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls())
    bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}
