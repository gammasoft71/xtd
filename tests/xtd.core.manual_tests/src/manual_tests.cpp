#include <filesystem>
#include <xtd/xtd.core>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/priority_class.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    auto s = strings::to_string(u8"àçéèêëïî\U0001F428");
    for (char c : s)
      console::write("'\\x{:X}', ", static_cast<uint8_t>(c));
  }
};

startup_(xtd_core_manual_test);
