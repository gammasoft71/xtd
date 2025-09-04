#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/list_box.hpp"
#include <xtd/drawing/pens>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/list_box>
#include <xtd/forms/native/toolkit>
#include <xtd/forms/native/window_styles>
#include <xtd/forms/native/list_box_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_out_of_range_exception>
#include <xtd/literals/translator>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::helpers;

struct list_box::data {
  forms::border_sides border_sides = forms::border_sides::all;
  std::optional<forms::border_style> border_style;
  object_collection items;
  item selected_item;
  forms::selection_mode selection_mode = forms::selection_mode::one;
  bool sorted = false;
};

list_box::list_box() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint | control_styles::standard_click | control_styles::use_text_for_accessibility, false);
  data_->items.item_added += {*this, &list_box::on_items_item_added};
  data_->items.item_removed += {*this, &list_box::on_items_item_removed};
  data_->items.item_updated += {*this, &list_box::on_items_item_updated};
}

list_box::list_box(list_box&& rhs) : list_control(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->items.item_added -= {rhs, &list_box::on_items_item_added};
  data_->items.item_removed -= {rhs, &list_box::on_items_item_removed};
  data_->items.item_updated -= {rhs, &list_box::on_items_item_updated};
  data_->items.item_added += {*this, &list_box::on_items_item_added};
  data_->items.item_removed += {*this, &list_box::on_items_item_removed};
  data_->items.item_updated += {*this, &list_box::on_items_item_updated};
}

forms::border_sides list_box::border_sides() const noexcept {
  return data_->border_sides;
}

list_box& list_box::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
  return *this;
}

forms::border_style list_box::border_style() const noexcept {
  return data_->border_style.value_or(forms::border_style::fixed_single);
}

list_box& list_box::border_style(forms::border_style border_style) {
  if (this->border_style() == border_style) return *this;
  data_->border_style = border_style;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

list_box& list_box::border_style(std::nullptr_t) {
  if (!data_->border_style) return *this;
  data_->border_style.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

list_box::object_collection& list_box::items() noexcept {
  return data_->items;
}

const list_box::object_collection& list_box::items() const noexcept {
  return data_->items;
}

const list_box& list_box::items(const object_collection& items) {
  data_->items = items;
  return *this;
}

list_control& list_box::selected_index(size_t selected_index) {
  if (selected_index != npos && selected_index >= data_->items.count()) throw_helper::throws(exception_case::argument_out_of_range, "Selected index greater than items size"_t);
  if (this->selected_index() == selected_index) return *this;
  set_selected_index(selected_index);
  if (is_handle_created()) native::list_box::selected_index(handle(), this->selected_index());
  
  auto selected = item {};
  if (this->selected_index() != npos) selected = data_->items[this->selected_index()];
  //this->selected_item(selected);
  data_->selected_item = selected;
  on_selected_value_changed(event_args::empty);
  
  on_selected_index_changed(event_args::empty);
  return *this;
}

array<xtd::size> list_box::selected_indices() const noexcept {
  return is_handle_created() ? native::list_box::selected_indices(handle()) : xtd::array<xtd::size> {};
}

list_box& list_box::selected_item(const item& selected_item) {
  if (data_->selected_item == selected_item) return *this;
  auto it = std::find(data_->items.begin(), data_->items.end(), selected_item);
  if (it == data_->items.end()) {
    if (selected_index() == npos || items().count() == 0) data_->selected_item = "";
    else {
      if (selected_index() >= items().count()) data_->selected_item = items()[items().count() - 1];
      else data_->selected_item = items()[selected_index()];
    }
  } else {
    auto index = it - data_->items.begin();
    selected_index(index);
    data_->selected_item = *it;
    on_selected_value_changed(event_args::empty);
  }
  return *this;
}

const list_box::item& list_box::selected_item() const noexcept {
  return data_->selected_item;
}

array<list_box::item> list_box::selected_items() const noexcept {
  auto itms = list<item> {};
  auto indices = selected_indices();
  std::for_each(indices.begin(), indices.end(), [&](size_t index) {itms.add(data_->items[index]);});
  return itms.to_array();
}

forms::selection_mode list_box::selection_mode() const noexcept {
  return data_->selection_mode;
}

list_box& list_box::selection_mode(forms::selection_mode selection_mode) {
  if (data_->selection_mode == selection_mode) return *this;
  data_->selection_mode = selection_mode;
  post_recreate_handle();
  return *this;
}

bool list_box::sorted() const noexcept {
  return data_->sorted;
}

list_box& list_box::sorted(bool sorted) {
  if (data_->sorted == sorted) return *this;
  data_->sorted = sorted;
  data_->items.sorted(data_->sorted);
  return *this;
}

control& list_box::text(const xtd::string& text) {
  return *this;
}

void list_box::begin_update() {
  if (is_handle_created()) native::list_box::begin_update(handle());
}

list_box list_box::create() {
  return list_box {};
}

list_box list_box::create(const drawing::point& location) {
  auto result = list_box {};
  result.location(location);
  return result;
}

list_box list_box::create(const drawing::point& location, const drawing::size& size) {
  auto result = list_box {};
  result.location(location);
  result.size(size);
  return result;
}

list_box list_box::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = list_box {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

list_box list_box::create(const object_collection& items) {
  auto result = list_box {};
  result.items(items);
  return result;
}

list_box list_box::create(const object_collection& items, const drawing::point& location) {
  auto result = list_box {};
  result.items(items);
  result.location(location);
  return result;
}

list_box list_box::create(const object_collection& items, const drawing::point& location, const drawing::size& size) {
  auto result = list_box {};
  result.items(items);
  result.location(location);
  result.size(size);
  return result;
}

list_box list_box::create(const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = list_box {};
  result.items(items);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

list_box list_box::create(const object_collection& items, size_t selected_index) {
  auto result = list_box {};
  result.items(items);
  result.selected_index(selected_index);
  return result;
}

list_box list_box::create(const object_collection& items, size_t selected_index, const drawing::point& location) {
  auto result = list_box {};
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  return result;
}

list_box list_box::create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size) {
  auto result = list_box {};
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  return result;
}

list_box list_box::create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = list_box {};
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

list_box list_box::create(const control& parent) {
  auto result = list_box {};
  result.parent(parent);
  return result;
}

list_box list_box::create(const control& parent, const drawing::point& location) {
  auto result = list_box {};
  result.parent(parent);
  result.location(location);
  return result;
}

list_box list_box::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = list_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

list_box list_box::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = list_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items, const drawing::point& location) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  result.location(location);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  result.location(location);
  result.size(size);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items, size_t selected_index) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  return result;
}

