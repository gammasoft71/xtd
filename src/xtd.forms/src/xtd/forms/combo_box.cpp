#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/combo_box.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/combo_box_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/combo_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

combo_box::combo_box() {
  //back_color_ = default_back_color();
  //fore_color_ = default_fore_color();
  size_ = default_size();
  drop_down_width_ = default_size().width();
  drop_down_height_ = static_cast<int32_t>(font().get_height()) * 9;

  items_.item_added += [&](size_t pos, const item& item) {
    native::combo_box::insert_item(handle(), pos, item.value());
    combo_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };

  items_.item_erased += [&](size_t pos, const item& item) {
    native::combo_box::delete_item(handle(), pos);

    combo_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
  
  items_.item_updated += [&](size_t pos, const item& item) {
    native::combo_box::update_item(handle(), pos, item.value());
    combo_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
}

combo_box& combo_box::drop_down_style(combo_box_style drop_down_style) {
  if (drop_down_style_ != drop_down_style) {
    drop_down_style_ = drop_down_style;
    recreate_handle();
    on_drop_down_style_changed(event_args::empty);
  }
  return *this;
}

list_control& combo_box::selected_index(size_t selected_index) {
  if (selected_index_ != selected_index) {
    if (selected_index != npos && selected_index >= items_.size()) throw argument_out_of_range_exception("Selected index greater than items size"_t, caller_info_);
    selected_index_ = selected_index;
    native::combo_box::selected_index(handle(), selected_index_);

    item selected_item;
    if (selected_index_ != npos) selected_item = items_[selected_index_];
    this->selected_item(selected_item);

    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

combo_box& combo_box::selected_item(const item& selected_item) {
  if (selected_item_ != selected_item) {
    auto it = std::find(items_.begin(), items_.end(), selected_item);
    if (it == items_.end())
      selected_item_ = selected_index() != npos ? items()[selected_index()] : "";
    else {
      size_t index = it - items_.begin();
      selected_index(index);
      selected_item_ = selected_item;
      on_selected_value_changed(event_args::empty);
    }
  }
  return *this;
}

combo_box& combo_box::sorted(bool sorted) {
  if (sorted_ != sorted) {
    sorted_ = sorted;
    items_.sorted(sorted_);
  }
  return *this;
}

void combo_box::begin_update() {
  native::combo_box::begin_update(handle());
}

void combo_box::end_update() {
  native::combo_box::end_update(handle());
}

forms::create_params combo_box::create_params() const {
  forms::create_params create_params = list_control::create_params();

  create_params.class_name("combobox");

  // Do not use native control sort
  //if (sorted_) create_params.style(create_params.style() | CBS_SORT);
  
  switch (drop_down_style_) {
    case combo_box_style::drop_down_list: create_params.style(create_params.style() | CBS_DROPDOWNLIST); break;
    case combo_box_style::drop_down: create_params.style(create_params.style() | CBS_DROPDOWN); break;
    case combo_box_style::simple: create_params.style(create_params.style() | CBS_SIMPLE); break;
  }

  if (drop_down_style_ == combo_box_style::simple && size_.height() == default_size().height())
    create_params.height(create_params.height() + drop_down_height_);
  
  return create_params;
}

void combo_box::on_drop_down_style_changed(const event_args& e) {
  drop_down_style_changed(*this, e);
}

void combo_box::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  items_.sorted(sorted_);
  for (size_t index = 0; index < items_.size(); ++index)
    native::combo_box::insert_item(handle(), index, items_[index].value());
  native::combo_box::selected_index(handle(), selected_index_);
  if (selected_index_ != npos) selected_item_ = items_[selected_index_];
}

void combo_box::on_selected_value_changed(const event_args& e) {
  list_control::text(selected_item_.value());
  list_control::on_selected_value_changed(e);
}

void combo_box::set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  drawing::size current_size = size_;
  list_control::set_bounds_core(x, y, width, height, specified);
  if (size_ != current_size)
    recreate_handle();
}

void combo_box::set_client_size_core(int32_t width, int32_t height) {
  drawing::size current_size = size_;
  list_control::set_client_size_core(width, height);
  if (size_ != current_size)
    recreate_handle();
}

void combo_box::wnd_proc(message& message) {
  switch (message.msg()) {
  case WM_LBUTTONDOWN: wm_mouse_down(message); break;
  case WM_LBUTTONUP: wm_mouse_up(message); break;
  case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
  case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
  default: list_control::wnd_proc(message);
  }
}

void combo_box::wm_mouse_double_click(message& message) {
  selected_index(native::combo_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void combo_box::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void combo_box::wm_mouse_up(message& message) {
  selected_index(native::combo_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void combo_box::wm_reflect_command(message& message) {
  def_wnd_proc(message);
  selected_index(native::combo_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
}
