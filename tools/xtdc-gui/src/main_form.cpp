#include "main_form.h"
#include <xtd/forms/application.h>

using namespace xtd::forms;
using namespace xtdc_gui;

main_form::main_form() {
  text("New project");
  client_size({800, 600});
}

void main_form::main() {
  application::enable_visual_styles();
  application::run(main_form());
}
