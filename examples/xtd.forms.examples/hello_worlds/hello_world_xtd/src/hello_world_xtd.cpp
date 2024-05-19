#include <xtd/xtd>

using namespace xtd;
using namespace drawing;
using namespace xtd::forms;

namespace hello_world_xtd_example {
  class main_form : public form {
  public:
    main_form() {
      menu(main_menu);
      text("Hello world (xtd)");
      
      status.parent(*this);
      status.text("Welcome to xtd!");
    }
    
  private:
    void on_exit_menu_click(object& sender, const event_args& e) {
      close();
    }
    
    void on_hello_menu_click(object& sender, const event_args& e) {
      message_box::show("Hello world from xtd!");
    }
    
    void on_about_menu_click(object& sender, const event_args& e) {
      about_box::show("This is a xtd Hello World example", "About Hello World");
    }
    
    menu_item hello_menu {"&Hello...", {*this, &main_form::on_hello_menu_click}, shortcut::cmd_h};
    menu_item separator_menu {"-"};
    menu_item exit_menu {texts::exit(), {*this, &main_form::on_exit_menu_click}, shortcut::alt_f4};
    
    menu_item about_menu {texts::about(), {*this, &main_form::on_about_menu_click}};
    
    menu_item file_menu_item {texts::file(), {hello_menu, separator_menu, exit_menu}};
    menu_item help_menu_item {texts::help(), {about_menu}};
    forms::main_menu main_menu {file_menu_item, help_menu_item};
    
    forms::status_bar status;
  };
}

auto main() -> int {
  application::run(hello_world_xtd_example::main_form {});
}
