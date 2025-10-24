#include "../../../include/xtd/globalization/culture_info.hpp"
#include "../../../include/xtd/globalization/date_time_format_info.hpp"
#include "../../../include/xtd/helpers/throw_helper"
#include "../../../include/xtd/io/binary_reader.hpp"
#include "../../../include/xtd/collections/generic/dictionary.hpp"
#include "../../../include/xtd/call_once.hpp"
#include "../../../include/xtd/day_of_week.hpp"
#include "../../../include/xtd/environment.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::globalization;
using namespace xtd::helpers;
using namespace xtd::io;

struct date_time_format_info::data {
  array<string> abreviated_day_names = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  array<string> abreviated_month_genitive_names = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", ""};
  array<string> abreviated_month_names = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", ""};
  string am_designator = "AM";
  string date_separator = "/";
  array<string> day_names = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  day_of_week first_day_of_week = day_of_week::sunday;
  string full_date_time_pattern = "dddd, dd MMMM yyyy HH:mm:ss";
  string long_date_pattern = "dddd, dd MMMM yyyy";
  string long_time_pattern = "HH:mm:ss";
  string month_day_pattern = "MMMM dd";
  array<string> month_genitive_names = {"January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December", ""};
  array<string> month_names = {"January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December", ""};
  string native_calendar_name = "Gregorian Calendar";
  string pm_designator = "PM";
  string rfc_1123_pattern = "ddd, dd MMM yyyy HH':'mm':'ss 'GMT'";
  string short_date_pattern = "MM/dd/yyyy";
  string short_time_pattern = "HH:mm";
  array<string> shortest_day_names = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
  string sortable_date_time_pattern = "yyyy'-'MM'-'dd'T'HH':'mm':'ss";
  string time_separator = ":";
  string universal_sortable_date_time_pattern = "yyyy'-'MM'-'dd HH':'mm':'ss'Z'";
  string year_month_pattern = "yyyy MMMM";
};

date_time_format_info::date_time_format_info() : data_ {new_ptr<data>()} {
}

date_time_format_info::date_time_format_info(const date_time_format_info& info) : date_time_format_info() {
  *data_ = *info.data_;
}

const array<string>& date_time_format_info::abreviated_day_names() const noexcept {
  return data_->abreviated_day_names;
}

date_time_format_info& date_time_format_info::abreviated_day_names(const array<string>& value) noexcept {
  data_->abreviated_day_names = value;
  return self_;
}

const array<string>& date_time_format_info::abreviated_month_genitive_names() const noexcept {
  return data_->abreviated_month_genitive_names;
}

date_time_format_info& date_time_format_info::abreviated_month_genitive_names(const array<string>& value) noexcept {
  data_->abreviated_month_genitive_names = value;
  return self_;
}

const array<string>& date_time_format_info::abreviated_month_names() const noexcept {
  return data_->abreviated_month_names;
}

date_time_format_info& date_time_format_info::abreviated_month_names(const array<string>& value) noexcept {
  data_->abreviated_month_names = value;
  return self_;
}

const xtd::string& date_time_format_info::am_designator() const noexcept {
  return data_->am_designator;
}

date_time_format_info& date_time_format_info::am_designator(const xtd::string& value) noexcept {
  data_->am_designator = value;
  return self_;
}

const xtd::string& date_time_format_info::date_separator() const noexcept {
  return data_->date_separator;
}

date_time_format_info& date_time_format_info::date_separator(const xtd::string& value) noexcept {
  data_->date_separator = value;
  return self_;
}

const array<string>& date_time_format_info::day_names() const noexcept {
  return data_->day_names;
}

date_time_format_info& date_time_format_info::day_names(const array<string>& value) noexcept {
  data_->day_names = value;
  return self_;
}

day_of_week date_time_format_info::first_day_of_week() const noexcept {
  return data_->first_day_of_week;
}

date_time_format_info& date_time_format_info::first_day_of_week(day_of_week value) noexcept {
  data_->first_day_of_week = value;
  return self_;
}

const string& date_time_format_info::full_date_time_pattern() const noexcept {
  return data_->full_date_time_pattern;
}

date_time_format_info& date_time_format_info::full_date_time_pattern(const string& value) noexcept {
  data_->full_date_time_pattern = value;
  return self_;
}

const string& date_time_format_info::long_date_pattern() const noexcept {
  return data_->long_date_pattern;
}

