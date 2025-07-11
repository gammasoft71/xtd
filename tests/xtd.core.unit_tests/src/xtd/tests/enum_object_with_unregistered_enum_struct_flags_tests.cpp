#include <xtd/as>
#include <xtd/enum_object>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum struct enum_object_with_unregistered_enum_struct_flags_test {
  none = 0b0,
  one = 0b1,
  two = 0b10,
  three = 0b100,
  four = 0b1000
};

inline enum_object_with_unregistered_enum_struct_flags_test operator |(enum_object_with_unregistered_enum_struct_flags_test lhs, enum_object_with_unregistered_enum_struct_flags_test rhs) {return static_cast < enum_object_with_unregistered_enum_struct_flags_test > (static_cast < std::underlying_type<enum_object_with_unregistered_enum_struct_flags_test>::type>(lhs) | static_cast < std::underlying_type < enum_object_with_unregistered_enum_struct_flags_test >::type > (rhs));}

namespace xtd::tests {
  class test_class_(enum_object_with_unregistered_enum_struct_flags_tests) {
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_default_ctor) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e;
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::none, e);
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::none, e.value);
      assert::are_equal(as < byte > (0), e.to_byte());
      assert::are_equal(as < int16 > (0), e.to_int16());
      assert::are_equal(as < int32 > (0), e.to_int32());
      assert::are_equal(as < int64 > (0), e.to_int64());
      assert::are_equal(as < sbyte > (0), e.to_sbyte());
      assert::are_equal(as < uint16 > (0), e.to_uint16());
      assert::are_equal(as < uint32 > (0), e.to_uint32());
      assert::are_equal(as < uint64 > (0), e.to_uint64());
      assert::are_equal("0", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_ctor_with_one) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e {enum_object_with_unregistered_enum_struct_flags_test::one};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one, e);
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one, e.value);
      assert::are_equal(as < byte > (1), e.to_byte());
      assert::are_equal(as < int16 > (1), e.to_int16());
      assert::are_equal(as < int32 > (1), e.to_int32());
      assert::are_equal(as < int64 > (1), e.to_int64());
      assert::are_equal(as < sbyte > (1), e.to_sbyte());
      assert::are_equal(as < uint16 > (1), e.to_uint16());
      assert::are_equal(as < uint32 > (1), e.to_uint32());
      assert::are_equal(as < uint64 > (1), e.to_uint64());
      assert::are_equal("1", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_ctor_with_two) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e {enum_object_with_unregistered_enum_struct_flags_test::two};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::two, e);
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::two, e.value);
      assert::are_equal(as < byte > (2), e.to_byte());
      assert::are_equal(as < int16 > (2), e.to_int16());
      assert::are_equal(as < int32 > (2), e.to_int32());
      assert::are_equal(as < int64 > (2), e.to_int64());
      assert::are_equal(as < sbyte > (2), e.to_sbyte());
      assert::are_equal(as < uint16 > (2), e.to_uint16());
      assert::are_equal(as < uint32 > (2), e.to_uint32());
      assert::are_equal(as < uint64 > (2), e.to_uint64());
      assert::are_equal("2", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_ctor_with_three) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e {enum_object_with_unregistered_enum_struct_flags_test::three};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three, e);
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three, e.value);
      assert::are_equal(as < byte > (4), e.to_byte());
      assert::are_equal(as < int16 > (4), e.to_int16());
      assert::are_equal(as < int32 > (4), e.to_int32());
      assert::are_equal(as < int64 > (4), e.to_int64());
      assert::are_equal(as < sbyte > (4), e.to_sbyte());
      assert::are_equal(as < uint16 > (4), e.to_uint16());
      assert::are_equal(as < uint32 > (4), e.to_uint32());
      assert::are_equal(as < uint64 > (4), e.to_uint64());
      assert::are_equal("4", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_ctor_with_four) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e {enum_object_with_unregistered_enum_struct_flags_test::four};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::four, e);
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::four, e.value);
      assert::are_equal(as < byte > (8), e.to_byte());
      assert::are_equal(as < int16 > (8), e.to_int16());
      assert::are_equal(as < int32 > (8), e.to_int32());
      assert::are_equal(as < int64 > (8), e.to_int64());
      assert::are_equal(as < sbyte > (8), e.to_sbyte());
      assert::are_equal(as < uint16 > (8), e.to_uint16());
      assert::are_equal(as < uint32 > (8), e.to_uint32());
      assert::are_equal(as < uint64 > (8), e.to_uint64());
      assert::are_equal("8", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_ctor_with_one_and_two) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e {enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two, e);
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two, e.value);
      assert::are_equal(as < byte > (3), e.to_byte());
      assert::are_equal(as < int16 > (3), e.to_int16());
      assert::are_equal(as < int32 > (3), e.to_int32());
      assert::are_equal(as < int64 > (3), e.to_int64());
      assert::are_equal(as < sbyte > (3), e.to_sbyte());
      assert::are_equal(as < uint16 > (3), e.to_uint16());
      assert::are_equal(as < uint32 > (3), e.to_uint32());
      assert::are_equal(as < uint64 > (3), e.to_uint64());
      assert::are_equal("3", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_ctor_with_three_and_four) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e {enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four};
      
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::is_true(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four, e);
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four, e.value);
      assert::are_equal(as < byte > (12), e.to_byte());
      assert::are_equal(as < int16 > (12), e.to_int16());
      assert::are_equal(as < int32 > (12), e.to_int32());
      assert::are_equal(as < int64 > (12), e.to_int64());
      assert::are_equal(as < sbyte > (12), e.to_sbyte());
      assert::are_equal(as < uint16 > (12), e.to_uint16());
      assert::are_equal(as < uint32 > (12), e.to_uint32());
      assert::are_equal(as < uint64 > (12), e.to_uint64());
      assert::are_equal("12", e.to_string());
    }
    
    void test_method_(enum_object_with_unregistered_enum_struct_flags_test_ctor_with_invalid_value) {
      enum_object < enum_object_with_unregistered_enum_struct_flags_test > e {as < enum_object_with_unregistered_enum_struct_flags_test > (16)};
      
      assert::is_true(e.has_flag(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::is_false(e.has_flag(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (16), e);
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (16), e.value);
      assert::are_equal(as < byte > (16), e.to_byte());
      assert::are_equal(as < int16 > (16), e.to_int16());
      assert::are_equal(as < int32 > (16), e.to_int32());
      assert::are_equal(as < int64 > (16), e.to_int64());
      assert::are_equal(as < sbyte > (16), e.to_sbyte());
      assert::are_equal(as < uint16 > (16), e.to_uint16());
      assert::are_equal(as < uint32 > (16), e.to_uint32());
      assert::are_equal(as < uint64 > (16), e.to_uint64());
      assert::are_equal("16", e.to_string());
    }
    
    void test_method_(equals) {
      assert::is_true(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one).equals(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one)));
      assert::is_false(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one).equals(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::two)));
      assert::is_true(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) == enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::is_false(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) != enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::is_false(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) == enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::is_true(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) != enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::two));
      
      assert::is_true(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one).equals(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::is_false(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one).equals(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::is_true(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) == enum_object_with_unregistered_enum_struct_flags_test::one);
      assert::is_false(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) != enum_object_with_unregistered_enum_struct_flags_test::one);
      assert::is_false(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) == enum_object_with_unregistered_enum_struct_flags_test::two);
      assert::is_true(enum_object < enum_object_with_unregistered_enum_struct_flags_test > (enum_object_with_unregistered_enum_struct_flags_test::one) != enum_object_with_unregistered_enum_struct_flags_test::two);
    }
    
    void test_method_(get_entries) {
      auto expected_entries = enum_collection < enum_object_with_unregistered_enum_struct_flags_test > {};
      auto actual_entries = enum_object < >::get_entries < enum_object_with_unregistered_enum_struct_flags_test > ();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()));
      //collection_assert::are_equal(enum_collection<enum_object_with_unregistered_enum_struct_flags_test> {{enum_object_with_unregistered_enum_struct_flags_test::none, "none"}, {enum_object_with_unregistered_enum_struct_flags_test::one, "one"}, {enum_object_with_unregistered_enum_struct_flags_test::two, "two"}, {enum_object_with_unregistered_enum_struct_flags_test::three, "three"}, {enum_object_with_unregistered_enum_struct_flags_test::four, "four"}}, enum_object<>::get_entries<enum_object_with_unregistered_enum_struct_flags_test>());
    }
    
    void test_method_(get_entries_as_byte) {
      collection_assert::is_empty(enum_object < >::get_entries_as_byte < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_entries_as_int16) {
      collection_assert::is_empty(enum_object < >::get_entries_as_int16 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_entries_as_int32) {
      collection_assert::is_empty(enum_object < >::get_entries_as_int32 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_entries_as_int64) {
      collection_assert::is_empty(enum_object < >::get_entries_as_int64 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_entries_as_sbyte) {
      collection_assert::is_empty(enum_object < >::get_entries_as_sbyte < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_entries_as_uint16) {
      collection_assert::is_empty(enum_object < >::get_entries_as_uint16 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_entries_as_uint32) {
      collection_assert::is_empty(enum_object < >::get_entries_as_uint32 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_entries_as_uint64) {
      collection_assert::is_empty(enum_object < >::get_entries_as_uint64 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_name) {
      assert::are_equal("0", enum_object < >::get_name(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal("1", enum_object < >::get_name(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal("2", enum_object < >::get_name(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal("4", enum_object < >::get_name(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal("8", enum_object < >::get_name(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal("16", enum_object < >::get_name(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
    }
    
    void test_method_(get_name_enum_object) {
      assert::are_equal("0", enum_object < >::get_name(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::none}));
      assert::are_equal("1", enum_object < >::get_name(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::one}));
      assert::are_equal("2", enum_object < >::get_name(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::two}));
      assert::are_equal("4", enum_object < >::get_name(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::three}));
      assert::are_equal("8", enum_object < >::get_name(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::four}));
      assert::are_equal("16", enum_object < >::get_name(enum_object < enum_object_with_unregistered_enum_struct_flags_test> {as < enum_object_with_unregistered_enum_struct_flags_test > (16)}));
    }
    
    void test_method_(get_name_int32) {
      assert::are_equal("0", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int32 > (0)));
      assert::are_equal("1", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int32 > (1)));
      assert::are_equal("2", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int32 > (2)));
      assert::are_equal("4", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int32 > (4)));
      assert::are_equal("8", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int32 > (8)));
      assert::are_equal("16", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int32 > (16)));
    }
    
    void test_method_(get_name_int64) {
      assert::are_equal("0", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int64 > (0)));
      assert::are_equal("1", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int64 > (1)));
      assert::are_equal("2", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int64 > (2)));
      assert::are_equal("4", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int64 > (4)));
      assert::are_equal("8", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int64 > (8)));
      assert::are_equal("16", enum_object < >::get_name < enum_object_with_unregistered_enum_struct_flags_test>(as < int64 > (16)));
    }
    
    void test_method_(get_names) {
      collection_assert::is_empty(enum_object < >::get_names < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values) {
      auto expected_entries = array < enum_object_with_unregistered_enum_struct_flags_test > {};
      auto actual_entries = enum_object < >::get_values < enum_object_with_unregistered_enum_struct_flags_test > ();
      assert::is_true(std::equal(actual_entries.begin(), actual_entries.end(), expected_entries.begin(), expected_entries.end()));
    }
    
    void test_method_(get_values_as_byte) {
      collection_assert::is_empty(enum_object < >::get_values_as_byte < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values_as_int16) {
      collection_assert::is_empty(enum_object < >::get_values_as_int16 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values_as_int32) {
      collection_assert::is_empty(enum_object < >::get_values_as_int32 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values_as_int64) {
      collection_assert::is_empty(enum_object < >::get_values_as_int64 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values_as_sbyte) {
      collection_assert::is_empty(enum_object < >::get_values_as_sbyte < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values_as_uint16) {
      collection_assert::is_empty(enum_object < >::get_values_as_uint16 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values_as_uint32) {
      collection_assert::is_empty(enum_object < >::get_values_as_uint32 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(get_values_as_uint64) {
      collection_assert::is_empty(enum_object < >::get_values_as_uint64 < enum_object_with_unregistered_enum_struct_flags_test > ());
    }
    
    void test_method_(is_defined) {
      assert::is_false(enum_object < >::is_defined(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::is_false(enum_object < >::is_defined(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::is_false(enum_object < >::is_defined(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::is_false(enum_object < >::is_defined(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::is_false(enum_object < >::is_defined(enum_object_with_unregistered_enum_struct_flags_test::four));
      
      assert::is_false(enum_object < >::is_defined(as < enum_object_with_unregistered_enum_struct_flags_test > (0)));
      assert::is_false(enum_object < >::is_defined(as < enum_object_with_unregistered_enum_struct_flags_test > (1)));
      assert::is_false(enum_object < >::is_defined(as < enum_object_with_unregistered_enum_struct_flags_test > (2)));
      assert::is_false(enum_object < >::is_defined(as < enum_object_with_unregistered_enum_struct_flags_test > (4)));
      assert::is_false(enum_object < >::is_defined(as < enum_object_with_unregistered_enum_struct_flags_test > (8)));
      assert::is_false(enum_object < >::is_defined(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
    }
    
    void test_method_(is_defined_enum_object) {
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::none}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::one}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::two}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::three}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test > {enum_object_with_unregistered_enum_struct_flags_test::four}));
      
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test> {as < enum_object_with_unregistered_enum_struct_flags_test > (0)}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test> {as < enum_object_with_unregistered_enum_struct_flags_test > (1)}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test> {as < enum_object_with_unregistered_enum_struct_flags_test > (2)}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test> {as < enum_object_with_unregistered_enum_struct_flags_test > (4)}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test> {as < enum_object_with_unregistered_enum_struct_flags_test > (8)}));
      assert::is_false(enum_object < >::is_defined(enum_object < enum_object_with_unregistered_enum_struct_flags_test> {as < enum_object_with_unregistered_enum_struct_flags_test > (16)}));
    }
    
    void test_method_(parse) {
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::none, enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("0"));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one, enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("1"));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::two, enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("2"));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three, enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("4"));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::four, enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("8"));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two, enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("3"));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four, enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("12"));
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (16), enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("16"));
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("none");});
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("one");});
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("two");});
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("three");});
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("four");});
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("one, two");});
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("three, four");});
      assert::throws < format_exception > ([] {enum_object < >::parse < enum_object_with_unregistered_enum_struct_flags_test > ("five");});
    }
    
    void test_method_(to_byte) {
      assert::are_equal(as < byte > (0), enum_object < >::to_byte(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < byte > (1), enum_object < >::to_byte(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < byte > (2), enum_object < >::to_byte(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < byte > (4), enum_object < >::to_byte(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < byte > (8), enum_object < >::to_byte(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < byte > (16), enum_object < >::to_byte(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < byte > (3), enum_object < >::to_byte(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < byte > (12), enum_object < >::to_byte(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(to_int16) {
      assert::are_equal(as < int16 > (0), enum_object < >::to_int16(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < int16 > (1), enum_object < >::to_int16(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < int16 > (2), enum_object < >::to_int16(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < int16 > (4), enum_object < >::to_int16(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < int16 > (8), enum_object < >::to_int16(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < int16 > (16), enum_object < >::to_int16(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < int16 > (3), enum_object < >::to_int16(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < int16 > (12), enum_object < >::to_int16(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(to_int32) {
      assert::are_equal(as < int32 > (0), enum_object < >::to_int32(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < int32 > (1), enum_object < >::to_int32(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < int32 > (2), enum_object < >::to_int32(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < int32 > (4), enum_object < >::to_int32(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < int32 > (8), enum_object < >::to_int32(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < int32 > (16), enum_object < >::to_int32(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < int32 > (3), enum_object < >::to_int32(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < int32 > (12), enum_object < >::to_int32(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(to_int64) {
      assert::are_equal(as < int64 > (0), enum_object < >::to_int64(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < int64 > (1), enum_object < >::to_int64(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < int64 > (2), enum_object < >::to_int64(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < int64 > (4), enum_object < >::to_int64(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < int64 > (8), enum_object < >::to_int64(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < int64 > (16), enum_object < >::to_int64(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < int64 > (3), enum_object < >::to_int64(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < int64 > (12), enum_object < >::to_int64(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(to_sbyte) {
      assert::are_equal(as < sbyte > (0), enum_object < >::to_sbyte(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < sbyte > (1), enum_object < >::to_sbyte(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < sbyte > (2), enum_object < >::to_sbyte(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < sbyte > (4), enum_object < >::to_sbyte(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < sbyte > (8), enum_object < >::to_sbyte(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < sbyte > (16), enum_object < >::to_sbyte(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < sbyte > (3), enum_object < >::to_sbyte(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < sbyte > (12), enum_object < >::to_sbyte(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(to_uint16) {
      assert::are_equal(as < uint16 > (0), enum_object < >::to_uint16(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < uint16 > (1), enum_object < >::to_uint16(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < uint16 > (2), enum_object < >::to_uint16(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < uint16 > (4), enum_object < >::to_uint16(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < uint16 > (8), enum_object < >::to_uint16(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < uint16 > (16), enum_object < >::to_uint16(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < uint16 > (3), enum_object < >::to_uint16(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < uint16 > (12), enum_object < >::to_uint16(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(to_uint32) {
      assert::are_equal(as < uint32 > (0), enum_object < >::to_uint32(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < uint32 > (1), enum_object < >::to_uint32(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < uint32 > (2), enum_object < >::to_uint32(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < uint32 > (4), enum_object < >::to_uint32(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < uint32 > (8), enum_object < >::to_uint32(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < uint32 > (16), enum_object < >::to_uint32(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < uint32 > (3), enum_object < >::to_uint32(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < uint32 > (12), enum_object < >::to_uint32(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(to_uint64) {
      assert::are_equal(as < uint64 > (0), enum_object < >::to_uint64(enum_object_with_unregistered_enum_struct_flags_test::none));
      assert::are_equal(as < uint64 > (1), enum_object < >::to_uint64(enum_object_with_unregistered_enum_struct_flags_test::one));
      assert::are_equal(as < uint64 > (2), enum_object < >::to_uint64(enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < uint64 > (4), enum_object < >::to_uint64(enum_object_with_unregistered_enum_struct_flags_test::three));
      assert::are_equal(as < uint64 > (8), enum_object < >::to_uint64(enum_object_with_unregistered_enum_struct_flags_test::four));
      assert::are_equal(as < uint64 > (16), enum_object < >::to_uint64(as < enum_object_with_unregistered_enum_struct_flags_test > (16)));
      assert::are_equal(as < uint64 > (3), enum_object < >::to_uint64(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two));
      assert::are_equal(as < uint64 > (12), enum_object < >::to_uint64(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four));
    }
    
    void test_method_(try_parse) {
      enum_object_with_unregistered_enum_struct_flags_test result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("0", result));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::none, result);
      
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("1", result));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one, result);
      
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("2", result));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::two, result);
      
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("4", result));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three, result);
      
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("8", result));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::four, result);
      
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("3", result));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::one | enum_object_with_unregistered_enum_struct_flags_test::two, result);
      
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("12", result));
      assert::are_equal(enum_object_with_unregistered_enum_struct_flags_test::three | enum_object_with_unregistered_enum_struct_flags_test::four, result);
    }
    
    void test_method_(try_parse_with_invalid_enum) {
      enum_object_with_unregistered_enum_struct_flags_test result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_true(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("16", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (16), result);
      
      result = as < enum_object_with_unregistered_enum_struct_flags_test > (-1);
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("none", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
      
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("one", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
      
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("two", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
      
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("three", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
      
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("four", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
      
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("five", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
      
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("one, two", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
      
      assert::is_false(enum_object < >::try_parse < enum_object_with_unregistered_enum_struct_flags_test > ("three, four", result));
      assert::are_equal(as < enum_object_with_unregistered_enum_struct_flags_test > (-1), result);
    }
  };
}
