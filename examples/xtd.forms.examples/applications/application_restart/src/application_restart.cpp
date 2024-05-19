#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/environment>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

auto main() -> int {
  auto restart_count = environment::get_environment_variable("application_restart_count").empty() ? 0 : parse<int>(environment::get_environment_variable("application_restart_count"));
  auto main_form = form::create(ustring::format("Restart {} times", restart_count));
  auto restart_button = button::create(main_form, "Restart", {10, 10});
  restart_button.click += application::restart;
  
  environment::set_environment_variable("application_restart_count", to_string(restart_count + 1));
  
  application::run(main_form);
}
