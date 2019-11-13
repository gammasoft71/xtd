#include <xtd/xtd.forms>
#include "Gammasoft-32x32.xpm"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  
  button button1;
  button1.parent(form_main);
  button1.location({10, 10});
  button1.size({100, 40});
  button1.image(bitmap(gammasoft_32x32));
  button1.text("Click me");
  button1.image_align(content_alignment::middle_left);

  application::run(form_main);
}
