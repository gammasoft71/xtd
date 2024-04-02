#include "../../../include/xtd/forms/month_calendar.h"
#include "../../../include/xtd/forms/application.h"
#include <xtd/diagnostics/debug>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/month_calendar>
#include <xtd/forms/native/month_calendar_styles>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct month_calendar::data {
  std::vector<xtd::date_time> annually_bolded_dates;
  std::vector<xtd::date_time> bolded_dates;
  xtd::drawing::size calendar_dimensions = {1, 1};
  xtd::forms::day first_day_of_week = xtd::forms::day::default_day;
  xtd::date_time min_date = date_time::min_value;
  date_time max_date = date_time::max_value;
  uint32 max_selection_count = 7;
  std::vector<xtd::date_time> monthly_bolded_dates;
  xtd::date_time selection_start = date_time::now();
  xtd::date_time selection_end = date_time::now();
  mutable xtd::drawing::size single_month_size = {225, 143};
  bool show_today = true;
  bool show_today_circle = true;
  bool show_week_numbers = false;
  std::optional<xtd::drawing::color> title_back_color;
  std::optional<xtd::drawing::color> title_fore_color;
  xtd::date_time today_date = xtd::date_time::now();
  bool today_date_set = false;
  std::optional<xtd::drawing::color> trailing_fore_color;
};

xtd::forms::month_calendar::hit_area month_calendar::hit_test_info::hit_area() const noexcept {
  return hit_area_;
}

/// @brief Gets the point that was hit-tested.
/// @return A xtd::drawing::point containing the xtd::drawing::point::x and xtd::drawing::point::y values tested.
const xtd::drawing::point& month_calendar::hit_test_info::point() const noexcept {
  return point_;
}

/// @brief Gets the time information specific to the location that was hit-tested.
/// @return The time information specific to the location that was hit-tested.
/// @remarks The xtd::forms::month_calendar::hit_test_info::time property contains a valid date when the xtd::forms::month_calendar::hit_area property is set to xtd::forms::month_calendar::hit_area::date or xtd::forms::month_calendar::hit_area::week_numbers.
const xtd::date_time& month_calendar::hit_test_info::time() const noexcept {
  return time_;
}

month_calendar::hit_test_info::hit_test_info(xtd::forms::month_calendar::hit_area hit_area, const xtd::drawing::point& point, const xtd::date_time& time) : hit_area_(hit_area), point_(point), time_(time) {
}

month_calendar::month_calendar() : data_(std::make_shared<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint, false);
  set_style(control_styles::standard_click, false);
}

std::vector<xtd::date_time> month_calendar::annually_bolded_dates() const noexcept {
  return data_->annually_bolded_dates;
}

month_calendar& month_calendar::annually_bolded_dates(const std::vector<xtd::date_time>& value) {
  if (data_->annually_bolded_dates == value) return *this;
  data_->annually_bolded_dates = value;
  native::month_calendar::annually_bolded_dates(handle(), data_->annually_bolded_dates);
  return *this;
}

std::vector<xtd::date_time> month_calendar::bolded_dates() const noexcept {
  return data_->bolded_dates;
}

month_calendar& month_calendar::bolded_dates(const std::vector<xtd::date_time>& value) {
  if (data_->bolded_dates == value) return *this;
  data_->bolded_dates = value;
  native::month_calendar::bolded_dates(handle(), data_->bolded_dates);
  return *this;
}

const xtd::drawing::size& month_calendar::calendar_dimensions() const noexcept {
  return data_->calendar_dimensions;
}

month_calendar& month_calendar::calendar_dimensions(const xtd::drawing::size& value) {
  if (data_->calendar_dimensions == value) return *this;
  data_->calendar_dimensions = value;
  native::month_calendar::bolded_dates(handle(), data_->bolded_dates);
  return *this;
}

xtd::forms::day month_calendar::first_day_of_week() const noexcept {
  return data_->first_day_of_week;
}
month_calendar& month_calendar::first_day_of_week(xtd::forms::day value) {
  if (data_->first_day_of_week == value) return *this;
  data_->first_day_of_week = value;
  native::month_calendar::first_day_of_week(handle(), static_cast<uint32>(data_->first_day_of_week));
  return *this;
}

