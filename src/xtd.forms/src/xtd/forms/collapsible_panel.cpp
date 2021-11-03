#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/collapsible_panel.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/collapsible_panel.h"

using namespace xtd;
using namespace xtd::forms;

collapsible_panel::collapsible_panel() {
  auto_size_mode_ = forms::auto_size_mode::grow_and_shrink;
  can_focus_ = false;
}

collapsible_panel& collapsible_panel::border_style(forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    recreate_handle();
  }
  return *this;
}

collapsible_panel& collapsible_panel::expanded(bool expanded) {
  if (expanded_ != expanded) {
    expanded_ = expanded;
    native::collapsible_panel::expanded(handle_, expanded_);
    on_expanded_changed(event_args::empty);
  }
  return *this;
}

forms::create_params collapsible_panel::create_params() const {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("collapsiblepanel");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

void collapsible_panel::on_control_added(const control_event_args& e) {
  control::on_control_added(e);
  if (expanded()) {
    expanded(false);
    expanded(true);
  }
}

void collapsible_panel::on_control_removed(const control_event_args& e) {
  control::on_control_removed(e);
  /*
  if (expanded()) {
    expanded(false);
    expanded(true);
  }
   */
}

void collapsible_panel::on_expanded_changed(const xtd::event_args& e) {
  if (parent().has_value()) parent().value().get().perform_layout();
  expanded_changed(*this, e);
}

void collapsible_panel::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  size(native::control::size(handle_));
}

drawing::size collapsible_panel::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}

void collapsible_panel::wnd_proc(message &message) {
  switch (message.msg()) {
    case  WM_COMMAND: wm_command(message); break;
    default: control::wnd_proc(message);
  }
}

void collapsible_panel::wm_command(message &message) {
  expanded_ = native::collapsible_panel::expanded(handle_);
  size(native::control::size(handle_));
  on_expanded_changed(event_args::empty);
}
