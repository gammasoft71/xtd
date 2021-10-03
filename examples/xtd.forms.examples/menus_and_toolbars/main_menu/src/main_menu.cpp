#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Main menu example");
      menu({
        {system_texts::file(), {
          {system_texts::new_(), {*this, &form1::on_menu_click}, menu_images::file_new(), shortcut::cmd_n},
          {"-"},
          {system_texts::open(), {*this, &form1::on_menu_click}, menu_images::file_open(), shortcut::cmd_o},
          {"Open recen", {
            {"Path/File1", {*this, &form1::on_menu_click}},
            {"Path/File2", {*this, &form1::on_menu_click}},
            {"Path/File3", {*this, &form1::on_menu_click}},
            {"Path/File4", {*this, &form1::on_menu_click}},
            {"Path/File5", {*this, &form1::on_menu_click}},
          }},
          {system_texts::close(), {*this, &form1::on_menu_click}, shortcut::cmd_w},
          {"-"},
          {system_texts::save(), {*this, &form1::on_menu_click}, menu_images::file_save(), shortcut::cmd_s},
          {system_texts::save_as(), {*this, &form1::on_menu_click}},
          {"-"},
          {"Page &Seup...", {*this, &form1::on_menu_click}},
          {system_texts::print(), {*this, &form1::on_menu_click}, menu_images::file_print(), shortcut::cmd_p},
          {system_texts::print_preview(), {*this, &form1::on_menu_click}, menu_images::file_print_preview()},
          {"-"},
          {system_texts::exit(), {overload_<>(&application::exit)}, menu_images::file_exit(), shortcut::alt_f4},
        }},
        {system_texts::edit(), {
          {system_texts::undo(), {*this, &form1::on_menu_click}, menu_images::edit_undo(), shortcut::cmd_z},
          {system_texts::redo(), {*this, &form1::on_menu_click}, menu_images::edit_redo(), shortcut::cmd_shift_z},
          {"-"},
          {system_texts::cut(), {*this, &form1::on_menu_click}, menu_images::edit_cut(), shortcut::cmd_x},
          {system_texts::copy(), {*this, &form1::on_menu_click}, menu_images::edit_copy(), shortcut::cmd_c},
          {system_texts::paste(), {*this, &form1::on_menu_click}, menu_images::edit_paste(), shortcut::cmd_v},
          {"-"},
          {system_texts::select_all(), {*this, &form1::on_menu_click}, shortcut::cmd_a},
          {"-"},
          {system_texts::options(), {*this, &form1::on_menu_click}},
        }},
        {system_texts::view(), {
          {system_texts::back(), {*this, &form1::on_menu_click}, menu_images::view_back()},
          {system_texts::forward(), {*this, &form1::on_menu_click}, menu_images::view_forward()},
          {"-"},
          {"Show", {*this, &form1::on_menu_click}},
          {"Hide", {*this, &form1::on_menu_click}},
        }},
        {system_texts::options(), {
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
        {system_texts::help(), {
          {system_texts::about(), {*this, &form1::on_menu_click}},
        }},
      });

      list_box1.parent(*this);
      list_box1.dock(dock_style::fill);
    }
    
    void on_menu_click(object& sender, const event_args& e) {
      list_box1.items().push_back(ustring::format("{} clicked", as<menu_item&>(sender).text()));
      list_box1.selected_index(list_box1.items().size() - 1);
    }
    
  private:
    list_box list_box1;
  };
}

int main() {
  application::enable_menu_images();
  application::run(examples::form1());
}
