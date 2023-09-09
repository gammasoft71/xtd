#include "../../include/xtd/guid.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/format_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/guid.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;

const guid guid::empty;

guid::guid(const std::vector<xtd::byte>& data) : data_(data) {
  if (data.size() != data_.size()) throw xtd::argument_exception(ustring::format("Vector size must be {}", data_.size()), csf_);
}

guid::guid(const std::initializer_list<xtd::byte>& data) : data_(data) {
  if (data.size() != data_.size()) throw xtd::argument_exception(ustring::format("Vector size must be {}", data_.size()), csf_);
}

guid::guid(int32 a, int16 b, int16 c, const std::vector<xtd::byte>& d) : guid(static_cast<uint32>(a), static_cast<uint16>(b), static_cast<uint16>(c), d) {
}

guid::guid(uint32 a, uint16 b, uint16 c, const std::vector<xtd::byte>& d) {
  if (d.size() != data_.size() - 8) throw xtd::argument_exception(ustring::format("Vector size must be {}", data_.size() - 8), csf_);
  
  auto index = 0U;
  data_[index++] = static_cast<xtd::byte>((a & 0xFF000000) >> 24);
  data_[index++] = static_cast<xtd::byte>((a & 0x00FF0000) >> 16);
  data_[index++] = static_cast<xtd::byte>((a & 0x0000FF00) >> 8);
  data_[index++] = static_cast<xtd::byte>((a & 0x000000FF) >> 0);
  data_[index++] = static_cast<xtd::byte>((b & 0xFF00) >> 8);
  data_[index++] = static_cast<xtd::byte>((b & 0x00FF) >> 0);
  data_[index++] = static_cast<xtd::byte>((c & 0xFF00) >> 8);
  data_[index++] = static_cast<xtd::byte>((c & 0x00FF) >> 0);
  
  for (; index < data_.size(); ++index)
    data_[index] = d[index - 8];
}

guid::guid(int32 a, int16 b, int16 c, xtd::byte d, xtd::byte e, xtd::byte f, xtd::byte g, xtd::byte h, xtd::byte i, xtd::byte j, xtd::byte k) noexcept : guid(static_cast<uint32>(a), static_cast<uint16>(b), static_cast<uint16>(c), d, e, f, g, h, i, j, k) {
}

guid::guid(uint32 a, uint16 b, uint16 c, xtd::byte d, xtd::byte e, xtd::byte f, xtd::byte g, xtd::byte h, xtd::byte i, xtd::byte j, xtd::byte k) noexcept {
  auto index = 0U;
  data_[index++] = static_cast<xtd::byte>((a & 0xFF000000) >> 24);
  data_[index++] = static_cast<xtd::byte>((a & 0x00FF0000) >> 16);
  data_[index++] = static_cast<xtd::byte>((a & 0x0000FF00) >> 8);
  data_[index++] = static_cast<xtd::byte>((a & 0x000000FF) >> 0);
  data_[index++] = static_cast<xtd::byte>((b & 0xFF00) >> 8);
  data_[index++] = static_cast<xtd::byte>((b & 0x00FF) >> 0);
  data_[index++] = static_cast<xtd::byte>((c & 0xFF00) >> 8);
  data_[index++] = static_cast<xtd::byte>((c & 0x00FF) >> 0);
  data_[index++] = d;
  data_[index++] = e;
  data_[index++] = f;
  data_[index++] = g;
  data_[index++] = h;
  data_[index++] = i;
  data_[index++] = j;
  data_[index++] = k;
}

guid::guid(const ustring& guid) {
  ustring simple = guid.replace("0x", "").replace(",", "").replace("-", "").replace("(", "").replace(")", "").replace("{", "").replace("}", "");
  for (auto index = 0U; index < data_.size(); ++index) {
    data_[index] = xtd::parse<xtd::byte>(simple.substring(0, 2), xtd::number_styles::hex_number);
    simple = simple.remove(0, 2);
  }
}

int32 guid::compare_to(const guid& value) const noexcept {
  for (auto index = 0U; index < data_.size(); ++index)
    if (data_[index] > value.data_[index]) return 1;
    else if (data_[index] < value.data_[index]) return -1;
  return 0;
}

bool guid::equals(const guid& g) const noexcept {
  for (auto index = 0U; index < data_.size(); ++index)
    if (data_[index] != g.data_[index]) return false;
  return true;
}

guid guid::new_guid() noexcept {
  return guid(native::guid::new_guid());
}

const std::vector<xtd::byte>& guid::to_byte_array() const noexcept {
  return data_;
}

xtd::ustring guid::to_string() const noexcept {
  return to_string("D");
}

ustring guid::to_string(ustring format) const {
  format = format.empty() ? "d" : format.to_lower();
  
  if (format.size() != 1 || ustring("ndbpx").index_of(format) == ustring::npos)
    throw xtd::format_exception {csf_};
    
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
