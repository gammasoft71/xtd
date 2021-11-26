#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Main menu example");
      menu(main_menu1);

      list_box1.parent(*this);
      list_box1.dock(dock_style::fill);
    }
    
    void on_menu_click(object& sender, const event_args& e) {
      list_box1.items().push_back(ustring::format("{} clicked", as<menu_item&>(sender).text()));
      list_box1.selected_index(list_box1.items().size() - 1);
    }
    
  private:
    menu_item file_open_recent_file1 {"Path/File1", {*this, &form1::on_menu_click}};
    menu_item file_open_recent_file2 {"Path/File2", {*this, &form1::on_menu_click}};
    menu_item file_open_recent_file3 {"Path/File3", {*this, &form1::on_menu_click}};
    menu_item file_open_recent_file4 {"Path/File4", {*this, &form1::on_menu_click}};

    menu_item file_new {system_texts::new_(), {*this, &form1::on_menu_click}, menu_images::file_new(), shortcut::cmd_n};
    menu_item file_separator1 {"-"};
    menu_item file_open {system_texts::open(), {*this, &form1::on_menu_click}, menu_images::file_open(), shortcut::cmd_o};
    menu_item file_open_recent {"Open recent", {file_open_recent_file1, file_open_recent_file2, file_open_recent_file3, file_open_recent_file4}};
    menu_item file_close {system_texts::close(), {*this, &form1::on_menu_click}, shortcut::cmd_w};
    menu_item file_separator2 {"-"};
    menu_item file_save {system_texts::save(), {*this, &form1::on_menu_click}, menu_images::file_save(), shortcut::cmd_s};
    menu_item file_save_as {system_texts::save_as(), {*this, &form1::on_menu_click}};
    menu_item file_separator3 {"-"};
    menu_item file_page_setup {"Page &Seup...", {*this, &form1::on_menu_click}};
    menu_item file_print {system_texts::print(), {*this, &form1::on_menu_click}, menu_images::file_print(), shortcut::cmd_p};
    menu_item file_print_preview {system_texts::print_preview(), {*this, &form1::on_menu_click}, menu_images::file_print_preview()};
    menu_item file_separator4 {"-"};
    menu_item file_exit {system_texts::exit(), {overload_<>(&application::exit)}, menu_images::file_exit(), shortcut::alt_f4};

    menu_item edit_undo {system_texts::undo(), {*this, &form1::on_menu_click}, menu_images::edit_undo(), shortcut::cmd_z};
    menu_item edit_redo {system_texts::redo(), {*this, &form1::on_menu_click}, menu_images::edit_redo(), shortcut::cmd_shift_z};
    menu_item edit_separator1 {"-"};
    menu_item edit_cut {system_texts::cut(), {*this, &form1::on_menu_click}, menu_images::edit_cut(), shortcut::cmd_x};
    menu_item edit_copy {system_texts::copy(), {*this, &form1::on_menu_click}, menu_images::edit_copy(), shortcut::cmd_c};
    menu_item edit_paste {system_texts::paste(), {*this, &form1::on_menu_click}, menu_images::edit_paste(), shortcut::cmd_v};
    menu_item edit_separator2 {"-"};
    menu_item edit_select_all {system_texts::select_all(), {*this, &form1::on_menu_click}, shortcut::cmd_a};
    menu_item edit_separator3 {"-"};
    menu_item edit_options {system_texts::options(), {*this, &form1::on_menu_click}};

    menu_item view_back {system_texts::back(), {*this, &form1::on_menu_click}, menu_images::view_back()};
    menu_item view_forward {system_texts::forward(), {*this, &form1::on_menu_click}, menu_images::view_forward()};
    menu_item view_separator1 {"-"};
    menu_item view_show {"Show", {*this, &form1::on_menu_click}};
    menu_item view_hide {"Hide", {*this, &form1::on_menu_click}};

    menu_item options_value_a {"Value A", {*this, &form1::on_menu_click}, menu_item_kind::check, true, shortcut::alt_1};
    menu_item options_value_b {"Value B", {*this, &form1::on_menu_click}, menu_item_kind::check, shortcut::alt_2};
    menu_item options_value_c {"Value C", {*this, &form1::on_menu_click}, menu_item_kind::check, true, shortcut::alt_3};
    menu_item options_separator1 {"-"};
    menu_item options_value_d {"Value D", {*this, &form1::on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::d)};
    menu_item options_value_e {"Value E", {*this, &form1::on_menu_click}, menu_item_kind::radio, true, static_cast<shortcut>(keys::alt|keys::e)};
    menu_item options_value_f {"Value F", {*this, &form1::on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::f)};
    menu_item options_separator2 {"-"};
    menu_item options_value_g {"Value G", {*this, &form1::on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::shift|keys::left)};
    menu_item options_value_h {"Value H", {*this, &form1::on_menu_click}, menu_item_kind::radio};
    menu_item options_value_i {"-"};

    menu_item help_about {system_texts::about(), {*this, &form1::on_menu_click}};

    menu_item file {system_texts::file(), {file_new, file_separator1, file_open, file_open_recent, file_close, file_separator2, file_save, file_save_as, file_separator3, file_page_setup, file_print, file_print_preview, file_separator4, file_exit}};
    menu_item edit {system_texts::edit(), {edit_undo, edit_redo, edit_separator1, edit_cut, edit_copy, edit_paste, edit_separator2, edit_select_all, edit_separator3, edit_options}};
    menu_item view {system_texts::view(), {view_back, view_forward, view_separator1, view_show, view_hide}};
    menu_item options {system_texts::options(), {options_value_a, options_value_b, options_value_c, options_separator1, options_value_d, options_value_e, options_value_f, options_separator2, options_value_g, options_value_h, options_value_i}};
    menu_item help {system_texts::help(), {help_about}};

    main_menu main_menu1 {file, edit, view, options, help};
    
    list_box list_box1;
  };
}

int main() {
  application::enable_menu_images();
  application::run(examples::form1());
}
