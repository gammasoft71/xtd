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
  form_main.menu(forms::main_menu::create_standard_items([&](component& sender, const event_args& e) {
    cdebug << format("Clik on menu item : {}", static_cast<menu_item&>(sender).text()) << endl;
  }));
  //form_main.menu(nullptr);
  
  /*
  split_container splitter;
  splitter.parent(form_main);
  splitter.location({10, 10});
  //splitter.dock(dock_style::fill);
  //splitter.splitter_style(xtd::forms::splitter_style::update_childs);
  //splitter.orientation(xtd::forms::orientation::horzontal);
  splitter.splitter_width(1);
  
  splitter.panel1().border_style(forms::border_style::fixed_3d);
  splitter.panel2().border_style(forms::border_style::fixed_3d);
   */
  
  panel panel1;
  panel1.dock(dock_style::left);
  panel1.back_color(drawing::color::pink);
  panel1.width(70);

  splitter splitter;
  splitter.dock(dock_style::left);
  splitter.min_size(0);
  
  panel panel2;
  panel2.dock(dock_style::fill);
  panel2.back_color(drawing::color::light_green);

  form_main.controls().push_back_range({panel2, splitter, panel1});
  
  application::enable_menu_images();
  application::run(form_main);
}
