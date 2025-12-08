#include <xtd/cpp_language>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(cpp_language_tests) {
    static constexpr int32 cpp20 = 202002l;
    static constexpr int32 cpp17 = 201703l;
    static constexpr int32 cpp14 = 201402l;
    static constexpr int32 cpp11 = 201103l;
    static constexpr int32 cpp98 = 199711l;
    static constexpr int32 cpp_pre98 = 1l;
    static constexpr int32 cpp_unknown = 0;
    static constexpr int32 cpp20_experimental = 201707l;
    
    auto test_method_(default_ctor) {
      cpp_language cl;
      
      assert::is_false(cl.is_experimental_language());
      assert::is_false(cl.is_supported());
      assert::are_equal(language_id::unknown, cl.language());
      assert::are_equal(language_id::unknown, cl.experimental_language());
      assert::is_zero(cl.month());
      assert::are_equal("<unknown>", cl.name());
      assert::is_zero(cl.value());
      assert::are_equal(version {}, cl.version());
      assert::are_equal("<unknown> 0.0", cl.version_string());
      assert::is_zero(cl.year());
      assert::are_equal("<unknown> 0.0", cl.to_string());
    }
    
    auto test_method_(ctor_witth_cpp20) {
      cpp_language cl {cpp20};
      
      assert::is_false(cl.is_experimental_language());
      assert::is_true(cl.is_supported());
      assert::are_equal(language_id::cpp20, cl.language());
      assert::are_equal(language_id::cpp20, cl.experimental_language());
      assert::are_equal(2, cl.month());
      assert::are_equal("C++ 20", cl.name());
      assert::are_equal(202002ul, cl.value());
      assert::are_equal(version {2020, 2}, cl.version());
      assert::are_equal("C++ 20 2020.2", cl.version_string());
      assert::are_equal(2020, cl.year());
      assert::are_equal("C++ 20 2020.2", cl.to_string());
    }
    
    auto test_method_(ctor_witth_cpp17) {
      cpp_language cl {cpp17};
      
      assert::is_false(cl.is_experimental_language());
      assert::is_true(cl.is_supported());
      assert::are_equal(language_id::cpp17, cl.language());
      assert::are_equal(language_id::cpp17, cl.experimental_language());
      assert::are_equal(3, cl.month());
      assert::are_equal("C++ 17", cl.name());
      assert::are_equal(201703ul, cl.value());
      assert::are_equal(version {2017, 3}, cl.version());
      assert::are_equal("C++ 17 2017.3", cl.version_string());
      assert::are_equal(2017, cl.year());
      assert::are_equal("C++ 17 2017.3", cl.to_string());
    }
    
    auto test_method_(ctor_witth_cpp14) {
      cpp_language cl {cpp14};
      
      assert::is_false(cl.is_experimental_language());
      assert::is_false(cl.is_supported());
      assert::are_equal(language_id::cpp14, cl.language());
      assert::are_equal(language_id::cpp14, cl.experimental_language());
      assert::are_equal(2, cl.month());
      assert::are_equal("C++ 14", cl.name());
      assert::are_equal(201402ul, cl.value());
      assert::are_equal(version {2014, 2}, cl.version());
      assert::are_equal("C++ 14 2014.2", cl.version_string());
      assert::are_equal(2014, cl.year());
      assert::are_equal("C++ 14 2014.2", cl.to_string());
    }
    
    auto test_method_(ctor_witth_cpp11) {
      cpp_language cl {cpp11};
      
      assert::is_false(cl.is_experimental_language());
      assert::is_false(cl.is_supported());
      assert::are_equal(language_id::cpp11, cl.language());
      assert::are_equal(language_id::cpp11, cl.experimental_language());
      assert::are_equal(3, cl.month());
      assert::are_equal("C++ 11", cl.name());
      assert::are_equal(201103ul, cl.value());
      assert::are_equal(version {2011, 3}, cl.version());
      assert::are_equal("C++ 11 2011.3", cl.version_string());
      assert::are_equal(2011, cl.year());
      assert::are_equal("C++ 11 2011.3", cl.to_string());
    }
    
    auto test_method_(ctor_witth_cpp98) {
      cpp_language cl {cpp98};
      
      assert::is_false(cl.is_experimental_language());
      assert::is_false(cl.is_supported());
      assert::are_equal(language_id::cpp98, cl.language());
      assert::are_equal(language_id::cpp98, cl.experimental_language());
      assert::are_equal(11, cl.month());
      assert::are_equal("C++ 98", cl.name());
      assert::are_equal(199711ul, cl.value());
      assert::are_equal(version {1997, 11}, cl.version());
      assert::are_equal("C++ 98 1997.11", cl.version_string());
      assert::are_equal(1997, cl.year());
      assert::are_equal("C++ 98 1997.11", cl.to_string());
    }
    
    auto test_method_(ctor_witth_cpp_pre98) {
      cpp_language cl {cpp_pre98};
      
      assert::is_false(cl.is_experimental_language());
      assert::is_false(cl.is_supported());
      assert::are_equal(language_id::cpp_pre98, cl.language());
      assert::are_equal(language_id::cpp_pre98, cl.experimental_language());
      assert::are_equal(1, cl.month());
      assert::are_equal("C++ Pre 98", cl.name());
      assert::are_equal(1ul, cl.value());
      assert::are_equal(version {0, 1}, cl.version());
      assert::are_equal("C++ Pre 98 0.1", cl.version_string());
      assert::is_zero(cl.year());
      assert::are_equal("C++ Pre 98 0.1", cl.to_string());
    }
    
    auto test_method_(ctor_with_cpp_unknown) {
      cpp_language cl {cpp_unknown};
      
      assert::is_false(cl.is_experimental_language());
      assert::is_false(cl.is_supported());
      assert::are_equal(language_id::unknown, cl.language());
      assert::are_equal(language_id::unknown, cl.experimental_language());
      assert::is_zero(cl.month());
      assert::are_equal("<unknown>", cl.name());
      assert::is_zero(cl.value());
      assert::are_equal(version {}, cl.version());
      assert::are_equal("<unknown> 0.0", cl.version_string());
      assert::is_zero(cl.year());
      assert::are_equal("<unknown> 0.0", cl.to_string());
    }
    
    auto test_method_(ctor_with_cpp20_experimental) {
      cpp_language cl {cpp20_experimental};
      
      assert::is_true(cl.is_experimental_language());
      assert::is_true(cl.is_supported());
      assert::are_equal(language_id::cpp17, cl.language());
      assert::are_equal(language_id::cpp20, cl.experimental_language());
      assert::are_equal(7, cl.month());
      assert::are_equal("Experimental C++ 20", cl.name());
      assert::are_equal(201707ul, cl.value());
      assert::are_equal(version {2017, 7}, cl.version());
      assert::are_equal("Experimental C++ 20 2017.7", cl.version_string());
      assert::are_equal(2017, cl.year());
      assert::are_equal("Experimental C++ 20 2017.7", cl.to_string());
    }
  };
}
