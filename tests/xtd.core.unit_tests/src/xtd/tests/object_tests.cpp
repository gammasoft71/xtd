#include <xtd/object>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(object_tests) {
    auto test_method_(equals_with_another_object) {
      assert::is_false(object().equals(object()));
    }
    
    auto test_method_(equals_with_same_object) {
      object object1;
      object& object2 = object1;
      assert::is_true(object1.equals(object2));
    }
    
    auto test_method_(equals_on_different_objects) {
      assert::is_false(object::equals(object(), object()));
    }
    
    auto test_method_(equals_on_same_objects) {
      object object1;
      assert::is_true(object::equals(object1, object1));
    }
    
    auto test_method_(get_type_on_object) {
      //assert::are_equal("xtd::object", object().get_type().full_name());
    }
    
    auto test_method_(memberwise_clone_on_object) {
      xtd::sptr<object> obj = xtd::new_sptr<object>();
      auto cloned_obj = obj->memberwise_clone<object>();
      assert::is_false(obj->equals(*cloned_obj));
    }
    
    auto test_method_(reference_equals_on_different_objects) {
      object object1;
      object& object2 = object1;
      assert::is_false(object::reference_equals(object(), object2));
    }
    
    auto test_method_(reference_equals_on_same_objects) {
      object object1;
      object& object2 = object1;
      assert::is_true(object::reference_equals(object1, object2));
      
    }
    
    auto test_method_(reference_equals_on_two_different_objects) {
      object object1;
      object object4;
      assert::is_false(object::reference_equals(object1, object4));
    }
    
    auto test_method_(object_to_string) {
      assert::are_equal("xtd::object", object().to_string());
    }
  };
}
