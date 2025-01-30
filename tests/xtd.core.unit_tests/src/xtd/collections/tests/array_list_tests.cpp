#include <xtd/collections/array_list>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections;
using namespace xtd::tunit;

namespace xtd::collections::tests {
  class test_class_(array_list_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<any_object>(), typeof_<array_list::value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<std::vector<any_object>>(), typeof_<array_list::base_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<xtd::size>(), typeof_<array_list::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<xtd::ptrdiff>(), typeof_<array_list::difference_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<any_object&>(), typeof_<array_list::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const any_object&>(), typeof_<array_list::const_reference>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<any_object*>(), typeof_<array_list::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const any_object*>(), typeof_<array_list::const_pointer>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<generic::ilist<any_object>::iterator>(), typeof_<array_list::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<generic::ilist<any_object>::const_iterator>(), typeof_<array_list::const_iterator>());
    }
    
    void test_method_(reverse_iterator) {
      assert::are_equal(typeof_<array_list::base_type::reverse_iterator>(), typeof_<array_list::reverse_iterator>());
    }
    
    void test_method_(const_reverse_iterator) {
      assert::are_equal(typeof_<array_list::base_type::const_reverse_iterator>(), typeof_<array_list::const_reverse_iterator>());
    }

    void test_method_(constructor) {
      auto items = array_list {};
      assert::is_zero(items.capacity());
      assert::is_zero(items.count());
      collection_assert::is_empty(items);
    }
    
    void test_method_(constructor_with_count) {
      auto items = array_list(3_z);
      assert::are_equal(3_z, items.count());
      assert::is_greater_or_equal(items.capacity(), 3_z);
      collection_assert::are_equal({any_object {}, any_object {}, any_object {}}, items);
    }

    void test_method_(constructor_with_count_and_type) {
      auto items = array_list(3, "Tyrannosaurus");
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Tyrannosaurus", "Tyrannosaurus"}, items);
    }

    void test_method_(constructor_with_iterators) {
      std::vector v = {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(v.begin(), v.end());
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
    }

    void test_method_(constructor_with_base_type) {
      auto bt = array_list::base_type {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(bt);
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
    }

    void test_method_(constructor_with_array_list) {
      auto l = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(l);
      l.add("Mamenchisaurus");
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
    }
    
    void test_method_(constructor_with_move_array_list) {
      auto l = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(std::move(l));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
      collection_assert::is_empty(l);
    }

    void test_method_(constructor_with_move_base_type) {
      auto bt = array_list::base_type {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items = array_list(std::move(bt));
      assert::are_equal(3_z, items.count());
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
      collection_assert::is_empty(bt);
    }
    
    void test_method_(const_back) {
      assert::are_equal("Amargasaurus", array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"}.back());
      assert::throws<index_out_of_range_exception>([] {array_list {}.back();});
    }
    
    void test_method_(back) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      items.back() = "Mamenchisaurus";
      assert::are_equal("Mamenchisaurus", items.back());
      auto empty_items = array_list {};
      assert::throws<index_out_of_range_exception>([&] {empty_items.back() = "Mamenchisaurus";});
    }
    
    void test_method_(begin) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal("Tyrannosaurus", *items.begin());
    }
    
    void test_method_(capaciy) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal(3_z, items.count());
      
      items.capacity(42_z);
      assert::is_greater_or_equal(items.capacity(), 42_z);
      assert::are_equal(3_z, items.count());
    }

    void test_method_(cbegin) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal("Tyrannosaurus", *items.cbegin());
    }
    
    void test_method_(cend) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal(any_object {}, *items.cend());
    }
    
    void test_method_(count) {
      auto items = array_list {};
      assert::is_zero(items.count());
      items.push_back("Tyrannosaurus");
      items.push_back("Compsognathus");
      items.push_back("Amargasaurus");
      assert::are_equal(3_z, items.count());
      items.resize(50_z);
      assert::are_equal(50_z, items.count());
    }

    void test_method_(crbegin) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal("Amargasaurus", *items.crbegin());
    }
    
    void test_method_(crend) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      // the crend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.crend();});
    }
    
    void test_method_(data) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      
      auto ptr = items.data();
      assert::are_equal("Tyrannosaurus", *ptr);
      assert::are_equal("Compsognathus", *(ptr + 1));
      assert::are_equal("Amargasaurus", *(ptr + 2));
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //assert::are_equal(0, *(ptr + 3));
      
      *(ptr) = "Mamenchisaurus";
      *(ptr + 1) = "Deinonychus";
      *(ptr + 2) = "Compsognathus";
      
      // Attempting to access a pointer that exceeds size() results in undefined behaviour.
      //*(ptr + 3) = "Tyrannosaurus";
      
      collection_assert::are_equal({"Mamenchisaurus", "Deinonychus", "Compsognathus"}, items);
    }

    void test_method_(empty) {
      assert::is_true(array_list {}.empty());
      assert::is_false(array_list {"Tyrannosaurus"}.empty());
      
      auto items = array_list {};
      assert::is_true(items.empty());
      items.capacity(42);
      assert::is_true(items.empty());
      items.resize(1);
      assert::is_false(items.empty());
      items.resize(0);
      assert::is_true(items.empty());
      items.push_back("Tyrannosaurus");
      assert::is_false(items.empty());
    }
    
    void test_method_(end) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal(any_object {}, *items.end());
    }
    
    void test_method_(front_const) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal("Tyrannosaurus", items.front());
      assert::throws<index_out_of_range_exception>([&] {array_list {}.front();});
    }
    
    void test_method_(front) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      items.front() = "Mamenchisaurus";
      assert::are_equal( "Mamenchisaurus", items.front());
      auto empty_items = array_list {};
      assert::throws<index_out_of_range_exception>([&] {empty_items.front() = "Mamenchisaurus";});
    }

    void test_method_(is_fixed_size) {
      // Is always false;
      assert::is_false(array_list {}.is_fixed_size());
    }
    
    void test_method_(is_read_only) {
      // Is always false;
      assert::is_false(array_list {}.is_read_only());
    }
    
    void test_method_(is_synchronized) {
      // Is always false;
      assert::is_false(array_list {}.is_synchronized());
    }
    
    void test_method_(items_const) {
      assert::are_equal(typeof_<array_list::base_type>(), typeof_(array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"}.items()));
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"}.items());
    }

    void test_method_(items) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal(typeof_<array_list::base_type>(), typeof_(items.items()));
      
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
    
    void test_method_(max_size) {
      assert::is_not_zero(array_list {}.max_size());
    }
    
    void test_method_(rbegin) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::are_equal("Amargasaurus", *items.rbegin());
    }
    
    void test_method_(rend) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      // the rend() property unlike end() and cend() is the same as underlying value type (std::vector) so this element acts as a placeholder, attempting to access it results in undefined behavior.
      // see https://en.cppreference.com/w/cpp/container/vector/rend documentation
      //assert::throws<argument_out_of_range_exception>([&] {*items.rend();});
    }

    void test_method_(size) {
      auto items = array_list {};
      assert::is_zero(items.size());
      items.push_back("Tyrannosaurus");
      items.push_back("Compsognathus");
      items.push_back("Amargasaurus");
      assert::are_equal(3_z, items.size());
      items.resize(50);
      assert::are_equal(50_z, items.size());
    }

    void test_method_(at) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      
      assert::are_equal("Tyrannosaurus", items.at(0));
      assert::are_equal("Compsognathus", items.at(1));
      assert::are_equal("Amargasaurus", items.at(2));
      assert::throws<index_out_of_range_exception>([&]{[[maybe_unused]] auto i = items[3];});
      
      items.at(0) = "Mamenchisaurus";
      items.at(1) = "Deinonychus";
      items.at(2) = "Compsognathus";
      assert::throws<index_out_of_range_exception>([&]{items[3] = 5;});
      
      collection_assert::are_equal({"Mamenchisaurus", "Deinonychus", "Compsognathus"}, items);
    }

    void test_method_(add) {
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
    
    void test_method_(add_range) {
      auto items = array_list {};
      
      items.add_range({"Tyrannosaurus", "Compsognathus", "Amargasaurus"});
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, items);
      
      items.add_range(array_list {"Mamenchisaurus", "Deinonychus", "Compsognathus"});
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"}, items);
    }
    
    void test_method_(contains) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items.contains("Tyrannosaurus"));
      assert::is_true(items.contains("Compsognathus"));
      assert::is_true(items.contains("Amargasaurus"));
      assert::is_false(items.contains("Mamenchisaurus"));
      assert::is_false(items.contains("Deinonychus"));
      assert::is_false(items.contains(""));
    }
    
    void test_method_(copy_to) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto dest = array<any_object>(3);
      items.copy_to(dest, 0);
      collection_assert::are_equal({"Tyrannosaurus", "Compsognathus", "Amargasaurus"}, dest);
      
      dest = array<any_object>(5);
      items.copy_to(dest, 2);
      collection_assert::are_equal(array<any_object> {any_object {}, any_object {}, "Tyrannosaurus", "Compsognathus", "Amargasaurus"}, dest);
      
      dest = array<any_object>(7);
      items.copy_to(dest, 2);
      collection_assert::are_equal(array<any_object> {any_object {}, any_object {}, "Tyrannosaurus", "Compsognathus", "Amargasaurus", any_object {}, any_object {}}, dest);

      dest = array<any_object>(3);
      assert::throws<argument_exception>([&] {items.copy_to(dest, 1);});
    }
    
    void test_method_(equals_object) {
      auto items1 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items2 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items1.equals(as<object>(items2)));
      auto items3 = array_list {"Mamenchisaurus", "Deinonychus", "Compsognathus"};
      assert::is_false(items1.equals(as<object>(items3)));
      auto items4 = array<any_object> {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_false(items1.equals(items4));
    }
    
    void test_method_(equals_array_list) {
      auto items1 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      auto items2 = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      assert::is_true(items1.equals(items2));
      auto items3 = array_list {"Mamenchisaurus", "Deinonychus", "Compsognathus"};
      assert::is_false(items1.equals(items3));
    }
    
    void test_method_(for_each) {
      auto items = array_list {1, 2, 3, 4, 5};
      auto accumulator = 0;
      for (auto item: items)
        accumulator += as<int>(item);
      assert::are_equal(15, accumulator);
    }

    void test_method_(get_enumerator) {
      auto items = array_list {1, 2, 3, 4, 5};
      auto enumerator = items.get_enumerator();
      auto accumulator = 0;
      while(enumerator.move_next())
        accumulator += as<int>(enumerator.current());
      assert::are_equal(15, accumulator);
    }

    void test_method_(index_operator) {
      auto items = array_list {"Tyrannosaurus", "Compsognathus", "Amargasaurus"};
      
      assert::are_equal("Tyrannosaurus", items[0]);
      assert::are_equal("Compsognathus", items[1]);
      assert::are_equal("Amargasaurus", items[2]);
      assert::throws<index_out_of_range_exception>([&]{[[maybe_unused]] auto i = items[3];});
      
      items[0] = "Mamenchisaurus";
      items[1] = "Deinonychus";
      items[2] = "Compsognathus";
      assert::throws<index_out_of_range_exception>([&]{items[3] = "Tyrannosaurus";});
      
      collection_assert::are_equal({"Mamenchisaurus", "Deinonychus", "Compsognathus"}, items);
    }
  };
}
