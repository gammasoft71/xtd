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
  form_main.menu(forms::main_menu::create_standard_items({[&](component& sender, const event_args& e) {
    cdebug << format("Clik on menu item : {}", static_cast<menu_item&>(sender).text()) << endl;
  }}));
  //form_main.menu(nullptr);
  
  application::enable_menu_images();
  application::run(form_main);
}
