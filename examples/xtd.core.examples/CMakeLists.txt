cmake_minimum_required(VERSION 3.20)

project(xtd.core.examples)
find_package(xtd REQUIRED)

add_projects(
  hello_worlds
  any
  array
  bit_converter
  boxing
  collections
  configuration
  console
  convert
  date_time
  delegates
  diagnostics
  environment
  enumerations
  exceptions
  format
  generic_collections
  globalization
  guid
  hash_code
  interfaces
  io
  keywords
  linq
  mains
  math
  media
  memory_information
  network
  object
  object_model_collections
  parse
  processes
  random
  ranges
  span
  specialized_collections
  sprintf
  startups
  strings
  text
  threading
  time_span
  timers
  tips_and_tricks
  uri
  version
  web
  others
  tests
)

