#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

using namespace xtd;

class xtd_core_manual_test : public object {
public:
  static void main() {
    console::write_line("Hello, World!");
  }
};

startup_(xtd_core_manual_test);
