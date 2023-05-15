#include <xtd/convert.h>
#include <xtd/date_time.h>
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
    
    void test_method_(object_to_other_ptr) {
      guid* g = new guid();
      
      object* o = convert_pointer::to_ptr<object>(*g);
      assert::are_equal(g, o, csf_);
      delete g;
    }
    
    void test_method_(const_ptr_to_ptr) {
      const guid* g1 = new guid();
      
      const guid* g2 = convert_pointer::to_ptr(g1);
      assert::are_equal(g1, g2, csf_);
      delete g1;
    }
    
    void test_method_(ptr_to_ptr) {
      guid* g1 = new guid();
      
      guid* g2 = convert_pointer::to_ptr(g1);
      assert::are_equal(g1, g2, csf_);
      delete g1;
    }
    
    void test_method_(const_ptr_to_other_ptr) {
      const guid* g = new guid();
      
      const object* o = convert_pointer::to_ptr<object>(g);
      assert::are_equal(g, o, csf_);
      delete g;
    }
    
    void test_method_(ptr_to_other_ptr) {
      guid* g = new guid();
      
      object* o = convert_pointer::to_ptr<object>(g);
      assert::are_equal(g, o, csf_);
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
    
    void test_method_(object_to_other_ref) {
      guid* g = new guid();
      
      object& o = convert_pointer::to_ref<object>(*g);
      assert::are_equal(g, &o, csf_);
      delete g;
    }
    
    void test_method_(const_pointer_to_ref) {
      const date_time* d1 = new date_time();
      const date_time& d2 = convert_pointer::to_ref(d1);
      assert::are_equal(d1, &d2, csf_);
      delete d1;
    }
    
    void test_method_(pointer_to_ref) {
      date_time* d1 = new date_time();
      date_time& d2 = convert_pointer::to_ref(d1);
      assert::are_equal(d1, &d2, csf_);
      delete d1;
    }
    
    void test_method_(const_pointer_to_other_ref) {
      const date_time* d = new date_time();
      const object& o = convert_pointer::to_ref<object>(d);
      assert::are_equal(d, &o, csf_);
      delete d;
    }
    
    void test_method_(pointer_to_other_ref) {
      date_time* d = new date_time();
      object& o = convert_pointer::to_ref<object>(d);
      assert::are_equal(d, &o, csf_);
      delete d;
    }
  };
}
