#include <xtd/reference_wrapper_object>
#include <xtd/null_pointer_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(reference_wrapper_object_tests) {
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::reference_wrapper<int>>(), typeof_<reference_wrapper_object<int>::base_type>());
    }
    
    void test_method_(type) {
      assert::are_equal(typeof_<int>(), typeof_<reference_wrapper_object<int>::type>());
    }
    
    void test_method_(reference_type) {
      assert::are_equal(typeof_<int>(), typeof_<reference_wrapper_object<int>::reference_type>());
    }
    
    void test_method_(empty) {
      assert::is_true(reference_wrapper_object<int>::empty.is_empty());
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<int>::empty.get();});
    }

    void test_method_(create_with_no_param) {
      auto r = reference_wrapper_object<int> {};
      assert::is_true(r.is_empty());
      assert::throws<null_pointer_exception>([&] {r.get();});
    }

    void test_method_(create_with_null) {
      auto r = reference_wrapper_object<int> {null};
      assert::is_true(r.is_empty());
      assert::throws<null_pointer_exception>([&] {r.get();});
    }
    
    void test_method_(create_with_integer) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {i};
      assert::is_false(r.is_empty());
      assert::are_equal(42, r.get());
    }
    
    void test_method_(create_with_empty_reference_wrapper_object) {
      auto r1 = reference_wrapper_object<int> {};
      auto r2 = reference_wrapper_object<int> {r1};
      assert::is_true(r2.is_empty());
      assert::throws<null_pointer_exception>([&] {r2.get();});
    }
    
    void test_method_(create_with_reference_wrapper_object) {
      auto i = 42;
      auto r1 = reference_wrapper_object<int> {i};
      auto r2 = reference_wrapper_object<int> {r1};
      assert::is_false(r1.is_empty());
      assert::is_false(r2.is_empty());
      assert::are_equal(42, r2.get());
    }
    
    void test_method_(create_with_std_reference_wrapper) {
      auto i = 42;
      auto r1 = std::reference_wrapper<int> {i};
      auto r2 = reference_wrapper_object<int> {r1};
      assert::are_equal(42, r1.get());
      assert::is_false(r2.is_empty());
      assert::are_equal(42, r2.get());
    }
    
    void test_method_(create_with_different_type_of_reference_wrapper_object) {
      auto s = string {"value"};
      auto r1 = reference_wrapper_object<string> {s};
      auto r2 = reference_wrapper_object<object> {r1};
      assert::is_false(r1.is_empty());
      assert::is_false(r2.is_empty());
      assert::are_equal("value", r2.get().to_string());
    }
    
    void test_method_(create_with_different_type_of_std_reference_wrapper) {
      auto s = string {"value"};
      auto r1 = std::reference_wrapper<string> {s};
      auto r2 = reference_wrapper_object<object> {r1};
      assert::are_equal("value", r1.get());
      assert::is_false(r2.is_empty());
      assert::are_equal("value", r2.get().to_string());
    }
    
    void test_method_(create_with_moved_reference_wrapper_object) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {reference_wrapper_object<int> {i}};
      assert::is_false(r.is_empty());
      assert::are_equal(42, r.get());
    }
    
    void test_method_(create_with_moved_std_reference_wrapper) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {std::reference_wrapper<int> {i}};
      assert::is_false(r.is_empty());
      assert::are_equal(42, r.get());
    }
    
    void test_method_(create_with_moved_different_type_of_reference_wrapper_object) {
      auto s = string {"value"};
      auto r = reference_wrapper_object<object> {reference_wrapper_object<string> {s}};
      assert::is_false(r.is_empty());
      assert::are_equal("value", r.get().to_string());
    }
    
    void test_method_(create_with_moved_different_type_of_std_reference_wrapper) {
      auto s = string {"value"};
      auto r = reference_wrapper_object<object> {std::reference_wrapper<string> {s}};
      assert::is_false(r.is_empty());
      assert::are_equal("value", r.get().to_string());
    }
    
    void test_method_(is_empty) {
      auto s = string {"value"};
      auto r1 = reference_wrapper_object<string> {};
      auto r2 = reference_wrapper_object<object> {s};
      auto r3 = reference_wrapper_object<object> {r1};
      auto r4 = reference_wrapper_object<object> {r2};

      assert::is_true(reference_wrapper_object<object>::empty.is_empty());
      assert::is_true(r1.is_empty());
      assert::is_false(r2.is_empty());
      assert::is_true(r3.is_empty());
      assert::is_false(r4.is_empty());
    }
    
    /*
    void test_method_(is_unique) {
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<object> {r1};
      auto r3 = reference_wrapper_object<object> {new string {"value"}};
      assert::is_false(r1.is_unique());
      assert::is_false(r2.is_unique());
      assert::is_true(r3.is_unique());
    }

    void test_method_(owner_before) {
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<object> {r1};
      assert::is_false(r1.owner_before(r2));
      assert::is_false(r2.owner_before(r1));
    }
    
    void test_method_(pointer) {
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = r1.pointer();
      assert::are_equal(typeof_<std::reference_wrapper<string>>(), typeof_(r2));
      assert::are_equal(2, r2.use_count());
      assert::is_not_null(r2.get());

      assert::is_null(reference_wrapper_object<string>::empty.pointer().get());
    }
    
    void test_method_(use_count) {
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<object> {r1};
      assert::are_equal(2_z, r1.use_count());
      assert::are_equal(2_z, r2.use_count());
      r2 = null;
      assert::are_equal(1_z, r1.use_count());
      assert::is_zero(r2.use_count());
    }
    
    void test_method_(compare_to) {
      assert::is_zero(reference_wrapper_object<string>::empty.compare_to(reference_wrapper_object<string>::empty));
      assert::is_negative(reference_wrapper_object<string>::empty.compare_to(reference_wrapper_object<string> {new string {"value"}}));
      assert::is_positive(reference_wrapper_object<string> {new string {"value"}}.compare_to(reference_wrapper_object<string>::empty));

      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<string> {new string {"value"}};

      assert::is_zero(r1.compare_to(r1));
      assert::is_zero(r2.compare_to(r2));
      // -> Not sure to keep the next two tests because the memory allocation order is not predictive...
      //assert::is_positive(r1.compare_to(r2));
      //assert::is_negative(r2.compare_to(r1));
      // <-
    }
    
    void test_method_(equals) {
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<string> {new string {"value"}};
      auto r3 = reference_wrapper_object<string> {r1};
      auto r4 = reference_wrapper_object<string> {r2};
      
      assert::is_true(r1.equals(r1));
      assert::is_false(r1.equals(r2));
      assert::is_true(r1.equals(r3));
      assert::is_false(r1.equals(r4));
      assert::is_true(r2.equals(r4));
    }

    void test_method_(equals_with_object) {
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<string> {new string {"value"}};
      auto r3 = reference_wrapper_object<string> {r1};
      auto r4 = reference_wrapper_object<string> {r2};
      
      auto& o1 = dynamic_cast<object&>(r1);
      auto& o2 = dynamic_cast<object&>(r2);
      auto& o3 = dynamic_cast<object&>(r3);
      auto& o4 = dynamic_cast<object&>(r4);
      
      assert::is_true(r1.equals(o1));
      assert::is_false(r1.equals(o2));
      assert::is_true(r1.equals(o3));
      assert::is_false(r1.equals(o4));
      assert::is_true(r2.equals(o4));
    }
    
    void test_method_(get) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto r1 = reference_wrapper_object<string> {p1};
      auto r2 = reference_wrapper_object<string> {p2};
      auto r3 = r1;
      auto r4 = r2;

      assert::is_null(reference_wrapper_object<int>::empty.get());
      assert::are_equal(p1, r1.get());
      assert::are_equal(p2, r2.get());
      assert::are_equal(r3.get(), r1.get());
      assert::are_not_equal(r2.get(), r1.get());
      assert::are_not_equal(r3.get(), r2.get());
      assert::are_equal(r4.get(), r2.get());
    }
    
    void test_method_(get_hash_code) {
      assert::is_zero(reference_wrapper_object<int>::empty.get_hash_code());
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<string> {new string {"value"}};
      auto r3 = reference_wrapper_object<string> {new string {"other"}};
      auto r4 = reference_wrapper_object<string> {new string {"other"}};
      assert::are_equal(hash_code::combine(r1.to_pointer()), r1.get_hash_code());
      assert::are_not_equal(r2.get_hash_code(), r1.get_hash_code());
      assert::are_not_equal(r3.get_hash_code(), r1.get_hash_code());
      assert::are_not_equal(r4.get_hash_code(), r1.get_hash_code());
      assert::are_not_equal(r4.get_hash_code(), r3.get_hash_code());
    }
    
    void test_method_(reset) {
      auto p = new string {"value"};
      auto r = reference_wrapper_object<string> {p};
      assert::are_equal(p, r.get());
      r.reset();
      assert::is_null(r.get());
    }
    
    void test_method_(reset_with_pointer) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto r1 = reference_wrapper_object<string> {p1};
      assert::are_equal(p1, r1.get());
      r1.reset(p2);
      assert::are_equal(p2, r1.get());
    }
    
    void test_method_(reset_with_null) {
      auto p = new string {"value"};
      auto r = reference_wrapper_object<string> {p};
      assert::are_equal(p, r.get());
      r.reset(null);
      assert::is_null(r.get());
    }

    void test_method_(swap) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto r1 = reference_wrapper_object<string> {p1};
      auto r2 = reference_wrapper_object<string> {p2};
      assert::are_equal(p1, r1.get());
      assert::are_equal(p2, r2.get());
      r1.swap(r2);
      assert::are_equal(p2, r1.get());
      assert::are_equal(p1, r2.get());
    }
    
    void test_method_(to_object) {
      assert::are_equal("value", reference_wrapper_object<string> {new string {"value"}}.to_object());
      assert::are_equal(42, reference_wrapper_object<int> {new int {42}}.to_object());
    }
    
    void test_method_(to_object_with_specified_type) {
      assert::are_equal("value", reference_wrapper_object<object> {new string {"value"}}.to_object<string>());
      assert::are_equal(42, reference_wrapper_object<int> {new int {42}}.to_object<byte>());
      assert::throws<null_pointer_exception>([]{reference_wrapper_object<object> {}.to_object<string>();});
    }
    
    void test_method_(to_pointer) {
      assert::are_equal("value", *reference_wrapper_object<string> {new string {"value"}}.to_pointer());
      assert::are_equal(42, *reference_wrapper_object<int> {new int {42}}.to_pointer());
    }
    
    void test_method_(to_pointer_with_specified_type) {
      assert::are_equal("value", *reference_wrapper_object<object> {new string {"value"}}.to_pointer<string>());
      //assert::are_equal(42, *reference_wrapper_object<int> {new int {42}}.to_pointer<byte>());
      assert::is_null(reference_wrapper_object<object> {}.to_pointer<string>());
    }
    
    void test_method_(to_string) {
      assert::are_equal("xtd::reference_wrapper_object<xtd::object> [pointer=null]", reference_wrapper_object<object> {}.to_string());
      string_assert::starts_with("xtd::reference_wrapper_object<int> [pointer=0x", reference_wrapper_object<int> {new int {42}}.to_string());
      string_assert::ends_with(", use_count=1]", reference_wrapper_object<int> {new int {42}}.to_string());
      auto r1 = reference_wrapper_object<int> {new int {42}};
      auto r2 = r1, r3 = r1, r4 = r1;
      string_assert::ends_with(", use_count=4]", r1.to_string());
    }
    
    void test_method_(assignment_operator_with_reference_wrapper_object) {
      auto r1 = reference_wrapper_object<int> {new int {42}};
      auto r2 = reference_wrapper_object<int> {};
      r2 = r1;
      assert::are_equal(r1.to_pointer(), r2.to_pointer());
      assert::are_equal(2_z, r2.use_count());
    }
    
    void test_method_(assignment_operator_with_moved_reference_wrapper_object) {
      auto r = reference_wrapper_object<int> {};
      s = reference_wrapper_object<int> {new int {42}};
      assert::is_not_null(r.to_pointer());
      assert::are_equal(1_z, r.use_count());
    }
    
    void test_method_(assignment_operator_with_reference_wrapper_object_and_different_type) {
      auto r1 = reference_wrapper_object<string> {new string {"value"}};
      auto r2 = reference_wrapper_object<object> {};
      r2 = r1;
      assert::are_equal(r1.to_pointer(), r2.to_pointer());
      assert::are_equal(2_z, r2.use_count());
    }
    
    void test_method_(assignment_operator_with_moved_reference_wrapper_object_and_different_type) {
      auto r = reference_wrapper_object<object> {};
      s = reference_wrapper_object<string> {new string {"value"}};
      assert::is_not_null(r.to_pointer());
      assert::are_equal(1_z, r.use_count());
    }
    
    void test_method_(assignment_operator_with_std_reference_wrapper) {
      auto r1 = std::reference_wrapper<int> {new int {42}};
      auto r2 = reference_wrapper_object<int> {};
      r2 = r1;
      assert::are_equal(r1.operator ->(), r2.to_pointer());
      assert::are_equal(2_z, r2.use_count());
    }
    
    void test_method_(assignment_operator_with_moved_std_reference_wrapper) {
      auto r = reference_wrapper_object<int> {};
      s = std::reference_wrapper<int> {new int {42}};
      assert::is_not_null(r.to_pointer());
      assert::are_equal(1_z, r.use_count());
    }
    
    void test_method_(object_operator) {
      assert::are_equal("value", *reference_wrapper_object<string> {new string {"value"}});
      assert::are_equal(42, *reference_wrapper_object<int> {new int {42}});
    }
    
    void test_method_(bool_operator) {
      assert::is_false(!reference_wrapper_object<string> {new string {"value"}});
      assert::is_true(!reference_wrapper_object<string> {});
    }
    
    void test_method_(base_type_operator) {
      auto r = std::reference_wrapper<int> {};
      s = reference_wrapper_object<int> {new int {42}};
      assert::is_not_null(r.operator ->());
      assert::are_equal(1, r.use_count());
    }
     */
  };
}
