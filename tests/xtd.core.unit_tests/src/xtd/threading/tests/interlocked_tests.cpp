#include <xtd/threading/interlocked>
#include <limits>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(interlocked_tests) {
    void test_method_(add_int32) {
      int32 location = 42;
      assert::are_equal(45, interlocked::add(location, 3), csf_);
      assert::are_equal(45, location, csf_);
    }
    
    void test_method_(add_int64) {
      int64 location = 42;
      assert::are_equal(45, interlocked::add(location, 3), csf_);
      assert::are_equal(45, location, csf_);
    }
    
    void test_method_(compare_exchange_double_if_comparand_equal) {
      double location = 0.42;
      assert::are_equal(0.42, interlocked::compare_exchange(location, 0.24, 0.42), csf_);
      assert::are_equal(0.24, location, csf_);
    }
    
    void test_method_(compare_exchange_double_if_comparand_different) {
      double location = 0.42;
      assert::are_equal(0.42, interlocked::compare_exchange(location, 0.24, 0.33), csf_);
      assert::are_equal(0.42, location, csf_);
    }
    
    void test_method_(compare_exchange_int32_if_comparand_equal) {
      int32 location = 42;
      assert::are_equal(42, interlocked::compare_exchange(location, 24, 42), csf_);
      assert::are_equal(24, location, csf_);
    }
    
    void test_method_(compare_exchange_int32_if_comparand_different) {
      int32 location = 42;
      assert::are_equal(42, interlocked::compare_exchange(location, 24, 33));
      assert::are_equal(42, location);
    }
    
    void test_method_(compare_exchange_int64_if_comparand_equal) {
      int64 location = 42;
      assert::are_equal(42, interlocked::compare_exchange(location, 24, 42), csf_);
      assert::are_equal(24, location, csf_);
    }
    
    void test_method_(compare_exchange_int64_if_comparand_different) {
      int64 location = 42;
      assert::are_equal(42, interlocked::compare_exchange(location, 24, 33), csf_);
      assert::are_equal(42, location, csf_);
    }
    
    void test_method_(compare_exchange_intptr_if_comparand_equal) {
      intptr location = 42;
      assert::are_equal(42, interlocked::compare_exchange(location, 24, 42), csf_);
      assert::are_equal(24, location, csf_);
    }
    
    void test_method_(compare_exchange_intptr_if_comparand_different) {
      intptr location = 42;
      assert::are_equal(42, interlocked::compare_exchange(location, 24, 33), csf_);
      assert::are_equal(42, location, csf_);
    }
    
    void test_method_(compare_exchange_void_pointer_if_comparand_equal) {
      int a = 1;
      int b = 2;
      void* location = &a;
      assert::are_equal(&a, interlocked::compare_exchange(location, &b, &a), csf_);
      assert::are_equal(&b, location, csf_);
    }
    
    void test_method_(compare_exchange_void_pointer_if_comparand_different) {
      int a = 1;
      int b = 2;
      void* location = &a;
      assert::are_equal(&a, interlocked::compare_exchange(location, &b, &b), csf_);
      assert::are_equal(&a, location, csf_);
    }
    
    void test_method_(compare_exchange_single_if_comparand_equal) {
      float location = 0.42f;
      assert::are_equal(0.42f, interlocked::compare_exchange(location, 0.24f, 0.42f), csf_);
      assert::are_equal(0.24f, location, csf_);
    }
    
    void test_method_(compare_exchange_single_if_comparand_different) {
      float location = 0.42f;
      assert::are_equal(0.42f, interlocked::compare_exchange(location, 0.24f, 0.33f), csf_);
      assert::are_equal(0.42f, location, csf_);
    }
    
    void test_method_(compare_exchange_ustring_if_comparand_equal) {
      ustring location = "str1";
      assert::are_equal("str1", interlocked::compare_exchange(location, "str2"_s, "str1"_s), csf_);
      assert::are_equal("str2", location, csf_);
    }
    
    void test_method_(compare_exchange_ustring_if_comparand_different) {
      ustring location = "str1";
      assert::are_equal("str1", interlocked::compare_exchange(location, "str2"_s, "str"_s), csf_);
      assert::are_equal("str1", location, csf_);
    }
    
    void test_method_(decrement_int32) {
      int32 location = 42;
      assert::are_equal(41, interlocked::decrement(location), csf_);
      assert::are_equal(41, location, csf_);
    }
    
    void test_method_(decrement_int64) {
      int64 location = 42;
      assert::are_equal(41, interlocked::decrement(location), csf_);
      assert::are_equal(41, location, csf_);
    }
    
    void test_method_(exchange_double) {
      double location = 0.42;
      assert::are_equal(0.42, interlocked::exchange(location, 0.24), csf_);
      assert::are_equal(0.24, location, csf_);
    }
    
    void test_method_(exchange_int32) {
      int32 location = 42;
      assert::are_equal(42, interlocked::exchange(location, 24), csf_);
      assert::are_equal(24, location, csf_);
    }
    
    void test_method_(exchange_int64) {
      int64 location = 42;
      assert::are_equal(42, interlocked::exchange(location, 24), csf_);
      assert::are_equal(24, location, csf_);
    }
    
    void test_method_(exchange_intptr) {
      intptr location = 42;
      assert::are_equal(42, interlocked::exchange(location, 24), csf_);
      assert::are_equal(24, location, csf_);
    }
    
    void test_method_(exchange_void_pointer) {
      int a = 1;
      int b = 2;
      void* location = &a;
      assert::are_equal(&a, interlocked::exchange(location, &b), csf_);
      assert::are_equal(&b, location, csf_);
    }
    
    void test_method_(exchangeSingle) {
      float location = 0.42f;
      assert::are_equal(0.42f, interlocked::exchange(location, 0.24f), csf_);
      assert::are_equal(0.24f, location, csf_);
    }
    
    void test_method_(exchange_ustring) {
      ustring location = "str1";
      assert::are_equal("str1", interlocked::exchange(location, "str2"_s), csf_);
      assert::are_equal("str2", location, csf_);
    }
    
    void test_method_(increment_int32) {
      int32 location = 42;
      assert::are_equal(43, interlocked::increment(location), csf_);
      assert::are_equal(43, location, csf_);
    }
    
    void test_method_(increment_int64) {
      int64 location = 42;
      assert::are_equal(43, interlocked::increment(location), csf_);
      assert::are_equal(43, location, csf_);
    }
  };
}
