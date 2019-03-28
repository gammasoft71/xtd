#include <xtd/strings>

#include <bitset>
#include <iostream>
#include <vector>
#include <codecvt>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::string_literals;

enum class numbers {
  one,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine
};

std::ostream& operator<<(std::ostream& os, numbers n) {
  switch (n) {
    case numbers::one: os << "one"; break;
    case numbers::two: os << "two"; break;
    case numbers::three: os << "three"; break;
    case numbers::four: os << "four"; break;
    case numbers::five: os << "five"; break;
    case numbers::six: os << "six"; break;
    case numbers::seven: os << "seven"; break;
    case numbers::eight: os << "eight"; break;
    case numbers::nine: os << "nine"; break;
  }
  return os;
}

class cl {
public:
  cl() = default;
  cl(const cl&) = default;
  cl(int a, int b) : value_a_(a), value_b_(b) {}
  
  int value_a() const {return this->value_a_;}
  int value_b() const {return this->value_b_;}

  template<typename Char>
  friend std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, const cl& value) {
    os << Char('[');
    os << value.value_a();
    os << Char(' ');
    os << value.value_b();
    os << Char(']');
    return os;
  }
  
private:
  int value_a_ = 0;
  int value_b_ = 0;
};

namespace xtd {
  template<>
  std::string to_string(const cl& value, const std::string& fmt) {
    std::stringstream ss;
    ss << "[";
    ss << value.value_a();
    ss << fmt[0];
    ss << value.value_b();
    ss << "]";
    return ss.str();
  }
  
  template<>
  std::wstring to_string(const cl& value, const std::wstring& fmt) {
    std::wstringstream ss;
    ss << L"[";
    ss << value.value_a();
    ss << fmt[0];
    ss << value.value_b();
    ss << L"]";
    return ss.str();
  }
}

// The main entry point for the application.
int main() {
  /*
  cout << strings::format("{}", numbers::two) << endl;
  cout << strings::format("{}", cl(32, 16)) << endl;
  cout << strings::format("{:+}", cl(32, 16)) << endl;
  wcout << strings::format(L"{}", cl(32, 16)) << endl;
  wcout << strings::format(L"{:+}", cl(32, 16)) << endl;
   */

  std::vector names = {"Adam", "Bridgette", "Carla", "Daniel", "Ebenezer", "Francine", "George"};
  std::vector hours = {40.0, 6.667, 40.39, 82.0, 40.333, 80.0, 16.75};
  
  std::cout << xtd::strings::format("{0,-20} {1,5}\n", "Name", "Hours") << std::endl;
  for (size_t ctr = 0; ctr < names.size(); ctr++)
    std::cout << xtd::strings::format("{0,-20} {1:N1}", names[ctr], hours[ctr]) << std::endl;

}

// This code produces the following output:
//
// Hello, World!
