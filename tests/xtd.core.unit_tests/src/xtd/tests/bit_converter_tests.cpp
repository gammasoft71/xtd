#include <cfloat>
#include <cmath>
#include <xtd/bit_converter>
#include <xtd/argument_out_of_range_exception>
#include <xtd/block_scope>
#include "bytes_assert.hpp"
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(bit_converter_tests) {
    void test_method_(get_bytes_boolean) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(false)) {
        bytes_assert::are_equal(0, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(true)) {
        bytes_assert::are_equal(1, bytes);
      }
    }
    
    void test_method_(get_bytes_char) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(' ')) {
        bytes_assert::are_equal(0x20, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes('*')) {
        bytes_assert::are_equal(0x2A, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes('3')) {
        bytes_assert::are_equal(0x33, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes('A')) {
        bytes_assert::are_equal(0x41, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes('[')) {
        bytes_assert::are_equal(0x5B, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes('a')) {
        bytes_assert::are_equal(0x61, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes('{')) {
        bytes_assert::are_equal(0x7B, 0x00, 0x00, 0x00, bytes);
      }
    }
    
    void test_method_(get_bytes_double) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(255.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(4294967295.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0.00390625)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0.00000000023283064365386962890625)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.23456789012345E-300)) {
        bytes_assert::are_equal(0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.2345678901234565)) {
        bytes_assert::are_equal(0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.2345678901234567)) {
        bytes_assert::are_equal(0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.2345678901234569)) {
        bytes_assert::are_equal(0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.23456789012345678E+300)) {
        bytes_assert::are_equal(0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<double>::lowest())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<double>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(DBL_EPSILON)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x3C, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<double>::quiet_NaN())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-std::numeric_limits<double>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<double>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F, bytes);
      }
    }
    
    void test_method_(get_bytes_int16) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<int16>(0))) {
        bytes_assert::are_equal(0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<int16>(15))) {
        bytes_assert::are_equal(0x0F, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<int16>(-15))) {
        bytes_assert::are_equal(0xF1, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<int16>(10000))) {
        bytes_assert::are_equal(0x10, 0x27, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<int16>(-10000))) {
        bytes_assert::are_equal(0xF0, 0xD8, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<int16>::lowest())) {
        bytes_assert::are_equal(0x00, 0x80, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<int16>::max())) {
        bytes_assert::are_equal(0xFF, 0x7F, bytes);
      }
    }
    
    void test_method_(get_bytes_int32) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(15)) {
        bytes_assert::are_equal(0x0F, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-15)) {
        bytes_assert::are_equal(0xF1, 0xFF, 0xFF, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1048576)) {
        bytes_assert::are_equal(0x00, 0x00, 0x10, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-1048576)) {
        bytes_assert::are_equal(0x00, 0x00, 0xF0, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1000000000)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-1000000000)) {
        bytes_assert::are_equal(0x00, 0x36, 0x65, 0xC4, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<int32>::lowest())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x80, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<int32>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0x7F, bytes);
      }
    }
    
    void test_method_(get_bytes_int64) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0xFFFFFFLL)) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1000000000LL)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-1000000000LL)) {
        bytes_assert::are_equal(0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0x100000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-0x100000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0xAAAAAAAAAAAALL)) {
        bytes_assert::are_equal(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-0xAAAAAAAAAAAALL)) {
        bytes_assert::are_equal(0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1000000000000000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-1000000000000000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<int64>::lowest())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<int64>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, bytes);
      }
    }
    
    void test_method_(get_bytes_float) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0.0f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.0f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(15.0f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x70, 0x41, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(65535.0f)) {
        bytes_assert::are_equal(0x00, 0xFF, 0x7F, 0x47, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0.00390625f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x3B, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0.00000000023283064365386962890625f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x2F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.2345E-35f)) {
        bytes_assert::are_equal(0x49, 0x46, 0x83, 0x05, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.2345671f)) {
        bytes_assert::are_equal(0x4B, 0x06, 0x9E, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.2345673f)) {
        bytes_assert::are_equal(0x4D, 0x06, 0x9E, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.2345677f)) {
        bytes_assert::are_equal(0x50, 0x06, 0x9E, 0x3F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1.23456789E+35f)) {
        bytes_assert::are_equal(0x1E, 0x37, 0xBE, 0x79, bytes);
      }
      
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<float>::lowest())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0x7F, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<float>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0x7F, 0x7F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(FLT_EPSILON)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x34, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<float>::quiet_NaN())) {
        bytes_assert::are_equal(0x00, 0x00, 0xC0, 0x7F, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(-std::numeric_limits<float>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0xFF, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<float>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x7F, bytes);
      }
    }
    
    void test_method_(get_bytes_uint16_t) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<uint16>(15))) {
        bytes_assert::are_equal(0x0F, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<uint16>(1023))) {
        bytes_assert::are_equal(0xFF, 0x03, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<uint16>(10000))) {
        bytes_assert::are_equal(0x10, 0x27, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(static_cast<uint16>(0))) {
        bytes_assert::are_equal(0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<uint16>::lowest())) {
        bytes_assert::are_equal(0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<uint16>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, bytes);
      }
    }
    
    void test_method_(get_bytes_uint32) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(15u)) {
        bytes_assert::are_equal(0x0F, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1023u)) {
        bytes_assert::are_equal(0xFF, 0x03, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0x100000u)) {
        bytes_assert::are_equal(0x00, 0x00, 0x10, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1000000000u)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<uint32>::lowest())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<uint32>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, bytes);
      }
    }
    
    void test_method_(getBytesUInt64) {
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0xFFFFFFull)) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1000000000ull)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0x100000000ull)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(0xAAAAAAAAAAAAull)) {
        bytes_assert::are_equal(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(1000000000000000000ull)) {
        bytes_assert::are_equal(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(10000000000000000000ull)) {
        bytes_assert::are_equal(0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<uint64>::lowest())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes);
      }
      
      block_scope_(array<xtd::byte> bytes = bit_converter::get_bytes(std::numeric_limits<uint64>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, bytes);
      }
    }
    
    void test_method_(to_boolean) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_boolean(array<byte> {0}, 1);});
      
      assert::is_false(bit_converter::to_boolean(array<byte> {0}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {1}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {2}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {4}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {8}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {16}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {32}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {64}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {128}, 0));
      assert::is_true(bit_converter::to_boolean(array<byte> {255}, 0));
    }
    
    void test_method_(to_char) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_char(array<byte> {0x00, 0x00, 0x00, 0x00}, 4);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_char(array<byte> {0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(U' ', bit_converter::to_char(array<byte> {0x20, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(U'*', bit_converter::to_char(array<byte> {0x2A, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(U'3', bit_converter::to_char(array<byte> {0x33, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(U'A', bit_converter::to_char(array<byte> {0x41, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(U'[', bit_converter::to_char(array<byte> {0x5B, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(U'a', bit_converter::to_char(array<byte> {0x61, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(U'{', bit_converter::to_char(array<byte> {0x7B, 0x00, 0x00, 0x00}, 0));
    }
    
    void test_method_(to_double) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(0.0, bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(1.0, bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F}, 0));
      assert::are_equal(255.0, bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40}, 0));
      assert::are_equal(4294967295.0, bit_converter::to_double(array<byte> {0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41}, 0));
      assert::are_equal(0.00390625, bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F}, 0));
      assert::are_equal(0.00000000023283064365386962890625, bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D}, 0));
      assert::are_equal(1.23456789012345E-300, bit_converter::to_double(array<byte> {0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01}, 0));
      assert::are_equal(1.2345678901234565, bit_converter::to_double(array<byte> {0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
      assert::are_equal(1.2345678901234567, bit_converter::to_double(array<byte> {0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
      assert::are_equal(1.2345678901234569, bit_converter::to_double(array<byte> {0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0));
      assert::are_equal(1.23456789012345678E+300, bit_converter::to_double(array<byte> {0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E}, 0));
      assert::are_equal(std::numeric_limits<double>::lowest(), bit_converter::to_double(array<byte> {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF}, 0));
      assert::are_equal(std::numeric_limits<double>::max(), bit_converter::to_double(array<byte> {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F}, 0));
      assert::are_equal(DBL_EPSILON, bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x3C}, 0));
      assert::is_true(std::isnan(bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F}, 0)));
      assert::are_equal(-std::numeric_limits<double>::infinity(), bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF}, 0));
      assert::are_equal(std::numeric_limits<double>::infinity(), bit_converter::to_double(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F}, 0));
    }
    
    void test_method_(to_int16) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_int16(array<byte> {0x00, 0x00}, 2);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_int16(array<byte> {0x00, 0x00}, 1);});
      
      assert::are_equal(0, bit_converter::to_int16(array<byte> {0x00, 0x00}, 0));
      assert::are_equal(15, bit_converter::to_int16(array<byte> {0x0F, 0x00}, 0));
      assert::are_equal(-15, bit_converter::to_int16(array<byte> {0xF1, 0xFF}, 0));
      assert::are_equal(10000, bit_converter::to_int16(array<byte> {0x10, 0x27}, 0));
      assert::are_equal(-10000, bit_converter::to_int16(array<byte> {0xF0, 0xD8}, 0));
      assert::are_equal(std::numeric_limits<int16>::lowest(), bit_converter::to_int16(array<byte> {0x00, 0x80}, 0));
      assert::are_equal(std::numeric_limits<int16>::max(), bit_converter::to_int16(array<byte> {0xFF, 0x7F}, 0));
    }
    
    void test_method_(to_int32) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_int32(array<byte> {0x00, 0x00, 0x00, 0x00}, 4);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_int32(array<byte> {0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(0, bit_converter::to_int32(array<byte> {0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(15, bit_converter::to_int32(array<byte> {0x0F, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(-15, bit_converter::to_int32(array<byte> {0xF1, 0xFF, 0xFF, 0xFF}, 0));
      assert::are_equal(1048576, bit_converter::to_int32(array<byte> {0x00, 0x00, 0x10, 0x00}, 0));
      assert::are_equal(-1048576, bit_converter::to_int32(array<byte> {0x00, 0x00, 0xF0, 0xFF}, 0));
      assert::are_equal(1000000000, bit_converter::to_int32(array<byte> {0x00, 0xCA, 0x9A, 0x3B}, 0));
      assert::are_equal(-1000000000, bit_converter::to_int32(array<byte> {0x00, 0x36, 0x65, 0xC4}, 0));
      assert::are_equal(std::numeric_limits<int32>::lowest(), bit_converter::to_int32(array<byte> {0x00, 0x00, 0x00, 0x80}, 0));
      assert::are_equal(std::numeric_limits<int32>::max(), bit_converter::to_int32(array<byte> {0xFF, 0xFF, 0xFF, 0x7F}, 0));
    }
    
    void test_method_(to_int64) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_int64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_int64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(0LL, bit_converter::to_int64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(0xFFFFFFLL, bit_converter::to_int64(array<byte> {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(1000000000LL, bit_converter::to_int64(array<byte> {0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(-1000000000LL, bit_converter::to_int64(array<byte> {0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
      assert::are_equal(0x100000000LL, bit_converter::to_int64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(-0x100000000LL, bit_converter::to_int64(array<byte> {0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
      assert::are_equal(0xAAAAAAAAAAAALL, bit_converter::to_int64(array<byte> {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0));
      assert::are_equal(-0xAAAAAAAAAAAALL, bit_converter::to_int64(array<byte> {0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF}, 0));
      assert::are_equal(1000000000000000000LL, bit_converter::to_int64(array<byte> {0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0));
      assert::are_equal(-1000000000000000000LL, bit_converter::to_int64(array<byte> {0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2}, 0));
      assert::are_equal(std::numeric_limits<int64>::lowest(), bit_converter::to_int64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80}, 0));
      assert::are_equal(std::numeric_limits<int64>::max(), bit_converter::to_int64(array<byte> {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}, 0));
    }
    
    void test_method_(to_single) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_single(array<byte> {0x00, 0x00, 0x00, 0x00}, 4);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_single(array<byte> {0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(0.0, bit_converter::to_single(array<byte> {0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(1.0f, bit_converter::to_single(array<byte> {0x00, 0x00, 0x80, 0x3F}, 0));
      assert::are_equal(15.0f, bit_converter::to_single(array<byte> {0x00, 0x00, 0x70, 0x41}, 0));
      assert::are_equal(65535.0f, bit_converter::to_single(array<byte> {0x00, 0xFF, 0x7F, 0x47}, 0));
      assert::are_equal(0.00390625f, bit_converter::to_single(array<byte> {0x00, 0x00, 0x80, 0x3B}, 0));
      assert::are_equal(0.00000000023283064365386962890625f, bit_converter::to_single(array<byte> {0x00, 0x00, 0x80, 0x2F}, 0));
      assert::are_equal(1.2345E-35f, bit_converter::to_single(array<byte> {0x49, 0x46, 0x83, 0x05}, 0));
      assert::are_equal(1.2345671f, bit_converter::to_single(array<byte> {0x4B, 0x06, 0x9E, 0x3F}, 0));
      assert::are_equal(1.2345673f, bit_converter::to_single(array<byte> {0x4D, 0x06, 0x9E, 0x3F}, 0));
      assert::are_equal(1.2345677f, bit_converter::to_single(array<byte> {0x50, 0x06, 0x9E, 0x3F}, 0));
      assert::are_equal(1.23456789E+35f, bit_converter::to_single(array<byte> {0x1E, 0x37, 0xBE, 0x79}, 0));
      assert::are_equal(std::numeric_limits<float>::lowest(), bit_converter::to_single(array<byte> {0xFF, 0xFF, 0x7F, 0xFF}, 0));
      assert::are_equal(std::numeric_limits<float>::max(), bit_converter::to_single(array<byte> {0xFF, 0xFF, 0x7F, 0x7F}, 0));
      assert::are_equal(FLT_EPSILON, bit_converter::to_single(array<byte> {0x00, 0x00, 0x00, 0x34}, 0));
      assert::is_true(std::isnan(bit_converter::to_single(array<byte> {0x00, 0x00, 0xC0, 0x7F}, 0)));
      assert::are_equal(-std::numeric_limits<float>::infinity(), bit_converter::to_single(array<byte> {0x00, 0x00, 0x80, 0xFF}, 0));
      assert::are_equal(std::numeric_limits<float>::infinity(), bit_converter::to_single(array<byte> {0x00, 0x00, 0x80, 0x7F}, 0));
    }
    
    void test_method_(to_string) {
      array<xtd::byte> vectorOne = {0, 1, 2, 4, 8, 16, 32, 64, 128, 255};
      assert::are_equal("00-01-02-04-08-10-20-40-80-FF", bit_converter::to_string(vectorOne));
      
      array<xtd::byte> vectorTwo = {32, 0, 0, 42, 0, 65, 0, 125, 0, 197, 0, 168, 3, 41, 4, 172, 32};
      assert::are_equal("20-00-00-2A-00-41-00-7D-00-C5-00-A8-03-29-04-AC-20", bit_converter::to_string(vectorTwo));
      
      array<xtd::byte> vectorThree = {15, 0, 0, 128, 16, 39, 240, 216, 241, 255, 127};
      assert::are_equal("0F-00-00-80-10-27-F0-D8-F1-FF-7F", bit_converter::to_string(vectorThree));
      
      array<xtd::byte> vectorFour = {15, 0, 0, 0, 0, 16, 0, 255, 3, 0, 0, 202, 154, 59, 255, 255, 255, 255, 127};
      assert::are_equal("0F-00-00-00-00-10-00-FF-03-00-00-CA-9A-3B-FF-FF-FF-FF-7F", bit_converter::to_string(vectorFour));
      
      array<xtd::byte> vectorEmpty;
      assert::is_empty(bit_converter::to_string(vectorEmpty));
    }
    
    void test_method_(to_string_with_start_index) {
      array<xtd::byte> vectorOne = {3, 6, 9};
      assert::are_equal("03-06-09", bit_converter::to_string(vectorOne, 0));
      assert::are_equal("06-09", bit_converter::to_string(vectorOne, 1));
      assert::are_equal("09", bit_converter::to_string(vectorOne, 2));
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 3);});
      
      array<xtd::byte> vectorEmpty;
      assert::is_empty(bit_converter::to_string(vectorEmpty, 0));
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorEmpty, 1);});
    }
    
    void test_method_(to_string_with_start_index_and_length) {
      array<xtd::byte> vectorOne = {3, 6, 9};
      
      assert::is_empty(bit_converter::to_string(vectorOne, 0, 0));
      assert::are_equal("03", bit_converter::to_string(vectorOne, 0, 1));
      assert::are_equal("03-06", bit_converter::to_string(vectorOne, 0, 2));
      assert::are_equal("03-06-09", bit_converter::to_string(vectorOne, 0, 3));
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 0, 4);});
      
      assert::is_empty(bit_converter::to_string(vectorOne, 1, 0));
      assert::are_equal("06", bit_converter::to_string(vectorOne, 1, 1));
      assert::are_equal("06-09", bit_converter::to_string(vectorOne, 1, 2));
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 1, 3);});
      
      assert::is_empty(bit_converter::to_string(vectorOne, 2, 0));
      assert::are_equal("09", bit_converter::to_string(vectorOne, 2, 1));
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 2, 2);});
      
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 3, 1);});
      
      array<xtd::byte> vectorEmpty;
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorEmpty, 1);});
    }
    
    void test_method_(to_uint16) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_uint16(array<byte> {0x00, 0x00}, 2);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_uint16(array<byte> {0x00, 0x00}, 1);});
      
      assert::are_equal(15, bit_converter::to_uint16(array<byte> {0x0F, 0x00}, 0));
      assert::are_equal(1023, bit_converter::to_uint16(array<byte> {0xFF, 0x03}, 0));
      assert::are_equal(10000, bit_converter::to_uint16(array<byte> {0x10, 0x27}, 0));
      assert::are_equal(0, bit_converter::to_uint16(array<byte> {0x00, 0x00}, 0));
      assert::are_equal(std::numeric_limits<uint16>::lowest(), bit_converter::to_uint16(array<byte> {0x00, 0x00}, 0));
      assert::are_equal(std::numeric_limits<uint16>::max(), bit_converter::to_uint16(array<byte> {0xFF, 0xFF}, 0));
    }
    
    void test_method_(to_uint32) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_uint32(array<byte> {0x00, 0x00, 0x00, 0x00}, 4);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_uint32(array<byte> {0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(15u, bit_converter::to_uint32(array<byte> {0x0F, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(1023u, bit_converter::to_uint32(array<byte> {0xFF, 0x03, 0x00, 0x00}, 0));
      assert::are_equal(0x100000u, bit_converter::to_uint32(array<byte> {0x00, 0x00, 0x10, 0x00}, 0));
      assert::are_equal(1000000000u, bit_converter::to_uint32(array<byte> {0x00, 0xCA, 0x9A, 0x3B}, 0));
      assert::are_equal(std::numeric_limits<uint32>::lowest(), bit_converter::to_uint32(array<byte> {0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(std::numeric_limits<uint32>::max(), bit_converter::to_uint32(array<byte> {0xFF, 0xFF, 0xFF, 0xFF}, 0));
    }
    
    void test_method_(to_uint64) {
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_uint64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);});
      assert::throws<index_out_of_range_exception>([] {bit_converter::to_uint64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(0xFFFFFFull, bit_converter::to_uint64(array<byte> {0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(1000000000ull, bit_converter::to_uint64(array<byte> {0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(0x100000000ull, bit_converter::to_uint64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(0xAAAAAAAAAAAAull, bit_converter::to_uint64(array<byte> {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0));
      assert::are_equal(1000000000000000000ull, bit_converter::to_uint64(array<byte> {0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0));
      assert::are_equal(10000000000000000000ull, bit_converter::to_uint64(array<byte> {0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A}, 0));
      assert::are_equal(std::numeric_limits<uint64>::lowest(), bit_converter::to_uint64(array<byte> {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(std::numeric_limits<uint64>::max(), bit_converter::to_uint64(array<byte> {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
    }
  };
}
