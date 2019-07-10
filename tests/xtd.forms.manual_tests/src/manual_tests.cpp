#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");

    label1.parent(*this);
    label1.text("label1");
    label1.location({10, 50});

    button_add.parent(*this);
    button_add.text("Add");
    button_add.location({10, 150});
    button_add.mouse_click += [&](const control& sender, const mouse_event_args& e) {
      if (&this->label1.parent() == &control::null)
        this->label1.parent(*this);
    };

    button_remove.parent(*this);
    button_remove.text("Remove");
    button_remove.location({100, 150});
    button_remove.mouse_click += [&](const control& sender, const mouse_event_args& e) {
      if (&this->label1.parent() != &control::null)
        this->label1.parent(control::null);
    };
  }
  
private:
  label label1;
  button button_add;
  button button_remove;
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
