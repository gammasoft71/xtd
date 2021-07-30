#include <xtd/xtd.core>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test : public object {
public:
  static void main() {
    auto str = ustring::format("Hello, {}", "world!");
    console::write_line(str);
    console::write(std::array<std::string, 3> {"One", "Two", "Three"});
  }
};

startup_(xtd_core_manual_test);
