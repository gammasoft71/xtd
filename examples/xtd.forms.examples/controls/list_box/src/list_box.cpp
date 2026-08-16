#include <xtd/xtd>

namespace list_box_example {
  class form1 : public form {
  public:
    form1() {
      text("List box example");
      client_size({360, 240});
      
      layout_panel.parent(self_);
      layout_panel.controls().add_range({list_box_left, list_box_right});
      layout_panel.control_layout_style(list_box_left, {size_type::auto_size, true});
      layout_panel.control_layout_style(list_box_right, {size_type::auto_size, true});
      layout_panel.dock(dock_style::fill);
      layout_panel.padding(forms::padding(20));
      
      list_box_left.double_click += delegate_ {
        if (list_box_left.selected_index() != list_box_left.npos) {
          list_box_right.items().add(list_box_left.selected_item());
          list_box_right.selected_index(0);
          list_box_left.items().remove_at(list_box_left.selected_index());
        }
      };
      
      list_box_right.sorted(true);
      list_box_right.double_click += delegate_ {
        if (list_box_right.selected_index() != list_box_right.npos) {
          list_box_left.items().add(list_box_right.selected_item());
          list_box_left.selected_index(0);
          list_box_right.items().remove_at(list_box_right.selected_index());
        }
      };
      
      list_box_left.items().add_range({"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"});
      list_box_left.selected_index(0);
    }
    
  private:
    horizontal_layout_panel layout_panel;
    list_box list_box_left;
    list_box list_box_right;
  };
}

auto main() -> int {
  application::run(list_box_example::form1 {});
}
