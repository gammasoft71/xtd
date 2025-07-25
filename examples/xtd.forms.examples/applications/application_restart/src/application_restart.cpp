#include <xtd/xtd>

auto main() -> int {
  auto restart_count = environment::get_environment_variable("application_restart_count").empty() ? 0 : parse<int>(environment::get_environment_variable("application_restart_count"));
  auto main_form = form::create(string::format("Restart {} times", restart_count));
  auto restart_button = button::create(main_form, "Restart", {10, 10});
  restart_button.click += application::restart;
  
  environment::set_environment_variable("application_restart_count", int32_object {restart_count + 1}.to_string());
  
  application::run(main_form);
}
