#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_parse) {
  public:
    void test_method_(parse_string) {
      assert::are_equal("string", xtd::parse<string>("string"));
    }

    void test_method_(parse_int) {
      assert::are_equal(42, xtd::parse<int>("42"));
    }

    void test_method_(parse_int_binary) {
      assert::are_equal(42, xtd::parse<int>("0b101010", number_styles::binary_number));
    }

    void test_method_(parse_int_octal) {
      assert::are_equal(42, xtd::parse<int>("052", number_styles::octal_number));
    }

    void test_method_(parse_int_hexa) {
      assert::are_equal(42, xtd::parse<int>("0x2A", number_styles::hex_number));
    }
  };
}
