#include <xtd/forms/style_sheets/name_property.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_name_property) {
  public:
    void test_method_(create_default) {
      name_property n;
      assert::is_true(n == name_property::empty, csf_);
    }

    void test_method_(create_with_specified_authors) {
      name_property n("Name text.");
      assert::are_equal("Name text.", n.text(), csf_);
    }

    void test_method_(equals) {
      name_property n1("Name 1.");
      name_property n2("Name 1.");
      name_property n3("Name 2.");
      assert::is_true(n1 == n2, csf_);
      assert::is_false(n1 == n3, csf_);
    }

    void test_method_(different) {
      name_property n1("Name 1.");
      name_property n2("Name 2.");
      name_property n3("Name 1.");
      assert::is_true(n1 != n2, csf_);
      assert::is_false(n1 != n3, csf_);
    }
    
    void test_method_(from_css) {
      name_property n = name_property::from_css("\"Name text.\"", name_property("Default"));
      assert::are_equal("Name text.", n.text(), csf_);
    }
    
    void test_method_(from_css_with_bad_format) {
      name_property n = name_property::from_css("Name text.", name_property("Default"));
      assert::are_equal("Default", n.text(), csf_);
    }
    
    void test_method_(to_css) {
      name_property n("Name text.");
      assert::are_equal("\"Name text.\"", n.to_css(), csf_);
    }
  };
}
