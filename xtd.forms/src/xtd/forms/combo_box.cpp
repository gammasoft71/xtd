#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/combo_box.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <xtd/forms/native/window_combo_box.hpp>
#include "../../../include/xtd/forms/combo_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

combo_box::combo_box() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();
  this->drop_down_width_ = this->default_size().width();
  this->drop_down_height_ = this->font().get_height() * 9;

  this->items_.item_added += [&](size_t pos, const item& item) {
    native::combo_box::insert_item(this->handle_, pos, item.value());
    if (this->sorted_) std::sort(this->items_.begin(), this->items_.end());
    combo_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };

  this->items_.item_erased += [&](size_t pos, const item& item) {
    native::combo_box::delete_item(this->handle_, pos);

    combo_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
  
  this->items_.item_updated += [&](size_t pos, const item& item) {
    static bool update_disabled = false;
    if (update_disabled) return;
    native::combo_box::delete_item(this->handle_, pos);
    native::combo_box::insert_item(this->handle_, pos, item.value());
    if (this->sorted_) {
      update_disabled = true;
      std::sort(this->items_.begin(), this->items_.end());
      update_disabled = false;
    }
    combo_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
}

combo_box& combo_box::drop_down_style(combo_box_style drop_down_style) {
  if (this->drop_down_style_ != drop_down_style) {
    this->drop_down_style_ = drop_down_style;
    this->recreate_handle();
    this->on_drop_down_style_changed(event_args::empty);
  }
  return *this;
}

list_control& combo_box::selected_index(size_t selected_index) {
  if (this->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->items_.size()) throw invalid_argument("out of range index");
    this->selected_index_ = selected_index;
    native::combo_box::selected_index(this->handle_, this->selected_index_);

    item selected_item;
    if (this->selected_index_ != -1) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);

    this->on_selected_index_changed(event_args::empty);
  }
  return *this;
}

combo_box& combo_box::selected_item(const item& selected_item) {
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

combo_box& combo_box::sorted(bool sorted) {
  if (this->sorted_ != sorted) {
    this->sorted_ = sorted;
    if (this->sorted_) std::sort(this->items_.begin(), this->items_.end());
    this->recreate_handle();
  }
  return *this;
}

void combo_box::begin_update() {
  native::combo_box::begin_update(this->handle_);
}

void combo_box::end_update() {
  native::combo_box::end_update(this->handle_);
}

forms::create_params combo_box::create_params() const {
  forms::create_params create_params = this->list_control::create_params();

  create_params.class_name("combobox");

  if (this->sorted_) create_params.style(create_params.style() | CBS_SORT);
  
  switch (this->drop_down_style_) {
    case combo_box_style::drop_down_list: create_params.style(create_params.style() | CBS_DROPDOWNLIST); break;
    case combo_box_style::drop_down: create_params.style(create_params.style() | CBS_DROPDOWN); break;
    case combo_box_style::simple: create_params.style(create_params.style() | CBS_SIMPLE); break;
  }
  
  return create_params;
}

void combo_box::on_drop_down_style_changed(const event_args& e) {
  this->drop_down_style_changed(*this, e);
}

void combo_box::on_handle_created(const event_args& e) {
  this->list_control::on_handle_created(e);
  for (size_t index = 0; index < this->items_.size(); ++index)
    native::combo_box::insert_item(this->handle_, index, this->items_[index].value());
  native::combo_box::selected_index(this->handle_, this->selected_index_);
  if (this->selected_index_ != -1) this->selected_item_ = this->items_[this->selected_index_];
}

void combo_box::on_selected_value_changed(const event_args& e) {
  this->list_control::text(this->selected_item_.value());
  this->list_control::on_selected_value_changed(e);
}

void combo_box::wnd_proc(message& message) {
  switch (message.msg()) {
  case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
  case WM_LBUTTONUP: this->wm_mouse_up(message); break;
  case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
  case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
  default: this->list_control::wnd_proc(message);
  }
}

void combo_box::wm_mouse_double_click(message& message) {
  this->selected_index(native::combo_box::selected_index(this->handle_));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void combo_box::wm_mouse_down(message& message) {
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void combo_box::wm_mouse_up(message& message) {
  this->selected_index(native::combo_box::selected_index(this->handle_));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
  if (this->allow_selection())
    this->list_control::wnd_proc(message);
}

void combo_box::wm_reflect_command(message& message) {
  this->def_wnd_proc(message);
  this->selected_index(native::combo_box::selected_index(this->handle_));
  if (this->selected_index_ != -1) this->selected_item(this->items_[this->selected_index_]);
}