date_time_format_info& date_time_format_info::long_date_pattern(const string& value) noexcept {
  data_->long_date_pattern = value;
  return self_;
}

const string& date_time_format_info::long_time_pattern() const noexcept {
  return data_->long_time_pattern;
}

date_time_format_info& date_time_format_info::long_time_pattern(const string& value) noexcept {
  data_->long_time_pattern = value;
  return self_;
}

const string& date_time_format_info::month_day_pattern() const noexcept {
  return data_->month_day_pattern;
}

date_time_format_info& date_time_format_info::month_day_pattern(const string& value) noexcept {
  data_->month_day_pattern = value;
  return self_;
}

const array<string>& date_time_format_info::month_genitive_names() const noexcept {
  return data_->month_genitive_names;
}

date_time_format_info& date_time_format_info::month_genitive_names(const array<string>& value) noexcept {
  data_->month_genitive_names = value;
  return self_;
}

const array<string>& date_time_format_info::month_names() const noexcept {
  return data_->month_names;
}

date_time_format_info& date_time_format_info::month_names(const array<string>& value) noexcept {
  data_->month_names = value;
  return self_;
}

const xtd::string& date_time_format_info::native_calendar_name() const noexcept {
  return data_->native_calendar_name;
}

date_time_format_info& date_time_format_info::native_calendar_name(const xtd::string& value) noexcept {
  data_->native_calendar_name = value;
  return self_;
}

const xtd::string& date_time_format_info::pm_designator() const noexcept {
  return data_->pm_designator;
}

date_time_format_info& date_time_format_info::pm_designator(const xtd::string& value) noexcept {
  data_->pm_designator = value;
  return self_;
}

const xtd::string& date_time_format_info::rfc_1123_pattern() const noexcept {
  return data_->rfc_1123_pattern;
}

date_time_format_info& date_time_format_info::rfc_1123_pattern(const xtd::string& value) noexcept {
  data_->rfc_1123_pattern = value;
  return self_;
}

const string& date_time_format_info::short_date_pattern() const noexcept {
  return data_->short_date_pattern;
}

date_time_format_info& date_time_format_info::short_date_pattern(const string& value) noexcept {
  data_->short_date_pattern = value;
  return self_;
}

const string& date_time_format_info::short_time_pattern() const noexcept {
  return data_->short_time_pattern;
}

date_time_format_info& date_time_format_info::short_time_pattern(const string& value) noexcept {
  data_->short_time_pattern = value;
  return self_;
}

const array<string>& date_time_format_info::shortest_day_names() const noexcept {
  return data_->shortest_day_names;
}

date_time_format_info& date_time_format_info::shortest_day_names(const array<string>& value) noexcept {
  data_->shortest_day_names = value;
  return self_;
}

const string& date_time_format_info::sortable_date_time_pattern() const noexcept {
  return data_->sortable_date_time_pattern;
}

date_time_format_info& date_time_format_info::sortable_date_time_pattern(const string& value) noexcept {
  data_->sortable_date_time_pattern = value;
  return self_;
}

const xtd::string& date_time_format_info::time_separator() const noexcept {
  return data_->time_separator;
}

date_time_format_info& date_time_format_info::time_separator(const xtd::string& value) noexcept {
  data_->time_separator = value;
  return self_;
}

const string& date_time_format_info::universal_sortable_date_time_pattern() const noexcept {
  return data_->universal_sortable_date_time_pattern;
}

date_time_format_info& date_time_format_info::universal_sortable_date_time_pattern(const string& value) noexcept {
  data_->universal_sortable_date_time_pattern = value;
  return self_;
}

const string& date_time_format_info::year_month_pattern() const noexcept {
  return data_->year_month_pattern;
}

date_time_format_info& date_time_format_info::year_month_pattern(const string& value) noexcept {
  data_->year_month_pattern = value;
  return self_;
}

const date_time_format_info& date_time_format_info::current_info() noexcept {
  return culture_info::current_culture().date_time_format();
}

const date_time_format_info& date_time_format_info::invariant_info() noexcept {
  return culture_info::invariant_culture().date_time_format();
}

date_time_format_info& date_time_format_info::operator =(const date_time_format_info& info) {
  *data_ = *info.data_;
  return self_;
}

