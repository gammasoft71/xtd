#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../include/xtd/as.h"
#include "../include/xtd/is.h"
#include "../include/xtd/time_zone_info.h"
#include "../include/xtd/time_zone_not_found_exception.h"
#include "../include/xtd/chrono.h"
#include <list>

using namespace std;
using namespace std::chrono;
using namespace xtd;

uint32 time_zone_info::transition_time::day() const noexcept {
  return day_;
}

xtd::day_of_week time_zone_info::transition_time::day_of_week() const noexcept {
  return day_of_week_;
}

bool time_zone_info::transition_time::is_fixed_rule() const noexcept {
  return is_fixed_date_rule_;
}

uint32 time_zone_info::transition_time::month() const noexcept {
  return month_;
}

xtd::date_time time_zone_info::transition_time::time_of_day() const noexcept {
  return time_of_day_;
}

uint32 time_zone_info::transition_time::week() const noexcept {
  return week_;
}

time_zone_info::transition_time time_zone_info::transition_time::create_fixed_date_rule(date_time time_of_day, uint32 month, uint32 day) {
  if (time_of_day.year() != 1 || time_of_day.month() != 1 || time_of_day.day() != 1 || time_of_day.kind() != date_time_kind::unspecified) throw argument_exception {csf_};
  if (month < 1 || month > 12 || day < 1 || day > 31) throw argument_out_of_range_exception {csf_};
  auto result = transition_time {};
  result.day_ = day;
  result.is_fixed_date_rule_ = false;
  result.month_ = month;
  result.time_of_day_ = time_of_day;
  return result;
}

time_zone_info::transition_time time_zone_info::transition_time::create_floating_date_rule(date_time time_of_day, uint32 month, uint32 week, xtd::day_of_week day_of_week) {
  if (time_of_day.year() != 1 || time_of_day.month() != 1 || time_of_day.day() != 1 || time_of_day.kind() != date_time_kind::unspecified) throw argument_exception {csf_};
  if (month < 1 || month > 12 || week < 1 || week > 5) throw argument_out_of_range_exception {csf_};
  auto result = transition_time {};
  result.day_of_week_ = day_of_week;
  result.is_fixed_date_rule_ = false;
  result.month_ = month;
  result.time_of_day_ = time_of_day;
  result.week_ = week;
  return result;
}

bool time_zone_info::transition_time::equals(const time_zone_info::transition_time& tt) const noexcept {
  return day_ == tt.day_ && day_of_week_ == tt.day_of_week_ && is_fixed_date_rule_ == tt.is_fixed_date_rule_ && month_ == tt.month_ && time_of_day_ == tt.time_of_day_ && week_ == tt.week_;
}

const xtd::date_time& time_zone_info::adjustement_rule::date_end() const noexcept {
  return date_end_;
}

const xtd::date_time& time_zone_info::adjustement_rule::date_start() const noexcept {
  return date_start_;
}

xtd::time_span time_zone_info::adjustement_rule::daylight_delta() const noexcept {
  return xtd::time_span {daylight_delta_};
}

time_zone_info::transition_time time_zone_info::adjustement_rule::daylight_transition_end() const noexcept {
  return daylight_transition_end_;
}

time_zone_info::transition_time time_zone_info::adjustement_rule::daylight_transition_start() const noexcept {
  return daylight_transition_start_;
}

bool time_zone_info::adjustement_rule::equals(const adjustement_rule& ar) const noexcept {
  return date_end_ == ar.date_end_ && date_start_ == ar.date_start_ && daylight_delta_ == ar.daylight_delta_ && daylight_transition_end_ == ar.daylight_transition_end_ && daylight_transition_start_ == ar.daylight_transition_start_;
}

time_zone_info::time_zone_info(const ustring& id, const ticks& base_utc_offset, const ustring& daylight_name, const ustring& display_name, const ustring& standard_name, bool supports_daylight_saving_time) : id_(id), base_utc_offset_(base_utc_offset), daylight_name_(daylight_name), display_name_(display_name), standard_name_(standard_name), supports_daylight_saving_time_(supports_daylight_saving_time) {
}

ticks time_zone_info::base_utc_offset() const noexcept {
  return base_utc_offset_;
}

const ustring& time_zone_info::daylight_name() const noexcept {
  return daylight_name_;
}

const ustring& time_zone_info::display_name() const noexcept {
  return display_name_;
}

const ustring& time_zone_info::id() const noexcept {
  return id_;
}

const time_zone_info& time_zone_info::local() noexcept {
  static auto local_time_zone = time_zone_info {};
  if (ustring::is_empty(local_time_zone.id_)) {
    auto tzi = native::date_time::get_local_time_zone();
    local_time_zone.id_ = tzi.id;
    local_time_zone.base_utc_offset_ = ticks(tzi.base_utc_offset);
    local_time_zone.daylight_name_ = tzi.daylight_name;
    local_time_zone.display_name_ = tzi.display_name;
    local_time_zone.standard_name_ = tzi.standard_name;
    local_time_zone.supports_daylight_saving_time_ = tzi.supports_daylight_saving_time;
  }
  return local_time_zone;
}

