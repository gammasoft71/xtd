#include "../../include/xtd/as.h"
#include "../../include/xtd/guid.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/format_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/guid>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;

const guid guid::empty;

guid::guid(const std::vector<xtd::byte>& data) : data_(data) {
  if (data.size() != data_.size()) throw argument_exception(string::format("Vector size must be {}", data_.size()));
}

guid::guid(const std::initializer_list<xtd::byte>& data) : data_(data) {
  if (data.size() != data_.size()) throw argument_exception(string::format("Vector size must be {}", data_.size()));
}

guid::guid(int32 a, int16 b, int16 c, const std::vector<xtd::byte>& d) : guid(as<uint32>(a), as<uint16>(b), as<uint16>(c), d) {
}

guid::guid(uint32 a, uint16 b, uint16 c, const std::vector<xtd::byte>& d) {
  if (d.size() != data_.size() - 8) throw argument_exception(string::format("Vector size must be {}", data_.size() - 8));
  
  auto index = 0_z;
  data_[index++] = as<xtd::byte>((a & 0xFF000000) >> 24);
  data_[index++] = as<xtd::byte>((a & 0x00FF0000) >> 16);
  data_[index++] = as<xtd::byte>((a & 0x0000FF00) >> 8);
  data_[index++] = as<xtd::byte>((a & 0x000000FF) >> 0);
  data_[index++] = as<xtd::byte>((b & 0xFF00) >> 8);
  data_[index++] = as<xtd::byte>((b & 0x00FF) >> 0);
  data_[index++] = as<xtd::byte>((c & 0xFF00) >> 8);
  data_[index++] = as<xtd::byte>((c & 0x00FF) >> 0);
  
  for (; index < data_.size(); ++index)
    data_[index] = d[index - 8];
}

guid::guid(int32 a, int16 b, int16 c, xtd::byte d, xtd::byte e, xtd::byte f, xtd::byte g, xtd::byte h, xtd::byte i, xtd::byte j, xtd::byte k) noexcept : guid(as<uint32>(a), as<uint16>(b), as<uint16>(c), d, e, f, g, h, i, j, k) {
}

guid::guid(uint32 a, uint16 b, uint16 c, xtd::byte d, xtd::byte e, xtd::byte f, xtd::byte g, xtd::byte h, xtd::byte i, xtd::byte j, xtd::byte k) noexcept {
  auto index = 0_z;
  data_[index++] = as<xtd::byte>((a & 0xFF000000) >> 24);
  data_[index++] = as<xtd::byte>((a & 0x00FF0000) >> 16);
  data_[index++] = as<xtd::byte>((a & 0x0000FF00) >> 8);
  data_[index++] = as<xtd::byte>((a & 0x000000FF) >> 0);
  data_[index++] = as<xtd::byte>((b & 0xFF00) >> 8);
  data_[index++] = as<xtd::byte>((b & 0x00FF) >> 0);
  data_[index++] = as<xtd::byte>((c & 0xFF00) >> 8);
  data_[index++] = as<xtd::byte>((c & 0x00FF) >> 0);
  data_[index++] = d;
  data_[index++] = e;
  data_[index++] = f;
  data_[index++] = g;
  data_[index++] = h;
  data_[index++] = i;
  data_[index++] = j;
  data_[index++] = k;
}

guid::guid(const string& guid) {
  auto simple = guid.replace("0x", string::empty_string).replace(",", string::empty_string).replace("-", string::empty_string).replace("(", string::empty_string).replace(")", string::empty_string).replace("{", string::empty_string).replace("}", string::empty_string);
  for (auto index = 0_z; index < data_.size(); ++index) {
    data_[index] = parse<xtd::byte>(simple.substring(0, 2), number_styles::hex_number);
    simple = simple.remove(0, 2);
  }
}

int32 guid::compare_to(const guid& value) const noexcept {
  for (auto index = 0_z; index < data_.size(); ++index)
    if (data_[index] > value.data_[index]) return 1;
    else if (data_[index] < value.data_[index]) return -1;
  return 0;
}

bool guid::equals(const guid& g) const noexcept {
  for (auto index = 0_z; index < data_.size(); ++index)
    if (data_[index] != g.data_[index]) return false;
  return true;
}

guid guid::new_guid() noexcept {
  return guid(native::guid::new_guid());
}

const std::vector<xtd::byte>& guid::to_byte_array() const noexcept {
  return data_;
}

string guid::to_string() const noexcept {
  return to_string("D");
}

string guid::to_string(const string& format) const {
  return to_string(format, std::locale {});
}

string guid::to_string(const string& format, const std::locale& loc) const {
  auto fmt = format.empty() ? "d" : format.to_lower();
  
  if (fmt.size() != 1 || string("ndbpx").index_of(fmt) == string::npos) throw format_exception {};
    
  auto hyphens = fmt != "n" && fmt != "x";
  auto braces = fmt == "b";
  auto parentheses = fmt == "p";
  auto hexadecimal = fmt == "x";
  
  auto result = string::empty_string;
  for (auto index = 0_z; index < data_.size(); ++index) {
    if (hexadecimal && (index == 4 || index == 6 || (index >= 8 && index <= 15))) result += ",";
    if (hexadecimal && (index == 0 || index == 8)) result += "{";
    if (hexadecimal && (index == 0 || index == 4 || index == 6 || (index >= 8 && index <= 15))) result += "0x";
    result += xtd::to_string(data_[index], "x2").c_str();
    if (hexadecimal && index == 15) result += "}}";
    if (hyphens && (index == 3 || index == 5 || index == 7 || index == 9)) result += "-";
  }
  
  if (braces) result = "{" + result + "}";
  if (parentheses) result = "(" + result + ")";
    
  return result;
}
