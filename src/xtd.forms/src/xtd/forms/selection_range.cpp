#include "../../../include/xtd/forms/selection_range.h"

using namespace xtd;
using namespace xtd::forms;

selection_range::selection_range(time_point start, time_point end) : start_(start), end_(end) {
}

selection_range::time_point selection_range::end() const {
  return end_;
}

void selection_range::end(selection_range::time_point value) {
  end_ = value;
}

void selection_range::end(time_t value) {
  end(std::chrono::system_clock::from_time_t(value));
}

void selection_range::end(const std::tm& value) {
  std::tm internal_max_date = value;
  end(mktime(&internal_max_date));
}

void selection_range::end(int32_t year, int32_t month, int32_t day) {
  std::tm internal_max_date = {};
  internal_max_date.tm_year = year - 1900;
  internal_max_date.tm_mon = month - 1;
  internal_max_date.tm_mday = day;
  end(std::mktime(&internal_max_date));
}

void selection_range::end(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm internal_date = {};
  internal_date.tm_year = year - 1900;
  internal_date.tm_mon = month - 1;
  internal_date.tm_mday = day;
  internal_date.tm_hour = hour;
  internal_date.tm_min = minute;
  internal_date.tm_sec = second;
  end(std::mktime(&internal_date));
}

selection_range::time_point selection_range::start() const {
  return start_;
}

void selection_range::start(selection_range::time_point value) {
  start_ = value;
}

void selection_range::start(time_t value) {
  start(std::chrono::system_clock::from_time_t(value));
}

void selection_range::start(const std::tm& value) {
  std::tm internal_max_date = value;
  start(mktime(&internal_max_date));
}

void selection_range::start(int32_t year, int32_t month, int32_t day) {
  std::tm internal_max_date = {};
  internal_max_date.tm_year = year - 1900;
  internal_max_date.tm_mon = month - 1;
  internal_max_date.tm_mday = day;
  start(std::mktime(&internal_max_date));
}

void selection_range::start(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm internal_date = {};
  internal_date.tm_year = year - 1900;
  internal_date.tm_mon = month - 1;
  internal_date.tm_mday = day;
  internal_date.tm_hour = hour;
  internal_date.tm_min = minute;
  internal_date.tm_sec = second;
  start(std::mktime(&internal_date));
}