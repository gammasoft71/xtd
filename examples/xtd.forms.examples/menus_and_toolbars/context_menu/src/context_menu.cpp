#include <xtd/xtd>

namespace context_menu_example {
  class form1 : public form {
  public:
    form1() {
      text("Context menu example");
      
      list_box1.parent(*this);
      list_box1.dock(dock_style::fill);
      list_box1.context_menu(context_menu1);
    }
    
  protected:
    void on_form_closing(form_closing_event_args& e) override {
      e.cancel(message_box::show(*this, "Are you sure you want exit?", "Close Form", message_box_buttons::yes_no, message_box_icon::question) == dialog_result::no);
    };
    
  private:
    void on_menu_click(object& sender, const event_args& e) {
      list_box1.items().add(string::format("{} clicked", as<menu_item>(sender).text()));
      list_box1.selected_index(list_box1.items().count() - 1);
      if (file_exit_menu_item == sender) application::exit();
    }
    
    menu_item file_open_recent_file1_menu_item {"Path/File1", {*this, &form1::on_menu_click}};
    menu_item file_open_recent_file2_menu_item {"Path/File2", {*this, &form1::on_menu_click}};
    menu_item file_open_recent_file3_menu_item {"Path/File3", {*this, &form1::on_menu_click}};
    menu_item file_open_recent_file4_menu_item {"Path/File4", {*this, &form1::on_menu_click}};
    
    menu_item file_new_menu_item {texts::new_(), {*this, &form1::on_menu_click}, menu_images::file_new()};
    menu_item file_separator1_menu_item {"-"};
    menu_item file_open_menu_item {texts::open(), {*this, &form1::on_menu_click}, menu_images::file_open()};
    menu_item file_open_recent_menu_item {"Open recent", {file_open_recent_file1_menu_item, file_open_recent_file2_menu_item, file_open_recent_file3_menu_item, file_open_recent_file4_menu_item}};
    menu_item file_close_menu_item {texts::close(), {*this, &form1::on_menu_click}};
    menu_item file_separator2_menu_item {"-"};
    menu_item file_save_menu_item {texts::save(), {*this, &form1::on_menu_click}, menu_images::file_save()};
    menu_item file_save_as_menu_item {texts::save_as(), {*this, &form1::on_menu_click}};
    menu_item file_separator3_menu_item {"-"};
    menu_item file_page_setup_menu_item {"Page &Seup...", {*this, &form1::on_menu_click}};
    menu_item file_print_menu_item {texts::print(), {*this, &form1::on_menu_click}, menu_images::file_print()};
    menu_item file_print_preview_menu_item {texts::print_preview(), {*this, &form1::on_menu_click}, menu_images::file_print_preview()};
    menu_item file_separator4_menu_item {"-"};
    menu_item file_exit_menu_item {texts::exit(), {*this, &form1::on_menu_click}, menu_images::file_exit()};
    
    menu_item edit_undo_menu_item {texts::undo(), {*this, &form1::on_menu_click}, menu_images::edit_undo()};
    menu_item edit_redo_menu_item {texts::redo(), {*this, &form1::on_menu_click}, menu_images::edit_redo()};
    menu_item edit_separator1_menu_item {"-"};
    menu_item edit_cut_menu_item {texts::cut(), {*this, &form1::on_menu_click}, menu_images::edit_cut()};
    menu_item edit_copy_menu_item {texts::copy(), {*this, &form1::on_menu_click}, menu_images::edit_copy()};
    menu_item edit_paste_menu_item {texts::paste(), {*this, &form1::on_menu_click}, menu_images::edit_paste()};
    menu_item edit_separator2_menu_item {"-"};
    menu_item edit_select_all_menu_item {texts::select_all(), {*this, &form1::on_menu_click}};
    menu_item edit_separator3_menu_item {"-"};
    menu_item edit_options_menu_item {texts::options(), {*this, &form1::on_menu_click}};
    
    menu_item view_back_menu_item {texts::back(), {*this, &form1::on_menu_click}, menu_images::view_back()};
    menu_item view_forward_menu_item {texts::forward(), {*this, &form1::on_menu_click}, menu_images::view_forward()};
    menu_item view_separator1_menu_item {"-"};
    menu_item view_show_menu_item {"Show", {*this, &form1::on_menu_click}};
    menu_item view_hide_menu_item {"Hide", {*this, &form1::on_menu_click}};
    
    menu_item options_value_a_menu_item {"Value A", {*this, &form1::on_menu_click}, menu_item_kind::check, true};
    menu_item options_value_b_menu_item {"Value B", {*this, &form1::on_menu_click}, menu_item_kind::check};
    menu_item options_value_c_menu_item {"Value C", {*this, &form1::on_menu_click}, menu_item_kind::check, true};
    menu_item options_separator1_menu_item {"-"};
    menu_item options_value_d_menu_item {"Value D", {*this, &form1::on_menu_click}, menu_item_kind::radio};
    menu_item options_value_e_menu_item {"Value E", {*this, &form1::on_menu_click}, menu_item_kind::radio, true};
    menu_item options_value_f_menu_item {"Value F", {*this, &form1::on_menu_click}, menu_item_kind::radio};
    menu_item options_separator2_menu_item {"-"};
    menu_item options_value_g_menu_item {"Value G", {*this, &form1::on_menu_click}, menu_item_kind::radio};
    menu_item options_value_h_menu_item {"Value H", {*this, &form1::on_menu_click}, menu_item_kind::radio};
    menu_item options_value_i_menu_item {"Value I", {*this, &form1::on_menu_click}, menu_item_kind::radio};
    
    menu_item help_about_menu_item {texts::about(), {*this, &form1::on_menu_click}};
    
    menu_item file_menu_item {texts::file(), {file_new_menu_item, file_separator1_menu_item, file_open_menu_item, file_open_recent_menu_item, file_close_menu_item, file_separator2_menu_item, file_save_menu_item, file_save_as_menu_item, file_separator3_menu_item, file_page_setup_menu_item, file_print_menu_item, file_print_preview_menu_item, file_separator4_menu_item, file_exit_menu_item}};
    menu_item edit_menu_item {texts::edit(), {edit_undo_menu_item, edit_redo_menu_item, edit_separator1_menu_item, edit_cut_menu_item, edit_copy_menu_item, edit_paste_menu_item, edit_separator2_menu_item, edit_select_all_menu_item, edit_separator3_menu_item, edit_options_menu_item}};
    menu_item view_menu_item {texts::view(), {view_back_menu_item, view_forward_menu_item, view_separator1_menu_item, view_show_menu_item, view_hide_menu_item}};
    menu_item options_menu_item {texts::options(), {options_value_a_menu_item, options_value_b_menu_item, options_value_c_menu_item, options_separator1_menu_item, options_value_d_menu_item, options_value_e_menu_item, options_value_f_menu_item, options_separator2_menu_item, options_value_g_menu_item, options_value_h_menu_item, options_value_i_menu_item}};
    menu_item help_menu_item {texts::help(), {help_about_menu_item}};
    
    forms::context_menu context_menu1 {file_menu_item, edit_menu_item, view_menu_item, options_menu_item, help_menu_item};
    
    list_box list_box1;
  };
}

auto main() -> int {
  application::run(context_menu_example::form1 {});
}
