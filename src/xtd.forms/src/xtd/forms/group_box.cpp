#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/group_box.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/group_box.h"

using namespace xtd;
using namespace xtd::forms;

group_box::group_box() {
  auto_size_mode_ = forms::auto_size_mode::grow_only;
  can_focus_ = false;
  size_ = default_size();
}

group_box& group_box::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

forms::create_params group_box::create_params() const {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("groupbox");
  create_params.style(create_params.style() | BS_GROUPBOX);
  
  return create_params;
}

drawing::size group_box::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}

void group_box::on_font_changed(const xtd::event_args& e) {
  control::on_font_changed(e);
  if (flat_style_ != xtd::forms::flat_style::system) invalidate();
}

void group_box::on_text_changed(const xtd::event_args& e) {
  control::on_text_changed(e);
  if (flat_style_ != xtd::forms::flat_style::system) invalidate();
}

void group_box::on_resize(const xtd::event_args& e) {
  control::on_resize(e);
  if (flat_style_ != xtd::forms::flat_style::system) invalidate();
}
