#include <xtd/random>
#include <xtd/collections/generic/list>
#include <xtd/as_const>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(random_tests) {
    void test_method_(default_constructor) {
      assert::are_equal(std::default_random_engine {static_cast<uint32>(environment::tick_count().count())}, xtd::random {}.generator());
    }

    void test_method_(constructor_with_seed) {
      assert::are_equal(std::default_random_engine {1}, xtd::random {0}.generator());
      assert::are_equal(std::default_random_engine {2}, xtd::random {1}.generator());
      assert::are_equal(std::default_random_engine {11}, xtd::random {10}.generator());
    }

    void test_method_(constructor_with_device) {
      // to be defined...
    }
    
    void test_method_(copy_constructor) {
      assert::are_equal(std::default_random_engine {43}, xtd::random {xtd::random {42}}.generator());
    }
    
    void test_method_(copy_operator) {
      auto rnd = xtd::random {};
      rnd = xtd::random {42};
      assert::are_equal(std::default_random_engine {43}, rnd.generator());
    }
    
    void test_method_(generator) {
      assert::are_equal(std::default_random_engine {1}, xtd::random {0}.generator());
    }
    
    void test_method_(const_generator) {
      auto rnd = xtd::random {0};
      assert::are_equal(std::default_random_engine {1}, as_const(rnd).generator());
    }
    
    void test_method_(get_items_int_with_choices_array_and_length) {
      auto items = xtd::random {1}.get_items<int>(array<int> {0, 1, 2, 3}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({4, 5, 6, 7, 8, 9}, items);
      if (environment::os_version().is_linux()) collection_assert::are_equal({1, 3, 1, 1, 3, 0, 0, 0, 0, 0, 1, 3, 0, 1, 1, 2}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({1, 2, 1, 2, 1, 0, 2, 0, 3, 3, 3, 1, 3, 2, 2, 2}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({1, 3, 3, 1, 1, 0, 2, 0, 1, 2, 2, 2, 1, 2, 2, 1}, items);
    }
    
    void test_method_(get_items_boolean_with_choices_array_and_length) {
      auto items = xtd::random {1}.get_items<boolean>(array<boolean> {false, true}, 16);
      assert::are_equal(16_z, items.length());
      if (environment::os_version().is_linux()) collection_assert::are_equal({false, true, false, false, true, false, false, false, false, false, false, true, false, false, false, true}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({false, true, false, true, false, false, true, false, true, true, true, false, true, true, true, true}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({false, true, true, false, false, false, true, false, false, true, true, true, false, true, true, false}, items);
    }

    void test_method_(get_items_double_with_choices_array_and_length) {
      auto items = xtd::random {1}.get_items<double>(array<double> {0.3, 0.5, 0.8}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({0.1, 0.2, 0.4, 0.6, 0.7, 0.9}, items);
      if (environment::os_version().is_linux()) collection_assert::are_equal({0.5, 0.8, 0.5, 0.5, 0.8, 0.3, 0.3, 0.3, 0.3, 0.3, 0.5, 0.8, 0.3, 0.5, 0.5, 0.5}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({0.3, 0.8, 0.5, 0.8, 0.5, 0.3, 0.5, 0.3, 0.8, 0.8, 0.8, 0.5, 0.8, 0.5, 0.5, 0.8}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({0.3, 0.8, 0.8, 0.5, 0.5, 0.3, 0.5, 0.3, 0.5, 0.5, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5}, items);
    }
    
    void test_method_(get_items_int_with_choices_read_only_span_and_length) {
      auto items = xtd::random {1}.get_items<int>(read_only_span<int> {0, 1, 2, 3}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({4, 5, 6, 7, 8, 9}, items);
      if (environment::os_version().is_linux()) collection_assert::are_equal({1, 3, 1, 1, 3, 0, 0, 0, 0, 0, 1, 3, 0, 1, 1, 2}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({1, 2, 1, 2, 1, 0, 2, 0, 3, 3, 3, 1, 3, 2, 2, 2}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({1, 3, 3, 1, 1, 0, 2, 0, 1, 2, 2, 2, 1, 2, 2, 1}, items);
    }

    void test_method_(get_items_boolean_with_choices_read_only_span_and_length) {
      auto items = xtd::random {1}.get_items<boolean>(read_only_span<boolean> {false, true}, 16);
      assert::are_equal(16_z, items.length());
      if (environment::os_version().is_linux()) collection_assert::are_equal({false, true, false, false, true, false, false, false, false, false, false, true, false, false, false, true}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({false, true, false, true, false, false, true, false, true, true, true, false, true, true, true, true}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({false, true, true, false, false, false, true, false, false, true, true, true, false, true, true, false}, items);
    }

    void test_method_(get_items_double_with_choices_read_only_span_and_length) {
      auto items = xtd::random {1}.get_items<double>(read_only_span<double> {0.3, 0.5, 0.8}, 16);
      assert::are_equal(16_z, items.length());
      collection_assert::does_not_contain({0.1, 0.2, 0.4, 0.6, 0.7, 0.9}, items);
      if (environment::os_version().is_linux()) collection_assert::are_equal({0.5, 0.8, 0.5, 0.5, 0.8, 0.3, 0.3, 0.3, 0.3, 0.3, 0.5, 0.8, 0.3, 0.5, 0.5, 0.5}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({0.3, 0.8, 0.5, 0.8, 0.5, 0.3, 0.5, 0.3, 0.8, 0.8, 0.8, 0.5, 0.8, 0.5, 0.5, 0.8}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({0.3, 0.8, 0.8, 0.5, 0.5, 0.3, 0.5, 0.3, 0.5, 0.5, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5}, items);
    }
    
    void test_method_(get_items_int_with_choices_read_only_span_and_destination) {
      auto items_list = list<int>(16);
      auto items = span<int>(items_list);
      xtd::random {1}.get_items<int>(read_only_span<int> {0, 1, 2, 3}, items);
      collection_assert::does_not_contain({4, 5, 6, 7, 8, 9}, items);
      if (environment::os_version().is_linux()) collection_assert::are_equal({1, 3, 1, 1, 3, 0, 0, 0, 0, 0, 1, 3, 0, 1, 1, 2}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({1, 2, 1, 2, 1, 0, 2, 0, 3, 3, 3, 1, 3, 2, 2, 2}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({1, 3, 3, 1, 1, 0, 2, 0, 1, 2, 2, 2, 1, 2, 2, 1}, items);
    }

    void test_method_(get_items_boolean_with_choices_read_only_span_and_destination) {
      auto items_list = list<boolean>(16);
      auto items = span<boolean>(items_list);
      xtd::random {1}.get_items<boolean>(read_only_span<boolean> {false, true}, items);
      if (environment::os_version().is_linux()) collection_assert::are_equal({false, true, false, false, true, false, false, false, false, false, false, true, false, false, false, true}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({false, true, false, true, false, false, true, false, true, true, true, false, true, true, true, true}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({false, true, true, false, false, false, true, false, false, true, true, true, false, true, true, false}, items);
    }

    void test_method_(get_items_double_with_choices_read_only_span_and_destination) {
      auto items_list = list<double>(16);
      auto items = span<double>(items_list);
      xtd::random {1}.get_items<double>(read_only_span<double> {0.3, 0.5, 0.8}, items);
      collection_assert::does_not_contain({0.1, 0.2, 0.4, 0.6, 0.7, 0.9}, items);
      if (environment::os_version().is_linux()) collection_assert::are_equal({0.5, 0.8, 0.5, 0.5, 0.8, 0.3, 0.3, 0.3, 0.3, 0.3, 0.5, 0.8, 0.3, 0.5, 0.5, 0.5}, items);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({0.3, 0.8, 0.5, 0.8, 0.5, 0.3, 0.5, 0.3, 0.8, 0.8, 0.8, 0.5, 0.8, 0.5, 0.5, 0.8}, items);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({0.3, 0.8, 0.8, 0.5, 0.5, 0.3, 0.5, 0.3, 0.5, 0.5, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5}, items);
    }
    
    void test_method_(next) {
      if (!environment::os_version().is_macos()) return;
      auto rnd = xtd::random {1};
      assert::are_equal(365211587, rnd.next());
      assert::are_equal(1681957626, rnd.next());
      assert::are_equal(814711366, rnd.next());
      assert::are_equal(1709433009, rnd.next());
      assert::are_equal(1045878015, rnd.next());
    }
    
    void test_method_(next_with_boolean) {
      if (!environment::os_version().is_macos()) return;
      auto rnd = xtd::random {1};
      assert::are_equal(false, rnd.next<boolean>());
      assert::are_equal(true, rnd.next<boolean>());
      assert::are_equal(false, rnd.next<boolean>());
      assert::are_equal(true, rnd.next<boolean>());
      assert::are_equal(false, rnd.next<boolean>());
    }
    
    void test_method_(next_with_double) {
      auto rnd = xtd::random {1};
      if (environment::os_version().is_linux()) {
        assert::are_equal(4.72929156823009E+307, rnd.next<double>(), 0.00000000000001E+307);
        assert::are_equal(1.64902438728367E+308, rnd.next<double>(), 0.00000000000001E+308);
        assert::are_equal(7.87242851738426E+307, rnd.next<double>(), 0.00000000000001E+307);
        assert::are_equal(6.43087746707646E+307, rnd.next<double>(), 0.00000000000001E+307);
        assert::are_equal(1.56288886980333E+308, rnd.next<double>(), 0.00000000000001E+308);
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(3.05724499436841E+307, rnd.next<double>(), 0.00000000000001E+307);
        assert::are_equal(1.40799380865409E+308, rnd.next<double>(), 0.00000000000001E+308);
        assert::are_equal(6.82008001395177E+307, rnd.next<double>(), 0.00000000000001E+307);
        assert::are_equal(1.4309938939764E+308, rnd.next<double>(), 0.0000000000001E+308);
        assert::are_equal(8.75521324746089E+307, rnd.next<double>(), 0.00000000000001E+307);
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(3.32720787431632E+307, rnd.next<double>(), 0.00000000000001E+307);
        assert::are_equal(1.67462461532753E+308, rnd.next<double>(), 0.00000000000001E+308);
        assert::are_equal(1.70372881304609E+308, rnd.next<double>(), 0.00000000000001E+308);
        assert::are_equal(8.71430122574866E+307, rnd.next<double>(), 0.00000000000001E+307);
        assert::are_equal(5.7622615115016E+307, rnd.next<double>(), 0.0000000000001E+307);
      }
    }

    void test_method_(next_int_with_max_value_less_or_equal_to_1) {
      auto rnd = xtd::random {1};
      assert::are_equal(0, rnd.next(0));
      assert::are_equal(0, rnd.next(0));
      assert::are_equal(0, rnd.next(0));
      assert::are_equal(0, rnd.next(1));
      assert::are_equal(0, rnd.next(1));
      assert::are_equal(0, rnd.next(1));
    }

    void test_method_(next_boolean_with_max_value_equal_to_false) {
      auto rnd = xtd::random {1};
      assert::are_equal(false, rnd.next(false));
      assert::are_equal(false, rnd.next(false));
      assert::are_equal(false, rnd.next(false));
    }

    void test_method_(next_double_with_max_value_equal_to_0) {
      auto rnd = xtd::random {1};
      assert::are_equal(0.0, rnd.next(0.0));
      assert::are_equal(0.0, rnd.next(0.0));
      assert::are_equal(0.0, rnd.next(0.0));
    }
    
    void test_method_(next_int_with_max_value) {
      auto rnd = xtd::random {1};
      if (environment::os_version().is_linux()) {
        assert::are_equal(1, rnd.next(4));
        assert::are_equal(3, rnd.next(4));
        assert::are_equal(1, rnd.next(4));
        assert::are_equal(1, rnd.next(4));
        assert::are_equal(3, rnd.next(4));
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(1, rnd.next(4));
        assert::are_equal(2, rnd.next(4));
        assert::are_equal(1, rnd.next(4));
        assert::are_equal(2, rnd.next(4));
        assert::are_equal(1, rnd.next(4));
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(1, rnd.next(4));
        assert::are_equal(3, rnd.next(4));
        assert::are_equal(3, rnd.next(4));
        assert::are_equal(1, rnd.next(4));
        assert::are_equal(1, rnd.next(4));
      }
    }
    
    void test_method_(next_boolean_with_max_value) {
      auto rnd = xtd::random {1};
      if (environment::os_version().is_linux()) {
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
      }
    }

    void test_method_(next_int_with_min_and_max_with_same_value_or_same_value_plus_one) {
      auto rnd = xtd::random {1};
      assert::are_equal(4, rnd.next(4, 4));
      assert::are_equal(4, rnd.next(4, 4));
      assert::are_equal(4, rnd.next(4, 5));
      assert::are_equal(4, rnd.next(4, 5));
    }
    
    void test_method_(next_boolean_with_min_and_max_with_same_value) {
      auto rnd = xtd::random {1};
      assert::are_equal(false, rnd.next<boolean>(false, false));
      assert::are_equal(false, rnd.next<boolean>(false, false));
      assert::are_equal(true, rnd.next<boolean>(true, true));
      assert::are_equal(true, rnd.next<boolean>(true, true));
    }
    
    void test_method_(next_double_with_min_and_max_with_same_valuee) {
      auto rnd = xtd::random {1};
      assert::are_equal(4, rnd.next(4.0, 4.0));
      assert::are_equal(4, rnd.next(4.0, 4.0));
    }

    void test_method_(next_int_with_min_and_max_value) {
      auto rnd = xtd::random {1};
      if (environment::os_version().is_linux()) {
        assert::are_equal(5, rnd.next(4, 8));
        assert::are_equal(7, rnd.next(4, 8));
        assert::are_equal(5, rnd.next(4, 8));
        assert::are_equal(5, rnd.next(4, 8));
        assert::are_equal(7, rnd.next(4, 8));
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(5, rnd.next(4, 8));
        assert::are_equal(6, rnd.next(4, 8));
        assert::are_equal(5, rnd.next(4, 8));
        assert::are_equal(6, rnd.next(4, 8));
        assert::are_equal(5, rnd.next(4, 8));
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(5, rnd.next(4, 8));
        assert::are_equal(7, rnd.next(4, 8));
        assert::are_equal(7, rnd.next(4, 8));
        assert::are_equal(5, rnd.next(4, 8));
        assert::are_equal(5, rnd.next(4, 8));
      }
    }

    void test_method_(next_boolean_with_min_and_max_value) {
      auto rnd = xtd::random {1};
      if (environment::os_version().is_linux()) {
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(true, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
        assert::are_equal(false, rnd.next(true));
      }
    }

    void test_method_(next_double_with_min_and_max_value) {
      auto rnd = xtd::random {1};
      if (environment::os_version().is_linux()) {
        assert::are_equal(5.05230230377273, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(7.66920105618576, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(5.75167348969983, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(5.43091773392548, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(7.47754316795126, rnd.next(4.0, 8.0), 0.00000000000001);
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(4.68025959160211, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(7.13289021657622, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(5.51751817519715, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(7.18406710517031, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(5.94809961225812, rnd.next(4.0, 8.0), 0.00000000000001);
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(4.74032832629606, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(7.72616345437796, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(7.79092244389435, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(5.93899638525706, rnd.next(4.0, 8.0), 0.00000000000001);
        assert::are_equal(5.28214574551244, rnd.next(4.0, 8.0), 0.00000000000001);
      }
    }
    
    void test_method_(next_byte_with_array) {
      auto rnd = xtd::random {1};
      auto bytes = array<byte>(16_z);
      rnd.next_bytes(bytes);
      if (environment::os_version().is_linux()) collection_assert::are_equal({67, 233, 111, 91, 221, 10, 18, 15, 4, 34, 95, 219, 14, 78, 102, 133}, bytes);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({43, 199, 96, 202, 124, 31, 157, 6, 252, 237, 216, 78, 234, 182, 149, 211}, bytes);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({47, 237, 241, 123, 81, 39, 178, 30, 123, 161, 208, 173, 127, 149, 183, 66}, bytes);
    }
    
    void test_method_(next_byte_with_span) {
      auto rnd = xtd::random {1};
      auto bytes = list<byte>(16_z);
      auto span_byes = span<byte> {bytes};
      rnd.next_bytes(span_byes);
      if (environment::os_version().is_linux()) collection_assert::are_equal({67, 233, 111, 91, 221, 10, 18, 15, 4, 34, 95, 219, 14, 78, 102, 133}, span_byes);
      else if (environment::os_version().is_macos()) collection_assert::are_equal({43, 199, 96, 202, 124, 31, 157, 6, 252, 237, 216, 78, 234, 182, 149, 211}, span_byes);
      else if (environment::os_version().is_windows()) collection_assert::are_equal({47, 237, 241, 123, 81, 39, 178, 30, 123, 161, 208, 173, 127, 149, 183, 66}, span_byes);
    }
    
    void test_method_(next_double) {
      auto rnd = xtd::random {1};
      if (environment::os_version().is_linux()) {
        assert::are_equal(0.263075575943183, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.91730026404644, rnd.next_double(), 0.00000000000001);
        assert::are_equal(0.437918372424958, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.357729433481371, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.869385791987816, rnd.next_double(), 0.000000000000001);
      } else if (environment::os_version().is_macos()) {
        assert::are_equal(0.170064897900529, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.783222554144054, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.379379543799288, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.796016776292578, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.48702490306453, rnd.next_double(), 0.00000000000001);
      } else if (environment::os_version().is_windows()) {
        assert::are_equal(0.185082081574014, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.931540863594489, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.947730610973589, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.484749096314265, rnd.next_double(), 0.000000000000001);
        assert::are_equal(0.32053643637811, rnd.next_double(), 0.00000000000001);
      }
    }
  };
}
