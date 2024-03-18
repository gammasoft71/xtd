#include <xtd/forms/list_box>
#include <xtd/forms/form>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(list_box_tests) {
    void test_method_(create_list_box) {
      form form;
      list_box list_box;
      list_box.parent(form);
      assert::is_not_zero(list_box.handle(), csf_);
    }
    
    void test_method_(unsorted_add_items) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      
      assert::are_equal(4_z, list_box.items().size(), csf_);
      assert::are_equal("d", list_box.items()[0], csf_);
      assert::are_equal("a", list_box.items()[1], csf_);
      assert::are_equal("c", list_box.items()[2], csf_);
      assert::are_equal("b", list_box.items()[3], csf_);
    }
    
    void test_method_(unsorted_add_items_with_tags) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({{"d", 4}, {"a", 1}, {"c", 3}, {"b", 2}});
      
      assert::are_equal(4_z, list_box.items().size(), csf_);
      assert::are_equal("d", list_box.items()[0], csf_);
      assert::are_equal(4, std::any_cast<int>(list_box.items()[0].tag()), csf_);
      assert::are_equal("a", list_box.items()[1], csf_);
      assert::are_equal(1, std::any_cast<int>(list_box.items()[1].tag()), csf_);
      assert::are_equal("c", list_box.items()[2], csf_);
      assert::are_equal(3, std::any_cast<int>(list_box.items()[2].tag()), csf_);
      assert::are_equal("b", list_box.items()[3], csf_);
      assert::are_equal(2, std::any_cast<int>(list_box.items()[3].tag()), csf_);
    }
    
    void test_method_(sorted_add_items) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.sorted(true);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      
      assert::are_equal(4_z, list_box.items().size(), csf_);
      assert::are_equal("a", list_box.items()[0], csf_);
      assert::are_equal("b", list_box.items()[1], csf_);
      assert::are_equal("c", list_box.items()[2], csf_);
      assert::are_equal("d", list_box.items()[3], csf_);
    }
    
    void test_method_(unsorted_add_items_then_make_sorted) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      list_box.sorted(true);
      
      assert::are_equal(4_z, list_box.items().size(), csf_);
      assert::are_equal("a", list_box.items()[0], csf_);
      assert::are_equal("b", list_box.items()[1], csf_);
      assert::are_equal("c", list_box.items()[2], csf_);
      assert::are_equal("d", list_box.items()[3], csf_);
    }
    
    void test_method_(unsorted_add_items_then_make_std_sorted) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      std::sort(list_box.items().begin(), list_box.items().end());
      
      assert::are_equal(4_z, list_box.items().size(), csf_);
      assert::are_equal("a", list_box.items()[0], csf_);
      assert::are_equal("b", list_box.items()[1], csf_);
      assert::are_equal("c", list_box.items()[2], csf_);
      assert::are_equal("d", list_box.items()[3], csf_);
    }
    
    void test_method_(empty_list_box_selection_index_with_bad_index) {
      form form;
      list_box list_box;
      list_box.parent(form);
      
      assert::throws<argument_exception>([&] {list_box.selected_index(0);}, csf_);
    }
    
    void test_method_(selection_index_with_bad_index) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      
      assert::throws<argument_exception>([&] {list_box.selected_index(4);}, csf_);
    }
  };
}
