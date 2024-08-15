#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  auto duration = 26_h + 3_min + 32_s + 24_ms + 500_ns;
  console::out << ustring::format("{}", duration) << environment::new_line;
  console::out << ustring::format("{:c}", duration) << environment::new_line;
  console::out << ustring::format("{:d}", duration) << environment::new_line;
  console::out << ustring::format("{:D}", duration) << environment::new_line;
  console::out << ustring::format("{:f}", duration) << environment::new_line;
  console::out << ustring::format("{:F}", duration) << environment::new_line;
  console::out << ustring::format("{:g}", duration) << environment::new_line;
  console::out << ustring::format("{:G}", duration) << environment::new_line;
  console::out << ustring::format("{:h}", duration) << environment::new_line;
  console::out << ustring::format("{:H}", duration) << environment::new_line;
  console::out << ustring::format("{:m}", duration) << environment::new_line;
  console::out << ustring::format("{:M}", duration) << environment::new_line;
  console::out << ustring::format("{:n}", duration) << environment::new_line;
  console::out << ustring::format("{:N}", duration) << environment::new_line;
  console::out << ustring::format("{:s}", duration) << environment::new_line;
  console::out << ustring::format("{:S}", duration) << environment::new_line;
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
