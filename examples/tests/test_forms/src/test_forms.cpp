#include <xtd/xtd.forms>

using namespace xtd::forms;
using namespace std::literals;

int main() {
  xtd::drawing::point p {
    10, 24
  };
  form form;
  form.text("Test forms");
  form.show();
  application::run(form);
}
