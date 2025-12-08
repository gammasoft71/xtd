#include <xtd/collections/generic/dictionary>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/environment>
#include <xtd/size_object>
#include <xtd/string_comparer>
#include <xtd/globalization/translator>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

#if !defined(__XTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM__)
namespace xtd::collections::generic::tests {
  class test_class_(dictionary_tests) {
    auto test_method_(key_type) {
      assert::are_equal(typeof_<int>(), typeof_<dictionary<int, string>::key_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_type>(), typeof_<dictionary<int, string>::key_type>());
    }
    
    auto test_method_(mapped_type) {
      assert::are_equal(typeof_<string>(), typeof_<dictionary<int, string>::mapped_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::mapped_type>(), typeof_<dictionary<int, string>::mapped_type>());
    }
    
    auto test_method_(value_type) {
      assert::are_equal(typeof_<key_value_pair<int, string>>(), typeof_<dictionary<int, string>::value_type > ());
    }
    
    auto test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<dictionary<int, string>::size_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::size_type>(), typeof_<dictionary<int, string>::size_type>());
    }
    
    auto test_method_(hasher) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::hasher>(), typeof_<dictionary<int, string>::hasher>());
    }
    
    auto test_method_(equator) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_equal>(), typeof_<dictionary<int, string>::equator>());
    }
    
    auto test_method_(base_value_type) {
      assert::are_equal(typeof_<std::pair<const int, string>>(), typeof_<dictionary<int, string>::base_value_type > ());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::value_type>(), typeof_<dictionary<int, string>::base_value_type>());
    }
    
    auto test_method_(base_type) {
      assert::are_equal(typeof_<std::unordered_map<int, string, dictionary<int, string>::hasher, dictionary<int, string>::equator>>(), typeof_<dictionary<int, string>::base_type > ());
    }
    
    auto test_method_(iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::icollection<key_value_pair<int, string>>::iterator>(), typeof_<dictionary<int, string>::iterator > ());
    }
    
    auto test_method_(const_iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::icollection<key_value_pair<int, string>>::const_iterator>(), typeof_<dictionary<int, string>::const_iterator > ());
    }
    
    auto test_method_(default_constructor) {
      auto items = dictionary<int, string> {};
      // assert::is_zero(items.capacity()); // Does not work on all platforms.
      assert::is_zero(items.count());
    }
    
    auto test_method_(constructor_with_idictionary) {
      const idictionary<int, string>& items1 = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string>(items1);
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }
    
    auto test_method_(constructor_with_ienumerable) {
      const ienumerable<key_value_pair<int, string>>& items1 = array<key_value_pair<int, string >> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string>(items1);
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }
    
    auto test_method_(constructor_with_ienumerable_and_equality_comparer) {
      const ienumerable<key_value_pair<string, string>>& items1 = array<key_value_pair<string, string >> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}};
      auto items2 = dictionary<string, string>(items1);
      collection_assert::are_equivalent(array<key_value_pair<string, string>> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}}, items2);
      assert::throws<argument_exception>([&] {items2 = dictionary<string, string>(items1, string_comparer::ordinal_ignore_case());});
    }
    
    auto test_method_(constructor_with_equality_comparer) {
      auto items = dictionary<string, string> {};
      items.add("one", "one");
      items.add("oNe", "oNe");
      items.add("OnE", "OnE");
      items.add("ONE", "ONE");
      collection_assert::are_equivalent(array<key_value_pair<string, string>> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}}, items);
      
      items = dictionary<string, string> {string_comparer::ordinal_ignore_case()};
      items.add("one", "one");
      assert::throws<argument_exception>([&] {items.add("oNe", "oNe");});
      assert::throws<argument_exception>([&] {items.add("OnE", "OnE");});
      assert::throws<argument_exception>([&] {items.add("ONE", "ONE");});
    }
    
    auto test_method_(constructor_with_capacity_and_equality_comparer) {
      auto items = dictionary<string, string> {10_z};
      assert::is_greater_or_equal(items.capacity(), 10_z);
      items.add("one", "one");
      items.add("oNe", "oNe");
      items.add("OnE", "OnE");
      items.add("ONE", "ONE");
      collection_assert::are_equivalent(array<key_value_pair<string, string>> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}}, items);
      
      items = dictionary<string, string> {10_z, string_comparer::ordinal_ignore_case()};
      assert::is_greater_or_equal(items.capacity(), 10_z);
      items.add("one", "one");
      assert::throws<argument_exception>([&] {items.add("oNe", "oNe");});
      assert::throws<argument_exception>([&] {items.add("OnE", "OnE");});
      assert::throws<argument_exception>([&] {items.add("ONE", "ONE");});
    }
    
    auto test_method_(constructor_with_capacity) {
      auto items = dictionary<string, string> {10_z};
      assert::is_greater_or_equal(items.capacity(), 10_z);
      items.add("one", "one");
      items.add("oNe", "oNe");
      items.add("OnE", "OnE");
      items.add("ONE", "ONE");
      collection_assert::are_equivalent(array<key_value_pair<string, string>> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}}, items);
    }
    
    auto test_method_(constructor_with_first_and_last_iterators) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end()};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    auto test_method_(constructor_with_first_and_last_iterators_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end()};});
    }
    
    auto test_method_(constructor_with_dictionary) {
      auto items1 = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string> {items1};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }
    
    auto test_method_(constructor_with_unordered_map) {
      auto items1 = std::unordered_map<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string> {items1};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }
    
    auto test_method_(constructor_with_value_type_initializer_list) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    auto test_method_(constructor_with_value_type_initializer_list_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}};});
    }
    
    auto test_method_(constructor_with_base_value_type_initializer_list) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    auto test_method_(constructor_with_base_value_type_initializer_list_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};});
    }
    
    auto test_method_(constructor_with_specified_hasher_and_equator) {
      struct string_hash {
        xtd::size operator()(const string& obj) const {return obj.to_lower().get_hash_code();}
      };
      
      struct string_equal {
        bool operator()(const string& x, const string & y) const {return x.to_lower().equals(y.to_lower());}
      };
      
      auto items = dictionary<string, string, string_hash, string_equal> {};
      // assert::is_zero(items.capacity()); // Does not work on all platforms.
      assert::is_zero(items.count());
      
      items["one"] = "one";
      items["oNe"] = "oNe";
      items["OnE"] = "OnE";
      items["ONE"] = "ONE";
      
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      assert::are_equal("one", enumerator.current().key());
      assert::are_equal("ONE", enumerator.current().value());
      assert::is_false(enumerator.move_next());
      assert::is_true(items.contains_key("one"));
      assert::is_true(items.contains_key("oNe"));
      assert::is_true(items.contains_key("OnE"));
      assert::is_true(items.contains_key("ONE"));
      assert::is_true(items.contains_key("ONe"));
      assert::is_false(items.contains_key("two"));
    }
    
    auto test_method_(const_begin) {
      const auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      
      assert::are_equal(enumerator.current(), *items.begin());
    }
    
    auto test_method_(begin) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      
      assert::are_equal(enumerator.current(), *items.begin());
    }
    
    auto test_method_(capacity) {
      auto items = dictionary<string, int> {};
      // assert::is_zero(items.capacity()); // Does not work on all platforms.
      items.add("one", 1);
      assert::is_greater_or_equal(items.capacity(), 1_z);
      assert::are_equal(items.items().bucket_count(), items.capacity());
      items.add("two", 2);
      assert::is_greater_or_equal(items.capacity(), 2_z);
      assert::are_equal(items.items().bucket_count(), items.capacity());
      items.items().reserve(1000);
      assert::is_greater_or_equal(items.capacity(), 1000_z);
      assert::are_equal(items.items().bucket_count(), items.capacity());
    }
    
    auto test_method_(cbegin) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      
      assert::are_equal(enumerator.current(), *items.cbegin());
    }
    
    auto test_method_(cend) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_not_equal(items.cbegin(), items.cend());
      auto empty_items = dictionary<int, string> {};
      assert::are_equal(empty_items.cbegin(), empty_items.cend());
    }
    
    auto test_method_(count) {
      auto items = dictionary<string, int> {};
      assert::is_zero(items.count());
      items.add("one", 1);
      assert::are_equal(1_z, items.count());
      items.add("two", 2);
      assert::are_equal(2_z, items.count());
    }
    
    auto test_method_(const_end) {
      const auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_not_equal(items.begin(), items.end());
      const auto empty_items = dictionary<int, string> {};
      assert::are_equal(empty_items.begin(), empty_items.end());
    }
    
    auto test_method_(end) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_not_equal(items.begin(), items.end());
      auto empty_items = dictionary<int, string> {};
      assert::are_equal(empty_items.begin(), empty_items.end());
    }
    
    auto test_method_(const_items) {
      const auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.items();
      assert::is_instance_of<dictionary<int, string>::base_type>(items);
      collection_assert::are_equivalent(std::vector<std::pair<const int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    auto test_method_(items) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.items();
      assert::is_instance_of<dictionary<int, string>::base_type>(items);
      collection_assert::are_equivalent(std::vector<std::pair<const int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    auto test_method_(keys) {
      collection_assert::are_equivalent({1, 2, 3, 4, 5}, dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.keys());
    }
    
    auto test_method_(values) {
      collection_assert::are_equivalent({"one", "two", "three", "four", "five"}, dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.values());
    }
    
    auto test_method_(add) {
      auto items = dictionary<int, string> {};
      items.add(1, "one");
      items.add(2, "two");
      items.add(3, "three");
      items.add(4, "four");
      items.add(5, "five");
      assert::throws<argument_exception>([&] {items.add(5, "six");});
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    auto test_method_(begin_with_size) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto bucket_count = items.items().bucket_count();
      auto bucket = items.items().bucket(1);
      assert::is_less(bucket, bucket_count);
      assert::are_not_equal(items.items().end(bucket), items.items().begin(bucket));
      const auto& [key, value] = *items.items().begin(bucket);
      assert::are_equal(1, key);
      assert::are_equal("one", value);
    }
    
    auto test_method_(cbegin_with_size) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto bucket_count = items.items().bucket_count();
      auto bucket = items.items().bucket(1);
      assert::is_less(bucket, bucket_count);
      assert::are_not_equal(items.items().end(bucket), items.items().cbegin(bucket));
      const auto& [key, value] = *items.items().cbegin(bucket);
      assert::are_equal(1, key);
      assert::are_equal("one", value);
    }
    
    auto test_method_(clear) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_equal(5_z, items.count());
      items.clear();
      assert::is_zero(items.count());
    }
    
    auto test_method_(contains_key) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::is_false(items.contains_key(0));
      assert::is_true(items.contains_key(1));
      assert::is_true(items.contains_key(2));
      assert::is_true(items.contains_key(3));
      assert::is_true(items.contains_key(4));
      assert::is_true(items.contains_key(5));
      assert::is_false(items.contains_key(6));
    }
    
    auto test_method_(get_enumerator) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      assert::is_true(items.contains(enumerator.current()));
      assert::is_true(enumerator.move_next());
      assert::is_true(items.contains(enumerator.current()));
      assert::is_true(enumerator.move_next());
      assert::is_true(items.contains(enumerator.current()));
      assert::is_true(enumerator.move_next());
      assert::is_true(items.contains(enumerator.current()));
      assert::is_true(enumerator.move_next());
      assert::is_true(items.contains(enumerator.current()));
      assert::is_false(enumerator.move_next());
    }
  };
}
#endif
