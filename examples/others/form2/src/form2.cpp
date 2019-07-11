#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  form form1 = control::create<form>("form1");
  application::run(form1);
}
