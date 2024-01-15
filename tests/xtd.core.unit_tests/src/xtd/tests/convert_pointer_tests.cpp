#include <xtd/convert>
#include <xtd/guid>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(convert_pointer_tests) {
    void test_method_(const_object_to_ptr) {
      const guid* g1 = new guid();
      
      const guid* g2 = convert_pointer::to_ptr(*g1);
      assert::are_equal(g1, g2, csf_);
      delete g1;
    }
    
    void test_method_(object_to_ptr) {
      guid* g1 = new guid();
      
      guid* g2 = convert_pointer::to_ptr(*g1);
      assert::are_equal(g1, g2, csf_);
      delete g1;
    }
    
    void test_method_(const_object_to_other_ptr) {
      const guid* g = new guid();
      
      const object* o = convert_pointer::to_ptr<object>(*g);
      assert::are_equal(g, o, csf_);
      delete g;
    }
    
    void test_method_(const_object_to_invalid_other_ptr) {
      const guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<ustring>(*g);}, csf_);
      delete g;
    }
    
    void test_method_(object_to_other_ptr) {
      guid* g = new guid();
      
      object* o = convert_pointer::to_ptr<object>(*g);
      assert::are_equal(g, o, csf_);
      delete g;
    }
    
    void test_method_(object_to_invalid_other_ptr) {
      guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<ustring>(*g);}, csf_);
      delete g;
    }
    
    void test_method_(const_ptr_to_ptr) {
      const guid* g1 = new guid();
      
      const guid* g2 = convert_pointer::to_ptr(g1);
      assert::are_equal(g1, g2, csf_);
      delete g1;
    }
    
    void test_method_(const_null_ptr_to_ptr) {
      const guid* g1 = null;
      
      const guid* g2 = convert_pointer::to_ptr(g1);
      assert::is_null(g2, csf_);
    }
    
    void test_method_(ptr_to_ptr) {
      guid* g1 = new guid();
      
      guid* g2 = convert_pointer::to_ptr(g1);
      assert::are_equal(g1, g2, csf_);
      delete g1;
    }
    
    void test_method_(null_ptr_to_ptr) {
      guid* g1 = null;
      
      guid* g2 = convert_pointer::to_ptr(g1);
      assert::is_null(g2, csf_);
    }
    
    void test_method_(const_ptr_to_other_ptr) {
      const guid* g = new guid();
      
      const object* o = convert_pointer::to_ptr<object>(g);
      assert::are_equal(g, o, csf_);
      delete g;
    }
    
    void test_method_(const_null_ptr_to_other_ptr) {
      const guid* g = null;
      
      const object* o = convert_pointer::to_ptr<object>(g);
      assert::is_null(o, csf_);
    }
    
    void test_method_(const_ptr_to_invalid_other_ptr) {
      const guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<ustring>(g);}, csf_);
      delete g;
    }
    
    void test_method_(ptr_to_other_ptr) {
      guid* g = new guid();
      
      object* o = convert_pointer::to_ptr<object>(g);
      assert::are_equal(g, o, csf_);
      delete g;
    }
    
    void test_method_(ptr_null_to_other_ptr) {
      guid* g = null;
      
      object* o = convert_pointer::to_ptr<object>(g);
      assert::is_null(o, csf_);
    }
    
    void test_method_(ptr_to_invalid_other_ptr) {
      guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ptr<ustring>(g);}, csf_);
      delete g;
    }
    
    void test_method_(const_object_to_ref) {
      const guid* g1 = new guid();
      
      const guid& g2 = convert_pointer::to_ref(*g1);
      assert::are_equal(g1, &g2, csf_);
      delete g1;
    }
    
    void test_method_(object_to_ref) {
      guid* g1 = new guid();
      
      guid& g2 = convert_pointer::to_ref(*g1);
      assert::are_equal(g1, &g2, csf_);
      delete g1;
    }
    
    void test_method_(const_object_to_other_ref) {
      const guid* g = new guid();
      
      const object& o = convert_pointer::to_ref<object>(*g);
      assert::are_equal(g, &o, csf_);
      delete g;
    }
    
    void test_method_(const_object_to_invalid_other_ref) {
      const guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<ustring>(*g);}, csf_);
      delete g;
    }
    
    void test_method_(object_to_other_ref) {
      guid* g = new guid();
      
      object& o = convert_pointer::to_ref<object>(*g);
      assert::are_equal(g, &o, csf_);
      delete g;
    }
    
    void test_method_(object_to_invalid_other_ref) {
      guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<ustring>(*g);}, csf_);
      delete g;
    }
    
    void test_method_(const_pointer_to_ref) {
      const guid* g1 = new guid();
      const guid& g2 = convert_pointer::to_ref(g1);
      assert::are_equal(g1, &g2, csf_);
      delete g1;
    }
    
    void test_method_(const_null_pointer_to_ref) {
      const guid* g1 = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref(g1);}, csf_);
    }
    
    void test_method_(pointer_to_ref) {
      guid* g1 = new guid();
      guid& g2 = convert_pointer::to_ref(g1);
      assert::are_equal(g1, &g2, csf_);
      delete g1;
    }
    
    void test_method_(null_pointer_to_ref) {
      guid* g = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref(g);}, csf_);
    }
    
    void test_method_(const_pointer_to_other_ref) {
      const guid* g = new guid();
      const object& o = convert_pointer::to_ref<object>(g);
      assert::are_equal(g, &o, csf_);
      delete g;
    }
    
    void test_method_(const_null_pointer_to_other_ref) {
      const guid* g = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref<object>(g);}, csf_);
    }
    
    void test_method_(const_pointer_to_invalid_other_ref) {
      const guid* g = new guid();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<ustring>(g);}, csf_);
      delete g;
    }
    
    void test_method_(pointer_to_other_ref) {
      guid* g = new guid();
      object& o = convert_pointer::to_ref<object>(g);
      assert::are_equal(g, &o, csf_);
      delete g;
    }
    
    void test_method_(null_pointer_to_other_ref) {
      guid* g = null;
      assert::throws<argument_null_exception>([&] {convert_pointer::to_ref<object>(g);}, csf_);
    }
    
    void test_method_(pointer_to_invalid_other_ref) {
      guid* g = new guid();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_ref<ustring>(g);}, csf_);
      delete g;
    }
    
    void test_method_(to_unique_ptr) {
      unique_ptr<guid> g = make_unique<guid>();
      guid* ptr = g.get();
      unique_ptr<object> o = convert_pointer::to_unique_ptr<object>(g);
      assert::are_equal(ptr, o.get(), csf_);
      assert::is_null(g, csf_);
    }
    
    void test_method_(to_unique_ptr_invalid) {
      unique_ptr<guid> g = make_unique<guid>();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_unique_ptr<ustring>(g);}, csf_);
    }
    
    void test_method_(move_to_unique_ptr) {
      unique_ptr<object> o = convert_pointer::to_unique_ptr<object>(make_unique<guid>());
      assert::is_not_null(o.get(), csf_);
    }
    
    void test_method_(move_to_unique_ptr_invalid) {
      assert::throws<invalid_cast_exception>([] {convert_pointer::to_unique_ptr<ustring>(make_unique<guid>());}, csf_);
    }
    
    void test_method_(to_shared_ptr) {
      shared_ptr<guid> g = make_shared<guid>();
      shared_ptr<object> o = convert_pointer::to_shared_ptr<object>(g);
      assert::are_equal(g, o, csf_);
    }
    
    void test_method_(to_shared_ptr_invalid) {
      shared_ptr<guid> g = make_shared<guid>();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_shared_ptr<ustring>(g);}, csf_);
    }
    
    void test_method_(const_to_shared_ptr) {
      const shared_ptr<guid> g = make_shared<guid>();
      shared_ptr<object> o = convert_pointer::to_shared_ptr<object>(g);
      assert::are_equal(g, o, csf_);
    }
    
    void test_method_(const_to_shared_ptr_invalid) {
      const shared_ptr<guid> g = make_shared<guid>();
      assert::throws<invalid_cast_exception>([&] {convert_pointer::to_shared_ptr<ustring>(g);}, csf_);
    }
    
    void test_method_(move_to_shared_ptr) {
      shared_ptr<object> o = convert_pointer::to_shared_ptr<object>(make_shared<guid>());
      assert::is_not_null(o.get(), csf_);
    }
    
    void test_method_(move_to_shared_ptr_invalid) {
      assert::throws<invalid_cast_exception>([] {convert_pointer::to_shared_ptr<ustring>(make_shared<guid>());}, csf_);
    }
  };
}
