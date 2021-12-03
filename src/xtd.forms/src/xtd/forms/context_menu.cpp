#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/context_menu.h>
#include <xtd/forms/native/menu_item.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/menu_item.h"
#include "../../../include/xtd/forms/context_menu.h"
#include "../../../include/xtd/forms/menu_images.h"
#include "../../../include/xtd/forms/shortcut.h"
#include "../../../include/xtd/forms/system_texts.h"

using namespace xtd;
using namespace xtd::forms;

context_menu::context_menu() {
  create_menu();
}

context_menu::context_menu(const std::initializer_list<const_menu_item_ref>& menu_items) {
  create_menu();
  for (auto& item : menu_items)
    data_->menu_items_.push_back(menu_item_ref(const_cast<menu_item&>(item.get())));
}

context_menu::context_menu(const std::vector<menu_item_ref>& menu_items) {
  create_menu();
  data_->menu_items_.push_back_range(menu_items);
}

context_menu::~context_menu() {
  if (data_.use_count() == 1) destroy_menu_handle(data_->handle_);
}

intptr_t context_menu::create_menu_handle() {
  return native::context_menu::create();
}

void context_menu::destroy_menu_handle(intptr_t handle) {
  if (handle) native::context_menu::destroy(handle);
}

void context_menu::on_item_added(size_t pos, menu_item_ref item) {
  menu::on_item_added(pos, item);
  item.get().data_->context_menu_ = *this;
  item.get().data_->parent_ = *this;
  if (!item.get().handle()) item.get().create_menu();
  if (item.get().is_parent() || item.get().data_->main_menu_.has_value()) native::context_menu::insert_menu(handle(), pos, item.get().handle(), item.get().text());
  else {
    native::context_menu::insert_item(handle(), pos, item.get().handle());
    native::menu_item::enabled(item.get().handle(), item.get().enabled());
    if (item.get().kind() == menu_item_kind::check || item.get().kind() == menu_item_kind::radio) native::menu_item::checked(item.get().handle(), item.get().checked());
  }
}

void context_menu::on_item_removed(size_t pos, menu_item_ref item) {
  menu::on_item_removed(pos, item);
  item.get().data_->parent_.reset();
  native::context_menu::remove_item(handle(), pos);
}

void context_menu::wm_click(message& message) {
  auto it = handles_.find(static_cast<int32_t>(message.wparam()));
  if (it != handles_.end()) {
    auto& menu = static_cast<menu_item&>(it->second.get());
    menu.perform_click();
  }
}
