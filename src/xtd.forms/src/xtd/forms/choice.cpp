#include "../../../include/xtd/forms/choice.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/choice>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception>
#include <xtd/literals>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct choice::data {
  object_collection items;
  item selected_item;
  bool sorted = false;
};

choice::choice() : data_(std::make_shared<data>()) {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint | control_styles::use_text_for_accessibility | control_styles::standard_click, false);
  data_->items.item_added += {*this, &choice::on_items_item_added};
  data_->items.item_removed += {*this, &choice::on_items_item_removed};
  data_->items.item_updated += {*this, &choice::on_items_item_updated};
}

choice::object_collection& choice::items() noexcept {
  return data_->items;
}

const choice::object_collection& choice::items() const noexcept {
  return data_->items;
}

const choice& choice::items(const object_collection& items) {
  data_->items = items;
  return *this;
}

list_control& choice::selected_index(size_t selected_index) {
  if (this->selected_index() == selected_index) return *this;
  if (selected_index != npos && selected_index >= data_->items.size()) throw argument_out_of_range_exception("Selected index greater than items size"_t, csf_);
  set_selected_index(selected_index);
  if (is_handle_created()) native::choice::selected_index(handle(), this->selected_index());
  
  item selected;
  if (this->selected_index() != npos) selected = data_->items[this->selected_index()];
  //this->selected_item(selected);
  data_->selected_item = selected;
  on_selected_value_changed(event_args::empty);
  
  on_selected_index_changed(event_args::empty);
  return *this;
}

const choice::item& choice::selected_item() const noexcept {
  return data_->selected_item;
}

choice& choice::selected_item(const item& selected_item) {
  if (data_->selected_item == selected_item) return *this;
  auto it = std::find(data_->items.begin(), data_->items.end(), selected_item);
  if (it == data_->items.end())
    data_->selected_item = selected_index() != npos ? items()[selected_index()] : item {""};
  else {
    size_t index = it - data_->items.begin();
    selected_index(index);
    data_->selected_item = *it;
    on_selected_value_changed(event_args::empty);
  }
  return *this;
}

bool choice::sorted() const noexcept {
  return data_->sorted;
}

choice& choice::sorted(bool sorted) {
  if (data_->sorted == sorted) return *this;
  data_->sorted = sorted;
  data_->items.sorted(data_->sorted);
  return *this;
}

control& choice::text(const xtd::ustring& text) {
  return *this;
}

void choice::begin_update() {
  if (is_handle_created()) native::choice::begin_update(handle());
}

choice choice::create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = choice {};
  result.items(items);
  result.selected_index(selected_index);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

choice choice::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = choice {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

void choice::end_update() {
  if (is_handle_created()) native::choice::end_update(handle());
}

forms::create_params choice::create_params() const noexcept {
  auto create_params = list_control::create_params();
  
  create_params.class_name("choice");
  
  // Do not use native control sort
  //if (data_->sorted) create_params.style(create_params.style() | CBS_SORT);
  
  return create_params;
}

void choice::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  data_->items.sorted(data_->sorted);
  for (auto index = 0_sz; index < data_->items.size(); ++index)
    native::choice::insert_item(handle(), index, data_->items[index].value());
  native::choice::selected_index(handle(), selected_index());
  if (selected_index() != npos) data_->selected_item = data_->items[selected_index()];
}

void choice::on_selected_value_changed(const event_args& e) {
  list_control::text(data_->selected_item.value());
  list_control::on_selected_value_changed(e);
}

void choice::set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) {
  auto current_size = size();
  list_control::set_bounds_core(x, y, width, height, specified);
  if (size() != current_size)
    post_recreate_handle();
}

void choice::set_client_size_core(int32 width, int32 height) {
  auto current_size = size();
  list_control::set_client_size_core(width, height);
  if (size() != current_size)
    post_recreate_handle();
}

void choice::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: list_control::wnd_proc(message);
  }
}

void choice::on_items_item_added(size_t pos, const item& item) {
  if (is_handle_created()) native::choice::insert_item(handle(), pos, item.value());
  auto selected = npos;
  if (this->selected_index() != npos && this->selected_index() < data_->items.size()) selected = this->selected_index();
  this->selected_index(selected);
}

void choice::on_items_item_removed(size_t pos, const item& item)  {
  if (is_handle_created()) native::choice::delete_item(handle(), pos);
  if (selected_index() == pos) selected_index(npos);
}

void choice::on_items_item_updated(size_t pos, const item& item) {
  if (is_handle_created()) native::choice::update_item(handle(), pos, item.value());
  auto selected = npos;
  if (this->selected_index() != npos && this->selected_index() < data_->items.size()) selected = this->selected_index();
  this->selected_index(selected);
}

void choice::wm_command_control(message& message) {
  def_wnd_proc(message);
  if (HIWORD(message.wparam()) == LBN_SELCHANGE) {
    selected_index(native::choice::selected_index(handle()));
    if (selected_index() != npos) selected_item(data_->items[selected_index()]);
    on_click(event_args::empty);
  }
}

void choice::wm_mouse_double_click(message& message) {
  selected_index(native::choice::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void choice::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void choice::wm_mouse_up(message& message) {
  selected_index(native::choice::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}
