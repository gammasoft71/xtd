#include <xtd/forms/native/control.h>
#include <xtd/forms/native/choice.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/choice.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

choice::choice() {
  //this->back_color_ = this->default_back_color();
  //this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();

  this->items_.item_added += [&](size_t pos, const item& item) {
    native::choice::insert_item(handle(), pos, item.value());
    size_t selected_index = -1;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_index = this->selected_index_;
    this->selected_index(selected_index);
  };

  this->items_.item_erased += [&](size_t pos, const item& item) {
    native::choice::delete_item(handle(), pos);

    size_t selected_index = -1;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_index = this->selected_index_;
    this->selected_index(selected_index);
  };
  
  this->items_.item_updated += [&](size_t pos, const item& item) {
    native::choice::update_item(handle(), pos, item.value());
    size_t selected_index = -1;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_index = this->selected_index_;
    this->selected_index(selected_index);
  };
}

list_control& choice::selected_index(size_t selected_index) {
  if (this->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->items_.size()) throw invalid_argument("out of range index");
    this->selected_index_ = selected_index;
    native::choice::selected_index(handle(), this->selected_index_);

    item selected_item;
    if (this->selected_index_ != -1) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);

    this->on_selected_index_changed(event_args::empty);
  }
  return *this;
}

choice& choice::selected_item(const item& selected_item) {
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

choice& choice::sorted(bool sorted) {
  if (this->sorted_ != sorted) {
    this->sorted_ = sorted;
    items_.sorted(sorted_);
  }
  return *this;
}

void choice::begin_update() {
  native::choice::begin_update(handle());
}

void choice::end_update() {
  native::choice::end_update(handle());
}

forms::create_params choice::create_params() const {
  forms::create_params create_params = this->list_control::create_params();

  create_params.class_name("choice");

  // Do not use native control sort
  //if (this->sorted_) create_params.style(create_params.style() | CBS_SORT);
    
  return create_params;
}

void choice::on_handle_created(const event_args& e) {
  this->list_control::on_handle_created(e);
  items_.sorted(sorted_);
  for (size_t index = 0; index < this->items_.size(); ++index)
    native::choice::insert_item(handle(), index, this->items_[index].value());
  native::choice::selected_index(handle(), this->selected_index_);
  if (this->selected_index_ != -1) this->selected_item_ = this->items_[this->selected_index_];
}

void choice::on_selected_value_changed(const event_args& e) {
  this->list_control::text(this->selected_item_.value());
  this->list_control::on_selected_value_changed(e);
}

void choice::set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  drawing::size current_size = size_;
  list_control::set_bounds_core(x, y, width, height, specified);
  if (size_ != current_size)
    recreate_handle();
}

void choice::set_client_size_core(int32_t width, int32_t height) {
  drawing::size current_size = size_;
  list_control::set_client_size_core(width, height);
  if (size_ != current_size)
    recreate_handle();
}

void choice::wnd_proc(message& message) {
  switch (message.msg()) {
  case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
  case WM_LBUTTONUP: this->wm_mouse_up(message); break;
  case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
  case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
  default: this->list_control::wnd_proc(message);
  }
}

void choice::wm_mouse_double_click(message& message) {
  this->selected_index(native::choice::selected_index(handle()));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void choice::wm_mouse_down(message& message) {
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void choice::wm_mouse_up(message& message) {
  this->selected_index(native::choice::selected_index(handle()));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void choice::wm_reflect_command(message& message) {
  this->def_wnd_proc(message);
  this->selected_index(native::choice::selected_index(handle()));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
}
