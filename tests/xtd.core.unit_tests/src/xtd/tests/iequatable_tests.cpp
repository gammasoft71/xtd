#include <xtd/iequatable>
#include <xtd/string>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(iequatable_tests) {
    class iequatable_test : public object, public iequatable<iequatable_test> {
    public:
      iequatable_test(int value) : value_(value) {}
      iequatable_test() = default;
      iequatable_test(iequatable_test&&) = default;
      iequatable_test(const iequatable_test&) = default;
      
      using object::equals;
      bool equals(const iequatable_test& ie) const noexcept override {return value_ == ie.value_;}
      
    private:
      int value_ = 0;
    };
    
    void test_method_(equals) {
      iequatable_test ie1 {42};
      iequatable_test ie2 {42};
      iequatable_test ie3 {84};
      
      assert::is_true(ie1.equals(ie2));
      assert::is_false(ie1.equals(ie3));
    }
    
    void test_method_(opearator_equal) {
      iequatable_test ie1 {42};
      iequatable_test ie2 {42};
      iequatable_test ie3 {84};
      
      assert::is_true(ie1 == ie2);
      assert::is_false(ie1 == ie3);
    }
    
    void test_method_(opearator_inequal) {
      iequatable_test ie1 {42};
      iequatable_test ie2 {42};
      iequatable_test ie3 {84};
      
      assert::is_false(ie1 != ie2);
      assert::is_true(ie1 != ie3);
    }
  };
}
