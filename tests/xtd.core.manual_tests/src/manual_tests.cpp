#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    console::write_line("Start app");
    
    console::write_line("End app");
  }
};

startup_(xtd_core_manual_test);
