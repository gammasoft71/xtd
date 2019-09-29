#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Checked list box example");
      client_size({200, 280});

      list_box1.parent(*this);
      list_box1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      list_box1.location({20, 20});
      list_box1.size({160, 200});

      button_add.parent(*this);
      button_add.location({20, 240});
      button_add.text("Add...");
      button_add.click += [this] {
        list_box1.begin_update();
        for (size_t index = 0; index < 10000; index++) {
          list_box1.items().push_back(strings::format("Item {}", index));
        }
        list_box1.end_update();
      };
    }
    
  private:
    list_box list_box1;
    button button_add;
  };
}

int main() {
  application::run(examples::form1());
}
