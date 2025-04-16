#include <xtd/as>
#include <xtd/enum_object>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum enum_object_with_unregistered_enum_test {
  none,
  one,
  two,
  three,
  four
};

namespace xtd::tests {
  class test_class_(enum_object_with_unregistered_enum_tests) {
    void test_method_(enum_object_with_unregistered_enum_test_default_ctor) {
      enum_object<enum_object_with_unregistered_enum_test> e;
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_test::none));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(enum_object_with_unregistered_enum_test::none, e);
      assert::are_equal(enum_object_with_unregistered_enum_test::none, e.value);
      assert::are_equal(as<byte>(0), e.to_byte());
      assert::are_equal(as<int16>(0), e.to_int16());
      assert::are_equal(as<int32>(0), e.to_int32());
      assert::are_equal(as<int64>(0), e.to_int64());
      assert::are_equal(as<sbyte>(0), e.to_sbyte());
      assert::are_equal(as<uint16>(0), e.to_uint16());
      assert::are_equal(as<uint32>(0), e.to_uint32());
      assert::are_equal(as<uint64>(0), e.to_uint64());
      assert::are_equal("0", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_test_ctor_with_one) {
      enum_object<enum_object_with_unregistered_enum_test> e {enum_object_with_unregistered_enum_test::one};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_test::one));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(enum_object_with_unregistered_enum_test::one, e);
      assert::are_equal(enum_object_with_unregistered_enum_test::one, e.value);
      assert::are_equal(as<byte>(1), e.to_byte());
      assert::are_equal(as<int16>(1), e.to_int16());
      assert::are_equal(as<int32>(1), e.to_int32());
      assert::are_equal(as<int64>(1), e.to_int64());
      assert::are_equal(as<sbyte>(1), e.to_sbyte());
      assert::are_equal(as<uint16>(1), e.to_uint16());
      assert::are_equal(as<uint32>(1), e.to_uint32());
      assert::are_equal(as<uint64>(1), e.to_uint64());
      assert::are_equal("1", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_test_ctor_with_two) {
      enum_object<enum_object_with_unregistered_enum_test> e {enum_object_with_unregistered_enum_test::two};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_test::two));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(enum_object_with_unregistered_enum_test::two, e);
      assert::are_equal(enum_object_with_unregistered_enum_test::two, e.value);
      assert::are_equal(as<byte>(2), e.to_byte());
      assert::are_equal(as<int16>(2), e.to_int16());
      assert::are_equal(as<int32>(2), e.to_int32());
      assert::are_equal(as<int64>(2), e.to_int64());
      assert::are_equal(as<sbyte>(2), e.to_sbyte());
      assert::are_equal(as<uint16>(2), e.to_uint16());
      assert::are_equal(as<uint32>(2), e.to_uint32());
      assert::are_equal(as<uint64>(2), e.to_uint64());
      assert::are_equal("2", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_test_ctor_with_three) {
      enum_object<enum_object_with_unregistered_enum_test> e {enum_object_with_unregistered_enum_test::three};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_test::three));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(enum_object_with_unregistered_enum_test::three, e);
      assert::are_equal(enum_object_with_unregistered_enum_test::three, e.value);
      assert::are_equal(as<byte>(3), e.to_byte());
      assert::are_equal(as<int16>(3), e.to_int16());
      assert::are_equal(as<int32>(3), e.to_int32());
      assert::are_equal(as<int64>(3), e.to_int64());
      assert::are_equal(as<sbyte>(3), e.to_sbyte());
      assert::are_equal(as<uint16>(3), e.to_uint16());
      assert::are_equal(as<uint32>(3), e.to_uint32());
      assert::are_equal(as<uint64>(3), e.to_uint64());
      assert::are_equal("3", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_test_ctor_with_four) {
      enum_object<enum_object_with_unregistered_enum_test> e {enum_object_with_unregistered_enum_test::four};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_test::four));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(enum_object_with_unregistered_enum_test::four, e);
      assert::are_equal(enum_object_with_unregistered_enum_test::four, e.value);
      assert::are_equal(as<byte>(4), e.to_byte());
      assert::are_equal(as<int16>(4), e.to_int16());
      assert::are_equal(as<int32>(4), e.to_int32());
      assert::are_equal(as<int64>(4), e.to_int64());
      assert::are_equal(as<sbyte>(4), e.to_sbyte());
      assert::are_equal(as<uint16>(4), e.to_uint16());
      assert::are_equal(as<uint32>(4), e.to_uint32());
      assert::are_equal(as<uint64>(4), e.to_uint64());
      assert::are_equal("4", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_test_ctor_with_invalid_value) {
      enum_object<enum_object_with_unregistered_enum_test> e {as<enum_object_with_unregistered_enum_test>(5)};
      
      assert::is_true(e.has_flag(as<enum_object_with_unregistered_enum_test>(5)));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(5), e);
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(5), e.value);
      assert::are_equal(as<byte>(5), e.to_byte());
      assert::are_equal(as<int16>(5), e.to_int16());
      assert::are_equal(as<int32>(5), e.to_int32());
      assert::are_equal(as<int64>(5), e.to_int64());
      assert::are_equal(as<sbyte>(5), e.to_sbyte());
      assert::are_equal(as<uint16>(5), e.to_uint16());
      assert::are_equal(as<uint32>(5), e.to_uint32());
      assert::are_equal(as<uint64>(5), e.to_uint64());
      assert::are_equal("5", e.to_string());
    }
    
    void test_method_(equals) {
      assert::is_true(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one).equals(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one)));
      assert::is_false(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one).equals(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::two)));
      assert::is_true(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) == enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one));
      assert::is_false(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) != enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one));
      assert::is_false(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) == enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::two));
      assert::is_true(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) != enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::two));
      
      assert::is_true(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one).equals(enum_object_with_unregistered_enum_test::one));
      assert::is_false(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one).equals(enum_object_with_unregistered_enum_test::two));
      assert::is_true(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) == enum_object_with_unregistered_enum_test::one);
      assert::is_false(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) != enum_object_with_unregistered_enum_test::one);
      assert::is_false(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) == enum_object_with_unregistered_enum_test::two);
      assert::is_true(enum_object<enum_object_with_unregistered_enum_test>(enum_object_with_unregistered_enum_test::one) != enum_object_with_unregistered_enum_test::two);
    }
    
    void test_method_(get_entries) {
      auto expected_entries = enum_collection<enum_object_with_unregistered_enum_test> {};
      auto actual_entries = enum_object<>::get_entries<enum_object_with_unregistered_enum_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()));
      //collection_assert::is_empty( enum_object<>::get_entries<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_byte) {
      collection_assert::is_empty(enum_object<>::get_entries_as_byte<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_int16) {
      collection_assert::is_empty(enum_object<>::get_entries_as_int16<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_int32) {
      collection_assert::is_empty(enum_object<>::get_entries_as_int32<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_int64) {
      collection_assert::is_empty(enum_object<>::get_entries_as_int64<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_sbyte) {
      collection_assert::is_empty(enum_object<>::get_entries_as_sbyte<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_uint16) {
      collection_assert::is_empty(enum_object<>::get_entries_as_uint16<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_uint32) {
      collection_assert::is_empty(enum_object<>::get_entries_as_uint32<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_entries_as_uint64) {
      collection_assert::is_empty(enum_object<>::get_entries_as_uint64<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_name) {
      assert::are_equal("0", enum_object<>::get_name(enum_object_with_unregistered_enum_test::none));
      assert::are_equal("1", enum_object<>::get_name(enum_object_with_unregistered_enum_test::one));
      assert::are_equal("2", enum_object<>::get_name(enum_object_with_unregistered_enum_test::two));
      assert::are_equal("3", enum_object<>::get_name(enum_object_with_unregistered_enum_test::three));
      assert::are_equal("4", enum_object<>::get_name(enum_object_with_unregistered_enum_test::four));
      assert::are_equal("5", enum_object<>::get_name(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(get_name_enum_object) {
      assert::are_equal("0", enum_object<>::get_name(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::none}));
      assert::are_equal("1", enum_object<>::get_name(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::one}));
      assert::are_equal("2", enum_object<>::get_name(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::two}));
      assert::are_equal("3", enum_object<>::get_name(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::three}));
      assert::are_equal("4", enum_object<>::get_name(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::four}));
      assert::are_equal("5", enum_object<>::get_name(enum_object<enum_object_with_unregistered_enum_test> {as<enum_object_with_unregistered_enum_test>(5)}));
    }
    
    void test_method_(get_name_int32) {
      assert::are_equal("0", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int32>(0)));
      assert::are_equal("1", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int32>(1)));
      assert::are_equal("2", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int32>(2)));
      assert::are_equal("3", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int32>(3)));
      assert::are_equal("4", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int32>(4)));
      assert::are_equal("5", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int32>(5)));
    }
    
    void test_method_(get_name_int64) {
      assert::are_equal("0", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int64>(0)));
      assert::are_equal("1", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int64>(1)));
      assert::are_equal("2", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int64>(2)));
      assert::are_equal("3", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int64>(3)));
      assert::are_equal("4", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int64>(4)));
      assert::are_equal("5", enum_object<>::get_name<enum_object_with_unregistered_enum_test>(as<int64>(5)));
    }
    
    void test_method_(get_names) {
      collection_assert::is_empty(enum_object<>::get_names<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values) {
      auto expected_entries = array<enum_object_with_unregistered_enum_test> {};
      auto actual_entries = enum_object<>::get_values<enum_object_with_unregistered_enum_test>();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()));
    }
    
    void test_method_(get_values_as_byte) {
      collection_assert::is_empty(enum_object<>::get_values_as_byte<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values_as_int16) {
      collection_assert::is_empty(enum_object<>::get_values_as_int16<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values_as_int32) {
      collection_assert::is_empty(enum_object<>::get_values_as_int32<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values_as_int64) {
      collection_assert::is_empty(enum_object<>::get_values_as_int64<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values_as_sbyte) {
      collection_assert::is_empty(enum_object<>::get_values_as_sbyte<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values_as_uint16) {
      collection_assert::is_empty(enum_object<>::get_values_as_uint16<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values_as_uint32) {
      collection_assert::is_empty(enum_object<>::get_values_as_uint32<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(get_values_as_uint64) {
      collection_assert::is_empty(enum_object<>::get_values_as_uint64<enum_object_with_unregistered_enum_test>());
    }
    
    void test_method_(is_defined) {
      assert::is_false(enum_object<>::is_defined(enum_object_with_unregistered_enum_test::none));
      assert::is_false(enum_object<>::is_defined(enum_object_with_unregistered_enum_test::one));
      assert::is_false(enum_object<>::is_defined(enum_object_with_unregistered_enum_test::two));
      assert::is_false(enum_object<>::is_defined(enum_object_with_unregistered_enum_test::three));
      assert::is_false(enum_object<>::is_defined(enum_object_with_unregistered_enum_test::four));
      
      assert::is_false(enum_object<>::is_defined(as<enum_object_with_unregistered_enum_test>(0)));
      assert::is_false(enum_object<>::is_defined(as<enum_object_with_unregistered_enum_test>(1)));
      assert::is_false(enum_object<>::is_defined(as<enum_object_with_unregistered_enum_test>(2)));
      assert::is_false(enum_object<>::is_defined(as<enum_object_with_unregistered_enum_test>(3)));
      assert::is_false(enum_object<>::is_defined(as<enum_object_with_unregistered_enum_test>(4)));
      assert::is_false(enum_object<>::is_defined(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(is_defined_enum_object) {
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::none}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::one}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::two}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::three}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {enum_object_with_unregistered_enum_test::four}));
      
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {as<enum_object_with_unregistered_enum_test>(0)}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {as<enum_object_with_unregistered_enum_test>(1)}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {as<enum_object_with_unregistered_enum_test>(2)}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {as<enum_object_with_unregistered_enum_test>(3)}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {as<enum_object_with_unregistered_enum_test>(4)}));
      assert::is_false(enum_object<>::is_defined(enum_object<enum_object_with_unregistered_enum_test> {as<enum_object_with_unregistered_enum_test>(5)}));
    }
    
    void test_method_(parse) {
      assert::are_equal(enum_object_with_unregistered_enum_test::none, enum_object<>::parse<enum_object_with_unregistered_enum_test>("0"));
      assert::are_equal(enum_object_with_unregistered_enum_test::one, enum_object<>::parse<enum_object_with_unregistered_enum_test>("1"));
      assert::are_equal(enum_object_with_unregistered_enum_test::two, enum_object<>::parse<enum_object_with_unregistered_enum_test>("2"));
      assert::are_equal(enum_object_with_unregistered_enum_test::three, enum_object<>::parse<enum_object_with_unregistered_enum_test>("3"));
      assert::are_equal(enum_object_with_unregistered_enum_test::four, enum_object<>::parse<enum_object_with_unregistered_enum_test>("4"));
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(5), enum_object<>::parse<enum_object_with_unregistered_enum_test>("5"));
      
      assert::throws<format_exception>([] {enum_object<>::parse<enum_object_with_unregistered_enum_test>("none");});
      assert::throws<format_exception>([] {enum_object<>::parse<enum_object_with_unregistered_enum_test>("one");});
      assert::throws<format_exception>([] {enum_object<>::parse<enum_object_with_unregistered_enum_test>("two");});
      assert::throws<format_exception>([] {enum_object<>::parse<enum_object_with_unregistered_enum_test>("three");});
      assert::throws<format_exception>([] {enum_object<>::parse<enum_object_with_unregistered_enum_test>("four");});
      assert::throws<format_exception>([] {enum_object<>::parse<enum_object_with_unregistered_enum_test>("five");});
    }
    
    void test_method_(to_byte) {
      assert::are_equal(as<byte>(0), enum_object<>::to_byte(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<byte>(1), enum_object<>::to_byte(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<byte>(2), enum_object<>::to_byte(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<byte>(3), enum_object<>::to_byte(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<byte>(4), enum_object<>::to_byte(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<byte>(5), enum_object<>::to_byte(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(to_int16) {
      assert::are_equal(as<int16>(0), enum_object<>::to_int16(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<int16>(1), enum_object<>::to_int16(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<int16>(2), enum_object<>::to_int16(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<int16>(3), enum_object<>::to_int16(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<int16>(4), enum_object<>::to_int16(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<int16>(5), enum_object<>::to_int16(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(to_int32) {
      assert::are_equal(as<int32>(0), enum_object<>::to_int32(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<int32>(1), enum_object<>::to_int32(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<int32>(2), enum_object<>::to_int32(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<int32>(3), enum_object<>::to_int32(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<int32>(4), enum_object<>::to_int32(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<int32>(5), enum_object<>::to_int32(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(to_int64) {
      assert::are_equal(as<int64>(0), enum_object<>::to_int64(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<int64>(1), enum_object<>::to_int64(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<int64>(2), enum_object<>::to_int64(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<int64>(3), enum_object<>::to_int64(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<int64>(4), enum_object<>::to_int64(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<int64>(5), enum_object<>::to_int64(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(to_sbyte) {
      assert::are_equal(as<sbyte>(0), enum_object<>::to_sbyte(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<sbyte>(1), enum_object<>::to_sbyte(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<sbyte>(2), enum_object<>::to_sbyte(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<sbyte>(3), enum_object<>::to_sbyte(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<sbyte>(4), enum_object<>::to_sbyte(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<sbyte>(5), enum_object<>::to_sbyte(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(to_uint16) {
      assert::are_equal(as<uint16>(0), enum_object<>::to_uint16(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<uint16>(1), enum_object<>::to_uint16(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<uint16>(2), enum_object<>::to_uint16(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<uint16>(3), enum_object<>::to_uint16(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<uint16>(4), enum_object<>::to_uint16(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<uint16>(5), enum_object<>::to_uint16(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(to_uint32) {
      assert::are_equal(as<uint32>(0), enum_object<>::to_uint32(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<uint32>(1), enum_object<>::to_uint32(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<uint32>(2), enum_object<>::to_uint32(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<uint32>(3), enum_object<>::to_uint32(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<uint32>(4), enum_object<>::to_uint32(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<uint32>(5), enum_object<>::to_uint32(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(to_uint64) {
      assert::are_equal(as<uint64>(0), enum_object<>::to_uint64(enum_object_with_unregistered_enum_test::none));
      assert::are_equal(as<uint64>(1), enum_object<>::to_uint64(enum_object_with_unregistered_enum_test::one));
      assert::are_equal(as<uint64>(2), enum_object<>::to_uint64(enum_object_with_unregistered_enum_test::two));
      assert::are_equal(as<uint64>(3), enum_object<>::to_uint64(enum_object_with_unregistered_enum_test::three));
      assert::are_equal(as<uint64>(4), enum_object<>::to_uint64(enum_object_with_unregistered_enum_test::four));
      assert::are_equal(as<uint64>(5), enum_object<>::to_uint64(as<enum_object_with_unregistered_enum_test>(5)));
    }
    
    void test_method_(try_parse) {
      enum_object_with_unregistered_enum_test result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("0", result));
      assert::are_equal(enum_object_with_unregistered_enum_test::none, result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("1", result));
      assert::are_equal(enum_object_with_unregistered_enum_test::one, result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("2", result));
      assert::are_equal(enum_object_with_unregistered_enum_test::two, result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("3", result));
      assert::are_equal(enum_object_with_unregistered_enum_test::three, result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("4", result));
      assert::are_equal(enum_object_with_unregistered_enum_test::four, result);
    }
    
    void test_method_(try_parse_with_invalid_enum) {
      enum_object_with_unregistered_enum_test result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_true(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("5", result));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(5), result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("none", result));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(-1), result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("one", result));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(-1), result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("two", result));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(-1), result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("three", result));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(-1), result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("four", result));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(-1), result);
      
      result = as<enum_object_with_unregistered_enum_test>(-1);
      assert::is_false(enum_object<>::try_parse<enum_object_with_unregistered_enum_test>("five", result));
      assert::are_equal(as<enum_object_with_unregistered_enum_test>(-1), result);
    }
  };
}
