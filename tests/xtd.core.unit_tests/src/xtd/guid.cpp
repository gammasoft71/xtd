#include <map>
#include <xtd/guid.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_guid) {
  public:
    void test_method_(create_guid) {
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid().to_string(), csf_);
    }
    
    void test_method_(create_guid_from_bytes) {
      assert::are_equal("01020304-0506-0708-090a-0b0c0d0e0f10", guid({0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10}).to_string(), csf_);
    }
    
    void test_method_(create_guid_from_byte_array) {
      assert::are_equal("10203040-5060-7080-90a0-b0c0d0e0f001", guid(vector<uint8_t> {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).to_string(), csf_);
    }
    
    void test_method_(constructor) {
      assert::are_equal("01020304-0506-0708-090a-0b0c0d0e0f10", guid(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10}).to_string(), csf_);
      
      assert::are_equal("10203040-5060-7080-90a0-b0c0d0e0f001", guid(0x10203040, 0x5060, 0x7080, vector<uint8_t> {0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).to_string(), csf_);
      
      assert::are_equal("01020304-0506-0708-090a-0b0c0d0e0f10", guid(int32_t(0x01020304), int16_t(0x0506), int16_t(0x0708), 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10).to_string(), csf_);
      assert::are_equal("10203040-5060-7080-90a0-b0c0d0e0f001", guid(uint32_t(0x10203040), uint16_t(0x5060), uint16_t(0x7080), 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01).to_string(), csf_);
    }
    
    void test_method_(constructor2) {
      xtd::guid guid = xtd::guid::new_guid();
      assert::is_greater(guid.compare_to(guid::empty), 0, csf_);
      assert::is_less(guid::empty.compare_to(guid), 0, csf_);
      
      assert::are_equal(xtd::guid(uint32_t(0x00000000), uint16_t(0x0000), uint16_t(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).compare_to(xtd::guid(uint32_t(0x00000000), uint16_t(0x0000), uint16_t(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0);
      assert::is_less(xtd::guid(uint32_t(0x00000000), uint16_t(0x0000), uint16_t(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).compare_to(xtd::guid(uint32_t(0x00000000), uint16_t(0x0000), uint16_t(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02)), 0, csf_);
      assert::is_greater(xtd::guid(uint32_t(0x00000000), uint16_t(0x0000), uint16_t(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02).compare_to(xtd::guid(uint32_t(0x00000000), uint16_t(0x0000), uint16_t(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0, csf_);
    }
    
    void test_method_(equals) {
      guid guid1 = guid::new_guid();
      guid guid2 = guid::new_guid();
      assert::is_false(guid1.equals(guid::empty), csf_);
      assert::is_false(guid1.equals(guid2), csf_);
    }
    
    void test_method_(new_guid) {
      map<guid, guid> guids;
      for (int32_t i = 0; i < 1'000; i++) {
        xtd::guid guid = xtd::guid::new_guid();
        assert::is_true(guids.find(guid) == guids.end(), csf_);
        guids[guid] = guid;
      }
    }
    
    void test_method_(to_string) {
      assert::throws<format_exception>([]{guid::empty.to_string("A");}, csf_);
      assert::throws<format_exception>([]{guid::empty.to_string("ND");}, csf_);
      
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string(), csf_);
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string(""), csf_);
      assert::are_equal("00000000000000000000000000000000", guid::empty.to_string("N"), csf_);
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string("D"), csf_);
      assert::are_equal("{00000000-0000-0000-0000-000000000000}", guid::empty.to_string("B"), csf_);
      assert::are_equal("(00000000-0000-0000-0000-000000000000)", guid::empty.to_string("P"), csf_);
      assert::are_equal("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", guid::empty.to_string("X"), csf_);
      assert::are_equal("00000000000000000000000000000000", guid::empty.to_string("n"), csf_);
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string("d"), csf_);
      assert::are_equal("{00000000-0000-0000-0000-000000000000}", guid::empty.to_string("b"), csf_);
      assert::are_equal("(00000000-0000-0000-0000-000000000000)", guid::empty.to_string("p"), csf_);
      assert::are_equal("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", guid::empty.to_string("x"), csf_);
    }
    
    void test_method_(compare_to) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      //assert::is_less(guid1.compare_to(guid2), 0, csf_);
      //assert::is_greater(guid2.compare_to(guid1), 0, csf_);
    }
    
    void test_method_(less_than_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 < guid2, csf_);
      assert::is_false(guid2 < guid1, csf_);
    }
    
    void test_method_(less_equal_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 <= guid2, csf_);
      assert::is_true(guid1 <= guid3, csf_);
      assert::is_false(guid2 <= guid1, csf_);
    }
    
    void test_method_(greate_than_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 > guid2, csf_);
      assert::is_false(guid2 > guid1, csf_);
    }
    
    void test_method_(greater_equal_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 >= guid2, csf_);
      assert::is_true(guid1 >= guid3, csf_);
      assert::is_false(guid2 >= guid1, csf_);
    }
    
    void test_method_(equal_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_false(guid1 == guid2, csf_);
      assert::is_true(guid1 == guid3, csf_);
    }
    
    void test_method_(different_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 != guid2, csf_);
      assert::is_false(guid1 != guid3, csf_);
    }
  };
}
