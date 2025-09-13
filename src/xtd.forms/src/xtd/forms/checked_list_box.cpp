#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/checked_list_box.hpp"
#include <xtd/drawing/graphics>
#include <xtd/drawing/pens>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/checked_list_box>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/toolkit>
#include <xtd/forms/native/window_styles>
#include <xtd/forms/native/list_box_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception>
#include <xtd/literals/translator>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::helpers;

checked_list_box::item::item(const xtd::string& value) : list_box::item(value) {
}

checked_list_box::item::item(const xtd::string& value, bool checked) : list_box::item(value), check_state_(checked ? forms::check_state::checked : forms::check_state::unchecked) {
}

checked_list_box::item::item(const xtd::string& value, forms::check_state check_state) : list_box::item(value), check_state_(check_state) {
}

checked_list_box::item::item(const xtd::string& value, const any_object& tag) : list_box::item(value, tag) {
}

checked_list_box::item::item(const xtd::string& value, bool checked, const any_object& tag) : list_box::item(value, tag), check_state_(checked ? forms::check_state::checked : forms::check_state::unchecked) {
}

checked_list_box::item::item(const xtd::string& value, forms::check_state check_state, const any_object& tag) : list_box::item(value, tag), check_state_(check_state) {
}

checked_list_box::item::item(const char* value) : list_box::item(value) {
}

bool checked_list_box::item::checked() const {
  return check_state_ != forms::check_state::unchecked;
}

forms::check_state checked_list_box::item::check_state() const {
  return check_state_;
}

int32 checked_list_box::item::compare_to(const item& value) const noexcept {
  return list_box::item::compare_to(as<list_box::item>(value));
}

bool checked_list_box::item::equals(const item& value) const noexcept {
  return list_box::item::equals(as<list_box::item>(value));
}

struct checked_list_box::data {
  object_collection items;
  item selected_item;
};

checked_list_box::checked_list_box() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::resize_redraw, true);
  data_->items.item_added += {*this, &checked_list_box::on_items_item_added};
  data_->items.item_removed += {*this, &checked_list_box::on_items_item_removed};
  data_->items.item_updated += {*this, &checked_list_box::on_items_item_updated};
}

checked_list_box::checked_list_box(checked_list_box&& rhs) : list_box(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->items.item_added -= {rhs, &checked_list_box::on_items_item_added};
  data_->items.item_removed -= {rhs, &checked_list_box::on_items_item_removed};
  data_->items.item_updated -= {rhs, &checked_list_box::on_items_item_updated};
  data_->items.item_added += {*this, &checked_list_box::on_items_item_added};
  data_->items.item_removed += {*this, &checked_list_box::on_items_item_removed};
  data_->items.item_updated += {*this, &checked_list_box::on_items_item_updated};
}

checked_list_box::checked_index_collection checked_list_box::checked_indices() const noexcept {
  auto indices = checked_index_collection {};
  for (auto index = 0_z; index < data_->items.count(); ++index)
    if (data_->items[index].checked()) indices.add(index);
  return indices;
}

checked_list_box::checked_item_collection checked_list_box::checked_items() const noexcept {
  //return data_->items.find_all([](auto item) {return item.checked();});
  auto items = checked_item_collection {};
  for (const auto& item : data_->items)
    if (item.checked()) items.add(item);
  return items;
}

checked_list_box::object_collection& checked_list_box::items() noexcept {
  return data_->items;
}

const checked_list_box::object_collection& checked_list_box::items() const noexcept {
  return data_->items;
}

const list_box& checked_list_box::items(const object_collection& items) {
  data_->items = items;
  return *this;
}

list_control& checked_list_box::selected_index(size_t selected_index) {
  if (this->selected_index() == selected_index) return *this;
  if (selected_index != npos && selected_index >= data_->items.count()) throw_helper::throws(exception_case::argument_out_of_range, "Selected index greater than items size"_t);
  set_selected_index(selected_index);
  if (is_handle_created()) native::checked_list_box::selected_index(handle(), selected_index);
  
  auto selected = item {};
  if (this->selected_index() != npos) selected = data_->items[this->selected_index()];
  //this->selected_item(selected);
  data_->selected_item = selected;
  on_selected_value_changed(event_args::empty);
  
  on_selected_index_changed(event_args::empty);
  return *this;
}

checked_list_box::selected_index_collection checked_list_box::selected_indices() const noexcept {
  return is_handle_created() ? native::checked_list_box::selected_indices(handle()) : selected_index_collection {};
}

const checked_list_box::item& checked_list_box::selected_item() const noexcept {
  return data_->selected_item;
}

checked_list_box& checked_list_box::selected_item(const item& selected_item) {
  if (data_->selected_item == selected_item) return *this;
  auto it = std::find(data_->items.begin(), data_->items.end(), selected_item);
  if (it == data_->items.end())
    data_->selected_item = selected_index() != npos ? items()[selected_index()] : "";
  else {
    size_t index = it - data_->items.begin();
    selected_index(index);
    data_->selected_item = *it;
    on_selected_value_changed(event_args::empty);
  }
  return *this;
}

checked_list_box::selected_object_collection checked_list_box::selected_items() const noexcept {
  auto itms = selected_object_collection {};
  auto indices = selected_indices();
  std::for_each(indices.begin(), indices.end(), [&](size_t index) {itms.add(data_->items[index]);});
  return itms;
}

control& checked_list_box::text(const xtd::string& text) {
  data_->selected_item = {text};
  return *this;
}

void checked_list_box::begin_update() {
  if (is_handle_created()) native::checked_list_box::begin_update(handle());
}

checked_list_box checked_list_box::create() {
  return checked_list_box {};
}

