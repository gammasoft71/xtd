#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

class encoding {
  
};

/// @brief Encode and decode to UTF-8.
/// @remarks see https://en.wikipedia.org/wiki/UTF-8
class utf8 {
public:
  static int32_t from_bytes(const std::vector<xtd::byte_t>& bytes, size_t index = 0) {
    size_t size = get_format(bytes[0]);
    if (size == 1) return bytes[0];

    uint32_t codepoint = 0;
    size_t offset = 0;
    size_t rest = size - 1;
    for (size_t i = 0; i < size; i += 1) {
      if (i == 0)  { // head byte
        if (size == 1)
          offset = 1;
        else
          offset = size + 1;
      } else
        offset = 2;
      xtd::byte_t mask = 0xFF >> offset;
      uint32_t filtered = bytes[i] & mask;
      uint32_t toSet =  filtered << (rest * 6);
      rest -= 1;
      codepoint = codepoint | toSet;
    }
    return codepoint;
  }
  
  static size_t get_format(int32_t codepoint) noexcept {
    if (codepoint >> 7 == 0) return 1; // 0xxxxxxx
    if (codepoint >> 5 == 110) return 2; // 110xxxxx
    if (codepoint >> 4 == 1110) return 3; // 1110xxxx
    if (codepoint >> 3 == 11110) return 4; // 11110xxx
    return 1;
  }
  
  static size_t get_byte_count(int32_t codepoint) noexcept {
    if (codepoint < 0x80) return 1;
    if (codepoint < 0x800) return 2;
    if (codepoint < 0x10000) return 3;
    return 4;
  }
  
  static std::vector<xtd::byte_t> to_bytes(uint32_t codepoint) noexcept {
    std::vector<xtd::byte_t> result;
    if (codepoint < 0x80) {
      result.push_back(static_cast<xtd::byte_t>(codepoint));
    } else  if (codepoint < 0x800) {
      result.push_back(static_cast<xtd::byte_t>((codepoint >> 6) | 0xc0));
      result.push_back(static_cast<xtd::byte_t>((codepoint & 0x3f) | 0x80));
    } else if (codepoint < 0x10000) {
      result.push_back(static_cast<xtd::byte_t>((codepoint >> 12) | 0xe0));
      result.push_back(static_cast<xtd::byte_t>(((codepoint >> 6) & 0x3f) | 0x80));
      result.push_back(static_cast<xtd::byte_t>((codepoint & 0x3f) | 0x80));
    } else {
      result.push_back(static_cast<xtd::byte_t>((codepoint >> 18) | 0xf0));
      result.push_back(static_cast<xtd::byte_t>(((codepoint >> 12) & 0x3f) | 0x80));
      result.push_back(static_cast<xtd::byte_t>(((codepoint >> 6) & 0x3f) | 0x80));
      result.push_back(static_cast<xtd::byte_t>((codepoint & 0x3f) | 0x80));
    }
    return result;
  }

};

/// @brief Encode and decode to UTF-16.
/// @remarks see https://en.wikipedia.org/wiki/UTF-16
class utf16 {
public:
  static size_t get_byte_count(int32_t codepoint) noexcept {
    if (codepoint <= 0xFFFF) return 2;
    return 4;
  }
  
  static std::vector<xtd::byte_t> to_bytes(uint32_t codepoint) {
    /// https://en.wikipedia.org/wiki/UTF-16
    std::vector<xtd::byte_t> result;
    if (codepoint <= 0xFFFF)
      for (auto b : xtd::bit_converter::get_bytes(static_cast<char16_t>(codepoint)))
        result.push_back(b);
    else {
      for (auto b : xtd::bit_converter::get_bytes(static_cast<char16_t>((codepoint >> 10)   + 0xD7C0u)))
        result.push_back(b);
      for (auto b : xtd::bit_converter::get_bytes(static_cast<char16_t>((codepoint & 0x3ff) + 0xDC00u)))
        result.push_back(b);
    }
    return result;
  }
};

/// @brief Encode and decode to UTF-32.
/// @remarks see https://en.wikipedia.org/wiki/UTF-32
class utf32 {
public:
  static int32_t from_bytes(const std::vector<xtd::byte_t>& bytes, size_t index = 0) {
    return static_cast<char32_t>(xtd::bit_converter::to_int32(bytes, index));
  }
  
  static size_t get_byte_count(int32_t codepoint) noexcept {
    return 4;
  }

  static std::vector<xtd::byte_t> to_bytes(uint32_t codepoint) {
    std::vector<xtd::byte_t> result;
    for (auto b : xtd::bit_converter::get_bytes(codepoint))
        result.push_back(b);
    return result;
  }
  
};

using namespace std;
using namespace xtd;

class xtd_core_manual_test : public object {
public:
  static void main() {
    console::write_line("Hello, World!");
    version v(1, 2, 3);
    console::write_line("v = {}", v);
    object& o = v;
    console::write_line("o = {}", o);
  }
};

startup_(xtd_core_manual_test);
