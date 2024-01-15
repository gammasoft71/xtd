#include <xtd/drawing/xtd_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(xtd_system_images_tests) {
    void test_method_(default_size) {
      auto s = xtd_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(gammasoft) {
      auto i = xtd_system_images::gammasoft();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("gammasoft"), i, csf_);
    }

    void test_method_(gammasoft_with_specified_size) {
      auto i = xtd_system_images::gammasoft({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("gammasoft", size {64, 64}), i, csf_);
    }

    void test_method_(xtd) {
      auto i = xtd_system_images::xtd();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd"), i, csf_);
    }

    void test_method_(xtd_with_specified_size) {
      auto i = xtd_system_images::xtd({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_console) {
      auto i = xtd_system_images::xtd_console();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-console"), i, csf_);
    }

    void test_method_(xtd_console_with_specified_size) {
      auto i = xtd_system_images::xtd_console({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-console", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_forms) {
      auto i = xtd_system_images::xtd_forms();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-forms"), i, csf_);
    }

    void test_method_(xtd_forms_with_specified_size) {
      auto i = xtd_system_images::xtd_forms({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-forms", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_tunit) {
      auto i = xtd_system_images::xtd_tunit();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-tunit"), i, csf_);
    }

    void test_method_(xtd_tunit_with_specified_size) {
      auto i = xtd_system_images::xtd_tunit({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-tunit", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_core) {
      auto i = xtd_system_images::xtd_core();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-core"), i, csf_);
    }

    void test_method_(xtd_core_with_specified_size) {
      auto i = xtd_system_images::xtd_core({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-core", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_delegates) {
      auto i = xtd_system_images::xtd_delegates();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-delegates"), i, csf_);
    }

    void test_method_(xtd_delegates_with_specified_size) {
      auto i = xtd_system_images::xtd_delegates({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-delegates", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_diagnostics) {
      auto i = xtd_system_images::xtd_diagnostics();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-diagnostics"), i, csf_);
    }

    void test_method_(xtd_diagnostics_with_specified_size) {
      auto i = xtd_system_images::xtd_diagnostics({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-diagnostics", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_drawing) {
      auto i = xtd_system_images::xtd_drawing();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-drawing"), i, csf_);
    }

    void test_method_(xtd_drawing_with_specified_size) {
      auto i = xtd_system_images::xtd_drawing({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-drawing", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_io) {
      auto i = xtd_system_images::xtd_io();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-io"), i, csf_);
    }

    void test_method_(xtd_io_with_specified_size) {
      auto i = xtd_system_images::xtd_io({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-io", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_strings) {
      auto i = xtd_system_images::xtd_strings();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-strings"), i, csf_);
    }

    void test_method_(xtd_strings_with_specified_size) {
      auto i = xtd_system_images::xtd_strings({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-strings", size {64, 64}), i, csf_);
    }

    void test_method_(xtd_cmake) {
      auto i = xtd_system_images::xtd_cmake();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-cmake"), i, csf_);
    }

    void test_method_(xtd_cmake_with_specified_size) {
      auto i = xtd_system_images::xtd_cmake({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("xtd-cmake", size {64, 64}), i, csf_);
    }
  };
}
