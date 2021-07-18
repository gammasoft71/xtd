#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu.h>
#include <xtd/forms/native/menu_item.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/menu_item.h"

using namespace xtd;
using namespace xtd::forms;

menu_item::menu_item() : menu(menu::menu_item_collection {}) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text) : menu(menu::menu_item_collection {}), text_(text) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), shortcut_(shortcut) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::drawing::image& image) : menu(menu::menu_item_collection {}), text_(text),image_(image)  {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text),image_(image), shortcut_(shortcut) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, xtd::forms::menu_item_kind kind) : menu(menu::menu_item_collection {}), text_(text), kind_(kind) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), kind_(kind), shortcut_(shortcut) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind), shortcut_(shortcut) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, xtd::forms::menu_item_kind kind, bool checked) : menu(menu::menu_item_collection {}), text_(text), kind_(kind), checked_(checked) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), kind_(kind), checked_(checked), shortcut_(shortcut) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind), checked_(checked) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind), checked_(checked), shortcut_(shortcut) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click) : menu(menu::menu_item_collection {}), text_(text) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), shortcut_(shortcut) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image) : menu(menu::menu_item_collection {}), text_(text),image_(image)  {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text),image_(image), shortcut_(shortcut) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind) : menu(menu::menu_item_collection {}), text_(text), kind_(kind) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), kind_(kind), shortcut_(shortcut) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind), shortcut_(shortcut) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, bool checked) : menu(menu::menu_item_collection {}), text_(text), kind_(kind), checked_(checked) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), kind_(kind), checked_(checked), shortcut_(shortcut) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind), checked_(checked) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : menu(menu::menu_item_collection {}), text_(text), image_(image), kind_(kind), checked_(checked), shortcut_(shortcut) {
  data_->on_click_ = on_click;
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const std::vector<menu_item>& items) : menu(items), text_(text) {
  data_->handle_ = create_menu_handle();
}

intptr_t menu_item::create_menu_handle() {
  if (is_parent()) {
    std::vector<intptr_t> menu_items;
    for (auto item : data_->menu_items_)
      menu_items.push_back(item.handle());
    return native::menu::create(text_, menu_items);
  }
  return native::menu_item::create(text_, image_, static_cast<int>(kind_), checked_, static_cast<size_t>(shortcut_));
}

void menu_item::destroy_menu_handle(intptr_t handle) {
  if (is_parent()) return native::menu::destroy(handle);
  return native::menu_item::destroy(handle);
}

int menu_item::menu_id() const {
  return native::menu_item::menu_id(data_->handle_);
}

std::string menu_item::to_string() const noexcept {
  return strings::format("{}, text: {}", menu::to_string(), text_);
}
