#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(image_tests) {
        auto test_method_(_image_operator_on_char_ptr) {
          auto v = "system-file-manager"_image;
          assert::is_instance_of<image>(v);
          assert::are_equal(system_images::default_size(), v.size());
          assert::are_equal(system_images::from_name("system-file-manager"), v);
        }
        
        auto test_method_(_image_operator_on_char8_ptr) {
          auto v = u8"system-file-manager"_image;
          assert::is_instance_of<image>(v);
          assert::are_equal(system_images::from_name("system-file-manager"), v);
        }
        
        auto test_method_(_image_operator_on_char16_ptr) {
          auto v = u"system-file-manager"_image;
          assert::is_instance_of<image>(v);
          assert::are_equal(system_images::from_name("system-file-manager"), v);
        }
        
        auto test_method_(_image_operator_on_char32_ptr) {
          auto v = U"system-file-manager"_image;
          assert::is_instance_of<image>(v);
          assert::are_equal(system_images::from_name("system-file-manager"), v);
        }
        
        auto test_method_(_image_operator_on_wchar_ptr) {
          auto v = L"system-file-manager"_image;
          assert::is_instance_of<image>(v);
          assert::are_equal(system_images::from_name("system-file-manager"), v);
        }
      };
    }
  }
}
