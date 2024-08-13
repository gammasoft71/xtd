#include <xtd/ustring>
#include <optional>

using namespace xtd;

auto main() -> int {
  std::cout << ustring::format("{}", std::optional<ustring>()) << std::endl;
  std::cout << ustring::format("{}", std::optional<ustring>("Optional string")) << std::endl;
}

// This code produces the following output :
//
// (null)
// (Optional string)
