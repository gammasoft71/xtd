#include <xtd/object.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_object) {
  public:
    void test_method_(equals_with_another_object) {
      assert::is_false_(object().equals(object()));
    }

    void test_method_(equals_with_same_object) {
      object object1;
      object& object2 = object1;
      assert::is_true_(object1.equals(object2));
    }
    
    void test_method_(equals_on_different_objects) {
      assert::is_false_(object::equals(object(), object()));
    }
    
    void test_method_(equals_on_same_objects) {
      object object1;
      assert::is_true_(object::equals(object1, object1));
    }
    
    void test_method_(get_type_on_object) {
      //assert::are_equal_("xtd::object", object().get_type().full_name());
    }
    
    void test_method_(memberwise_clone_on_object) {
      shared_ptr<object> obj = make_shared<object>();
      auto cloned_obj = obj->memberwise_clone<object>();
      assert::is_false_(obj->equals(*cloned_obj));
    }
    
    void test_method_(reference_equals_on_different_objects) {
      object object1;
      object& object2 = object1;
      assert::is_false_(object::reference_equals(object(), object2));
    }
    
    void test_method_(reference_equals_on_same_objects) {
      object object1;
      object& object2 = object1;
      assert::is_true_(object::reference_equals(object1, object2));
      
    }
    
    void test_method_(reference_equals_on_two_different_objects) {
      object object1;
      object object4;
      assert::is_false_(object::reference_equals(object1, object4));
    }
    
    void test_method_(object_to_string) {
      assert::are_equal_("xtd::object", object().to_string());
    }    
  };
}
