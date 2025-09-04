#include "../../../include/xtd/forms/tab_control.hpp"
#include "../../../include/xtd/forms/tab_page.hpp"
#include "tab_control_data.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/tab_control>
#include <xtd/forms/native/tab_page>
#include <xtd/forms/native/tab_control_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/environment>
#include <xtd/is>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

tab_control::tab_page_collection::tab_page_collection(const tab_control::tab_page_collection::allocator_type& allocator) : tab_control::tab_page_collection::base(allocator) {
}

tab_control::tab_page_collection::tab_page_collection(const tab_control::tab_page_collection::base& collection) : tab_control::tab_page_collection::base(collection) {}
tab_control::tab_page_collection::tab_page_collection(const tab_control::tab_page_collection& collection) : tab_control::tab_page_collection::base(collection) {}
tab_control::tab_page_collection& tab_control::tab_page_collection::operator =(const tab_control::tab_page_collection& collection) {
  base::operator =(collection);
  return *this;
}

void tab_control::tab_page_collection::add(const xtd::string& text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::add(const xtd::string& text, const string& name) {
  text_added(npos, text, name);
}

void tab_control::tab_page_collection::add(const char* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::add(const char8* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::add(const char16* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::add(const char32* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::add(const wchar* text) {
  add(text, string::empty_string);
}

tab_control::tab_page_collection::iterator tab_control::tab_page_collection::insert(const_iterator pos, const xtd::string& text) {
  return insert(pos, text, string::empty_string);
}

tab_control::tab_page_collection::iterator tab_control::tab_page_collection::insert(const_iterator pos, const xtd::string& text, const xtd::string& name) {
  return text_inserted(pos, text, name);
}

void tab_control::tab_page_collection::insert_at(size_t index, const xtd::string& text) {
  return insert_at(index, text, string::empty_string);
}

void tab_control::tab_page_collection::insert_at(size_t index, const xtd::string& text, const xtd::string& name) {
  text_added(index, text, name);
}

void tab_control::tab_page_collection::push_back(const xtd::string& text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::push_back(const xtd::string& text, const string& name) {
  text_added(npos, text, name);
}

void tab_control::tab_page_collection::push_back(const char* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::push_back(const char8* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::push_back(const char16* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::push_back(const char32* text) {
  add(text, string::empty_string);
}

void tab_control::tab_page_collection::push_back(const wchar* text) {
  add(text, string::empty_string);
}

std::optional<tab_control::tab_page_collection::value_type> tab_control::tab_page_collection::operator [](const string& name) const {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

std::optional<tab_control::tab_page_collection::value_type> tab_control::tab_page_collection::operator [](const string& name) {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

tab_control::tab_control() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint, false);
  
  data_->tab_pages.item_added += {*this, &tab_control::on_tab_pages_item_added};
  data_->tab_pages.item_removed += {*this, &tab_control::on_tab_pages_item_removed};
  data_->tab_pages.text_added += {*this, &tab_control::on_tab_pages_text_added};
}

tab_control::tab_control(tab_control&& rhs) : control(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->tab_pages.item_added -= {rhs, &tab_control::on_tab_pages_item_added};
  data_->tab_pages.item_removed -= {rhs, &tab_control::on_tab_pages_item_removed};
  data_->tab_pages.text_added -= {rhs, &tab_control::on_tab_pages_text_added};
  data_->tab_pages.item_added += {*this, &tab_control::on_tab_pages_item_added};
  data_->tab_pages.item_removed += {*this, &tab_control::on_tab_pages_item_removed};
  data_->tab_pages.text_added += {*this, &tab_control::on_tab_pages_text_added};
}

tab_alignment tab_control::alignment() const noexcept {
  return data_->alignment;
}

tab_control& tab_control::alignment(tab_alignment alignment) {
  if (data_->alignment == alignment) return *this;
  data_->alignment = alignment;
  post_recreate_handle();
  return *this;
}

const forms::image_list& tab_control::image_list() const noexcept {
  return data_->image_list;
}

tab_control& tab_control::image_list(const forms::image_list& value) {
  if (data_->image_list == value) return *this;
  data_->image_list = value;
  post_recreate_handle();
  return *this;
}

size_t tab_control::selected_index() const noexcept {
  return data_->selected_index;
}

tab_control& tab_control::selected_index(size_t selected_index) {
  if (data_->selected_index == selected_index) return *this;
  if (selected_index >= tab_pages().count()) throw_helper::throws(exception_case::argument_out_of_range);
  data_->selected_index = selected_index;
  if (is_handle_created()) native::tab_control::selected_index(handle(), data_->selected_index);
  on_selected_index_changed(event_args::empty);
  return *this;
}

tab_control::tab_page_collection& tab_control::tab_pages() noexcept {
  return data_->tab_pages;
}

const tab_control::tab_page_collection& tab_control::tab_pages() const noexcept {
  return data_->tab_pages;
}

tab_control tab_control::create() {
  return tab_control {};
}

tab_control tab_control::create(const drawing::point& location) {
  auto result = tab_control {};
  result.location(location);
  return result;
}

tab_control tab_control::create(const drawing::point& location, const drawing::size& size) {
  auto result = tab_control {};
  result.location(location);
  result.size(size);
  return result;
}

tab_control tab_control::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = tab_control {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

tab_control tab_control::create(const control& parent) {
  auto result = tab_control {};
  result.parent(parent);
  return result;
}

tab_control tab_control::create(const control& parent, const drawing::point& location) {
  auto result = tab_control {};
  result.parent(parent);
  result.location(location);
  return result;
}

tab_control tab_control::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = tab_control {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

tab_control tab_control::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = tab_control {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params tab_control::create_params() const noexcept {
  auto create_params = control::create_params();
  
  create_params.class_name("tabcontrol");
  
  switch (data_->alignment) {
    case tab_alignment::bottom: create_params.style(create_params.style() | TCS_BOTTOM); break;
    case tab_alignment::left: create_params.style(create_params.style() | TCS_VERTICAL); break;
    case tab_alignment::right: create_params.style(create_params.style() | TCS_VERTICAL | TCS_RIGHT); break;
    default: break;
  }
  
  return create_params;
}

xtd::uptr<xtd::object> tab_control::clone() const {
  auto result = xtd::new_uptr<tab_control>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

drawing::size tab_control::measure_control() const noexcept {
  auto bounds = drawing::rectangle {};
  for (auto item : controls())
    if (item.get().visible()) bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}

void tab_control::on_control_added(const control_event_args& e) {
  if (!is<xtd::forms::tab_page>(e.control())) throw_helper::throws(exception_case::argument, string::format("Cannot add '{}' to tab_control.  Only tab_pages can be directly added to tab_controls.", e.control().get_type().name()).c_str());
  control::on_control_added(e);
  if (data_->selected_index == npos) data_->selected_index = 0;
}

void tab_control::on_control_removed(const control_event_args& e) {
  control::on_control_removed(e);
  if (controls().count() == 0) data_->selected_index = npos;
}

void tab_control::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::tab_control::image_list(handle(), data_->image_list.handle());
  
  for (auto& control : controls())
    native::tab_page::image_index(as<tab_page>(control.get()).handle(), as<tab_page>(control.get()).image_index());
}

void tab_control::on_selected_index_changed(const event_args& e) {
  selected_index_changed(*this, e);
}

void tab_control::wnd_proc(message& message) {
  switch (message.msg) {
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: control::wnd_proc(message);
  }
}

size_t tab_control::get_child_index(intptr page) {
  for (auto index = 0_z; index < controls().count(); ++index)
    if (controls()[index].get().handle() == page) return index;
  return npos;
}

void tab_control::on_tab_pages_item_added(size_t index, tab_page_ref& item) {
  controls().insert(index, item.get());
}

void tab_control::on_tab_pages_item_removed(size_t index, tab_page_ref& item) {
  controls().remove_at(index);
}

void tab_control::on_tab_pages_text_added(size_t index, const string& text, const string& name) {
  auto item = xtd::new_sptr<tab_page>();
  item->text(text);
  item->name(name);
  if (index == tab_pages().npos) {
    tab_pages().add(*item);
    data_->text_tab_pages.add(item);
  } else {
    tab_pages().insert(index, *item);
    data_->text_tab_pages.insert(index, item);
  }
}

void tab_control::on_tab_pages_text_inserted(xtd::size pos, const string& text, const string& name) {
  auto item = xtd::new_sptr<tab_page>();
  item->text(text);
  item->name(name);
  tab_pages().insert(pos, *item);
  if (pos == tab_pages().npos) data_->text_tab_pages.add(item);
  else data_->text_tab_pages.insert(pos, item);
}

void tab_control::wm_command_control(message& message) {
  def_wnd_proc(message);
  selected_index(native::tab_control::selected_index(handle()));
}
