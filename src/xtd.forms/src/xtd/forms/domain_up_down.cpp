#include "../../../include/xtd/forms/domain_up_down.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/domain_up_down>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/up_down_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception>
#include <xtd/literals>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

domain_up_down::item::item(const xtd::string& value) : value_(value) {
}

domain_up_down::item::item(const xtd::string& value, const any_object& tag) : value_(value), tag_(tag) {
}

domain_up_down::item::item(const char* value) : value_(value) {
}

const xtd::string& domain_up_down::item::value() const noexcept {
  return value_;
}

const any_object& domain_up_down::item::tag() const noexcept {
  return tag_;
}

int32 domain_up_down::item::compare_to(const item& value) const noexcept {
  return value_ < value.value_ ? -1 : value_ > value.value_ ? 1 : 0;
}

bool domain_up_down::item::equals(const object& obj) const noexcept {
  return is<domain_up_down::item>(obj) && equals(static_cast<const domain_up_down::item&>(obj));
}

bool domain_up_down::item::equals(const item& other) const noexcept {
  return value_ == other.value_;
}

xtd::size domain_up_down::item::get_hash_code() const noexcept {
  return hash_code::combine(value_);
}

xtd::string domain_up_down::item::to_string() const noexcept {
  return value_;
}

struct domain_up_down::data {
  object_collection items;
  size_t selected_index = npos;
  item selected_item;
  bool wrap = false;
};

domain_up_down::domain_up_down() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);

  data_->items.item_added += {*this, &domain_up_down::on_items_item_added};
  data_->items.item_removed += {*this, &domain_up_down::on_items_item_removed};
  data_->items.item_updated += {*this, &domain_up_down::on_items_item_updated};
}

domain_up_down::domain_up_down(domain_up_down&& rhs) : up_down_base(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->items.item_added -= {rhs, &domain_up_down::on_items_item_added};
  data_->items.item_removed -= {rhs, &domain_up_down::on_items_item_removed};
  data_->items.item_updated -= {rhs, &domain_up_down::on_items_item_updated};
  data_->items.item_added += {*this, &domain_up_down::on_items_item_added};
  data_->items.item_removed += {*this, &domain_up_down::on_items_item_removed};
  data_->items.item_updated += {*this, &domain_up_down::on_items_item_updated};
}

domain_up_down::object_collection& domain_up_down::items() noexcept {
  return data_->items;
}

const domain_up_down::object_collection& domain_up_down::items() const noexcept {
  return data_->items;
}

const domain_up_down& domain_up_down::items(const object_collection& items) {
  data_->items = items;
  return *this;
}

size_t domain_up_down::selected_index() const noexcept {
  return data_->selected_index;
}

domain_up_down& domain_up_down::selected_index(size_t selected_index) {
  if (selected_index != npos && selected_index >= data_->items.size()) argument_out_of_range_exception("Selected index greater than items size");
  if (data_->selected_index == selected_index) return *this;
  data_->selected_index = selected_index;
  if (is_handle_created()) native::domain_up_down::selected_index(handle(), data_->selected_index);
  
  auto selected = item {};
  if (data_->selected_index != npos) selected = data_->items[data_->selected_index];
  //this->selected_item(selected);
  data_->selected_item = selected;
  
  on_text_changed(event_args::empty);
  return *this;
}

const domain_up_down::item& domain_up_down::selected_item() const noexcept {
  return data_->selected_item;
}

domain_up_down& domain_up_down::selected_item(const item& selected_item) {
  if (data_->selected_item == selected_item) return *this;
  auto it = std::find(data_->items.begin(), data_->items.end(), selected_item);
  if (it == data_->items.end())
    data_->selected_item = selected_index() != npos ? items()[selected_index()] : "";
  else {
    auto index = it - data_->items.begin();
    selected_index(index);
    data_->selected_item = *it;
  }
  return *this;
}

bool domain_up_down::wrap() const noexcept {
  return data_->wrap;
}

domain_up_down& domain_up_down::wrap(bool value) {
  if (data_->wrap == value) return *this;
  data_->wrap = value;
  post_recreate_handle();
  return *this;
}

domain_up_down domain_up_down::create() {
  return domain_up_down {};
}

domain_up_down domain_up_down::create(const drawing::point& location) {
  auto result = domain_up_down {};
  result.location(location);
  return result;
}

domain_up_down domain_up_down::create(const drawing::point& location, const drawing::size& size) {
  auto result = domain_up_down {};
  result.location(location);
  result.size(size);
  return result;
}

