#include "../../../include/xtd/globalization/number_format_info.hpp"
#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/helpers/throw_helper.hpp"
#include "../../../include/xtd/io/binary_reader.hpp"
#include "../../../include/xtd/collections/generic/dictionary.hpp"
#include "../../../include/xtd/call_once.hpp"
#include "../../../include/xtd/environment.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::globalization;
using namespace xtd::helpers;
using namespace xtd::io;

struct number_format_info::data {
  int32 currency_decimal_digits = 2;
  string currency_decimal_separator = ".";
  string currency_group_separator = ",";
  array<int32> currency_group_sizes = {3};
  int32 currency_negative_pattern = 0;
  int32 currency_positive_pattern = 0;
  string currency_symbol = "¤";
  int32 digit_substitution = 1;
  string nan_symbol = "NaN";
  string negative_infinity_symbol = "-Infinity";
  string negative_sign = "-";
  int32 number_decimal_digits = 2;
  string number_decimal_separator = ".";
  string number_group_separator = ",";
  array<int32> number_group_sizes = {3};
  int32 number_negative_pattern = 1;
  int32 percent_decimal_digits = 2;
  string percent_decimal_separator = ".";
  string percent_group_separator = ",";
  array<int32> percent_group_sizes = {3};
  int32 percent_negative_pattern = 0;
  int32 percent_positive_pattern = 0;
  string percent_symbol = "%";
  string per_mille_symbol = "‰";
  string positive_infinity_symbol = "Infinity";
  string positive_sign = "+";
};

number_format_info::number_format_info() : data_ {new_ptr<data>()} {
}

number_format_info::number_format_info(const number_format_info& info) : number_format_info {} {
  *data_ = *info.data_;
}

auto number_format_info::currency_decimal_digits() const noexcept -> int32 {
  return data_->currency_decimal_digits;
}

auto number_format_info::currency_decimal_digits(int32 value) noexcept -> number_format_info& {
  data_->currency_decimal_digits = value;
  return self_;
}

auto number_format_info::currency_decimal_separator() const noexcept -> const string& {
  return data_->currency_decimal_separator;
}

auto number_format_info::currency_decimal_separator(const string& value) noexcept -> number_format_info& {
  data_->currency_decimal_separator = value;
  return self_;
}

auto number_format_info::currency_group_separator() const noexcept -> const string& {
  return data_->currency_group_separator;
}

auto number_format_info::currency_group_separator(const string& value) noexcept -> number_format_info& {
  data_->currency_group_separator = value;
  return self_;
}

auto number_format_info::currency_group_sizes() const noexcept -> const array<int32>& {
  return data_->currency_group_sizes;
}

auto number_format_info::currency_group_sizes(const array<int32>& value) noexcept -> number_format_info& {
  data_->currency_group_sizes = value;
  return self_;
}

auto number_format_info::currency_negative_pattern() const noexcept -> int32 {
  return data_->currency_negative_pattern;
}

auto number_format_info::currency_negative_pattern(int32 value) noexcept -> number_format_info& {
  data_->currency_negative_pattern = value;
  return self_;
}

auto number_format_info::currency_positive_pattern() const noexcept -> int32 {
  return data_->currency_positive_pattern;
}

auto number_format_info::currency_positive_pattern(int32 value) noexcept -> number_format_info& {
  data_->currency_positive_pattern = value;
  return self_;
}

auto number_format_info::currency_symbol() const noexcept -> const string& {
  return data_->currency_symbol;
}

auto number_format_info::currency_symbol(const string& value) noexcept -> number_format_info& {
  data_->currency_symbol = value;
  return self_;
}

auto number_format_info::digit_substitution() const noexcept -> int32 {
  return data_->digit_substitution;
}

auto number_format_info::digit_substitution(int32 value) noexcept -> number_format_info& {
  data_->digit_substitution = value;
  return self_;
}

auto number_format_info::nan_symbol() const noexcept -> const string& {
  return data_->nan_symbol;
}

auto number_format_info::nan_symbol(const string& value) noexcept -> number_format_info& {
  data_->nan_symbol = value;
  return self_;
}

auto number_format_info::negative_infinity_symbol() const noexcept -> const string& {
  return data_->negative_infinity_symbol;
}

auto number_format_info::negative_infinity_symbol(const string& value) noexcept -> number_format_info& {
  data_->negative_infinity_symbol = value;
  return self_;
}

auto number_format_info::negative_sign() const noexcept -> const string& {
  return data_->negative_sign;
}

