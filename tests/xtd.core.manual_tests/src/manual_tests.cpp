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
    vector<byte_t> bytes;
    add_bytes(bytes, 123);
    add_bytes(bytes, 123);
    add_bytes(bytes, sbyte(123));
    console::write("bytes = [");
    for (auto b : bytes)
      console::write("{}, ", b);
    console::write_line("]");
  }
};

startup_(xtd_core_manual_test);
