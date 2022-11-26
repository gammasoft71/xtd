#include <xtd/as.h>
#include <xtd/environment.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/tab_page.h>
#include <xtd/forms/native/tab_control_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"

using namespace xtd;
using namespace xtd::forms;

tab_control::tab_control() {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint, false);
}

tab_control& tab_control::alignment(tab_alignment alignment) {
  if (alignment_ != alignment) {
    alignment_ = alignment;
    post_recreate_handle();
  }
  return *this;
}

tab_control& tab_control::selected_index(size_t selected_index) {
  if (selected_index_ != selected_index) {
    selected_index_ = selected_index;
    if (is_handle_created()) native::tab_control::selected_index(handle(), selected_index_);
    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

tab_control& tab_control::image_list(const forms::image_list& value) {
  if (image_list_ != value) {
    image_list_ = value;
    post_recreate_handle();
  }
  return *this;
}

forms::create_params tab_control::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("tabcontrol");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  switch (alignment_) {
    case tab_alignment::bottom: create_params.style(create_params.style() | TCS_BOTTOM); break;
    case tab_alignment::left: create_params.style(create_params.style() | TCS_VERTICAL); break;
    case tab_alignment::right: create_params.style(create_params.style() | TCS_VERTICAL | TCS_RIGHT); break;
    default: break;
  }
  
  return create_params;
}

drawing::size tab_control::measure_control() const noexcept {
  drawing::rectangle bounds;
  for (auto item : controls())
    if (item.get().visible()) bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}

void tab_control::on_control_added(const control_event_args& e) {
  control::on_control_added(e);
  if (selected_index_ == npos) selected_index_ = 0;
}

void tab_control::on_control_removed(const control_event_args& e) {
  control::on_control_removed(e);
  if (controls().size() == 0) selected_index_ = npos;
}

void tab_control::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::tab_control::image_list(handle(), image_list_.handle());
  
  for (auto& control : controls())
    native::tab_page::image_index(as<tab_page>(control.get()).handle(), as<tab_page>(control.get()).image_index());
}

void tab_control::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: control::wnd_proc(message);
  }
}

void tab_control::wm_command_control(message& message) {
  def_wnd_proc(message);
  selected_index(native::tab_control::selected_index(handle()));
}
