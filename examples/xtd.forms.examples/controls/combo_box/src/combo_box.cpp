#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      controls().push_back_range({combo_box1, combo_box2, combo_box3});
      text("Combo box example");

      combo_box1.location({10, 10});
      combo_box1.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box1.selected_index(0);
      combo_box1.selected_index_changed += event_handler(*this, &form1::on_combo_box_click);

      combo_box2.location({10, 50});
      combo_box2.drop_down_style(combo_box_style::drop_down_list);
      combo_box2.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box2.selected_index(0);
      combo_box2.selected_index_changed += event_handler(*this, &form1::on_combo_box_click);

      combo_box3.location({10, 90});
      combo_box3.drop_down_style(combo_box_style::simple);
      combo_box3.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box3.selected_index(0);
      combo_box3.selected_index_changed += event_handler(*this, &form1::on_combo_box_click);
    }
    
  private:
    void on_combo_box_click(object& sender, const xtd::event_args& e) {
      combo_box1.selected_index(as<combo_box&>(sender).selected_index());
      combo_box2.selected_index(as<combo_box&>(sender).selected_index());
      combo_box3.selected_index(as<combo_box&>(sender).selected_index());
    }
    combo_box combo_box1;
    combo_box combo_box2;
    combo_box combo_box3;
  };
}

int main() {
  application::run(examples::form1());
}