const ustring& time_zone_info::standard_name() const noexcept {
  return standard_name_;
}

bool time_zone_info::supports_daylight_saving_time() const noexcept {
  return supports_daylight_saving_time_;
}

const time_zone_info& time_zone_info::utc() noexcept {
  static auto utc_time_zone = time_zone_info {"UTC", ticks(0), "UTC", "UTC", "UTC", false};
  return utc_time_zone;
}

xtd::date_time time_zone_info::convert_time_to_utc(const xtd::date_time& date_time) {
  /// @Todo revue convert_to_utc
  /// Get utc offset
  if (date_time.kind() == date_time_kind::utc) return date_time;
  
  return xtd::date_time::specify_kind(date_time.to_universal_time(), date_time_kind::utc);
}

const list<time_zone_info>& time_zone_info::get_system_time_zones() noexcept {
  static auto system_time_zones = list<time_zone_info> {};
  if (system_time_zones.size()) return system_time_zones;
  auto stzs = native::date_time::get_system_time_zones();
  for_each(stzs.begin(), stzs.end(), [&](auto item) {system_time_zones.emplace_back(time_zone_info(item.id, ticks(item.base_utc_offset), item.daylight_name, item.display_name, item.standard_name, item.supports_daylight_saving_time));});
  return system_time_zones;
}

int32 time_zone_info::compare_to(const time_zone_info& tzi) const noexcept {
  return id_.compare_to(tzi.id_);
}

xtd::date_time time_zone_info::convert_time(const xtd::date_time& date_time, const xtd::time_zone_info& destination_time_zone) {
  return {};
}

xtd::date_time time_zone_info::convert_time(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone, const xtd::time_zone_info& destination_time_zone) {
  return {};
}

xtd::date_time time_zone_info::convert_time_by_system_time_zone_id(const xtd::date_time& date_time, const xtd::ustring& destination_time_zone_id) {
  return {};
}

xtd::date_time time_zone_info::convert_time_by_system_time_zone_id(const xtd::date_time& date_time, const xtd::ustring& source_time_zone_id, const xtd::ustring& destination_time_zone_id) {
  return {};
}

xtd::date_time time_zone_info::convert_from_utc(const xtd::date_time& date_time, const xtd::time_zone_info& destination_time_zone) {
  return {};
}

xtd::date_time time_zone_info::convert_to_utc(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone) {
  if (date_time.kind() == date_time_kind::utc) return date_time;
  
  auto daylight_saving_time_offset = ticks {0};
  if (source_time_zone.supports_daylight_saving_time() && source_time_zone.is_daylight_saving_time(date_time))
    daylight_saving_time_offset = duration_cast<ticks>(hours(1));
    
  auto offset_local = -(source_time_zone.base_utc_offset() + daylight_saving_time_offset);
  
  if (date_time.ticks_duration() < offset_local)
    return xtd::date_time(date_time.ticks(), date_time_kind::utc);
    
  return xtd::date_time(date_time.ticks_duration() - offset_local, date_time_kind::utc);
}

xtd::date_time time_zone_info::convert_to_utc(const xtd::date_time& date_time) {
  return convert_to_utc(date_time, local());
}

bool time_zone_info::equals(const time_zone_info& tzi) const noexcept {
  return id_.equals(tzi.id_);
}

std::vector<time_zone_info::adjustement_rule> time_zone_info::get_adjustement_rules() const noexcept {
  return adjustement_rules_;
}

bool time_zone_info::is_daylight_saving_time(const xtd::date_time& date_time) const noexcept {
  if (date_time.kind() != date_time_kind::local || !supports_daylight_saving_time()) return false;
  return false;
}

time_zone_info time_zone_info::time_find_system_time_zone_by_id(const ustring& id) {
  if (local().id_ == id) return local();
  if (utc().id_ == id) return utc();
  
  auto stzs = get_system_time_zones();
  auto iterator = find_if(stzs.begin(), stzs.end(), [&](auto item) {return item.id_ == id;});
  if (iterator != stzs.end()) return *iterator;
  
  throw time_zone_not_found_exception {csf_};
}

ustring time_zone_info::to_string() const noexcept {
  return ustring::format("time_zone_info [id=\"{}\", base_utc_offset={}, daylight_name=\"{}\", display_name\"{}\", standard_name=\"{}\", supports_daylight_saving_time={}]", id(), base_utc_offset(), daylight_name(), display_name(), standard_name(), supports_daylight_saving_time());
}
