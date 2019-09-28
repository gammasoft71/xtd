#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  form form1;

  check_box check_box1;
  check_box1.parent(form1);
  check_box1.location({20, 20});
  check_box1.text("radio 1");

  combo_box combo_box1;
  combo_box1.parent(form1);
  combo_box1.location({20, 60});
  combo_box1.items().push_back_range({{"top_left", content_alignment::top_left}, {"top_center", content_alignment::top_center}, {"top_right", content_alignment::top_right}, {"middle_left", content_alignment::middle_left}, {"middle_center", content_alignment::middle_center}, {"middle_right", content_alignment::middle_right}, {"bottom_left", content_alignment::bottom_left}, {"bottom_center", content_alignment::bottom_center}, {"bottom_right", content_alignment::bottom_right}});
  combo_box1.selected_index(3);
  combo_box1.selected_index_changed += [&] {
    check_box1.check_align(any_cast<content_alignment>(combo_box1.selected_item().tag()));
  };
  
  application::run(form1);
}
