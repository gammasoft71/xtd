#include <xtd/xtd.core>
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;
using namespace xtd::io;

string to_variable(const string& name) {
  return strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(strings::trim(strings::to_lower(name)), " ", "_"), "(", ""), ")", ""), "'", "_"), "ô", "o"), "é", "e"), "Å", "a"), ",", ""), "ç", "c"), "-", "_"), ".", ""), ":", "");
}

string to_value(const string& value) {
  auto items = strings::split(strings::trim(value), {' '});
  if (items.size() == 1) return xtd::strings::format("0x{:X8}", xtd::parse<int>(xtd::strings::remove(items[0], 0, 2), number_styles::hex_number));
  std::string result = "{";
  for (auto index  = 0U; index < items.size(); index++)
    result.append(xtd::strings::format("0x{:X8}{}", xtd::parse<int>(xtd::strings::remove(items[index], 0, 2), number_styles::hex_number), index < items.size() - 1 ? ", " : ""));
  result += "}";
  return result;
}

void generate_header_file(const std::string& filename) {
  cout << format("      // {}", xtd::strings::remove(path::get_file_name_without_extension(filename), 0, 5)) << endl;
  cout << endl;

  auto lines = file::read_all_lines(filename);
  for(auto index = 0U; index < lines.size(); index += 2) {
    cout << format("      /// @brief Gets a system-defined emoticon that has a string value of {}. This field is constant.\n", to_value(lines[index+1]));
    cout << format("      static const xtd::forms::emoticon {};\n", to_variable(lines[index]));
  }
  cout << endl;
}

void generate_source_file(const std::string& filename) {
  cout << format("// {}", xtd::strings::remove(path::get_file_name_without_extension(filename), 0, 5)) << endl;
  cout << endl;
  
  auto lines = file::read_all_lines(filename);
  for(auto index = 0U; index < lines.size(); index += 2)
    cout << format("const xtd::forms::emoticon xtd::forms::emoticons::{} = {{\"{}\", {}}};\n", to_variable(lines[index]), xtd::strings::to_lower(lines[index]), to_value(lines[index + 1]));
  cout << endl;
}

void generate_vector_items(const std::string& filename) {
  auto lines = file::read_all_lines(filename);
  for(auto index = 0U; index < lines.size(); index += 2)
    cout << format("{}, ", to_variable(lines[index]));
  cout << endl;
}

void generate_flags_header_file(const std::string& filename) {
  static const vector<int> enclosed_letters {0x1F1E6, 0x1F1E7, 0x1F1E8, 0x1F1E9, 0x1F1EA, 0x1F1EB, 0x1F1EC, 0x1F1ED, 0x1F1EE, 0x1F1EF, 0x1F1F0, 0x1F1F1, 0x1F1F2, 0x1F1F3, 0x1F1F4, 0x1F1F5, 0x1F1F6, 0x1F1F7, 0x1F1F8, 0x1F1F9, 0x1F1FA, 0x1F1FB, 0x1F1FC, 0x1F1FD, 0x1F1FE, 0x1F1FF};
  auto lines = file::read_all_lines(filename);
  for(auto index = 0U; index < lines.size(); index += 2) {
    auto items = strings::split(strings::trim(lines[index]), {'\t'});
    cout << format("      /// @brief Gets a system-defined emoticon that has a string value of {{0x{:X8}, 0x{:X8}}}. This field is constant.\n", enclosed_letters[items[1][0] - 'A'], enclosed_letters[items[1][1] - 'A']);
    cout << format("      static const xtd::forms::emoticon {}_flag;\n\n", to_variable(items[0]));
  }
  cout << endl;
}

void generate_flags_source_file(const std::string& filename) {
  static const vector<int> enclosed_letters {0x1F1E6, 0x1F1E7, 0x1F1E8, 0x1F1E9, 0x1F1EA, 0x1F1EB, 0x1F1EC, 0x1F1ED, 0x1F1EE, 0x1F1EF, 0x1F1F0, 0x1F1F1, 0x1F1F2, 0x1F1F3, 0x1F1F4, 0x1F1F5, 0x1F1F6, 0x1F1F7, 0x1F1F8, 0x1F1F9, 0x1F1FA, 0x1F1FB, 0x1F1FC, 0x1F1FD, 0x1F1FE, 0x1F1FF};
  auto lines = file::read_all_lines(filename);
  for(auto index = 0U; index < lines.size(); index++) {
    auto items = strings::split(strings::trim(lines[index]), {'\t'});
    cout << format("const xtd::forms::emoticon xtd::forms::emoticons::{}_flag = {{\"flag of {}\", {{0x{:X8}, 0x{:X8}}}}};\n", to_variable(items[0]), items[0], enclosed_letters[items[1][0] - 'A'], enclosed_letters[items[1][1] - 'A']);
  }
  cout << endl;
}

void generate_flags_vector_items(const std::string& filename) {
  auto lines = file::read_all_lines(filename);
  for(auto index = 0U; index < lines.size(); index += 2) {
    auto items = strings::split(strings::trim(lines[index]), {'\t'});
    cout << format("{}_flag, ", to_variable(items[0]));
  }
  cout << endl;
}

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;
  
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/01 - 00080-00FF Latin 1 Supplement.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/02 - 2000-206F - General Punctuation.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/03 - 2100-214F Letterlike Symbols.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/04 - 2190-21FF Arrows.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/05 - 2300-23FF Miscellaneous Technical.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/06 - 2460-24FF Enclosed Alphanumerics.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/07 - 25A0 25FF Geometric Shapes.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/08 - 2600-26FF Miscellaneous Symbols.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/09 - 2700-27BF Dingbats.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/10 - 2900-297F Supplemental Arrows-B.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/11 - 2B00-2BFF Miscellaneous Symbols And Arrows.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/12 - 3000-303F CJK Symbols and Punctuation.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/13 - 3200-32FF Enclosed CJK Letters and Months.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/14 - FE00-FE0F Variation Selectors.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/15 - 1F000-1F02F Mahjong Tiles.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/16 - 1F0A0-1F0FF Playing Cards.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/17 - 1F100-1F1FF Enclosed Alphanumeric Supplement.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/18 - 1F200-1F2FF Enclosed Ideographic Supplement.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/19 - 1F300-1F5FF symbols_and_pictographs.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/20 - 1F600-1F64F Emoticons (Emoji).txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/21 - 1F680-1F6FF Transport And Map Symbols.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/22 - 1F780-1F7FF Geometric Shapes Extended.txt";
  // auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/23 - 1F900-1F9FF Supplemental Symbols and Pictographs.txt";
  //auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/24 - 1FA70-1F7FF Symbols and Pictographs Extended-A.txt";
  //auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/25 - Emoji ZWJ Sequences.txt";

  auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/14 - FE00-FE0F Variation Selectors.txt";

  //generate_header_file(filename);
  generate_source_file(filename);
  //generate_vector_items(filename);
  
  //auto filename = "/Users/yves/Projects/xtd/src/xtd_forms/docs/Emoticons/25 - Country Flags.txt";
  //generate_flags_header_file(filename);
  //generate_flags_source_file(filename);
  //generate_flags_vector_items(filename);
  
}

// This code produces the following output with colors:
//
// Hello, World!
