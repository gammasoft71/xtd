#include <xtd/ustring.h>
#include <xtd/xtd.tunit>

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
  };
}
