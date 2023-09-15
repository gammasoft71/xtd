#include <xtd/enum_object>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

enum_(, enum_object_with_registered_enum_flags_test,
  none = 0b0,
  one = 0b1,
  two = 0b10,
  three = 0b100,
  four = 0b1000
);

flags_attribute_(, enum_object_with_registered_enum_flags_test);

namespace xtd::tests {
  class test_class_(enum_object_with_registered_enum_flags_tests) {
  public:
    void test_method_(enum_object_with_registered_enum_flags_test_default_ctor) {
      enum_object<enum_object_with_registered_enum_flags_test> e;
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, e.value(), csf_);
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
    
    void test_method_(enum_object_with_registered_enum_flags_test_ctor_with_one) {
      enum_object<enum_object_with_registered_enum_flags_test> e {enum_object_with_registered_enum_flags_test::one};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one, e.value(), csf_);
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
    
    void test_method_(enum_object_with_registered_enum_flags_test_ctor_with_two) {
      enum_object<enum_object_with_registered_enum_flags_test> e {enum_object_with_registered_enum_flags_test::two};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::two, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::two, e.value(), csf_);
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
    
    void test_method_(enum_object_with_registered_enum_flags_test_ctor_with_three) {
      enum_object<enum_object_with_registered_enum_flags_test> e {enum_object_with_registered_enum_flags_test::three};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three, e.value(), csf_);
      assert::are_equal(as<byte>(4), e.to_byte(), csf_);
      assert::are_equal(as<int16>(4), e.to_int16(), csf_);
      assert::are_equal(as<int32>(4), e.to_int32(), csf_);
      assert::are_equal(as<int64>(4), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(4), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(4), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(4), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(4), e.to_uint64(), csf_);
      assert::are_equal("three", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_flags_test_ctor_with_four) {
      enum_object<enum_object_with_registered_enum_flags_test> e {enum_object_with_registered_enum_flags_test::four};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::four, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::four, e.value(), csf_);
      assert::are_equal(as<byte>(8), e.to_byte(), csf_);
      assert::are_equal(as<int16>(8), e.to_int16(), csf_);
      assert::are_equal(as<int32>(8), e.to_int32(), csf_);
      assert::are_equal(as<int64>(8), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(8), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(8), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(8), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(8), e.to_uint64(), csf_);
      assert::are_equal("four", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_flags_test_ctor_with_one_and_two) {
      enum_object<enum_object_with_registered_enum_flags_test> e {enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two, e.value(), csf_);
      assert::are_equal(as<byte>(3), e.to_byte(), csf_);
      assert::are_equal(as<int16>(3), e.to_int16(), csf_);
      assert::are_equal(as<int32>(3), e.to_int32(), csf_);
      assert::are_equal(as<int64>(3), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(3), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(3), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(3), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(3), e.to_uint64(), csf_);
      assert::are_equal("one, two", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_flags_test_ctor_with_three_and_four) {
      enum_object<enum_object_with_registered_enum_flags_test> e {enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four};
      
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::is_true(e.has_flag(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four, e, csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four, e.value(), csf_);
      assert::are_equal(as<byte>(12), e.to_byte(), csf_);
      assert::are_equal(as<int16>(12), e.to_int16(), csf_);
      assert::are_equal(as<int32>(12), e.to_int32(), csf_);
      assert::are_equal(as<int64>(12), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(12), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(12), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(12), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(12), e.to_uint64(), csf_);
      assert::are_equal("three, four", e.to_string(), csf_);
    }
    
    void test_method_(enum_object_with_registered_enum_flags_test_ctor_with_invalid_value) {
      enum_object<enum_object_with_registered_enum_flags_test> e {as<enum_object_with_registered_enum_flags_test>(16)};
      
      assert::is_true(e.has_flag(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::is_false(e.has_flag(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(16), e, csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(16), e.value(), csf_);
      assert::are_equal(as<byte>(16), e.to_byte(), csf_);
      assert::are_equal(as<int16>(16), e.to_int16(), csf_);
      assert::are_equal(as<int32>(16), e.to_int32(), csf_);
      assert::are_equal(as<int64>(16), e.to_int64(), csf_);
      assert::are_equal(as<sbyte>(16), e.to_sbyte(), csf_);
      assert::are_equal(as<uint16>(16), e.to_uint16(), csf_);
      assert::are_equal(as<uint32>(16), e.to_uint32(), csf_);
      assert::are_equal(as<uint64>(16), e.to_uint64(), csf_);
      assert::are_equal("16", e.to_string(), csf_);
    }
    
    void test_method_(equals) {
      assert::is_true(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one).equals(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one)), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one).equals(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::two)), csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) == enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) != enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) == enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) != enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::two), csf_);
      
      assert::is_true(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one).equals(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one).equals(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) == enum_object_with_registered_enum_flags_test::one, csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) != enum_object_with_registered_enum_flags_test::one, csf_);
      assert::is_false(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) == enum_object_with_registered_enum_flags_test::two, csf_);
      assert::is_true(enum_object<enum_object_with_registered_enum_flags_test>(enum_object_with_registered_enum_flags_test::one) != enum_object_with_registered_enum_flags_test::two, csf_);
    }
    
    void test_method_(get_entries) {
      auto expected_entries = enum_collection<enum_object_with_registered_enum_flags_test> {{enum_object_with_registered_enum_flags_test::none, "none"}, {enum_object_with_registered_enum_flags_test::one, "one"}, {enum_object_with_registered_enum_flags_test::two, "two"}, {enum_object_with_registered_enum_flags_test::three, "three"}, {enum_object_with_registered_enum_flags_test::four, "four"}};
      auto actual_entries = enum_object<>::get_entries<enum_object_with_registered_enum_flags_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
      //collection_assert::are_equal(enum_collection<enum_object_with_registered_enum_flags_test> {{enum_object_with_registered_enum_flags_test::none, "none"}, {enum_object_with_registered_enum_flags_test::one, "one"}, {enum_object_with_registered_enum_flags_test::two, "two"}, {enum_object_with_registered_enum_flags_test::three, "three"}, {enum_object_with_registered_enum_flags_test::four, "four"}}, enum_object<>::get_entries<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_byte) {
      collection_assert::are_equal(enum_collection<byte> {{0_u8, "none"}, {1_u8, "one"}, {2_u8, "two"}, {4_u8, "three"}, {8_u8, "four"}}, enum_object<>::get_entries_as_byte<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_int16) {
      collection_assert::are_equal(enum_collection<int16> {{0_s16, "none"}, {1_s16, "one"}, {2_s16, "two"}, {4_s16, "three"}, {8_s16, "four"}}, enum_object<>::get_entries_as_int16<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_int32) {
      collection_assert::are_equal(enum_collection<int32> {{0_s32, "none"}, {1_s32, "one"}, {2_s32, "two"}, {4_s32, "three"}, {8_s32, "four"}}, enum_object<>::get_entries_as_int32<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_int64) {
      collection_assert::are_equal(enum_collection<int64> {{0_s64, "none"}, {1_s64, "one"}, {2_s64, "two"}, {4_s64, "three"}, {8_s64, "four"}}, enum_object<>::get_entries_as_int64<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_sbyte) {
      collection_assert::are_equal(enum_collection<sbyte> {{0_s8, "none"}, {1_s8, "one"}, {2_s8, "two"}, {4_s8, "three"}, {8_s8, "four"}}, enum_object<>::get_entries_as_sbyte<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_uint16) {
      collection_assert::are_equal(enum_collection<uint16> {{0_u16, "none"}, {1_u16, "one"}, {2_u16, "two"}, {4_u16, "three"}, {8_u16, "four"}}, enum_object<>::get_entries_as_uint16<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_uint32) {
      collection_assert::are_equal(enum_collection<uint32> {{0_u32, "none"}, {1_u32, "one"}, {2_u32, "two"}, {4_u32, "three"}, {8_u32, "four"}}, enum_object<>::get_entries_as_uint32<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_entries_as_uint64) {
      collection_assert::are_equal(enum_collection<uint64> {{0_u64, "none"}, {1_u64, "one"}, {2_u64, "two"}, {4_u64, "three"}, {8_u64, "four"}}, enum_object<>::get_entries_as_uint64<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_name) {
      assert::are_equal("none", enum_object<>::get_name(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal("one", enum_object<>::get_name(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal("two", enum_object<>::get_name(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal("three", enum_object<>::get_name(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal("four", enum_object<>::get_name(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal("16", enum_object<>::get_name(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
    }
    
    void test_method_(get_name_enum_object) {
      assert::are_equal("none", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::none}), csf_);
      assert::are_equal("one", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::one}), csf_);
      assert::are_equal("two", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::two}), csf_);
      assert::are_equal("three", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::three}), csf_);
      assert::are_equal("four", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::four}), csf_);
      assert::are_equal("16", enum_object<>::get_name(enum_object<enum_object_with_registered_enum_flags_test> {as<enum_object_with_registered_enum_flags_test>(16)}), csf_);
    }
    
    void test_method_(get_name_int32) {
      assert::are_equal("none", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int32>(0)), csf_);
      assert::are_equal("one", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int32>(1)), csf_);
      assert::are_equal("two", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int32>(2)), csf_);
      assert::are_equal("three", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int32>(4)), csf_);
      assert::are_equal("four", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int32>(8)), csf_);
      assert::are_equal("16", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int32>(16)), csf_);
    }
    
    void test_method_(get_name_int64) {
      assert::are_equal("none", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int64>(0)), csf_);
      assert::are_equal("one", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int64>(1)), csf_);
      assert::are_equal("two", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int64>(2)), csf_);
      assert::are_equal("three", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int64>(4)), csf_);
      assert::are_equal("four", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int64>(8)), csf_);
      assert::are_equal("16", enum_object<>::get_name<enum_object_with_registered_enum_flags_test>(as<int64>(16)), csf_);
    }
    
    void test_method_(get_names) {
      collection_assert::are_equal({"none", "one", "two", "three", "four"}, enum_object<>::get_names<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values) {
      auto expected_entries = vector<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::none, enum_object_with_registered_enum_flags_test::one, enum_object_with_registered_enum_flags_test::two, enum_object_with_registered_enum_flags_test::three, enum_object_with_registered_enum_flags_test::four};
      auto actual_entries = enum_object<>::get_values<enum_object_with_registered_enum_flags_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()), csf_);
    }
    
    void test_method_(get_values_as_byte) {
      collection_assert::are_equal({0_u8, 1_u8, 2_u8, 4_u8, 8_u8}, enum_object<>::get_values_as_byte<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values_as_int16) {
      collection_assert::are_equal({0_s16, 1_s16, 2_s16, 4_s16, 8_s16}, enum_object<>::get_values_as_int16<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values_as_int32) {
      collection_assert::are_equal({0_s32, 1_s32, 2_s32, 4_s32, 8_s32}, enum_object<>::get_values_as_int32<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values_as_int64) {
      collection_assert::are_equal({0_s64, 1_s64, 2_s64, 4_s64, 8_s64}, enum_object<>::get_values_as_int64<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values_as_sbyte) {
      collection_assert::are_equal({0_s8, 1_s8, 2_s8, 4_s8, 8_s8}, enum_object<>::get_values_as_sbyte<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values_as_uint16) {
      collection_assert::are_equal({0_u16, 1_u16, 2_u16, 4_u16, 8_u16}, enum_object<>::get_values_as_uint16<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values_as_uint32) {
      collection_assert::are_equal({0_u32, 1_u32, 2_u32, 4_u32, 8_u32}, enum_object<>::get_values_as_uint32<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(get_values_as_uint64) {
      collection_assert::are_equal({0_u64, 1_u64, 2_u64, 4_u64, 8_u64}, enum_object<>::get_values_as_uint64<enum_object_with_registered_enum_flags_test>(), csf_);
    }
    
    void test_method_(is_defined) {
      assert::is_true(enum_object<>::is_defined(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object_with_registered_enum_flags_test::four), csf_);
      
      assert::is_true(enum_object<>::is_defined(as<enum_object_with_registered_enum_flags_test>(0)), csf_);
      assert::is_true(enum_object<>::is_defined(as<enum_object_with_registered_enum_flags_test>(1)), csf_);
      assert::is_true(enum_object<>::is_defined(as<enum_object_with_registered_enum_flags_test>(2)), csf_);
      assert::is_true(enum_object<>::is_defined(as<enum_object_with_registered_enum_flags_test>(4)), csf_);
      assert::is_true(enum_object<>::is_defined(as<enum_object_with_registered_enum_flags_test>(8)), csf_);
      assert::is_false(enum_object<>::is_defined(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
    }
    
    void test_method_(is_defined_enum_object) {
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::none}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::one}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::two}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::three}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {enum_object_with_registered_enum_flags_test::four}), csf_);
      
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {as<enum_object_with_registered_enum_flags_test>(0)}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {as<enum_object_with_registered_enum_flags_test>(1)}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {as<enum_object_with_registered_enum_flags_test>(2)}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {as<enum_object_with_registered_enum_flags_test>(4)}), csf_);
      assert::is_true(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {as<enum_object_with_registered_enum_flags_test>(8)}), csf_);
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_registered_enum_flags_test> {as<enum_object_with_registered_enum_flags_test>(16)}), csf_);
    }
    
    void test_method_(parse) {
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("none"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("one"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::two, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("two"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("three"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::four, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("four"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("one, two"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("three, four"), csf_);
      
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("0"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("1"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::two, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("2"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("4"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::four, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("8"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("3"), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four, enum_object<>::parse<enum_object_with_registered_enum_flags_test>("12"), csf_);
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(16), enum_object<>::parse<enum_object_with_registered_enum_flags_test>("16"), csf_);
      assert::throws<format_exception>([] {enum_object<>::parse<enum_object_with_registered_enum_flags_test>("five");}, csf_);
    }
    
    void test_method_(to_byte) {
      assert::are_equal(as<byte>(0), enum_object<>::to_byte(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<byte>(1), enum_object<>::to_byte(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<byte>(2), enum_object<>::to_byte(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<byte>(4), enum_object<>::to_byte(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<byte>(8), enum_object<>::to_byte(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<byte>(16), enum_object<>::to_byte(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<byte>(3), enum_object<>::to_byte(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<byte>(12), enum_object<>::to_byte(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(to_int16) {
      assert::are_equal(as<int16>(0), enum_object<>::to_int16(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<int16>(1), enum_object<>::to_int16(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<int16>(2), enum_object<>::to_int16(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<int16>(4), enum_object<>::to_int16(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<int16>(8), enum_object<>::to_int16(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<int16>(16), enum_object<>::to_int16(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<int16>(3), enum_object<>::to_int16(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<int16>(12), enum_object<>::to_int16(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(to_int32) {
      assert::are_equal(as<int32>(0), enum_object<>::to_int32(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<int32>(1), enum_object<>::to_int32(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<int32>(2), enum_object<>::to_int32(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<int32>(4), enum_object<>::to_int32(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<int32>(8), enum_object<>::to_int32(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<int32>(16), enum_object<>::to_int32(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<int32>(3), enum_object<>::to_int32(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<int32>(12), enum_object<>::to_int32(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(to_int64) {
      assert::are_equal(as<int64>(0), enum_object<>::to_int64(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<int64>(1), enum_object<>::to_int64(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<int64>(2), enum_object<>::to_int64(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<int64>(4), enum_object<>::to_int64(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<int64>(8), enum_object<>::to_int64(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<int64>(16), enum_object<>::to_int64(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<int64>(3), enum_object<>::to_int64(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<int64>(12), enum_object<>::to_int64(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(to_sbyte) {
      assert::are_equal(as<sbyte>(0), enum_object<>::to_sbyte(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<sbyte>(1), enum_object<>::to_sbyte(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<sbyte>(2), enum_object<>::to_sbyte(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<sbyte>(4), enum_object<>::to_sbyte(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<sbyte>(8), enum_object<>::to_sbyte(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<sbyte>(16), enum_object<>::to_sbyte(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<sbyte>(3), enum_object<>::to_sbyte(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<sbyte>(12), enum_object<>::to_sbyte(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(to_uint16) {
      assert::are_equal(as<uint16>(0), enum_object<>::to_uint16(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<uint16>(1), enum_object<>::to_uint16(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<uint16>(2), enum_object<>::to_uint16(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<uint16>(4), enum_object<>::to_uint16(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<uint16>(8), enum_object<>::to_uint16(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<uint16>(16), enum_object<>::to_uint16(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<uint16>(3), enum_object<>::to_uint16(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<uint16>(12), enum_object<>::to_uint16(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(to_uint32) {
      assert::are_equal(as<uint32>(0), enum_object<>::to_uint32(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<uint32>(1), enum_object<>::to_uint32(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<uint32>(2), enum_object<>::to_uint32(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<uint32>(4), enum_object<>::to_uint32(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<uint32>(8), enum_object<>::to_uint32(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<uint32>(16), enum_object<>::to_uint32(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<uint32>(3), enum_object<>::to_uint32(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<uint32>(12), enum_object<>::to_uint32(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(to_uint64) {
      assert::are_equal(as<uint64>(0), enum_object<>::to_uint64(enum_object_with_registered_enum_flags_test::none), csf_);
      assert::are_equal(as<uint64>(1), enum_object<>::to_uint64(enum_object_with_registered_enum_flags_test::one), csf_);
      assert::are_equal(as<uint64>(2), enum_object<>::to_uint64(enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<uint64>(4), enum_object<>::to_uint64(enum_object_with_registered_enum_flags_test::three), csf_);
      assert::are_equal(as<uint64>(8), enum_object<>::to_uint64(enum_object_with_registered_enum_flags_test::four), csf_);
      assert::are_equal(as<uint64>(16), enum_object<>::to_uint64(as<enum_object_with_registered_enum_flags_test>(16)), csf_);
      assert::are_equal(as<uint64>(3), enum_object<>::to_uint64(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two), csf_);
      assert::are_equal(as<uint64>(12), enum_object<>::to_uint64(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four), csf_);
    }
    
    void test_method_(try_parse) {
      enum_object_with_registered_enum_flags_test result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("none", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("one", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("two", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::two, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("three", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("four", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::four, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("one, two", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("three, four", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("0", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("1", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("2", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::two, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("4", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("8", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::four, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("3", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one | enum_object_with_registered_enum_flags_test::two, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("12", result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three | enum_object_with_registered_enum_flags_test::four, result, csf_);
    }
    
    void test_method_(try_parse_with_invalid_enum) {
      enum_object_with_registered_enum_flags_test result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("16", result), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(16), result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("five", result), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(-1), result, csf_);
      
      assert::is_false(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("OnE", result), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(-1), result, csf_);
    }
    
    void test_method_(try_parse_with_ignore_case_to_false) {
      enum_object_with_registered_enum_flags_test result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("none", false, result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("OnE", false, result), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(-1), result, csf_);
      
      assert::is_false(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("TWO", false, result), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(-1), result, csf_);
      
      assert::is_false(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("tHREE", false, result), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(-1), result, csf_);
      
      assert::is_false(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("Four", false, result), csf_);
      assert::are_equal(as<enum_object_with_registered_enum_flags_test>(-1), result, csf_);
    }
    
    void test_method_(try_parse_with_ignore_case_to_true) {
      enum_object_with_registered_enum_flags_test result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("none", true, result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::none, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("OnE", true, result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::one, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("TWO", true, result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::two, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("tHREE", true, result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::three, result, csf_);
      
      result = as<enum_object_with_registered_enum_flags_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_registered_enum_flags_test>("Four", true, result), csf_);
      assert::are_equal(enum_object_with_registered_enum_flags_test::four, result, csf_);
    }
  };
}
