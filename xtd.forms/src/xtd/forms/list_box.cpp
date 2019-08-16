#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/list_box.hpp>
#include "../../../include/xtd/forms/list_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

list_box::list_box() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->items_.item_added += [&](size_t pos, const std::string& item) {
    native::list_box::insert_item(this->handle_, pos, item);

    string selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
  
  this->items_.item_erased += [&](size_t pos, const std::string& item) {
    native::list_box::delete_item(this->handle_, pos);

    string selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
}

color list_box::default_back_color() const {
  return native::list_box::default_back_color();
}

color list_box::default_fore_color() const {
  return native::list_box::default_fore_color();
}

list_box& list_box::selected_index(size_t selected_index) {
  if (this->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->items_.size()) throw invalid_argument("out of range index");
    this->selected_index_ = selected_index;
    native::list_box::selected_index(this->handle_, this->selected_index_);

    string selected_item;
    if (this->selected_index_ != -1) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);

    this->on_selected_index_changed(event_args::empty);
  }
  return *this;
}

list_box& list_box::selected_item(const string& selected_item) {
  if (this->selected_item_ != selected_item) {
    this->selected_item_ = selected_item;
    auto it = std::find(this->items_.begin(), this->items_.end(), selected_item);
    size_t index = -1;
    if (it != this->items_.end()) index = it - this->items_.begin();
    this->selected_index(index);
    if (index == -1) this->selected_item_= "";
    this->control::text(this->selected_item_);
  }
  return *this;
}

control& list_box::text(const std::string& text) {
  return this->selected_item(text);
}

void list_box::create_handle() {
  this->handle_ = native::list_box::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
}

void list_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
    default: this->control::wnd_proc(message);
  }
}

void list_box::wm_reflect_command(message &message) {
  this->def_wnd_proc(message);
  this->selected_index(native::list_box::selected_index(this->handle_));
}
