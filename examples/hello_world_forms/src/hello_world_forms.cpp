#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  application::enable_visual_styles();
  
  button button1;
  button1.text("Click me");
  button1.location({10, 10});
  button1.click += [&](const control& sender, const event_args& e) {
    message_box::show("Hello, World!");
  };
  
  form form1;
  form1.text("Hello World Form");
  form.controls().push_back(button1);
  
  application::run(form1);
}
