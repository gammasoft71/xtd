#include <xtd/xtd.drawing>

using namespace xtd;
using namespace xtd::drawing;

class xtd_drawing_manual_test : public object {
public:
  static void main() {
    console::write_line("Hello, with {}.", color::blue);
  }
};

startup_(xtd_drawing_manual_test);
