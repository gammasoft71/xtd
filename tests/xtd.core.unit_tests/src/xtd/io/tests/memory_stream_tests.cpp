#include <xtd/io/memory_stream>
#include <xtd/not_implemented_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(memory_stream_tests) {
    void test_method_(create_memory_stream) {
      auto stream = memory_stream {};
      assert::is_true(stream.can_read());
      assert::is_true(stream.can_seek());
      assert::is_true(stream.can_write());
      assert::is_zero(stream.capacity());
      assert::is_zero(stream.length());
      assert::is_zero(stream.position());
    }

    void test_method_(create_memory_stream_with_capacity) {
      assert::throws<not_implemented_exception>([] {auto stream = memory_stream {42_z};});
    }
    
  };
}
