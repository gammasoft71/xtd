#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/main_menu.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/menu_item.h"
#include "../../../include/xtd/forms/main_menu.h"
#include "../../../include/xtd/forms/menu_images.h"
#include "../../../include/xtd/forms/shortcut.h"
#include "../../../include/xtd/forms/texts.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

main_menu::main_menu() {
  data_->menu_items_.item_added += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_ = *this;
    item.get().data_->parent_ = *this;
    item.get().create_menu();
  };

  data_->menu_items_.item_updated += [&](size_t, std::reference_wrapper<menu_item> item) {
    
  };

  data_->menu_items_.item_erased += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_.reset();
    item.get().destroy_menu();
  };

  data_->handle_ = create_menu_handle();
}

main_menu::main_menu(const std::initializer_list<menu_item>& menu_items) {
  data_->menu_items_.item_added += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_ = *this;
    item.get().data_->parent_ = *this;
    item.get().create_menu();
  };
  
  data_->menu_items_.item_updated += [&](size_t, std::reference_wrapper<menu_item> item) {
    
  };
  
  data_->menu_items_.item_erased += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_.reset();
    item.get().destroy_menu();
  };
  
  data_->menu_items_.push_back_range(menu_items);
  
  data_->handle_ = create_menu_handle();
}

main_menu::main_menu(const std::vector<menu_item>& menu_items) {
  data_->menu_items_.item_added += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_ = *this;
    item.get().data_->parent_ = *this;
    item.get().create_menu();
  };
  
  data_->menu_items_.item_updated += [&](size_t, std::reference_wrapper<menu_item> item) {
    
  };
  
  data_->menu_items_.item_erased += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_.reset();
    item.get().destroy_menu();
  };
  
  data_->menu_items_.push_back_range(menu_items);
  
  data_->handle_ = create_menu_handle();
}


main_menu::~main_menu() {
  if (data_.use_count() == 1) destroy_menu_handle(data_->handle_);
}

intptr_t main_menu::create_menu_handle() {
  std::vector<intptr_t> menu_items;
  for(auto menu_item : data_->menu_items_)
    menu_items.push_back(menu_item.data_->handle_);
  auto handle = native::main_menu::create(menu_items);
  handles_.clear();
  add_handles(data_->menu_items_);
  return handle;
}

void main_menu::destroy_menu_handle(intptr_t handle) {
  remove_handles(data_->menu_items_);
  return native::main_menu::destroy(handle);
}

void main_menu::wm_click(message& message) {
  auto& menu = static_cast<menu_item*>(handles_[message.lparam()])->menu_items()[message.wparam()];
  menu.data_->callback(menu);
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
      texts::file(), {
        {texts::new_(), on_click, menu_images::file_new(theme, size), shortcut::cmd_n},
        {texts::open(), on_click, menu_images::file_open(theme, size), shortcut::cmd_o},
        {"-"},
        {texts::save(), on_click, menu_images::file_save(theme, size), shortcut::cmd_s},
        {texts::save_as(), on_click},
        {"-"},
        {texts::print(), on_click, menu_images::file_print(theme, size), shortcut::cmd_p},
        {texts::print_preview(), on_click, menu_images::file_print_preview(theme, size)},
        {"-"},
        {texts::exit(), on_click, shortcut::alt_f4}
      }
    },
    {
      texts::edit(), {
        {texts::undo(), on_click, shortcut::cmd_z},
        {texts::redo(), on_click, shortcut::cmd_shift_z},
        {"-"},
        {texts::cut(), on_click, menu_images::edit_cut(theme, size), shortcut::cmd_x},
        {texts::copy(), on_click, menu_images::edit_copy(theme, size), shortcut::cmd_c},
        {texts::paste(), on_click, menu_images::edit_paste(theme, size), shortcut::cmd_v},
        {"-"},
        {texts::select_all(), on_click, shortcut::cmd_a}
      }
    },
    {
      texts::tools(), {
        {texts::customize(), on_click},
        {texts::options(), on_click}
      }
    },
    {
      texts::help(), {
        {texts::contents(), on_click},
        {texts::index(), on_click},
        {texts::search(), on_click},
        {"-"},
        {texts::about(), on_click}
      }
    }
  };
}
