#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/checked_list_box.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/list_box_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/checked_list_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

checked_list_box::checked_list_box() {
  //back_color_ = default_back_color();
  //fore_color_ = default_fore_color();
  size_ = default_size();

  items_.item_added += [&](size_t pos, const item& item) {
    native::checked_list_box::insert_item(handle(), pos, item.value(), static_cast<int32_t>(item.check_state()));
    checked_list_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };

  items_.item_erased += [&](size_t pos, const item& item) {
    native::checked_list_box::delete_item(handle(), pos);

    checked_list_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
  
  items_.item_updated += [&](size_t pos, const item& item) {
    native::checked_list_box::update_item(handle(), pos, item.value(), static_cast<int32_t>(item.check_state()));
    checked_list_box::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
}

checked_list_box::checked_index_collection checked_list_box::checked_indices() const {
  checked_index_collection indices;
  for(size_t index = 0; index < items_.size(); index++)
    if (items_[index].checked()) indices.push_back(index);
  return indices;
}
 
checked_list_box::checked_item_collection checked_list_box::checked_items() const {
  checked_item_collection items;
  for(checked_list_box::item item : items_)
    if (item.checked()) items.push_back(item);
  return items;
}

list_control& checked_list_box::selected_index(size_t selected_index) {
  if (selected_index_ != selected_index) {
    if (selected_index != npos && selected_index >= items_.size()) throw argument_out_of_range_exception("Selected index greater than items size"_t, caller_info_);
    selected_index_ = selected_index;
    native::checked_list_box::selected_index(handle(), selected_index_);

    item selected_item;
    if (selected_index_ != npos) selected_item = items_[selected_index_];
    this->selected_item(selected_item);

    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

vector<size_t> checked_list_box::selected_indices() const {
  return native::checked_list_box::selected_indices(handle());
}

list_box& checked_list_box::selected_item(const item& selected_item) {
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

vector<checked_list_box::item> checked_list_box::selected_items() const {
  vector<item> items;
  for (size_t index : selected_indices())
    items.push_back(items_[index]);
  return items;
}

void checked_list_box::begin_update() {
  native::checked_list_box::begin_update(handle());
}

void checked_list_box::end_update() {
  native::checked_list_box::end_update(handle());
}

bool checked_list_box::get_item_checked(size_t index) const {
  return items()[index].checked();
}

forms::check_state checked_list_box::get_item_check_state(size_t index) const {
  return items()[index].check_state();
}

const std::string& checked_list_box::get_item_text(size_t index) const {
  return items()[index].value();
}

void checked_list_box::set_item_checked(size_t index, bool checked) {
  if (items()[index].checked() != checked) {
    items()[index] = {items()[index].value(), checked, items()[index].tag()};
  }
}

void checked_list_box::set_item_check_state(size_t index, forms::check_state check_state) {
  if (items()[index].check_state() != check_state) {
    items()[index] = {items()[index].value(), check_state, items()[index].tag()};
  }
}

void checked_list_box::set_item_text(size_t index, const std::string& text) {
  items()[index] = {text, items()[index].checked(), items()[index].tag()};
}

forms::create_params checked_list_box::create_params() const {
  forms::create_params create_params = list_box::create_params();

  create_params.class_name("checkedlistbox");
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

void checked_list_box::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  items_.sorted(sorted_);
  for (size_t index = 0; index < items_.size(); ++index)
    native::checked_list_box::insert_item(handle(), index, items_[index].value(), items_[index].checked());
  if (selection_mode_ == forms::selection_mode::none) selected_index(npos);
  native::checked_list_box::selected_index(handle(), selected_index_);
  if (selected_index_ != npos) selected_item_ = items_[selected_index_];
}

void checked_list_box::on_selected_value_changed(const event_args& e) {
  list_box::text(selected_item_.value());
  list_box::on_selected_value_changed(e);
}

void checked_list_box::wnd_proc(message& message) {
  switch (message.msg()) {
  case WM_LBUTTONDOWN: wm_mouse_down(message); break;
  case WM_LBUTTONUP: wm_mouse_up(message); break;
  case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
  case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
  default: list_box::wnd_proc(message);
  }
}

void checked_list_box::wm_mouse_double_click(message& message) {
  selected_index(native::checked_list_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void checked_list_box::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void checked_list_box::wm_mouse_up(message& message) {
  selected_index(native::checked_list_box::selected_index(handle()));
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void checked_list_box::wm_reflect_command(message& message) {
  def_wnd_proc(message);
  size_t selected_index = native::checked_list_box::selected_index(handle());
  if (selected_index != npos) {
    forms::check_state check_state = static_cast<forms::check_state>(native::checked_list_box::check_state(handle(), selected_index));
    if (items_[selected_index].check_state() != check_state) {
      item_check_event_args item_check_event_args(selected_index, check_state, items_[selected_index].check_state());
      on_item_check(item_check_event_args);
      if (item_check_event_args.new_value() != check_state) native::checked_list_box::check_state(handle(), selected_index, static_cast<int>(item_check_event_args.new_value()));
      set_item_check_state(selected_index, item_check_event_args.new_value());
    }
  }
  this->selected_index(selected_index);
  if (selected_index_ != npos) selected_item(items_[selected_index_]);
}
