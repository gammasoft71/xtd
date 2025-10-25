#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Get the properties of an en-US date_time_format_info object.
  auto dtfi = culture_info::get_culture_info("en-US").date_time_format();
  using property_info = std::tuple<string, delegate<const string&()>>;
  auto props = array<property_info> {{"full_date_time_pattern", {dtfi, &date_time_format_info::full_date_time_pattern}}, {"long_date_pattern", {dtfi, &date_time_format_info::long_date_pattern}}, {"long_time_pattern", {dtfi, &date_time_format_info::long_time_pattern}}, {"month_day_pattern", {dtfi, &date_time_format_info::month_day_pattern}}, {"rfc_1123_pattern", {dtfi, &date_time_format_info::rfc_1123_pattern}}, {"short_date_pattern", {dtfi, &date_time_format_info::short_date_pattern}}, {"short_time_pattern", {dtfi, &date_time_format_info::short_time_pattern}}, {"sortable_date_time_pattern", {dtfi, &date_time_format_info::sortable_date_time_pattern}}, {"universal_sortable_date_time_pattern", {dtfi, &date_time_format_info::universal_sortable_date_time_pattern}}, {"year_month_pattern", {dtfi, &date_time_format_info::year_month_pattern}}};
  auto value  = date_time {2012, 5, 28, 11, 35, 0};
  
  for (const auto& [name, pattern] : props)
    console::write_line("{,-37} {} \n{,-41}Example: {}\n", name, pattern(), "", value.to_string(pattern()));
}

// This code produces the following output :
//
// full_date_time_pattern                dddd, MMMM d, yyyy h:mm:ss tt
//                                          Example: Monday, May 28, 2012 11:35:00 AM
//
// long_date_pattern                     dddd, MMMM d, yyyy
//                                          Example: Monday, May 28, 2012
//
// long_time_pattern                     h:mm:ss tt
//                                          Example: 11:35:00 AM
//
// month_day_pattern                     MMMM d
//                                          Example: May 28
//
// rfc_1123_pattern                      ddd, dd MMM yyyy HH':'mm':'ss 'GMT'
//                                          Example: Mon, 28 May 2012 11:35:00 GMT
//
// short_date_pattern                    M/d/yyyy
//                                          Example: 5/28/2012
//
// short_time_pattern                    h:mm tt
//                                          Example: 11:35 AM
//
// sortable_date_time_pattern            yyyy'-'MM'-'dd'T'HH':'mm':'ss
//                                          Example: 2012-05-28T11:35:00
//
// universal_sortable_date_time_pattern  yyyy'-'MM'-'dd HH':'mm':'ss'Z'
//                                          Example: 2012-05-28 11:35:00Z
//
// year_month_pattern                    MMMM yyyy
//                                          Example: May 2012
//
