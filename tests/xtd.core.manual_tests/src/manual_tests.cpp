#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

using namespace std;
using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    console::write_line("is admin = {}", environment::user_administrator());
  }
};

startup_(xtd_core_manual_test);
