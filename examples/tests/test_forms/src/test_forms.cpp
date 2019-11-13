#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace std::literals;

int main() {
  form form;
  form.text("Test Gui");

  application::run(form);
}
