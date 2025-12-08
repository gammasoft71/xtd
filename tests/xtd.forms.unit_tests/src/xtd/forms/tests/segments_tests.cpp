#include <xtd/forms/segments>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(segments_tests) {
  public:
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(segments::none));
      assert::are_equal("none", enum_object<>::to_string(segments::none));
      assert::are_equal(segments::none, enum_object<>::parse<segments>("none"));
    }
    
    auto test_method_(a) {
      assert::are_equal(1, enum_object<>::to_int32(segments::a));
      assert::are_equal("a", enum_object<>::to_string(segments::a));
      assert::are_equal(segments::a, enum_object<>::parse<segments>("a"));
    }
    
    auto test_method_(b) {
      assert::are_equal(2, enum_object<>::to_int32(segments::b));
      assert::are_equal("b", enum_object<>::to_string(segments::b));
      assert::are_equal(segments::b, enum_object<>::parse<segments>("b"));
    }
    
    auto test_method_(c) {
      assert::are_equal(4, enum_object<>::to_int32(segments::c));
      assert::are_equal("c", enum_object<>::to_string(segments::c));
      assert::are_equal(segments::c, enum_object<>::parse<segments>("c"));
    }
    
    auto test_method_(d) {
      assert::are_equal(8, enum_object<>::to_int32(segments::d));
      assert::are_equal("d", enum_object<>::to_string(segments::d));
      assert::are_equal(segments::d, enum_object<>::parse<segments>("d"));
    }
    
    auto test_method_(e) {
      assert::are_equal(16, enum_object<>::to_int32(segments::e));
      assert::are_equal("e", enum_object<>::to_string(segments::e));
      assert::are_equal(segments::e, enum_object<>::parse<segments>("e"));
    }
    
    auto test_method_(f) {
      assert::are_equal(32, enum_object<>::to_int32(segments::f));
      assert::are_equal("f", enum_object<>::to_string(segments::f));
      assert::are_equal(segments::f, enum_object<>::parse<segments>("f"));
    }
    
    auto test_method_(g) {
      assert::are_equal(64, enum_object<>::to_int32(segments::g));
      assert::are_equal("g", enum_object<>::to_string(segments::g));
      assert::are_equal(segments::g, enum_object<>::parse<segments>("g"));
    }
    
    auto test_method_(h) {
      assert::are_equal(128, enum_object<>::to_int32(segments::h));
      assert::are_equal("h", enum_object<>::to_string(segments::h));
      assert::are_equal(segments::h, enum_object<>::parse<segments>("h"));
    }
    
    auto test_method_(i) {
      assert::are_equal(256, enum_object<>::to_int32(segments::i));
      assert::are_equal("i", enum_object<>::to_string(segments::i));
      assert::are_equal(segments::i, enum_object<>::parse<segments>("i"));
    }
    
    auto test_method_(j) {
      assert::are_equal(512, enum_object<>::to_int32(segments::j));
      assert::are_equal("j", enum_object<>::to_string(segments::j));
      assert::are_equal(segments::j, enum_object<>::parse<segments>("j"));
    }
    
    auto test_method_(k) {
      assert::are_equal(1024, enum_object<>::to_int32(segments::k));
      assert::are_equal("k", enum_object<>::to_string(segments::k));
      assert::are_equal(segments::k, enum_object<>::parse<segments>("k"));
    }
    
    auto test_method_(l) {
      assert::are_equal(2048, enum_object<>::to_int32(segments::l));
      assert::are_equal("l", enum_object<>::to_string(segments::l));
      assert::are_equal(segments::l, enum_object<>::parse<segments>("l"));
    }
    
    auto test_method_(m) {
      assert::are_equal(4096, enum_object<>::to_int32(segments::m));
      assert::are_equal("m", enum_object<>::to_string(segments::m));
      assert::are_equal(segments::m, enum_object<>::parse<segments>("m"));
    }
    
    auto test_method_(a2) {
      assert::are_equal(8192, enum_object<>::to_int32(segments::a2));
      assert::are_equal("a2", enum_object<>::to_string(segments::a2));
      assert::are_equal(segments::a2, enum_object<>::parse<segments>("a2"));
    }
    
    auto test_method_(d2) {
      assert::are_equal(16384, enum_object<>::to_int32(segments::d2));
      assert::are_equal("d2", enum_object<>::to_string(segments::d2));
      assert::are_equal(segments::d2, enum_object<>::parse<segments>("d2"));
    }
    
    auto test_method_(g2) {
      assert::are_equal(32768, enum_object<>::to_int32(segments::g2));
      assert::are_equal("g2", enum_object<>::to_string(segments::g2));
      assert::are_equal(segments::g2, enum_object<>::parse<segments>("g2"));
    }
    
    auto test_method_(dp) {
      assert::are_equal(65536, enum_object<>::to_int32(segments::dp));
      assert::are_equal("dp", enum_object<>::to_string(segments::dp));
      assert::are_equal(segments::dp, enum_object<>::parse<segments>("dp"));
    }
    
    auto test_method_(pc) {
      assert::are_equal(131072, enum_object<>::to_int32(segments::pc));
      assert::are_equal("pc", enum_object<>::to_string(segments::pc));
      assert::are_equal(segments::pc, enum_object<>::parse<segments>("pc"));
    }
  };
}
