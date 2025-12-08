#include <xtd/forms/battery_charge_status>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(battery_charge_status_tests) {
  public:
    auto test_method_(high) {
      assert::are_equal(1, enum_object<>::to_int32(battery_charge_status::high));
      assert::are_equal("high", enum_object<>::to_string(battery_charge_status::high));
      assert::are_equal(battery_charge_status::high, enum_object<>::parse<battery_charge_status>("high"));
    }
    
    auto test_method_(low) {
      assert::are_equal(2, enum_object<>::to_int32(battery_charge_status::low));
      assert::are_equal("low", enum_object<>::to_string(battery_charge_status::low));
      assert::are_equal(battery_charge_status::low, enum_object<>::parse<battery_charge_status>("low"));
    }
    
    auto test_method_(critical) {
      assert::are_equal(4, enum_object<>::to_int32(battery_charge_status::critical));
      assert::are_equal("critical", enum_object<>::to_string(battery_charge_status::critical));
      assert::are_equal(battery_charge_status::critical, enum_object<>::parse<battery_charge_status>("critical"));
    }
    
    auto test_method_(charging) {
      assert::are_equal(8, enum_object<>::to_int32(battery_charge_status::charging));
      assert::are_equal("charging", enum_object<>::to_string(battery_charge_status::charging));
      assert::are_equal(battery_charge_status::charging, enum_object<>::parse<battery_charge_status>("charging"));
    }
    
    auto test_method_(no_system_battery) {
      assert::are_equal(128, enum_object<>::to_int32(battery_charge_status::no_system_battery));
      assert::are_equal("no_system_battery", enum_object<>::to_string(battery_charge_status::no_system_battery));
      assert::are_equal(battery_charge_status::no_system_battery, enum_object<>::parse<battery_charge_status>("no_system_battery"));
    }
    
    auto test_method_(unknown) {
      assert::are_equal(255, enum_object<>::to_int32(battery_charge_status::unknown));
      assert::are_equal("unknown", enum_object<>::to_string(battery_charge_status::unknown));
      assert::are_equal(battery_charge_status::unknown, enum_object<>::parse<battery_charge_status>("unknown"));
    }
  };
}
