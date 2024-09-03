cmake_minimum_required(VERSION 3.20)

project(xtd.core.examples)
find_package(xtd REQUIRED)

add_projects(
  hello_worlds
  any
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
  guid
  hash_code
  interfaces
  io
  keywords
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
  sprintf
  startups
  strings
  text
  threading
  time_span
  timers
  uri
  version
  web
  others
  tests
)

