#include <xtd/ustring>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(parse_tests) {
  public:
    void test_method_(parse_string) {
      assert::are_equal("string", xtd::parse<string>("string"), csf_);
    }
  };
}
