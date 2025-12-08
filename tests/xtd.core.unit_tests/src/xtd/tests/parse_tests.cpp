#include <xtd/string>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(parse_tests) {
    auto test_method_(parse_string) {
      assert::are_equal("string", xtd::parse<std::string>("string"));
    }
  };
}
