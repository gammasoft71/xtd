#include <cfloat>
#include <cmath>
#include <xtd/bit_converter.h>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/using.h>
#include "bytes_assert.h"

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_bit_converter) {
    public:
    void test_method_(get_bytes_boolean) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(false)) {
        bytes_assert::are_equal(0, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(true)) {
        bytes_assert::are_equal(1, bytes, csf_);
      }
    }

    void test_method_(get_bytes_char) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(' ')) {
        bytes_assert::are_equal(0x20, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes('*')) {
        bytes_assert::are_equal(0x2A, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes('3')) {
        bytes_assert::are_equal(0x33, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes('A')) {
        bytes_assert::are_equal(0x41, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes('[')) {
        bytes_assert::are_equal(0x5B, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes('a')) {
        bytes_assert::are_equal(0x61, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes('{')) {
        bytes_assert::are_equal(0x7B, 0x00, 0x00, 0x00, bytes, csf_);
      }
    }

    void test_method_(get_bytes_double) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(255.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(4294967295.0)) {
        bytes_assert::are_equal(0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0.00390625)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0.00000000023283064365386962890625)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.23456789012345E-300)) {
        bytes_assert::are_equal(0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.2345678901234565)) {
        bytes_assert::are_equal(0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.2345678901234567)) {
        bytes_assert::are_equal(0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.2345678901234569)) {
        bytes_assert::are_equal(0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.23456789012345678E+300)) {
        bytes_assert::are_equal(0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-std::numeric_limits<double>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<double>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(DBL_EPSILON)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x3C, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<double>::quiet_NaN())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-std::numeric_limits<double>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<double>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F, bytes, csf_);
      }
    }

    void test_method_(get_bytes_int16) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<int16_t>(0))) {
        bytes_assert::are_equal(0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<int16_t>(15))) {
        bytes_assert::are_equal(0x0F, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<int16_t>(-15))) {
        bytes_assert::are_equal(0xF1, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<int16_t>(10000))) {
        bytes_assert::are_equal(0x10, 0x27, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<int16_t>(-10000))) {
        bytes_assert::are_equal(0xF0, 0xD8, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<int16_t>::min())) {
        bytes_assert::are_equal(0x00, 0x80, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<int16_t>::max())) {
        bytes_assert::are_equal(0xFF, 0x7F, bytes, csf_);
      }
    }

    void test_method_(get_bytes_int32) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(15)) {
        bytes_assert::are_equal(0x0F, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-15)) {
        bytes_assert::are_equal(0xF1, 0xFF, 0xFF, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1048576)) {
        bytes_assert::are_equal(0x00, 0x00, 0x10, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-1048576)) {
        bytes_assert::are_equal(0x00, 0x00, 0xF0, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1000000000)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-1000000000)) {
        bytes_assert::are_equal(0x00, 0x36, 0x65, 0xC4, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<int32_t>::min())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x80, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<int32_t>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0x7F, bytes, csf_);
      }
    }
    
    void test_method_(get_bytes_int64) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0xFFFFFFLL)) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1000000000LL)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-1000000000LL)) {
        bytes_assert::are_equal(0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0x100000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-0x100000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0xAAAAAAAAAAAALL)) {
        bytes_assert::are_equal(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-0xAAAAAAAAAAAALL)) {
        bytes_assert::are_equal(0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1000000000000000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-1000000000000000000LL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<int64_t>::min())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<int64_t>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, bytes, csf_);
      }
    }
    
    void test_method_(get_bytes_float) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0.0f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.0f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(15.0f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x70, 0x41, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(65535.0f)) {
        bytes_assert::are_equal(0x00, 0xFF, 0x7F, 0x47, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0.00390625f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x3B, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0.00000000023283064365386962890625f)) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x2F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.2345E-35f)) {
        bytes_assert::are_equal(0x49, 0x46, 0x83, 0x05, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.2345671f)) {
        bytes_assert::are_equal(0x4B, 0x06, 0x9E, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.2345673f)) {
        bytes_assert::are_equal(0x4D, 0x06, 0x9E, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.2345677f)) {
        bytes_assert::are_equal(0x50, 0x06, 0x9E, 0x3F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1.23456789E+35f)) {
        bytes_assert::are_equal(0x1E, 0x37, 0xBE, 0x79, bytes, csf_);
      }

      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-std::numeric_limits<float>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0x7F, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<float>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0x7F, 0x7F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(FLT_EPSILON)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x34, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<float>::quiet_NaN())) {
        bytes_assert::are_equal(0x00, 0x00, 0xC0, 0x7F, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(-std::numeric_limits<float>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0xFF, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<float>::infinity())) {
        bytes_assert::are_equal(0x00, 0x00, 0x80, 0x7F, bytes, csf_);
      }
    }
    
    void test_method_(get_bytes_uint16_t) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<uint16_t>(15))) {
        bytes_assert::are_equal(0x0F, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<uint16_t>(1023))) {
        bytes_assert::are_equal(0xFF, 0x03, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<uint16_t>(10000))) {
        bytes_assert::are_equal(0x10, 0x27, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(static_cast<uint16_t>(0))) {
        bytes_assert::are_equal(0x00, 0x00, bytes, csf_);
      }
            
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<uint16_t>::min())) {
        bytes_assert::are_equal(0x00, 0x00, bytes, csf_);
      }

      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<uint16_t>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, bytes, csf_);
      }
    }
    
    void test_method_(get_bytes_uint32) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(15U)) {
        bytes_assert::are_equal(0x0F, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1023U)) {
        bytes_assert::are_equal(0xFF, 0x03, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0x100000U)) {
        bytes_assert::are_equal(0x00, 0x00, 0x10, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1000000000U)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<uint32_t>::min())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<uint32_t>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, bytes, csf_);
      }
    }
    
    void test_method_(getBytesUInt64) {
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0xFFFFFFULL)) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1000000000ULL)) {
        bytes_assert::are_equal(0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0x100000000ULL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(0xAAAAAAAAAAAAULL)) {
        bytes_assert::are_equal(0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(1000000000000000000ULL)) {
        bytes_assert::are_equal(0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(10000000000000000000ULL)) {
        bytes_assert::are_equal(0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<uint64_t>::min())) {
        bytes_assert::are_equal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, bytes, csf_);
      }
      
      using_(vector<uint8_t> bytes = bit_converter::get_bytes(std::numeric_limits<uint64_t>::max())) {
        bytes_assert::are_equal(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, bytes, csf_);
      }
    }
    
    void test_method_(to_boolean) {
      assert::throws<out_of_range>([]{bit_converter::to_boolean({0}, 1);}, csf_);
      
      assert::is_false(bit_converter::to_boolean({0}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({1}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({2}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({4}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({8}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({16}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({32}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({64}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({128}, 0), csf_);
      assert::is_true(bit_converter::to_boolean({255}, 0), csf_);
    }
    
    void test_method_(to_char) {
      assert::throws<out_of_range>([] {bit_converter::to_char({0x00, 0x00, 0x00, 0x00}, 4);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_char({0x00, 0x00, 0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(U' ', bit_converter::to_char({0x20, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(U'*', bit_converter::to_char({0x2A, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(U'3', bit_converter::to_char({0x33, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(U'A', bit_converter::to_char({0x41, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(U'[', bit_converter::to_char({0x5B, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(U'a', bit_converter::to_char({0x61, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(U'{', bit_converter::to_char({0x7B, 0x00, 0x00, 0x00}, 0), csf_);
    }
    
    void test_method_(to_double) {
      assert::throws<out_of_range>([] {bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(0.0, bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(1.0, bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F}, 0), csf_);
      assert::are_equal(255.0, bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x6F, 0x40}, 0), csf_);
      assert::are_equal(4294967295.0, bit_converter::to_double({0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xEF, 0x41}, 0), csf_);
      assert::are_equal(0.00390625, bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3F}, 0), csf_);
      assert::are_equal(0.00000000023283064365386962890625, bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3D}, 0), csf_);
      assert::are_equal(1.23456789012345E-300, bit_converter::to_double({0xDF, 0x88, 0x1E, 0x1C, 0xFE, 0x74, 0xAA, 0x01}, 0), csf_);
      assert::are_equal(1.2345678901234565, bit_converter::to_double({0xFA, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0), csf_);
      assert::are_equal(1.2345678901234567, bit_converter::to_double({0xFB, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0), csf_);
      assert::are_equal(1.2345678901234569, bit_converter::to_double({0xFC, 0x59, 0x8C, 0x42, 0xCA, 0xC0, 0xF3, 0x3F}, 0), csf_);
      assert::are_equal(1.23456789012345678E+300, bit_converter::to_double({0x52, 0xD3, 0xBB, 0xBC, 0xE8, 0x7E, 0x3D, 0x7E}, 0), csf_);
      assert::are_equal(-std::numeric_limits<double>::max(), bit_converter::to_double({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF}, 0), csf_);
      assert::are_equal(std::numeric_limits<double>::max(), bit_converter::to_double({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F}, 0), csf_);
      assert::are_equal(DBL_EPSILON, bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x3C}, 0), csf_);
      assert::is_true(isnan(bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F}, 0)), csf_);
      assert::are_equal(-std::numeric_limits<double>::infinity(), bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF}, 0), csf_);
      assert::are_equal(std::numeric_limits<double>::infinity(), bit_converter::to_double({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F}, 0), csf_);
    }
    
    void test_method_(to_int16) {
      assert::throws<out_of_range>([] {bit_converter::to_int16({0x00, 0x00}, 2);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_int16({0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(0, bit_converter::to_int16({0x00, 0x00}, 0), csf_);
      assert::are_equal(15, bit_converter::to_int16({0x0F, 0x00}, 0), csf_);
      assert::are_equal(-15, bit_converter::to_int16({0xF1, 0xFF}, 0), csf_);
      assert::are_equal(10000, bit_converter::to_int16({0x10, 0x27}, 0), csf_);
      assert::are_equal(-10000, bit_converter::to_int16({0xF0, 0xD8}, 0), csf_);
      assert::are_equal(std::numeric_limits<int16_t>::min(), bit_converter::to_int16({0x00, 0x80}, 0), csf_);
      assert::are_equal(std::numeric_limits<int16_t>::max(), bit_converter::to_int16({0xFF, 0x7F}, 0), csf_);
    }
    
    void test_method_(to_int32) {
      assert::throws<out_of_range>([] {bit_converter::to_int32({0x00, 0x00, 0x00, 0x00}, 4);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_int32({0x00, 0x00, 0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(0, bit_converter::to_int32({0x00, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(15, bit_converter::to_int32({0x0F, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(-15, bit_converter::to_int32({0xF1, 0xFF, 0xFF, 0xFF}, 0), csf_);
      assert::are_equal(1048576, bit_converter::to_int32({0x00, 0x00, 0x10, 0x00}, 0), csf_);
      assert::are_equal(-1048576, bit_converter::to_int32({0x00, 0x00, 0xF0, 0xFF}, 0), csf_);
      assert::are_equal(1000000000, bit_converter::to_int32({0x00, 0xCA, 0x9A, 0x3B}, 0), csf_);
      assert::are_equal(-1000000000, bit_converter::to_int32({0x00, 0x36, 0x65, 0xC4}, 0), csf_);
      assert::are_equal(std::numeric_limits<int32_t>::min(), bit_converter::to_int32({0x00, 0x00, 0x00, 0x80}, 0), csf_);
      assert::are_equal(std::numeric_limits<int32_t>::max(), bit_converter::to_int32({0xFF, 0xFF, 0xFF, 0x7F}, 0), csf_);
    }
    
    void test_method_(to_int64) {
      assert::throws<out_of_range>([] {bit_converter::to_int64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_int64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(0LL, bit_converter::to_int64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(0xFFFFFFLL, bit_converter::to_int64({0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(1000000000LL, bit_converter::to_int64({0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(-1000000000LL, bit_converter::to_int64({0x00, 0x36, 0x65, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF}, 0), csf_);
      assert::are_equal(0x100000000LL, bit_converter::to_int64({0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(-0x100000000LL, bit_converter::to_int64({0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF}, 0), csf_);
      assert::are_equal(0xAAAAAAAAAAAALL, bit_converter::to_int64({0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0), csf_);
      assert::are_equal(-0xAAAAAAAAAAAALL, bit_converter::to_int64({0x56, 0x55, 0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF}, 0), csf_);
      assert::are_equal(1000000000000000000LL, bit_converter::to_int64({0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0), csf_);
      assert::are_equal(-1000000000000000000LL, bit_converter::to_int64({0x00, 0x00, 0x9C, 0x58, 0x4C, 0x49, 0x1F, 0xF2}, 0), csf_);
      assert::are_equal(std::numeric_limits<int64_t>::min(), bit_converter::to_int64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80}, 0), csf_);
      assert::are_equal(std::numeric_limits<int64_t>::max(), bit_converter::to_int64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}, 0), csf_);
    }
    
    void test_method_(to_single) {
      assert::throws<out_of_range>([] {bit_converter::to_single({0x00, 0x00, 0x00, 0x00}, 4);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_single({0x00, 0x00, 0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(0.0, bit_converter::to_single({0x00, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(1.0f, bit_converter::to_single({0x00, 0x00, 0x80, 0x3F}, 0), csf_);
      assert::are_equal(15.0f, bit_converter::to_single({0x00, 0x00, 0x70, 0x41}, 0));
      assert::are_equal(65535.0f, bit_converter::to_single({0x00, 0xFF, 0x7F, 0x47}, 0), csf_);
      assert::are_equal(0.00390625f, bit_converter::to_single({0x00, 0x00, 0x80, 0x3B}, 0), csf_);
      assert::are_equal(0.00000000023283064365386962890625f, bit_converter::to_single({0x00, 0x00, 0x80, 0x2F}, 0), csf_);
      assert::are_equal(1.2345E-35f, bit_converter::to_single({0x49, 0x46, 0x83, 0x05}, 0), csf_);
      assert::are_equal(1.2345671f, bit_converter::to_single({0x4B, 0x06, 0x9E, 0x3F}, 0), csf_);
      assert::are_equal(1.2345673f, bit_converter::to_single({0x4D, 0x06, 0x9E, 0x3F}, 0), csf_);
      assert::are_equal(1.2345677f, bit_converter::to_single({0x50, 0x06, 0x9E, 0x3F}, 0), csf_);
      assert::are_equal(1.23456789E+35f, bit_converter::to_single({0x1E, 0x37, 0xBE, 0x79}, 0), csf_);
      assert::are_equal(-std::numeric_limits<float>::max(), bit_converter::to_single({0xFF, 0xFF, 0x7F, 0xFF}, 0), csf_);
      assert::are_equal(std::numeric_limits<float>::max(), bit_converter::to_single({0xFF, 0xFF, 0x7F, 0x7F}, 0), csf_);
      assert::are_equal(FLT_EPSILON, bit_converter::to_single({0x00, 0x00, 0x00, 0x34}, 0), csf_);
      assert::is_true(isnan(bit_converter::to_single({0x00, 0x00, 0xC0, 0x7F}, 0)), csf_);
      assert::are_equal(-std::numeric_limits<float>::infinity(), bit_converter::to_single({0x00, 0x00, 0x80, 0xFF}, 0), csf_);
      assert::are_equal(std::numeric_limits<float>::infinity(), bit_converter::to_single({0x00, 0x00, 0x80, 0x7F}, 0), csf_);
    }
    
    void test_method_(to_string) {
      vector<uint8_t> vectorOne = {0, 1, 2, 4, 8, 16, 32, 64, 128, 255};
      assert::are_equal("00-01-02-04-08-10-20-40-80-FF", bit_converter::to_string(vectorOne), csf_);
      
      vector<uint8_t> vectorTwo = {32, 0, 0, 42, 0, 65, 0, 125, 0, 197, 0, 168, 3, 41, 4, 172, 32};
      assert::are_equal("20-00-00-2A-00-41-00-7D-00-C5-00-A8-03-29-04-AC-20", bit_converter::to_string(vectorTwo), csf_);
      
      vector<uint8_t> vectorThree = {15, 0, 0, 128, 16, 39, 240, 216, 241, 255, 127};
      assert::are_equal("0F-00-00-80-10-27-F0-D8-F1-FF-7F", bit_converter::to_string(vectorThree), csf_);
      
      vector<uint8_t> vectorFour = {15, 0, 0, 0, 0, 16, 0, 255, 3, 0, 0, 202, 154, 59, 255, 255, 255, 255, 127};
      assert::are_equal("0F-00-00-00-00-10-00-FF-03-00-00-CA-9A-3B-FF-FF-FF-FF-7F", bit_converter::to_string(vectorFour), csf_);
      
      vector<uint8_t> vectorEmpty;
      assert::are_equal("", bit_converter::to_string(vectorEmpty), csf_);
    }
    
    void test_method_(to_string_with_start_index) {
      vector<uint8_t> vectorOne = {3, 6, 9};
      assert::are_equal("03-06-09", bit_converter::to_string(vectorOne, 0), csf_);
      assert::are_equal("06-09", bit_converter::to_string(vectorOne, 1), csf_);
      assert::are_equal("09", bit_converter::to_string(vectorOne, 2), csf_);
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 3);}, csf_);
      
      vector<uint8_t> vectorEmpty;
      assert::are_equal("", bit_converter::to_string(vectorEmpty, 0), csf_);
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorEmpty, 1);}, csf_);
    }
    
    void test_method_(to_string_with_start_index_and_length) {
      vector<uint8_t> vectorOne = {3, 6, 9};
      
      assert::are_equal("", bit_converter::to_string(vectorOne, 0, 0), csf_);
      assert::are_equal("03", bit_converter::to_string(vectorOne, 0, 1), csf_);
      assert::are_equal("03-06", bit_converter::to_string(vectorOne, 0, 2), csf_);
      assert::are_equal("03-06-09", bit_converter::to_string(vectorOne, 0, 3), csf_);
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 0, 4);}, csf_);
      
      assert::are_equal("", bit_converter::to_string(vectorOne, 1, 0), csf_);
      assert::are_equal("06", bit_converter::to_string(vectorOne, 1, 1), csf_);
      assert::are_equal("06-09", bit_converter::to_string(vectorOne, 1, 2), csf_);
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 1, 3);}, csf_);
      
      assert::are_equal("", bit_converter::to_string(vectorOne, 2, 0), csf_);
      assert::are_equal("09", bit_converter::to_string(vectorOne, 2, 1), csf_);
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 2, 2);}, csf_);
      
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorOne, 3, 1);}, csf_);
      
      vector<uint8_t> vectorEmpty;
      assert::throws<argument_out_of_range_exception>([&] {bit_converter::to_string(vectorEmpty, 1);}, csf_);
    }
    
    void test_method_(to_uint16) {
      assert::throws<out_of_range>([] {bit_converter::to_uint16({0x00, 0x00}, 2);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_uint16({0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(15, bit_converter::to_uint16({0x0F, 0x00}, 0), csf_);
      assert::are_equal(1023, bit_converter::to_uint16({0xFF, 0x03}, 0), csf_);
      assert::are_equal(10000, bit_converter::to_uint16({0x10, 0x27}, 0), csf_);
      assert::are_equal(0, bit_converter::to_uint16({0x00, 0x00}, 0), csf_);
      assert::are_equal(std::numeric_limits<uint16_t>::min(), bit_converter::to_uint16({0x00, 0x00}, 0), csf_);
      assert::are_equal(std::numeric_limits<uint16_t>::max(), bit_converter::to_uint16({0xFF, 0xFF}, 0), csf_);
    }
    
    void test_method_(to_uint32) {
      assert::throws<out_of_range>([] {bit_converter::to_uint32({0x00, 0x00, 0x00, 0x00}, 4);}, csf_);
      assert::throws<out_of_range>([] {bit_converter::to_uint32({0x00, 0x00, 0x00, 0x00}, 1);}, csf_);
      
      assert::are_equal(15U, bit_converter::to_uint32({0x0F, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(1023U, bit_converter::to_uint32({0xFF, 0x03, 0x00, 0x00}, 0), csf_);
      assert::are_equal(0x100000U, bit_converter::to_uint32({0x00, 0x00, 0x10, 0x00}, 0), csf_);
      assert::are_equal(1000000000U, bit_converter::to_uint32({0x00, 0xCA, 0x9A, 0x3B}, 0), csf_);
      assert::are_equal(std::numeric_limits<uint32_t>::min(), bit_converter::to_uint32({0x00, 0x00, 0x00, 0x00}, 0), csf_);
      assert::are_equal(std::numeric_limits<uint32_t>::max(), bit_converter::to_uint32({0xFF, 0xFF, 0xFF, 0xFF}, 0), csf_);
    }
    
    void test_method_(to_uint64) {
      assert::throws<out_of_range>([] {bit_converter::to_uint64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);});
      assert::throws<out_of_range>([] {bit_converter::to_uint64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 1);});
      
      assert::are_equal(0xFFFFFFULL, bit_converter::to_uint64({0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(1000000000ULL, bit_converter::to_uint64({0x00, 0xCA, 0x9A, 0x3B, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(0x100000000ULL, bit_converter::to_uint64({0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(0xAAAAAAAAAAAAULL, bit_converter::to_uint64({0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00}, 0));
      assert::are_equal(1000000000000000000ULL, bit_converter::to_uint64({0x00, 0x00, 0x64, 0xA7, 0xB3, 0xB6, 0xE0, 0x0D}, 0));
      assert::are_equal(10000000000000000000ULL, bit_converter::to_uint64({0x00, 0x00, 0xE8, 0x89, 0x04, 0x23, 0xC7, 0x8A}, 0));
      assert::are_equal(std::numeric_limits<uint64_t>::min(), bit_converter::to_uint64({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0));
      assert::are_equal(std::numeric_limits<uint64_t>::max(), bit_converter::to_uint64({0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, 0));
    }
  };
}