date_time month_calendar::max_date() const noexcept {
  return data_->max_date;
}

month_calendar& month_calendar::max_date(date_time value) {
  if (data_->max_date == value) return *this;
  data_->max_date = value;
  if (data_->max_date < data_->min_date) data_->min_date = data_->max_date;
  if (is_handle_created()) native::month_calendar::allowable_dates(handle(), data_->min_date, data_->max_date);
  selection_start(data_->selection_start);
  selection_end(data_->selection_end);
  return *this;
}

uint32 month_calendar::max_selection_count() const noexcept {
  return data_->max_selection_count;
}

month_calendar& month_calendar::max_selection_count(uint32 value) {
  if (data_->max_selection_count == value) return *this;
  data_->max_selection_count = value;
  native::month_calendar::max_selection_count(handle(), data_->max_selection_count);
  return *this;
}

date_time month_calendar::min_date() const noexcept {
  return data_->min_date;
}

month_calendar& month_calendar::month_calendar::min_date(date_time value) {
  if (data_->min_date == value) return *this;
  data_->min_date = value;
  if (data_->max_date < data_->min_date) data_->max_date = data_->min_date;
  if (is_handle_created()) native::month_calendar::allowable_dates(handle(), data_->min_date, data_->max_date);
  selection_start(data_->selection_start);
  selection_end(data_->selection_end);
  return *this;
}

std::vector<xtd::date_time> month_calendar::monthly_bolded_dates() const noexcept {
  return data_->monthly_bolded_dates;
}

month_calendar& month_calendar::monthly_bolded_dates(const std::vector<xtd::date_time>& value) {
  if (data_->monthly_bolded_dates == value) return *this;
  data_->monthly_bolded_dates = value;
  native::month_calendar::monthly_bolded_dates(handle(), data_->monthly_bolded_dates);
  return *this;
}

date_time month_calendar::selection_end() const noexcept {
  return data_->selection_end;
}

month_calendar& month_calendar::selection_end(date_time value) {
  if (value < data_->min_date) value = data_->min_date;
  if (value > data_->max_date) value = data_->max_date;
  if (data_->selection_end == value) return *this;
  data_->selection_end = value;
  if (is_handle_created()) native::month_calendar::selection_range(handle(), data_->selection_start, data_->selection_end);
  on_date_selected(date_range_event_args(data_->selection_start, data_->selection_end));
  return *this;
}

date_time month_calendar::selection_start() const noexcept {
  return data_->selection_start;
}

month_calendar& month_calendar::selection_start(date_time value) {
  if (value < data_->min_date) value = data_->min_date;
  if (value > data_->max_date) value = data_->max_date;
  if (data_->selection_start == value) return *this;
  data_->selection_start = value;
  if (is_handle_created()) native::month_calendar::selection_range(handle(), data_->selection_start, data_->selection_end);
  on_date_selected(date_range_event_args(data_->selection_start, data_->selection_end));
  return *this;
}

forms::selection_range month_calendar::selection_range() const noexcept {
  return {data_->selection_start, data_->selection_end};
}

month_calendar& month_calendar::selection_range(const forms::selection_range& value) {
  data_->selection_start = value.start();
  data_->selection_end = value.end();
  return *this;
}

bool month_calendar::show_today() const noexcept {
  return data_->show_today;
}

month_calendar& month_calendar::show_today(bool value) {
  if (data_->show_today == value) return *this;
  data_->show_today = value;
  post_recreate_handle();
  return *this;
}

bool month_calendar::show_today_circle() const noexcept {
  return data_->show_today_circle;
}

month_calendar& month_calendar::show_today_circle(bool value) {
  if (data_->show_today_circle == value) return *this;
  data_->show_today_circle = value;
  post_recreate_handle();
  return *this;
}

bool month_calendar::show_week_numbers() const noexcept {
  return data_->show_week_numbers;
}

month_calendar& month_calendar::show_week_numbers(bool value) {
  if (data_->show_week_numbers == value) return *this;
  data_->show_week_numbers = value;
  post_recreate_handle();
  return *this;
}

drawing::size month_calendar::single_month_size() const noexcept {
  data_->single_month_size = native::month_calendar::single_month_size(handle());
  return data_->single_month_size;
}

