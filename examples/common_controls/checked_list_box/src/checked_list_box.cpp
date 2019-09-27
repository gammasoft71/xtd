#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Checked list box example");
      this->client_size({200, 240});

      this->checked_list_box1.parent(*this);
      this->checked_list_box1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      this->checked_list_box1.location({20, 20});
      this->checked_list_box1.size({160, 200});

      for (int index = 1; index <= 50; ++index)
        this->checked_list_box1.items().push_back({strings::format("Item {}", index), index % 2 != 0});
      this->checked_list_box1.selected_index(0);
    }
    
  private:
    checked_list_box checked_list_box1;
  };
}

int main() {
  application::run(examples::form1());
}
