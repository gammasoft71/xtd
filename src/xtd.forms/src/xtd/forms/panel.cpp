#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/panel.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/pens.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/panel.h"

using namespace xtd;
using namespace xtd::forms;

panel::panel() {
  auto_size_mode_ = forms::auto_size_mode::grow_only;
  can_focus_ = false;
  size_ = default_size();
}

panel& panel::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

panel& panel::border_style(forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    recreate_handle();
  }
  return *this;
}

forms::create_params panel::create_params() const {
  forms::create_params create_params = scrollable_control::create_params();
  
  create_params.class_name("panel");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
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
  if (auto_scroll_) native::panel::virtual_size(handle(), display_rectangle().size());
}

void panel::on_paint(paint_event_args& e) {
  scrollable_control::on_paint(e);
  // Workaround : on macOS with wxWidgets toolkit, retina display, dark mode enabled, and border style is not none, the border is not show.
  if (environment::os_version().is_macos_platform() && native::toolkit::name() == "wxwidgets" && screen::from_handle(parent().value().get().handle()).scale_factor() > 1. && application::dark_mode_enabled() && border_style_ != forms::border_style::none)
    e.graphics().draw_rectangle(xtd::drawing::pens::white(), xtd::drawing::rectangle::inflate(e.clip_rectangle(), {-3, -3}));
}
