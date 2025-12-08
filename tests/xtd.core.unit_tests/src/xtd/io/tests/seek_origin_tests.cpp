#include <xtd/io/seek_origin>
#include <xtd/as>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(seek_origin_tests) {
    auto test_method_(begin) {
      assert::are_equal(0, enum_object<>::to_int32(seek_origin::begin));
      assert::are_equal("begin", enum_object<>::to_string(seek_origin::begin));
      assert::are_equal(seek_origin::begin, enum_object<>::parse<seek_origin>("begin"));
    }
    
    auto test_method_(current) {
      assert::are_equal(1, enum_object<>::to_int32(seek_origin::current));
      assert::are_equal("current", enum_object<>::to_string(seek_origin::current));
      assert::are_equal(seek_origin::current, enum_object<>::parse<seek_origin>("current"));
    }
    
    auto test_method_(end) {
      assert::are_equal(2, enum_object<>::to_int32(seek_origin::end));
      assert::are_equal("end", enum_object<>::to_string(seek_origin::end));
      assert::are_equal(seek_origin::end, enum_object<>::parse<seek_origin>("end"));
    }
    
    auto test_method_(as_std_ios_base) {
      assert::are_equal(std::ios_base::beg, as<std::ios_base::seekdir>(seek_origin::begin));
      assert::are_equal(std::ios_base::cur, as<std::ios_base::seekdir>(seek_origin::current));
      assert::are_equal(std::ios_base::end, as<std::ios_base::seekdir>(seek_origin::end));
    }
  };
}

