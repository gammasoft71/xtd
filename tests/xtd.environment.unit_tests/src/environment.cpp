#include <xtd/environment>
#include <xtd/tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_environment) {
  public:
    void test_method_(create_environment) {
      assert::are_equal_(42, 42);
    }
  };
}
