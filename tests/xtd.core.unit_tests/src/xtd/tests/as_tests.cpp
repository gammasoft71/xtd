#include <xtd/as>
#include <xtd/is>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(as_tests) {
  public:
    void test_method_(bool_as_int) {
      assert::is_true(is<int>(as<int>((bool)true)), csf_);
    }
    
    void test_method_(literal_bool_as_int) {
      assert::is_true(is<int>(as<int>(true)), csf_);
    }
    
    void test_method_(char_as_int) {
      assert::is_true(is<int>(as<int>((char)'a')), csf_);
    }
    
#if defined(__cpp_lib_char8_t)
    void test_method_(char8_as_int) {
      assert::is_true(is<int>(as<int>((char8)'a')), csf_);
    }
#endif
    
    void test_method_(char16_as_int) {
      assert::is_true(is<int>(as<int>((char16)'a')), csf_);
    }
    
    void test_method_(char32_as_int) {
      assert::is_true(is<int>(as<int>((char32)'a')), csf_);
    }
    
    void test_method_(wchar_as_int) {
      assert::is_true(is<int>(as<int>((wchar)'a')), csf_);
    }
    
    void test_method_(unsigned_char_as_int) {
      assert::is_true(is<int>(as<int>((unsigned char)'a')), csf_);
    }
    
    void test_method_(literal_char_as_int) {
      assert::is_true(is<int>(as<int>('a')), csf_);
    }
    
    void test_method_(literal_char8_as_int) {
      assert::is_true(is<int>(as<int>(u8'a')), csf_);
    }
    
    void test_method_(literal_char16_as_int) {
      assert::is_true(is<int>(as<int>(u'a')), csf_);
    }
    
    void test_method_(literal_char32_as_int) {
      assert::is_true(is<int>(as<int>(U'a')), csf_);
    }
    
    void test_method_(literal_wchar_as_int) {
      assert::is_true(is<int>(as<int>(L'a')), csf_);
    }
    
    void test_method_(short_as_double) {
      assert::is_true(is<double>(as<double>((short)42)), csf_);
    }
    
    void test_method_(int_as_double) {
      assert::is_true(is<double>(as<double>((int)42)), csf_);
    }
    
    void test_method_(long_as_double) {
      assert::is_true(is<double>(as<double>((long)42)), csf_);
    }
    
    void test_method_(long_long_as_double) {
      assert::is_true(is<double>(as<double>((long long)42)));
    }
    
    void test_method_(long_long_int_as_double) {
      assert::is_true(is<double>(as<double>((long long int)42)), csf_);
    }
    
    void test_method_(int8_as_double) {
      assert::is_true(is<double>(as<double>((sbyte)42)), csf_);
    }
    
    void test_method_(int16_as_double) {
      assert::is_true(is<double>(as<double>((int16)42)), csf_);
    }
    
    void test_method_(int32_as_double) {
      assert::is_true(is<double>(as<double>((int32)42)), csf_);
    }
    
    void test_method_(int64_as_double) {
      assert::is_true(is<double>(as<double>((int64)42)), csf_);
    }
    
    void test_method_(llong_as_double) {
      assert::is_true(is<double>(as<double>((slong)42)), csf_);
    }
    
    void test_method_(literal_int_as_double) {
      assert::is_true(is<double>(as<double>(42)), csf_);
    }
    
    void test_method_(literal_long_as_double) {
      assert::is_true(is<double>(as<double>(42l)), csf_);
    }
    
    void test_method_(literal_long_llong_as_double) {
      assert::is_true(is<double>(as<double>(42ll)), csf_);
    }
    
    void test_method_(unsigned_short_as_double) {
      assert::is_true(is<double>(as<double>((unsigned short)42)), csf_);
    }
    
    void test_method_(unsigned_int_as_double) {
      assert::is_true(is<double>(as<double>((unsigned int)42)), csf_);
    }
    
    void test_method_(unsigned_long_as_double) {
      assert::is_true(is<double>(as<double>((unsigned long)42)), csf_);
    }
    
    void test_method_(unsigned_long_long_as_double) {
      assert::is_true(is<double>(as<double>((unsigned long long)42)), csf_);
    }
    
    void test_method_(unsigned_long_long_int_as_double) {
      assert::is_true(is<double>(as<double>((unsigned long long int)42)), csf_);
    }
    
    void test_method_(unsigned_as_double) {
      assert::is_true(is<double>(as<double>((unsigned)42)), csf_);
    }
    
    void test_method_(uint8_as_double) {
      assert::is_true(is<double>(as<double>((xtd::byte)42)), csf_);
    }
    
    void test_method_(uint16_as_double) {
      assert::is_true(is<double>(as<double>((uint16)42)), csf_);
    }
    
    void test_method_(uint32_as_double) {
      assert::is_true(is<double>(as<double>((uint32)42)), csf_);
    }
    
    void test_method_(uint64_as_double) {
      assert::is_true(is<double>(as<double>((uint64)42)), csf_);
    }
    
    void test_method_(ullong_as_double) {
      assert::is_true(is<double>(as<double>((xtd::ulong)42)), csf_);
    }
    
    void test_method_(literal_unsigned_int_as_double) {
      assert::is_true(is<double>(as<double>(42u)), csf_);
    }
    
    void test_method_(literal_unsigned_long_as_double) {
      assert::is_true(is<double>(as<double>(42ul)), csf_);
    }
    
    void test_method_(literal_unsigned_long_llong_as_double) {
      assert::is_true(is<double>(as<double>(42ull)), csf_);
    }
    
    void test_method_(size_t_as_int) {
      assert::is_true(is<int>(as<int>((size_t)42)), csf_);
    }
    
    void test_method_(intptr_as_int) {
      assert::is_true(is<int>(as<int>((intptr)42)), csf_);
    }
    
    void test_method_(uintptr_as_int) {
      assert::is_true(is<int>(as<int>((uintptr)42)), csf_);
    }
    
    void test_method_(float_as_int) {
      assert::is_true(is<int>(as<int>((float)42.f)), csf_);
    }
    
    void test_method_(double_as_int) {
      assert::is_true(is<int>(as<int>((double)42.)), csf_);
    }
    
    void test_method_(decimal_as_int) {
      assert::is_true(is<int>(as<int>((decimal)42.)), csf_);
    }
    
    void test_method_(long_double_as_int) {
      assert::is_true(is<int>(as<int>((long double)42.)), csf_);
    }
    
    void test_method_(literal_float_as_int) {
      assert::is_true(is<int>(as<int>(42.f)), csf_);
    }
    
    void test_method_(literal_double_as_int) {
      assert::is_true(is<int>(as<int>(42.)), csf_);
    }
    
    void test_method_(literal_decimal_as_int) {
      assert::is_true(is<int>(as<int>(42.l)), csf_);
    }
    
    void test_method_(ref_as_base) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      
      derived o;
      derived& d = o;
      assert::is_true(is<base>(as<base>(d)), csf_);
    }
    
    void test_method_(ref_as_other) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      struct other {virtual ~other() = default;};
      
      derived o;
      derived& d = o;
      assert::throws<invalid_cast_exception>([&] {as<other>(d);}, csf_);
    }
    
    void test_method_(const_ref_as_base) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      
      derived o;
      const derived& d = o;
      assert::is_true(is<base>(as<base>(d)), csf_);
    }
    
    void test_method_(const_ref_as_other) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      struct other {virtual ~other() = default;};
      
      derived o;
      const derived& d = o;
      assert::throws<invalid_cast_exception>([&] {as<other>(d);}, csf_);
    }
    
    void test_method_(ptr_as_base) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      
      derived o;
      derived* d = &o;
      assert::is_true(is<base>(as<base>(d)), csf_);
    }
    
    void test_method_(ptr_as_other) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      struct other {virtual ~other() = default;};
      
      derived o;
      derived* d = &o;
      assert::throws<invalid_cast_exception>([&] {as<other>(d);}, csf_);
    }
    
    void test_method_(const_ptr_as_base) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      
      derived o;
      const derived* d = &o;
      assert::is_true(is<base>(as<base>(d)), csf_);
    }
    
    void test_method_(const_ptr_as_other) {
      struct base {virtual ~base() = default;};
      struct derived : public base {};
      struct other {virtual ~other() = default;};
      
      derived o;
      const derived* d = &o;
      assert::throws<invalid_cast_exception>([&] {as<other>(d);}, csf_);
    }
    
  };
}

/*
  console::write_line(as<int>(any(42)));
  console::write_line(as<string>(any("String"s)));
*/
