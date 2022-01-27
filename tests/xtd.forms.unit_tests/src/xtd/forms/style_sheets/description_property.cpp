#include <xtd/forms/style_sheets/description_property.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_description_property) {
  public:
    void test_method_(create_default) {
      description_property d;
      assert::is_true(d == description_property::empty, csf_);
    }

    void test_method_(create_with_specified_authors) {
      description_property d("Description text.");
      assert::are_equal("Description text.", d.text(), csf_);
    }

    void test_method_(equals) {
      description_property d1("Description 1.");
      description_property d2("Description 1.");
      description_property d3("Description 2.");
      assert::is_true(d1 == d2, csf_);
      assert::is_false(d1 == d3, csf_);
    }

    void test_method_(different) {
      description_property d1("Description 1.");
      description_property d2("Description 2.");
      description_property d3("Description 1.");
      assert::is_true(d1 != d2, csf_);
      assert::is_false(d1 != d3, csf_);
    }
    
    void test_method_(from_css) {
      description_property d = description_property::from_css("\"Description text.\"", description_property("Default"));
      assert::are_equal("Description text.", d.text(), csf_);
    }
    
    void test_method_(from_css_with_bad_format) {
      description_property d = description_property::from_css("Description text.", description_property("Default"));
      assert::are_equal("Default", d.text(), csf_);
    }
    
    void test_method_(to_css) {
      description_property d("Description text.");
      assert::are_equal("\"Description text.\"", d.to_css(), csf_);
    }
  };
}
