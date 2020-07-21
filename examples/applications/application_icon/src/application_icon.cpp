#include <xtd/xtd.forms>
#include "../properties/resources.h"

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Application icon example");
  main_form->icon(xtd::drawing::icon::from_bitmap(application_icon::properties::resources::application_icon()));
  xtd::forms::application::run(*main_form);
}
