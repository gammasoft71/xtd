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

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;
  auto lines = file::read_all_lines("/Users/yves/Desktop/countries.txt");
  const vector<string> enclosed_letters {u8"\\U0001F1E6", u8"\\U0001F1E7", u8"\\U0001F1E8", u8"\\U0001F1E9", u8"\\U0001F1EA", u8"\\U0001F1EB", u8"\\U0001F1EC", u8"\\U0001F1ED", u8"\\U0001F1EE", u8"\\U0001F1EF", u8"\\U0001F1F0", u8"\\U0001F1F1", u8"\\U0001F1F2", u8"\\U0001F1F3", u8"\\U0001F1F4", u8"\\U0001F1F5", u8"\\U0001F1F6", u8"\\U0001F1F7", u8"\\U0001F1F8", u8"\\U0001F1F9", u8"\\U0001F1FA", u8"\\U0001F1FB", u8"\\U0001F1FC", u8"\\U0001F1FD", u8"\\U0001F1FE", u8"\\U0001F1FF"};
  for(auto index = 0; index < lines.size(); index += 1) {
    //cout << format("      static const xtd::forms::emoticon {};\n", to_variable(lines[index]));
    //cout << format("const xtd::forms::emoticon xtd::forms::emoticons::{} = {{\"{}\", \"{}\"}};\n", to_variable(lines[index]), lines[index], strings::replace(lines[index + 1], "U+", "\\U000"));
    //cout << format("{}, ", to_variable(lines[index]));
    auto items = strings::split(strings::trim(lines[index]), {'\t'});
    //cout << format("const xtd::forms::emoticon xtd::forms::emoticons::flag_of_{} = {{\"{}\", \"{}\"}};\n", to_variable(items[0]), items[0], enclosed_letters[items[1][0] - 'A'] + enclosed_letters[items[1][1] - 'A']);
    cout << format("flag_of_{}, ", to_variable(items[0]));
  }
}

// This code produces the following output with colors:
//
// Hello, World!
