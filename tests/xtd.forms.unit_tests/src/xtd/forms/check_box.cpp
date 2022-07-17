#include <xtd/forms/check_box.h>
#include <xtd/forms/form.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_check_box) {
  public:
    void test_method_(constructor) {
      forms::check_box check_box;
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
    }
    
    void test_method_(set_client_size) {
      form form;
      check_box check_box;
      check_box.parent(form);
      check_box.client_size({100, 50});
      assert::are_equal(size(100, 50), check_box.client_size(), csf_);
    }
    
    void test_method_(set_size) {
      form form;
      check_box check_box;
      check_box.parent(form);
      check_box.size({100, 50});
      assert::are_equal(size(100, 50), check_box.size(), csf_);
    }
  };
}
