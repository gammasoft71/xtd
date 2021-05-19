#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    // console::write_line("Hello, Wolrd!");
    throw invalid_operation_exception(caller_info_);
  }
};

startup_(xtd_core_manual_test);