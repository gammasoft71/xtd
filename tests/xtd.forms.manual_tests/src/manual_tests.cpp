#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

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
  form_main.menu({
    {texts::file, {
      {texts::new_, xtd::drawing::images::new_16x16(), shortcut::cmd_n},
      {"-"},
      {texts::open, xtd::drawing::images::open_16x16(), shortcut::cmd_o},
      {"Open recen", {
        {"Path/File1"},
        {"Path/File2"},
        {"Path/File3"},
        {"Path/File4"},
        {"Path/File5"},
      }},
      {texts::close, shortcut::cmd_w},
      {"-"},
      {texts::save, xtd::drawing::images::save_16x16(), shortcut::cmd_s},
      {texts::save_as},
      {"-"},
      {"Page &Seup..."},
      {texts::print, xtd::drawing::images::print_16x16(), shortcut::cmd_p},
      {"-"},
      {texts::quit, xtd::drawing::images::quit_16x16(), shortcut::cmd_q},
    }},
    {texts::edit, {
      {texts::undo, xtd::drawing::images::undo_16x16(), shortcut::cmd_z},
      {texts::redo, xtd::drawing::images::redo_16x16(), shortcut::cmd_shift_z},
      {"-"},
      {texts::cut, xtd::drawing::images::cut_16x16(), shortcut::cmd_x},
      {texts::copy, xtd::drawing::images::copy_16x16(), shortcut::cmd_c},
      {texts::paste, xtd::drawing::images::paste_16x16(), shortcut::cmd_v},
      {"-"},
      {texts::select_all, shortcut::cmd_a},
      {"-"},
      {texts::options},
    }},
    {texts::view, {
      {texts::back, xtd::drawing::images::back_16x16()},
      {texts::forward, xtd::drawing::images::forward_16x16()},
      {"-"},
      {"Show"},
      {"Hide"},
    }},
    {texts::options, {
      {"Value A", menu_item_kind::check, shortcut::alt_1},
      {"Value B", menu_item_kind::check, shortcut::alt_2},
      {"Value C", menu_item_kind::check, shortcut::alt_3},
      {"-"},
      {"Value D", menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::d)},
      {"Value E", menu_item_kind::radio, true, static_cast<shortcut>(keys::alt|keys::e)},
      {"Value F", menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::f)},
      {"-"},
      {"Value G", menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::shift|keys::left)},
      {"Value H", menu_item_kind::radio},
      {"Value I", menu_item_kind::radio, true},
    }},
    {"&Window"},
    {texts::help, {
      {texts::about},
    }},
  });
  
  application::enable_menu_images();
  application::run(form_main);
}
