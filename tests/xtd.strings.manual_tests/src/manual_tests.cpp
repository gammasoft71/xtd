#include <xtd/strings>

#include <bitset>
#include <chrono>
#include <iostream>
#include <vector>
#include <codecvt>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::string_literals;


namespace xtd {
}

// The main entry point for the application.
int main() {
  /*
  cout << to_string(325, "C", std::locale("en_US.UTF-8")) << endl;
  std::locale::global(std::locale("en_US.UTF-8"));
  cout << to_string(325, "C") << endl;
  cout << strings::format("{:C}", 325) << endl;
  
  cout << to_string(325, "C", std::locale("fr_FR.UTF-8")) << endl;
  std::locale::global(std::locale("fr_FR.UTF-8"));
  cout << to_string(325, "C") << endl;
  cout << strings::format("{:C}", 325) << endl;
  
  cout << to_string(325, "C", std::locale("ja_JP.UTF-8")) << endl;
  std::locale::global(std::locale("ja_JP.UTF-8"));
  cout << to_string(325, "C") << endl;
  cout << strings::format("{:C}", 325) << endl;
  
  cout << to_string(325, "C", std::locale("fi_FI.UTF-8")) << endl;
  std::locale::global(std::locale("fi_FI.UTF-8"));
  cout << to_string(325, "C") << endl;
  cout << strings::format("{:C}", 325) << endl;
   */
  
  std::locale::global(std::locale("ja_JP.UTF-8"));

  cout << strings::date_time_format("%A, %w %B %Y", std::chrono::system_clock::now()) << endl;
  
  cout << strings::format("{:N}\n", std::chrono::system_clock::now());
}

// This code produces the following output:
//
// Hello, World!
