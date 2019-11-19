#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_list_box) {
  public:
    void test_method_(create_list_box) {
      form form;
      list_box list_box;
      list_box.parent(form);
      assert::is_not_zero_(list_box.handle());
    }
    
    void test_method_(unsorted_add_items) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      
      assert::are_equal_("d", list_box.items()[0]);
      assert::are_equal_("a", list_box.items()[1]);
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_("b", list_box.items()[3]);
    }
    
    void test_method_(sorted_add_items) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.sorted(true);
      //list_box.items().push_back_range({"d", "a", "c", "b"});
      list_box.items().push_back("d");
      list_box.items().push_back("a");
      list_box.items().push_back("c");
      list_box.items().push_back("b");

      assert::are_equal_("a", list_box.items()[0]);
      assert::are_equal_("b", list_box.items()[1]);
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_("d", list_box.items()[3]);
    }

    void test_method_(unsorted_add_items_then_make_sorted) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      list_box.sorted(true);
      
      assert::are_equal_("a", list_box.items()[0]);
      assert::are_equal_("b", list_box.items()[1]);
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_("d", list_box.items()[3]);
    }
  };
}
