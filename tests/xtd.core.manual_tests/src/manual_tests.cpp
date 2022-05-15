#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

using namespace std;
using namespace xtd;


namespace {
  template<typename type_t>
  void add_bytes(vector<byte_t>& bytes, type_t value) {
    auto value_bytes = bit_converter::get_bytes(value);
    bytes.insert(bytes.end(), value_bytes.begin(), value_bytes.end());
  }
}

class xtd_core_manual_test : public object {
public:
  static void main() {
    console::write_line("Hello, World!");
    console::write_line("processor_count = {}", environment::processor_count());
    console::write_line("os = {}", environment::os_version().name());
    console::write_line("desktop = {}", environment::os_version().desktop_environment());
    console::write_line("theme = {}", environment::os_version().desktop_theme());
  }
};

startup_(xtd_core_manual_test);
