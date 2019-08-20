#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

// The main entry point for the application.
int main() {
  for (known_color kc = known_color::transparent; kc < known_color::yellow_green; kc = known_color(int(kc) + 1)) {
    //if (kc != known_color::blue) continue;
    color c = color::from_known_color(kc);
    cout << strings::format("") << endl;
    cout << strings::format("    void test_method_(create_from_name_{}) {{", c.name()) << endl;
    cout << strings::format("      color c = color::from_name(\"{}\");", c.name()) << endl;
    cout << strings::format("") << endl;
    cout << strings::format("      assert::are_equal(color::from_name(\"{}\"), c);", c.name()) << endl;
    cout << strings::format("      assert::are_not_equal(color(), c);") << endl;
    cout << strings::format("      assert::are_not_equal(color::empty, c);") << endl;
    cout << strings::format("") << endl;
    cout << strings::format("      assert::are_equal({}, c.a());", strings::format("0x{:X2}", c.a())) << endl;
    cout << strings::format("      assert::are_equal({}, c.r());", strings::format("0x{:X2}", c.r())) << endl;
    cout << strings::format("      assert::are_equal({}, c.g());", strings::format("0x{:X2}", c.g())) << endl;
    cout << strings::format("      assert::are_equal({}, c.b());", strings::format("0x{:X2}", c.b())) << endl;
    cout << strings::format("      assert::are_equal(0, c.handle());") << endl;
    cout << strings::format("      assert::are_equal(\"{}\", c.name());", c.name()) << endl;
    cout << strings::format("") << endl;
    cout << strings::format("      assert::is_false(c.is_empty());") << endl;
    cout << strings::format("      assert::is_true(c.is_known_color());") << endl;
    cout << strings::format("      assert::is_false(c.is_system_color());") << endl;
    cout << strings::format("      assert::is_true(c.is_named_color());") << endl;
    cout << strings::format("") << endl;
    cout << strings::format("      assert::are_equal({}, c.to_argb());", strings::format("0x{:X8}", c.to_argb())) << endl;
    cout << strings::format("      assert::are_equal(known_color::{}, c.to_known_color());", c.name()) << endl;
    cout << strings::format("    }}") << endl;
  }
}
