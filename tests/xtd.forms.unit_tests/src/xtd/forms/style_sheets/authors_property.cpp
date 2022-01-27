#include <xtd/forms/style_sheets/authors_property.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_authors_property) {
  public:
    void test_method_(create_default) {
      authors_property a;
      assert::is_true(a == authors_property::empty, csf_);
    }

    void test_method_(create_with_specified_authors) {
      authors_property a("Author1 Author2 Author3");
      assert::are_equal("Author1 Author2 Author3", a.text(), csf_);
    }

    void test_method_(equals) {
      authors_property a1("Author1");
      authors_property a2("Author1");
      authors_property a3("Author2");
      assert::is_true(a1 == a2, csf_);
      assert::is_false(a1 == a3, csf_);
    }

    void test_method_(different) {
      authors_property a1("Author1");
      authors_property a2("Author2");
      authors_property a3("Author1");
      assert::is_true(a1 != a2, csf_);
      assert::is_false(a1 != a3, csf_);
    }
    
    void test_method_(from_css) {
      authors_property a = authors_property::from_css("\"Author1 Author2 Author3\"", authors_property("Default"));
      assert::are_equal("Author1 Author2 Author3", a.text(), csf_);
    }
    
    void test_method_(from_css_with_bad_format) {
      authors_property a = authors_property::from_css("Author1 Author2 Author3", authors_property("Default"));
      assert::are_equal("Default", a.text(), csf_);
    }
    
    void test_method_(to_css) {
      authors_property a("Author1 Author2 Author3");
      assert::are_equal("\"Author1 Author2 Author3\"", a.to_css(), csf_);
    }
  };
}
