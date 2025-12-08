#include <xtd/unique_ptr_object>
#include <xtd/null_pointer_exception>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(unique_ptr_object_tests) {
    auto test_method_(base_type) {
      assert::are_equal(typeof_<std::unique_ptr<int>>(), typeof_<unique_ptr_object<int>::base_type > ());
    }
    
    auto test_method_(deleter_type) {
      assert::are_equal(typeof_<std::default_delete<int>>(), typeof_<unique_ptr_object<int>::deleter_type > ());
    }
    
    auto test_method_(element_type) {
      assert::are_equal(typeof_<int>(), typeof_<unique_ptr_object<int>::element_type>());
      // Does not build oon Windows
      //assert::are_equal(typeof_<int>(), typeof_<unique_ptr_object<int[]>::element_type>());
    }
    
    auto test_method_(pointer_type) {
      assert::are_equal(typeof_<int*>(), typeof_<unique_ptr_object<int>::pointer_type>());
    }
    
    auto test_method_(empty) {
      assert::is_null(unique_ptr_object<int>::empty.get());
    }
    
    auto test_method_(create_with_no_param) {
      auto s = unique_ptr_object<int> {};
      assert::is_null(s.get());
    }
    
    auto test_method_(create_with_null) {
      auto s = unique_ptr_object<int> {null};
      assert::is_null(s.get());
    }
    
    auto test_method_(create_with_pointer) {
      auto p = new int {42};
      auto s = unique_ptr_object<int> {p};
      assert::are_equal(p, s.get());
    }
    
    auto test_method_(create_with_empty_unique_ptr_object) {
      auto s = unique_ptr_object<int> {unique_ptr_object<int> {}};
      assert::is_null(s.get());
    }
    
    auto test_method_(create_with_empty_std_unique_ptr) {
      auto s = unique_ptr_object<int> {std::unique_ptr<int> {}};
      assert::is_null(s.get());
    }
    
    auto test_method_(create_with_unique_ptr_object) {
      auto p = new int {42};
      auto s = unique_ptr_object<int> {unique_ptr_object<int> {p}};
      assert::are_equal(p, s.get());
    }
    
    auto test_method_(create_with_std_unique_ptr) {
      auto p = new int {42};
      auto s = unique_ptr_object<int> {std::unique_ptr<int> {p}};
      assert::are_equal(p, s.get());
    }
    
    auto test_method_(create_with_different_type_of_unique_ptr_object) {
      auto p = new string {"value"};
      auto s = unique_ptr_object<object> {unique_ptr_object<string> {p}};
      assert::are_equal(p, s.get());
    }
    
    auto test_method_(create_with_different_type_of_std_unique_ptr) {
      auto p = new string {"value"};
      auto s = unique_ptr_object<object> {std::unique_ptr<string> {p}};
      assert::are_equal(p, s.get());
    }
    
    auto test_method_(pointer) {
      auto p = new string {"value"};
      auto s1 = unique_ptr_object<string> {p};
      auto s2 = std::move(s1.pointer());
      assert::are_equal(typeof_<std::unique_ptr<string>>(), typeof_(s2));
      assert::are_equal(p, s2.get());
    }
    
    auto test_method_(compare_to) {
      assert::is_zero(unique_ptr_object<string>::empty.compare_to(unique_ptr_object<string>::empty));
      assert::is_negative(unique_ptr_object<string>::empty.compare_to(unique_ptr_object<string> {new string {"value"}}));
      assert::is_positive(unique_ptr_object<string> {new string {"value"}}.compare_to(unique_ptr_object<string>::empty));
      
      auto s1 = unique_ptr_object<string> {new string {"value"}};
      auto s2 = unique_ptr_object<string> {new string {"value"}};
      
      assert::is_zero(s1.compare_to(s1));
      assert::is_zero(s2.compare_to(s2));
      // -> Not sure to keep the next two tests because the memory allocation order is not predictive...
      //assert::is_positive(s1.compare_to(s2));
      //assert::is_negative(s2.compare_to(s1));
      // <-
    }
    
    auto test_method_(equals) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto s1 = unique_ptr_object<string> {p1};
      auto s2 = unique_ptr_object<string> {p2};
      auto& s3 = s1;
      auto& s4 = s2;
      
      assert::is_true(s1.equals(s1));
      assert::is_false(s1.equals(s2));
      assert::is_true(s1.equals(s3));
      assert::is_false(s1.equals(s4));
      assert::is_true(s2.equals(s4));
    }
    
    auto test_method_(equals_with_object) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto s1 = unique_ptr_object<string> {p1};
      auto s2 = unique_ptr_object<string> {p2};
      auto& s3 = s1;
      auto& s4 = s2;
      
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
      auto s1 = unique_ptr_object<string> {p1};
      auto s2 = unique_ptr_object<string> {p2};
      auto& s3 = s1;
      auto& s4 = s2;
      
      assert::is_null(unique_ptr_object<int>::empty.get());
      assert::are_equal(p1, s1.get());
      assert::are_equal(p2, s2.get());
      assert::are_equal(s3.get(), s1.get());
      assert::are_not_equal(s2.get(), s1.get());
      assert::are_not_equal(s3.get(), s2.get());
      assert::are_equal(s4.get(), s2.get());
    }
    
    auto test_method_(get_hash_code) {
      assert::is_zero(unique_ptr_object<int>::empty.get_hash_code());
      auto s1 = unique_ptr_object<string> {new string {"value"}};
      auto s2 = unique_ptr_object<string> {new string {"value"}};
      auto s3 = unique_ptr_object<string> {new string {"other"}};
      auto s4 = unique_ptr_object<string> {new string {"other"}};
      assert::are_equal(hash_code::combine(s1.to_pointer()), s1.get_hash_code());
      assert::are_not_equal(s2.get_hash_code(), s1.get_hash_code());
      assert::are_not_equal(s3.get_hash_code(), s1.get_hash_code());
      assert::are_not_equal(s4.get_hash_code(), s1.get_hash_code());
      assert::are_not_equal(s4.get_hash_code(), s3.get_hash_code());
    }
    
    auto test_method_(release) {
      auto p1 = new string {"value"};
      auto s1 = unique_ptr_object<string> {p1};
      assert::are_equal(p1, s1.get());
      auto p2 = s1.release();
      assert::is_null(s1.get());
      assert::are_equal(p1, p2);
      delete p2;
    }
    
    auto test_method_(reset) {
      auto p = new string {"value"};
      auto s = unique_ptr_object<string> {p};
      assert::are_equal(p, s.get());
      s.reset();
      assert::is_null(s.get());
    }
    
    auto test_method_(reset_with_pointer) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto s1 = unique_ptr_object<string> {p1};
      assert::are_equal(p1, s1.get());
      s1.reset(p2);
      assert::are_equal(p2, s1.get());
    }
    
    auto test_method_(reset_with_null) {
      auto p = new string {"value"};
      auto s = unique_ptr_object<string> {p};
      assert::are_equal(p, s.get());
      s.reset(null);
      assert::is_null(s.get());
    }
    
    auto test_method_(swap) {
      auto p1 = new string {"value"};
      auto p2 = new string {"value"};
      auto s1 = unique_ptr_object<string> {p1};
      auto s2 = unique_ptr_object<string> {p2};
      assert::are_equal(p1, s1.get());
      assert::are_equal(p2, s2.get());
      s1.swap(s2);
      assert::are_equal(p2, s1.get());
      assert::are_equal(p1, s2.get());
    }
    
    auto test_method_(to_object) {
      assert::are_equal("value", unique_ptr_object<string> {new string {"value"}}.to_object());
      assert::are_equal(42, unique_ptr_object<int> {new int {42}}.to_object());
    }
    
    auto test_method_(to_object_with_specified_type) {
      assert::are_equal("value", unique_ptr_object<object> {new string {"value"}}.to_object<string>());
      assert::are_equal(42, unique_ptr_object<int> {new int {42}}.to_object<byte>());
      assert::throws<null_pointer_exception>([] {unique_ptr_object<object> {}.to_object<string>();});
    }
    
    auto test_method_(to_pointer) {
      assert::are_equal("value", *unique_ptr_object<string> {new string {"value"}}.to_pointer());
      assert::are_equal(42, *unique_ptr_object<int> {new int {42}}.to_pointer());
    }
    
    auto test_method_(to_pointer_with_specified_type) {
      assert::are_equal("value", *unique_ptr_object<object> {new string {"value"}}.to_pointer<string>());
      //assert::are_equal(42, *unique_ptr_object<int> {new int {42}}.to_pointer<byte>());
      assert::is_null(unique_ptr_object<object> {}.to_pointer<string>());
    }
    
    auto test_method_(to_string) {
      if (environment::os_version().is_windows()) assert::are_equal("xtd::unique_ptr_object<xtd::object,std::default_delete<xtd::object> > [pointer=null]", unique_ptr_object<object> {}.to_string());
      else if (environment::os_version().is_macos()) assert::are_equal("xtd::unique_ptr_object<xtd::object, std::default_delete<xtd::object>> [pointer=null]", unique_ptr_object<object> {}.to_string());
      else if (environment::os_version().is_linux()) assert::are_equal("xtd::unique_ptr_object<xtd::object, std::default_delete<xtd::object> > [pointer=null]", unique_ptr_object<object> {}.to_string());
      if (environment::os_version().is_windows())  string_assert::starts_with("xtd::unique_ptr_object<int,std::default_delete<int> > [pointer=0x", unique_ptr_object<int> {new int {42}}.to_string());
      else if (environment::os_version().is_macos())  string_assert::starts_with("xtd::unique_ptr_object<int, std::default_delete<int>> [pointer=0x", unique_ptr_object<int> {new int {42}}.to_string());
      else if (environment::os_version().is_linux())  string_assert::starts_with("xtd::unique_ptr_object<int, std::default_delete<int> > [pointer=0x", unique_ptr_object<int> {new int {42}}.to_string());
      string_assert::ends_with("]", unique_ptr_object<int> {new int {42}}.to_string());
    }
    
    auto test_method_(assignment_operator_with_moved_unique_ptr_object) {
      auto s = unique_ptr_object<int> {};
      s = unique_ptr_object<int> {new int {42}};
      assert::is_not_null(s.to_pointer());
    }
    
    auto test_method_(assignment_operator_with_moved_unique_ptr_object_and_different_type) {
      auto s = unique_ptr_object<object> {};
      s = unique_ptr_object<string> {new string {"value"}};
      assert::is_not_null(s.to_pointer());
    }
    
    auto test_method_(assignment_operator_with_moved_std_unique_ptr) {
      auto s = unique_ptr_object<int> {};
      s = std::unique_ptr<int> {new int {42}};
      assert::is_not_null(s.to_pointer());
    }
    
    auto test_method_(object_operator) {
      assert::are_equal("value", *unique_ptr_object<string> {new string {"value"}});
      assert::are_equal(42, *unique_ptr_object<int> {new int {42}});
    }
    
    auto test_method_(bool_operator) {
      assert::is_false(!unique_ptr_object<string> {new string {"value"}});
      assert::is_true(!unique_ptr_object<string> {});
    }
  };
}
