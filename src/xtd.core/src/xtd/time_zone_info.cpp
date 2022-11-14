#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../include/xtd/as.h"
#include "../include/xtd/is.h"
#include "../include/xtd/time_zone_info.h"
#include "../include/xtd/time_zone_not_found_exception.h"
#include <chrono>
#include <list>

using namespace std;
using namespace std::chrono;
using namespace xtd;

time_zone_info::time_zone_info(const ustring& id, const ticks& base_utc_offset, const ustring& daylight_name, const ustring& display_name, const ustring& standard_name, bool supports_daylight_saving_time) : id_(id), base_utc_offset_(base_utc_offset), daylight_name_(daylight_name), display_name_(display_name), standard_name_(standard_name), supports_daylight_saving_time_(supports_daylight_saving_time) {
}

const time_zone_info& time_zone_info::local() {
  static time_zone_info local_time_zone;
  if (ustring::is_empty(local_time_zone.id_)) {
    native::date_time::time_zone_info tzi = native::date_time::get_local_time_zone();
    local_time_zone.id_ = tzi.id;
    local_time_zone.base_utc_offset_ = ticks(tzi.base_utc_offset);
    local_time_zone.daylight_name_ = tzi.daylight_name;
    local_time_zone.display_name_ = tzi.display_name;
    local_time_zone.standard_name_ = tzi.standard_name;
    local_time_zone.supports_daylight_saving_time_ = tzi.supports_daylight_saving_time;
  }
  return local_time_zone;
}

const time_zone_info& time_zone_info::utc() {
  static time_zone_info utc_time_zone("UTC", ticks(0), "UTC", "UTC", "UTC", false);
  return utc_time_zone;
}

xtd::date_time time_zone_info::convert_time_to_utc(const xtd::date_time& date_time) {
  /// @Todo revue convert_to_utc
  /// Get utc offset
  if (date_time.kind() == date_time_kind::utc) return date_time;
  
  return xtd::date_time::specify_kind(date_time.to_universal_time(), date_time_kind::utc);
}


const list<time_zone_info>& time_zone_info::get_system_time_zones() {
  static list<time_zone_info> system_time_zones;
  if (!system_time_zones.size())
    for (auto item : native::date_time::get_system_time_zones())
      system_time_zones.emplace_back(time_zone_info(item.id, ticks(item.base_utc_offset), item.daylight_name, item.display_name, item.standard_name, item.supports_daylight_saving_time));
  return system_time_zones;
}

int32_t time_zone_info::compare_to(const time_zone_info& tzi) const noexcept {
  return id_.compare_to(tzi.id_);
}

int32_t time_zone_info::compare_to(const object& obj) const noexcept {
  return is<time_zone_info>(obj) && compare_to(static_cast<const time_zone_info&>(obj));
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

xtd::date_time time_zone_info::convert_time_by_system_time_zone_id(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone_id, const xtd::time_zone_info& destination_time_zone_id) {
  return {};
}

xtd::date_time time_zone_info::convert_from_utc(const xtd::date_time& date_time, const xtd::time_zone_info& destination_time_zone) {
  return {};
}

xtd::date_time time_zone_info::convert_to_utc(const xtd::date_time& date_time, const xtd::time_zone_info& source_time_zone) {
  if (date_time.kind() == date_time_kind::utc) return date_time;
  
  ticks daylight_saving_time_offset(0);
  if (source_time_zone.supports_daylight_saving_time() && source_time_zone.is_daylight_saving_time(date_time))
    daylight_saving_time_offset = duration_cast<ticks>(hours(1));
    
  ticks offset_local = -(source_time_zone.base_utc_offset() + daylight_saving_time_offset);
  
  if (date_time.ticks() < offset_local)
    return xtd::date_time(date_time.ticks(), date_time_kind::utc);
    
  return xtd::date_time(date_time.ticks() - offset_local, date_time_kind::utc);
}

xtd::date_time time_zone_info::convert_to_utc(const xtd::date_time& date_time) {
  return convert_to_utc(date_time, local());
}

bool time_zone_info::equals(const time_zone_info& tzi) const noexcept {
  return id_.equals(tzi.id_);
}

bool time_zone_info::equals(const object& obj) const noexcept {
  return is<time_zone_info>(obj) && equals(static_cast<const time_zone_info&>(obj));
}

std::vector<time_zone_info::adjustement_rule> time_zone_info::get_adjustement_rules() const {
  return adjustement_rules_;
}

bool time_zone_info::is_daylight_saving_time(const xtd::date_time& date_time) const {
  if (date_time.kind() != date_time_kind::local || !supports_daylight_saving_time()) return false;
  return false;
}

const time_zone_info& time_zone_info::time_find_system_time_zone_by_id(const ustring& id) {
  if (local().id_ == id) return local();
  if (utc().id_ == id) return utc();
  
  for (const time_zone_info& item : get_system_time_zones())
    if (item.id_ == id) return item;
    
  throw time_zone_not_found_exception(csf_);
}

ustring time_zone_info::to_string() const noexcept {
  return ustring::format("time_zone_info [id=\"{}\", base_utc_offset={}, daylight_name=\"{}\", display_name\"{}\", standard_name=\"{}\", supports_daylight_saving_time={}]", id(), base_utc_offset(), daylight_name(), display_name(), standard_name(), supports_daylight_saving_time());
}
