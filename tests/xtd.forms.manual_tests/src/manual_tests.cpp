#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");

    button_add.parent(*this);
    button_add.text("Add");
    button_add.location({10, 150});
    button_add.mouse_click += [&](const control& sender, const mouse_event_args& e) {
      this->button_remove.text("Add");
    };

    button_remove.parent(*this);
    button_remove.text("Remove");
    button_remove.location({100, 150});
    button_remove.mouse_click += [&](const control& sender, const mouse_event_args& e) {
      this->button_remove.text("Remove");
    };
  }
  
private:
  button button_add;
  button button_remove;
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
