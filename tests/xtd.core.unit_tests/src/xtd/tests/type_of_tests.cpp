#include <xtd/type_of>
#include <xtd/web/css/property_dictionary>
#include <xtd/web/css/selector_dictionary>
#include <xtd/collections/specialized/ordered_dictionary>
#include <xtd/collections/specialized/string_collection>
#include <xtd/collections/specialized/string_dictionary>
#include <xtd/collections/specialized/string_key_value_pair>
#include <xtd/collections/array_list>
#include <xtd/collections/comparer>
#include <xtd/collections/dictionary_entry>
#include <xtd/collections/enumerator>
#include <xtd/collections/hashtable>
#include <xtd/collections/icollection>
#include <xtd/collections/ienumerable>
#include <xtd/collections/ienumerator>
#include <xtd/collections/iequality_comparer>
#include <xtd/collections/ilist>
#include <xtd/collections/queue>
#include <xtd/collections/sorted_list>
#include <xtd/collections/stack>
#include <xtd/read_only_span>
#include <xtd/span>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(type_of_tests) {
    auto test_method_(int_type) {
      auto type = type_of<int>();
      assert::are_equal("int", type.full_name());
      assert::are_equal("int", type.name());
      assert::is_empty(type.namespace_());
    }
    
    auto test_method_(int_value) {
      auto type = type_of(0);
      assert::are_equal("int", type.full_name());
      assert::are_equal("int", type.name());
      assert::is_empty(type.namespace_());
    }
    
    struct foo {};
    auto test_method_(foo_type) {
      auto type = type_of<foo>();
      assert::are_equal("xtd::tests::type_of_tests::foo", type.full_name());
      assert::are_equal("foo", type.name());
      assert::are_equal("xtd::tests::type_of_tests", type.namespace_());
    }
    
    auto test_method_(foo_value) {
      auto type = type_of(foo {});
      assert::are_equal("xtd::tests::type_of_tests::foo", type.full_name());
      assert::are_equal("foo", type.name());
      assert::are_equal("xtd::tests::type_of_tests", type.namespace_());
    }
    
    struct foo_object : object {};
    auto test_method_(foo_object_type) {
      auto type = type_of<foo_object>();
      assert::are_equal("xtd::tests::type_of_tests::foo_object", type.full_name());
      assert::are_equal("foo_object", type.name());
      assert::are_equal("xtd::tests::type_of_tests", type.namespace_());
    }
    
    auto test_method_(foo_object_value) {
      auto type = type_of(foo_object {});
      assert::are_equal(foo_object {}.get_type(), type);
      assert::are_equal("xtd::tests::type_of_tests::foo_object", type.full_name());
      assert::are_equal("foo_object", type.name());
      assert::are_equal("xtd::tests::type_of_tests", type.namespace_());
    }
    
    /* xtd::collections::generic::sorted_dictionary is not yet implemented
    auto test_method_(web_css_property_dictionary_type) {
      auto type = type_of<xtd::web::css::property_dictionary>();
      assert::are_equal("xtd::web::css::property_dictionary", type.full_name());
      assert::are_equal("property_dictionary", type.name());
      assert::are_equal("xtd::web::css", type.namespace_());
    }

    auto test_method_(web_css_property_dictionary_value) {
      auto type = type_of(xtd::web::css::property_dictionary {});
      assert::are_equal(xtd::web::css::property_dictionary {}.get_type(), type);
      assert::are_equal("xtd::web::css::property_dictionary", type.full_name());
      assert::are_equal("property_dictionary", type.name());
      assert::are_equal("xtd::web::css", type.namespace_());
    }

    auto test_method_(web_css_selector_dictionary_type) {
      auto type = type_of<xtd::web::css::selector_dictionary>();
      assert::are_equal("xtd::web::css::selector_dictionary", type.full_name());
      assert::are_equal("selector_dictionary", type.name());
      assert::are_equal("xtd::web::css", type.namespace_());
    }
    
    auto test_method_(web_css_selector_dictionary_value) {
      auto type = type_of(xtd::web::css::selector_dictionary {});
      assert::are_equal(xtd::web::css::selector_dictionary {}.get_type(), type);
      assert::are_equal("xtd::web::css::selector_dictionary", type.full_name());
      assert::are_equal("property_dictionary", type.name());
      assert::are_equal("xtd::web::css", type.namespace_());
    }
     */

    auto test_method_(specialized_ordered_dictionary_type) {
      auto type = type_of<xtd::collections::specialized::ordered_dictionary>();
      assert::are_equal("xtd::collections::specialized::ordered_dictionary", type.full_name());
      assert::are_equal("ordered_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(specialized_ordered_dictionary_value) {
      auto type = type_of(xtd::collections::specialized::ordered_dictionary {});
      assert::are_equal(xtd::collections::specialized::ordered_dictionary {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::ordered_dictionary", type.full_name());
      assert::are_equal("ordered_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }

    auto test_method_(specialized_string_collection_type) {
      auto type = type_of<xtd::collections::specialized::string_collection>();
      assert::are_equal("xtd::collections::specialized::string_collection", type.full_name());
      assert::are_equal("string_collection", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(specialized_string_collection_value) {
      auto type = type_of(xtd::collections::specialized::string_collection {});
      assert::are_equal(xtd::collections::specialized::string_collection {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::string_collection", type.full_name());
      assert::are_equal("string_collection", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(specialized_string_dictionary_type) {
      auto type = type_of<xtd::collections::specialized::string_dictionary>();
      assert::are_equal("xtd::collections::specialized::string_dictionary", type.full_name());
      assert::are_equal("string_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(specialized_string_dictionary_value) {
      auto type = type_of(xtd::collections::specialized::string_dictionary {});
      assert::are_equal(xtd::collections::specialized::string_dictionary {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::string_dictionary", type.full_name());
      assert::are_equal("string_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(specialized_string_key_value_pair_type) {
      auto type = type_of<xtd::collections::specialized::string_key_value_pair>();
      assert::are_equal("xtd::collections::specialized::string_key_value_pair", type.full_name());
      assert::are_equal("string_key_value_pair", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(specialized_string_key_value_pair_value) {
      auto type = type_of(xtd::collections::specialized::string_key_value_pair {});
      assert::are_equal(xtd::collections::specialized::string_key_value_pair {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::string_key_value_pair", type.full_name());
      assert::are_equal("string_key_value_pair", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }

    auto test_method_(generic_comparer_wtih_any_object_type) {
      auto type = type_of<xtd::collections::generic::comparer<xtd::any_object>>();
      assert::are_equal("xtd::collections::comparer", type.full_name());
      assert::are_equal("comparer", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(generic_comparer_type) {
      auto type = type_of<xtd::collections::generic::comparer<int>>();
      assert::are_equal("xtd::collections::generic::comparer<int>", type.full_name());
      assert::are_equal("comparer<int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }

    auto test_method_(generic_dictionary_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::dictionary<xtd::any_object, xtd::any_object>>();
      assert::are_equal("xtd::collections::hashtable", type.full_name());
      assert::are_equal("hashtable", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_dictionary_with_any_object_value) {
      auto type = type_of(xtd::collections::generic::dictionary<xtd::any_object, xtd::any_object> {});
      assert::are_equal(xtd::collections::generic::dictionary<xtd::any_object, xtd::any_object> {}.get_type(), type);
      assert::are_equal("xtd::collections::hashtable", type.full_name());
      assert::are_equal("hashtable", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(generic_dictionary_with_string_type) {
      auto type = type_of<xtd::collections::generic::dictionary<xtd::string, xtd::string>>();
      assert::are_equal("xtd::collections::specialized::string_dictionary", type.full_name());
      assert::are_equal("string_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(generic_dictionary_with_string_value) {
      auto type = type_of(xtd::collections::generic::dictionary<xtd::string, xtd::string> {});
      assert::are_equal(xtd::collections::generic::dictionary<xtd::string, xtd::string> {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::string_dictionary", type.full_name());
      assert::are_equal("string_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }

    auto test_method_(generic_dictionary_type) {
      auto type = type_of<xtd::collections::generic::dictionary<xtd::string, int>>();
      assert::are_equal("xtd::collections::generic::dictionary<xtd::string, int, xtd::collections::generic::helpers::hasher<xtd::string>, xtd::collections::generic::helpers::equator<xtd::string>, std::allocator<std::pair<xtd::string const, int>>>", type.full_name());
      assert::are_equal("dictionary<xtd::string, int, xtd::collections::generic::helpers::hasher<xtd::string>, xtd::collections::generic::helpers::equator<xtd::string>, std::allocator<std::pair<xtd::string const, int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(generic_dictionary_value) {
      auto type = type_of(xtd::collections::generic::dictionary<xtd::string, int> {});
      assert::are_equal(xtd::collections::generic::dictionary<xtd::string, int> {}.get_type(), type);
      assert::are_equal("xtd::collections::generic::dictionary<xtd::string, int, xtd::collections::generic::helpers::hasher<xtd::string>, xtd::collections::generic::helpers::equator<xtd::string>, std::allocator<std::pair<xtd::string const, int>>>", type.full_name());
      assert::are_equal("dictionary<xtd::string, int, xtd::collections::generic::helpers::hasher<xtd::string>, xtd::collections::generic::helpers::equator<xtd::string>, std::allocator<std::pair<xtd::string const, int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(generic_key_value_pair_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::key_value_pair<xtd::any_object, xtd::any_object>>();
      assert::are_equal("xtd::collections::dictionary_entry", type.full_name());
      assert::are_equal("dictionary_entry", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_key_value_pair_with_any_object_value) {
      auto type = type_of(xtd::collections::generic::key_value_pair<xtd::any_object, xtd::any_object> {});
      assert::are_equal(xtd::collections::generic::key_value_pair<xtd::any_object, xtd::any_object> {}.get_type(), type);
      assert::are_equal("xtd::collections::dictionary_entry", type.full_name());
      assert::are_equal("dictionary_entry", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_key_value_pair_with_string_type) {
      auto type = type_of<xtd::collections::generic::key_value_pair<xtd::string, xtd::string>>();
      assert::are_equal("xtd::collections::specialized::string_key_value_pair", type.full_name());
      assert::are_equal("string_key_value_pair", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(generic_key_value_pair_with_string_value) {
      auto type = type_of(xtd::collections::generic::key_value_pair<xtd::string, xtd::string> {});
      assert::are_equal(xtd::collections::generic::key_value_pair<xtd::string, xtd::string> {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::string_key_value_pair", type.full_name());
      assert::are_equal("string_key_value_pair", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(generic_key_value_pair_type) {
      auto type = type_of<xtd::collections::generic::key_value_pair<xtd::string, int>>();
      assert::are_equal("xtd::collections::generic::key_value_pair<xtd::string, int>", type.full_name());
      assert::are_equal("key_value_pair<xtd::string, int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(generic_key_value_pair_value) {
      auto type = type_of(xtd::collections::generic::key_value_pair<xtd::string, int> {});
      assert::are_equal(xtd::collections::generic::key_value_pair<xtd::string, int> {}.get_type(), type);
      assert::are_equal("xtd::collections::generic::key_value_pair<xtd::string, int>", type.full_name());
      assert::are_equal("key_value_pair<xtd::string, int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(genric_icollection_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::icollection<xtd::any_object>>();
      assert::are_equal("xtd::collections::icollection", type.full_name());
      assert::are_equal("icollection", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(genric_icollection_type) {
      auto type = type_of<xtd::collections::generic::icollection<int>>();
      assert::are_equal("xtd::collections::generic::icollection<int>", type.full_name());
      assert::are_equal("icollection<int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(genric_ienumerable_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::ienumerable<xtd::any_object>>();
      assert::are_equal("xtd::collections::ienumerable", type.full_name());
      assert::are_equal("ienumerable", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(genric_ienumerable_type) {
      auto type = type_of<xtd::collections::generic::ienumerable<int>>();
      assert::are_equal("xtd::collections::generic::ienumerable<int>", type.full_name());
      assert::are_equal("ienumerable<int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(genric_ienumerator_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::ienumerator<xtd::any_object>>();
      assert::are_equal("xtd::collections::ienumerator", type.full_name());
      assert::are_equal("ienumerator", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(genric_ienumerator_type) {
      auto type = type_of<xtd::collections::generic::ienumerator<int>>();
      assert::are_equal("xtd::collections::generic::ienumerator<int>", type.full_name());
      assert::are_equal("ienumerator<int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(genric_iequality_comparer_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::iequality_comparer<xtd::any_object>>();
      assert::are_equal("xtd::collections::iequality_comparer", type.full_name());
      assert::are_equal("iequality_comparer", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(genric_iequality_comparer_type) {
      auto type = type_of<xtd::collections::generic::iequality_comparer<int>>();
      assert::are_equal("xtd::collections::generic::iequality_comparer<int>", type.full_name());
      assert::are_equal("iequality_comparer<int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(genric_ilist_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::ilist<xtd::any_object>>();
      assert::are_equal("xtd::collections::ilist", type.full_name());
      assert::are_equal("ilist", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(genric_ilist_type) {
      auto type = type_of<xtd::collections::generic::ilist<int>>();
      assert::are_equal("xtd::collections::generic::ilist<int>", type.full_name());
      assert::are_equal("ilist<int>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }

    auto test_method_(generic_list_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::list<xtd::any_object>>();
      assert::are_equal("xtd::collections::array_list", type.full_name());
      assert::are_equal("array_list", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_list_with_any_object_value) {
      auto type = type_of(xtd::collections::generic::list<xtd::any_object> {});
      assert::are_equal(xtd::collections::generic::list<xtd::any_object> {}.get_type(), type);
      assert::are_equal("xtd::collections::array_list", type.full_name());
      assert::are_equal("array_list", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(generic_list_with_string_type) {
      auto type = type_of<xtd::collections::generic::list<xtd::string>>();
      assert::are_equal("xtd::collections::specialized::string_collection", type.full_name());
      assert::are_equal("string_collection", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(generic_list_with_string_value) {
      auto type = type_of(xtd::collections::generic::list<xtd::string> {});
      assert::are_equal(xtd::collections::generic::list<xtd::string> {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::string_collection", type.full_name());
      assert::are_equal("string_collection", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }

    auto test_method_(generic_list_type) {
      auto type = type_of<xtd::collections::generic::list<int>>();
      assert::are_equal("xtd::collections::generic::list<int, std::allocator<int>>", type.full_name());
      assert::are_equal("list<int, std::allocator<int>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(generic_list_value) {
      auto type = type_of(xtd::collections::generic::list<int> {});
      assert::are_equal(xtd::collections::generic::list<int> {}.get_type(), type);
      assert::are_equal("xtd::collections::generic::list<int, std::allocator<int>>", type.full_name());
      assert::are_equal("list<int, std::allocator<int>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }

    auto test_method_(generic_ordered_dictionary_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::ordered_dictionary<xtd::any_object, xtd::any_object>>();
      assert::are_equal("xtd::collections::specialized::ordered_dictionary", type.full_name());
      assert::are_equal("ordered_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }
    
    auto test_method_(generic_ordered_dictionary_with_any_object_value) {
      auto type = type_of(xtd::collections::generic::ordered_dictionary<xtd::any_object, xtd::any_object> {});
      assert::are_equal(xtd::collections::generic::ordered_dictionary<xtd::any_object, xtd::any_object> {}.get_type(), type);
      assert::are_equal("xtd::collections::specialized::ordered_dictionary", type.full_name());
      assert::are_equal("ordered_dictionary", type.name());
      assert::are_equal("xtd::collections::specialized", type.namespace_());
    }

    auto test_method_(generic_ordered_dictionary_type) {
      auto type = type_of<xtd::collections::generic::ordered_dictionary<xtd::string, int>>();
      assert::are_equal("xtd::collections::generic::ordered_dictionary<xtd::string, int, std::allocator<std::pair<xtd::string const, int>>>", type.full_name());
      assert::are_equal("ordered_dictionary<xtd::string, int, std::allocator<std::pair<xtd::string const, int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(generic_ordered_dictionary_value) {
      auto type = type_of(xtd::collections::generic::ordered_dictionary<xtd::string, int> {});
      assert::are_equal(xtd::collections::generic::ordered_dictionary<xtd::string, int> {}.get_type(), type);
      assert::are_equal("xtd::collections::generic::ordered_dictionary<xtd::string, int, std::allocator<std::pair<xtd::string const, int>>>", type.full_name());
      assert::are_equal("ordered_dictionary<xtd::string, int, std::allocator<std::pair<xtd::string const, int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }

    auto test_method_(generic_queue_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::queue<xtd::any_object>>();
      assert::are_equal("xtd::collections::queue", type.full_name());
      assert::are_equal("queue", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_queue_with_any_object_value) {
      auto type = type_of(xtd::collections::generic::queue<xtd::any_object> {});
      assert::are_equal(xtd::collections::generic::queue<xtd::any_object> {}.get_type(), type);
      assert::are_equal("xtd::collections::queue", type.full_name());
      assert::are_equal("queue", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_queue_type) {
      auto type = type_of<xtd::collections::generic::queue<int>>();
      assert::are_equal("xtd::collections::generic::queue<int, std::deque<int, std::allocator<int>>>", type.full_name());
      assert::are_equal("queue<int, std::deque<int, std::allocator<int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(generic_queue_value) {
      auto type = type_of(xtd::collections::generic::queue<int> {});
      assert::are_equal(xtd::collections::generic::queue<int> {}.get_type(), type);
      assert::are_equal("xtd::collections::generic::queue<int, std::deque<int, std::allocator<int>>>", type.full_name());
      assert::are_equal("queue<int, std::deque<int, std::allocator<int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }

    auto test_method_(generic_stack_with_any_object_type) {
      auto type = type_of<xtd::collections::generic::stack<xtd::any_object>>();
      assert::are_equal("xtd::collections::stack", type.full_name());
      assert::are_equal("stack", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_stack_with_any_object_value) {
      auto type = type_of(xtd::collections::generic::stack<xtd::any_object> {});
      assert::are_equal(xtd::collections::generic::stack<xtd::any_object> {}.get_type(), type);
      assert::are_equal("xtd::collections::stack", type.full_name());
      assert::are_equal("stack", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(generic_stack_type) {
      auto type = type_of<xtd::collections::generic::stack<int>>();
      assert::are_equal("xtd::collections::generic::stack<int, std::deque<int, std::allocator<int>>>", type.full_name());
      assert::are_equal("stack<int, std::deque<int, std::allocator<int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }
    
    auto test_method_(generic_stack_value) {
      auto type = type_of(xtd::collections::generic::stack<int> {});
      assert::are_equal(xtd::collections::generic::stack<int> {}.get_type(), type);
      assert::are_equal("xtd::collections::generic::stack<int, std::deque<int, std::allocator<int>>>", type.full_name());
      assert::are_equal("stack<int, std::deque<int, std::allocator<int>>>", type.name());
      assert::are_equal("xtd::collections::generic", type.namespace_());
    }

    auto test_method_(collections_array_list_type) {
      auto type = type_of<xtd::collections::array_list>();
      assert::are_equal("xtd::collections::array_list", type.full_name());
      assert::are_equal("array_list", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_array_list_value) {
      auto type = type_of(xtd::collections::array_list {});
      assert::are_equal(xtd::collections::array_list {}.get_type(), type);
      assert::are_equal("xtd::collections::array_list", type.full_name());
      assert::are_equal("array_list", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(collections_comparer_type) {
      auto type = type_of<xtd::collections::comparer>();
      assert::are_equal("xtd::collections::comparer", type.full_name());
      assert::are_equal("comparer", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(colelctions_dictionary_entry_type) {
      auto type = type_of<xtd::collections::dictionary_entry>();
      assert::are_equal("xtd::collections::dictionary_entry", type.full_name());
      assert::are_equal("dictionary_entry", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_dictionary_entry_value) {
      auto type = type_of(xtd::collections::dictionary_entry {});
      assert::are_equal(xtd::collections::dictionary_entry {}.get_type(), type);
      assert::are_equal("xtd::collections::dictionary_entry", type.full_name());
      assert::are_equal("dictionary_entry", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_enumerator_type) {
      auto type = type_of<xtd::collections::enumerator>();
      assert::are_equal("xtd::collections::enumerator", type.full_name());
      assert::are_equal("enumerator", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(collections_enumerator_value) {
      auto type = type_of(xtd::collections::enumerator {});
      assert::are_equal(xtd::collections::enumerator {}.get_type(), type);
      assert::are_equal("xtd::collections::enumerator", type.full_name());
      assert::are_equal("enumerator", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(collections_hashtable_type) {
      auto type = type_of<xtd::collections::hashtable>();
      assert::are_equal("xtd::collections::hashtable", type.full_name());
      assert::are_equal("hashtable", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_hashtable_value) {
      auto type = type_of(xtd::collections::hashtable {});
      assert::are_equal(xtd::collections::hashtable {}.get_type(), type);
      assert::are_equal("xtd::collections::hashtable", type.full_name());
      assert::are_equal("hashtable", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_icollection_type) {
      auto type = type_of<xtd::collections::icollection>();
      assert::are_equal("xtd::collections::icollection", type.full_name());
      assert::are_equal("icollection", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_ienumerable_type) {
      auto type = type_of<xtd::collections::ienumerable>();
      assert::are_equal("xtd::collections::ienumerable", type.full_name());
      assert::are_equal("ienumerable", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_ienumerator_type) {
      auto type = type_of<xtd::collections::ienumerator>();
      assert::are_equal("xtd::collections::ienumerator", type.full_name());
      assert::are_equal("ienumerator", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_iequality_comparer_type) {
      auto type = type_of<xtd::collections::iequality_comparer>();
      assert::are_equal("xtd::collections::iequality_comparer", type.full_name());
      assert::are_equal("iequality_comparer", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_ilist_type) {
      auto type = type_of<xtd::collections::ilist>();
      assert::are_equal("xtd::collections::ilist", type.full_name());
      assert::are_equal("ilist", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(collections_queue_type) {
      auto type = type_of<xtd::collections::queue>();
      assert::are_equal("xtd::collections::queue", type.full_name());
      assert::are_equal("queue", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_queue_value) {
      auto type = type_of(xtd::collections::queue {});
      assert::are_equal(xtd::collections::queue {}.get_type(), type);
      assert::are_equal("xtd::collections::queue", type.full_name());
      assert::are_equal("queue", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    /* xtd::collections::generic::sorted_list is not yet implemented
    auto test_method_(collections_sorted_list_type) {
      auto type = type_of<xtd::collections::sorted_list>();
      assert::are_equal("xtd::collections::sorted_list", type.full_name());
      assert::are_equal("sorted_list", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
    
    auto test_method_(collections_sorted_list_value) {
      auto type = type_of(xtd::collections::sorted_list {});
      assert::are_equal(xtd::collections::sorted_list {}.get_type(), type);
      assert::are_equal("xtd::collections::sorted_list", type.full_name());
      assert::are_equal("sorted_list", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }
     */

    auto test_method_(collections_stack_value) {
      auto type = type_of(xtd::collections::stack {});
      assert::are_equal(xtd::collections::stack {}.get_type(), type);
      assert::are_equal("xtd::collections::stack", type.full_name());
      assert::are_equal("stack", type.name());
      assert::are_equal("xtd::collections", type.namespace_());
    }

    auto test_method_(string_type) {
      auto type = type_of<string>();
      assert::are_equal("xtd::string", type.full_name());
      assert::are_equal("string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(string_value) {
      auto type = type_of(string::empty_string);
      assert::are_equal(string::empty_string.get_type(), type);
      assert::are_equal("xtd::string", type.full_name());
      assert::are_equal("string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(u16string_type) {
      auto type = type_of<u16string>();
      assert::are_equal("xtd::u16string", type.full_name());
      assert::are_equal("u16string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(u16string_value) {
      auto type = type_of(u16string::empty_string);
      assert::are_equal(u16string::empty_string.get_type(), type);
      assert::are_equal("xtd::u16string", type.full_name());
      assert::are_equal("u16string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(u32string_type) {
      auto type = type_of<u32string>();
      assert::are_equal("xtd::u32string", type.full_name());
      assert::are_equal("u32string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(u32string_value) {
      auto type = type_of(u32string::empty_string);
      assert::are_equal(u32string::empty_string.get_type(), type);
      assert::are_equal("xtd::u32string", type.full_name());
      assert::are_equal("u32string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(u8string_type) {
      auto type = type_of<u8string>();
      assert::are_equal("xtd::u8string", type.full_name());
      assert::are_equal("u8string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(u8string_value) {
      auto type = type_of(u8string::empty_string);
      assert::are_equal(u8string::empty_string.get_type(), type);
      assert::are_equal("xtd::u8string", type.full_name());
      assert::are_equal("u8string", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(wstring_type) {
      auto type = type_of<wstring>();
      assert::are_equal("xtd::wstring", type.full_name());
      assert::are_equal("wstring", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(wstring_value) {
      auto type = type_of(wstring::empty_string);
      assert::are_equal(wstring::empty_string.get_type(), type);
      assert::are_equal("xtd::wstring", type.full_name());
      assert::are_equal("wstring", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(read_only_span_type) {
      auto type = type_of<read_only_span<int>>();
      assert::are_equal("xtd::read_only_span<int, xtd::dynamic_extent>", type.full_name());
      assert::are_equal("read_only_span<int, xtd::dynamic_extent>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(read_only_span_with_size_type) {
      auto type = type_of<read_only_span<int, 5>>();
      assert::are_equal("xtd::read_only_span<int, 5ul>", type.full_name());
      assert::are_equal("read_only_span<int, 5ul>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(read_only_span_value) {
      auto type = type_of(read_only_span<int> {});
      assert::are_equal(read_only_span<int> {}.get_type(), type);
      assert::are_equal("xtd::read_only_span<int, xtd::dynamic_extent>", type.full_name());
      assert::are_equal("read_only_span<int, xtd::dynamic_extent>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(read_only_span_with_size_value) {
      auto type = type_of(read_only_span<int, 5> {});
      assert::are_equal(read_only_span<int, 5> {}.get_type(), type);
      assert::are_equal("xtd::read_only_span<int, 5ul>", type.full_name());
      assert::are_equal("read_only_span<int, 5ul>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }

    auto test_method_(span_type) {
      auto type = type_of<span<int>>();
      assert::are_equal("xtd::span<int, xtd::dynamic_extent>", type.full_name());
      assert::are_equal("span<int, xtd::dynamic_extent>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(span_with_size_type) {
      auto type = type_of<span<int, 5>>();
      assert::are_equal("xtd::span<int, 5ul>", type.full_name());
      assert::are_equal("span<int, 5ul>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }

    auto test_method_(span_value) {
      auto type = type_of(span<int> {});
      assert::are_equal(span<int> {}.get_type(), type);
      assert::are_equal("xtd::span<int, xtd::dynamic_extent>", type.full_name());
      assert::are_equal("span<int, xtd::dynamic_extent>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
    
    auto test_method_(span_with_size_value) {
      auto type = type_of(span<int, 5> {});
      assert::are_equal(span<int, 5> {}.get_type(), type);
      assert::are_equal("xtd::span<int, 5ul>", type.full_name());
      assert::are_equal("span<int, 5ul>", type.name());
      assert::are_equal("xtd", type.namespace_());
    }
  };
}
