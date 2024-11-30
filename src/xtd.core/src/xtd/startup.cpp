#include "../../include/xtd/environment.hpp"
#include "../../include/xtd/startup.hpp"
#include "../../include/xtd/threading/thread.hpp"
#include <vector>

using namespace xtd;
using namespace xtd::collections::specialized;
using namespace xtd::threading;

void startup::init_safe_run() {
}

void startup::end_safe_run() {
  thread::join_all();
}

int startup::safe_run(xtd::delegate<void()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(xtd::delegate<void()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(xtd::delegate<void(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(xtd::delegate<void(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(xtd::delegate<void(const string_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(xtd::delegate<void(const string_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(xtd::delegate<int()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(xtd::delegate<int()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(xtd::delegate<int(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(xtd::delegate<int(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(xtd::delegate<int(const string_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(xtd::delegate<int(const string_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(void (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(void (*main_function)(const string_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(int (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(int (*main_function)(const string_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(void (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(void (*main_function)(const string_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(int (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(int (*main_function)(const string_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::run(xtd::delegate<void()> main_function, int, char* []) {
  main_function();
  return environment::exit_code();
}

int startup::run(xtd::delegate<void()> main_function) {
  main_function();
  return environment::exit_code();
}

int startup::run(void (*main_function)(), int, char* []) {
  main_function();
  return environment::exit_code();
}

int startup::run(void (*main_function)()) {
  main_function();
  return environment::exit_code();
}

int startup::run(xtd::delegate<void(int, char* [])> main_function, int argc, char* argv[]) {
  main_function(argc, argv);
  return environment::exit_code();
}

int startup::run(xtd::delegate<void(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = std::vector<char*>(args.size(), nullptr);
  for (auto index = 0_z; index < args.size(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.size()), argv.data());
  return environment::exit_code();
}

int startup::run(void (*main_function)(int, char* []), int argc, char* argv[]) {
  main_function(argc, argv);
  return environment::exit_code();
}

int startup::run(void (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = std::vector<char*>(args.size(), nullptr);
  for (auto index = 0_z; index < args.size(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.size()), argv.data());
  return environment::exit_code();
}

int startup::run(xtd::delegate<void (const string_collection&)> main_function, int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}

int startup::run(xtd::delegate<void (const string_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()});
  return environment::exit_code();
}

int startup::run(void (*main_function)(const string_collection&), int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}

int startup::run(void (*main_function)(const string_collection&)) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()});
  return environment::exit_code();
}

int startup::run(xtd::delegate<void (const std::vector<string>&)> main_function, int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}

int startup::run(xtd::delegate<void (const std::vector<string>&)> main_function) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()});
  return environment::exit_code();
}

int startup::run(void (*main_function)(const std::vector<string>&), int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}

int startup::run(void (*main_function)(const std::vector<string>&)) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()});
  return environment::exit_code();
}

int startup::run(xtd::delegate<int()> main_function, int argc, char* argv[]) {
  return main_function();
}

int startup::run(xtd::delegate<int()> main_function) {
  return main_function();
}

int startup::run(int (*main_function)(), int, char* []) {
  return main_function();
}

int startup::run(int (*main_function)()) {
  return main_function();
}

int startup::run(xtd::delegate<int(int, char* [])> main_function, int argc, char* argv[]) {
  return main_function(argc, argv);
}

int startup::run(xtd::delegate<int(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = std::vector<char*>(args.size(), nullptr);
  for (auto index = 0_z; index < args.size(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  auto exit_code = main_function(as<int32>(args.size()), argv.data());
  return exit_code;
}

int startup::run(int (*main_function)(int, char* []), int argc, char* argv[]) {
  return main_function(argc, argv);
}

int startup::run(int (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = std::vector<char*>(args.size(), nullptr);
  for (auto index = 0_z; index < args.size(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  auto exit_code = main_function(as<int32>(args.size()), argv.data());
  return exit_code;
}

int startup::run(xtd::delegate<int(const string_collection&)> main_function, int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc});
}

int startup::run(xtd::delegate<int(const string_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()});
}

int startup::run(int (*main_function)(const string_collection&), int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc});
}

int startup::run(int (*main_function)(const string_collection&)) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()});
}

int startup::run(xtd::delegate<int(const std::vector<string>&)> main_function, int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc});
}

int startup::run(xtd::delegate<int(const std::vector<string>&)> main_function) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()});
}

int startup::run(int (*main_function)(const std::vector<string>&), int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc});
}

int startup::run(int (*main_function)(const std::vector<string>&)) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()});
}
