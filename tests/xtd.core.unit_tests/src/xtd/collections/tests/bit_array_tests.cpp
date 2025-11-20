#include <xtd/collections/bit_array>
#include <xtd/as>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::tests {
  class test_class_(bit_array_tests) {
    void test_method_(value_type) {
      assert::are_equal(typeof_<bool>(), typeof_<bit_array::value_type>());
    }
    
    void test_method_(base_type) {
      assert::are_equal(typeof_<list<int32>>(), typeof_<bit_array::base_type>());
    }
    
    void test_method_(size_type) {
      assert::are_equal(typeof_<size>(), typeof_<bit_array::size_type>());
    }
    
    void test_method_(difference_type) {
      assert::are_equal(typeof_<ptrdiff>(), typeof_<bit_array::difference_type>());
    }
    
    void test_method_(reference) {
      assert::are_equal(typeof_<bool&>(), typeof_<bit_array::reference>());
    }
    
    void test_method_(const_reference) {
      assert::are_equal(typeof_<const bool>(), typeof_<bit_array::const_reference>());
    }
    
    void test_method_(pointer) {
      assert::are_equal(typeof_<bool*>(), typeof_<bit_array::pointer>());
    }
    
    void test_method_(const_pointer) {
      assert::are_equal(typeof_<const bool*>(), typeof_<bit_array::const_pointer>());
    }
    
    void test_method_(iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::ienumerable<bool>::iterator>(), typeof_<bit_array::iterator>());
    }
    
    void test_method_(const_iterator) {
      assert::are_equal(typeof_<xtd::collections::generic::ienumerable<bool>::const_iterator>(), typeof_<bit_array::const_iterator>());
    }
    
    void test_method_(constructor) {
      auto bits = bit_array {};
      assert::is_zero(bits.count());
      collection_assert::is_empty(bits);
    }
    
    void test_method_(constructor_with_length) {
      auto bits = bit_array(5);
      assert::are_equal(5_z, bits.count());
      collection_assert::are_equal({false, false, false, false, false}, bits);
    }
    
    void test_method_(constructor_with_length_and_false) {
      auto bits = bit_array(5, false);
      assert::are_equal(5_z, bits.count());
      collection_assert::are_equal({false, false, false, false, false}, bits);
    }
    
    void test_method_(constructor_with_length_and_true) {
      auto bits = bit_array(5, true);
      assert::are_equal(5_z, bits.count());
      collection_assert::are_equal({true, true, true, true, true}, bits);
    }
    
    void test_method_(constructor_with_bool_initializer_list) {
      auto bits = bit_array {true, false, false, true, true};
      assert::are_equal(5_z, bits.count());
      collection_assert::are_equal({true, false, false, true, true}, bits);
    }
    
    void test_method_(constructor_with_bool_array) {
      auto bits = bit_array(array {true, false, false, true, true});
      assert::are_equal(5_z, bits.count());
      collection_assert::are_equal({true, false, false, true, true}, bits);
    }
    
    void test_method_(constructor_with_byte_array) {
      auto bits = bit_array(array<byte> {0, 1, 2, 5, 40});
      assert::are_equal(40_z, bits.count());
      for (auto index = 0_z; index < 40_z ; ++index)
        if (index == 8 || index == 17 || index == 24  || index == 26 || index == 35 || index == 37)
          assert::is_true(bits[index]);
        else
          assert::is_false(bits[index]);
    }
    
    void test_method_(constructor_with_int32_array) {
      auto bits = bit_array(array {0, 1, 2, 5, 40});
      assert::are_equal(160_z, bits.count());
      for (auto index = 0_z; index < 160_z ; ++index)
        if (index == 32 || index == 65 || index == 96 || index == 98 || index == 131 || index == 133)
          assert::is_true(bits[index]);
        else
          assert::is_false(bits[index]);
    }
    
    void test_method_(copy_constructor) {
      auto bits1 = bit_array {true, false, false, true, true};
      auto bits2 = bits1;
      collection_assert::are_equal({true, false, false, true, true}, bits2);
    }
    
    void test_method_(copy_operator) {
      auto bits1 = bit_array {true, false, false, true, true};
      auto bits2 = bit_array {};
      bits2 = bits1;
      collection_assert::are_equal({true, false, false, true, true}, bits2);
    }
    
    void test_method_(begin_and_end) {
      auto bits = bit_array {true, false, false, true, true};
      auto it = bits.begin();
      assert::are_not_equal(bits.end(), it);
      assert::is_true(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_false(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_false(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_true(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_true(*it++);
      assert::are_equal(bits.end(), it);
    }
    
    void test_method_(const_begin_and_const_end) {
      const auto bits = bit_array {true, false, false, true, true};
      auto it = bits.begin();
      assert::are_not_equal(bits.end(), it);
      assert::is_true(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_false(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_false(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_true(*it++);
      assert::are_not_equal(bits.end(), it);
      assert::is_true(*it++);
      assert::are_equal(bits.end(), it);
    }
    
    void test_method_(cbegin_and_cend) {
      auto bits = bit_array {true, false, false, true, true};
      auto it = bits.cbegin();
      assert::are_not_equal(bits.cend(), it);
      assert::is_true(*it++);
      assert::are_not_equal(bits.cend(), it);
      assert::is_false(*it++);
      assert::are_not_equal(bits.cend(), it);
      assert::is_false(*it++);
      assert::are_not_equal(bits.cend(), it);
      assert::is_true(*it++);
      assert::are_not_equal(bits.cend(), it);
      assert::is_true(*it++);
      assert::are_equal(bits.cend(), it);
    }
    
    void test_method_(count) {
      auto bits = bit_array(5);
      assert::are_equal(5_z, bits.count());
      bits = bit_array(1587);
      assert::are_equal(1587_z, bits.count());
    }
    
    void test_method_(empty) {
      auto bits = bit_array {};
      assert::is_true(bits.empty());
      bits = bit_array(1);
      assert::is_false(bits.empty());
    }
    
    void test_method_(length) {
      auto bits = bit_array(4, true);
      assert::are_equal(4_z, bits.length());
      bits.length(8);
      assert::are_equal(8_z, bits.length());
      collection_assert::are_equal({true, true, true, true, false, false, false, false}, bits);
    }
    
    void test_method_(is_read_only) {
      auto bits = bit_array {};
      assert::is_false(as<icollection<bool>>(bits).is_read_only());
    }
    
    void test_method_(is_synchronized) {
      auto bits = bit_array {};
      assert::is_false(as<icollection<bool>>(bits).is_synchronized());
    }
    
    void test_method_(and_) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({true, false, false, false}, bits.and_({true, false, true, false}));
      assert::throws<argument_exception>([&] {bits.and_({true, false, true});});
      assert::throws<argument_exception>([&] {bits.and_({true, false, true, false, true});});
    }
    
    void test_method_(clone) {
      auto bits1 = bit_array {true, true, false, false};
      auto bits2 = as<bit_array>(bits1.clone());
      collection_assert::are_equal({true, true, false, false}, *bits2);
    }
    
    void test_method_(copy_to) {
      auto bits = bit_array {true, false, false, true, true};
      
      auto array1 = array<bool>(5);
      bits.copy_to(array1, 0);
      collection_assert::are_equal({true, false, false, true, true}, array1);
      
      auto array2 = array<bool>(8);
      bits.copy_to(array2, 2);
      collection_assert::are_equal({false, false, true, false, false, true, true, false}, array2);
      
      assert::throws<argument_exception>([&] {bits.copy_to(array2, 4);});
    }
    
    void test_method_(equals) {
      assert::is_true(bit_array {true, true, false, false}.equals(bit_array {true, true, false, false}));
      assert::is_false(bit_array {true, true, false, false}.equals(bit_array {true, true, false, true}));
      assert::is_false(bit_array {true, true, false, false}.equals(bit_array {true, true, false}));
      assert::is_false(bit_array {true, true, false, false}.equals(bit_array {true, true, false, false, false}));
    }
    
    void test_method_(get) {
      auto bits = bit_array {true, true, false, false};
      assert::is_true(bits.get(0));
      assert::is_true(bits.get(1));
      assert::is_false(bits.get(2));
      assert::is_false(bits.get(3));
      assert::throws<argument_out_of_range_exception>([&] {bits.get(4);});
      
      bits.get(0) = false;
      assert::is_false(bits.get(0));
      
      bits.get(2) = true;
      assert::is_true(bits.get(2));
    }
    
    void test_method_(const_get) {
      auto bits = bit_array {true, true, false, false};
      assert::is_true(bits.get(0));
      assert::is_true(bits.get(1));
      assert::is_false(bits.get(2));
      assert::is_false(bits.get(3));
      assert::throws<argument_out_of_range_exception>([&] {bits.get(4);});
    }
    
    void test_method_(get_enumerator) {
      auto bits = bit_array {true, false, false, true, true};
      auto enumerator = bits.get_enumerator();
      assert::is_true(enumerator.move_next());
      assert::is_true(enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::is_false(enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::is_false(enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::is_true(enumerator.current());
      assert::is_true(enumerator.move_next());
      assert::is_true(enumerator.current());
      assert::is_false(enumerator.move_next());
    }
    
    void test_method_(not_) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({false, false, true, true}, bits.not_());
    }
    
    void test_method_(or_) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({true, true, true, false}, bits.or_({true, false, true, false}));
      assert::throws<argument_exception>([&] {bits.or_({true, false, true});});
      assert::throws<argument_exception>([&] {bits.or_({true, false, true, false, true});});
    }
    
    void test_method_(set) {
      auto bits = bit_array {true, true, false, false};
      
      bits.set(0, false);
      bits.set(1, false);
      bits.set(2, true);
      bits.set(3, true);
      assert::throws<argument_out_of_range_exception>([&] {bits.set(4, false);});
      assert::throws<argument_out_of_range_exception>([&] {bits.set(4, true);});
      collection_assert::are_equal({false, false, true, true}, bits);
    }
    
    void test_method_(set_all) {
      auto bits = bit_array {true, true, false, false};
      
      bits.set_all(false);
      collection_assert::are_equal({false, false, false, false}, bits);
      
      bits.set_all(true);
      collection_assert::are_equal({true, true, true, true}, bits);
    }
    
    void test_method_(to_string) {
      auto bits = bit_array {true, false, false, true, true};
      assert::are_equal("[true, false, false, true, true]", bits.to_string());
    }
    
    void test_method_(xor_) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({false, true, true, false}, bits.xor_({true, false, true, false}));
      assert::throws<argument_exception>([&] {bits.xor_({true, false, true});});
      assert::throws<argument_exception>([&] {bits.xor_({true, false, true, false, true});});
    }
    
    void test_method_(equal_to_operator) {
      assert::is_true(bit_array {true, true, false, false} == bit_array {true, true, false, false});
      assert::is_false(bit_array {true, true, false, false} == bit_array {true, true, false, true});
      assert::is_false(bit_array {true, true, false, false} == bit_array {true, true, false});
      assert::is_false(bit_array {true, true, false, false} == bit_array {true, true, false, false, false});
    }
    
    void test_method_(not_equal_to_operator) {
      assert::is_false(bit_array {true, true, false, false} != bit_array {true, true, false, false});
      assert::is_true(bit_array {true, true, false, false} != bit_array {true, true, false, true});
      assert::is_true(bit_array {true, true, false, false} != bit_array {true, true, false});
      assert::is_true(bit_array {true, true, false, false} != bit_array {true, true, false, false, false});
    }
    
    void test_method_(index_operator) {
      auto bits = bit_array {true, true, false, false};
      assert::is_true(bits[0]);
      assert::is_true(bits[1]);
      assert::is_false(bits[2]);
      assert::is_false(bits[3]);
      assert::throws<argument_out_of_range_exception>([&] {bits[4];});
      
      bits[0] = false;
      assert::is_false(bits[0]);
      
      bits[2] = true;
      assert::is_true(bits[2]);
    }
    
    void test_method_(const_index_operator) {
      auto bits = bit_array {true, true, false, false};
      assert::is_true(bits[0]);
      assert::is_true(bits[1]);
      assert::is_false(bits[2]);
      assert::is_false(bits[3]);
      assert::throws<argument_out_of_range_exception>([&] {bits[4];});
    }
    
    void test_method_(and_operator) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({true, false, false, false}, bits & bit_array {true, false, true, false});
      collection_assert::are_equal({true, true, false, false}, bits);
      assert::throws<argument_exception>([&] {bits & bit_array {true, false, true};});
      assert::throws<argument_exception>([&] {bits & bit_array {true, false, true, false, true};});
    }
    
    void test_method_(and_equal_operator) {
      auto bits = bit_array {true, true, false, false};
      bits &= {true, false, true, false};
      collection_assert::are_equal({true, false, false, false}, bits);
      assert::throws<argument_exception>([&] {bits & bit_array {true, false, true};});
      assert::throws<argument_exception>([&] {bits & bit_array {true, false, true, false, true};});
    }
    
    void test_method_(or_operator) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({true, true, true, false}, bits | bit_array {true, false, true, false});
      collection_assert::are_equal({true, true, false, false}, bits);
      assert::throws<argument_exception>([&] {bits | bit_array {true, false, true};});
      assert::throws<argument_exception>([&] {bits | bit_array {true, false, true, false, true};});
    }
    
    void test_method_(or_equal_operator) {
      auto bits = bit_array {true, true, false, false};
      bits |= {true, false, true, false};
      collection_assert::are_equal({true, true, true, false}, bits);
      assert::throws<argument_exception>([&] {bits | bit_array {true, false, true};});
      assert::throws<argument_exception>([&] {bits | bit_array {true, false, true, false, true};});
    }
    
    void test_method_(xor_operator) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({false, true, true, false}, bits ^ bit_array {true, false, true, false});
      collection_assert::are_equal({true, true, false, false}, bits);
      assert::throws<argument_exception>([&] {bits ^ bit_array {true, false, true};});
      assert::throws<argument_exception>([&] {bits ^ bit_array {true, false, true, false, true};});
    }
    
    void test_method_(xor_equal_operator) {
      auto bits = bit_array {true, true, false, false};
      bits ^= {true, false, true, false};
      collection_assert::are_equal({false, true, true, false}, bits);
      assert::throws<argument_exception>([&] {bits ^ bit_array {true, false, true};});
      assert::throws<argument_exception>([&] {bits ^ bit_array {true, false, true, false, true};});
    }
    
    void test_method_(not_operator) {
      auto bits = bit_array {true, true, false, false};
      collection_assert::are_equal({false, false, true, true}, ~bits);
      collection_assert::are_equal({true, true, false, false}, bits);
    }
  };
}
