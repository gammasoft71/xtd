#include <xtd/xtd>

auto main() -> int {
  println("Command line arguments = {}", environment::get_command_line_args());
  println();
  println("Assembly : ");
  println("  Company = {}", reflection::assembly::get_executing_assembly().company());
  println("  Configuration = {}", reflection::assembly::get_executing_assembly().configuration());
  println("  Copyright = {}", reflection::assembly::get_executing_assembly().copyright());
  println("  Culture = {}", reflection::assembly::get_executing_assembly().culture());
  println("  Description = {}", reflection::assembly::get_executing_assembly().description());
  println("  File name = {}", reflection::assembly::get_executing_assembly().file_name());
  println("  File version = {}", reflection::assembly::get_executing_assembly().file_version());
  println("  Guid = {}", reflection::assembly::get_executing_assembly().guid());
  println("  Identifier = {}", reflection::assembly::get_executing_assembly().identifier());
  println("  Location = {}", reflection::assembly::get_executing_assembly().location());
  println("  Location path = {}", reflection::assembly::get_executing_assembly().location_path());
  println("  Name = {}", reflection::assembly::get_executing_assembly().name());
  println("  Product = {}", reflection::assembly::get_executing_assembly().product());
  println("  Title = {}", reflection::assembly::get_executing_assembly().title());
  println("  Trademarks = {}", reflection::assembly::get_executing_assembly().trademarks());
  println("  Version = {}", reflection::assembly::get_executing_assembly().version());
}

// This code produces the following output :
//
// Command line arguments = [./xtd.core.manual_tests, One, Two, Three Four, Five]
//
// Assembly :
//   Company = Gammasoft
//   Configuration = Test
//   Copyright = Copyright © Gammasoft 2026
//   Culture = en-US
//   Description = xtd.core.manual_tests contains xtd.core manual tests.
//   File name = xtd.core.manual_tests
//   File version =
//   Guid = f2a4ddf2-75ca-4967-8b19-950337aa088d
//   Identifier =
//   Localtion = /Users/gammasoft71/Projects/xtd/build/tests/xtd.core.manual_tests/Debug/xtd.core.manual_tests
//   Location path = /Users/gammasoft71/Projects/xtd/build/tests/xtd.core.manual_tests/Debug
//   Name =
//   Product = xtd.core.manual_tests
//   Title = xtd.core.manual_tests
//   Trademarks =
//   Version = 0.2.0
