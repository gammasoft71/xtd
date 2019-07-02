#include <iostream>
#include <xtd/forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");

    ctl.parent(*this);
    ctl.size({100, 100});
  }
  
private:
  control ctl;
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
