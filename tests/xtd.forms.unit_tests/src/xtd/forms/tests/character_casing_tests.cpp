#include <xtd/forms/character_casing>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(character_casing_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(character_casing::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(character_casing::normal), csf_);
      assert::are_equal(character_casing::normal, enum_object<>::parse<character_casing>("normal"), csf_);
    }
    
    void test_method_(upper) {
      assert::are_equal(1, enum_object<>::to_int32(character_casing::upper), csf_);
      assert::are_equal("upper", enum_object<>::to_string(character_casing::upper), csf_);
      assert::are_equal(character_casing::upper, enum_object<>::parse<character_casing>("upper"), csf_);
    }
    
    void test_method_(lower) {
      assert::are_equal(2, enum_object<>::to_int32(character_casing::lower), csf_);
      assert::are_equal("lower", enum_object<>::to_string(character_casing::lower), csf_);
      assert::are_equal(character_casing::lower, enum_object<>::parse<character_casing>("lower"), csf_);
    }
  };
}

