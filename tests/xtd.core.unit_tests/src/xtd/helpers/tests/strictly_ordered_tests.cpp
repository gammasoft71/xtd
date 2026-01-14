#include <xtd/helpers/strictly_ordered.hpp>
#include <xtd/enum_set_attribute.hpp>
#include <xtd/tunit/constraints/assert_that.hpp>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::helpers;

namespace xtd::helpers::tests {
  class test_class_(strictly_ordered_tests) {
    auto test_method_(with_object) {
      struct my_object_test : public object {};
      assert_that(strictly_ordered<my_object_test>).is().false_();
      assert_that(strictly_ordered < my_object_test && >).is().false_();
      assert_that(strictly_ordered<my_object_test&>).is().false_();
      assert_that(strictly_ordered<const my_object_test&>).is().false_();
    }

    auto test_method_(with_icomparable) {
      struct my_icomparable_test : public icomparable<my_icomparable_test> {
        auto compare_to(const my_icomparable_test&) const noexcept -> int32 override {return 0;}
      };
      assert_that(strictly_ordered<my_icomparable_test>).is().true_();
      assert_that(strictly_ordered < my_icomparable_test && >).is().true_();
      assert_that(strictly_ordered<my_icomparable_test&>).is().true_();
      assert_that(strictly_ordered<const my_icomparable_test&>).is().true_();
    }
    
    auto test_method_(with_enum) {
      enum my_enum_test {};
      assert_that(strictly_ordered<my_enum_test>).is().true_();
      assert_that(strictly_ordered < my_enum_test && >).is().true_();
      assert_that(strictly_ordered<my_enum_test&>).is().true_();
      assert_that(strictly_ordered<const my_enum_test&>).is().true_();
    }
    
    auto test_method_(with_enum_class) {
      enum class my_enum_class_test {};
      assert_that(strictly_ordered<my_enum_class_test>).is().true_();
      assert_that(strictly_ordered < my_enum_class_test && >).is().true_();
      assert_that(strictly_ordered<my_enum_class_test&>).is().true_();
      assert_that(strictly_ordered<const my_enum_class_test&>).is().true_();
    }
    
    auto test_method_(with_enum_struct) {
      enum struct my_enum_struct_test {};
      assert_that(strictly_ordered<my_enum_struct_test>).is().true_();
      assert_that(strictly_ordered < my_enum_struct_test && >).is().true_();
      assert_that(strictly_ordered<my_enum_struct_test&>).is().true_();
      assert_that(strictly_ordered<const my_enum_struct_test&>).is().true_();
    }
    
    struct my_strictly_ordered_test {
      auto operator <(const my_strictly_ordered_test&) const noexcept {return false;}
      auto operator >(const my_strictly_ordered_test&) const noexcept {return false;}
    };
    
    auto test_method_(with_strictly_ordered) {
      assert_that(strictly_ordered<my_strictly_ordered_test>).is().true_();
      assert_that(strictly_ordered < my_strictly_ordered_test && >).is().true_();
      assert_that(strictly_ordered<my_strictly_ordered_test&>).is().true_();
      assert_that(strictly_ordered<const my_strictly_ordered_test&>).is().true_();
    }
    
    struct my_tri_sstate_test {
      auto operator <=>(const my_tri_sstate_test&) const noexcept = default;
    };
    
    auto test_method_(with_tri_state) {
      assert_that(strictly_ordered<my_tri_sstate_test>).is().true_();
      assert_that(strictly_ordered < my_tri_sstate_test && >).is().true_();
      assert_that(strictly_ordered<my_tri_sstate_test&>).is().true_();
      assert_that(strictly_ordered<const my_tri_sstate_test&>).is().true_();
    }

    auto test_method_(with_somes_integrals) {
      assert_that(strictly_ordered<sbyte>).is().true_();
      assert_that(strictly_ordered < sbyte && >).is().true_();
      assert_that(strictly_ordered<sbyte&>).is().true_();
      assert_that(strictly_ordered<const sbyte&>).is().true_();
      
      assert_that(strictly_ordered<int16>).is().true_();
      assert_that(strictly_ordered < int16 && >).is().true_();
      assert_that(strictly_ordered<int16&>).is().true_();
      assert_that(strictly_ordered<const int16&>).is().true_();
      
      assert_that(strictly_ordered<int32>).is().true_();
      assert_that(strictly_ordered < int32 && >).is().true_();
      assert_that(strictly_ordered<int32&>).is().true_();
      assert_that(strictly_ordered<const int32&>).is().true_();
      
      assert_that(strictly_ordered<int64>).is().true_();
      assert_that(strictly_ordered < int64 && >).is().true_();
      assert_that(strictly_ordered<int64&>).is().true_();
      assert_that(strictly_ordered<const int64&>).is().true_();
      
      assert_that(strictly_ordered<intptr>).is().true_();
      assert_that(strictly_ordered < intptr && >).is().true_();
      assert_that(strictly_ordered<intptr&>).is().true_();
      assert_that(strictly_ordered<const intptr&>).is().true_();
      
      assert_that(strictly_ordered<byte>).is().true_();
      assert_that(strictly_ordered < byte && >).is().true_();
      assert_that(strictly_ordered<byte&>).is().true_();
      assert_that(strictly_ordered<const byte&>).is().true_();
      
      assert_that(strictly_ordered<uint16>).is().true_();
      assert_that(strictly_ordered < uint16 && >).is().true_();
      assert_that(strictly_ordered<uint16&>).is().true_();
      assert_that(strictly_ordered<const uint16&>).is().true_();
      
      assert_that(strictly_ordered<uint32>).is().true_();
      assert_that(strictly_ordered < uint32 && >).is().true_();
      assert_that(strictly_ordered<uint32&>).is().true_();
      assert_that(strictly_ordered<const uint32&>).is().true_();
      
      assert_that(strictly_ordered<uint64>).is().true_();
      assert_that(strictly_ordered < uint64 && >).is().true_();
      assert_that(strictly_ordered<uint64&>).is().true_();
      assert_that(strictly_ordered<const uint64&>).is().true_();
      
      assert_that(strictly_ordered<uintptr>).is().true_();
      assert_that(strictly_ordered < uintptr && >).is().true_();
      assert_that(strictly_ordered<uintptr&>).is().true_();
      assert_that(strictly_ordered<const uintptr&>).is().true_();
      
      assert_that(strictly_ordered<float>).is().true_();
      assert_that(strictly_ordered < float&& >).is().true_();
      assert_that(strictly_ordered<float&>).is().true_();
      assert_that(strictly_ordered<const float&>).is().true_();
      
      assert_that(strictly_ordered<double>).is().true_();
      assert_that(strictly_ordered < double&& >).is().true_();
      assert_that(strictly_ordered<double&>).is().true_();
      assert_that(strictly_ordered<const double&>).is().true_();
      
      assert_that(strictly_ordered<decimal>).is().true_();
      assert_that(strictly_ordered < decimal && >).is().true_();
      assert_that(strictly_ordered<decimal&>).is().true_();
      assert_that(strictly_ordered<const decimal&>).is().true_();
    }
    
    auto test_method_(with_invalid_type) {
      struct my_struct_test {};
      assert_that(strictly_ordered<my_struct_test>).is().false_();
      assert_that(strictly_ordered < my_struct_test && >).is().false_();
      assert_that(strictly_ordered<my_struct_test&>).is().false_();
      assert_that(strictly_ordered<const my_struct_test&>).is().false_();
    }
  };
}
