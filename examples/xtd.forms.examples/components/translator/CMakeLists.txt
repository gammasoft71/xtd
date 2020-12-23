cmake_minimum_required(VERSION 3.3)

project(translator)
find_package(xtd REQUIRED)
add_sources(
  src/translator.cpp
  locale/ar/locale.strings
  locale/fr/locale.strings
  locale/ru/locale.strings
  locale/en/locale.strings
  locale/es/locale.strings
)

target_type(GUI_APPLICATION)