auto number_format_info::negative_sign(const string& value) noexcept -> number_format_info& {
  data_->negative_sign = value; return self_;
}

auto number_format_info::number_decimal_digits() const noexcept -> int32 {
  return data_->number_decimal_digits;
}

auto number_format_info::number_decimal_digits(int32 value) noexcept -> number_format_info& {
  data_->number_decimal_digits = value;
  return self_;
}

auto number_format_info::number_decimal_separator() const noexcept -> const string& {
  return data_->number_decimal_separator;
}

auto number_format_info::number_decimal_separator(const string& value) noexcept -> number_format_info& {
  data_->number_decimal_separator = value;
  return self_;
}

auto number_format_info::number_group_separator() const noexcept -> const string& {
  return data_->number_group_separator;
}

auto number_format_info::number_group_separator(const string& value) noexcept -> number_format_info& {
  data_->number_group_separator = value;
  return self_;
}

auto number_format_info::number_group_sizes() const noexcept -> const array<int32>& {
  return data_->number_group_sizes;
}

auto number_format_info::number_group_sizes(const array<int32>& value) noexcept -> number_format_info& {
  data_->number_group_sizes = value;
  return self_;
}

auto number_format_info::number_negative_pattern() const noexcept -> int32 {
  return data_->number_negative_pattern;
}

auto number_format_info::number_negative_pattern(int32 value) noexcept -> number_format_info& {
  data_->number_negative_pattern = value;
  return self_;
}

auto number_format_info::percent_decimal_digits() const noexcept -> int32 {
  return data_->percent_decimal_digits;
}

auto number_format_info::percent_decimal_digits(int32 value) noexcept -> number_format_info& {
  data_->percent_decimal_digits = value;
  return self_;
}

auto number_format_info::percent_decimal_separator() const noexcept -> const string& {
  return data_->percent_decimal_separator;
}

auto number_format_info::percent_decimal_separator(const string& value) noexcept -> number_format_info& {
  data_->percent_decimal_separator = value;
  return self_;
}

auto number_format_info::percent_group_separator() const noexcept -> const string& {
  return data_->percent_group_separator;
}

auto number_format_info::percent_group_separator(const string& value) noexcept -> number_format_info& {
  data_->percent_group_separator = value;
  return self_;
}

auto number_format_info::percent_group_sizes() const noexcept -> const array<int32>& {
  return data_->percent_group_sizes;
}

auto number_format_info::percent_group_sizes(const array<int32>& value) noexcept -> number_format_info& {
  data_->percent_group_sizes = value;
  return self_;
}

auto number_format_info::percent_negative_pattern() const noexcept -> int32 {
  return data_->percent_negative_pattern;
}

auto number_format_info::percent_negative_pattern(int32 value) noexcept -> number_format_info& {
  data_->percent_negative_pattern = value;
  return self_;
}

auto number_format_info::percent_positive_pattern() const noexcept -> int32 {
  return data_->percent_positive_pattern;
}

auto number_format_info::percent_positive_pattern(int32 value) noexcept -> number_format_info& {
  data_->percent_positive_pattern = value;
  return self_;
}

auto number_format_info::percent_symbol() const noexcept -> const string& {
  return data_->percent_symbol;
}

auto number_format_info::percent_symbol(const string& value) noexcept -> number_format_info& {
  data_->percent_symbol = value;
  return self_;
}

auto number_format_info::per_mille_symbol() const noexcept -> const string& {
  return data_->per_mille_symbol;
}

auto number_format_info::per_mille_symbol(const string& value) noexcept -> number_format_info& {
  data_->per_mille_symbol = value;
  return self_;
}

auto number_format_info::positive_infinity_symbol() const noexcept -> const string& {
  return data_->positive_infinity_symbol;
}

auto number_format_info::positive_infinity_symbol(const string& value) noexcept -> number_format_info& {
  data_->positive_infinity_symbol = value;
  return self_;
}

auto number_format_info::positive_sign() const noexcept -> const string& {
  return data_->positive_sign;
}

auto number_format_info::positive_sign(const string& value) noexcept -> number_format_info& {
  data_->positive_sign = value;
  return self_;
}

auto number_format_info::operator=(const number_format_info& info) -> number_format_info& {
  *data_ = *info.data_;
  return self_;
}

auto number_format_info::current_info() noexcept -> const number_format_info& {
  return culture_info::current_culture().number_format();
}

auto number_format_info::invariant_info() noexcept -> const number_format_info& {
  return culture_info::invariant_culture().number_format();
}

