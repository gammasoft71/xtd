#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(manual_test) {
  public:
    void test_method_(test_case1) {
      //std::vector<int> a = {1, 2, 3, 4, 1};
      collection_assert::is_not_empty(std::initializer_list<int>{});
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
