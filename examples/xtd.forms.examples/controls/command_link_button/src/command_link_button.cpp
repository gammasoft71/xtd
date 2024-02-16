#include <xtd/forms/application>
#include <xtd/forms/command_link_button>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd;
using namespace xtd::forms;

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
      command_link_button1.click += [&] {
        label1.text(ustring::format("command link button 1 clicked {} times", ++command_link_button1_clicked));
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

auto main()->int {
  application::enable_button_images();
  application::run(command_link_button_example::form1 {});
}
