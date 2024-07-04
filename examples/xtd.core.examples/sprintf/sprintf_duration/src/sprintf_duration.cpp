#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << ustring::sprintf("%s", (26_h + 3_min + 32_s + 24_ms + 500_ns).to_string("")) << endl;
  cout << ustring::sprintf("%s", (26_h + 3_min + 32_s + 24_ms + 500_ns).to_string("G")) << endl;
  auto duration = 2_h + 3_min + 32_s + 24_ms + 500_ns;
  cout << ustring::sprintf("%s", duration.to_string("F")) << endl;
  cout << ustring::sprintf("%s:%s", duration.to_string("H"), duration.to_string("M")) << endl;
  cout << ustring::sprintf("%s:%s:%s:%s", duration.to_string("H"), duration.to_string("M"), duration.to_string("S"), duration.to_string("T")) << endl;
  cout << ustring::sprintf("%s:%s:%s:%s", duration.to_string("h"), duration.to_string("m"), duration.to_string("s"), duration.to_string("t")) << endl;
}

// This code produces the following output :
//
// 1.02:03:32.0240005
// 1.02:03:32.0240005
// 0.02:03:32.0240005
// 02:03
// 02:03:32:0240005
// 2:3:32:240005
