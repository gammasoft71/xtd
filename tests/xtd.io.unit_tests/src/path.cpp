#include <xtd/io>
#include <xtd/tunit>

using namespace std;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_path) {
  public:
    void test_method_(alt_directory_separator_char) {
      assert::are_equal('/', path::alt_directory_separator_char());
    }
  };
}
