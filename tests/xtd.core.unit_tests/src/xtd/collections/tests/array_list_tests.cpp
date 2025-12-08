#include <xtd/collections/array_list>
#include <xtd/collections/comparer>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections;
using namespace xtd::tunit;

namespace xtd::collections::tests {
  class test_class_(array_list_tests) {
    auto test_method_(value_type) {
      assert::are_equal(typeof_<any_object>(), typeof_<array_list::value_type>());
    }
    
    auto test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<any_object>>(), typeof_<array_list::base_type>());
    }
    
    auto test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<array_list::size_type>());
    }
    
    auto test_method_(reference) {
      assert::are_equal(typeof_<any_object&>(), typeof_<array_list::reference>());
    }
    
    auto test_method_(const_reference) {
      assert::are_equal(typeof_<const any_object&>(), typeof_<array_list::const_reference>());
    }
    
    auto test_method_(pointer) {
      assert::are_equal(typeof_<any_object*>(), typeof_<array_list::pointer>());
    }
    
    auto test_method_(const_pointer) {
      assert::are_equal(typeof_<const any_object*>(), typeof_<array_list::const_pointer>());
    }
    
    auto test_method_(epos) {
      assert::are_equal(size_object::max_value - 1, array_list::epos);
    }
    
    auto test_method_(npos) {
      assert::are_equal(size_object::max_value, array_list::npos);
    }
    
    auto test_method_(constructor) {
      auto items = array_list {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.count());
      collection_assert::is_empty(items);
    }
    
    auto test_method_(constructor_with_capacity) {
      auto items = array_list(3_z);
      assert::is_greater_or_equal(items.capacity(), 3_z);
      assert::is_zero(items.count());
    }
    
    auto test_method_(constructor_with_iterators) {
      array a = {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(a.begin(), a.end());
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
    }
    
    auto test_method_(constructor_with_base_type) {
      auto bt = array_list::base_type {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(bt);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
    }
    
    auto test_method_(constructor_with_array_list) {
      auto l = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(l);
      l.add("Mamenchisaurus");
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
    }
    
    auto test_method_(constructor_with_move_array_list) {
      auto l = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(std::move(l));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
      collection_assert::is_empty(l);
    }
    
    auto test_method_(constructor_with_move_base_type) {
      auto bt = array_list::base_type {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(std::move(bt));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
      collection_assert::is_empty(bt);
    }
    
    auto test_method_(begin) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal("Tyrannosaurus", *items.begin());
    }
    
    auto test_method_(capacity) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal(3_z, items.count());
      
      items.capacity(42_z);
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::are_equal(3_z, items.count());
    }
    
    auto test_method_(cbegin) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal("Tyrannosaurus", *items.cbegin());
    }
    
    auto test_method_(cend) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items.cend() == items.cbegin() + items.count());
    }
    
    auto test_method_(count) {
      auto items = array_list {};
      assert::is_zero(items.count());
      items.add("Tyrannosaurus");
      items.add("Compsognathus");
      items.add("Amargasaurus");
      assert::are_equal(3_z, items.count());
    }
    
    auto test_method_(end) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items.end() == items.begin() + items.count());
    }
    
    auto test_method_(is_fixed_size) {
      // Is always false;
      assert::is_false(as<ilist>(array_list {}).is_fixed_size());
    }
    
    auto test_method_(is_read_only) {
      // Is always false;
      assert::is_false(as<icollection>(array_list {}).is_read_only());
    }
    
    auto test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(as<icollection>(array_list {}).is_synchronized());
    }
    
    auto test_method_(items_const) {
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"}.items());
    }
    
    auto test_method_(items) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      
      auto& inners = items.items();
      assert::are_equal("Tyrannosaurus", inners[0]);
      assert::are_equal("Compsognathus", inners[1]);
      assert::are_equal("Amargasaurus", inners[2]);
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //assert::are_equal(any_object {}, inners[3]);
      
      inners[0] = "Mamenchisaurus";
      inners[1] = "Deinonychus";
      inners[2] = "Compsognathus";
      
      // Attempting to access index that exceeds size() results in undefined behaviour.
      //inners[3] = "Tyrannosaurus";
      
      collection_assert::are_equal({"Mamenchisaurus", "Deinonychus", "Compsognathus"}, items);
    }
    
    auto test_method_(add) {
      auto items = array_list {};
      
      items.add("Tyrannosaurus");
      collection_assert::are_equal({"Tyrannosaurus"}, items);
      items.add("Compsognathus");
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus"}, items);
      items.add("Amargasaurus");
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
      items.add("Mamenchisaurus");
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus", "Mamenchisaurus"}, items);
    }
    
    auto test_method_(add_range) {
      auto items = array_list {};
      
      items.add_range({"Tyrannosaurus", "Compsognathus", "Amargasaurus"});
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
      
      items.add_range(array_list {"Mamenchisaurus", "Deinonychus", "Compsognathus"});
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"}, items);
    }
    
    /*
    auto test_method_(binary_search) {
      auto items = array_list {5, 10, 15, 20, 25, 30, 35, 40};
      assert::are_equal(~3_z, items.binary_search(16));
      assert::are_equal(3_z, items.binary_search(20));
      assert::are_equal(~6_z, items.binary_search(33));
      assert::are_equal(6_z, items.binary_search(35));
      assert::are_equal(~8_z, items.binary_search(50));
    }
    
    auto test_method_(binary_search_with_comparer) {
      auto items = array_list {5, 10, 15, 20, 25, 30, 35, 40};
      assert::are_equal(~3_z, items.binary_search(16, collections::comparer::default_comparer));
      assert::are_equal(3_z, items.binary_search(20, collections::comparer::default_comparer));
      assert::are_equal(~6_z, items.binary_search(33, collections::comparer::default_comparer));
      assert::are_equal(6_z, items.binary_search(35, collections::comparer::default_comparer));
      assert::are_equal(~8_z, items.binary_search(50, collections::comparer::default_comparer));
    }
    
    auto test_method_(binary_search_with_index_count_and_comparer) {
      auto items = array_list {5, 10, 15, 20, 25, 30, 35, 40};
      assert::are_equal(~3_z, items.binary_search(2, 3, 16, collections::comparer::default_comparer));
      assert::are_equal(3_z, items.binary_search(2, 3, 20, collections::comparer::default_comparer));
      assert::are_equal(~5_z, items.binary_search(2, 3, 33, collections::comparer::default_comparer));
      assert::are_equal(~5_z, items.binary_search(2, 3, 35, collections::comparer::default_comparer));
      assert::are_equal(~5_z, items.binary_search(2, 3, 50, collections::comparer::default_comparer));
    }
     */
    
    auto test_method_(contains) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items.contains("Tyrannosaurus"));
      assert::is_true(items.contains("Compsognathus"));
      assert::is_true(items.contains("Amargasaurus"));
      assert::is_false(items.contains("Mamenchisaurus"));
      assert::is_false(items.contains("Deinonychus"));
      assert::is_false(items.contains(""));
    }
    
    auto test_method_(convert_all) {
      auto items = array_list {84, 42, 21};
      collection_assert::are_equal({"84", "42", "21"}, items.convert_all<string>([](auto n) {return string::format("{}", n);}));
    }
    
    auto test_method_(copy_to) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto dest = array<any_object>(3_z);
      items.copy_to(dest, 0);
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, dest);
    }
    
    auto test_method_(copy_to_with_index) {
      auto items = array_list {84, 42, 21};
      auto dest = array<any_object>(5);
      items.copy_to(dest, 2);
      collection_assert::are_equal(array<any_object> {any_object {}, any_object {}, 84, 42, 21}, dest);
      
      dest = array<any_object>(7);
      items.copy_to(dest, 2);
      collection_assert::are_equal(array<any_object> {any_object {}, any_object {}, 84, 42, 21, any_object {}, any_object {}}, dest);
      
      dest = array<any_object>(3);
      assert::throws<argument_exception>([&] {items.copy_to(dest, 1);});
    }
    
    auto test_method_(copy_to_with_index_and_count) {
      auto items = array_list {84, 42, 21, 33};
      auto dest = array<any_object>(5);
      items.copy_to(3, dest, 2, 1);
      collection_assert::are_equal(array<any_object> {any_object {}, any_object {}, 33, any_object {}, any_object {}}, dest);
      
      dest = array<any_object>(3);
      assert::throws<argument_exception>([&] {items.copy_to(0, dest, 0, 4);});
      assert::throws<argument_exception>([&] {items.copy_to(1, dest, 0, 4);});
      assert::throws<argument_exception>([&] {items.copy_to(1, dest, 1, 3);});
    }
    
    auto test_method_(equals_object) {
      auto items1 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items2 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items1.equals(as<object>(items2)));
      auto items3 = array_list {"Mamenchisaurus", "Deinonychus", "Compsognathus"};
      assert::is_false(items1.equals(as<object>(items3)));
      auto items4 = array<any_object> {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_false(items1.equals(items4));
    }
    
    auto test_method_(equals_array_list) {
      auto items1 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items2 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items1.equals(items2));
      auto items3 = array_list {"Mamenchisaurus", "Deinonychus", "Compsognathus"};
      assert::is_false(items1.equals(items3));
    }
    
    auto test_method_(for_each) {
      auto items = array_list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      for (auto item : items)
        accumulator += as<int>(item);
      assert::are_equal(15, accumulator);
    }
    
    auto test_method_(get_enumerator) {
      auto items = array_list {1, 2, 3, 4, 5};
      auto enumerator = items.get_enumerator();
      auto accumulator = 0;
      while (enumerator.move_next())
        accumulator += as<int>(enumerator.current());
      assert::are_equal(15, accumulator);
    }
    
    auto test_method_(index_operator) {
      auto items = array_list {"Tyrannosaurus", 42, 64.5};
      
      assert::are_equal("Tyrannosaurus", items[0]);
      assert::are_equal(42, items[1]);
      assert::are_equal(64.5, items[2]);
      assert::throws<index_out_of_range_exception>([&] {[[maybe_unused]] auto i = items[3];});
      
      items[0] = 24;
      items[1] = "Deinonychus";
      items[2] = "Compsognathus";
      assert::throws<index_out_of_range_exception>([&] {items[3] = "Tyrannosaurus";});
      
      collection_assert::are_equal(array_list {24, "Deinonychus", "Compsognathus"}, items);
    }
    
    auto test_method_(index_operators_with_epos) {
      auto items = array_list {1, 2, 3, 4, 5};
      
      assert::are_equal(5, items[items.count() - 1]);
      assert::are_equal(5, items[items.epos]);
      assert::are_equal(5, items[xtd::epos]);
      
      items[items.epos] = 6;
      assert::are_equal(6, items[items.count() - 1]);
      assert::are_equal(6, items[items.epos]);
      assert::are_equal(6, items[xtd::epos]);
      
      items[xtd::epos] = 7;
      assert::are_equal(7, items[items.count() - 1]);
      assert::are_equal(7, items[items.epos]);
      assert::are_equal(7, items[xtd::epos]);
    }
  };
}
