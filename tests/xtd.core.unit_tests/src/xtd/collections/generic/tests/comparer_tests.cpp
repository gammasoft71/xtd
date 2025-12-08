#include <xtd/collections/generic/comparer>
#include <xtd/icomparable>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::generic::tests {
  class test_class_(comparer_tests) {
    auto test_method_(default_comparer_with_boolean) {
      assert::is_negative(comparer<boolean>::default_comparer.compare(false, true));
      assert::is_zero(comparer<boolean>::default_comparer.compare(true, true));
      assert::is_positive(comparer<boolean>::default_comparer.compare(true, false));
    }
    
    auto test_method_(default_comparer_with_byte) {
      assert::is_negative(comparer<byte>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<byte>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<byte>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_decimal) {
      assert::is_negative(comparer<decimal>::default_comparer.compare(.1f, .4f));
      assert::is_zero(comparer<decimal>::default_comparer.compare(.4f, .4f));
      assert::is_positive(comparer<decimal>::default_comparer.compare(.4f, .1f));
    }
    
    auto test_method_(default_comparer_with_double) {
      assert::is_negative(comparer<double>::default_comparer.compare(.1f, .4f));
      assert::is_zero(comparer<double>::default_comparer.compare(.4f, .4f));
      assert::is_positive(comparer<double>::default_comparer.compare(.4f, .1f));
    }
    
    auto test_method_(default_comparer_with_int16) {
      assert::is_negative(comparer<int16>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<int16>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<int16>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_int32) {
      assert::is_negative(comparer<int32>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<int32>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<int32>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_int64) {
      assert::is_negative(comparer<int64>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<int64>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<int64>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_intptr) {
      assert::is_negative(comparer<intptr>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<intptr>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<intptr>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_sbyte) {
      assert::is_negative(comparer<sbyte>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<sbyte>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<sbyte>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_single) {
      assert::is_negative(comparer<single>::default_comparer.compare(.1f, .4f));
      assert::is_zero(comparer<single>::default_comparer.compare(.4f, .4f));
      assert::is_positive(comparer<single>::default_comparer.compare(.4f, .1f));
    }
    
    auto test_method_(default_comparer_with_string) {
      assert::is_negative(comparer<string>::default_comparer.compare("a", "g"));
      assert::is_zero(comparer<string>::default_comparer.compare("g", "g"));
      assert::is_positive(comparer<string>::default_comparer.compare("g", "a"));
    }
    
    auto test_method_(default_comparer_with_uint16) {
      assert::is_negative(comparer<uint16>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<uint16>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<uint16>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_uint32) {
      assert::is_negative(comparer<uint32>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<uint32>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<uint32>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_uint64) {
      assert::is_negative(comparer<uint64>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<uint64>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<uint64>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_uintptr) {
      assert::is_negative(comparer<uintptr>::default_comparer.compare(1, 4));
      assert::is_zero(comparer<uintptr>::default_comparer.compare(4, 4));
      assert::is_positive(comparer<uintptr>::default_comparer.compare(4, 1));
    }
    
    auto test_method_(default_comparer_with_icomparable_object) {
      struct foo : public icomparable<foo> {
        foo(int value) : value{value} {}
        int value = 0;
        int compare_to(const foo& o) const noexcept override {return value < o.value ? -1 : (value > o.value ? 1 : 0);}
      };
      
      assert::is_negative(comparer<foo>::default_comparer.compare(foo {1}, foo {4}));
      assert::is_zero(comparer<foo>::default_comparer.compare(foo {4}, foo {4}));
      assert::is_positive(comparer<foo>::default_comparer.compare(foo {4}, foo {1}));
    }
    
    auto test_method_(default_comparer_object_with_less_and_grether_operators) {
      struct foo {
        int value = 0;
        bool operator <(const foo& o) const noexcept {return value < o.value;}
        bool operator >(const foo& o) const noexcept {return value > o.value;}
      };
      
      assert::is_negative(comparer<foo>::default_comparer.compare(foo {1}, foo {4}));
      assert::is_zero(comparer<foo>::default_comparer.compare(foo {4}, foo {4}));
      assert::is_positive(comparer<foo>::default_comparer.compare(foo {4}, foo {1}));
    }
  };
}
