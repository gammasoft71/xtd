#include "../../../include/xtd/forms/application"
#include "../../../include/xtd/forms/menu_item"
#include "../../../include/xtd/forms/main_menu"
#include "../../../include/xtd/forms/menu_images"
#include "../../../include/xtd/forms/shortcut"
#include "../../../include/xtd/forms/system_texts"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/main_menu>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "menu_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

main_menu::main_menu() {
  create_menu();
}

main_menu::main_menu(const std::initializer_list<const_menu_item_ref>& menu_items) {
  create_menu();
  for (auto& item : menu_items)
    data_->menu_items.push_back(menu_item_ref(const_cast<menu_item&>(item.get())));
}

main_menu::main_menu(const std::vector<menu_item_ref>& menu_items) {
  create_menu();
  data_->menu_items.push_back_range(menu_items);
}

intptr main_menu::create_menu_handle() {
  return native::main_menu::create();
}

void main_menu::destroy_menu_handle(intptr handle) {
  if (handle) native::main_menu::destroy(handle);
}

void main_menu::on_item_added(size_t pos, menu_item_ref item) {
  menu::on_item_added(pos, item);
  item.get().menu::data_->main_menu = *this;
  item.get().menu::data_->parent = *this;
  if (!item.get().handle()) item.get().create_menu();
  native::main_menu::insert_item(handle(), pos, item.get().handle(), item.get().text());
}

void main_menu::on_item_removed(size_t pos, menu_item_ref item) {
  menu::on_item_removed(pos, item);
  item.get().menu::data_->parent.reset();
  native::main_menu::remove_item(handle(), pos);
}

void main_menu::wm_click(message& message) {
  auto it = handles_.find(static_cast<int32>(message.wparam()));
  if (it != handles_.end()) {
    auto& menu = static_cast<menu_item&>(it->second.get());
    menu.perform_click();
  }
}

main_menu main_menu::create_standard_items(const xtd::event_handler& on_click) {
  return create_standard_items(application::style_sheet().theme().name(), menu_images::size(), on_click);
}

xtd::forms::main_menu main_menu::create_standard_items(const drawing::size& size, const xtd::event_handler& on_click) {
  return create_standard_items(application::style_sheet().theme().name(), size, on_click);
}

xtd::forms::main_menu main_menu::create_standard_items(const xtd::ustring& theme, const xtd::event_handler& on_click) {
  return create_standard_items(application::style_sheet().theme().name(), menu_images::size(), on_click);
}

xtd::forms::main_menu main_menu::create_standard_items(const xtd::ustring& theme, const drawing::size& size, const xtd::event_handler& on_click) {
  auto file_new_menu_item = make_unique<menu_item>(system_texts::new_(), on_click, menu_images::file_new(theme, size), shortcut::cmd_n);
  auto file_open_menu_item = make_unique<menu_item>(system_texts::open(), on_click, menu_images::file_open(theme, size), shortcut::cmd_o);
  auto file_separator1_menu_item = make_unique<menu_item>("-");
  auto file_save_menu_item = make_unique<menu_item>(system_texts::save(), on_click, menu_images::file_save(theme, size), shortcut::cmd_s);
  auto file_save_as_menu_item = make_unique<menu_item>(system_texts::save_as(), on_click);
  auto file_separator2_menu_item = make_unique<menu_item>("-");
  auto file_print_menu_item = make_unique<menu_item>(system_texts::print(), on_click, menu_images::file_print(theme, size), shortcut::cmd_p);
  auto file_print_preview_menu_item = make_unique<menu_item>(system_texts::print_preview(), on_click, menu_images::file_print_preview(theme, size));
  auto file_separator3_menu_item = make_unique<menu_item>("-");
  auto file_exit_menu_item = make_unique<menu_item>(system_texts::exit(), on_click, shortcut::alt_f4);
  
  auto edit_undo_menu_item = make_unique<menu_item>(system_texts::undo(), on_click, shortcut::cmd_z);
  auto edit_redo_menu_item = make_unique<menu_item>(system_texts::redo(), on_click, shortcut::cmd_shift_z);
  auto edit_separator1_menu_item = make_unique<menu_item>("-");
  auto edit_cut_menu_item = make_unique<menu_item>(system_texts::cut(), on_click, menu_images::edit_cut(theme, size), shortcut::cmd_x);
  auto edit_copy_menu_item = make_unique<menu_item>(system_texts::copy(), on_click, menu_images::edit_copy(theme, size), shortcut::cmd_c);
  auto edit_paste_menu_item = make_unique<menu_item>(system_texts::paste(), on_click, menu_images::edit_paste(theme, size), shortcut::cmd_v);
  auto edit_separator2_menu_item = make_unique<menu_item>("-");
  auto edit_select_all_menu_item = make_unique<menu_item>(system_texts::select_all(), on_click, shortcut::cmd_a);
  
  auto tools_customize_menu_item = make_unique<menu_item>(system_texts::customize(), on_click);
  auto tools_options_menu_item = make_unique<menu_item>(system_texts::options(), on_click);
  
  auto help_contents_menu_item = make_unique<menu_item>(system_texts::contents(), on_click);
  auto help_index_menu_item = make_unique<menu_item>(system_texts::index(), on_click);
  auto help_search_menu_item = make_unique<menu_item>(system_texts::search(), on_click);
  auto help_separator1_menu_item = make_unique<menu_item>("-");
  auto help_about_menu_item = make_unique<menu_item>(system_texts::about(), on_click);
  
  auto file_menu_item = make_unique<menu_item>(system_texts::file(), vector<menu_item_ref> {*file_new_menu_item, *file_open_menu_item, *file_separator1_menu_item, *file_save_menu_item, *file_save_as_menu_item, *file_separator2_menu_item, *file_print_menu_item, *file_print_preview_menu_item, *file_separator3_menu_item, *file_exit_menu_item});
  auto edit_menu_item = make_unique<menu_item>(system_texts::edit(), vector<menu_item_ref> {*edit_undo_menu_item, *edit_redo_menu_item, *edit_separator1_menu_item, *edit_cut_menu_item, *edit_copy_menu_item, *edit_paste_menu_item, *edit_separator2_menu_item, *edit_select_all_menu_item});
  auto tools_menu_item = make_unique<menu_item>(system_texts::tools(), vector<menu_item_ref> {*tools_customize_menu_item, *tools_options_menu_item});
  auto help_menu_item = make_unique<menu_item>(system_texts::help(), vector<menu_item_ref> {*help_contents_menu_item, *help_index_menu_item, *help_search_menu_item, *help_separator1_menu_item, *help_about_menu_item});
  
  auto main_menu_with_standard_items = main_menu(vector<menu_item_ref> {*file_menu_item, *edit_menu_item, *tools_menu_item, *help_menu_item});
  
  main_menu_with_standard_items.standard_menu_items_.clear();
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_new_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_open_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_separator1_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_save_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_save_as_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_separator2_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_print_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_print_preview_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_separator3_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(file_exit_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_undo_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_redo_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_separator1_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_cut_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_copy_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_paste_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_separator2_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(edit_select_all_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(tools_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(tools_customize_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(tools_options_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(help_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(help_contents_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(help_index_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(help_search_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(help_separator1_menu_item));
  main_menu_with_standard_items.standard_menu_items_.emplace_back(std::move(help_about_menu_item));
  
  return main_menu_with_standard_items;
}
