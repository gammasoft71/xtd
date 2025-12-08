#include <xtd/convert_pointer>
#include <xtd/environment>
#include <xtd/guid>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(convert_pointer_tests) {
    auto test_method_(const_object_to_ptr) {
      const guid* g1 = new guid();
      
      const guid* g2 = convert_pointer::to_ptr<guid>(*g1);
      assert::are_equal(g1, g2);
      delete g1;
    }
    
    auto test_method_(object_to_ptr) {
      guid* g1 = new guid();
      
      guid* g2 = convert_pointer::to_ptr<guid>(*g1);
      assert::are_equal(g1, g2);
      delete g1;
    }
    
    auto test_method_(const_object_to_other_ptr) {
      const guid* g = new guid();
      
      const object* o = convert_pointer::to_ptr<object>(*g);
      assert::are_equal(g, o);
      delete g;
    }
    
    auto test_method_(const_object_to_invalid_other_ptr) {
      const guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<string>(*g);});
      delete g;
    }
    
    auto test_method_(object_to_other_ptr) {
      guid* g = new guid();
      
      object* o = convert_pointer::to_ptr<object>(*g);
      assert::are_equal(g, o);
      delete g;
    }
    
    auto test_method_(object_to_invalid_other_ptr) {
      guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<string>(*g);});
      delete g;
    }
    
    auto test_method_(const_ptr_to_ptr) {
      const guid* g1 = new guid();
      
      const guid* g2 = convert_pointer::to_ptr<guid>(g1);
      assert::are_equal(g1, g2);
      delete g1;
    }
    
    auto test_method_(const_null_ptr_to_ptr) {
      const guid* g1 = null;
      
      const guid* g2 = convert_pointer::to_ptr<guid>(g1);
      assert::is_null(g2);
    }
    
    auto test_method_(ptr_to_ptr) {
      guid* g1 = new guid();
      
      guid* g2 = convert_pointer::to_ptr<guid>(g1);
      assert::are_equal(g1, g2);
      delete g1;
    }
    
    auto test_method_(null_ptr_to_ptr) {
      guid* g1 = null;
      
      guid* g2 = convert_pointer::to_ptr<guid>(g1);
      assert::is_null(g2);
    }
    
    auto test_method_(const_ptr_to_other_ptr) {
      const guid* g = new guid();
      
      const object* o = convert_pointer::to_ptr<object>(g);
      assert::are_equal(g, o);
      delete g;
    }
    
    auto test_method_(const_null_ptr_to_other_ptr) {
      const guid* g = null;
      
      const object* o = convert_pointer::to_ptr<object>(g);
      assert::is_null(o);
    }
    
    auto test_method_(const_ptr_to_invalid_other_ptr) {
      const guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<string>(g);});
      delete g;
    }
    
    auto test_method_(ptr_to_other_ptr) {
      guid* g = new guid();
      
      object* o = convert_pointer::to_ptr<object>(g);
      assert::are_equal(g, o);
      delete g;
    }
    
    auto test_method_(ptr_null_to_other_ptr) {
      guid* g = null;
      
      object* o = convert_pointer::to_ptr<object>(g);
      assert::is_null(o);
    }
    
    auto test_method_(ptr_to_invalid_other_ptr) {
      guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<string>(g);});
      delete g;
    }
    
    auto test_method_(const_object_to_ref) {
      const guid* g1 = new guid();
      
      const guid& g2 = convert_pointer::to_ref<guid>(*g1);
      assert::are_equal(g1, &g2);
      delete g1;
    }
    
    auto test_method_(object_to_ref) {
      guid* g1 = new guid();
      
      guid& g2 = convert_pointer::to_ref<guid>(*g1);
      assert::are_equal(g1, &g2);
      delete g1;
    }
    
    auto test_method_(const_object_to_other_ref) {
      const guid* g = new guid();
      
      const object& o = convert_pointer::to_ref<object>(*g);
      assert::are_equal(g, &o);
      delete g;
    }
    
    auto test_method_(const_object_to_invalid_other_ref) {
      const guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<string>(*g);});
      delete g;
    }
    
    auto test_method_(object_to_other_ref) {
      guid* g = new guid();
      
      object& o = convert_pointer::to_ref<object>(*g);
      assert::are_equal(g, &o);
      delete g;
    }
    
    auto test_method_(object_to_invalid_other_ref) {
      guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<string>(*g);});
      delete g;
    }
    
    auto test_method_(const_pointer_to_ref) {
      const guid* g1 = new guid();
      const guid& g2 = convert_pointer::to_ref<guid>(g1);
      assert::are_equal(g1, &g2);
      delete g1;
    }
    
    auto test_method_(const_null_pointer_to_ref) {
      const guid* g1 = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref<guid>(g1);});
    }
    
    auto test_method_(pointer_to_ref) {
      guid* g1 = new guid();
      guid& g2 = convert_pointer::to_ref<guid>(g1);
      assert::are_equal(g1, &g2);
      delete g1;
    }
    
    auto test_method_(null_pointer_to_ref) {
      guid* g = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref<guid>(g);});
    }
    
    auto test_method_(const_pointer_to_other_ref) {
      const guid* g = new guid();
      const object& o = convert_pointer::to_ref<object>(g);
      assert::are_equal(g, &o);
      delete g;
    }
    
    auto test_method_(const_null_pointer_to_other_ref) {
      const guid* g = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref<object>(g);});
    }
    
    auto test_method_(const_pointer_to_invalid_other_ref) {
      const guid* g = new guid();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<string>(g);});
      delete g;
    }
    
    auto test_method_(pointer_to_other_ref) {
      guid* g = new guid();
      object& o = convert_pointer::to_ref<object>(g);
      assert::are_equal(g, &o);
      delete g;
    }
    
    auto test_method_(null_pointer_to_other_ref) {
      guid* g = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref<object>(g);});
    }
    
    auto test_method_(pointer_to_invalid_other_ref) {
      guid* g = new guid();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<string>(g);});
      delete g;
    }
    
    auto test_method_(to_unique_ptr) {
      xtd::uptr<guid> g = xtd::new_uptr<guid>();
      guid* ptr = g.get();
      xtd::uptr<object> o = convert_pointer::to_unique_ptr<object>(g);
      assert::are_equal(ptr, o.get());
      assert::is_null(g);
    }
    
    auto test_method_(to_unique_ptr_invalid) {
      xtd::uptr<guid> g = xtd::new_uptr<guid>();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_unique_ptr<string>(g);});
    }
    
    auto test_method_(move_to_unique_ptr) {
      xtd::uptr<object> o = convert_pointer::to_unique_ptr<object>(xtd::new_uptr<guid>());
      assert::is_not_null(o.get());
    }
    
    auto test_method_(move_to_unique_ptr_invalid) {
      assert::throws<invalid_cast_exception>([] {convert_pointer::to_unique_ptr<string>(xtd::new_uptr<guid>());});
    }
    
    auto test_method_(to_shared_ptr) {
      xtd::sptr<guid> g = xtd::new_sptr<guid>();
      xtd::sptr<object> o = convert_pointer::to_shared_ptr<object>(g);
      assert::are_equal(g.to_pointer(), o.to_pointer());
    }
    
    auto test_method_(to_shared_ptr_invalid) {
      xtd::sptr<guid> g = xtd::new_sptr<guid>();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_shared_ptr<string>(g);});
    }
    
    auto test_method_(const_to_shared_ptr) {
      const xtd::sptr<guid> g = xtd::new_sptr<guid>();
      xtd::sptr<object> o = convert_pointer::to_shared_ptr<object>(g);
      assert::are_equal(g.to_pointer(), o.to_pointer());
    }
    
    auto test_method_(const_to_shared_ptr_invalid) {
      const xtd::sptr<guid> g = xtd::new_sptr<guid>();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_shared_ptr<string>(g);});
    }
    
    auto test_method_(move_to_shared_ptr) {
      xtd::sptr<object> o = convert_pointer::to_shared_ptr<object>(xtd::new_sptr<guid>());
      assert::is_not_null(o.get());
    }
    
    auto test_method_(move_to_shared_ptr_invalid) {
      assert::throws<invalid_cast_exception>([] {convert_pointer::to_shared_ptr<string>(xtd::new_sptr<guid>());});
    }
  };
}
