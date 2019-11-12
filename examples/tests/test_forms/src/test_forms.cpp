#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace std::literals;

int main() {
  form form_main;
  form_main.client_size({1280, 850});
  form_main.text("Test Gui");

  application::run(form_main);
}
