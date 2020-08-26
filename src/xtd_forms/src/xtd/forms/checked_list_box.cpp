#include <xtd/forms/native/control.h>
#include <xtd/forms/native/checked_list_box.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/list_box_styles.h>
#include "../../../include/xtd/forms/checked_list_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

checked_list_box::checked_list_box() {
  //this->back_color_ = this->default_back_color();
  //this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();

  this->items_.item_added += [&](size_t pos, const item& item) {
    native::checked_list_box::insert_item(handle(), pos, item.value(), item.checked());
    checked_list_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };

  this->items_.item_erased += [&](size_t pos, const item& item) {
    native::checked_list_box::delete_item(handle(), pos);

    checked_list_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
  
  this->items_.item_updated += [&](size_t pos, const item& item) {
    native::checked_list_box::update_item(handle(), pos, item.value(), item.checked());
    checked_list_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
}

checked_list_box::checked_index_collection checked_list_box::checked_indices() const {
  checked_index_collection indices;
  for(size_t index = 0; index < this->items_.size(); index++)
    if (this->items_[index].checked()) indices.push_back(index);
  return indices;
}
 
checked_list_box::checked_item_collection checked_list_box::checked_items() const {
  checked_item_collection items;
  for(checked_list_box::item item : this->items_)
    if (item.checked()) items.push_back(item);
  return items;
}

list_control& checked_list_box::selected_index(size_t selected_index) {
  if (this->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->items_.size()) throw invalid_argument("out of range index");
    this->selected_index_ = selected_index;
    native::checked_list_box::selected_index(handle(), this->selected_index_);

    item selected_item;
    if (this->selected_index_ != -1) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);

    this->on_selected_index_changed(event_args::empty);
  }
  return *this;
}

vector<size_t> checked_list_box::selected_indices() const {
  return native::checked_list_box::selected_indices(handle());
}

list_box& checked_list_box::selected_item(const item& selected_item) {
  if (this->selected_item_ != selected_item) {
    auto it = std::find(this->items_.begin(), this->items_.end(), selected_item);
    if (it == this->items_.end())
      this->selected_item_ = this->selected_index() != -1 ? this->items()[this->selected_index()] : "";
    else {
      size_t index = it - this->items_.begin();
      this->selected_index(index);
      this->selected_item_ = selected_item;
      this->on_selected_value_changed(event_args::empty);
    }
  }
  return *this;
}

vector<checked_list_box::item> checked_list_box::selected_items() const {
  vector<item> items;
  for (size_t index : this->selected_indices())
    items.push_back(this->items_[index]);
  return items;
}

void checked_list_box::begin_update() {
  native::checked_list_box::begin_update(handle());
}

void checked_list_box::end_update() {
  native::checked_list_box::end_update(handle());
}

bool checked_list_box::get_item_checked(size_t index) const {
  return this->items()[index].checked();
}

forms::check_state checked_list_box::get_item_check_state(size_t index) const {
  return this->items()[index].check_state();
}

const std::string& checked_list_box::get_item_text(size_t index) const {
  return this->items()[index].value();
}

void checked_list_box::set_item_checked(size_t index, bool checked) {
  if (this->items()[index].checked() != checked) {
    this->items()[index] = {this->items()[index].value(), checked, this->items()[index].tag()};
  }
}

void checked_list_box::set_item_check_state(size_t index, forms::check_state check_state) {
  if (this->items()[index].check_state() != check_state) {
    this->items()[index] = {this->items()[index].value(), check_state, this->items()[index].tag()};
  }
}

void checked_list_box::set_item_text(size_t index, const std::string& text) {
  this->items()[index] = {text, this->items()[index].checked(), this->items()[index].tag()};
}

forms::create_params checked_list_box::create_params() const {
  forms::create_params create_params = this->list_box::create_params();

  create_params.class_name("checkedlistbox");
  create_params.style(create_params.style() | LBS_HASSTRINGS);

  switch (this->selection_mode_) {
  case selection_mode::none: create_params.style(create_params.style() | LBS_NOSEL); break;
  case selection_mode::one:  break;
  case selection_mode::multi_simple: create_params.style(create_params.style() | LBS_MULTIPLESEL); break;
  case selection_mode::multi_extended: create_params.style(create_params.style() | LBS_MULTIPLESEL | LBS_EXTENDEDSEL); break;
  default: break;
  }

  // Do not use native control sort
  //if (this->sorted_) create_params.style(create_params.style() | LBS_SORT);

  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

void checked_list_box::on_handle_created(const event_args& e) {
  this->list_control::on_handle_created(e);
  items_.sorted(sorted_);
  for (size_t index = 0; index < this->items_.size(); ++index)
    native::checked_list_box::insert_item(handle(), index, this->items_[index].value(), this->items_[index].checked());
  if (this->selection_mode_ == forms::selection_mode::none) this->selected_index(-1);
  native::checked_list_box::selected_index(handle(), this->selected_index_);
  if (this->selected_index_ != -1) this->selected_item_ = this->items_[this->selected_index_];
}

void checked_list_box::on_selected_value_changed(const event_args& e) {
  this->list_box::text(this->selected_item_.value());
  this->list_box::on_selected_value_changed(e);
}

void checked_list_box::wnd_proc(message& message) {
  switch (message.msg()) {
  case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
  case WM_LBUTTONUP: this->wm_mouse_up(message); break;
  case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
  case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
  default: this->list_box::wnd_proc(message);
  }
}

void checked_list_box::wm_mouse_double_click(message& message) {
  this->selected_index(native::checked_list_box::selected_index(handle()));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void checked_list_box::wm_mouse_down(message& message) {
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void checked_list_box::wm_mouse_up(message& message) {
  this->selected_index(native::checked_list_box::selected_index(handle()));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void checked_list_box::wm_reflect_command(message& message) {
  this->def_wnd_proc(message);
  size_t selected_index = native::checked_list_box::selected_index(handle());
  if (selected_index != -1) {
    forms::check_state check_state = static_cast<forms::check_state>(native::checked_list_box::check_state(handle(), selected_index));
    if (this->items_[selected_index].check_state() != check_state) {
      item_check_event_args item_check_event_args(selected_index, check_state, this->items_[selected_index].check_state());
      this->on_item_check(item_check_event_args);
      if (item_check_event_args.new_value() != check_state) native::checked_list_box::check_state(handle(), selected_index, static_cast<int>(item_check_event_args.new_value()));
      this->set_item_check_state(selected_index, item_check_event_args.new_value());
    }
  }
  this->selected_index(selected_index);
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
}
