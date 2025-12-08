#include <xtd/io/binary_reader>
#include <xtd/io/memory_stream>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/bit_converter>
#include <xtd/byte_object>
#include <xtd/date_time>
#include <xtd/double_object>
#include <xtd/int16_object>
#include <xtd/int32_object>
#include <xtd/int64_object>
#include <xtd/sbyte_object>
#include <xtd/single_object>
#include <xtd/time_span>
#include <xtd/uint16_object>
#include <xtd/uint32_object>
#include <xtd/uint64_object>
#include <sstream>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(binary_reader_tests) {
    /*
    struct memory_stream : std::stringstream {
      memory_stream() : std::stringstream {std::ios_base::in | std::ios_base::out | std::ios_base::binary} {}
    
      using std::stringstream::write;
      void write(const array<byte>& bytes) {write(bytes, 0_z, bytes.length());}
      void write(const array<byte>& bytes, size offset, size count) {write(reinterpret_cast<const char*>(bytes.data() + offset), count);}
    };*/
    
    auto test_method_(read_boolean) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(true));
      stream.write(bit_converter::get_bytes(false));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::is_true(reader.read_boolean());
      assert::is_false(reader.read_boolean());
    }
    
    auto test_method_(read_byte) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(byte_object::min_value));
      stream.write(bit_converter::get_bytes(42_u8));
      stream.write(bit_converter::get_bytes(byte_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(byte_object::min_value, reader.read_byte());
      assert::are_equal(42_u8, reader.read_byte());
      assert::are_equal(byte_object::max_value, reader.read_byte());
    }
    
    auto test_method_(read_date_time) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(date_time::min_value.to_binary()));
      stream.write(bit_converter::get_bytes(date_time {1971, 1, 5, 23, 1, 42}.to_binary()));
      stream.write(bit_converter::get_bytes(date_time::max_value.to_binary()));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(date_time::min_value, date_time::from_binary(reader.read_int64()));
      assert::are_equal(date_time {1971, 1, 5, 23, 1, 42}, date_time::from_binary(reader.read_int64()));
      assert::are_equal(date_time::max_value, date_time::from_binary(reader.read_int64()));
    }
    
    auto test_method_(read_double) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(double_object::min_value));
      stream.write(bit_converter::get_bytes(0.42));
      stream.write(bit_converter::get_bytes(double_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(double_object::min_value, reader.read_double());
      assert::are_equal(0.42, reader.read_double());
      assert::are_equal(double_object::max_value, reader.read_double());
    }
    
    auto test_method_(read_int16) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(int16_object::min_value));
      stream.write(bit_converter::get_bytes(42_s16));
      stream.write(bit_converter::get_bytes(int16_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(int16_object::min_value, reader.read_int16());
      assert::are_equal(42_s16, reader.read_int16());
      assert::are_equal(int16_object::max_value, reader.read_int16());
    }
    
    auto test_method_(read_int32) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(int32_object::min_value));
      stream.write(bit_converter::get_bytes(42_s32));
      stream.write(bit_converter::get_bytes(int32_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(int32_object::min_value, reader.read_int32());
      assert::are_equal(42_s32, reader.read_int32());
      assert::are_equal(int32_object::max_value, reader.read_int32());
    }
    
    auto test_method_(read_int64) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(int64_object::min_value));
      stream.write(bit_converter::get_bytes(42_s64));
      stream.write(bit_converter::get_bytes(int64_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(int64_object::min_value, reader.read_int64());
      assert::are_equal(42_s64, reader.read_int64());
      assert::are_equal(int64_object::max_value, reader.read_int64());
    }
    
    auto test_method_(read_sbyte) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(sbyte_object::min_value));
      stream.write(bit_converter::get_bytes(42_s8));
      stream.write(bit_converter::get_bytes(sbyte_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(sbyte_object::min_value, reader.read_sbyte());
      assert::are_equal(42_s8, reader.read_sbyte());
      assert::are_equal(sbyte_object::max_value, reader.read_sbyte());
    }
    
    auto test_method_(read_single) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(single_object::min_value));
      stream.write(bit_converter::get_bytes(0.42f));
      stream.write(bit_converter::get_bytes(single_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(single_object::min_value, reader.read_single());
      assert::are_equal(0.42f, reader.read_single());
      assert::are_equal(single_object::max_value, reader.read_single());
    }
    
    auto test_method_(read_size) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(size_object::min_value));
      stream.write(bit_converter::get_bytes(42_z));
      stream.write(bit_converter::get_bytes(size_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(size_object::min_value, reader.read_size());
      assert::are_equal(42_z, reader.read_size());
      assert::are_equal(size_object::max_value, reader.read_size());
    }
    
    auto test_method_(read_time_span) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(time_span::min_value.ticks()));
      stream.write(bit_converter::get_bytes(time_span {2, 18, 25, 36, 450, 200}.ticks()));
      stream.write(bit_converter::get_bytes(time_span::max_value.ticks()));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(time_span::min_value, time_span {reader.read_int64()});
      assert::are_equal(time_span {2, 18, 25, 36, 450, 200}, time_span {reader.read_int64()});
      assert::are_equal(time_span::max_value, time_span {reader.read_int64()});
    }
    
    auto test_method_(read_uint16) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(uint16_object::min_value));
      stream.write(bit_converter::get_bytes(42_u16));
      stream.write(bit_converter::get_bytes(uint16_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(uint16_object::min_value, reader.read_uint16());
      assert::are_equal(42_u16, reader.read_uint16());
      assert::are_equal(uint16_object::max_value, reader.read_uint16());
    }
    
    auto test_method_(read_uint32) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(uint32_object::min_value));
      stream.write(bit_converter::get_bytes(42_u32));
      stream.write(bit_converter::get_bytes(uint32_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(uint32_object::min_value, reader.read_uint32());
      assert::are_equal(42_u32, reader.read_uint32());
      assert::are_equal(uint32_object::max_value, reader.read_uint32());
    }
    
    auto test_method_(read_uint64) {
      auto stream = memory_stream {};
      stream.write(bit_converter::get_bytes(uint64_object::min_value));
      stream.write(bit_converter::get_bytes(42_u64));
      stream.write(bit_converter::get_bytes(uint64_object::max_value));
      
      stream.position(0);
      auto reader = binary_reader {stream};
      assert::are_equal(uint64_object::min_value, reader.read_uint64());
      assert::are_equal(42_u64, reader.read_uint64());
      assert::are_equal(uint64_object::max_value, reader.read_uint64());
    }
  };
}
