#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/tab_control.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/tab_control.hpp"

using namespace xtd;
using namespace xtd::forms;

tab_control::tab_control() {
  this->can_focus_ = false;
  this->size_ = this->default_size();
}

forms::create_params tab_control::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("tabcontrol");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  return create_params;
}

drawing::size tab_control::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls())
    bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}
