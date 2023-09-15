#include <sstream>
#include <xtd/box>
#include <xtd/is>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(box_tests) {
  public:
    void test_method_(create_box_with_default_constructor) {
      box<int32> b;
      assert::is_zero(b.value(), csf_);
    }
    
    void test_method_(create_box_value_type) {
      box<int32> b;
      assert::is_true(is<int32>(b.value()), csf_);
      assert::is_zero(b.value(), csf_);
    }
    
    void test_method_(create_box_with_value_constructor) {
      box<int32> b(42);
      assert::are_equal(42, b.value(), csf_);
    }
    
    void test_method_(create_box_with_copy_constructor) {
      box<int32> b1(42);
      box<int32> b2(b1);
      assert::are_equal(42, b2.value(), csf_);
    }
    
    void test_method_(box_equal_operator) {
      box<int32> b;
      b = 42;
      assert::are_equal(42, b.value(), csf_);
    }
    
    void test_method_(box_value_type_operator) {
      box<int32> b(42);
      int32 i = b;
      assert::are_equal(42, i, csf_);
    }
    
    void test_method_(box_get_value) {
      box<int32> b(42);
      int32 i = b.value();
      assert::are_equal(42, i, csf_);
    }
    
    void test_method_(box_set_value) {
      box<int32> b;
      b.value(42);
      assert::are_equal(42, b.value(), csf_);
    }
    
    void test_method_(box_equals) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_true(b1.equals(b2), csf_);
      
      box<int32> b3(41);
      assert::is_false(b1.equals(b3), csf_);
    }
    
    void test_method_(box_operator_equals) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_true(b1 == b2, csf_);
      
      box<int32> b3(41);
      assert::is_false(b1 == b3, csf_);
    }
    
    void test_method_(box_operator_not_equals) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_false(b1 != b2, csf_);
      
      box<int32> b3(41);
      assert::is_true(b1 != b3, csf_);
    }
    
    void test_method_(box_compare_to) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_zero(b1.compare_to(b2), csf_);
      
      box<int32> b3(41);
      assert::is_positive(b1.compare_to(b3), csf_);
      
      box<int32> b4(43);
      assert::is_negative(b1.compare_to(b4), csf_);
    }
    
    void test_method_(box_operator_less) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_false(b1 < b2, csf_);
      
      box<int32> b3(41);
      assert::is_false(b1 < b3, csf_);
      
      box<int32> b4(43);
      assert::is_true(b1 < b4, csf_);
    }
    
    void test_method_(box_operator_less_equal) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_true(b1 <= b2, csf_);
      assert::is_false(b1 > b2, csf_);
      assert::is_true(b1 >= b2, csf_);
      
      box<int32> b3(41);
      assert::is_false(b1 <= b3, csf_);
      
      box<int32> b4(43);
      assert::is_true(b1 <= b4, csf_);
    }
    
    void test_method_(box_operator_greater) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_false(b1 > b2, csf_);
      
      box<int32> b3(41);
      assert::is_true(b1 > b3, csf_);
      
      box<int32> b4(43);
      assert::is_false(b1 > b4, csf_);
    }
    
    void test_method_(box_operator_greater_equal) {
      box<int32> b1(42);
      box<int32> b2(42);
      assert::is_true(b1 >= b2, csf_);
      
      box<int32> b3(41);
      assert::is_true(b1 >= b3, csf_);
      
      box<int32> b4(43);
      assert::is_false(b1 >= b4, csf_);
    }
    
    void test_method_(box_parse) {
      assert::are_equal(42, box<int32>::parse("42"));
    }
    
    void test_method_(box_to_string) {
      assert::are_equal("42", box<int32>(42).to_string());
    }
    
    void test_method_(box_to_string_wth_format) {
      assert::are_equal("2A", box<int32>(42).to_string("X"));
    }
    
    void test_method_(box_try_parse) {
      int32 value = 0;
      assert::is_true(box<int32>(42).try_parse("42", value));
      assert::are_equal(42, value);
      
      value = 0;
      assert::is_false(box<int32>(42).try_parse("xxx", value));
      assert::is_zero(value);
    }
  };
}
