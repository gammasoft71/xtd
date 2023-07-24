#include <xtd/drawing/animations_system_images.h>
#include <xtd/drawing/system_images.h>
#include <xtd/tunit/assert.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(animations_system_images_tests) {
  public:
    void test_method_(default_size) {
      auto s = animations_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(process_working) {
      auto i = animations_system_images::process_working();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("process-working"), i, csf_);
    }

    void test_method_(process_working_with_specified_size) {
      auto i = animations_system_images::process_working({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("process-working", size {64, 64}), i, csf_);
    }
  };
}
