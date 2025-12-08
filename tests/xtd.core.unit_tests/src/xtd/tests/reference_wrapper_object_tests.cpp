#include <xtd/reference_wrapper_object>
#include <xtd/null_pointer_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(reference_wrapper_object_tests) {
    auto test_method_(base_type) {
      assert::are_equal(typeof_<std::reference_wrapper<int>>(), typeof_<reference_wrapper_object<int>::base_type > ());
    }
    
    auto test_method_(type) {
      assert::are_equal(typeof_<int>(), typeof_<reference_wrapper_object<int>::type>());
    }
    
    auto test_method_(reference_type) {
      assert::are_equal(typeof_<int>(), typeof_<reference_wrapper_object<int>::reference_type>());
    }
    
    auto test_method_(empty) {
      assert::is_true(reference_wrapper_object<int>::empty.is_empty());
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<int>::empty.get();});
    }
    
    auto test_method_(create_with_no_param) {
      auto r = reference_wrapper_object<int> {};
      assert::is_true(r.is_empty());
      assert::throws<null_pointer_exception>([&] {r.get();});
    }
    
    auto test_method_(create_with_null) {
      auto r = reference_wrapper_object<int> {null};
      assert::is_true(r.is_empty());
      assert::throws<null_pointer_exception>([&] {r.get();});
    }
    
    auto test_method_(create_with_integer) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {i};
      assert::is_false(r.is_empty());
      assert::are_equal(42, r.get());
    }
    
    auto test_method_(create_with_empty_reference_wrapper_object) {
      auto r1 = reference_wrapper_object<int> {};
      auto r2 = reference_wrapper_object<int> {r1};
      assert::is_true(r2.is_empty());
      assert::throws<null_pointer_exception>([&] {r2.get();});
    }
    
    auto test_method_(create_with_reference_wrapper_object) {
      auto i = 42;
      auto r1 = reference_wrapper_object<int> {i};
      auto r2 = reference_wrapper_object<int> {r1};
      assert::is_false(r1.is_empty());
      assert::is_false(r2.is_empty());
      assert::are_equal(42, r2.get());
    }
    
    auto test_method_(create_with_std_reference_wrapper) {
      auto i = 42;
      auto r1 = std::reference_wrapper<int> {i};
      auto r2 = reference_wrapper_object<int> {r1};
      assert::are_equal(42, r1.get());
      assert::is_false(r2.is_empty());
      assert::are_equal(42, r2.get());
    }
    
    auto test_method_(create_with_different_type_of_reference_wrapper_object) {
      auto s = string {"value"};
      auto r1 = reference_wrapper_object<string> {s};
      auto r2 = reference_wrapper_object<object> {r1};
      assert::is_false(r1.is_empty());
      assert::is_false(r2.is_empty());
      assert::are_equal("value", r2.get().to_string());
    }
    
    auto test_method_(create_with_different_type_of_std_reference_wrapper) {
      auto s = string {"value"};
      auto r1 = std::reference_wrapper<string> {s};
      auto r2 = reference_wrapper_object<object> {r1};
      assert::are_equal("value", r1.get());
      assert::is_false(r2.is_empty());
      assert::are_equal("value", r2.get().to_string());
    }
    
    auto test_method_(create_with_moved_reference_wrapper_object) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {reference_wrapper_object<int> {i}};
      assert::is_false(r.is_empty());
      assert::are_equal(42, r.get());
    }
    
    auto test_method_(create_with_moved_std_reference_wrapper) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {std::reference_wrapper<int> {i}};
      assert::is_false(r.is_empty());
      assert::are_equal(42, r.get());
    }
    
    auto test_method_(create_with_moved_different_type_of_reference_wrapper_object) {
      auto s = string {"value"};
      auto r = reference_wrapper_object<object> {reference_wrapper_object<string> {s}};
      assert::is_false(r.is_empty());
      assert::are_equal("value", r.get().to_string());
    }
    
    auto test_method_(create_with_moved_different_type_of_std_reference_wrapper) {
      auto s = string {"value"};
      auto r = reference_wrapper_object<object> {std::reference_wrapper<string> {s}};
      assert::is_false(r.is_empty());
      assert::are_equal("value", r.get().to_string());
    }
    
    auto test_method_(is_empty) {
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
    
    auto test_method_(reference) {
      auto s = string {"value"};
      auto r1 = reference_wrapper_object<string> {s};
      auto r2 = r1.reference();
      assert::are_equal(typeof_<std::reference_wrapper<string>>(), typeof_(r2));
      assert::are_equal("value", r2.get());
      
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<int>::empty.reference();});
    }
    
    auto test_method_(compare_to) {
      assert::is_zero(reference_wrapper_object<string>::empty.compare_to(reference_wrapper_object<string>::empty));
      auto s1 = string {"value"};
      auto s2 = string {"value"};
      assert::is_negative(reference_wrapper_object<string>::empty.compare_to(reference_wrapper_object<string> {s1}));
      assert::is_positive(reference_wrapper_object<string> {s2}.compare_to(reference_wrapper_object<string>::empty));
      
      auto r1 = reference_wrapper_object<string> {s1};
      auto r2 = reference_wrapper_object<string> {s2};
      
      assert::is_zero(r1.compare_to(r1));
      assert::is_zero(r2.compare_to(r2));
      assert::is_not_zero(r1.compare_to(r2));
      assert::is_not_zero(r2.compare_to(r1));
    }
    
    auto test_method_(equals) {
      auto s1 = string {"value"};
      auto s2 = string {"value"};
      auto r1 = reference_wrapper_object<string> {s1};
      auto r2 = reference_wrapper_object<string> {s2};
      auto r3 = reference_wrapper_object<string> {r1};
      auto r4 = reference_wrapper_object<string> {r2};
      
      assert::is_true(r1.equals(r1));
      assert::is_false(r1.equals(r2));
      assert::is_true(r1.equals(r3));
      assert::is_false(r1.equals(r4));
      assert::is_true(r2.equals(r4));
    }
    
    auto test_method_(equals_with_object) {
      auto s1 = string {"value"};
      auto s2 = string {"value"};
      auto r1 = reference_wrapper_object<string> {s1};
      auto r2 = reference_wrapper_object<string> {s2};
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
    
    auto test_method_(get) {
      auto s1 = string {"value"};
      auto s2 = string {"other"};
      auto r1 = reference_wrapper_object<string> {s1};
      auto r2 = reference_wrapper_object<string> {s2};
      auto r3 = r1;
      auto r4 = r2;
      
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<int>::empty.get();});
      assert::are_equal(s1, r1.get());
      assert::are_equal(s2, r2.get());
      assert::are_equal(r3.get(), r1.get());
      assert::are_not_equal(r2.get(), r1.get());
      assert::are_not_equal(r3.get(), r2.get());
      assert::are_equal(r4.get(), r2.get());
    }
    
    auto test_method_(get_hash_code) {
      assert::is_zero(reference_wrapper_object<int>::empty.get_hash_code());
      auto s1 = string {"value"};
      auto s2 = string {"other"};
      auto r1 = reference_wrapper_object<string> {s1};
      auto r2 = reference_wrapper_object<string> {s1};
      auto r3 = reference_wrapper_object<string> {s2};
      auto r4 = reference_wrapper_object<string> {s2};
      assert::are_equal(hash_code::combine(&r1.reference()), r1.get_hash_code());
      assert::are_not_equal(r2.get_hash_code(), r1.get_hash_code());
      assert::are_not_equal(r3.get_hash_code(), r1.get_hash_code());
      assert::are_not_equal(r4.get_hash_code(), r1.get_hash_code());
      assert::are_not_equal(r4.get_hash_code(), r3.get_hash_code());
    }
    
    auto test_method_(reset) {
      auto s = string {"value"};
      auto r = reference_wrapper_object<string> {s};
      assert::are_equal(s, r.get());
      r.reset();
      assert::is_true(r.is_empty());
    }
    
    auto test_method_(reset_with_reference) {
      auto s1 = string {"value"};
      auto s2 = string {"other"};
      auto r1 = reference_wrapper_object<string> {s1};
      assert::are_equal(s1, r1.get());
      r1.reset(s2);
      assert::are_equal(s2, r1.get());
    }
    
    auto test_method_(reset_with_null) {
      auto s = string {"value"};
      auto r = reference_wrapper_object<string> {s};
      assert::are_equal(s, r.get());
      r.reset(null);
      assert::is_true(r.is_empty());
    }
    
    auto test_method_(swap) {
      auto s1 = string {"value"};
      auto s2 = string {"other"};
      auto r1 = reference_wrapper_object<string> {s1};
      auto r2 = reference_wrapper_object<string> {s2};
      assert::are_equal(s1, r1.get());
      assert::are_equal(s2, r2.get());
      r1.swap(r2);
      assert::are_equal(s2, r1.get());
      assert::are_equal(s1, r2.get());
    }
    
    auto test_method_(to_object) {
      auto i = 42;
      auto s = string {"value"};
      assert::are_equal("value", reference_wrapper_object<string> {s}.to_object());
      assert::are_equal(42, reference_wrapper_object<int> {i}.to_object());
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<object> {}.to_object();});
    }
    
    auto test_method_(to_object_with_specified_type) {
      auto i = 42;
      auto s = string {"value"};
      assert::are_equal("value", reference_wrapper_object<object> {s}.to_object<string>());
      assert::are_equal(42, reference_wrapper_object<int> {i}.to_object<byte>());
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<object> {}.to_object<string>();});
    }
    
    auto test_method_(to_reference) {
      auto i = 42;
      auto s = string {"value"};
      assert::are_equal("value", reference_wrapper_object<string> {s}.to_reference());
      assert::are_equal(42, reference_wrapper_object<int> {i}.to_reference());
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<object> {}.to_reference();});
    }
    
    auto test_method_(to_reference_with_specified_type) {
      auto i = 42;
      auto s = string {"value"};
      assert::are_equal("value", reference_wrapper_object<object> {s}.to_reference<string>());
      assert::are_equal(42, reference_wrapper_object<int> {i}.to_reference<byte>());
      assert::throws<null_pointer_exception>([] {reference_wrapper_object<object> {}.to_reference<string>();});
    }
    
    auto test_method_(to_string) {
      auto i = 42;
      assert::are_equal("xtd::reference_wrapper_object<int> [value=42]", reference_wrapper_object<int> {i}.to_string());
      assert::are_equal("xtd::reference_wrapper_object<xtd::object> [value=(null)]", reference_wrapper_object<object> {}.to_string());
    }
    
    auto test_method_(assignment_operator_with_reference_wrapper_object) {
      auto i = 42;
      auto r1 = reference_wrapper_object<int> {i};
      auto r2 = reference_wrapper_object<int> {};
      r2 = r1;
      assert::are_equal(42, r1.to_object());
      assert::are_equal(42, r2.to_object());
    }
    
    auto test_method_(assignment_operator_with_moved_reference_wrapper_object) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {};
      r = reference_wrapper_object<int> {i};
      assert::are_equal(42, r.to_object());
    }
    
    auto test_method_(assignment_operator_with_reference_wrapper_object_and_different_type) {
      auto s = string {"value"};
      auto r1 = reference_wrapper_object<string> {s};
      auto r2 = reference_wrapper_object<object> {};
      r2 = r1;
      assert::are_equal("value", r1.to_object());
      assert::are_equal("value", r2.to_object().to_string());
    }
    
    auto test_method_(assignment_operator_with_moved_reference_wrapper_object_and_different_type) {
      auto s = string {"value"};
      auto r = reference_wrapper_object<object> {};
      r = reference_wrapper_object<string> {s};
      assert::are_equal("value", r.to_object().to_string());
    }
    
    auto test_method_(assignment_operator_with_std_reference_wrapper) {
      auto i = 42;
      auto r1 = std::reference_wrapper<int> {i};
      auto r2 = reference_wrapper_object<int> {};
      r2 = r1;
      assert::are_equal(42, r2.to_object());
    }
    
    auto test_method_(assignment_operator_with_moved_std_reference_wrapper) {
      auto i = 42;
      auto r = reference_wrapper_object<int> {};
      r = std::reference_wrapper<int> {i};
      assert::are_equal(42, r.to_object());
    }
    
    auto test_method_(type_operator) {
      auto s1 = string {"value"};
      string s2 = reference_wrapper_object<string> {s1};
      assert::are_equal("value", s2);
      auto i1 = 42;
      int i2 = reference_wrapper_object<int> {i1};
      assert::are_equal(42, i2);
    }
    
    auto test_method_(bool_operator) {
      auto s = string {"value"};
      assert::is_false(!reference_wrapper_object<string> {s});
      assert::is_true(!reference_wrapper_object<string> {});
    }
    
    auto test_method_(base_type_operator) {
      auto i1 = 24;
      auto i2 = 42;
      auto r = std::reference_wrapper<int> {i1};
      r = reference_wrapper_object<int> {i2};
      assert::are_equal(42, r.get());
    }
    
    auto test_method_(equality_operator_with_null) {
      auto i = 42;
      assert::is_false(reference_wrapper_object<int> {i} == null);
      assert::is_true(reference_wrapper_object<int> {} == null);
    }
    
    auto test_method_(equality_operator_with_nullptr) {
      auto i = 42;
      assert::is_false(reference_wrapper_object<int> {i} == nullptr);
      assert::is_true(reference_wrapper_object<int> {} == nullptr);
    }
  };
}
