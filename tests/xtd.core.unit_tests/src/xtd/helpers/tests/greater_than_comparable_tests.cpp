#include <xtd/helpers/greater_than_comparable.hpp>
#include <xtd/enum_set_attribute.hpp>
#include <xtd/tunit/constraints/assert_that.hpp>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::helpers;

namespace xtd::helpers::tests {
  class test_class_(greater_than_comparable_tests) {
    auto test_method_(with_object) {
      struct my_object_test : public object {};
      assert_that(greater_than_comparable<my_object_test>).is().false_();
      assert_that(greater_than_comparable < my_object_test && >).is().false_();
      assert_that(greater_than_comparable<my_object_test&>).is().false_();
      assert_that(greater_than_comparable<const my_object_test&>).is().false_();
    }

    auto test_method_(with_icomparable) {
      struct my_icomparable_test : public icomparable<my_icomparable_test> {
        auto compare_to(const my_icomparable_test&) const noexcept -> int32 override {return 0;}
      };
      assert_that(greater_than_comparable<my_icomparable_test>).is().true_();
      assert_that(greater_than_comparable < my_icomparable_test && >).is().true_();
      assert_that(greater_than_comparable<my_icomparable_test&>).is().true_();
      assert_that(greater_than_comparable<const my_icomparable_test&>).is().true_();
    }
    
    auto test_method_(with_enum) {
      enum my_enum_test {};
      assert_that(greater_than_comparable<my_enum_test>).is().true_();
      assert_that(greater_than_comparable < my_enum_test && >).is().true_();
      assert_that(greater_than_comparable<my_enum_test&>).is().true_();
      assert_that(greater_than_comparable<const my_enum_test&>).is().true_();
    }
    
    auto test_method_(with_enum_class) {
      enum class my_enum_class_test {};
      assert_that(greater_than_comparable<my_enum_class_test>).is().true_();
      assert_that(greater_than_comparable < my_enum_class_test && >).is().true_();
      assert_that(greater_than_comparable<my_enum_class_test&>).is().true_();
      assert_that(greater_than_comparable<const my_enum_class_test&>).is().true_();
    }
    
    auto test_method_(with_enum_struct) {
      enum struct my_enum_struct_test {};
      assert_that(greater_than_comparable<my_enum_struct_test>).is().true_();
      assert_that(greater_than_comparable < my_enum_struct_test && >).is().true_();
      assert_that(greater_than_comparable<my_enum_struct_test&>).is().true_();
      assert_that(greater_than_comparable<const my_enum_struct_test&>).is().true_();
    }
    
    struct my_greater_than_comparable_test {
      auto operator >(const my_greater_than_comparable_test&) const noexcept {return false;}
    };
    
    auto test_method_(with_greater_than_comparable) {
      assert_that(greater_than_comparable<my_greater_than_comparable_test>).is().true_();
      assert_that(greater_than_comparable < my_greater_than_comparable_test && >).is().true_();
      assert_that(greater_than_comparable<my_greater_than_comparable_test&>).is().true_();
      assert_that(greater_than_comparable<const my_greater_than_comparable_test&>).is().true_();
    }
    
    struct my_tri_sstate_test {
      auto operator <=>(const my_tri_sstate_test&) const noexcept = default;
    };
    
    auto test_method_(with_tri_state) {
      assert_that(greater_than_comparable<my_tri_sstate_test>).is().true_();
      assert_that(greater_than_comparable < my_tri_sstate_test && >).is().true_();
      assert_that(greater_than_comparable<my_tri_sstate_test&>).is().true_();
      assert_that(greater_than_comparable<const my_tri_sstate_test&>).is().true_();
    }

    auto test_method_(with_somes_integrals) {
      assert_that(greater_than_comparable<sbyte>).is().true_();
      assert_that(greater_than_comparable < sbyte && >).is().true_();
      assert_that(greater_than_comparable<sbyte&>).is().true_();
      assert_that(greater_than_comparable<const sbyte&>).is().true_();
      
      assert_that(greater_than_comparable<int16>).is().true_();
      assert_that(greater_than_comparable < int16 && >).is().true_();
      assert_that(greater_than_comparable<int16&>).is().true_();
      assert_that(greater_than_comparable<const int16&>).is().true_();
      
      assert_that(greater_than_comparable<int32>).is().true_();
      assert_that(greater_than_comparable < int32 && >).is().true_();
      assert_that(greater_than_comparable<int32&>).is().true_();
      assert_that(greater_than_comparable<const int32&>).is().true_();
      
      assert_that(greater_than_comparable<int64>).is().true_();
      assert_that(greater_than_comparable < int64 && >).is().true_();
      assert_that(greater_than_comparable<int64&>).is().true_();
      assert_that(greater_than_comparable<const int64&>).is().true_();
      
      assert_that(greater_than_comparable<intptr>).is().true_();
      assert_that(greater_than_comparable < intptr && >).is().true_();
      assert_that(greater_than_comparable<intptr&>).is().true_();
      assert_that(greater_than_comparable<const intptr&>).is().true_();
      
      assert_that(greater_than_comparable<byte>).is().true_();
      assert_that(greater_than_comparable < byte && >).is().true_();
      assert_that(greater_than_comparable<byte&>).is().true_();
      assert_that(greater_than_comparable<const byte&>).is().true_();
      
      assert_that(greater_than_comparable<uint16>).is().true_();
      assert_that(greater_than_comparable < uint16 && >).is().true_();
      assert_that(greater_than_comparable<uint16&>).is().true_();
      assert_that(greater_than_comparable<const uint16&>).is().true_();
      
      assert_that(greater_than_comparable<uint32>).is().true_();
      assert_that(greater_than_comparable < uint32 && >).is().true_();
      assert_that(greater_than_comparable<uint32&>).is().true_();
      assert_that(greater_than_comparable<const uint32&>).is().true_();
      
      assert_that(greater_than_comparable<uint64>).is().true_();
      assert_that(greater_than_comparable < uint64 && >).is().true_();
      assert_that(greater_than_comparable<uint64&>).is().true_();
      assert_that(greater_than_comparable<const uint64&>).is().true_();
      
      assert_that(greater_than_comparable<uintptr>).is().true_();
      assert_that(greater_than_comparable < uintptr && >).is().true_();
      assert_that(greater_than_comparable<uintptr&>).is().true_();
      assert_that(greater_than_comparable<const uintptr&>).is().true_();
      
      assert_that(greater_than_comparable<float>).is().true_();
      assert_that(greater_than_comparable < float&& >).is().true_();
      assert_that(greater_than_comparable<float&>).is().true_();
      assert_that(greater_than_comparable<const float&>).is().true_();
      
      assert_that(greater_than_comparable<double>).is().true_();
      assert_that(greater_than_comparable < double&& >).is().true_();
      assert_that(greater_than_comparable<double&>).is().true_();
      assert_that(greater_than_comparable<const double&>).is().true_();
      
      assert_that(greater_than_comparable<decimal>).is().true_();
      assert_that(greater_than_comparable < decimal && >).is().true_();
      assert_that(greater_than_comparable<decimal&>).is().true_();
      assert_that(greater_than_comparable<const decimal&>).is().true_();
    }
    
    auto test_method_(with_invalid_type) {
      struct my_struct_test {};
      assert_that(greater_than_comparable<my_struct_test>).is().false_();
      assert_that(greater_than_comparable < my_struct_test && >).is().false_();
      assert_that(greater_than_comparable<my_struct_test&>).is().false_();
      assert_that(greater_than_comparable<const my_struct_test&>).is().false_();
    }
  };
}
