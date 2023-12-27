cmake_minimum_required(VERSION 3.20)

# Project
project(locale)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

add_projects(
  ar
  ar_MA
  en
  en_AU
  en_CA
  en_GB
  en_IE
  en_NZ
  en_US
  en_ZA
  fr
  fr_CA
  fr_CH
  zh
  zh_CN
  zh_TW
)
