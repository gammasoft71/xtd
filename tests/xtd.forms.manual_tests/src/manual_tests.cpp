#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

void on_menu_click(component& sender, const event_args& e) {
  cdebug << format("Clik on menu item : {}", static_cast<menu_item&>(sender).text()) << endl;
}

int main() {
  /*
  main_menu menu;
  menu.menu_items().push_back("&File");
  menu.menu_items().push_back("&Edit");
  menu.menu_items().push_back("&View");
  menu.menu_items().push_back("&Window");
  menu.menu_items().push_back("&Help");
   */

  form form_main;
  form_main.text("Manual tests");
  //form_main.menu(menu);
  /*
  form_main.menu({
    {texts::file, {
      {texts::new_, {on_menu_click}, menu_images::file_new(), shortcut::cmd_n},
      {"-"},
      {texts::open, {on_menu_click}, menu_images::file_open(), shortcut::cmd_o},
      {"Open recen", {
        {"Path/File1", {on_menu_click}},
        {"Path/File2", {on_menu_click}},
        {"Path/File3", {on_menu_click}},
        {"Path/File4", {on_menu_click}},
        {"Path/File5", {on_menu_click}},
      }},
      {texts::close, {on_menu_click}, shortcut::cmd_w},
      {"-"},
      {texts::save, {on_menu_click}, menu_images::file_save(), shortcut::cmd_s},
      {texts::save_as, {on_menu_click}},
      {"-"},
      {"Page &Seup...", {on_menu_click}},
      {texts::print, {on_menu_click},menu_images::file_print(), shortcut::cmd_p},
      {"-"},
      {texts::exit, {on_menu_click}, menu_images::file_exit(), shortcut::alt_f4},
    }},
    {texts::edit, {
      {texts::undo, {on_menu_click}, menu_images::edit_undo(), shortcut::cmd_z},
      {texts::redo, {on_menu_click}, menu_images::edit_redo(), shortcut::cmd_shift_z},
      {"-"},
      {texts::cut, {on_menu_click}, menu_images::edit_cut(), shortcut::cmd_x},
      {texts::copy, {on_menu_click}, menu_images::edit_copy(), shortcut::cmd_c},
      {texts::paste, {on_menu_click}, menu_images::edit_paste(), shortcut::cmd_v},
      {"-"},
      {texts::select_all, {on_menu_click}, shortcut::cmd_a},
      {"-"},
      {texts::options, {on_menu_click}},
    }},
    {texts::view, {
      {texts::back, {on_menu_click}, menu_images::view_back()},
      {texts::forward, {on_menu_click}, menu_images::view_forward()},
      {"-"},
      {"Show", {on_menu_click}},
      {"Hide", {on_menu_click}},
    }},
    {texts::options, {
      {"Value A", {on_menu_click}, menu_item_kind::check, true, shortcut::alt_1},
      {"Value B", {on_menu_click}, menu_item_kind::check, shortcut::alt_2},
      {"Value C", {on_menu_click}, menu_item_kind::check, true, shortcut::alt_3},
      {"-"},
      {"Value D", {on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::d)},
      {"Value E", {on_menu_click}, menu_item_kind::radio, true, static_cast<shortcut>(keys::alt|keys::e)},
      {"Value F", {on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::f)},
      {"-"},
      {"Value G", {on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::shift|keys::left)},
      {"Value H", {on_menu_click}, menu_item_kind::radio},
      {"Value I", {on_menu_click}, menu_item_kind::radio, true},
    }},
    {texts::help, {
      {texts::about, {on_menu_click}, menu_images::help_about()},
    }},
  });
   */
  form_main.menu(forms::main_menu::create_standard_items("symbols"));
  
  application::enable_menu_images();
  application::run(form_main);
}
