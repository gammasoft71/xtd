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
    console::write_line("lb = {}", net::ip_address::ip_v6_loopback.to_string());
  }
};

startup_(xtd_core_manual_test);
