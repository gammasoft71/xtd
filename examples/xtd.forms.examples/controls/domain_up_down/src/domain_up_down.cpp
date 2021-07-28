#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Domain up down example");

      domain_up_down1.parent(*this);
      domain_up_down1.location({10, 10});
      domain_up_down1.items().push_back_range({"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"});
      domain_up_down1.text_changed += [&] {
        label1.text(ustring::format("value = {}", domain_up_down1.text()));
      };
      domain_up_down1.selected_index(1);

      label1.parent(*this);
      label1.location({10, 40});
    }
    
  private:
    domain_up_down domain_up_down1;
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