domain_up_down domain_up_down::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = domain_up_down {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

domain_up_down domain_up_down::create(const object_collection& items) {
  auto result = domain_up_down {};
  result.items(items);
  return result;
}

domain_up_down domain_up_down::create(const object_collection& items, const drawing::point& location) {
  auto result = domain_up_down {};
  result.items(items);
  result.location(location);
  return result;
}

domain_up_down domain_up_down::create(const object_collection& items, const drawing::point& location, const drawing::size& size) {
  auto result = domain_up_down {};
  result.items(items);
  result.location(location);
  result.size(size);
  return result;
}

domain_up_down domain_up_down::create(const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = domain_up_down {};
  result.items(items);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

domain_up_down domain_up_down::create(const object_collection& items, size_t selected_index) {
  auto result = domain_up_down {};
  result.items(items);
  result.selected_index(selected_index);
  return result;
}

domain_up_down domain_up_down::create(const object_collection& items, size_t selected_index, const drawing::point& location) {
  auto result = domain_up_down {};
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  return result;
}

domain_up_down domain_up_down::create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size) {
  auto result = domain_up_down {};
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
   return result;
}

domain_up_down domain_up_down::create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = domain_up_down {};
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

domain_up_down domain_up_down::create(const control& parent) {
  auto result = domain_up_down {};
  result.parent(parent);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const drawing::point& location) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.location(location);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items, const drawing::point& location) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  result.location(location);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  result.location(location);
  result.size(size);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items, size_t selected_index) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  return result;
}

domain_up_down domain_up_down::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = domain_up_down {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params domain_up_down::create_params() const noexcept {
  auto create_params = up_down_base::create_params();
  
  create_params.class_name("domainupdown");
  
  if (data_->wrap) create_params.style(create_params.style() | UDS_WRAP);
  create_params.size(native::control::default_size(create_params.class_name()));
  
  return create_params;
}

drawing::color domain_up_down::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color domain_up_down::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

xtd::uptr<xtd::object> domain_up_down::clone() const {
  auto result = xtd::new_uptr<domain_up_down>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

void domain_up_down::on_handle_created(const event_args& e) {
  scrollable_control::on_handle_created(e);
  for (auto index = 0_z; index < data_->items.size(); ++index)
    native::domain_up_down::insert_item(handle(), index, data_->items[index].value());
  native::domain_up_down::selected_index(handle(), data_->selected_index);
  if (data_->selected_index != npos) data_->selected_item = data_->items[data_->selected_index];
  else native::control::text(handle(), text());
}

void domain_up_down::on_lost_focus(const event_args& e) {
  up_down_base::on_lost_focus(e);
  selected_item(text());
}

void domain_up_down::on_text_changed(const event_args& e) {
  if (is_handle_created()) {
    set_text(native::control::text(handle()));
    if (data_->selected_index != native::domain_up_down::selected_index(handle())) {
      data_->selected_index = native::domain_up_down::selected_index(handle());
      if (data_->selected_index == npos)
        data_->selected_item = "";
      else
        data_->selected_item = data_->items[data_->selected_index];
      on_selected_item_changed(event_args::empty);
    }
  }
  up_down_base::on_text_changed(e);
}

void domain_up_down::on_selected_item_changed(const event_args& e) {
  if (can_raise_events()) selected_item_changed(*this, e);
}

void domain_up_down::wnd_proc(message& message) {
  switch (message.msg) {
    case WM_REFLECT + WM_VSCROLL: wm_scroll_control(message); break;
    default: up_down_base::wnd_proc(message);
  }
}

void domain_up_down::wm_scroll_control(message& message) {
  def_wnd_proc(message);
  if (data_->selected_index != native::domain_up_down::selected_index(handle())) {
    data_->selected_index = native::domain_up_down::selected_index(handle());
    on_selected_item_changed(event_args::empty);
  }
}

void domain_up_down::on_items_item_added(size_t pos, const item& item) {
  if (is_handle_created()) native::domain_up_down::insert_item(handle(), pos, item.value());
  auto selected = domain_up_down::item {};
  if (data_->selected_index != npos && data_->selected_index < data_->items.size()) selected = data_->items[data_->selected_index];
  this->selected_item(selected);
}

void domain_up_down::on_items_item_removed(size_t pos, const item& item) {
  if (is_handle_created()) native::domain_up_down::delete_item(handle(), pos);
  if (selected_index() == pos) selected_index(npos);
}

void domain_up_down::on_items_item_updated(size_t pos, const item& item) {
  static auto update_disabled = false;
  if (update_disabled) return;
  if (is_handle_created()) native::domain_up_down::update_item(handle(), pos, item.value());
  auto selected = domain_up_down::item {};
  if (data_->selected_index != npos && data_->selected_index < data_->items.size()) selected = data_->items[data_->selected_index];
  this->selected_item(selected);
}
