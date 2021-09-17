#include "../../include/xtd/guid.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/format_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/guid.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;

const guid guid::empty;

guid::guid(const std::vector<byte_t>& data) : data_(data) {
  if (data.size() != 16) throw xtd::argument_exception("Vector size must be 16", current_stack_frame_);
}

guid::guid(const std::initializer_list<byte_t>& data) : data_(data) {
  if (data.size() != 16) throw xtd::argument_exception("Vector size must be 16", current_stack_frame_);
}

guid::guid(int a, int b, int c, const std::vector<byte_t>& d) {
  if (d.size() != 8) throw xtd::argument_exception("Vector size must be 8", current_stack_frame_);
  
  data_[0] = static_cast<byte_t>((a & 0xFF000000) >> 24);
  data_[1] = static_cast<byte_t>((a & 0x00FF0000) >> 16);
  data_[2] = static_cast<byte_t>((a & 0x0000FF00) >> 8);
  data_[3] = static_cast<byte_t>((a & 0x000000FF) >> 0);
  data_[4] = static_cast<byte_t>((b & 0xFF00) >> 8);
  data_[5] = static_cast<byte_t>((b & 0x00FF) >> 0);
  data_[6] = static_cast<byte_t>((c & 0xFF00) >> 8);
  data_[7] = static_cast<byte_t>((c & 0x00FF) >> 0);
  
  for (int index = 0; index < 8; index++)
    data_[8 + index] = d[index];
}

guid::guid(int a, short b, short c, byte_t d, byte_t e, byte_t f, byte_t g, byte_t h, byte_t i, byte_t j, byte_t k) noexcept {
  data_[0] = static_cast<byte_t>((a & 0xFF000000) >> 24);
  data_[1] = static_cast<byte_t>((a & 0x00FF0000) >> 16);
  data_[2] = static_cast<byte_t>((a & 0x0000FF00) >> 8);
  data_[3] = static_cast<byte_t>((a & 0x000000FF) >> 0);
  data_[4] = static_cast<byte_t>((b & 0xFF00) >> 8);
  data_[5] = static_cast<byte_t>((b & 0x00FF) >> 0);
  data_[6] = static_cast<byte_t>((c & 0xFF00) >> 8);
  data_[7] = static_cast<byte_t>((c & 0x00FF) >> 0);
  data_[8] = d;
  data_[9] = e;
  data_[10] = f;
  data_[11] = g;
  data_[12] = h;
  data_[13] = i;
  data_[14] = j;
  data_[15] = k;
}

guid::guid(uint32_t a, uint16_t b, uint16_t c, byte_t d, byte_t e, byte_t f, byte_t g, byte_t h, byte_t i, byte_t j, byte_t k) noexcept {
  data_[0] = static_cast<byte_t>((a & 0xFF000000) >> 24);
  data_[1] = static_cast<byte_t>((a & 0x00FF0000) >> 16);
  data_[2] = static_cast<byte_t>((a & 0x0000FF00) >> 8);
  data_[3] = static_cast<byte_t>((a & 0x000000FF) >> 0);
  data_[4] = static_cast<byte_t>((b & 0xFF00) >> 8);
  data_[5] = static_cast<byte_t>((b & 0x00FF) >> 0);
  data_[6] = static_cast<byte_t>((c & 0xFF00) >> 8);
  data_[7] = static_cast<byte_t>((c & 0x00FF) >> 0);
  data_[8] = d;
  data_[9] = e;
  data_[10] = f;
  data_[11] = g;
  data_[12] = h;
  data_[13] = i;
  data_[14] = j;
  data_[15] = k;
}

guid::guid(const ustring& guid) {
  ustring simple = guid.replace("0x", "").replace(",", "").replace("-", "").replace("(", "").replace(")", "").replace("{", "").replace("}", "");
  for (size_t i = 0; i < data_.size(); i ++) {
    data_[i] = xtd::parse<byte_t>(simple.substring(0, 2), xtd::number_styles::hex_number);
    simple = simple.remove(0, 2);
  }
}

int32_t guid::compare_to(const object& obj) const noexcept {
  if (!dynamic_cast<const guid*>(&obj)) return 1;
  return compare_to(static_cast<const guid&>(obj));
}

/// @brief Compares the current instance with another object of the same type.
/// @param obj An object to compare with this instance.
/// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
/// The return value has these meanings:
/// | Value             | Condition                          |
/// |-------------------|------------------------------------|
/// | Less than zero    | This instance is less than obj.    |
/// | Zero              | This instance is equal to obj.     |
/// | Greater than zero | This instance is greater than obj. |
int32_t guid::compare_to(const guid& value) const noexcept {
  for (size_t i = 0; i < data_.size(); i++)
    if (data_[i] > value.data_[i]) return 1;
    else if (data_[i] < value.data_[i]) return -1;
  return 0;
}

bool guid::equals(const object& g) const noexcept {
  return dynamic_cast<const guid*>(&g) && equals(static_cast<const guid&>(g));
}

bool guid::equals(const guid& g) const noexcept {
  for (size_t index = 0; index < 16; index++)
    if (data_[index] != g.data_[index]) return false;
  return true;
}

guid guid::new_guid() noexcept {
  return guid(native::guid::new_guid());
}

const std::vector<byte_t>& guid::to_byte_array() const noexcept {
  return data_;
}

xtd::ustring guid::to_string() const noexcept {
  return to_string("D");
}

ustring guid::to_string(ustring format) const {
  format = format.empty() ? "d" : format.to_lower();
  
  if (format.size() != 1 || ustring("ndbpx").index_of(format) == ustring::npos)
    throw xtd::format_exception(current_stack_frame_);
  
  bool hyphens = format != "n" && format != "x";
  bool braces = format == "b";
  bool parentheses = format == "p";
  bool hexadecimal = format == "x";
  
  ustring result;
  for (size_t index = 0; index < data_.size(); index++) {
    if (hexadecimal && (index == 4 || index == 6 || (index >= 8 && index <= 15)))
      result += ",";
    if (hexadecimal && (index == 0 || index == 8))
      result += "{";
    if (hexadecimal && (index == 0 || index == 4 || index == 6 || (index >= 8 && index <= 15)))
      result += "0x";
    result += xtd::to_string(data_[index], "x2");
    if (hexadecimal && index == 15)
      result += "}}";
    if (hyphens && (index == 3 || index == 5 || index == 7 || index == 9))
      result += "-";
  }
  
  if (braces)
    result = "{" + result + "}";
  if (parentheses)
    result = "(" + result + ")";
  
  return result;
}
