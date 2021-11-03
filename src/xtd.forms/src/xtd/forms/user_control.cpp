#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/user_control.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/pens.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/user_control.h"

using namespace xtd;
using namespace xtd::forms;

user_control::user_control() {
  auto_size_mode_ = forms::auto_size_mode::grow_only;
  size_ = default_size();
}

user_control& user_control::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

user_control& user_control::border_style(forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    recreate_handle();
  }
  return *this;
}

forms::create_params user_control::create_params() const {
  forms::create_params create_params = scrollable_control::create_params();
  
  create_params.class_name("usercontrol");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

void user_control::on_handle_created(const event_args& e) {
  container_control::on_handle_created(e);
  
  // Workaround : on macOS with wxWidgets toolkit, retina display, dark mode enabled, and border style is fixed 3d, the border is not show.
  if (parent().has_value()) {
    parent().value().get().paint += [this](object& sender, paint_event_args& e) {
      if (environment::os_version().is_macos_platform() && native::toolkit::name() == "wxwidgets" && screen::from_handle(handle()).scale_factor() > 1. && application::dark_mode_enabled() && border_style_ == forms::border_style::fixed_3d)
        e.graphics().draw_rectangle(xtd::drawing::pens::white(), xtd::drawing::rectangle::offset(xtd::drawing::rectangle::inflate(this->bounds(), {-2, -2}), {1, 1}));
    };
  }
}

void user_control::on_layout(const event_args& e) {
  if (!application::message_loop()) return;
  scrollable_control::on_layout(e);
  if (auto_scroll_) native::user_control::virtual_size(handle(), display_rectangle().size());
}
