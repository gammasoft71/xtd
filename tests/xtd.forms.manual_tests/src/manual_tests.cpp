#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  form.text("Manual tests");
  form.name("main form");

  form.paint += [&](const control& sender, paint_event_args& e) {
    //e.graphics().clear(color::spring_green);
    auto graphics = form.create_graphics();
    graphics->clear(color::spring_green);
  };
  
  application::run(form);
}
