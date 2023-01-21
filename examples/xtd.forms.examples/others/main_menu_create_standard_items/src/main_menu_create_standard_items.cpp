#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Main menu create standard items example");
      menu(main_menu1);
      list_box1.parent(*this);
      list_box1.dock(dock_style::fill);
    }
    
  private:
    void on_menu_click(object& sender, const event_args& e) {
      list_box1.items().push_back(ustring::format("{} clicked", as<menu_item>(sender).text()));
      list_box1.selected_index(list_box1.items().size() - 1);
      // Index 0 corresponds to the file menu and index 9 corresponds to the file exit menu.
      if (main_menu1.menu_items()[0].get().menu_items()[9].get() == sender) application::exit();
    }
    
    main_menu main_menu1 = main_menu::create_standard_items({*this, &form1::on_menu_click});
    
    list_box list_box1;
  };
}

auto main()->int {
  application::enable_menu_images();
  application::run(examples::form1 {});
}
