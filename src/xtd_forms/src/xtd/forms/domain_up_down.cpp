#include <xtd/forms/native/control.h>
#include <xtd/forms/native/domain_up_down.h>
#include <xtd/forms/native/up_down_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/domain_up_down.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

domain_up_down::domain_up_down() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();

  this->items_.item_added += [&](size_t pos, const item& item) {
    native::domain_up_down::insert_item(handle(), pos, item.value());
    domain_up_down::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };

  this->items_.item_erased += [&](size_t pos, const item& item) {
    native::domain_up_down::delete_item(handle(), pos);

    domain_up_down::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
  
  this->items_.item_updated += [&](size_t pos, const item& item) {
    static bool update_disabled = false;
    if (update_disabled) return;
    native::domain_up_down::update_item(handle(), pos, item.value());
    domain_up_down::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
}

domain_up_down& domain_up_down::selected_index(size_t selected_index) {
  if (this->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->items_.size()) throw invalid_argument("out of range index");
    this->selected_index_ = selected_index;
    native::domain_up_down::selected_index(handle(), this->selected_index_);

    item selected_item;
    if (this->selected_index_ != -1) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);

    this->on_text_changed(event_args::empty);
  }
  return *this;
}

domain_up_down& domain_up_down::selected_item(const item& selected_item) {
  if (this->selected_item_ != selected_item) {
    auto it = std::find(this->items_.begin(), this->items_.end(), selected_item);
    if (it == this->items_.end())
      this->selected_item_ = this->selected_index() != -1 ? this->items()[this->selected_index()] : "";
    else {
      size_t index = it - this->items_.begin();
      this->selected_index(index);
      this->selected_item_ = selected_item;

    }
  }
  return *this;
}

domain_up_down& domain_up_down::wrapped(bool value) {
  if (this->wrapped_ != value) {
    this->wrapped_ = value;
    this->recreate_handle();
  }
  return *this;
}

forms::create_params domain_up_down::create_params() const {
  forms::create_params create_params = up_down_base::create_params();
  
  create_params.class_name("domainupdown");
  
  if (wrapped_) create_params.style(create_params.style() | UDS_WRAP);

  return create_params;
}

void domain_up_down::on_handle_created(const event_args &e) {
  this->scrollable_control::on_handle_created(e);
  for (size_t index = 0; index < this->items_.size(); ++index)
    native::domain_up_down::insert_item(handle(), index, this->items_[index].value());
  native::domain_up_down::selected_index(handle(), this->selected_index_);
  if (this->selected_index_ != -1) this->selected_item_ = this->items_[this->selected_index_];
  else native::control::text(handle(), text_);
}

void domain_up_down::on_text_changed(const event_args& e) {
  text_ = native::control::text(handle());
  if (selected_index_ != native::domain_up_down::selected_index(handle())) {
    selected_index_ = native::domain_up_down::selected_index(handle());
    if (selected_index_ == -1)
      selected_item_ = "";
    else
      selected_item_ = items_[selected_index_];
    on_selected_item_changed(event_args::empty);
  }
  up_down_base::on_text_changed(e);
}

void domain_up_down::on_selected_item_changed(const event_args& e) {
  if (this->can_raise_events()) selected_item_changed(*this, e);
}