number_format_info::number_format_info(int32 currency_decimal_digits, xtd::string&& currency_decimal_separator, xtd::string&& currency_group_separator, xtd::array<int32>&& currency_group_sizes, int32 currency_negative_pattern, int32 currency_positive_pattern, xtd::string&& currency_symbol, int32 digit_substitution, xtd::string&& nan_symbol, xtd::string&& negative_infinity_symbol, xtd::string&& negative_sign, int32 number_decimal_digits, xtd::string&& number_decimal_separator, xtd::string&& number_group_separator, xtd::array<int32>&& number_group_sizes, int32 number_negative_pattern, int32 percent_decimal_digits, xtd::string&& percent_decimal_separator, xtd::string&& percent_group_separator, xtd::array<int32>&& percent_group_sizes, int32 percent_negative_pattern, int32 percent_positive_pattern, xtd::string&& percent_symbol, xtd::string&& per_mille_symbol, xtd::string&& positive_infinity_symbol, xtd::string&& positive_sign) : number_format_info {} {
  data_->currency_decimal_digits = currency_decimal_digits;
  data_->currency_decimal_separator = std::move(currency_decimal_separator);
  data_->currency_group_separator = std::move(currency_group_separator);
  data_->currency_group_sizes = std::move(currency_group_sizes);
  data_->currency_negative_pattern = currency_negative_pattern;
  data_->currency_positive_pattern = currency_positive_pattern;
  data_->currency_symbol = std::move(currency_symbol);
  data_->digit_substitution = digit_substitution;
  data_->nan_symbol = std::move(nan_symbol);
  data_->negative_infinity_symbol = std::move(negative_infinity_symbol);
  data_->negative_sign = std::move(negative_sign);
  data_->number_decimal_digits = number_decimal_digits;
  data_->number_decimal_separator = std::move(number_decimal_separator);
  data_->number_group_separator = std::move(number_group_separator);
  data_->number_group_sizes = std::move(number_group_sizes);
  data_->number_negative_pattern = number_negative_pattern;
  data_->percent_decimal_digits = percent_decimal_digits;
  data_->percent_decimal_separator = std::move(percent_decimal_separator);
  data_->percent_group_separator = std::move(percent_group_separator);
  data_->percent_group_sizes = std::move(percent_group_sizes);
  data_->percent_negative_pattern = percent_negative_pattern;
  data_->percent_positive_pattern = percent_positive_pattern;
  data_->percent_symbol = std::move(percent_symbol);
  data_->per_mille_symbol = std::move(per_mille_symbol);
  data_->positive_infinity_symbol = std::move(positive_infinity_symbol);
  data_->positive_sign = std::move(positive_sign);
}

auto number_format_info::formats() -> dictionary<string, number_format_info>& {
  static auto formats = dictionary<string, number_format_info> {{"", {}}, {"en-us", {2, ".", ",", array<int32> {3}, 1, 0, "$", 1, "NaN", "-∞", "-", 3, ".", ",", array<int32> {3}, 1, 3, ".", ",", array<int32> {3}, 1, 1, "%", "‰", "∞", "+"}}};
  call_once_ {
    auto read_int32s = [](auto & br, auto count) {
      auto ints = array<int32>(as<size>(count));
      for (auto i = 0; i < count; ++i)
        ints[i] = br.read_int32();
      return ints;
    };
    auto file = path::combine({environment::get_folder_path(environment::special_folder::xtd_install), "share", "xtd", "data", "number_formats.bin"});
    if (!file::exists(file)) return;
    auto br = binary_reader{file};
    if (br.read_bytes(8) != array<byte>{'X', 'T', 'D', 0, 'N', 'U', 'M', 'F'}) throw_helper::throws(exception_case::format, "The file does not contain the signature 'XTD\\0NUMF'.");
    if (br.read_int32() > 1) throw_helper::throws(exception_case::format, "The file version is not supported");
    auto count = br.read_int32();
    for (auto i = 0; i < count; ++i) {
      auto key = br.read_string();
      formats[key] = number_format_info {br.read_int32(), br.read_string(), br.read_string(), read_int32s(br, br.read_int32()), br.read_int32(), br.read_int32(), br.read_string(), br.read_int32(), br.read_string(), br.read_string(), br.read_string(), br.read_int32(), br.read_string(), br.read_string(), read_int32s(br, br.read_int32()), br.read_int32(), br.read_int32(), br.read_string(), br.read_string(), read_int32s(br, br.read_int32()), br.read_int32(), br.read_int32(), br.read_string(), br.read_string(), br.read_string(), br.read_string()};
    }
  };
  return formats;
}
