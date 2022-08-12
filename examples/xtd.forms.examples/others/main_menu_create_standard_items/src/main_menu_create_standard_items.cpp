#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Main menu create standard items example");
      menu(*main_menu1);
      list_box1.parent(*this);
      list_box1.dock(dock_style::fill);
    }
    
  private:
    void on_menu_click(object& sender, const event_args& e) {
      list_box1.items().push_back(ustring::format("{} clicked", as<menu_item>(sender).text()));
      list_box1.selected_index(list_box1.items().size() - 1);
      // The 10th item of menu_items is the file exit menu item.
      if (*menu_items[10] == sender) application::exit();
    }
    
    vector<unique_ptr<menu_item>> menu_items;
    unique_ptr<main_menu> main_menu1 = main_menu::create_standard_items(menu_items, {*this, &form1::on_menu_click});
    
    list_box list_box1;
  };
}

int main() {
  application::enable_menu_images();
  application::run(examples::form1 {});
}
