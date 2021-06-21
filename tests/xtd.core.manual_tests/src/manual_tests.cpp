#include <filesystem>
#include <xtd/xtd.core>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test {
public:
  static void main() {
    xtd_assert(false);
    //xtd_assert_message(false, "User message");
    //debug::cassert(false, "User message");
    console::write_line("Hello, World!");
  }
};

startup_(xtd_core_manual_test);
