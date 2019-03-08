#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(manual_test) {
  public:
    void test_method_(test_case1) {
      std::ofstream of1("test1.txt");
      of1 << "Test1";
      of1.close();
      std::ofstream of2("test2.txt");
      of2 << "Test1";
      of2.close();
      
      file_assert::are_not_equal("test1.txt", "test2.txt");
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
