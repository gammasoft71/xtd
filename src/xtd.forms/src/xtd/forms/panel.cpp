#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/panel.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/pens.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/panel.h"

using namespace xtd;
using namespace xtd::forms;

panel::panel() {
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  set_can_focus(false);
}

panel& panel::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

panel& panel::border_style(forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    if (control_appearance() == forms::control_appearance::system) recreate_handle();
    else invalidate();
  }
  return *this;
}

forms::create_params panel::create_params() const {
  forms::create_params create_params = scrollable_control::create_params();
  
  create_params.class_name("panel");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (control_appearance() == forms::control_appearance::system) {
    if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style_ != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  return create_params;
}

drawing::size panel::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}

void panel::on_layout(const event_args& e) {
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::panel::virtual_size(handle(), display_rectangle().size());
}

void panel::on_paint(paint_event_args& e) {
  scrollable_control::on_paint(e);
  if (control_appearance() == forms::control_appearance::standard)
    control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), back_color(), e.clip_rectangle());
}
