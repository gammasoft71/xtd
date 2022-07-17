#include <xtd/forms/radio_button.h>
#include <xtd/forms/form.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_radio_button) {
  public:
    void test_method_(constructor) {
      forms::radio_button radio_button;
      assert::is_false(radio_button.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), radio_button.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, radio_button.flat_style(), csf_);
      assert::are_equal(image::empty, radio_button.image(), csf_);
      assert::are_equal(image_list::empty, radio_button.image_list(), csf_);
      assert::are_equal(-1, radio_button.image_index(), csf_);
      assert::are_equal(content_alignment::middle_center, radio_button.image_align(), csf_);
      assert::are_equal(content_alignment::middle_left, radio_button.text_align(), csf_);
    }
  };
}
