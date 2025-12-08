#include <xtd/io/memory_stream>
#include <xtd/not_implemented_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(memory_stream_tests) {
    auto test_method_(create_memory_stream) {
      auto stream = memory_stream {};
      assert::are_equal("xtd::io::memory_stream", stream.to_string());
      assert::is_zero(stream.capacity());
      assert::is_zero(stream.length());
      assert::is_zero(stream.position());
    }
    
    auto test_method_(create_memory_stream_with_capacity) {
      auto stream = memory_stream {42_z};
      assert::are_equal("xtd::io::memory_stream", stream.to_string());
      assert::are_equal(42_z, stream.capacity());
      assert::is_zero(stream.length());
      assert::is_zero(stream.position());
    }
    
    auto test_method_(can_read) {
      auto stream = memory_stream {};
      assert::is_true(stream.can_read());
    }
    
    auto test_method_(can_seek) {
      auto stream = memory_stream {};
      assert::is_true(stream.can_seek());
    }
    
    auto test_method_(can_write) {
      auto stream = memory_stream {};
      assert::is_true(stream.can_write());
    }
    
    auto test_method_(capacity) {
      auto stream = memory_stream {};
      assert::is_zero(stream.capacity());
      stream.write_byte(42);
      assert::is_greater_or_equal(stream.capacity(), 1_z);
    }
    
    auto test_method_(set_capacity) {
      auto stream = memory_stream {};
      assert::is_zero(stream.capacity());
      stream.capacity(42_z);
      assert::are_equal(42_z, stream.capacity());
      assert::is_zero(stream.length());
      assert::is_zero(stream.position());
    }
    
    auto test_method_(length) {
      auto stream = memory_stream {};
      assert::is_zero(stream.length());
      stream.write_byte(42);
      assert::are_equal(1_z, stream.length());
      stream.position(0);
      assert::are_equal(42, stream.read_byte());
    }
    
    auto test_method_(position) {
      auto stream = memory_stream {};
      assert::is_zero(stream.position());
      stream.write_byte(10);
      assert::are_equal(1_z, stream.position());
      stream.write_byte(20);
      assert::are_equal(2_z, stream.position());
      stream.write_byte(30);
      assert::are_equal(3_z, stream.position());
      stream.write_byte(40);
      assert::are_equal(4_z, stream.position());
      stream.write_byte(50);
      assert::are_equal(5_z, stream.position());
    }
    
    auto test_method_(set_position) {
      auto stream = memory_stream {};
      assert::is_zero(stream.position());
      stream.write(array<byte> {10, 20, 30, 40, 50});
      assert::are_equal(5_z, stream.position());
      stream.position(0);
      assert::is_zero(stream.position());
      stream.position(3);
      assert::are_equal(3_z, stream.position());
    }
    
    auto test_method_(copy_to) {
      auto stream1 = memory_stream {};
      stream1.write(array<byte> {10, 20, 30, 40, 50});
      
      auto stream2 = memory_stream {};
      stream1.position(0);
      stream1.copy_to(stream2);
      stream2.position(0);
      assert::are_equal(10, stream2.read_byte());
      assert::are_equal(20, stream2.read_byte());
      assert::are_equal(30, stream2.read_byte());
      assert::are_equal(40, stream2.read_byte());
      assert::are_equal(50, stream2.read_byte());
      assert::are_equal(stream::eof, stream2.read_byte());
      
    }
    auto test_method_(copy_to_with_buffer_size) {
      auto stream1 = memory_stream {};
      stream1.write(array<byte> {10, 20, 30, 40, 50});
      
      auto stream2 = memory_stream {};
      stream1.position(1);
      stream1.copy_to(stream2, 3);
      stream2.position(0);
      assert::are_equal(20, stream2.read_byte());
      assert::are_equal(30, stream2.read_byte());
      assert::are_equal(40, stream2.read_byte());
      assert::are_equal(stream::eof, stream2.read_byte());
    }
    
    auto test_method_(to_array) {
      auto stream1 = memory_stream {};
      stream1.write(array<byte> {10, 20, 30, 40, 50});
      stream1.position(0);
      collection_assert::are_equal({10, 20, 30, 40, 50}, stream1.to_array());
    }
  };
}
