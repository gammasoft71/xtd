#include "../../include/xtd/environment.hpp"
#include "../../include/xtd/startup.hpp"
#include "../../include/xtd/threading/thread.hpp"
#include <vector>

using namespace xtd;
using namespace xtd::threading;
using namespace xtd::threading::tasks;

void startup::init_safe_run() {
}

void startup::end_safe_run() {
  thread::join_all();
}

int startup::safe_run(delegate<void()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<void()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<void(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<void(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<void(const argument_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<void(const argument_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<int()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<int()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<int(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<int(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<int(const argument_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<int(const argument_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<task<>()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<task<>()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<task<>(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<task<>(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<task<>(const argument_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<task<>(const argument_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<task<int>()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<task<int>()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<task<int>(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<task<int>(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<task<int>(const argument_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<task<int>(const argument_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<wtask<>()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<wtask<>()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<wtask<>(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<wtask<>(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<wtask<>(const argument_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<wtask<>(const argument_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<wtask<int>()> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<wtask<int>()> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<wtask<int>(int, char* [])> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<wtask<int>(int, char* [])> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(delegate<wtask<int>(const argument_collection&)> main_function, int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(delegate<wtask<int>(const argument_collection&)> main_function) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(void (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(void (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(void (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(void (*main_function)(const argument_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(int (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(int (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(int (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(int (*main_function)(const argument_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(task<> (*main_function)(), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(task<> (*main_function)()) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(task<> (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(task<> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(task<> (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(task<> (*main_function)(const argument_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(task<int> (*main_function)(), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(task<int> (*main_function)()) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(task<int> (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(task<int> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(task<int> (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(task<int> (*main_function)(const argument_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(wtask<> (*main_function)(), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(wtask<> (*main_function)()) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(wtask<> (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(wtask<> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(wtask<> (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(wtask<> (*main_function)(const argument_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(wtask<int> (*main_function)(), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(wtask<int> (*main_function)()) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(wtask<int> (*main_function)(int, char* []), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(wtask<int> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return internal_safe_run(main_function, argc, argv);
}

int startup::safe_run(wtask<int> (*main_function)(int, char* [])) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::safe_run(wtask<int> (*main_function)(const argument_collection&)) {
  return internal_safe_run(main_function, std::nullopt, std::nullopt);
}

int startup::run(delegate<void()> main_function, int, char* []) {
  main_function();
  return environment::exit_code();
}

int startup::run(delegate<void()> main_function) {
  main_function();
  return environment::exit_code();
}

int startup::run(delegate<void(int, char* [])> main_function, int argc, char* argv[]) {
  main_function(argc, argv);
  return environment::exit_code();
}

int startup::run(delegate<void(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.length()), argv.data());
  return environment::exit_code();
}

int startup::run(delegate<void (const argument_collection&)> main_function, int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}

int startup::run(delegate<void (const argument_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()});
  return environment::exit_code();
}

int startup::run(delegate<int()> main_function, int argc, char* argv[]) {
  return main_function();
}

int startup::run(delegate<int()> main_function) {
  return main_function();
}

int startup::run(delegate<int(int, char* [])> main_function, int argc, char* argv[]) {
  return main_function(argc, argv);
}

int startup::run(delegate<int(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  auto exit_code = main_function(as<int32>(args.length()), argv.data());
  return exit_code;
}

int startup::run(delegate<int(const argument_collection&)> main_function, int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc});
}

int startup::run(delegate<int(const argument_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()});
}

int startup::run(delegate<task<>()> main_function, int, char* []) {
  main_function().wait();
  return environment::exit_code();
}

int startup::run(delegate<task<>()> main_function) {
  main_function().wait();
  return environment::exit_code();
}

int startup::run(delegate<task<>(int, char* [])> main_function, int argc, char* argv[]) {
  main_function(argc, argv).wait();
  return environment::exit_code();
}

int startup::run(delegate<task<>(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.length()), argv.data()).wait();
  return environment::exit_code();
}

int startup::run(delegate<task<> (const argument_collection&)> main_function, int argc, char* argv[]) {
  main_function({argv + 1, argv + argc}).wait();
  return environment::exit_code();
}

int startup::run(delegate<task<> (const argument_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()}).wait();
  return environment::exit_code();
}

int startup::run(delegate<task<int>()> main_function, int argc, char* argv[]) {
  return main_function().result();
}

int startup::run(delegate<task<int>()> main_function) {
  return main_function().result();
}

int startup::run(delegate<task<int>(int, char* [])> main_function, int argc, char* argv[]) {
  return main_function(argc, argv).result();
}

int startup::run(delegate<task<int>(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  auto exit_code = main_function(as<int32>(args.length()), argv.data()).result();
  return exit_code;
}

int startup::run(delegate<task<int>(const argument_collection&)> main_function, int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc}).result();
}

int startup::run(delegate<task<int>(const argument_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()}).result();
}

int startup::run(delegate<wtask<>()> main_function, int, char* []) {
  main_function().wait();
  return environment::exit_code();
}

int startup::run(delegate<wtask<>()> main_function) {
  main_function().wait();
  return environment::exit_code();
}

int startup::run(delegate<wtask<>(int, char* [])> main_function, int argc, char* argv[]) {
  main_function(argc, argv).wait();
  return environment::exit_code();
}

int startup::run(delegate<wtask<>(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.length()), argv.data()).wait();
  return environment::exit_code();
}

int startup::run(delegate<wtask<> (const argument_collection&)> main_function, int argc, char* argv[]) {
  main_function({argv + 1, argv + argc}).wait();
  return environment::exit_code();
}

int startup::run(delegate<wtask<> (const argument_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()}).wait();
  return environment::exit_code();
}

int startup::run(delegate<wtask<int>()> main_function, int argc, char* argv[]) {
  return main_function().result();
}

int startup::run(delegate<wtask<int>()> main_function) {
  return main_function().result();
}

int startup::run(delegate<wtask<int>(int, char* [])> main_function, int argc, char* argv[]) {
  return main_function(argc, argv).result();
}

int startup::run(delegate<wtask<int>(int, char* [])> main_function) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  auto exit_code = main_function(as<int32>(args.length()), argv.data()).result();
  return exit_code;
}

int startup::run(delegate<wtask<int>(const argument_collection&)> main_function, int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc}).result();
}

int startup::run(delegate<wtask<int>(const argument_collection&)> main_function) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()}).result();
}

int startup::run(void (*main_function)(), int, char* []) {
  main_function();
  return environment::exit_code();
}

int startup::run(void (*main_function)()) {
  main_function();
  return environment::exit_code();
}

int startup::run(void (*main_function)(int, char* []), int argc, char* argv[]) {
  main_function(argc, argv);
  return environment::exit_code();
}

int startup::run(void (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.length()), argv.data());
  return environment::exit_code();
}

int startup::run(void (*main_function)(const argument_collection&), int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}

int startup::run(void (*main_function)(const argument_collection&)) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()});
  return environment::exit_code();
}

int startup::run(int (*main_function)(), int, char* []) {
  return main_function();
}

int startup::run(int (*main_function)()) {
  return main_function();
}

int startup::run(int (*main_function)(int, char* []), int argc, char* argv[]) {
  return main_function(argc, argv);
}

int startup::run(int (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  auto exit_code = main_function(as<int32>(args.length()), argv.data());
  return exit_code;
}

int startup::run(int (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc});
}

int startup::run(int (*main_function)(const argument_collection&)) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()});
}

int startup::run(task<> (*main_function)(), int, char* []) {
  main_function().wait();
  return environment::exit_code();
}

int startup::run(task<> (*main_function)()) {
  main_function().wait();
  return environment::exit_code();
}

int startup::run(task<> (*main_function)(int, char* []), int argc, char* argv[]) {
  main_function(argc, argv).wait();
  return environment::exit_code();
}

int startup::run(task<> (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.length()), argv.data()).wait();
  return environment::exit_code();
}

int startup::run(task<> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  main_function({argv + 1, argv + argc}).wait();
  return environment::exit_code();
}

int startup::run(task<> (*main_function)(const argument_collection&)) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()}).wait();
  return environment::exit_code();
}

int startup::run(task<int> (*main_function)(), int, char* []) {
  return main_function().result();
}

int startup::run(task<int> (*main_function)()) {
  return main_function().result();
}

int startup::run(task<int> (*main_function)(int, char* []), int argc, char* argv[]) {
  return main_function(argc, argv).result();
}

int startup::run(task<int> (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  return main_function(as<int32>(args.length()), argv.data()).result();
}

int startup::run(task<int> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc}).result();
}

int startup::run(task<int> (*main_function)(const argument_collection&)) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()}).result();
}

int startup::run(wtask<> (*main_function)(), int, char* []) {
  main_function();
  return environment::exit_code();
}

int startup::run(wtask<> (*main_function)()) {
  main_function();
  return environment::exit_code();
}

int startup::run(wtask<> (*main_function)(int, char* []), int argc, char* argv[]) {
  main_function(argc, argv);
  return environment::exit_code();
}

int startup::run(wtask<> (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  main_function(as<int32>(args.length()), argv.data());
  return environment::exit_code();
}

int startup::run(wtask<> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  main_function({argv + 1, argv + argc});
  return environment::exit_code();
}

int startup::run(wtask<> (*main_function)(const argument_collection&)) {
  auto args = environment::get_command_line_args();
  main_function({args.begin() + 1, args.end()});
  return environment::exit_code();
}

int startup::run(wtask<int> (*main_function)(), int, char* []) {
  return main_function().result();
}

int startup::run(wtask<int> (*main_function)()) {
  return main_function().result();
}

int startup::run(wtask<int> (*main_function)(int, char* []), int argc, char* argv[]) {
  return main_function(argc, argv).result();
}

int startup::run(wtask<int> (*main_function)(int, char* [])) {
  auto args = environment::get_command_line_args();
  auto argv = array<char*>(args.length());
  for (auto index = 0_z; index < args.length(); ++index)
    argv[index] = const_cast<char*>(args[index].data());
  return main_function(as<int32>(args.length()), argv.data()).result();
}

int startup::run(wtask<int> (*main_function)(const argument_collection&), int argc, char* argv[]) {
  return main_function({argv + 1, argv + argc}).result();
}

int startup::run(wtask<int> (*main_function)(const argument_collection&)) {
  auto args = environment::get_command_line_args();
  return main_function({args.begin() + 1, args.end()}).result();
}
