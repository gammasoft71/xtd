#include <xtd/strings>

#include <bitset>
#include <iostream>
#include <vector>
#include <codecvt>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::string_literals;

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
  std::string to_string<cl>(const cl& value, const std::string& fmt) {
    std::stringstream ss;
    ss << "[";
    ss << value.value_a();
    ss << fmt[0];
    ss << value.value_b();
    ss << "]";
    return ss.str();
  }
  
  template<>
  std::wstring to_string<cl>(const cl& value, const std::wstring& fmt) {
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
  cout << strings::format("{}", cl(32, 16)) << endl;
  cout << strings::format("{:+}", cl(32, 16)) << endl;
  wcout << strings::format(L"{}", cl(32, 16)) << endl;
  wcout << strings::format(L"{:+}", cl(32, 16)) << endl;
}

// This code produces the following output with colors:
//
// Hello, World!
