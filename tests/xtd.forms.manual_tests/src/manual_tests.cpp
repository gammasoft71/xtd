#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  //form.back_color(color::from_argb(64, 255, 0, 0));
  form.text(strings::format("{}", color::spring_green.name()));
  form.back_color(color::spring_green);
  
  application::run(form);
}
