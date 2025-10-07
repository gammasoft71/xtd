// The following code is used to generate culture_info_cultures_tests unit tests.
#include <xtd/xtd>

using namespace globalization;
using namespace text;

auto main() -> int {
  auto content = string_builder {};
  
  content.append_line("#include <xtd/globalization/culture_info>");
  content.append_line("#include <xtd/tunit/assert>");
  content.append_line("#include <xtd/tunit/test_class_attribute>");
  content.append_line("#include <xtd/tunit/test_method_attribute>");
  content.append_line();
  content.append_line("using namespace xtd::globalization;");
  content.append_line("using namespace xtd::tunit;");
  content.append_line();
  content.append_line("namespace xtd::globalization::tests {");
  content.append_line("  class test_class_(culture_info_cultures_tests) {");
  content.append_line("    inline static std::locale current_locale_;");
  content.append_line("    static void test_initialize_(test_initialize) {");
  content.append_line("      current_locale_ = std::locale {};");
  content.append_line("    }");
  content.append_line();
  content.append_line("    static void test_cleanup_(test_cleanup) {");
  content.append_line("      std::locale::global(current_locale_);");
  content.append_line("    }");
  
  for (auto culture : culture_info::get_cultures(culture_types::all_cultures)) {
    content.append_format("    void test_method_({}) {{\n", culture.name() == "or" ? "or_" : string::is_empty(culture.name()) ? "invariant" : culture.name().replace("-", "_"));
    content.append_format("      auto culture = culture_info {{{}}};\n", culture.name().quoted());
    content.append_format("      assert::are_equal(globalization::culture_types::{}, culture.culture_types());\n", culture.culture_types());
    content.append_format("      assert::are_equal({}, culture.display_name());\n", culture.display_name().quoted());
    content.append_format("      assert::are_equal({}, culture.english_name());\n", culture.english_name().quoted());
    content.append_format("      assert::is_{}(culture.is_locale_available());\n", as<string>(culture.is_locale_available()));
    content.append_format("      assert::are_equal({}_z, culture.keyboard_layout_id());\n", culture.keyboard_layout_id());
    content.append_format("      assert::are_equal({}_z, culture.lcid());\n", culture.lcid());
    content.append_format("      assert::are_equal(std::locale {{{}}}, culture.locale());\n", as<string>(culture.locale().name()).quoted());
    content.append_format("      assert::are_equal({}, culture.name());\n", culture.name().quoted());
    content.append_format("      assert::are_equal({}, culture.native_name());\n", culture.native_name().quoted());
    content.append_line("    }");
    content.append_line();
  }
  content.remove(content.size() - 1, 1);
  content.append_line("  };");
  content.append_line("}");
  
  console::write(content);
}
