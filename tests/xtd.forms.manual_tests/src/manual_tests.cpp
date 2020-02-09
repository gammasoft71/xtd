#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  main_menu menu;
  
  menu.menu_items().push_back("&File");
  menu.menu_items().push_back("&Edit");
  menu.menu_items().push_back("&View");
  menu.menu_items().push_back("&Window");
  menu.menu_items().push_back("&Help");

  form form_main;
  form_main.text("Manual tests");
  form_main.menu(menu);
  
  button button;
  button.parent(form_main);
  button.click += [&] {
    form form;
    form.show_dialog();
  };
  application::run(form_main);
}
