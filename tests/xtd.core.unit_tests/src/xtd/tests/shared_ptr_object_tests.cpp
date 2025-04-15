#include <xtd/shared_ptr_object>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(shared_ptr_object_tests) {
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::shared_ptr<int>>(), typeof_<shared_ptr_object<int>::base_type>());
    }
    
    void test_method_(element_type) {
      assert::are_equal(typeof_<int>(), typeof_<shared_ptr_object<int>::element_type>());
      assert::are_equal(typeof_<int>(), typeof_<shared_ptr_object<int[]>::element_type>());
    }
    
    void test_method_(weak_type) {
      assert::are_equal(typeof_<std::weak_ptr<int>>(), typeof_<shared_ptr_object<int>::weak_type>());
    }
    
    void test_method_(empty) {
      assert::is_zero(shared_ptr_object<int>::empty.use_count());
      assert::is_null(shared_ptr_object<int>::empty.get());
    }

    void test_method_(create_with_no_param) {
      auto s = shared_ptr_object<int> {};
      assert::is_zero(s.use_count());
      assert::is_null(s.get());
    }

    void test_method_(create_with_null) {
      auto s = shared_ptr_object<int> {null};
      assert::is_zero(s.use_count());
      assert::is_null(s.get());
    }

    void test_method_(create_with_pointer) {
      auto s = shared_ptr_object<int> {new int {42}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }

    void test_method_(create_with_empty_shared_ptr_object) {
      auto s1 = shared_ptr_object<int> {};
      auto s2 = shared_ptr_object<int> {s1};
      assert::is_zero(s2.use_count());
      assert::is_null(s2.get());
    }

    void test_method_(create_with_empty_std_shared_ptr) {
      auto s1 = std::shared_ptr<int> {};
      auto s2 = shared_ptr_object<int> {s1};
      assert::is_zero(s2.use_count());
      assert::is_null(s2.get());
    }

    void test_method_(create_with_shared_ptr_object) {
      auto s1 = shared_ptr_object<int> {new int {42}};
      auto s2 = shared_ptr_object<int> {s1};
      assert::are_equal(2_z, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }

    void test_method_(create_with_std_shared_ptr) {
      auto s1 = std::shared_ptr<int> {new int {42}};
      auto s2 = shared_ptr_object<int> {s1};
      assert::are_equal(2, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }

    void test_method_(create_with_different_type_of_shared_ptr_object) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::are_equal(2_z, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }

    void test_method_(create_with_different_type_of_std_shared_ptr) {
      auto s1 = std::shared_ptr<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::are_equal(2, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }

    void test_method_(create_with_moved_shared_ptr_object) {
      auto s = shared_ptr_object<int> {shared_ptr_object<int> {new int {42}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    void test_method_(create_with_moved_std_shared_ptr) {
      auto s = shared_ptr_object<int> {std::shared_ptr<int> {new int {42}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }

    void test_method_(create_with_moved_different_type_of_shared_ptr_object) {
      auto s = shared_ptr_object<object> {shared_ptr_object<string> {new string {"value"}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    void test_method_(create_with_moved_different_type_of_std_shared_ptr) {
      auto s = shared_ptr_object<object> {std::shared_ptr<string> {new string {"value"}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    void test_method_(is_unique) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      auto s3 = shared_ptr_object<object> {new string {"value"}};
      assert::is_false(s1.is_unique());
      assert::is_false(s2.is_unique());
      assert::is_true(s3.is_unique());
    }

    void test_method_(owner_before) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::is_false(s1.owner_before(s2));
      assert::is_false(s2.owner_before(s1));
    }
    
    void test_method_(pointer) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = s1.pointer();
      assert::are_equal(typeof_<std::shared_ptr<string>>(), typeof_(s2));
      assert::are_equal(2, s2.use_count());
      assert::is_not_null(s2.get());

      assert::is_null(shared_ptr_object<string>::empty.pointer().get());
    }
    
    void test_method_(use_count) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::are_equal(2_z, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      s2 = null;
      assert::are_equal(1_z, s1.use_count());
      assert::is_zero(s2.use_count());
    }
    
    void test_method_(compare_to) {
      assert::is_zero(shared_ptr_object<string>::empty.compare_to(shared_ptr_object<string>::empty));
      assert::is_negative(shared_ptr_object<string>::empty.compare_to(shared_ptr_object<string> {new string {"value"}}));
      assert::is_positive(shared_ptr_object<string> {new string {"value"}}.compare_to(shared_ptr_object<string>::empty));

      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<string> {new string {"value"}};

      assert::is_zero(s1.compare_to(s1));
      assert::is_zero(s2.compare_to(s2));
      // -> Not sure to keep the next two tests because the memory allocation order is not predictive...
      //assert::is_positive(s1.compare_to(s2));
      //assert::is_negative(s2.compare_to(s1));
      // <-
    }
    
    void test_method_(equals) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<string> {new string {"value"}};
      auto s3 = shared_ptr_object<string> {s1};
      auto s4 = shared_ptr_object<string> {s2};
      
      assert::is_true(s1.equals(s1));
      assert::is_false(s1.equals(s2));
      assert::is_true(s1.equals(s3));
      assert::is_false(s1.equals(s4));
      assert::is_true(s2.equals(s4));
    }

    void test_method_(equals_with_object) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<string> {new string {"value"}};
      auto s3 = shared_ptr_object<string> {s1};
      auto s4 = shared_ptr_object<string> {s2};
      
      auto& o1 = dynamic_cast<object&>(s1);
      auto& o2 = dynamic_cast<object&>(s2);
      auto& o3 = dynamic_cast<object&>(s3);
      auto& o4 = dynamic_cast<object&>(s4);
      
      assert::is_true(s1.equals(o1));
      assert::is_false(s1.equals(o2));
      assert::is_true(s1.equals(o3));
      assert::is_false(s1.equals(o4));
      assert::is_true(s2.equals(o4));
    }
    
    void test_method_(get) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<string> {new string {"value"}};

      assert::is_null(shared_ptr_object<int>::empty.get());
    }
  };
}
