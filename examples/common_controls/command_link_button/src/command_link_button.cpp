#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Command link button example");
      
      command_link_button1.parent(*this);
      command_link_button1.text("Command link\nwidth supplementary text");
      command_link_button1.location({30, 30});
      command_link_button1.click += [&] {
        label1.text(strings::format("command link button 1 clicked {} times", ++command_link_button1_clicked));
      };
      
      label1.parent(*this);
      label1.auto_size(true);
      label1.text("command link button 1 clicked 0 times");
      label1.location({30, 100});
    }
    
  private:
    command_link_button command_link_button1;
    label label1;
    int command_link_button1_clicked = 0;
  };
}

int main() {
  application::enable_button_images();
  application::run(examples::form1());
}
