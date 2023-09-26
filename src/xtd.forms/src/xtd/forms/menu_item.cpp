#include "../../../include/xtd/forms/menu_item"
#include "menu_data.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu>
#include <xtd/forms/native/menu_item>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/not_implemented_exception>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct menu_item::data {
  xtd::ustring text;
  xtd::drawing::image image = xtd::drawing::image::empty;
  xtd::forms::menu_item_kind kind = xtd::forms::menu_item_kind::normal;
  bool checked = false;
  xtd::forms::shortcut shortcut = xtd::forms::shortcut::none;
  bool enabled = true;
  bool is_parent = false;
};

menu_item::menu_item() : data_(std::make_shared<data>()) {
}

menu_item::menu_item(const xtd::ustring& text) : data_(std::make_shared<data>()) {
  data_->text = text;
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->shortcut = shortcut;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->shortcut = shortcut;
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
  data_->shortcut = shortcut;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
  data_->shortcut = shortcut;
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, bool checked) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
  data_->checked = checked;
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
  data_->checked = checked;
  data_->shortcut = shortcut;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
  data_->checked = checked;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
  data_->checked = checked;
  data_->shortcut = shortcut;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click) : data_(std::make_shared<data>()) {
  data_->text = text;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->shortcut = shortcut;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->shortcut = shortcut;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind) : menu(menu::menu_item_collection {}), data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
  data_->shortcut = shortcut;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
  data_->shortcut = shortcut;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, bool checked) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
  data_->checked = checked;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->kind = kind;
  data_->checked = checked;
  data_->shortcut = shortcut;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
  data_->checked = checked;
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : data_(std::make_shared<data>()) {
  data_->text = text;
  data_->image = image;
  data_->kind = kind;
  data_->checked = checked;
  data_->shortcut = shortcut;
  click += on_click;
  create_menu();
}

menu_item::menu_item(const xtd::ustring& text, const std::vector<menu_item_ref>& items) : data_(std::make_shared<data>()) {
  data_->is_parent = true;
  data_->text = text;
  create_menu();
  menu::data_->menu_items.push_back_range(items);
}

menu_item::menu_item(const xtd::ustring& text, const std::initializer_list<const_menu_item_ref>& items) : data_(std::make_shared<data>()) {
  data_->is_parent = true;
  data_->text = text;
  create_menu();
  for (auto& item : items)
    menu::data_->menu_items.push_back(menu_item_ref(const_cast<menu_item&>(item.get())));
}

bool menu_item::checked() const noexcept {
  return data_->checked;
}

menu_item& menu_item::checked(bool value) {
  if (data_->checked != value) {
    data_->checked = value;
    if (handle()) native::menu_item::checked(handle(), data_->checked);
  }
  return *this;
}

bool menu_item::enabled() const noexcept {
  return data_->enabled;
}

menu_item& menu_item::enabled(bool value) {
  if (data_->enabled != value) {
    data_->enabled = value;
    if (handle()) native::menu_item::enabled(handle(), data_->enabled);
  }
  return *this;
}

bool menu_item::is_parent() const noexcept {
  return data_->is_parent || menu::is_parent();
}

xtd::forms::menu_item_kind menu_item::kind() const noexcept {
  return data_->kind;
}

menu_item& menu_item::kind(xtd::forms::menu_item_kind value) {
  if (data_->kind != value) {
    data_->kind = value;
    throw not_implemented_exception {csf_};
    //recreate_menu();
  }
  return *this;
}

xtd::forms::shortcut menu_item::shortcut() const noexcept {
  return data_->shortcut;
}

menu_item& menu_item::shortcut(xtd::forms::shortcut value) {
  if (data_->shortcut != value) {
    data_->shortcut = value;
    recreate_menu();
    if (handle()) native::menu_item::text(handle(), data_->text, static_cast<size_t>(data_->shortcut));
  }
  return *this;
}

const xtd::ustring& menu_item::text() const noexcept {
  return data_->text;
}

menu_item& menu_item::text(const xtd::ustring& value) {
  if (data_->text != value) {
    data_->text = value;
    if (handle() && (is_parent() || menu::data_->main_menu.has_value() || menu::data_->context_menu.has_value())) native::menu::text(handle(), data_->text);
    else if (handle()) native::menu_item::text(handle(), data_->text, static_cast<size_t>(data_->shortcut));
  }
  return *this;
}

intptr menu_item::create_menu_handle() {
  if (is_parent() || menu::data_->main_menu.has_value()) return native::menu::create();
  
  if (data_->text == "-") data_->kind = xtd::forms::menu_item_kind::separator;
  auto handle = native::menu_item::create(menu::data_->parent.value().get().handle(), data_->text, data_->image, static_cast<int32>(data_->kind), static_cast<size_t>(data_->shortcut));
  handles_.insert({native::menu_item::menu_id(handle), reference_wrapper<menu>(*this)});
  return handle;
}

void menu_item::destroy_menu_handle(intptr handle) {
  if (!handle) return;
  if (is_parent()) return native::menu::destroy(menu::data_->handle);
  handles_.erase(native::menu_item::menu_id(handle));
  native::menu_item::destroy(handle);
}

intptr menu_item::menu_id() const noexcept {
  return native::menu_item::menu_id(menu::data_->handle);
}

void menu_item::on_click(const event_args& e) {
  click(*this, e);
}

void menu_item::on_item_added(size_t pos, menu_item_ref item) {
  menu::on_item_added(pos, item);
  item.get().menu::data_->context_menu = menu::data_->context_menu;
  item.get().menu::data_->main_menu = menu::data_->main_menu;
  item.get().menu::data_->parent = *this;
  if (!item.get().handle()) item.get().create_menu();
  if (item.get().is_parent() || item.get().menu::data_->main_menu.has_value()) native::menu::insert_menu(handle(), pos, item.get().handle(), item.get().text());
  else {
    native::menu::insert_item(handle(), pos, item.get().handle());
    native::menu_item::enabled(item.get().handle(), item.get().enabled());
    if (item.get().kind() == menu_item_kind::check || item.get().kind() == menu_item_kind::radio) native::menu_item::checked(item.get().handle(), item.get().checked());
  }
}

void menu_item::on_item_removed(size_t pos, menu_item_ref item) {
  menu::on_item_removed(pos, item);
  item.get().menu::data_->parent.reset();
  native::menu::remove_item(handle(), pos);
}

void menu_item::perform_click() {
  on_click(event_args::empty);
}

ustring menu_item::to_string() const noexcept {
  return ustring::format("{}, text: {}", menu::to_string(), data_->text);
}
