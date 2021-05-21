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
  can_focus_ = false;
  size_ = default_size();

  /*
  controls_.item_added += [this](size_t index, std::reference_wrapper<control> item) {
    native::tab_control::insert_item(handle(), index, item.get().handle());
    native::tab_control::page_text(handle(), index, item.get().text());
    if (selected_index_ == -1) selected_index_ = 0;
  };
   */
  
  /* tab_page is removed by tab_page::destroy_handle() method.
  controls_.item_erased += [this](size_t index, std::reference_wrapper<control> item) {
    native::tab_control::delete_item(handle_, index);
  };*/
}

tab_control& tab_control::alignment(tab_alignment alignment) {
  if (alignment_ != alignment) {
    alignment_ = alignment;
    recreate_handle();
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

tab_control& tab_control::image_list(const forms::image_list& value) {
  if (image_list_ != value) {
    image_list_ = value;
    recreate_handle();
  }
  return *this;
}

forms::create_params tab_control::create_params() const {
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

drawing::size tab_control::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : controls())
    if (item.get().visible()) bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}

void tab_control::on_control_added(const control_event_args &e) {
  native::tab_control::insert_item(handle(), controls().size() - 1, controls()[controls().size() - 1].get().handle());
  //native::tab_control::page_text(handle(), controls().size() - 1, controls()[controls().size() - 1].get().text());
  native::tab_page::text(controls()[controls().size() - 1].get().handle(), controls()[controls().size() - 1].get().text());
  if (xtd::environment::os_version().is_linux_platform()) {
    controls()[controls().size() - 1].get().size(size() - xtd::drawing::size(0, 40));
    controls()[controls().size() - 1].get().client_size(size() - xtd::drawing::size(0, 40));
  }
  if (selected_index_ == npos) selected_index_ = 0;
  control::on_control_added(e);
}

void tab_control::on_control_removed(const control_event_args &e) {
  control::on_control_removed(e);
  if (selected_index_ != npos) selected_index(npos);
}

void tab_control::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::tab_control::image_list(handle(), image_list_.handle());
}

void tab_control::recreate_handle() {
  control::recreate_handle();

  native::tab_control::image_list(handle(), image_list_.handle());
  for (auto index = 0U; index < controls().size(); index++) {
    native::tab_control::insert_item(handle(), index, controls()[index].get().handle());
    //native::tab_control::page_text(handle(), index, controls()[index].get().text());
    //native::tab_control::page_image_index(handle(), index, dynamic_cast<xtd::forms::tab_page&>(controls()[index].get()).image_index());
    native::tab_page::text(controls()[index].get().handle(), controls()[index].get().text());
    native::tab_page::image_index(controls()[index].get().handle(), static_cast<tab_page&>(controls()[index].get()).image_index());
  }
}

void tab_control::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
    default: control::wnd_proc(message);
  }
}

void tab_control::wm_reflect_command(message& message) {
  def_wnd_proc(message);
  selected_index(native::tab_control::selected_index(handle()));
}
