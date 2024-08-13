#include <xtd/literals>
#include <xtd/ustring>

using namespace std::literals;
using namespace xtd;

auto main() -> int {
  std::cout << ustring::format("{}", "string") << std::endl;
  std::cout << ustring::format("{}", u8"string") << std::endl;
  std::cout << ustring::format("{}", L"string") << std::endl;
  std::cout << ustring::format("{}", u"string") << std::endl;
  std::cout << ustring::format("{}", U"string") << std::endl;
  std::cout << ustring::format("{}", "string"s) << std::endl;
  std::cout << ustring::format("{}", u8"string"s) << std::endl;
  std::cout << ustring::format("{}", L"string"s) << std::endl;
  std::cout << ustring::format("{}", u"string"s) << std::endl;
  std::cout << ustring::format("{}", U"string"s) << std::endl;
  std::cout << ustring::format("{}", "string"_s) << std::endl;
  std::cout << ustring::format("{}", u8"string"_s) << std::endl;
  std::cout << ustring::format("{}", L"string"_s) << std::endl;
  std::cout << ustring::format("{}", u"string"_s) << std::endl;
  std::cout << ustring::format("{}", U"string"_s) << std::endl;
  std::cout << ustring::format("{:anything}", "string") << std::endl;
}

// This code produces the following output :
//
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
// string
