#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("List box example");
      this->client_size({360, 240});

      this->list_box_left.parent(*this);
      this->list_box_left.location({20, 20});
      this->list_box_left.size({150, 200});
      this->list_box_left.double_click += [&](const control& sender, const event_args& e) {
        if (this->list_box_left.selected_index() != -1) {
          this->list_box_right.items().push_back(this->list_box_left.selected_item());
          this->list_box_right.selected_index(this->list_box_right.items().size() - 1);
          this->list_box_left.items().erase_at(this->list_box_left.selected_index());
        }
      };

      this->list_box_right.parent(*this);
      this->list_box_right.location({190, 20});
      this->list_box_right.size({150, 200});
      this->list_box_right.double_click += [&](const control& sender, const event_args& e) {
        if (this->list_box_right.selected_index() != -1) {
          this->list_box_left.items().push_back(this->list_box_right.selected_item());
          this->list_box_left.selected_index(this->list_box_left.items().size() - 1);
          this->list_box_right.items().erase_at(this->list_box_right.selected_index());
        }
      };
      
      this->list_box_left.items().push_back_range({"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"});
      this->list_box_left.selected_index(0);
    }
    
  private:
    list_box list_box_left;
    list_box list_box_right;
  };
}

int main() {
  application::run(examples::form1());
}
