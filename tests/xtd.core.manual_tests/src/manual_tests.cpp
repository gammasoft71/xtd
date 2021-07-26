#include <xtd/xtd.core>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test : public object {
public:
  static void main() {
    auto c = "Hello, Wolrd!";
    auto s1 = convert_string::to_ustring(c);
    auto s2 = as<ustring>(c);
    console::write_line(s1);
    console::write_line(s2);
  }
};

startup_(xtd_core_manual_test);
