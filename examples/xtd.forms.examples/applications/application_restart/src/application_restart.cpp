#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

auto main()->int {
  auto restart_count = environment::get_environment_variable("applicatioon_restart_count").empty() ? 0 : parse<int>(environment::get_environment_variable("applicatioon_restart_count"));
  auto main_form = form::create(ustring::format("Restart {} times", restart_count));
  auto restart_button = button::create(main_form, "Restart", {10, 10});
  restart_button.click += application::restart;
  
  environment::set_environment_variable("applicatioon_restart_count", to_string(restart_count + 1));
  
  application::run(main_form);
}
