cmake_minimum_required(VERSION 3.20)

project(globalization)
find_package(xtd REQUIRED)

add_projects(
  culture_info_culture_types
  culture_info_current_culture
  culture_info_date_time_format
  culture_info_is_neutral_culture
  culture_info_lcid
  culture_info_parent
  culture_info_properties
  culture_info_with_name
  date_time_format_info
)
