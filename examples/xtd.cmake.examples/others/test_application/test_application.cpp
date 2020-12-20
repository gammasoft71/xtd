#include <xtd/xtd.tunit>

using namespace std::literals;
using namespace xtd::tunit;

class test_class_(test_application) {
public:
  void test_method_(test) {
    assert::succeed("This test application was generate by xtd cmake helpers. See CMakeLists.txt file.");
  }
};

int main() {
  return console_unit_test().run();
}
