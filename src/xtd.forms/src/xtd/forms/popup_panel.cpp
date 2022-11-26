#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/popup_panel.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/popup_panel.h"

using namespace xtd;
using namespace xtd::forms;

popup_panel::popup_panel() {
  visible(false);
}

bool popup_panel::ignore_mouse_messages() const {
  return ignore_mouse_messages_;
}

popup_panel& popup_panel::ignore_mouse_messages(bool value) {
  if (ignore_mouse_messages_ != value) {
    ignore_mouse_messages_ = value;
    native::popup_panel::ignore_mouse_messages(handle(), ignore_mouse_messages_);
  }
  return *this;
}

forms::create_params popup_panel::create_params() const noexcept {
  forms::create_params create_params = panel::create_params();
  
  create_params.class_name("popuppanel");
  
  return create_params;
}

void popup_panel::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::popup_panel::ignore_mouse_messages(handle(), ignore_mouse_messages_);
}

void popup_panel::on_layout(const event_args& e) {
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::popup_panel::virtual_size(handle(), display_rectangle().size());
}

void popup_panel::on_region_changed(const event_args& e) {
  native::popup_panel::set_region(handle(), region().handle());
  control::on_region_changed(e);
}

void popup_panel::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_SHOWWINDOW: wm_show(message); break;
    default: panel::wnd_proc(message); break;
  }
}

void popup_panel::wm_show(message& message) {
  panel::wnd_proc(message);
  
  bool visible = message.lparam() != 0;
  if (get_state(state::visible) != visible) {
    set_state(state::visible, visible);
    on_visible_changed(event_args::empty);
  }
}
