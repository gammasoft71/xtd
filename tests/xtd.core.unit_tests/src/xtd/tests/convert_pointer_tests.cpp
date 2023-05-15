#include <xtd/convert.h>
#include <xtd/guid.h>
#include <xtd/xtd.core>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(convert_pointer_tests) {
  public:
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
      
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ptr<ustring>(*g);}, csf_);
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
      
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ptr<ustring>(*g);}, csf_);
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
      
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ptr<ustring>(g);}, csf_);
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

    void test_method_(ptr_to_invvalid_other_ptr) {
      guid* g = new guid();
      
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ptr<ustring>(g);}, csf_);
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
      
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ref<ustring>(*g);}, csf_);
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
      
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ref<ustring>(*g);}, csf_);
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
      assert::throws<argument_null_exception>([&]{convert_pointer::to_ref(g1);}, csf_);
    }
    
    void test_method_(pointer_to_ref) {
      guid* g1 = new guid();
      guid& g2 = convert_pointer::to_ref(g1);
      assert::are_equal(g1, &g2, csf_);
      delete g1;
    }
    
    void test_method_(null_pointer_to_ref) {
      guid* g = null;
      assert::throws<argument_null_exception>([&]{convert_pointer::to_ref(g);}, csf_);
    }
    
    void test_method_(const_pointer_to_other_ref) {
      const guid* g = new guid();
      const object& o = convert_pointer::to_ref<object>(g);
      assert::are_equal(g, &o, csf_);
      delete g;
    }
    
    void test_method_(const_null_pointer_to_other_ref) {
      const guid* g = null;
      assert::throws<argument_null_exception>([&]{convert_pointer::to_ref<object>(g);}, csf_);
    }
    
    void test_method_(const_pointer_to_invalid_other_ref) {
      const guid* g = new guid();
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ref<ustring>(g);}, csf_);
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
      assert::throws<argument_null_exception>([&]{convert_pointer::to_ref<object>(g);}, csf_);
    }

    void test_method_(pointer_to_invalid_other_ref) {
      guid* g = new guid();
      assert::throws<invalid_cast_exception>([&]{convert_pointer::to_ref<ustring>(g);}, csf_);
      delete g;
    }
  };
}
