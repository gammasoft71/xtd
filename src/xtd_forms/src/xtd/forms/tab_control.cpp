#include <xtd/environment.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/tab_control_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/tab_control.h"

using namespace xtd;
using namespace xtd::forms;

tab_control::tab_control() {
  this->can_focus_ = false;
  this->size_ = this->default_size();

  /*
  this->controls_.item_added += [this](size_t index, std::reference_wrapper<control> item) {
    native::tab_control::insert_item(handle(), index, item.get().handle());
    native::tab_control::page_text(handle(), index, item.get().text());
    if (selected_index_ == -1) selected_index_ = 0;
  };
   */
  
  /* tab_page is removed by tab_page::destroy_handle() method.
  this->controls_.item_erased += [this](size_t index, std::reference_wrapper<control> item) {
    native::tab_control::delete_item(handle_, index);
  };*/
}

tab_control& tab_control::alignment(tab_alignment alignment) {
  if (this->alignment_ != alignment) {
    this->alignment_ = alignment;
    this->recreate_handle();
  }
  return *this;
}

tab_control& tab_control::selected_index(size_t selected_index) {
  if (selected_index_ != selected_index) {
    selected_index_ = selected_index;
    native::tab_control::selected_index(handle(), selected_index_);
    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

forms::create_params tab_control::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("tabcontrol");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  switch (this->alignment_) {
    case tab_alignment::bottom: create_params.style(create_params.style() | TCS_BOTTOM); break;
    case tab_alignment::left: create_params.style(create_params.style() | TCS_VERTICAL); break;
    case tab_alignment::right: create_params.style(create_params.style() | TCS_VERTICAL | TCS_RIGHT); break;
    default: break;
  }
  
  return create_params;
}

drawing::size tab_control::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls())
    if (item.get().visible()) bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}

void tab_control::on_control_added(const control_event_args &e) {
  native::tab_control::insert_item(handle(), controls().size() - 1, controls()[controls().size() - 1].get().handle());
  native::tab_control::page_text(handle(), controls().size() - 1, controls()[controls().size() - 1].get().text());
  if (xtd::environment::os_version().is_linux_platform()) {
    controls()[controls().size() - 1].get().size(size() - xtd::drawing::size(0, 40));
    controls()[controls().size() - 1].get().client_size(size() - xtd::drawing::size(0, 40));
  }
  if (selected_index_ == -1) selected_index_ = 0;
  control::on_control_added(e);
}

void tab_control::on_control_removed(const control_event_args &e) {
  control::on_control_removed(e);
  if (selected_index_ != -1) selected_index(-1);
}

void tab_control::recreate_handle() {
  control::recreate_handle();

  for (int index = 0; index < controls().size(); index++) {
    native::tab_control::insert_item(handle(), index, controls()[index].get().handle());
    native::tab_control::page_text(handle(), index, controls()[index].get().text());
  }
}

void tab_control::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
    default: this->control::wnd_proc(message);
  }
}

void tab_control::wm_reflect_command(message& message) {
  this->def_wnd_proc(message);
  selected_index(native::tab_control::selected_index(this->handle()));
}
