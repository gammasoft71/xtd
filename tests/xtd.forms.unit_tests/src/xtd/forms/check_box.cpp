#include <xtd/forms/check_box.h>
#include <xtd/forms/form.h>
#include <xtd/xtd.tunit>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_check_box) {
  public:
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
