#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/main_menu.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/menu_item.h"
#include "../../../include/xtd/forms/main_menu.h"
#include "../../../include/xtd/forms/menu_images.h"
#include "../../../include/xtd/forms/shortcut.h"
#include "../../../include/xtd/forms/system_texts.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

main_menu::main_menu() {
  create_menu();
}

main_menu::main_menu(const std::initializer_list<menu_item>& menu_items) {
  create_menu();
  data_->menu_items_.push_back_range(menu_items);
}

main_menu::main_menu(const std::vector<menu_item>& menu_items) {
  create_menu();
  data_->menu_items_.push_back_range(menu_items);
}

intptr_t main_menu::create_menu_handle() {
  return native::main_menu::create();
}

void main_menu::destroy_menu_handle(intptr_t handle) {
  if (handle) native::main_menu::destroy(handle);
}

void main_menu::on_item_added(size_t pos, std::reference_wrapper<menu_item> item) {
  menu::on_item_added(pos, item);
  item.get().data_->main_menu_ = make_unique<main_menu>(*this);
  item.get().data_->parent_ = make_unique<main_menu>(*this);
  if (!item.get().handle()) item.get().create_menu();
  native::main_menu::insert_item(handle(), pos, item.get().handle());
}

void main_menu::on_item_removed(size_t pos, std::reference_wrapper<menu_item> item) {
  menu::on_item_removed(pos, item);
  //item.get().data_->parent_.reset();
  //item.get().destroy_menu();
}

void main_menu::wm_click(message& message) {
  auto it = handles_.find(message.wparam());
  if (it != handles_.end()) {
    auto& menu = static_cast<menu_item&>(*it->second);
    menu.data_->callback(menu);
  }
}

xtd::forms::main_menu main_menu::create_standard_items(const xtd::event_handler& on_click) {
  return create_standard_items(theme_images::current_theme(), menu_images::size(), on_click);
}

xtd::forms::main_menu main_menu::create_standard_items(const drawing::size& size, const xtd::event_handler& on_click) {
  return create_standard_items(theme_images::current_theme(), size, on_click);
}

xtd::forms::main_menu main_menu::create_standard_items(const xtd::ustring& theme, const xtd::event_handler& on_click) {
  return create_standard_items(theme_images::current_theme(), menu_images::size(), on_click);
}

xtd::forms::main_menu main_menu::create_standard_items(const xtd::ustring& theme, const drawing::size& size, const xtd::event_handler& on_click) {
  return create_standard_items(theme_images::theme_from_name(theme), size, on_click);
}

xtd::forms::main_menu main_menu::create_standard_items(const xtd::forms::theme_images& theme, const drawing::size& size, const xtd::event_handler& on_click) {
  return  {
    {
      system_texts::file(), {
        {system_texts::new_(), on_click, menu_images::file_new(theme, size), shortcut::cmd_n},
        {system_texts::open(), on_click, menu_images::file_open(theme, size), shortcut::cmd_o},
        {"-"},
        {system_texts::save(), on_click, menu_images::file_save(theme, size), shortcut::cmd_s},
        {system_texts::save_as(), on_click},
        {"-"},
        {system_texts::print(), on_click, menu_images::file_print(theme, size), shortcut::cmd_p},
        {system_texts::print_preview(), on_click, menu_images::file_print_preview(theme, size)},
        {"-"},
        {system_texts::exit(), on_click, shortcut::alt_f4}
      }
    },
    {
      system_texts::edit(), {
        {system_texts::undo(), on_click, shortcut::cmd_z},
        {system_texts::redo(), on_click, shortcut::cmd_shift_z},
        {"-"},
        {system_texts::cut(), on_click, menu_images::edit_cut(theme, size), shortcut::cmd_x},
        {system_texts::copy(), on_click, menu_images::edit_copy(theme, size), shortcut::cmd_c},
        {system_texts::paste(), on_click, menu_images::edit_paste(theme, size), shortcut::cmd_v},
        {"-"},
        {system_texts::select_all(), on_click, shortcut::cmd_a}
      }
    },
    {
      system_texts::tools(), {
        {system_texts::customize(), on_click},
        {system_texts::options(), on_click}
      }
    },
    {
      system_texts::help(), {
        {system_texts::contents(), on_click},
        {system_texts::index(), on_click},
        {system_texts::search(), on_click},
        {"-"},
        {system_texts::about(), on_click}
      }
    }
  };
}
