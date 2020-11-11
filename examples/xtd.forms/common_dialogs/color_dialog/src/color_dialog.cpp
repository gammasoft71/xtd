#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Color dialog example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.text("Color...");
    button1.click += [&] {
      color_dialog color_dialog;
      color_dialog.color(this->back_color());
      if (color_dialog.show_dialog(*this) == forms::dialog_result::ok)
        this->back_color(color_dialog.color());
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
