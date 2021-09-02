#include <xtd/xtd.core>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_as) {
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
    
    void test_method_(char8_t_as_int) {
      assert::is_true(is<int>(as<int>((char8_t)'a')), csf_);
    }
    
    void test_method_(char16_t_as_int) {
      assert::is_true(is<int>(as<int>((char16_t)'a')), csf_);
    }
    
    void test_method_(char32_t_as_int) {
      assert::is_true(is<int>(as<int>((char32_t)'a')), csf_);
    }
    
    void test_method_(wchar_t_as_int) {
      assert::is_true(is<int>(as<int>((wchar_t)'a')), csf_);
    }

    void test_method_(unsigned_char_as_int) {
      assert::is_true(is<int>(as<int>((unsigned char)'a')), csf_);
    }

    void test_method_(literal_char_as_int) {
      assert::is_true(is<int>(as<int>('a')), csf_);
    }
    
    void test_method_(literal_char8_t_as_int) {
      assert::is_true(is<int>(as<int>(u8'a')), csf_);
    }
    
    void test_method_(literal_char16_t_as_int) {
      assert::is_true(is<int>(as<int>(u'a'))), csf_;
    }
    
    void test_method_(literal_char32_t_as_int) {
      assert::is_true(is<int>(as<int>(U'a')), csf_);
    }
    
    void test_method_(literal_wchar_t_as_int) {
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

    void test_method_(int8_t_as_double) {
      assert::is_true(is<double>(as<double>((int8_t)42)), csf_);
    }

    void test_method_(int16_t_as_double) {
      assert::is_true(is<double>(as<double>((int16_t)42)), csf_);
    }

    void test_method_(int32_t_as_double) {
      assert::is_true(is<double>(as<double>((int32_t)42)), csf_);
    }

    void test_method_(int64_t_as_double) {
      assert::is_true(is<double>(as<double>((int64_t)42)), csf_);
    }

    void test_method_(llong_t_as_double) {
      assert::is_true(is<double>(as<double>((llong_t)42)), csf_);
    }
    
    void test_method_(literal_int_as_double) {
      assert::is_true(is<double>(as<double>(42)), csf_);
    }
    
    void test_method_(literal_long_as_double) {
      assert::is_true(is<double>(as<double>(42l))), csf_;
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

    void test_method_(uint8_t_as_double) {
      assert::is_true(is<double>(as<double>((uint8_t)42)), csf_);
    }
    
    void test_method_(uint16_t_as_double) {
      assert::is_true(is<double>(as<double>((uint16_t)42)), csf_);
    }
    
    void test_method_(uint32_t_as_double) {
      assert::is_true(is<double>(as<double>((uint32_t)42)), csf_);
    }
    
    void test_method_(uint64_t_as_double) {
      assert::is_true(is<double>(as<double>((uint64_t)42)), csf_);
    }
    
    void test_method_(ullong_t_as_double) {
      assert::is_true(is<double>(as<double>((ullong_t)42)), csf_);
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
    
    void test_method_(intptr_t_as_int) {
      assert::is_true(is<int>(as<int>((intptr_t)42)), csf_);
    }

    void test_method_(uintptr_t_as_int) {
      assert::is_true(is<int>(as<int>((uintptr_t)42)), csf_);
    }

    void test_method_(float_as_int) {
      assert::is_true(is<int>(as<int>((float)42.f)), csf_);
    }

    void test_method_(double_as_int) {
      assert::is_true(is<int>(as<int>((double)42.)), csf_);
    }
    
    void test_method_(decimal_as_int) {
      assert::is_true(is<int>(as<int>((decimal_t)42.)), csf_);
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
      assert::throws<invalid_cast_exception>([&]{as<other>(d);}, csf_);
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
      assert::throws<invalid_cast_exception>([&]{as<other>(d);}, csf_);
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
      assert::throws<invalid_cast_exception>([&]{as<other>(d);}, csf_);
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
      assert::throws<invalid_cast_exception>([&]{as<other>(d);}, csf_);
    }

  };
}

/*
  console::write_line(as<int>(any(42)));
  console::write_line(as<string>(any("String"s)));
*/
