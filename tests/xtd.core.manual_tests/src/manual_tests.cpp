#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

using namespace std;
using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    console::beep(800, 200);
    console::write_line("End");
  }
};

startup_(xtd_core_manual_test);
