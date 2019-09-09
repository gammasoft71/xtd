#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/list_box.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <xtd/forms/native/window_list_box.hpp>
#include "../../../include/xtd/forms/list_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

list_box::list_box() {
  this->make_control(*this);
  this->control::data_->back_color_ = this->default_back_color();
  this->control::data_->fore_color_ = this->default_fore_color();
  this->control::data_->size_ = this->default_size();

  this->data_->items_.item_added += [&](size_t pos, const std::string& item) {
    native::list_box::insert_item(this->control::data_->handle_, pos, item);
    if (this->data_->sorted_) std::sort(this->data_->items_.begin(), this->data_->items_.end());
    string selected_item;
    if (this->data_->selected_index_ != -1 && this->data_->selected_index_ < this->data_->items_.size()) selected_item = this->data_->items_[this->data_->selected_index_];
    this->selected_item(selected_item);
  };
  
  this->data_->items_.item_erased += [&](size_t pos, const std::string& item) {
    native::list_box::delete_item(this->control::data_->handle_, pos);

    string selected_item;
    if (this->data_->selected_index_ != -1 && this->data_->selected_index_ < this->data_->items_.size()) selected_item = this->data_->items_[this->data_->selected_index_];
    this->selected_item(selected_item);
  };
}

list_box& list_box::operator=(const list_box& value) {
  this->control::operator=(value);
  this->selected_index_changed = value.selected_index_changed;
  this->data_ = value.data_;
  return *this;
}

list_box& list_box::border_style(forms::border_style border_style) {
  if (this->data_->border_style_ != border_style) {
    this->data_->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

color list_box::default_back_color() const {
  return native::list_box::default_back_color();
}

color list_box::default_fore_color() const {
  return native::list_box::default_fore_color();
}

list_box& list_box::selected_index(size_t selected_index) {
  if (this->data_->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->data_->items_.size()) throw invalid_argument("out of range index");
    this->data_->selected_index_ = selected_index;
    native::list_box::selected_index(this->control::data_->handle_, this->data_->selected_index_);

    string selected_item;
    if (this->data_->selected_index_ != -1) selected_item = this->data_->items_[this->data_->selected_index_];
    this->selected_item(selected_item);

    this->on_selected_index_changed(event_args::empty);
  }
  return *this;
}

vector<size_t> list_box::selected_indices() const {
  return native::list_box::selected_indices(this->control::data_->handle_);
}

list_box& list_box::selected_item(const string& selected_item) {
  if (this->data_->selected_item_ != selected_item) {
    this->data_->selected_item_ = selected_item;
    auto it = std::find(this->data_->items_.begin(), this->data_->items_.end(), selected_item);
    size_t index = -1;
    if (it != this->data_->items_.end()) index = it - this->data_->items_.begin();
    this->selected_index(index);
    if (index == -1) this->data_->selected_item_= "";
    this->on_selected_value_changed(event_args::empty);
  }
  return *this;
}


vector<string> list_box::selected_items() const {
  vector<string> items;
  for (size_t index : this->selected_indices())
    items.push_back(this->data_->items_[index]);
  return items;
}

list_box& list_box::selection_mode(forms::selection_mode selection_mode) {
  if (this->data_->selection_mode_ != selection_mode) {
    this->data_->selection_mode_ = selection_mode;
    this->recreate_handle();
  }
  return *this;
}

list_box& list_box::sorted(bool sorted) {
  if (this->data_->sorted_ != sorted) {
    this->data_->sorted_ = sorted;
    if (this->data_->sorted_) std::sort(this->data_->items_.begin(), this->data_->items_.end());
    this->recreate_handle();
  }
  return *this;
}

forms::create_params list_box::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("listbox");
  create_params.style(create_params.style() | LBS_HASSTRINGS);

  switch (this->data_->selection_mode_) {
    case selection_mode::none: create_params.style(create_params.style() | LBS_NOSEL); break;
    case selection_mode::one:  break;
    case selection_mode::multi_simple: create_params.style(create_params.style() | LBS_MULTIPLESEL); break;
    case selection_mode::multi_extended: create_params.style(create_params.style() | LBS_MULTIPLESEL | LBS_EXTENDEDSEL); break;
    default: break;
  }

  if (this->data_->sorted_) create_params.style(create_params.style() | LBS_SORT);

  if (this->data_->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->data_->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  
  return create_params;
}

void list_box::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  for (size_t index = 0; index < this->data_->items_.size(); ++index)
    native::list_box::insert_item(this->control::data_->handle_, index, this->data_->items_[index]);
  if (this->data_->selection_mode_ == forms::selection_mode::none) this->selected_index(-1);
  native::list_box::selected_index(this->control::data_->handle_, this->data_->selected_index_);
  if (this->data_->selected_index_ != -1) this->data_->selected_item_ = this->data_->items_[this->data_->selected_index_];
}

void list_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
    case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
    default: this->control::wnd_proc(message);
  }
}

void list_box::wm_mouse_double_click(message &message) {
  if (this->selection_mode() != forms::selection_mode::none)
    this->control::wnd_proc(message);
}

void list_box::wm_mouse_down(message &message) {
  if (this->selection_mode() != forms::selection_mode::none)
    this->control::wnd_proc(message);
  else
    this->on_selected_index_changed(event_args::empty);
}

void list_box::wm_reflect_command(message &message) {
  this->def_wnd_proc(message);
  this->selected_index(native::list_box::selected_index(this->control::data_->handle_));
}
