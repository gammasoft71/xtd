#include <xtd/collections/generic/dictionary>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/environment>
#include <xtd/literals>
#include <xtd/size_object>
#include <xtd/string_comparer>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(dictionary_tests) {
    void test_method_(key_type) {
      assert::are_equal(typeof_<int>(), typeof_<dictionary<int, string>::key_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_type>(), typeof_<dictionary<int, string>::key_type>());
    }
    
    void test_method_(mapped_type) {
      assert::are_equal(typeof_<string>(), typeof_<dictionary<int, string>::mapped_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::mapped_type>(), typeof_<dictionary<int, string>::mapped_type>());
    }
    
    void test_method_(value_type) {
      assert::are_equal(typeof_<key_value_pair<int, string>>(), typeof_<dictionary<int, string>::value_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<dictionary<int, string>::size_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::size_type>(), typeof_<dictionary<int, string>::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<dictionary<int, string>::difference_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::difference_type>(), typeof_<dictionary<int, string>::difference_type>());
    }
    
    void test_method_(hasher) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::hasher>(), typeof_<dictionary<int, string>::hasher>());
    }
    
    void test_method_(equator) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_equal>(), typeof_<dictionary<int, string>::equator>());
    }
    
    void test_method_(key_equal) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::key_equal>(), typeof_<dictionary<int, string>::key_equal>());
    }
    
    void test_method_(allocator_type) {
      assert::are_equal(typeof_<helpers::allocator<std::pair<const int, string>>>(), typeof_<dictionary<int, string>::allocator_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::allocator_type>(), typeof_<dictionary<int, string>::allocator_type>());
    }

    void test_method_(base_value_type) {
      assert::are_equal(typeof_<std::pair<const int, string>>(), typeof_<dictionary<int, string>::base_value_type>());
      assert::are_equal(typeof_<dictionary<int, string>::base_type::value_type>(), typeof_<dictionary<int, string>::base_value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::unordered_map<int, string, dictionary<int, string>::hasher, dictionary<int, string>::equator>>(), typeof_<dictionary<int, string>::base_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<key_value_pair<int, string>&>(), typeof_<dictionary<int, string>::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const key_value_pair<int, string>&>(), typeof_<dictionary<int, string>::const_reference>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<std::allocator_traits<helpers::allocator<std::pair<const int, string>>>::pointer>(), typeof_<dictionary<int, string>::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<std::allocator_traits<helpers::allocator<std::pair<const int, string>>>::const_pointer>(), typeof_<dictionary<int, string>::const_pointer>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::icollection<key_value_pair<int, string>>::iterator>(), typeof_<dictionary<int, string>::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::icollection<key_value_pair<int, string>>::const_iterator>(), typeof_<dictionary<int, string>::const_iterator>());
    }
    
    void test_method_(local_iterator) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::local_iterator>(), typeof_<dictionary<int, string>::local_iterator>());
    }
    
    void test_method_(const_local_iterator) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::const_local_iterator>(), typeof_<dictionary<int, string>::const_local_iterator>());
    }
    
    void test_method_(node_type) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::node_type>(), typeof_<dictionary<int, string>::node_type>());
    }
    
    void test_method_(insert_return_type) {
      assert::are_equal(typeof_<dictionary<int, string>::base_type::insert_return_type>(), typeof_<dictionary<int, string>::insert_return_type>());
    }

    void test_method_(default_constructor) {
      auto items = dictionary<int, string> {};
      // assert::is_zero(items.capacity()); // Does not work on all platforms.
      assert::is_zero(items.count());
    }
    
    void test_method_(constructor_with_idictionary) {
      const idictionary<int, string>& items1 = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string>(items1);
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }
    
    void test_method_(constructor_with_ienumerable) {
      const ienumerable<key_value_pair<int, string>>& items1 = array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string>(items1);
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }

    void test_method_(constructor_with_ienumerable_and_equality_comparer) {
      const ienumerable<key_value_pair<string, string>>& items1 = array<key_value_pair<string, string>> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}};
      auto items2 = dictionary<string, string>(items1);
      collection_assert::are_equivalent(array<key_value_pair<string, string>> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}}, items2);
      assert::throws<argument_exception>([&]{items2 = dictionary<string, string>(items1, string_comparer::ordinal_ignore_case());});
    }

    void test_method_(constructor_with_equality_comparer) {
      auto items = dictionary<string, string> {};
      items.add("one", "one");
      items.add("oNe", "oNe");
      items.add("OnE", "OnE");
      items.add("ONE", "ONE");
      collection_assert::are_equivalent(array<key_value_pair<string, string>> {{"one", "one"}, {"oNe", "oNe"}, {"OnE", "OnE"}, {"ONE", "ONE"}}, items);
      
      items = dictionary<string, string> {string_comparer::ordinal_ignore_case()};
      items.add("one", "one");
      assert::throws<argument_exception>([&]{items.add("oNe", "oNe");});
      assert::throws<argument_exception>([&]{items.add("OnE", "OnE");});
      assert::throws<argument_exception>([&]{items.add("ONE", "ONE");});
    }

    void test_method_(constructor_with_capacity_and_equality_comparer) {
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
      assert::throws<argument_exception>([&]{items.add("oNe", "oNe");});
      assert::throws<argument_exception>([&]{items.add("OnE", "OnE");});
      assert::throws<argument_exception>([&]{items.add("ONE", "ONE");});
    }

    void test_method_(constructor_with_bucket_count) {
      auto items = dictionary<int, string> {42_z};
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::is_zero(items.count());
    }

    /* Confict with dictionary(size_t capacity, const equality_comparer_t& comparer) constructor
    void test_method_(constructor_with_bucket_count_and_hash) {
      auto items = dictionary<int, string> {42_z, helpers::hasher<int> {}};
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::is_zero(items.count());
    }*/

    void test_method_(constructor_with_bucket_count_hash_and_equator) {
      auto items = dictionary<int, string> {42_z, helpers::hasher<int> {}, helpers::equator<int> {}};
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::is_zero(items.count());
    }

    void test_method_(constructor_with_bucket_count_hash_equator_and_hasher) {
      auto items = dictionary<int, string> {42_z, helpers::hasher<int> {}, helpers::equator<int> {}, helpers::allocator<std::pair<int, string>> {}};
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::is_zero(items.count());
    }

    /* Confict with dictionary(size_t capacity, const equality_comparer_t& comparer) constructor
    void test_method_(constructor_with_bucket_count_and_allocator) {
      auto items = dictionary<int, string> {42_z, helpers::allocator<std::pair<int, string>> {}};
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::is_zero(items.count());
    }*/

    void test_method_(constructor_with_bucket_count_hasher_and_allocator) {
      auto items = dictionary<int, string> {42_z, helpers::hasher<int> {}, helpers::allocator<std::pair<int, string>> {}};
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::is_zero(items.count());
    }

    /* Conflict with dictionary(const equality_comparer_t& comparer) constructor.
    void test_method_(constructor_with_allocator) {
      auto items = dictionary<int, string> {helpers::allocator<std::pair<int, string>> {}};
      assert::is_zero(items.capacity());
      assert::is_zero(items.count());
    }*/

    void test_method_(constructor_with_first_and_last_iterators) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end()};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_first_and_last_iterators_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end()};});
    }

    void test_method_(constructor_with_first_and_last_iterators_and_bucket_count) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end(), 42_z};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end(), 42_z};});
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_and_hasher) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_hasher_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}};});
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_hasher_and_equator) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}, helpers::equator<int> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_hasher_equator_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}, helpers::equator<int> {}};});
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_hasher_equator_and_allocator) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}, helpers::equator<int> {}, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_hasher_equator_allocator_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}, helpers::equator<int> {}, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_and_allocator) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_allocator_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_hasher_and_allocator) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_first_and_last_iterators_bucket_count_hasher_allocator_and_duplicate_items) {
      auto init = std::initializer_list<std::pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {init.begin(), init.end(), 42_z, helpers::hasher<int> {}, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_dictionary) {
      auto items1 = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string> {items1};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }

    /* Conflict with dictionary(const idictionary<key_t, value_t>& dictionary, const equality_comparer_t& comparer) constructor.
    void test_method_(constructor_with_dictionary_and_allocator) {
      auto items1 = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string> {items1, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }*/

    void test_method_(constructor_with_unordered_map) {
      auto items1 = std::unordered_map<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string> {items1};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }

    void test_method_(constructor_with_unordered_map_and_allocator) {
      auto items1 = std::unordered_map<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto items2 = dictionary<int, string> {items1, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items2);
    }

    void test_method_(constructor_with_value_type_initializer_list) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    void test_method_(constructor_with_value_type_initializer_list_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}};});
    }
    
    void test_method_(constructor_with_value_type_initializer_list_and_bucket_count) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}, 42_z};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    void test_method_(constructor_with_value_type_initializer_list_bucket_count_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}, 42_z};});
    }

    void test_method_(constructor_with_value_type_initializer_list_bucket_count_and_hasher) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}, 42_z, helpers::hasher<int> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    void test_method_(constructor_with_value_type_initializer_list_bucket_count_hasher_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}, 42_z, helpers::hasher<int> {}};});
    }
    
    void test_method_(constructor_with_value_type_initializer_list_bucket_count_hasher_and_equator) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    void test_method_(constructor_with_value_type_initializer_list_bucket_count_hasher_equator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}};});
    }

    void test_method_(constructor_with_value_type_initializer_list_bucket_count_hasher_equator_and_allocator) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_value_type_initializer_list_bucket_count_hasher_equator_allocator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_value_type_initializer_list_bucket_count_and_allocator) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}, 42_z, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_value_type_initializer_list_bucket_count_allocator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}, 42_z, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_value_type_initializer_list_bucket_count_hasher_and_allocator) {
      auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five")}, 42_z, helpers::hasher<int> {}, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_value_type_initializer_list_bucket_count_hasher_allocator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{key_value_pair<>::create(1, "one"), key_value_pair<>::create(2, "two"), key_value_pair<>::create(3, "three"), key_value_pair<>::create(4, "four"), key_value_pair<>::create(5, "five"), key_value_pair<>::create(5, "six")}, 42_z, helpers::hasher<int> {}, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_base_value_type_initializer_list) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_base_value_type_initializer_list_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}};});
    }

    void test_method_(constructor_with_base_value_type_initializer_list_and_bucket_count) {
      auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, 42_z};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}}, 42_z};});
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_and_hasher) {
      auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, 42_z, helpers::hasher<int> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_hasher_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}}, 42_z, helpers::hasher<int> {}};});
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_hasher_and_equator) {
      auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_hasher_equator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}};});
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_hasher_equator_and_allocator) {
      auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_hasher_equator_allocator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}}, 42_z, helpers::hasher<int> {}, helpers::equator<int> {}, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_and_allocator) {
      auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, 42_z, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_allocator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}}, 42_z, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_hasher_and_allocator) {
      auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, 42_z, helpers::hasher<int> {}, helpers::allocator<std::pair<int, string>> {}};
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(constructor_with_base_value_type_initializer_list_bucket_count_hasher_allocator_and_duplicate_items) {
      assert::throws<argument_exception>([&] {auto items = dictionary<int, string> {{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {5, "six"}}, 42_z, helpers::hasher<int> {}, helpers::allocator<std::pair<int, string>> {}};});
    }

    void test_method_(constructor_with_specified_hasher_and_equator) {
      struct string_hash {
        xtd::size operator ()(const string& obj) const {return obj.to_lower().get_hash_code();}
      };
      
      struct string_equal {
        bool operator ()(const string& x, const string & y) const {return x.to_lower().equals(y.to_lower());}
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
    
    void test_method_(const_begin) {
      const auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      
      assert::are_equal(enumerator.current(), *items.begin());
    }
    
    void test_method_(begin) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      
      assert::are_equal(enumerator.current(), *items.begin());
    }

    void test_method_(bucket_count) {
      auto items = dictionary<string, int> {};
      // assert::is_zero(items.bucket_count()); // Does not work on all platforms.
      items.add("one", 1);
      assert::is_greater_or_equal(items.bucket_count(), 1_z);
      assert::are_equal(items.capacity(), items.bucket_count());
      items.add("two", 2);
      assert::is_greater_or_equal(items.bucket_count(), 2_z);
      assert::are_equal(items.capacity(), items.bucket_count());
      items.reserve(1000);
      assert::is_greater_or_equal(items.bucket_count(), 1000_z);
      assert::are_equal(items.capacity(), items.bucket_count());
    }

    void test_method_(capacity) {
      auto items = dictionary<string, int> {};
      // assert::is_zero(items.capacity()); // Does not work on all platforms.
      items.add("one", 1);
      assert::is_greater_or_equal(items.capacity(), 1_z);
      assert::are_equal(items.bucket_count(), items.capacity());
      items.add("two", 2);
      assert::is_greater_or_equal(items.capacity(), 2_z);
      assert::are_equal(items.bucket_count(), items.capacity());
      items.reserve(1000);
      assert::is_greater_or_equal(items.capacity(), 1000_z);
      assert::are_equal(items.bucket_count(), items.capacity());
    }
    
    void test_method_(cbegin) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto enumerator = items.get_enumerator();
      assert::is_true(enumerator.move_next());
      
      assert::are_equal(enumerator.current(), *items.cbegin());
    }
    
    void test_method_(cend) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_not_equal(items.cbegin(), items.cend());
      auto empty_items = dictionary<int, string> {};
      assert::are_equal(empty_items.cbegin(), empty_items.cend());
    }

    void test_method_(count) {
      auto items = dictionary<string, int> {};
      assert::is_zero(items.count());
      items.add("one", 1);
      assert::are_equal(1_z, items.count());
      items.add("two", 2);
      assert::are_equal(2_z, items.count());
    }

    void test_method_(empty) {
      auto items = dictionary<string, int> {};
      assert::is_true(items.empty());
      items.add("one", 1);
      assert::is_false(items.empty());
      items.add("two", 2);
      assert::is_false(items.empty());
    }

    void test_method_(const_end) {
      const auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_not_equal(items.begin(), items.end());
      const auto empty_items = dictionary<int, string> {};
      assert::are_equal(empty_items.begin(), empty_items.end());
    }

    void test_method_(end) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_not_equal(items.begin(), items.end());
      auto empty_items = dictionary<int, string> {};
      assert::are_equal(empty_items.begin(), empty_items.end());
    }

    void test_method_(const_items) {
      const auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.items();
      assert::is_instance_of<dictionary<int, string>::base_type>(items);
      collection_assert::are_equivalent(std::vector<std::pair<const int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }

    void test_method_(items) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.items();
      assert::is_instance_of<dictionary<int, string>::base_type>(items);
      collection_assert::are_equivalent(std::vector<std::pair<const int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    void test_method_(keys) {
      collection_assert::are_equivalent({1, 2, 3, 4, 5}, dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.keys());
    }
    
    void test_method_(load_factor) {
      assert::are_equal(.0f, dictionary<int, string> {}.load_factor());
      // assert::are_equal(0.5f, dictionary<int, string> {{1, "one"}}.load_factor()); // Does not work on all platforms.
      // assert::are_equal(1.0f, dictionary<int, string> {{1, "one"}, {2, "two"}}.load_factor()); // Does not work on all platforms.
    }
    
    void test_method_(max_bucket_count) {
      assert::is_not_zero(dictionary<int, string> {}.max_bucket_count());
    }
    
    void test_method_(max_load_factor) {
      assert::is_not_zero(dictionary<int, string> {}.max_load_factor());
    }
    void test_method_(max_size) {
      assert::is_not_zero(dictionary<int, string> {}.max_size());
    }

    void test_method_(size) {
      auto items = dictionary<string, int> {};
      assert::is_zero(items.size());
      items.add("one", 1);
      assert::are_equal(1_z, items.size());
      items.add("two", 2);
      assert::are_equal(2_z, items.size());
    }
    
    void test_method_(values) {
      collection_assert::are_equivalent({"one", "two", "three", "four", "five"}, dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}.values());
    }
    
    void test_method_(add) {
      auto items = dictionary<int, string> {};
      items.add(1, "one");
      items.add(2, "two");
      items.add(3, "three");
      items.add(4, "four");
      items.add(5, "five");
      assert::throws<argument_exception>([&] {items.add(5, "six");});
      collection_assert::are_equivalent(array<key_value_pair<int, string>> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}}, items);
    }
    
    void test_method_(const_at) {
      const auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::throws<key_not_found_exception>([&] {items.at(0);});
      assert::are_equal("one", items.at(1));
      assert::are_equal("two", items.at(2));
      assert::are_equal("three", items.at(3));
      assert::are_equal("four", items.at(4));
      assert::are_equal("five", items.at(5));
      assert::throws<key_not_found_exception>([&] {items.at(6);});
    }
    
    void test_method_(at) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::throws<key_not_found_exception>([&] {items.at(0);});
      assert::are_equal("one", items.at(1));
      assert::are_equal("two", items.at(2));
      assert::are_equal("three", items.at(3));
      assert::are_equal("four", items.at(4));
      assert::are_equal("five", items.at(5));
      assert::throws<key_not_found_exception>([&] {items.at(6);});
    }
    
    void test_method_(begin_with_size) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto bucket_count = items.bucket_count();
      auto bucket = items.bucket(1);
      assert::is_less(bucket, bucket_count);
      assert::are_not_equal(items.end(bucket), items.begin(bucket));
      const auto& [key, value] = *items.begin(bucket);
      assert::are_equal(1, key);
      assert::are_equal("one", value);
    }
    
    void test_method_(bucket_with_key) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto bucket = items.bucket(1);
      assert::is_less(bucket, items.bucket_count());
    }
    
    void test_method_(bucket_size_with_bucket) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::is_not_zero(items.bucket_size(items.bucket(1)));
    }
    
    void test_method_(cbegin_with_size) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto bucket_count = items.bucket_count();
      auto bucket = items.bucket(1);
      assert::is_less(bucket, bucket_count);
      assert::are_not_equal(items.end(bucket), items.cbegin(bucket));
      const auto& [key, value] = *items.cbegin(bucket);
      assert::are_equal(1, key);
      assert::are_equal("one", value);
    }

    void test_method_(hash_function) {
      auto items = dictionary<string, string> {};
      auto hasher = items.hash_function();
      assert::is_instance_of<dictionary<string, string>::hasher>(hasher);
    }
    
    void test_method_(clear) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_equal(5_z, items.count());
      items.clear();
      assert::is_zero(items.count());
    }
    
    void test_method_(contains) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::is_false(items.contains(0));
      assert::is_true(items.contains(1));
      assert::is_true(items.contains(2));
      assert::is_true(items.contains(3));
      assert::is_true(items.contains(4));
      assert::is_true(items.contains(5));
      assert::is_false(items.contains(6));
    }
    
    void test_method_(contains_key) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::is_false(items.contains_key(0));
      assert::is_true(items.contains_key(1));
      assert::is_true(items.contains_key(2));
      assert::is_true(items.contains_key(3));
      assert::is_true(items.contains_key(4));
      assert::is_true(items.contains_key(5));
      assert::is_false(items.contains_key(6));
    }
    
    void test_method_(emplace) {
      auto items = dictionary<int, string> {};
      const auto& [iterator1, succeeded1] = items.emplace(1, "one");
      assert::are_equal(items.begin(), iterator1);
      assert::is_true(succeeded1);
      const auto& [iterator2, succeeded2] = items.emplace(1, "two");
      assert::are_equal(items.begin(), iterator2);
      assert::is_false(succeeded2);
    }
    
    void test_method_(emplace_hint) {
      if (environment::os_version().is_windows()) return;
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto hint = items.begin();
      auto iterator = items.emplace_hint(hint, 6, "six");
      assert::are_equal(hint, iterator);
      assert::is_true(items.contains(6));
    }
    
    void test_method_(equal_range_with_key) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      
      const auto& [first1, last1] = items.equal_range(1);
      assert::are_equal(1, std::distance(first1, last1));
      assert::are_equal(1, first1->first);
      assert::are_equal("one", first1->second);

      const auto& [first2, last2] = items.equal_range(6);
      assert::are_equal(0, std::distance(first2, last2));
      assert::are_equal(items.end(), first2);
    }
    
    void test_method_(erase_with_pos) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto iterator = items.begin();
      ++iterator;
      auto [key, value] = *iterator;
      iterator = items.erase(iterator);
      assert::is_false(items.contains_key(key));
    }
    
    void test_method_(erase_with_first_and_last) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      auto iterator = items.begin();
      auto first = ++iterator;
      auto [key1, value1] = *first;
      auto last = ++iterator;
      auto [key2, value2] = *last;
      ++last;
      iterator = items.erase(first, last);
      assert::is_false(items.contains_key(key1));
      assert::is_false(items.contains_key(key2));
    }

    void test_method_(erase_with_key) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      assert::are_equal(1_z, items.erase(4));
      assert::is_false(items.contains_key(4));
      assert::are_equal(0_z, items.erase(6));
      assert::is_false(items.contains_key(6));
    }
    
    void test_method_(find_with_key) {
      auto items = dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
      const auto& [key, value] = *items.find(3);
      assert::are_equal(3, key);
      assert::are_equal("three", value);
      assert::are_equal(items.end(), items.find(6));
    }

    void test_method_(get_allocator) {
      auto items = dictionary<string, string> {};
      auto allocator = items.get_allocator();
      assert::is_instance_of<dictionary<string, string>::allocator_type>(allocator);
    }
    
    void test_method_(get_enumerator) {
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

    void test_method_(hash_function_instead_hasher_specified) {
      struct string_hash {
        xtd::size operator ()(const string& obj) const {return obj.to_lower().get_hash_code();}
      };
      auto items = dictionary<string, string, string_hash> {};
      auto hasher = items.hash_function();
      assert::is_instance_of<dictionary<string, string, string_hash>::hasher>(hasher);
    }

    void test_method_(key_eq) {
      auto items = dictionary<string, string> {};
      auto equator = items.key_eq();
      assert::is_instance_of<dictionary<string, string>::equator>(equator);
    }

    void test_method_(key_eq_instead_equator_specified) {
      struct string_equal {
        bool operator ()(const string& x, const string & y) const {return x.to_lower().equals(y.to_lower());}
      };
      auto items = dictionary<string, string, helpers::hasher<string>, string_equal> {};
      auto equator = items.key_eq();
      assert::is_instance_of<dictionary<string, string, helpers::hasher<string>, string_equal>::equator>(equator);
    }
  };
}
