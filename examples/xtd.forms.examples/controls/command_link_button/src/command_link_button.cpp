#include <xtd/xtd>

namespace command_link_button_example {
  class form1 : public form {
  public:
    form1() {
      text("Command link button example");
      client_size({300, 300});
      
      command_link_button1.parent(*this);
      command_link_button1.texts({"Command link", "width supplementary text"});
      // same as
      //command_link_button1.text("Command link\nwidth supplementary text");
      command_link_button1.location({30, 30});
      command_link_button1.size({240, 60});
      command_link_button1.click += delegate_ {
        label1.text(string::format("command link button 1 clicked {} times", ++command_link_button1_clicked));
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

auto main() -> int {
  application::run(command_link_button_example::form1 {});
}
