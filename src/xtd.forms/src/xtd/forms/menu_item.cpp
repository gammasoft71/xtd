#include <xtd/not_implemented_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu.h>
#include <xtd/forms/native/menu_item.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/menu_item.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

menu_item::menu_item() {
}

menu_item::menu_item(const xtd::ustring& text) : text_(text) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::shortcut shortcut) : text_(text), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image) : text_(text), image_(image)  {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : text_(text), image_(image), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind) : text_(text), kind_(kind) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : text_(text), image_(image), kind_(kind) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, bool checked) : text_(text), kind_(kind), checked_(checked) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), checked_(checked), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : text_(text), image_(image), kind_(kind), checked_(checked) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), checked_(checked), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click) : text_(text) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::shortcut shortcut) : text_(text), shortcut_(shortcut) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image) : text_(text), image_(image)  {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : text_(text), image_(image), shortcut_(shortcut) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind) : menu(menu::menu_item_collection {}), text_(text), kind_(kind) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), shortcut_(shortcut) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : text_(text), image_(image), kind_(kind) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), shortcut_(shortcut) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, bool checked) : text_(text), kind_(kind), checked_(checked) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), checked_(checked), shortcut_(shortcut) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : text_(text), image_(image), kind_(kind), checked_(checked) {
  click += on_click;
}

menu_item::menu_item(const xtd::ustring& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), checked_(checked), shortcut_(shortcut) {
  click += on_click;
  create_menu();
}

menu_item::menu_item(const xtd::ustring& text, const std::vector<menu_item_ref>& items) : text_(text) {
  is_parent_ = true;
  create_menu();
  data_->menu_items_.push_back_range(items);
}

menu_item::menu_item(const xtd::ustring& text, const std::initializer_list<const_menu_item_ref>& items) : text_(text) {
  is_parent_ = true;
  create_menu();
  for (auto& item : items)
    data_->menu_items_.push_back(menu_item_ref(const_cast<menu_item&>(item.get())));
}

bool menu_item::checked() const noexcept {
  return checked_;
}

menu_item& menu_item::checked(bool value) {
  if (checked_ != value) {
    checked_ = value;
    if (handle()) native::menu_item::checked(handle(), checked_);
  }
  return *this;
}

bool menu_item::enabled() const noexcept {
  return enabled_;
}

menu_item& menu_item::enabled(bool value) {
  if (enabled_ != value) {
    enabled_ = value;
    if (handle()) native::menu_item::enabled(handle(), enabled_);
  }
  return *this;
}

bool menu_item::is_parent() const noexcept {
  return is_parent_ || menu::is_parent();
}

xtd::forms::menu_item_kind menu_item::kind() const noexcept {
  return kind_;
}

menu_item& menu_item::kind(xtd::forms::menu_item_kind value) {
  if (kind_ != value) {
    kind_ = value;
    throw not_implemented_exception(csf_);
    //recreate_menu();
  }
  return *this;
}

xtd::forms::shortcut menu_item::shortcut() const noexcept {
  return shortcut_;
}

menu_item& menu_item::shortcut(xtd::forms::shortcut value) {
  if (shortcut_ != value) {
    shortcut_ = value;
    recreate_menu();
    if (handle()) native::menu_item::text(handle(), text_, static_cast<size_t>(shortcut_));
  }
  return *this;
}

const xtd::ustring& menu_item::text() const noexcept {
  return text_;
}

menu_item& menu_item::text(const xtd::ustring& value) {
  if (text_ != value) {
    text_ = value;
    if (handle() && (is_parent() || data_->main_menu_.has_value() || data_->context_menu_.has_value())) native::menu::text(handle(), text_);
    else if (handle()) native::menu_item::text(handle(), text_, static_cast<size_t>(shortcut_));
  }
  return *this;
}

intptr_t menu_item::create_menu_handle() {
  if (is_parent() || data_->main_menu_.has_value()) return native::menu::create();
  
  if (text_ == "-") kind_ = xtd::forms::menu_item_kind::separator;
  auto handle = native::menu_item::create(data_->parent_.value().get().handle(), text_, image_, static_cast<int>(kind_), static_cast<size_t>(shortcut_));
  handles_.insert({native::menu_item::menu_id(handle), reference_wrapper<menu>(*this)});
  return handle;
}

void menu_item::destroy_menu_handle(intptr_t handle) {
  if (!handle) return;
  if (is_parent()) return native::menu::destroy(data_->handle_);
  handles_.erase(native::menu_item::menu_id(handle));
  native::menu_item::destroy(handle);
}

intptr_t menu_item::menu_id() const noexcept {
  return native::menu_item::menu_id(data_->handle_);
}

void menu_item::on_click(const event_args& e) {
  click(*this, e);
}

void menu_item::on_item_added(size_t pos, menu_item_ref item) {
  menu::on_item_added(pos, item);
  item.get().data_->context_menu_ = data_->context_menu_;
  item.get().data_->main_menu_ = data_->main_menu_;
  item.get().data_->parent_ = *this;
  if (!item.get().handle()) item.get().create_menu();
  if (item.get().is_parent() || item.get().data_->main_menu_.has_value()) native::menu::insert_menu(handle(), pos, item.get().handle(), item.get().text());
  else {
    native::menu::insert_item(handle(), pos, item.get().handle());
    native::menu_item::enabled(item.get().handle(), item.get().enabled());
    if (item.get().kind() == menu_item_kind::check || item.get().kind() == menu_item_kind::radio) native::menu_item::checked(item.get().handle(), item.get().checked());
  }
}

void menu_item::on_item_removed(size_t pos, menu_item_ref item) {
  menu::on_item_removed(pos, item);
  item.get().data_->parent_.reset();
  native::menu::remove_item(handle(), pos);
}

void menu_item::perform_click() {
  on_click(event_args::empty);
}

ustring menu_item::to_string() const noexcept {
  return ustring::format("{}, text: {}", menu::to_string(), text_);
}
