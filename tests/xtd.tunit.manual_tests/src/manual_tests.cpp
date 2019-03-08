#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(manual_test) {
  public:
    void test_method_(test_case1) {
      std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a);
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