list_box list_box::create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = list_box {};
  result.parent(parent);
  result.items(items);
  result.selected_index(selected_index);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void list_box::end_update() {
  if (is_handle_created()) native::list_box::end_update(handle());
}

drawing::color list_box::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color list_box::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

bool list_box::allow_selection() const noexcept {
  return data_->selection_mode != forms::selection_mode::none;
}

forms::create_params list_box::create_params() const noexcept {
  auto create_params = list_control::create_params();
  
  create_params.class_name("listbox");
  create_params.style(create_params.style() | LBS_HASSTRINGS);
  
  switch (data_->selection_mode) {
    case selection_mode::none: create_params.style(create_params.style() | LBS_NOSEL); break;
    case selection_mode::one:  break;
    case selection_mode::multi_simple: create_params.style(create_params.style() | LBS_MULTIPLESEL); break;
    case selection_mode::multi_extended: create_params.style(create_params.style() | LBS_MULTIPLESEL | LBS_EXTENDEDSEL); break;
    default: break;
  }
  
  // Do not use native control sort
  //if (data_->sorted) create_params.style(create_params.style() | LBS_SORT);
  
  if (control_appearance() == forms::control_appearance::system) {
    if (border_style() == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style() != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  return create_params;
}

xtd::uptr<xtd::object> list_box::clone() const {
  auto result = xtd::new_uptr<list_box>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

void list_box::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);
  data_->items.sorted(data_->sorted);
  for (auto index = 0_z; index < data_->items.count(); ++index)
    native::list_box::insert_item(handle(), index, data_->items[index].value());
  if (data_->selection_mode == forms::selection_mode::none) selected_index(npos);
  native::list_box::selected_index(handle(), selected_index());
  if (selected_index() != npos) data_->selected_item = data_->items[selected_index()];
}

void list_box::on_selected_value_changed(const event_args& e) {
  list_control::text(data_->selected_item.value());
  list_control::on_selected_value_changed(e);
}


void list_box::wnd_proc(message& message) {
  switch (message.msg) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: list_control::wnd_proc(message);
  }
}

void list_box::on_items_item_added(size_t pos, const item& item) {
  if (is_handle_created()) native::list_box::insert_item(handle(), pos, item.value());
  auto selected = list_box::item {};
  if (selected_index() != npos && selected_index() < data_->items.count()) selected = data_->items[selected_index()];
  this->selected_item(selected);
}

void list_box::on_items_item_removed(size_t pos, const item& item)   {
  if (is_handle_created()) native::list_box::delete_item(handle(), pos);
  if (selected_index() == pos) selected_index(npos);
}

void list_box::on_items_item_updated(size_t pos, const item& item)   {
  if (is_handle_created()) native::list_box::update_item(handle(), pos, item.value());
  auto selected = list_box::item {};
  if (selected_index() != npos && selected_index() < data_->items.count()) selected = data_->items[selected_index()];
  this->selected_item(selected);
}

void list_box::wm_mouse_double_click(message& message) {
  selected_index(native::list_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_mouse_up(message& message) {
  selected_index(native::list_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void list_box::wm_command_control(message& message) {
  def_wnd_proc(message);
  if (HIWORD(message.wparam) == LBN_SELCHANGE) {
    selected_index(native::list_box::selected_index(handle()));
    if (selected_index() != npos) selected_item(data_->items[selected_index()]);
    on_click(event_args::empty);
  }
}
