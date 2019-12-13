#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  main_menu menu;
  
  menu.menu_items().push_back("File");
  menu.menu_items().push_back("Edit");
  menu.menu_items().push_back("View");
  
  form form_main;
  form_main.text("Manual tests");
  //form_main.menu(menu);
  form_main.auto_scroll(true);

  button button1;
  button1.parent(form_main);
  button1.location({10, 600});
  button1.text("Click");

  application::run(form_main);
}
