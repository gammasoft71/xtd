#pragma once
#include <xtd/tunit/base_assert>

namespace xtd::tests {
  class bytes_assert final : private xtd::tunit::base_assert {
    static bool is_little_endian() {
      static constexpr int32 endian = 1;
      return *(char*)&endian == 1;
    }
    
  public:
    template<class value_t, class bytes_t>
    static void are_equal(value_t b, const array<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(b, bytes, xtd::string::empty_string, stack_frame);}
    
    template<class value_t, class bytes_t>
    static void are_equal(value_t b, const array<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
      if (bytes.size() == 1 && bytes[0] == b)
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), base_assert::to_string(b), message, stack_frame);
    }
    
    template<class value1_t, class value2_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, const array<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(b1, b2, bytes, xtd::string::empty_string, stack_frame);}
    
    template<class value1_t, class value2_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, const array<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
      if (bytes.size() == 2 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2) || (bytes[0] == b2 && bytes[1] == b1)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " + base_assert::to_string(b2) + "}", message, stack_frame);
    }
    
    template<class value1_t, class value2_t, class value3_t, class value4_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, const array<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(b1, b2, b3, b4, bytes, xtd::string::empty_string, stack_frame);}
    
    template<class value1_t, class value2_t, class value3_t, class value4_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, const array<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
      if (bytes.size() == 4 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2 && bytes[2] == b3 && bytes[3] == b4) || (bytes[0] == b4 && bytes[1] == b3 && bytes[2] == b2 && bytes[3] == b1)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " + base_assert::to_string(b2) + ", " + base_assert::to_string(b3) + ", " + base_assert::to_string(b4) + "}", message, stack_frame);
    }
    
    template<class value1_t, class value2_t, class value3_t, class value4_t, class value5_t, class value6_t, class value7_t, class value8_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, const array<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, bytes, xtd::string::empty_string, stack_frame);}
    
    template<class value1_t, class value2_t, class value3_t, class value4_t, class value5_t, class value6_t, class value7_t, class value8_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, const array<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
      if (bytes.size() == 8 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2 && bytes[2] == b3 && bytes[3] == b4 && bytes[4] == b5 && bytes[5] == b6 && bytes[6] == b7 && bytes[7] == b8) || (bytes[0] == b8 && bytes[1] == b7 && bytes[2] == b6 && bytes[3] == b5 && bytes[4] == b4 && bytes[5] == b3 && bytes[6] == b2 && bytes[7] == b1)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " + base_assert::to_string(b2) + ", " + base_assert::to_string(b3) + ", " + base_assert::to_string(b4) + ", " + base_assert::to_string(b5) + ", " + base_assert::to_string(b6) + ", " + base_assert::to_string(b7) + ", " + base_assert::to_string(b8) + "}", message, stack_frame);
    }
    
    template<class value1_t, class value2_t, class value3_t, class value4_t, class value5_t, class value6_t, class value7_t, class value8_t, class value9_t, class value10_t, class value11_t, class value12_t, class value13_t, class value14_t, class value15_t, class value16_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, value9_t b9, value10_t b10, value11_t b11, value12_t b12, value13_t b13, value14_t b14, value15_t b15, value16_t b16, const array<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, b10, b11, b12, b13, b14, b15, b16, bytes, xtd::string::empty_string, stack_frame);}
    
    template<class value1_t, class value2_t, class value3_t, class value4_t, class value5_t, class value6_t, class value7_t, class value8_t, class value9_t, class value10_t, class value11_t, class value12_t, class value13_t, class value14_t, class value15_t, class value16_t, class bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, value9_t b9, value10_t b10, value11_t b11, value12_t b12, value13_t b13, value14_t b14, value15_t b15, value16_t b16, const array<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
      if (bytes.size() == 16 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2 && bytes[2] == b3 && bytes[3] == b4 && bytes[4] == b5 && bytes[5] == b6 && bytes[6] == b7 && bytes[7] == b8 && bytes[8] == b9 && bytes[9] == b10 && bytes[10] == b11 && bytes[11] == b12 && bytes[12] == b13 && bytes[13] == b14 && bytes[14] == b15 && bytes[15] == b16) || (bytes[0] == b8 && bytes[1] == b7 && bytes[2] == b6 && bytes[3] == b5 && bytes[4] == b4 && bytes[5] == b3 && bytes[6] == b2 && bytes[7] == b1 && bytes[8] == b16 && bytes[9] == b15 && bytes[10] == b14 && bytes[11] == b13 && bytes[12] == b12 && bytes[13] == b11 && bytes[14] == b10 && bytes[15] == b9)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " + base_assert::to_string(b2) + ", " + base_assert::to_string(b3) + ", " + base_assert::to_string(b4) + ", " + base_assert::to_string(b5) + ", " + base_assert::to_string(b6) + ", " + base_assert::to_string(b7) + ", " + base_assert::to_string(b8) + base_assert::to_string(b9) + base_assert::to_string(b10) + base_assert::to_string(b11) + base_assert::to_string(b12) + base_assert::to_string(b13) + base_assert::to_string(b14) + base_assert::to_string(b15) + base_assert::to_string(b16) + "}", message, stack_frame);
    }
  };
}
