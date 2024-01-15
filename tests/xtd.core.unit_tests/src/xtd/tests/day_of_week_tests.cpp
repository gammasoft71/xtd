#include <xtd/day_of_week>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(day_of_week_tests) {
    void test_method_(sunday) {
      assert::are_equal(0, enum_object<>::to_int32(day_of_week::sunday), csf_);
      assert::are_equal("sunday", enum_object<>::to_string(day_of_week::sunday), csf_);
      assert::are_equal(day_of_week::sunday, enum_object<>::parse<day_of_week>("sunday"), csf_);
    }
    
    void test_method_(monday) {
      assert::are_equal(1, enum_object<>::to_int32(day_of_week::monday), csf_);
      assert::are_equal("monday", enum_object<>::to_string(day_of_week::monday), csf_);
      assert::are_equal(day_of_week::monday, enum_object<>::parse<day_of_week>("monday"), csf_);
    }
    
    void test_method_(tuesday) {
      assert::are_equal(2, enum_object<>::to_int32(day_of_week::tuesday), csf_);
      assert::are_equal("tuesday", enum_object<>::to_string(day_of_week::tuesday), csf_);
      assert::are_equal(day_of_week::tuesday, enum_object<>::parse<day_of_week>("tuesday"), csf_);
    }
    
    void test_method_(wednesday) {
      assert::are_equal(3, enum_object<>::to_int32(day_of_week::wednesday), csf_);
      assert::are_equal("wednesday", enum_object<>::to_string(day_of_week::wednesday), csf_);
      assert::are_equal(day_of_week::wednesday, enum_object<>::parse<day_of_week>("wednesday"), csf_);
    }
    
    void test_method_(thursday) {
      assert::are_equal(4, enum_object<>::to_int32(day_of_week::thursday), csf_);
      assert::are_equal("thursday", enum_object<>::to_string(day_of_week::thursday), csf_);
      assert::are_equal(day_of_week::thursday, enum_object<>::parse<day_of_week>("thursday"), csf_);
    }
    
    void test_method_(friday) {
      assert::are_equal(5, enum_object<>::to_int32(day_of_week::friday), csf_);
      assert::are_equal("friday", enum_object<>::to_string(day_of_week::friday), csf_);
      assert::are_equal(day_of_week::friday, enum_object<>::parse<day_of_week>("friday"), csf_);
    }
    
    void test_method_(saturday) {
      assert::are_equal(6, enum_object<>::to_int32(day_of_week::saturday), csf_);
      assert::are_equal("saturday", enum_object<>::to_string(day_of_week::saturday), csf_);
      assert::are_equal(day_of_week::saturday, enum_object<>::parse<day_of_week>("saturday"), csf_);
    }
  };
}
