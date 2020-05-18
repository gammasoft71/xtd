#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Menu example");
      menu({
        {texts::file, {
          {texts::new_, {*this, &form1::on_menu_click}, xtd::drawing::images::new_16x16(), shortcut::cmd_n},
          {"-"},
          {texts::open, {*this, &form1::on_menu_click}, xtd::drawing::images::open_16x16(), shortcut::cmd_o},
          {"Open recen", {
            {"Path/File1", {*this, &form1::on_menu_click}},
            {"Path/File2", {*this, &form1::on_menu_click}},
            {"Path/File3", {*this, &form1::on_menu_click}},
            {"Path/File4", {*this, &form1::on_menu_click}},
            {"Path/File5", {*this, &form1::on_menu_click}},
          }},
          {texts::close, {*this, &form1::on_menu_click}, shortcut::cmd_w},
          {"-"},
          {texts::save, {*this, &form1::on_menu_click}, xtd::drawing::images::save_16x16(), shortcut::cmd_s},
          {texts::save_as, {*this, &form1::on_menu_click}},
          {"-"},
          {"Page &Seup...", {*this, &form1::on_menu_click}},
          {texts::print, {*this, &form1::on_menu_click}, xtd::drawing::images::print_16x16(), shortcut::cmd_p},
          {"-"},
          {texts::quit, {*this, &form1::on_menu_click}, xtd::drawing::images::quit_16x16(), environment::os_version().is_windows_platform() ? shortcut::alt_f4 : shortcut::cmd_q},
        }},
        {texts::edit, {
          {texts::undo, {*this, &form1::on_menu_click}, xtd::drawing::images::undo_16x16(), shortcut::cmd_z},
          {texts::redo, {*this, &form1::on_menu_click}, xtd::drawing::images::redo_16x16(), shortcut::cmd_shift_z},
          {"-"},
          {texts::cut, {*this, &form1::on_menu_click}, xtd::drawing::images::cut_16x16(), shortcut::cmd_x},
          {texts::copy, {*this, &form1::on_menu_click}, xtd::drawing::images::copy_16x16(), shortcut::cmd_c},
          {texts::paste, {*this, &form1::on_menu_click}, xtd::drawing::images::paste_16x16(), shortcut::cmd_v},
          {"-"},
          {texts::select_all, {*this, &form1::on_menu_click}, shortcut::cmd_a},
          {"-"},
          {texts::options, {*this, &form1::on_menu_click}},
        }},
        {texts::view, {
          {texts::back, {*this, &form1::on_menu_click}, xtd::drawing::images::back_16x16()},
          {texts::forward, {*this, &form1::on_menu_click}, xtd::drawing::images::forward_16x16()},
          {"-"},
          {"Show", {*this, &form1::on_menu_click}},
          {"Hide", {*this, &form1::on_menu_click}},
        }},
        {texts::options, {
          {"Value A", {*this, &form1::on_menu_click}, menu_item_kind::check, true, shortcut::alt_1},
          {"Value B", {*this, &form1::on_menu_click}, menu_item_kind::check, shortcut::alt_2},
          {"Value C", {*this, &form1::on_menu_click}, menu_item_kind::check, true, shortcut::alt_3},
          {"-"},
          {"Value D", {*this, &form1::on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::d)},
          {"Value E", {*this, &form1::on_menu_click}, menu_item_kind::radio, true, static_cast<shortcut>(keys::alt|keys::e)},
          {"Value F", {*this, &form1::on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::f)},
          {"-"},
          {"Value G", {*this, &form1::on_menu_click}, menu_item_kind::radio, static_cast<shortcut>(keys::alt|keys::shift|keys::left)},
          {"Value H", {*this, &form1::on_menu_click}, menu_item_kind::radio},
          {"Value I", {*this, &form1::on_menu_click}, menu_item_kind::radio, true},
        }},
        {texts::help, {
          {texts::about, {*this, &form1::on_menu_click}},
        }},
      });

      list_box1.parent(*this);
      list_box1.dock(dock_style::fill);
    }
    
    void on_menu_click(component& sender, const event_args& e) {
      list_box1.items().push_back(strings::format("{} clicked", static_cast<menu_item&>(sender).text()));
    }
    
  private:
    list_box list_box1;
  };
}

int main() {
  application::enable_menu_images();
  application::run(examples::form1());
}
