#include <iostream>
#include <xtd/xtd.drawing>

using namespace xtd;
using namespace xtd::drawing;

// The main entry point for the application.
int main() {
  std::cout << format("p1 = {}", point()) << std::endl;
  std::cout << format("p2 = {}", point(10, 20)) << std::endl;
  std::cout << format("p3 = {}", point(0x0014000A)) << std::endl;
  std::cout << format("p4 = {}", point(size(10, 20))) << std::endl;
  std::cout << format("point::empty = {}", point::empty) << std::endl;

  std::cout << format("pf1 = {}", point_f()) << std::endl;
  std::cout << format("pf2 = {}", point_f(10, 20)) << std::endl;
  std::cout << format("pf3 = {}", point_f(point(10, 20))) << std::endl;

  std::cout << format("s1 = {}", size()) << std::endl;
  std::cout << format("s2 = {}", size(10, 20)) << std::endl;
}
