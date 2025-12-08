#include <xtd/shared_ptr_object>
#include <xtd/null_pointer_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(shared_ptr_object_tests) {
    auto test_method_(base_type) {
      assert::are_equal(typeof_<std::shared_ptr<int>>(), typeof_<shared_ptr_object<int>::base_type > ());
    }
    
    auto test_method_(element_type) {
      assert::are_equal(typeof_<int>(), typeof_<shared_ptr_object<int>::element_type>());
      // Does not build oon Windows
      //assert::are_equal(typeof_<int>(), typeof_<shared_ptr_object<int[]>::element_type>());
    }
    
    auto test_method_(weak_type) {
      assert::are_equal(typeof_<std::weak_ptr<int>>(), typeof_<shared_ptr_object<int>::weak_type > ());
    }
    
    auto test_method_(empty) {
      assert::is_zero(shared_ptr_object<int>::empty.use_count());
      assert::is_null(shared_ptr_object<int>::empty.get());
    }
    
    auto test_method_(create_with_no_param) {
      auto s = shared_ptr_object<int> {};
      assert::is_zero(s.use_count());
      assert::is_null(s.get());
    }
    
    auto test_method_(create_with_null) {
      auto s = shared_ptr_object<int> {null};
      assert::is_zero(s.use_count());
      assert::is_null(s.get());
    }
    
    auto test_method_(create_with_pointer) {
      auto s = shared_ptr_object<int> {new int {42}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    auto test_method_(create_with_empty_shared_ptr_object) {
      auto s1 = shared_ptr_object<int> {};
      auto s2 = shared_ptr_object<int> {s1};
      assert::is_zero(s2.use_count());
      assert::is_null(s2.get());
    }
    
    auto test_method_(create_with_empty_std_shared_ptr) {
      auto s1 = std::shared_ptr<int> {};
      auto s2 = shared_ptr_object<int> {s1};
      assert::is_zero(s2.use_count());
      assert::is_null(s2.get());
    }
    
    auto test_method_(create_with_shared_ptr_object) {
      auto s1 = shared_ptr_object<int> {new int {42}};
      auto s2 = shared_ptr_object<int> {s1};
      assert::are_equal(2_z, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }
    
    auto test_method_(create_with_std_shared_ptr) {
      auto s1 = std::shared_ptr<int> {new int {42}};
      auto s2 = shared_ptr_object<int> {s1};
      assert::are_equal(2, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }
    
    auto test_method_(create_with_different_type_of_shared_ptr_object) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::are_equal(2_z, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }
    
    auto test_method_(create_with_different_type_of_std_shared_ptr) {
      auto s1 = std::shared_ptr<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::are_equal(2, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      assert::is_not_null(s2.get());
    }
    
    auto test_method_(create_with_moved_shared_ptr_object) {
      auto s = shared_ptr_object<int> {shared_ptr_object<int> {new int {42}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    auto test_method_(create_with_moved_std_shared_ptr) {
      auto s = shared_ptr_object<int> {std::shared_ptr<int> {new int {42}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    auto test_method_(create_with_moved_different_type_of_shared_ptr_object) {
      auto s = shared_ptr_object<object> {shared_ptr_object<string> {new string {"value"}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    auto test_method_(create_with_moved_different_type_of_std_shared_ptr) {
      auto s = shared_ptr_object<object> {std::shared_ptr<string> {new string {"value"}}};
      assert::are_equal(1_z, s.use_count());
      assert::is_not_null(s.get());
    }
    
    auto test_method_(is_unique) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      auto s3 = shared_ptr_object<object> {new string {"value"}};
      assert::is_false(s1.is_unique());
      assert::is_false(s2.is_unique());
      assert::is_true(s3.is_unique());
    }
    
    auto test_method_(owner_before) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::is_false(s1.owner_before(s2));
      assert::is_false(s2.owner_before(s1));
    }
    
    auto test_method_(pointer) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = s1.pointer();
      assert::are_equal(typeof_<std::shared_ptr<string>>(), typeof_(s2));
      assert::are_equal(2, s2.use_count());
      assert::is_not_null(s2.get());
      
      assert::is_null(shared_ptr_object<string>::empty.pointer().get());
    }
    
    auto test_method_(use_count) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {s1};
      assert::are_equal(2_z, s1.use_count());
      assert::are_equal(2_z, s2.use_count());
      s2 = null;
      assert::are_equal(1_z, s1.use_count());
      assert::is_zero(s2.use_count());
    }
    
    auto test_method_(compare_to) {
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
    
    auto test_method_(equals) {
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
    
    auto test_method_(equals_with_object) {
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
    
    auto test_method_(get) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto s1 = shared_ptr_object<string> {p1};
      auto s2 = shared_ptr_object<string> {p2};
      auto s3 = s1;
      auto s4 = s2;
      
      assert::is_null(shared_ptr_object<int>::empty.get());
      assert::are_equal(p1, s1.get());
      assert::are_equal(p2, s2.get());
      assert::are_equal(s3.get(), s1.get());
      assert::are_not_equal(s2.get(), s1.get());
      assert::are_not_equal(s3.get(), s2.get());
      assert::are_equal(s4.get(), s2.get());
    }
    
    auto test_method_(get_hash_code) {
      assert::is_zero(shared_ptr_object<int>::empty.get_hash_code());
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<string> {new string {"value"}};
      auto s3 = shared_ptr_object<string> {new string {"other"}};
      auto s4 = shared_ptr_object<string> {new string {"other"}};
      assert::are_equal(hash_code::combine(s1.to_pointer()), s1.get_hash_code());
      assert::are_not_equal(s2.get_hash_code(), s1.get_hash_code());
      assert::are_not_equal(s3.get_hash_code(), s1.get_hash_code());
      assert::are_not_equal(s4.get_hash_code(), s1.get_hash_code());
      assert::are_not_equal(s4.get_hash_code(), s3.get_hash_code());
    }
    
    auto test_method_(reset) {
      auto p = new string {"value"};
      auto s = shared_ptr_object<string> {p};
      assert::are_equal(p, s.get());
      s.reset();
      assert::is_null(s.get());
    }
    
    auto test_method_(reset_with_pointer) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto s1 = shared_ptr_object<string> {p1};
      assert::are_equal(p1, s1.get());
      s1.reset(p2);
      assert::are_equal(p2, s1.get());
    }
    
    auto test_method_(reset_with_null) {
      auto p = new string {"value"};
      auto s = shared_ptr_object<string> {p};
      assert::are_equal(p, s.get());
      s.reset(null);
      assert::is_null(s.get());
    }
    
    auto test_method_(swap) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto s1 = shared_ptr_object<string> {p1};
      auto s2 = shared_ptr_object<string> {p2};
      assert::are_equal(p1, s1.get());
      assert::are_equal(p2, s2.get());
      s1.swap(s2);
      assert::are_equal(p2, s1.get());
      assert::are_equal(p1, s2.get());
    }
    
    auto test_method_(to_object) {
      assert::are_equal("value", shared_ptr_object<string> {new string {"value"}}.to_object());
      assert::are_equal(42, shared_ptr_object<int> {new int {42}}.to_object());
    }
    
    auto test_method_(to_object_with_specified_type) {
      assert::are_equal("value", shared_ptr_object<object> {new string {"value"}}.to_object<string>());
      assert::are_equal(42, shared_ptr_object<int> {new int {42}}.to_object<byte>());
      assert::throws<null_pointer_exception>([] {shared_ptr_object<object> {}.to_object<string>();});
    }
    
    auto test_method_(to_pointer) {
      assert::are_equal("value", *shared_ptr_object<string> {new string {"value"}}.to_pointer());
      assert::are_equal(42, *shared_ptr_object<int> {new int {42}}.to_pointer());
    }
    
    auto test_method_(to_pointer_with_specified_type) {
      assert::are_equal("value", *shared_ptr_object<object> {new string {"value"}}.to_pointer<string>());
      //assert::are_equal(42, *shared_ptr_object<int> {new int {42}}.to_pointer<byte>());
      assert::is_null(shared_ptr_object<object> {}.to_pointer<string>());
    }
    
    auto test_method_(to_string) {
      assert::are_equal("xtd::shared_ptr_object<xtd::object> [pointer=null]", shared_ptr_object<object> {}.to_string());
      string_assert::starts_with("xtd::shared_ptr_object<int> [pointer=0x", shared_ptr_object<int> {new int {42}}.to_string());
      string_assert::ends_with(", use_count=1]", shared_ptr_object<int> {new int {42}}.to_string());
      auto s1 = shared_ptr_object<int> {new int {42}};
      auto s2 = s1, s3 = s1, s4 = s1;
      string_assert::ends_with(", use_count=4]", s1.to_string());
    }
    
    auto test_method_(assignment_operator_with_shared_ptr_object) {
      auto s1 = shared_ptr_object<int> {new int {42}};
      auto s2 = shared_ptr_object<int> {};
      s2 = s1;
      assert::are_equal(s1.to_pointer(), s2.to_pointer());
      assert::are_equal(2_z, s2.use_count());
    }
    
    auto test_method_(assignment_operator_with_moved_shared_ptr_object) {
      auto s = shared_ptr_object<int> {};
      s = shared_ptr_object<int> {new int {42}};
      assert::is_not_null(s.to_pointer());
      assert::are_equal(1_z, s.use_count());
    }
    
    auto test_method_(assignment_operator_with_shared_ptr_object_and_different_type) {
      auto s1 = shared_ptr_object<string> {new string {"value"}};
      auto s2 = shared_ptr_object<object> {};
      s2 = s1;
      assert::are_equal(s1.to_pointer(), s2.to_pointer());
      assert::are_equal(2_z, s2.use_count());
    }
    
    auto test_method_(assignment_operator_with_moved_shared_ptr_object_and_different_type) {
      auto s = shared_ptr_object<object> {};
      s = shared_ptr_object<string> {new string {"value"}};
      assert::is_not_null(s.to_pointer());
      assert::are_equal(1_z, s.use_count());
    }
    
    auto test_method_(assignment_operator_with_std_shared_ptr) {
      auto s1 = std::shared_ptr<int> {new int {42}};
      auto s2 = shared_ptr_object<int> {};
      s2 = s1;
      assert::are_equal(s1.operator ->(), s2.to_pointer());
      assert::are_equal(2_z, s2.use_count());
    }
    
    auto test_method_(assignment_operator_with_moved_std_shared_ptr) {
      auto s = shared_ptr_object<int> {};
      s = std::shared_ptr<int> {new int {42}};
      assert::is_not_null(s.to_pointer());
      assert::are_equal(1_z, s.use_count());
    }
    
    auto test_method_(object_operator) {
      assert::are_equal("value", *shared_ptr_object<string> {new string {"value"}});
      assert::are_equal(42, *shared_ptr_object<int> {new int {42}});
    }
    
    auto test_method_(bool_operator) {
      assert::is_false(!shared_ptr_object<string> {new string {"value"}});
      assert::is_true(!shared_ptr_object<string> {});
    }
    
    auto test_method_(base_type_operator) {
      auto s = std::shared_ptr<int> {};
      s = shared_ptr_object<int> {new int {42}};
      assert::is_not_null(s.operator ->());
      assert::are_equal(1, s.use_count());
    }
  };
}