xtd::drawing::color month_calendar::title_back_color() const noexcept {
  return data_->title_back_color.value_or(application::style_sheet().system_colors().active_caption());
}

month_calendar& month_calendar::title_back_color(const xtd::drawing::color& value) {
  if (data_->title_back_color == value) return *this;
  data_->title_back_color = value;
  native::month_calendar::title_back_color(handle(), title_back_color());
  return *this;
}

xtd::drawing::color month_calendar::title_fore_color() const noexcept {
  return data_->title_fore_color.value_or(application::style_sheet().system_colors().active_caption_text());
}

month_calendar& month_calendar::title_fore_color(const xtd::drawing::color& value) {
  if (data_->title_fore_color == value) return *this;
  data_->title_fore_color = value;
  native::month_calendar::title_fore_color(handle(), title_fore_color());
  return *this;
}

const xtd::date_time& month_calendar::today_date() const noexcept {
  return data_->today_date;
}

month_calendar& month_calendar::today_date(const xtd::date_time& value) {
  if (data_->today_date == value) return *this;
  data_->today_date = value;
  data_->today_date_set = true;
  return *this;
}

bool month_calendar::today_date_set() const noexcept {
  return data_->today_date_set;
}

xtd::drawing::color month_calendar::trailing_fore_color() const noexcept {
  return data_->trailing_fore_color.value_or(application::style_sheet().system_colors().gray_text());
}

month_calendar& month_calendar::trailing_fore_color(const xtd::drawing::color& value) {
  if (data_->trailing_fore_color == value) return *this;
  data_->trailing_fore_color = value;
  native::month_calendar::trailing_fore_color(handle(), trailing_fore_color());
  return *this;
}

void month_calendar::add_annually_bolded_date(const xtd::date_time& date) {
  data_->annually_bolded_dates.push_back(date);
}

void month_calendar::add_bolded_date(const xtd::date_time& date) {
  data_->bolded_dates.push_back(date);
}

void month_calendar::add_monthly_bolded_date(const xtd::date_time& date) {
  data_->monthly_bolded_dates.push_back(date);
}

month_calendar month_calendar::create() {
  return  month_calendar {};
}

month_calendar month_calendar::create(const drawing::point& location) {
  auto result = month_calendar {};
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const drawing::point& location) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& max_date) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.max_date(max_date);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& max_date, const drawing::point& location) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.max_date(max_date);
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar month_calendar::create(const control& parent) {
  auto result = month_calendar {};
  result.parent(parent);
  return result;
}

month_calendar month_calendar::create(const control& parent, const drawing::point& location) {
  auto result = month_calendar {};
  result.parent(parent);
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const drawing::point& location) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& max_date) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.max_date(max_date);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& max_date, const drawing::point& location) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.max_date(max_date);
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  return result;
}

