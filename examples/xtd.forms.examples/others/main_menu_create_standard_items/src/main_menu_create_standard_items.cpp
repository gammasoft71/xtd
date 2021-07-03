#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Main menu create standard ittems example");
      menu(main_menu::create_standard_items([&](component& sender, const event_args& e) {
        list_box1.items().push_back(strings::format("{} clicked", static_cast<menu_item&>(sender).text()));
        list_box1.selected_index(list_box1.items().size() - 1);
      }));
      list_box1.parent(*this);
      list_box1.dock(dock_style::fill);
    }
    
  private:
    list_box list_box1;
  };
}

int main() {
  application::enable_menu_images();
  application::run(examples::form1());
}
