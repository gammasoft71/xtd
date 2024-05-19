#include <xtd/forms/application>
#include <xtd/forms/form>

using namespace xtd::forms;

auto main() -> int {
  application::run(form::create("Application name"));
}
