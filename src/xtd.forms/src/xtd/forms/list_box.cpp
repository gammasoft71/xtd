#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/list_box.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/list_box_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/pens.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/list_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

list_box::list_box() {
  //back_color_ = default_back_color();
  //fore_color_ = default_fore_color();
  size_ = default_size();

  items_.item_added += [this](size_t index, const item& item) {
    native::list_box::insert_item(handle(), index, item.value());
    list_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };

  items_.item_erased += [this](size_t index, const item& item) {
    native::list_box::delete_item(handle(), index);
    list_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
  
  items_.item_updated += [this](size_t index, const item& item) {
    native::list_box::update_item(handle(), index, item.value());
    list_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
}

list_box& list_box::border_style(forms::border_style border_style) {
  if (border_style_ != border_style) {
    border_style_ = border_style;
    recreate_handle();
  }
  return *this;
}

list_control& list_box::selected_index(size_t selected_index) {
  if (selected_index != npos && selected_index >= items_.size()) throw argument_out_of_range_exception("Selected index greater than items size"_t, caller_info_);
  if (selected_index_ != selected_index) {
    selected_index_ = selected_index;
    native::list_box::selected_index(handle(), selected_index_);

    item selected_item;
    if (selected_index_ != npos) selected_item = items_[selected_index_];
    this->selected_item(selected_item);

    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

vector<size_t> list_box::selected_indices() const {
  return native::list_box::selected_indices(handle());
}

list_box& list_box::selected_item(const item& selected_item) {
  if (selected_item_ != selected_item) {
    auto it = std::find(items_.begin(), items_.end(), selected_item);
    if (it == items_.end()) {
      if (selected_index() == npos || items().size() == 0) selected_item_ = "";
      else {
        if (selected_index() >= items().size()) selected_item_ = items()[items().size() - 1];
        else selected_item_ = items()[selected_index()];
      }
    }
    else {
      size_t index = it - items_.begin();
      selected_index(index);
      selected_item_ = selected_item;
      on_selected_value_changed(event_args::empty);
    }
  }
  return *this;
}

vector<list_box::item> list_box::selected_items() const {
  vector<item> items;
  for (size_t index : selected_indices())
    items.push_back(items_[index]);
  return items;
}

list_box& list_box::selection_mode(forms::selection_mode selection_mode) {
  if (selection_mode_ != selection_mode) {
    selection_mode_ = selection_mode;
    recreate_handle();
  }
  return *this;
}

list_box& list_box::sorted(bool sorted) {
  if (sorted_ != sorted) {
    sorted_ = sorted;
    items_.sorted(sorted_);
  }
  return *this;
}

void list_box::begin_update() {
  native::list_box::begin_update(handle());
}

void list_box::end_update() {
  native::list_box::end_update(handle());
}

forms::create_params list_box::create_params() const {
  forms::create_params create_params = list_control::create_params();

  create_params.class_name("listbox");
  create_params.style(create_params.style() | LBS_HASSTRINGS);

  switch (selection_mode_) {
  case selection_mode::none: create_params.style(create_params.style() | LBS_NOSEL); break;
  case selection_mode::one:  break;
  case selection_mode::multi_simple: create_params.style(create_params.style() | LBS_MULTIPLESEL); break;
  case selection_mode::multi_extended: create_params.style(create_params.style() | LBS_MULTIPLESEL | LBS_EXTENDEDSEL); break;
  default: break;
  }

  // Do not use native control sort
  //if (sorted_) create_params.style(create_params.style() | LBS_SORT);

  if (border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);

  return create_params;
}

void list_box::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  items_.sorted(sorted_);
  for (size_t index = 0; index < items_.size(); ++index)
    native::list_box::insert_item(handle(), index, items_[index].value());
  if (selection_mode_ == forms::selection_mode::none) selected_index(npos);
  native::list_box::selected_index(handle(), selected_index_);
  if (selected_index_ != npos) selected_item_ = items_[selected_index_];
}

void list_box::on_paint(paint_event_args& e) {
  list_control::on_paint(e);
  
  // Workaround : on macOS with wxWidgets toolkit, retina display, dark mode enabled and border style is not none, the border is not show.
  if (environment::os_version().is_macos_platform() && native::toolkit::name() == "wxwidgets" && screen::from_handle(handle()).scale_factor() > 1. && application::dark_mode_enabled() && border_style_ != forms::border_style::none)
    e.graphics().draw_rectangle(xtd::drawing::pens::white(), xtd::drawing::rectangle::inflate(e.clip_rectangle(), {-2, -2}));
}

void list_box::on_selected_value_changed(const event_args& e) {
  list_control::text(selected_item_.value());
  list_control::on_selected_value_changed(e);
}

void list_box::wnd_proc(message& message) {
  switch (message.msg()) {
  case WM_LBUTTONDOWN: wm_mouse_down(message); break;
  case WM_LBUTTONUP: wm_mouse_up(message); break;
  case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
  case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
  default: list_control::wnd_proc(message);
  }
}

void list_box::wm_mouse_double_click(message& message) {
  selected_index(native::list_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_mouse_up(message& message) {
  selected_index(native::list_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_reflect_command(message& message) {
  def_wnd_proc(message);
  selected_index(native::list_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
}
