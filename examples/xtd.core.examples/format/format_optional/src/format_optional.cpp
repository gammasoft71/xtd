#include <xtd/ustring>
#include <optional>

using namespace std;
using namespace xtd;

auto main() -> int {
  cout << ustring::format("{}", optional<string>()) << endl;
  cout << ustring::format("{}", optional<string>("Optional string")) << endl;
}

// This code produces the following output :
//
// (null)
// (Optional string)
