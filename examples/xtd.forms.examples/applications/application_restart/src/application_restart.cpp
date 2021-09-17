#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto restart_count = 0;
  if (!environment::get_environment_variable("applicatioon_restart_count").empty())
    restart_count = parse<int>(environment::get_environment_variable("applicatioon_restart_count"));

  auto main_form = control::create<form>(ustring::format("Restart {} times", restart_count));
  auto restart_button = control::create<button>(*main_form, "Restart", {10 ,10});
  restart_button->click += application::restart;

  environment::set_environment_variable("applicatioon_restart_count", to_string(restart_count + 1));

  application::run(*main_form);
}
