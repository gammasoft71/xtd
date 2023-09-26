#include "../../../include/xtd/forms/menu_item"
#include "../../../include/xtd/forms/context_menu"
#include "../../../include/xtd/forms/control"
#include "../../../include/xtd/forms/menu_images"
#include "../../../include/xtd/forms/shortcut"
#include "../../../include/xtd/forms/system_texts"
#include "menu_data.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/context_menu>
#include <xtd/forms/native/control>
#include <xtd/forms/native/menu_item>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

context_menu::context_menu() {
  create_menu();
}

context_menu::context_menu(const std::initializer_list<const_menu_item_ref>& menu_items) {
  create_menu();
  for (auto& item : menu_items)
    data_->menu_items.push_back(menu_item_ref(const_cast<menu_item&>(item.get())));
}

context_menu::context_menu(const std::vector<menu_item_ref>& menu_items) {
  create_menu();
  data_->menu_items.push_back_range(menu_items);
}

context_menu::~context_menu() {
  if (data_.use_count() == 1) destroy_menu_handle(data_->handle);
}

void context_menu::show(const xtd::forms::control& control, const xtd::drawing::point& pos)  {
  control.show_context_menu(*this, pos);
}

intptr context_menu::create_menu_handle() {
  return native::context_menu::create();
}

void context_menu::destroy_menu_handle(intptr handle) {
  if (handle) native::context_menu::destroy(handle);
}

void context_menu::on_item_added(size_t pos, menu_item_ref item) {
  menu::on_item_added(pos, item);
  item.get().menu::data_->context_menu = *this;
  item.get().menu::data_->parent = *this;
  if (!item.get().handle()) item.get().create_menu();
  if (item.get().is_parent() || item.get().menu::data_->main_menu.has_value()) native::context_menu::insert_menu(handle(), pos, item.get().handle(), item.get().text());
  else {
    native::context_menu::insert_item(handle(), pos, item.get().handle());
    native::menu_item::enabled(item.get().handle(), item.get().enabled());
    if (item.get().kind() == menu_item_kind::check || item.get().kind() == menu_item_kind::radio) native::menu_item::checked(item.get().handle(), item.get().checked());
  }
}

void context_menu::on_item_removed(size_t pos, menu_item_ref item) {
  menu::on_item_removed(pos, item);
  item.get().menu::data_->parent.reset();
  native::context_menu::remove_item(handle(), pos);
}

bool context_menu::on_item_click(intptr menu_id) {
  auto it = handles_.find(menu_id);
  if (it != handles_.end()) {
    auto& menu = static_cast<menu_item&>(it->second.get());
    menu.perform_click();
    return true;
  }
  return false;
}
