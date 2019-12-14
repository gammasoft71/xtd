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

  tab_control tc;
  tc.parent(form_main);
  tc.dock(dock_style::fill);
  
  tab_page tp2;
  tp2.text("Two");
  tp2.auto_scroll(true);
  tc.controls().push_back(tp2);
  
  tab_page tp1;
  tp1.text("One");
  tp1.auto_scroll(true);
  tc.controls().insert_at(0, tp1);
  
  tab_page tp3;
  tp3.text("Three");
  tp3.auto_scroll(true);
  tc.controls().insert_at(2, tp3);
  
  button button1;
  button1.parent(tp2);
  button1.location({10, 10});
  button1.text("Click");
  button1.click += [&] {
    static int click_count = 0;
    tp2.text(strings::format("Two {}", ++click_count));
  };
  
  application::run(form_main);
}
