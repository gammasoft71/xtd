cmake_minimum_required(VERSION 3.20)

project(date_time)
find_package(xtd REQUIRED)

add_projects(
  date_time
  date_time_add
  date_time_add_days
  date_time_add_hours
  date_time_add_milliseconds
  date_time_add_minutes
  date_time_add_months
  date_time_add_seconds
  date_time_add_years
  date_time_date
  date_time_day_of_week
  date_time_day_of_year
  date_time_days_in_month
  date_time_days_in_month2
  date_time_max_value
  date_time_min_value
  date_time_now
  date_time_now2
  date_time_specify_kind
  date_time_sprintf
  date_time_subtract
  date_time_ticks
  date_time_ticks2
  date_time_time_of_day
  date_time_today
  date_time_to_string_format
)

