#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/domain_up_down.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/up_down_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/domain_up_down.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

domain_up_down::domain_up_down() {
  control_appearance(forms::control_appearance::system);
  
  items_.item_added += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::domain_up_down::insert_item(handle(), pos, item.value());
    domain_up_down::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
  
  items_.item_removed += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::domain_up_down::delete_item(handle(), pos);
    
    domain_up_down::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
  
  items_.item_updated += [&](size_t pos, const item & item) {
    static bool update_disabled = false;
    if (update_disabled) return;
    if (is_handle_created()) native::domain_up_down::update_item(handle(), pos, item.value());
    domain_up_down::item selected_item;
    if (selected_index_ != npos && selected_index_ < items_.size()) selected_item = items_[selected_index_];
    this->selected_item(selected_item);
  };
}

domain_up_down& domain_up_down::selected_index(size_t selected_index) {
  if (selected_index != npos && selected_index >= items_.size()) argument_out_of_range_exception("Selected index greater than items size");
  if (selected_index_ != selected_index) {
    selected_index_ = selected_index;
    if (is_handle_created()) native::domain_up_down::selected_index(handle(), selected_index_);
    
    item selected_item;
    if (selected_index_ != npos) selected_item = items_[selected_index_];
    //this->selected_item(selected_item);
    selected_item_ = selected_item;
    
    on_text_changed(event_args::empty);
  }
  return *this;
}

domain_up_down& domain_up_down::selected_item(const item& selected_item) {
  if (selected_item_ != selected_item) {
    auto it = std::find(items_.begin(), items_.end(), selected_item);
    if (it == items_.end())
      selected_item_ = selected_index() != npos ? items()[selected_index()] : "";
    else {
      size_t index = it - items_.begin();
      selected_index(index);
      selected_item_ = *it;
      
    }
  }
  return *this;
}

domain_up_down& domain_up_down::wrap(bool value) {
  if (wrap_ != value) {
    wrap_ = value;
    post_recreate_handle();
  }
  return *this;
}

forms::create_params domain_up_down::create_params() const {
  forms::create_params create_params = up_down_base::create_params();
  
  create_params.class_name("domainupdown");
  
  if (wrap_) create_params.style(create_params.style() | UDS_WRAP);
  create_params.size(native::control::default_size(create_params.class_name()));
  
  return create_params;
}

drawing::color domain_up_down::default_back_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color domain_up_down::default_fore_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

void domain_up_down::on_handle_created(const event_args& e) {
  scrollable_control::on_handle_created(e);
  for (size_t index = 0; index < items_.size(); ++index)
    native::domain_up_down::insert_item(handle(), index, items_[index].value());
  native::domain_up_down::selected_index(handle(), selected_index_);
  if (selected_index_ != npos) selected_item_ = items_[selected_index_];
  else native::control::text(handle(), text());
}

void domain_up_down::on_text_changed(const event_args& e) {
  if (is_handle_created()) {
    set_text(native::control::text(handle()));
    if (selected_index_ != native::domain_up_down::selected_index(handle())) {
      selected_index_ = native::domain_up_down::selected_index(handle());
      if (selected_index_ == npos)
        selected_item_ = "";
      else
        selected_item_ = items_[selected_index_];
      on_selected_item_changed(event_args::empty);
    }
  }
  up_down_base::on_text_changed(e);
}

void domain_up_down::on_selected_item_changed(const event_args& e) {
  if (can_raise_events()) selected_item_changed(*this, e);
}
