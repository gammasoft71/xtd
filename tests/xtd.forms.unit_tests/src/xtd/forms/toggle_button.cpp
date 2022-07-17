#include <xtd/forms/toggle_button.h>
#include <xtd/forms/form.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_toggle_button) {
  public:
    void test_method_(constructor) {
      forms::toggle_button toggle_button;
      assert::is_false(toggle_button.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), toggle_button.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, toggle_button.flat_style(), csf_);
      assert::are_equal(image::empty, toggle_button.image(), csf_);
      assert::are_equal(image_list::empty, toggle_button.image_list(), csf_);
      assert::are_equal(-1, toggle_button.image_index(), csf_);
      assert::are_equal(content_alignment::middle_center, toggle_button.image_align(), csf_);
      assert::are_equal(content_alignment::middle_center, toggle_button.text_align(), csf_);
    }
  };
}
