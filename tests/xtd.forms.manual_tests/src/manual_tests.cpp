#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;
using namespace xtd::diagnostics;

class form1 : public form {
public:
  form1() {
    this->name("form1");
    this->text("form1");
    this->form_closing += [&](const control& sender, form_closing_event_args& e) {
      e.cancel(true);
    };
  }
  
private:
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
