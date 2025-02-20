#include <xtd/xtd>

using namespace xtd::drawing;

namespace manual_tests {
  class program static_ {
  public:
    static auto main(const auto& args) {
      //console::write_line("Hello, world!");
      foreach_(auto color, colors::get_colors()) {
        println("  void test_method_({}) {{", color.name());
        println("    auto c = colors::{}();", color.name());
        println("    ");
        println("    assert::are_equal(colors::{}(), c);", color.name());
        println("    assert::are_equal(color::from_known_color(known_color::{}), c);", color.name());
        println("    assert::are_not_equal(color(), c);");
        println("    assert::are_not_equal(color::empty, c);");
        println("    ");
        println("    assert::are_equal(0x{:X2}, c.a());", color.a());
        println("    assert::are_equal(0x{:X2}, c.r());", color.r());
        println("    assert::are_equal(0x{:X2}, c.g());", color.g());
        println("    assert::are_equal(0x{:X2}, c.b());", color.b());
        println("    assert::are_equal(0, c.handle());");
        println("    assert::are_equal(\"{}\", c.name());", color.name());
        println("    ");
        println("    assert::are_equal(\"color [{}]\", c.to_string());", color.name());
        println("    ");
        println("    assert::is_false(c.is_empty());");
        println("    assert::is_true(c.is_known_color());");
        println("    assert::is_false(c.is_system_color());");
        println("    assert::is_true(c.is_named_color());");
        println("    ");
        println("    assert::are_equal(0x{:X8}, c.to_argb());", color.to_argb());
        println("    assert::are_equal(known_color::{}, c.to_known_color());", color.name());
        println("  }}");
        println("  ");
      }
    }
  };
}

startup_(manual_tests::program::main);

// This code can produces the following output:
//
// Hello, World!
