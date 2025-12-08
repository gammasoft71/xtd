#include <map>
#include <xtd/guid>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(guid_tests) {
    auto test_method_(create_guid) {
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid().to_string());
    }
    
    auto test_method_(create_guid_from_bytes) {
      assert::are_equal("01020304-0506-0708-090a-0b0c0d0e0f10", guid({0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10}).to_string());
    }
    
    auto test_method_(create_guid_from_byte_array) {
      assert::are_equal("10203040-5060-7080-90a0-b0c0d0e0f001", guid(array<xtd::byte> {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).to_string());
    }
    
    auto test_method_(constructor) {
      assert::are_equal("01020304-0506-0708-090a-0b0c0d0e0f10", guid(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10}).to_string());
      
      assert::are_equal("10203040-5060-7080-90a0-b0c0d0e0f001", guid(0x10203040, 0x5060, 0x7080, array<xtd::byte> {0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01}).to_string());
      
      assert::are_equal("01020304-0506-0708-090a-0b0c0d0e0f10", guid(int32(0x01020304), int16(0x0506), int16(0x0708), 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10).to_string());
      assert::are_equal("10203040-5060-7080-90a0-b0c0d0e0f001", guid(uint32(0x10203040), uint16(0x5060), uint16(0x7080), 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0x01).to_string());
    }
    
    auto test_method_(constructor2) {
      xtd::guid guid = xtd::guid::new_guid();
      assert::is_greater(guid.compare_to(guid::empty), 0);
      assert::is_less(guid::empty.compare_to(guid), 0);
      
      assert::are_equal(xtd::guid(uint32(0x00000000), uint16(0x0000), uint16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).compare_to(xtd::guid(uint32(0x00000000), uint16(0x0000), uint16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0);
      assert::is_less(xtd::guid(uint32(0x00000000), uint16(0x0000), uint16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01).compare_to(xtd::guid(uint32(0x00000000), uint16(0x0000), uint16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02)), 0);
      assert::is_greater(xtd::guid(uint32(0x00000000), uint16(0x0000), uint16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02).compare_to(xtd::guid(uint32(0x00000000), uint16(0x0000), uint16(0x0000), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01)), 0);
    }
    
    auto test_method_(equals) {
      guid guid1 = guid::new_guid();
      guid guid2 = guid::new_guid();
      assert::is_false(guid1.equals(guid::empty));
      assert::is_false(guid1.equals(guid2));
    }
    
    auto test_method_(new_guid) {
      std::map<guid, guid> guids;
      for (int32 i = 0; i < 1'000; i++) {
        xtd::guid guid = xtd::guid::new_guid();
        assert::is_true(guids.find(guid) == guids.end());
        guids[guid] = guid;
      }
    }
    
    auto test_method_(to_string) {
      assert::throws<format_exception>([] {guid::empty.to_string("A");});
      assert::throws<format_exception>([] {guid::empty.to_string("ND");});
      
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string());
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string(""));
      assert::are_equal("00000000000000000000000000000000", guid::empty.to_string("N"));
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string("D"));
      assert::are_equal("{00000000-0000-0000-0000-000000000000}", guid::empty.to_string("B"));
      assert::are_equal("(00000000-0000-0000-0000-000000000000)", guid::empty.to_string("P"));
      assert::are_equal("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", guid::empty.to_string("X"));
      assert::are_equal("00000000000000000000000000000000", guid::empty.to_string("n"));
      assert::are_equal("00000000-0000-0000-0000-000000000000", guid::empty.to_string("d"));
      assert::are_equal("{00000000-0000-0000-0000-000000000000}", guid::empty.to_string("b"));
      assert::are_equal("(00000000-0000-0000-0000-000000000000)", guid::empty.to_string("p"));
      assert::are_equal("{0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}", guid::empty.to_string("x"));
    }
    
    auto test_method_(compare_to) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      //assert::is_less(guid1.compare_to(guid2), 0);
      //assert::is_greater(guid2.compare_to(guid1), 0);
    }
    
    auto test_method_(less_than_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 < guid2);
      assert::is_false(guid2 < guid1);
    }
    
    auto test_method_(less_equal_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 <= guid2);
      assert::is_true(guid1 <= guid3);
      assert::is_false(guid2 <= guid1);
    }
    
    auto test_method_(greate_than_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 > guid2);
      assert::is_false(guid2 > guid1);
    }
    
    auto test_method_(greater_equal_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 >= guid2);
      assert::is_true(guid1 >= guid3);
      assert::is_false(guid2 >= guid1);
    }
    
    auto test_method_(equal_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_false(guid1 == guid2);
      assert::is_true(guid1 == guid3);
    }
    
    auto test_method_(different_operator) {
      guid guid1(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      guid guid2(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10});
      guid guid3(0x01020304, 0x0506, 0x0708, {0x09, 0x0A, 0x0B, 0x0C, 0x3D, 0x0E, 0x0F, 0x10});
      
      assert::is_true(guid1 != guid2);
      assert::is_false(guid1 != guid3);
    }
  };
}
