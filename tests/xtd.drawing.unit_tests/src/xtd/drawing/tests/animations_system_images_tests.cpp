#include <xtd/environment>
#include <xtd/drawing/animations_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(animations_system_images_tests) {
    auto test_method_(default_size) {
      auto s = animations_system_images::default_size();
      assert::are_equal(size {32, 32}, s);
    }
    
    auto test_method_(process_working) {
      if (environment::os_version().is_linux()) assert::ignore();
      auto i = animations_system_images::process_working();
      assert::are_equal(size {32, 32}, i.size());
      assert::are_not_equal(image::empty, i);
      assert::are_equal(system_images::from_name("process-working"), i);
    }
    
    auto test_method_(process_working_with_specified_size) {
      if (environment::os_version().is_linux()) assert::ignore();
      auto i = animations_system_images::process_working({64, 64});
      assert::are_equal(size {64, 64}, i.size());
      assert::are_not_equal(image::empty, i);
      assert::are_equal(system_images::from_name("process-working", size {64, 64}), i);
    }
  };
}
