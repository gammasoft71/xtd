#include <xtd/icomparable>
#include <xtd/ustring>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(icomparable_tests) {
    class icomparable_test : public object, public icomparable<icomparable_test> {
    public:
      icomparable_test(int value) noexcept : value_(value) {}
      icomparable_test() noexcept = default;
      icomparable_test(icomparable_test&&) noexcept = default;
      icomparable_test(const icomparable_test&) noexcept = default;
      icomparable_test& operator =(const icomparable_test&) noexcept = default;
      
      int compare_to(const icomparable_test& ie) const noexcept override {return value_ < ie.value_ ? -1 : (value_ > ie.value_ ? 1 : 0);}
      
    private:
      int value_ = 0;
    };
    
    void test_method_(compare_to) {
      icomparable_test ic1 {42};
      icomparable_test ic2 {42};
      icomparable_test ic3 {84};
      
      assert::is_zero(ic1.compare_to(ic2), csf_);
      assert::is_negative(ic1.compare_to(ic3), csf_);
      assert::is_positive(ic3.compare_to(ic1), csf_);
    }
    
    void test_method_(opearator_less) {
      icomparable_test ic1 {42};
      icomparable_test ic2 {42};
      icomparable_test ic3 {84};
      
      assert::is_false(ic1 < ic2, csf_);
      assert::is_true(ic1 < ic3, csf_);
      assert::is_false(ic3 < ic1, csf_);
      assert::is_false(ic1 < "a"_s);
    }
    
    void test_method_(opearator_less_or_equal) {
      icomparable_test ic1 {42};
      icomparable_test ic2 {42};
      icomparable_test ic3 {84};
      
      assert::is_true(ic1 <= ic2, csf_);
      assert::is_true(ic1 <= ic3, csf_);
      assert::is_false(ic3 <= ic1);
      assert::is_false(ic1 <= "a"_s);
    }
    
    void test_method_(opearator_greather) {
      icomparable_test ic1 {42};
      icomparable_test ic2 {42};
      icomparable_test ic3 {84};
      
      assert::is_false(ic1 > ic2, csf_);
      assert::is_false(ic1 > ic3, csf_);
      assert::is_true(ic3 > ic1, csf_);
      assert::is_false(ic1 > "a"_s);
    }
    
    void test_method_(opearator_greather_or_equal) {
      icomparable_test ic1 {42};
      icomparable_test ic2 {42};
      icomparable_test ic3 {84};
      
      assert::is_true(ic1 >= ic2, csf_);
      assert::is_false(ic1 >= ic3, csf_);
      assert::is_true(ic3 >= ic1, csf_);
      assert::is_false(ic1 >= "a"_s);
    }
  };
}
