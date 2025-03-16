#include <xtd/random>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(random_tests) {
    void test_method_(default_constructor) {
      assert::are_equal(std::default_random_engine {static_cast<uint32>(environment::tick_count().count())}, xtd::random {}.generator());
    }

    void test_method_(constructor_with_seed) {
      assert::are_equal(std::default_random_engine {1}, xtd::random {0}.generator());
      assert::are_equal(std::default_random_engine {2}, xtd::random {1}.generator());
      assert::are_equal(std::default_random_engine {11}, xtd::random {10}.generator());
    }

    void test_method_(constructor_with_device) {
      // to be defined...
    }
    
    void test_method_(copy_constructor) {
      assert::are_equal(std::default_random_engine {43}, xtd::random {xtd::random {42}}.generator());
    }
    
    void test_method_(copy_operator) {
      auto rnd = xtd::random {};
      rnd = xtd::random {42};
      assert::are_equal(std::default_random_engine {43}, rnd.generator());
    }

  };
}
