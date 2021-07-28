#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Checked list box example");
      client_size({200, 240});

      checked_list_box1.parent(*this);
      checked_list_box1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      checked_list_box1.location({20, 20});
      checked_list_box1.size({160, 200});

      for (auto index = 1; index <= 10; ++index)
        checked_list_box1.items().push_back({ustring::format("Item {}", index), index % 2 != 0});
      checked_list_box1.selected_index(0);
      
      checked_list_box1.item_check += [](object& sender, item_check_event_args& e) {
        cdebug << ustring::format("item_check, index={}, new_value={}, current_value={}", e.index(), e.new_value(), e.current_value()) << endl;
      };
    }
    
  private:
    checked_list_box checked_list_box1;
  };
}

int main() {
  application::run(examples::form1());
}
