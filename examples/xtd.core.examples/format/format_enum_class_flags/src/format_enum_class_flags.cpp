#include <xtd/enum_class>
#include <xtd/ustring>

using namespace std;
using namespace xtd;

enum class text_styles {
  normal =    0b0,
  bold =      0b1,
  italic =    0b10,
  underline = 0b100,
  strikeout = 0b1000,
};

// Add text_style enum class flags operators and register flags attribute.
flags_attribute_(, text_styles);

// Only this operator is needed for text_styles enum class to be recognized by xtd::ustring::format().
template<> struct xtd::enum_register<text_styles> {
  explicit operator auto() const noexcept {return xtd::enum_collection<text_styles> {{text_styles::normal, "normal"}, {text_styles::bold, "bold"}, {text_styles::italic, "italic"}, {text_styles::underline, "underline"}, {text_styles::strikeout, "strikeout"}};}
};

auto main() -> int {
  cout << ustring::format("{}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("0b{:b}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("0b{:B}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("{:d}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("{:D}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("{:g}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("{:G}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("0{:o}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("0{:O}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("0x{:x}", text_styles::bold | text_styles::italic) << endl;
  cout << ustring::format("0x{:X}", text_styles::bold | text_styles::italic) << endl;
}

// This code produces the following output :
//
// saturday
// 0b101
// 0b101
// 5
// 5
// saturday
// saturday
// 05
// 05
// 0x5
// 0x5
