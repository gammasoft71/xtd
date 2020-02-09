#include <xtd/xtd.core>
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;
using namespace xtd::io;

string to_variable(const string& name) {
  return strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::trim(strings::to_lower(name)), " ", "_"), "(", ""), ")", ""), "'", "_"), "ô", "o"), "é", "e"), "Å", "a"), ",", ""), "ç", "c"), "-", "_"), ".", "");
}

string to_value(const string& value) {
  auto items = strings::split(strings::trim(value), {' '});
  if (items.size() == 1) return xtd::strings::format("0x{:X8}", xtd::parse<int>(xtd::strings::remove(items[0], 0, 2), number_styles::hex_number));
  std::string result = "{";
  for (auto index  = 0; index < items.size(); index++)
    result.append(xtd::strings::format("0x{:X8}{}", xtd::parse<int>(xtd::strings::remove(items[index], 0, 2), number_styles::hex_number), index < items.size() - 1 ? ", " : ""));
  result += "}";
  return result;
}

void generate_header_file(const std::string& filename) {
  cout << format("      /// {}", xtd::strings::remove(path::get_file_name_without_extension(filename), 0, 5)) << endl;
  cout << endl;

  auto lines = file::read_all_lines(filename);
  for(auto index = 0; index < lines.size(); index += 2) {
    cout << format("      /// @brief Gets a system-defined emoticon that has a string value of {}. This field is constant.\n", to_value(lines[index+1]));
    cout << format("      static const xtd::forms::emoticon {};\n", to_variable(lines[index]));
  }
  cout << endl;
}

void generate_source_file(const std::string& filename) {
  cout << format("/// {}", xtd::strings::remove(path::get_file_name_without_extension(filename), 0, 5)) << endl;
  cout << endl;
  
  auto lines = file::read_all_lines(filename);
  for(auto index = 0; index < lines.size(); index += 2)
    cout << format("const xtd::forms::emoticon xtd::forms::emoticons::{} = {{\"{}\", {}}};\n", to_variable(lines[index]), xtd::strings::to_lower(lines[index]), to_value(lines[index + 1]));
  cout << endl;
}

void generate_vector_items(const std::string& filename) {
  auto lines = file::read_all_lines(filename);
  for(auto index = 0; index < lines.size(); index += 2)
    cout << format("{}, ", to_variable(lines[index]));
  cout << endl;
}

void generate_flags_header_file(const std::string& filename) {
  static const vector<int> enclosed_letters {0x1F1E6, 0x1F1E7, 0x1F1E8, 0x1F1E9, 0x1F1EA, 0x1F1EB, 0x1F1EC, 0x1F1ED, 0x1F1EE, 0x1F1EF, 0x1F1F0, 0x1F1F1, 0x1F1F2, 0x1F1F3, 0x1F1F4, 0x1F1F5, 0x1F1F6, 0x1F1F7, 0x1F1F8, 0x1F1F9, 0x1F1FA, 0x1F1FB, 0x1F1FC, 0x1F1FD, 0x1F1FE, 0x1F1FF};
  auto lines = file::read_all_lines(filename);
  for(auto index = 0; index < lines.size(); index += 2) {
    auto items = strings::split(strings::trim(lines[index]), {'\t'});
    cout << format("      /// @brief Gets a system-defined emoticon that has a string value of {{0x{:X8}, 0x{:X8}}}. This field is constant.\n", enclosed_letters[items[1][0] - 'A'], enclosed_letters[items[1][1] - 'A']);
    cout << format("      static const xtd::forms::emoticon {}_flag;\n\n", to_variable(items[0]));
  }
  cout << endl;
}

void generate_flags_source_file(const std::string& filename) {
  static const vector<int> enclosed_letters {0x1F1E6, 0x1F1E7, 0x1F1E8, 0x1F1E9, 0x1F1EA, 0x1F1EB, 0x1F1EC, 0x1F1ED, 0x1F1EE, 0x1F1EF, 0x1F1F0, 0x1F1F1, 0x1F1F2, 0x1F1F3, 0x1F1F4, 0x1F1F5, 0x1F1F6, 0x1F1F7, 0x1F1F8, 0x1F1F9, 0x1F1FA, 0x1F1FB, 0x1F1FC, 0x1F1FD, 0x1F1FE, 0x1F1FF};
  auto lines = file::read_all_lines(filename);
  for(auto index = 0; index < lines.size(); index++) {
    auto items = strings::split(strings::trim(lines[index]), {'\t'});
    cout << format("const xtd::forms::emoticon xtd::forms::emoticons::{}_flag = {{\"flag of {}\", {{0x{:X8}, 0x{:X8}}}}};\n", to_variable(items[0]), items[0], enclosed_letters[items[1][0] - 'A'], enclosed_letters[items[1][1] - 'A']);
  }
  cout << endl;
}

void generate_flags_vector_items(const std::string& filename) {
  auto lines = file::read_all_lines(filename);
  for(auto index = 0; index < lines.size(); index += 2) {
    auto items = strings::split(strings::trim(lines[index]), {'\t'});
    cout << format("{}_flag, ", to_variable(items[0]));
  }
  cout << endl;
}

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;
  
  generate_header_file("/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/01 - 00080-00FF Latin 1 Supplement.txt");
  //generate_source_file("/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/01 - 00080-00FF Latin 1 Supplement.txt");
  //generate_vector_items("/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/01 - 00080-00FF Latin 1 Supplement.txt");
  
  //generate_flags_header_file("/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/25 - Country Flags.txt");
  //generate_flags_source_file("/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/25 - Country Flags.txt");
  //generate_flags_vector_items("/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/25 - Country Flags.txt");
  
}

// This code produces the following output with colors:
//
// Hello, World!
