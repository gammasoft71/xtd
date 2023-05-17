#include <xtd/enum_object.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

enum_class_(, enum_object_with_registered_enum_class_test,
  none,
  one,
  two,
  three,
  four
);

namespace xtd::tests {
  class test_class_(enum_object_with_registered_enum_class_tests) {
  public:
    void test_method_(enum_object_with_registered_enum_class_test_default_ctor) {
      enum_object<enum_object_with_registered_enum_class_test> e;
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_class_test::none), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_class_test::one), csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::none, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::none, e.value(), csf_);
      assert::are_equal(as<byte>(0), e.to_byte(), csf_);
      assert::are_equal(as<int16>(0), e.to_int16(), csf_);
      assert::are_equal(as<int32>(0), e.to_int32(), csf_);
      assert::are_equal(as<int64>(0), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(0), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(0), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(0), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(0), e.to_uint64(), csf_);
      assert::are_equal("none", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_class_test_ctor_with_one) {
      enum_object<enum_object_with_registered_enum_class_test> e {enum_object_with_registered_enum_class_test::one};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_class_test::one), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_class_test::two), csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::one, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::one, e.value(), csf_);
      assert::are_equal(as<byte>(1), e.to_byte(), csf_);
      assert::are_equal(as<int16>(1), e.to_int16(), csf_);
      assert::are_equal(as<int32>(1), e.to_int32(), csf_);
      assert::are_equal(as<int64>(1), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(1), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(1), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(1), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(1), e.to_uint64(), csf_);
      assert::are_equal("one", e.to_string(), csf_);
    }

    void test_method_(enum_object_with_registered_enum_class_test_ctor_with_two) {
      enum_object<enum_object_with_registered_enum_class_test> e {enum_object_with_registered_enum_class_test::two};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_class_test::two), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_class_test::one), csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::two, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::two, e.value(), csf_);
      assert::are_equal(as<byte>(2), e.to_byte(), csf_);
      assert::are_equal(as<int16>(2), e.to_int16(), csf_);
      assert::are_equal(as<int32>(2), e.to_int32(), csf_);
      assert::are_equal(as<int64>(2), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(2), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(2), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(2), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(2), e.to_uint64(), csf_);
      assert::are_equal("two", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_class_test_ctor_with_three) {
      enum_object<enum_object_with_registered_enum_class_test> e {enum_object_with_registered_enum_class_test::three};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_class_test::three), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_class_test::four), csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::three, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::three, e.value(), csf_);
      assert::are_equal(as<byte>(3), e.to_byte(), csf_);
      assert::are_equal(as<int16>(3), e.to_int16(), csf_);
      assert::are_equal(as<int32>(3), e.to_int32(), csf_);
      assert::are_equal(as<int64>(3), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(3), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(3), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(3), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(3), e.to_uint64(), csf_);
      assert::are_equal("three", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_class_test_ctor_with_four) {
      enum_object<enum_object_with_registered_enum_class_test> e {enum_object_with_registered_enum_class_test::four};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_class_test::four), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_class_test::one), csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::four, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_class_test::four, e.value(), csf_);
      assert::are_equal(as<byte>(4), e.to_byte(), csf_);
      assert::are_equal(as<int16>(4), e.to_int16(), csf_);
      assert::are_equal(as<int32>(4), e.to_int32(), csf_);
      assert::are_equal(as<int64>(4), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(4), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(4), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(4), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(4), e.to_uint64(), csf_);
      assert::are_equal("four", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_class_test_ctor_with_invalid_value) {
      enum_object<enum_object_with_registered_enum_class_test> e {as<enum_object_with_registered_enum_class_test>(5)};
      
      assert::is_true(e.has_flag(as<enum_object_with_registered_enum_class_test>(5)), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_class_test::two), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_class_test>(5), e, csf_);
      assert::are_equal(as<enum_object_with_registered_enum_class_test>(5), e.value(), csf_);
      assert::are_equal(as<byte>(5), e.to_byte(), csf_);
      assert::are_equal(as<int16>(5), e.to_int16(), csf_);
      assert::are_equal(as<int32>(5), e.to_int32(), csf_);
      assert::are_equal(as<int64>(5), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(5), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(5), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(5), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(5), e.to_uint64(), csf_);
      assert::are_equal("5", e.to_string(), csf_);
    }

    void test_method_(equals) {
      assert::is_true(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one).equals(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one)), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one).equals(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::two)), csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) == enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) != enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) == enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::two), csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) != enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::two), csf_);

      assert::is_true(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one).equals(enum_object_with_registered_enum_class_test::one), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one).equals(enum_object_with_registered_enum_class_test::two), csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) == enum_object_with_registered_enum_class_test::one, csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) != enum_object_with_registered_enum_class_test::one, csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) == enum_object_with_registered_enum_class_test::two, csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_class_test>(enum_object_with_registered_enum_class_test::one) != enum_object_with_registered_enum_class_test::two, csf_);
    }
    
    void test_method_(get_entries) {
      auto expected_entries = enum_collection<enum_object_with_registered_enum_class_test> {{enum_object_with_registered_enum_class_test::none, "none"}, {enum_object_with_registered_enum_class_test::one, "one"}, {enum_object_with_registered_enum_class_test::two, "two"}, {enum_object_with_registered_enum_class_test::three, "three"}, {enum_object_with_registered_enum_class_test::four, "four"}};
      auto actual_entries = enum_object<>::get_entries<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_byte) {
      auto expected_entries = enum_collection<byte> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_byte<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_int16) {
      auto expected_entries = enum_collection<int16> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_int16<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_int32) {
      auto expected_entries = enum_collection<int32> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_int32<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_int64) {
      auto expected_entries = enum_collection<int64> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_int64<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_sbyte) {
      auto expected_entries = enum_collection<sbyte> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_sbyte<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_uint16) {
      auto expected_entries = enum_collection<uint16> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_uint16<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_uint32) {
      auto expected_entries = enum_collection<uint32> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_uint32<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_entries_as_uint64) {
      auto expected_entries = enum_collection<uint64> {{0, "none"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
      auto actual_entries = enum_object<>::get_entries_as_uint64<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_name) {
      assert::are_equal("none", enum_object<>::get_name(enum_object_with_registered_enum_class_test::none), csf_);
      assert::are_equal("one", enum_object<>::get_name(enum_object_with_registered_enum_class_test::one), csf_);
      assert::are_equal("two", enum_object<>::get_name(enum_object_with_registered_enum_class_test::two), csf_);
      assert::are_equal("three", enum_object<>::get_name(enum_object_with_registered_enum_class_test::three), csf_);
      assert::are_equal("four", enum_object<>::get_name(enum_object_with_registered_enum_class_test::four), csf_);
      assert::are_equal("5", enum_object<>::get_name(as<enum_object_with_registered_enum_class_test>(5)), csf_);
    }
    
    void test_method_(get_name_enum_object) {
      assert::are_equal("none", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_class_test> {enum_object_with_registered_enum_class_test::none}), csf_);
      assert::are_equal("one", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_class_test> {enum_object_with_registered_enum_class_test::one}), csf_);
      assert::are_equal("two", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_class_test> {enum_object_with_registered_enum_class_test::two}), csf_);
      assert::are_equal("three", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_class_test> {enum_object_with_registered_enum_class_test::three}), csf_);
      assert::are_equal("four", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_class_test> {enum_object_with_registered_enum_class_test::four}), csf_);
      assert::are_equal("5", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_class_test> {as<enum_object_with_registered_enum_class_test>(5)}), csf_);
    }
    
    void test_method_(get_name_int32) {
      assert::are_equal("none", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int32>(0)), csf_);
      assert::are_equal("one", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int32>(1)), csf_);
      assert::are_equal("two", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int32>(2)), csf_);
      assert::are_equal("three", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int32>(3)), csf_);
      assert::are_equal("four", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int32>(4)), csf_);
      assert::are_equal("5", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int32>(5)), csf_);
    }
    
    void test_method_(get_name_int64) {
      assert::are_equal("none", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int64>(0)), csf_);
      assert::are_equal("one", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int64>(1)), csf_);
      assert::are_equal("two", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int64>(2)), csf_);
      assert::are_equal("three", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int64>(3)), csf_);
      assert::are_equal("four", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int64>(4)), csf_);
      assert::are_equal("5", enum_object<>::get_name<enum_object_with_registered_enum_class_test>(as<int64>(5)), csf_);
    }
    
    void test_method_(get_names) {
      collection_assert::are_equal({"none", "one", "two", "three", "four"}, enum_object<>::get_names<enum_object_with_registered_enum_class_test>(), csf_);
    }
    
    void test_method_(get_values) {
      auto expected_entries = vector<enum_object_with_registered_enum_class_test> {enum_object_with_registered_enum_class_test::none, enum_object_with_registered_enum_class_test::one, enum_object_with_registered_enum_class_test::two, enum_object_with_registered_enum_class_test::three, enum_object_with_registered_enum_class_test::four};
      auto actual_entries = enum_object<>::get_values<enum_object_with_registered_enum_class_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_values_as_byte) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_byte<enum_object_with_registered_enum_class_test>(),  csf_);
    }
    
    void test_method_(get_values_as_int16) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_int16<enum_object_with_registered_enum_class_test>(),  csf_);
    }
    
    void test_method_(get_values_as_int32) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_int32<enum_object_with_registered_enum_class_test>(),  csf_);
    }
    
    void test_method_(get_values_as_int64) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_int64<enum_object_with_registered_enum_class_test>(),  csf_);
    }
    
    void test_method_(get_values_as_sbyte) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_sbyte<enum_object_with_registered_enum_class_test>(),  csf_);
    }
    
    void test_method_(get_values_as_uint16) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_uint16<enum_object_with_registered_enum_class_test>(),  csf_);
    }
    
    void test_method_(get_values_as_uint32) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_uint32<enum_object_with_registered_enum_class_test>(),  csf_);
    }
    
    void test_method_(get_values_as_uint64) {
      collection_assert::are_equal({0, 1, 2, 3, 4}, enum_object<>::get_values_as_uint64<enum_object_with_registered_enum_class_test>(),  csf_);
    }
  };
}
