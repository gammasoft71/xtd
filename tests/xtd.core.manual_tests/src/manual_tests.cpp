#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

using namespace std;
using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    console::write_line("{}", char_object::is_punctuation('.'));
  }
};

startup_(xtd_core_manual_test);
