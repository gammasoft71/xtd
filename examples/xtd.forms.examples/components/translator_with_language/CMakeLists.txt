cmake_minimum_required(VERSION 3.20)

project(translator_with_language)
find_package(xtd REQUIRED)
add_sources(
  src/translator_with_language.cpp
  locale/ar/locale.strings
  locale/fr/locale.strings
  locale/ru/locale.strings
  locale/en/locale.strings
  locale/es/locale.strings
)

target_type(GUI_APPLICATION)