checked_list_box checked_list_box::create(const drawing::point& location) {
  auto result = checked_list_box {};
  result.location(location);
  return result;
}

checked_list_box checked_list_box::create(const drawing::point& location, const drawing::size& size) {
  auto result = checked_list_box {};
  result.location(location);
  result.size(size);
  return result;
}

checked_list_box checked_list_box::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = checked_list_box {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items, const drawing::point& location) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  result.location(location);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items, const drawing::point& location, const drawing::size& size) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  result.location(location);
  result.size(size);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items, size_t selected_index) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  result.selected_index(selected_index);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items, size_t selected_index, const drawing::point& location) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  result.selected_index(selected_index);
  result.location(location);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  return result;
}

checked_list_box checked_list_box::create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = checked_list_box {};
  result.items().add_range(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

checked_list_box checked_list_box::create(const control& parent) {
  auto result = checked_list_box {};
  result.parent(parent);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const drawing::point& location) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.location(location);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items, const drawing::point& location) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  result.location(location);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  result.location(location);
  result.size(size);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items, size_t selected_index) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  result.selected_index(selected_index);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  result.selected_index(selected_index);
  result.location(location);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  return result;
}

checked_list_box checked_list_box::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = checked_list_box {};
  result.parent(parent);
  result.items().add_range(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void checked_list_box::end_update() {
  if (is_handle_created()) native::checked_list_box::end_update(handle());
}

bool checked_list_box::get_item_checked(size_t index) const {
  return items()[index].checked();
}

forms::check_state checked_list_box::get_item_check_state(size_t index) const {
  return items()[index].check_state();
}

const xtd::string& checked_list_box::get_item_text(size_t index) const {
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

void checked_list_box::set_item_text(size_t index, const xtd::string& text) {
  items()[index] = {text, items()[index].checked(), items()[index].tag()};
}

bool checked_list_box::allow_selection() const noexcept {
  return selection_mode() != forms::selection_mode::none;
}

forms::create_params checked_list_box::create_params() const noexcept {
  auto create_params = list_box::create_params();
  
  create_params.class_name("checkedlistbox");
  create_params.style(create_params.style() | LBS_HASSTRINGS);
  
  switch (selection_mode()) {
    case selection_mode::none: create_params.style(create_params.style() | LBS_NOSEL); break;
    case selection_mode::one:  break;
    case selection_mode::multi_simple: create_params.style(create_params.style() | LBS_MULTIPLESEL); break;
    case selection_mode::multi_extended: create_params.style(create_params.style() | LBS_MULTIPLESEL | LBS_EXTENDEDSEL); break;
    default: break;
  }
  
  // Do not use native control sort
  //if (sorted_) create_params.style(create_params.style() | LBS_SORT);
  
  return create_params;
}

xtd::uptr<xtd::object> checked_list_box::clone() const {
  auto result = xtd::new_uptr<checked_list_box>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

void checked_list_box::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  data_->items.sorted(sorted());
  for (auto index = 0_z; index < data_->items.count(); ++index)
    native::checked_list_box::insert_item(handle(), index, data_->items[index].value(), data_->items[index].checked());
  if (selection_mode() == forms::selection_mode::none) selected_index(npos);
  native::checked_list_box::selected_index(handle(), selected_index());
  if (selected_index() != npos) data_->selected_item = data_->items[selected_index()];
}

void checked_list_box::on_item_check(item_check_event_args& e) {
  item_check(*this, e);
}

void checked_list_box::on_selected_value_changed(const event_args& e) {
  list_box::text(data_->selected_item.value());
  list_box::on_selected_value_changed(e);
}

void checked_list_box::wnd_proc(message& message) {
  switch (message.msg) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: list_box::wnd_proc(message);
  }
}

void checked_list_box::on_items_item_added(size_t pos, const item& item) {
  if (is_handle_created()) native::checked_list_box::insert_item(handle(), pos, item.value(), static_cast<int32>(item.check_state()));
  checked_list_box::item selected;
  if (selected_index() != npos && selected_index() < data_->items.count()) selected = data_->items[selected_index()];
  this->selected_item(selected);
}

void checked_list_box::on_items_item_removed(size_t pos, const item& item)  {
  if (is_handle_created()) native::checked_list_box::delete_item(handle(), pos);
  if (selected_index() == pos) selected_index(npos);
}

void checked_list_box::on_items_item_updated(size_t pos, const item& item) {
  if (is_handle_created()) native::checked_list_box::update_item(handle(), pos, item.value(), static_cast<int32>(item.check_state()));
  checked_list_box::item selected;
  if (selected_index() != npos && selected_index() < data_->items.count()) selected = data_->items[selected_index()];
  this->selected_item(selected);
}

void checked_list_box::wm_mouse_double_click(message& message) {
  selected_index(native::checked_list_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void checked_list_box::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void checked_list_box::wm_mouse_up(message& message) {
  selected_index(native::checked_list_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void checked_list_box::wm_command_control(message& message) {
  def_wnd_proc(message);
  size_t selected = native::checked_list_box::selected_index(handle());
  if (selected != npos) {
    forms::check_state check_state = static_cast<forms::check_state>(native::checked_list_box::check_state(handle(), selected));
    if (data_->items[selected].check_state() != check_state) {
      item_check_event_args item_check_event_args(selected, check_state, data_->items[selected].check_state());
      on_item_check(item_check_event_args);
      if (item_check_event_args.new_value() != check_state) native::checked_list_box::check_state(handle(), selected, static_cast<int32>(item_check_event_args.new_value()));
      set_item_check_state(selected, item_check_event_args.new_value());
    }
  }
  this->selected_index(selected);
  if (this->selected_index() != npos) selected_item(data_->items[this->selected_index()]);
}
