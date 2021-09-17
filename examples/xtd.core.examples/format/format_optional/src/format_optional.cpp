#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("{}", optional<string>()) << endl;
  cout << ustring::format("{}", optional<string>("Optional string")) << endl;
}

// This code produces the following output :
//
// (null)
// (Optional string)