date_time_format_info::date_time_format_info(array<string>&& abreviated_day_names, array<string>&& abreviated_month_genitive_names, array<string>&& abreviated_month_names, string&& am_designator, string&& date_separator, array<string>&& day_names, day_of_week first_day_of_week, string&& full_date_time_pattern, string&& long_date_pattern, string&& long_time_pattern, string&& month_day_pattern, array<string>&& month_genitive_names, array<string>&& month_names, string&& native_calendar_name, string&& pm_designator, string&& rfc_1123_pattern, string&& short_date_pattern, string&& short_time_pattern, array<string>&& shortest_day_names, string&& sortable_date_time_pattern, string&& time_separator, string&& universal_sortable_date_time_pattern, string&& year_month_pattern) : date_time_format_info() {
  data_->abreviated_day_names = std::move(abreviated_day_names);
  data_->abreviated_month_genitive_names = std::move(abreviated_month_genitive_names);
  data_->abreviated_month_names = std::move(abreviated_month_names);
  data_->am_designator = std::move(am_designator);
  data_->date_separator = std::move(date_separator);
  data_->day_names = std::move(day_names);
  data_->first_day_of_week = first_day_of_week;
  data_->full_date_time_pattern = std::move(full_date_time_pattern);
  data_->long_date_pattern = std::move(long_date_pattern);
  data_->long_time_pattern = std::move(long_time_pattern);
  data_->month_day_pattern = std::move(month_day_pattern);
  data_->month_genitive_names = std::move(month_genitive_names);
  data_->month_names = std::move(month_names);
  data_->native_calendar_name = std::move(native_calendar_name);
  data_->pm_designator = std::move(pm_designator);
  data_->rfc_1123_pattern = std::move(rfc_1123_pattern);
  data_->short_date_pattern = std::move(short_date_pattern);
  data_->short_time_pattern = std::move(short_time_pattern);
  data_->shortest_day_names = std::move(shortest_day_names);
  data_->sortable_date_time_pattern = std::move(sortable_date_time_pattern);
  data_->time_separator = std::move(time_separator);
  data_->universal_sortable_date_time_pattern = std::move(universal_sortable_date_time_pattern);
  data_->year_month_pattern = std::move(year_month_pattern);
}

dictionary<string, date_time_format_info>& date_time_format_info::formats() {
  static auto formats = dictionary<string, date_time_format_info> {{"", {}}, {"en-us", {array<string> {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}, array<string> {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", ""}, array<string> {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", ""}, "AM", "/", array<string> {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}, xtd::day_of_week::sunday, "dddd, MMMM d, yyyy h:mm:ss tt", "dddd, MMMM d, yyyy", "h:mm:ss tt", "MMMM d", array<string> {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", ""}, array<string> {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", ""}, "Gregorian Calendar", "PM", "ddd, dd MMM yyyy HH':'mm':'ss 'GMT'", "M/d/yyyy", "h:mm tt", array<string> {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"}, "yyyy'-'MM'-'dd'T'HH':'mm':'ss", ":", "yyyy'-'MM'-'dd HH':'mm':'ss'Z'", "MMMM yyyy"}}};
  call_once_ {
    auto read_strings = [](auto & br, auto count) {
      auto strings = list<string> {};
      for (auto i = 0; i < count; ++i)
        strings.add(br.read_string());
      return strings.to_array();
    };
    auto file = path::combine({environment::get_folder_path(environment::special_folder::xtd_install), "share", "xtd", "data", "date_time_formats.bin"});
    if (!file::exists(file)) return;
    auto br = binary_reader {file};
    if (br.read_bytes(8) != array<byte> {'X', 'T', 'D', 0, 'D', 'T', 'F', 'M'}) throw_helper::throws(exception_case::format, "The file does not contain the signature 'XTD\0DTF'.");
    if (br.read_int32() > 1) throw_helper::throws(exception_case::format, "The file version is not supported");
    auto count = br.read_int32();
    for (auto i = 0; i < count; ++i) {
      auto key = br.read_string();
      formats[key] = date_time_format_info {read_strings(br, br.read_int32()), read_strings(br, br.read_int32()), read_strings(br, br.read_int32()), br.read_string(), br.read_string(), read_strings(br, br.read_int32()), as<day_of_week>(br.read_int32()), br.read_string(), br.read_string(), br.read_string(), br.read_string(), read_strings(br, br.read_int32()), read_strings(br, br.read_int32()), br.read_string(), br.read_string(), br.read_string(), br.read_string(), br.read_string(), read_strings(br, br.read_int32()), br.read_string(), br.read_string(), br.read_string(), br.read_string()};
    }
  };
  return formats;
}
