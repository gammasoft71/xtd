#include <xtd/forms/link_label>
#include <xtd/forms/form>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(link_label_tests) {
    auto test_method_(new_link_label) {
      form form;
      link_label label;
      label.parent(form);
      assert::are_equal(drawing::size(100, 23),  label.size());
    }
  };
}