month_calendar month_calendar::create(const control& parent, const forms::selection_range& selection_range, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = month_calendar {};
  result.parent(parent);
  result.selection_range(selection_range);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

month_calendar::hit_test_info month_calendar::hit_test(int32 x, int32 y) const {
  return hit_test({x, y});
}

month_calendar::hit_test_info month_calendar::hit_test(const xtd::drawing::point& point) const {
  auto [hit_area, time] = native::month_calendar::hit_test(handle(), point);
  return month_calendar::hit_test_info(static_cast<month_calendar::hit_area>(hit_area), point, time);
}

void month_calendar::remove_all_annually_bolded_dates() {
  data_->annually_bolded_dates.clear();
}

void month_calendar::remove_all_bolded_dates() {
  data_->bolded_dates.clear();
}

void month_calendar::remove_all_monthly_bolded_dates() {
  data_->monthly_bolded_dates.clear();
}

void month_calendar::remove_annually_bolded_dates(const xtd::date_time& date) {
  auto it = find(data_->annually_bolded_dates.begin(), data_->annually_bolded_dates.end(), date);
  if (it != data_->annually_bolded_dates.end()) data_->annually_bolded_dates.erase(it);
}

void month_calendar::remove_bolded_dates(const xtd::date_time& date) {
  auto it = find(data_->bolded_dates.begin(), data_->bolded_dates.end(), date);
  if (it != data_->bolded_dates.end()) data_->bolded_dates.erase(it);
}

void month_calendar::remove_monthly_bolded_dates(const xtd::date_time& date) {
  auto it = find(data_->monthly_bolded_dates.begin(), data_->monthly_bolded_dates.end(), date);
  if (it != data_->monthly_bolded_dates.end()) data_->monthly_bolded_dates.erase(it);
}

void month_calendar::set_calendar_dimensions(int32 x, int32 y) {
  calendar_dimensions({x, y});
}

void month_calendar::set_date(const xtd::date_time& date) {
  selection_start(date);
  selection_end(date);
}

void month_calendar::set_selection_range(const xtd::date_time& date1, const xtd::date_time& date2) {
  selection_start(date1);
  selection_end(date2);
}

xtd::ustring month_calendar::to_string() const noexcept {
  return ustring::format("{}, SelectionRange: Start: {:d}, End: {:d}", control::to_string(), data_->selection_start, data_->selection_end);
}

void month_calendar::update_bolded_dates() {
  native::month_calendar::annually_bolded_dates(handle(), data_->annually_bolded_dates);
  native::month_calendar::bolded_dates(handle(), data_->bolded_dates);
  native::month_calendar::monthly_bolded_dates(handle(), data_->bolded_dates);
}

xtd::drawing::color month_calendar::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

xtd::drawing::color month_calendar::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

forms::create_params month_calendar::create_params() const noexcept {
  auto create_params = control::create_params();
  create_params.class_name("monthcalendar");
  
  if (!data_->show_today) create_params.style(create_params.style() | MCS_NOTODAY);
  if (!data_->show_today_circle) create_params.style(create_params.style() | MCS_NOTODAYCIRCLE);
  if (data_->show_week_numbers) create_params.style(create_params.style() | MCS_WEEKNUMBERS);
  
  return create_params;
}

unique_ptr<xtd::object> month_calendar::clone() const {
  auto result = make_unique<month_calendar>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}

void month_calendar::on_date_changed(const date_range_event_args& e) {
  if (can_raise_events()) date_changed(*this, e);
}

void month_calendar::on_date_selected(const date_range_event_args& e) {
  if (can_raise_events()) date_selected(*this, e);
}

void month_calendar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::month_calendar::allowable_dates(handle(), data_->min_date, data_->max_date);
  native::month_calendar::first_day_of_week(handle(), static_cast<uint32>(data_->first_day_of_week));
  native::month_calendar::max_selection_count(handle(), data_->max_selection_count);
  native::month_calendar::selection_range(handle(), data_->selection_start, data_->selection_end);
  native::month_calendar::today_date(handle(), data_->today_date);
  native::month_calendar::title_back_color(handle(), title_back_color());
  native::month_calendar::title_fore_color(handle(), title_fore_color());
  native::month_calendar::trailing_fore_color(handle(), trailing_fore_color());
  update_bolded_dates();
  single_month_size();
}

void month_calendar::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_NOTIFY: wm_notify_control(message); break;
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP:
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_XBUTTONDBLCLK: def_wnd_proc(message); break; // Mouse events are not supported
    default: control::wnd_proc(message);
  }
}

void month_calendar::wm_notify_control(message& message) {
  auto nmhdr = reinterpret_cast<NMHDR*>(message.lparam());
  switch (nmhdr->code) {
    case MCN_SELECT: wm_date_selected(message); break;
    case MCN_SELCHANGE: wm_date_changed(message); break;
    case MCN_VIEWCHANGE: wm_view_changed(message); break;
    default: break;
  }
}

void month_calendar::wm_date_selected(message& message) {
  auto range = native::month_calendar::selection_range(handle());
  data_->selection_start = range.first;
  data_->selection_end = range.second;
  on_date_selected(date_range_event_args(data_->selection_start, data_->selection_end));
}

void month_calendar::wm_date_changed(message& message) {
  auto range = native::month_calendar::selection_range(handle());
  data_->selection_start = range.first;
  data_->selection_end = range.second;
  on_date_changed(date_range_event_args(data_->selection_start, data_->selection_end));
}

void month_calendar::wm_view_changed(message& message) {
  // Do something or not if view changed
}
