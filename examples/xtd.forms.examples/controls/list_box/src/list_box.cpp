#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("List box example");
      client_size({360, 240});

      layout_panel.parent(*this);
      layout_panel.dock(dock_style::fill);
      layout_panel.padding(forms::padding(20));
      
      list_box_left.parent(layout_panel);
      list_box_left.double_click += [&] {
        if (list_box_left.selected_index() != list_box_left.npos) {
          list_box_right.items().push_back(list_box_left.selected_item());
          list_box_right.selected_index(0);
          list_box_left.items().erase_at(list_box_left.selected_index());
        }
      };

      list_box_right.parent(layout_panel);
      list_box_right.sorted(true);
      list_box_right.double_click += [&] {
        if (list_box_right.selected_index() != list_box_right.npos) {
          list_box_left.items().push_back(list_box_right.selected_item());
          list_box_left.selected_index(0);
          list_box_right.items().erase_at(list_box_right.selected_index());
        }
      };
      
      list_box_left.items().push_back_range({"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"});
      list_box_left.selected_index(0);
    }
    
  private:
    horizontal_layout_panel layout_panel;
    list_box list_box_left;
    list_box list_box_right;
  };
}

int main() {
  application::run(examples::form1());
}
