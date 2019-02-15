#include <xtd/tunit>
#include <iostream>
#include <stdexcept>
#include <thread>

using namespace xtd::tunit;
using namespace std;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(version_test) {
  public:
    void test_method_(test_case1) {
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    
    void test_method_(test_case2) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    
    void ignore_test_method_(test_case3) {
      std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
  };

  // The class test must be declared with test_class_ helper.
  class test_class_(uri_test) {
  public:
    void test_method_(test_case1) {
      std::this_thread::sleep_for(std::chrono::milliseconds(2));
      throw std::invalid_argument("");
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
