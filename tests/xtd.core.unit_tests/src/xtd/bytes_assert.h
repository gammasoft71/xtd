#pragma once
#include <xtd/xtd.tunit>

namespace unit_tests {
  class bytes_assert final : private xtd::tunit::base_assert {
    static bool is_little_endian() {
      static constexpr const int32_t endian = 1;
      return *(char*)&endian == 1;
    }
    
  public:
    template<typename value_t, typename bytes_t>
    static void are_equal(value_t b, const std::vector<bytes_t>& bytes) {are_equal(b, bytes, "", xtd::diagnostics::stack_frame());}
    
    template<typename value_t, typename bytes_t>
    static void are_equal(value_t b, const std::vector<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(b, bytes, "", stack_frame);}
    
    template<typename value_t, typename bytes_t>
    static void are_equal(value_t b, const std::vector<bytes_t>& bytes, const std::string& message) {are_equal(b, bytes, message, xtd::diagnostics::stack_frame());}
    
    template<typename value_t, typename bytes_t>
    static void are_equal(value_t b, const std::vector<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
      if (bytes.size() == 1 && bytes[0] == b)
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), base_assert::to_string(b), message, stack_frame);
    }
    
    template<typename value1_t, typename value2_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, const std::vector<bytes_t>& bytes) {are_equal(b1, b2, bytes, "", xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, const std::vector<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(b1, b2, bytes, "", stack_frame);}
    
    template<typename value1_t, typename value2_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, const std::vector<bytes_t>& bytes, const std::string& message) {are_equal(b1, b2, bytes, message, xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, const std::vector<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
      if (bytes.size() == 2 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2) || (bytes[0] == b2 && bytes[1] == b1)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " +  base_assert::to_string(b2) + "}", message, stack_frame);
    }
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, const std::vector<bytes_t>& bytes) {are_equal(b1, b2, b3, b4, bytes, "", xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, const std::vector<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(b1, b2, b3, b4, bytes, "", stack_frame);}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, const std::vector<bytes_t>& bytes, const std::string& message) {are_equal(b1, b2, b3, b4, bytes, message, xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, const std::vector<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
      if (bytes.size() == 4 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2 && bytes[2] == b3 && bytes[3] == b4) || (bytes[0] == b4 && bytes[1] == b3 && bytes[2] == b2 && bytes[3] == b1)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " +  base_assert::to_string(b2) + ", " +  base_assert::to_string(b3) + ", " +  base_assert::to_string(b4) + "}", message, stack_frame);
    }
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, const std::vector<bytes_t>& bytes) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, bytes, "", xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, const std::vector<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, bytes, "", stack_frame);}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, const std::vector<bytes_t>& bytes, const std::string& message) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, bytes, message, xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, const std::vector<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
      if (bytes.size() == 8 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2 && bytes[2] == b3 && bytes[3] == b4 && bytes[4] == b5 && bytes[5] == b6 && bytes[6] == b7 && bytes[7] == b8) || (bytes[0] == b8 && bytes[1] == b7 && bytes[2] == b6 && bytes[3] == b5 && bytes[4] == b4 && bytes[5] == b3 && bytes[6] == b2 && bytes[7] == b1)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " +  base_assert::to_string(b2) + ", " +  base_assert::to_string(b3) + ", " +  base_assert::to_string(b4) + ", " +  base_assert::to_string(b5) + ", " +  base_assert::to_string(b6) + ", " +  base_assert::to_string(b7) + ", " +  base_assert::to_string(b8) + "}", message, stack_frame);
    }
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename value9_t, typename value10_t, typename value11_t, typename value12_t, typename value13_t, typename value14_t, typename value15_t, typename value16_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, value9_t b9, value10_t b10, value11_t b11, value12_t b12, value13_t b13, value14_t b14, value15_t b15, value16_t b16, const std::vector<bytes_t>& bytes) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, bytes, "", xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename value9_t, typename value10_t, typename value11_t, typename value12_t, typename value13_t, typename value14_t, typename value15_t, typename value16_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, value9_t b9, value10_t b10, value11_t b11, value12_t b12, value13_t b13, value14_t b14, value15_t b15, value16_t b16, const std::vector<bytes_t>& bytes, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, b10, b11, b12, b13, b14, b15, b16, bytes, "", stack_frame);}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename value9_t, typename value10_t, typename value11_t, typename value12_t, typename value13_t, typename value14_t, typename value15_t, typename value16_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, value9_t b9, value10_t b10, value11_t b11, value12_t b12, value13_t b13, value14_t b14, value15_t b15, value16_t b16, const std::vector<bytes_t>& bytes, const std::string& message) {are_equal(b1, b2, b3, b4, b5, b6, b7, b8, b10, b11, b12, b13, b14, b15, b16, bytes, message, xtd::diagnostics::stack_frame());}
    
    template<typename value1_t, typename value2_t, typename value3_t, typename value4_t, typename value5_t, typename value6_t, typename value7_t, typename value8_t, typename value9_t, typename value10_t, typename value11_t, typename value12_t, typename value13_t, typename value14_t, typename value15_t, typename value16_t, typename bytes_t>
    static void are_equal(value1_t b1, value2_t b2, value3_t b3, value4_t b4, value5_t b5, value6_t b6, value7_t b7, value8_t b8, value9_t b9, value10_t b10, value11_t b11, value12_t b12, value13_t b13, value14_t b14, value15_t b15, value16_t b16, const std::vector<bytes_t>& bytes, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
      if (bytes.size() == 16 && ((is_little_endian() && bytes[0] == b1 && bytes[1] == b2 && bytes[2] == b3 && bytes[3] == b4 && bytes[4] == b5 && bytes[5] == b6 && bytes[6] == b7 && bytes[7] == b8 && bytes[8] == b9 && bytes[9] == b10 && bytes[10] == b11 && bytes[11] == b12 && bytes[12] == b13 && bytes[13] == b14 && bytes[14] == b15 && bytes[15] == b16) || (bytes[0] == b8 && bytes[1] == b7 && bytes[2] == b6 && bytes[3] == b5 && bytes[4] == b4 && bytes[5] == b3 && bytes[6] == b2 && bytes[7] == b1 && bytes[8] == b16 && bytes[9] == b15 && bytes[10] == b14 && bytes[11] == b13 && bytes[12] == b12 && bytes[13] == b11 && bytes[14] == b10 && bytes[15] == b9)))
        base_assert::succeed(message, stack_frame);
      else
        base_assert::fail(base_assert::to_string(bytes), "{" + base_assert::to_string(b1) + ", " +  base_assert::to_string(b2) + ", " +  base_assert::to_string(b3) + ", " +  base_assert::to_string(b4) + ", " +  base_assert::to_string(b5) + ", " +  base_assert::to_string(b6) + ", " +  base_assert::to_string(b7) + ", " +  base_assert::to_string(b8) +  base_assert::to_string(b9) +  base_assert::to_string(b10) +  base_assert::to_string(b11) +  base_assert::to_string(b12) +  base_assert::to_string(b13) +  base_assert::to_string(b14) +  base_assert::to_string(b15) +  base_assert::to_string(b16) + "}", message, stack_frame);
    }
  };
}
