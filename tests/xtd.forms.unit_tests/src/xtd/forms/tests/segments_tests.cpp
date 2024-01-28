#include <xtd/forms/segments>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(segments_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(segments::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(segments::none), csf_);
      assert::are_equal(segments::none, enum_object<>::parse<segments>("none"), csf_);
    }
    
    void test_method_(a) {
      assert::are_equal(1, enum_object<>::to_int32(segments::a), csf_);
      assert::are_equal("a", enum_object<>::to_string(segments::a), csf_);
      assert::are_equal(segments::a, enum_object<>::parse<segments>("a"), csf_);
    }
    
    void test_method_(b) {
      assert::are_equal(2, enum_object<>::to_int32(segments::b), csf_);
      assert::are_equal("b", enum_object<>::to_string(segments::b), csf_);
      assert::are_equal(segments::b, enum_object<>::parse<segments>("b"), csf_);
    }
    
    void test_method_(c) {
      assert::are_equal(4, enum_object<>::to_int32(segments::c), csf_);
      assert::are_equal("c", enum_object<>::to_string(segments::c), csf_);
      assert::are_equal(segments::c, enum_object<>::parse<segments>("c"), csf_);
    }
    
    void test_method_(d) {
      assert::are_equal(8, enum_object<>::to_int32(segments::d), csf_);
      assert::are_equal("d", enum_object<>::to_string(segments::d), csf_);
      assert::are_equal(segments::d, enum_object<>::parse<segments>("d"), csf_);
    }
    
    void test_method_(e) {
      assert::are_equal(16, enum_object<>::to_int32(segments::e), csf_);
      assert::are_equal("e", enum_object<>::to_string(segments::e), csf_);
      assert::are_equal(segments::e, enum_object<>::parse<segments>("e"), csf_);
    }
    
    void test_method_(f) {
      assert::are_equal(32, enum_object<>::to_int32(segments::f), csf_);
      assert::are_equal("f", enum_object<>::to_string(segments::f), csf_);
      assert::are_equal(segments::f, enum_object<>::parse<segments>("f"), csf_);
    }
    
    void test_method_(g) {
      assert::are_equal(64, enum_object<>::to_int32(segments::g), csf_);
      assert::are_equal("g", enum_object<>::to_string(segments::g), csf_);
      assert::are_equal(segments::g, enum_object<>::parse<segments>("g"), csf_);
    }
    
    void test_method_(h) {
      assert::are_equal(128, enum_object<>::to_int32(segments::h), csf_);
      assert::are_equal("h", enum_object<>::to_string(segments::h), csf_);
      assert::are_equal(segments::h, enum_object<>::parse<segments>("h"), csf_);
    }
    
    void test_method_(i) {
      assert::are_equal(256, enum_object<>::to_int32(segments::i), csf_);
      assert::are_equal("i", enum_object<>::to_string(segments::i), csf_);
      assert::are_equal(segments::i, enum_object<>::parse<segments>("i"), csf_);
    }
    
    void test_method_(j) {
      assert::are_equal(512, enum_object<>::to_int32(segments::j), csf_);
      assert::are_equal("j", enum_object<>::to_string(segments::j), csf_);
      assert::are_equal(segments::j, enum_object<>::parse<segments>("j"), csf_);
    }
    
    void test_method_(k) {
      assert::are_equal(1024, enum_object<>::to_int32(segments::k), csf_);
      assert::are_equal("k", enum_object<>::to_string(segments::k), csf_);
      assert::are_equal(segments::k, enum_object<>::parse<segments>("k"), csf_);
    }
    
    void test_method_(l) {
      assert::are_equal(2048, enum_object<>::to_int32(segments::l), csf_);
      assert::are_equal("l", enum_object<>::to_string(segments::l), csf_);
      assert::are_equal(segments::l, enum_object<>::parse<segments>("l"), csf_);
    }
    
    void test_method_(m) {
      assert::are_equal(4096, enum_object<>::to_int32(segments::m), csf_);
      assert::are_equal("m", enum_object<>::to_string(segments::m), csf_);
      assert::are_equal(segments::m, enum_object<>::parse<segments>("m"), csf_);
    }
    
    void test_method_(a2) {
      assert::are_equal(8192, enum_object<>::to_int32(segments::a2), csf_);
      assert::are_equal("a2", enum_object<>::to_string(segments::a2), csf_);
      assert::are_equal(segments::a2, enum_object<>::parse<segments>("a2"), csf_);
    }
    
    void test_method_(d2) {
      assert::are_equal(16384, enum_object<>::to_int32(segments::d2), csf_);
      assert::are_equal("d2", enum_object<>::to_string(segments::d2), csf_);
      assert::are_equal(segments::d2, enum_object<>::parse<segments>("d2"), csf_);
    }
    
    void test_method_(g2) {
      assert::are_equal(32768, enum_object<>::to_int32(segments::g2), csf_);
      assert::are_equal("g2", enum_object<>::to_string(segments::g2), csf_);
      assert::are_equal(segments::g2, enum_object<>::parse<segments>("g2"), csf_);
    }
    
    void test_method_(dp) {
      assert::are_equal(65536, enum_object<>::to_int32(segments::dp), csf_);
      assert::are_equal("dp", enum_object<>::to_string(segments::dp), csf_);
      assert::are_equal(segments::dp, enum_object<>::parse<segments>("dp"), csf_);
    }
    
    void test_method_(pc) {
      assert::are_equal(131072, enum_object<>::to_int32(segments::pc), csf_);
      assert::are_equal("pc", enum_object<>::to_string(segments::pc), csf_);
      assert::are_equal(segments::pc, enum_object<>::parse<segments>("pc"), csf_);
    }
  };
}
