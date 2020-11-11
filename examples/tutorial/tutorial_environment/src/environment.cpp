#include <xtd/xtd.core>
#include <xtd/xtd.console>

using namespace std::literals;

int main(int argc, char* argv[]) {
  xtd::console::write_line("os : {}", xtd::environment::os_version());
  xtd::console::write_line("user : {}", xtd::environment::user_name());
  xtd::console::write_line("system directory : {}", xtd::environment::system_directory());
}
