#include <xtd/xtd.core>
#include <xtd/xtd.console>

using namespace std::literals;

int main(int argc, char* argv[]) {
  auto str1 = xtd::environment::os_version().desktop_environment();
  auto str2 = "desktop"s;
  auto str3 = "environment"s;

  xtd::console::write_line(xtd::strings::join(" ", {str1, str2, str3}));
}
