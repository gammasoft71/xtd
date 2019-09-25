#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Combo box example");
      
      this->combo_box1.location({10, 10});
      this->combo_box1.items().push_back_range({"Item1", "Item2", "Item3"});
      this->combo_box1.selected_index(1);
      this->combo_box1.parent(*this);
    }
    
  private:
    combo_box combo_box1;
  };
}

int main() {
  application::run(examples::form1());
}
