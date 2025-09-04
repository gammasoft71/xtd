#include <xtd/xtd>

namespace combo_box_example {
  class form1 : public form {
  public:
    form1() {
      controls().add_range({combo_box1, combo_box2, combo_box3});
      text("Combo box example");
      
      combo_box1.location({10, 10});
      combo_box1.items().add_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box1.selected_index(0);
      combo_box1.selected_index_changed += event_handler(*this, &form1::on_combo_box_selected_index_changed);
      
      combo_box2.location({10, 50});
      combo_box2.drop_down_style(combo_box_style::drop_down_list);
      combo_box2.items().add_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box2.selected_index(0);
      combo_box2.selected_index_changed += event_handler(*this, &form1::on_combo_box_selected_index_changed);
      
      combo_box3.location({10, 90});
      combo_box3.drop_down_style(combo_box_style::simple);
      combo_box3.items().add_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box3.selected_index(0);
      combo_box3.selected_index_changed += event_handler(*this, &form1::on_combo_box_selected_index_changed);
    }
    
  private:
    void on_combo_box_selected_index_changed(object& sender, const xtd::event_args& e) {
      combo_box1.selected_index(as<combo_box&>(sender).selected_index());
      combo_box2.selected_index(as<combo_box&>(sender).selected_index());
      combo_box3.selected_index(as<combo_box&>(sender).selected_index());
    }
    combo_box combo_box1;
    combo_box combo_box2;
    combo_box combo_box3;
  };
}

auto main() -> int {
  application::run(combo_box_example::form1 {});
}
