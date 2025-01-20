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
    void test_method_(memory_buffer) {
      assert::are_equal(typeof_<std::stringbuf>(), typeof_<memory_stream::memory_buffer>());
    }
    
    void test_method_(create_memory_stream) {
      auto stream = memory_stream {};
      assert::are_equal("xtd::io::memory_stream", stream.to_string());
      assert::is_zero(stream.capacity());
      assert::is_zero(stream.length());
      assert::is_zero(stream.position());
    }

    void test_method_(create_memory_stream_with_capacity) {
      assert::throws<not_implemented_exception>([] {auto stream = memory_stream {42_z};});
    }
    
    void test_method_(can_read) {
      auto stream = memory_stream {};
      assert::is_true(stream.can_read());
    }
    
    void test_method_(can_seek) {
      auto stream = memory_stream {};
      assert::is_true(stream.can_seek());
    }
    
    void test_method_(can_write) {
      auto stream = memory_stream {};
      assert::is_true(stream.can_write());
    }

    void test_method_(capacity) {
      auto stream = memory_stream {};
      assert::is_zero(stream.capacity());
      stream.write_byte(42);
      assert::is_greater_or_equal(stream.capacity(), 1_z);
    }
    
    void test_method_(set_capacity) {
      assert::throws<not_implemented_exception>([] {memory_stream {}.capacity(42_z);});
    }
    
    void test_method_(length) {
      auto stream = memory_stream {};
      assert::is_zero(stream.length());
      stream.write_byte(42);
      assert::are_equal(1_z, stream.length());
    }

    void test_method_(position) {
      auto stream = memory_stream {};
      assert::is_zero(stream.position());
      stream.write_byte(42);
      assert::are_equal(1_z, stream.position());
    }

  };
}
