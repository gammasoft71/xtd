#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  auto duration = 26_h + 3_min + 32_s + 24_ms + 500_ns;
  console::out << string::format("{}", duration) << environment::new_line;
  console::out << string::format("{:c}", duration) << environment::new_line;
  console::out << string::format("{:d}", duration) << environment::new_line;
  console::out << string::format("{:D}", duration) << environment::new_line;
  console::out << string::format("{:f}", duration) << environment::new_line;
  console::out << string::format("{:F}", duration) << environment::new_line;
  console::out << string::format("{:g}", duration) << environment::new_line;
  console::out << string::format("{:G}", duration) << environment::new_line;
  console::out << string::format("{:h}", duration) << environment::new_line;
  console::out << string::format("{:H}", duration) << environment::new_line;
  console::out << string::format("{:m}", duration) << environment::new_line;
  console::out << string::format("{:M}", duration) << environment::new_line;
  console::out << string::format("{:n}", duration) << environment::new_line;
  console::out << string::format("{:N}", duration) << environment::new_line;
  console::out << string::format("{:s}", duration) << environment::new_line;
  console::out << string::format("{:S}", duration) << environment::new_line;
}

// This code produces the following output :
//
// 1.02:03:32:024000500
// 1.02:03:32:024000500
// 1
// 01
// 1:2:03:32:024000500
// 1:02:03:32:024000500
// 1.2:03:32:024000500
// 1.02:03:32:024000500
// 2
// 02
// 3
// 03
// 24000500
// 024000500
// 32
// 32
