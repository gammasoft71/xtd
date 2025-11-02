// The following code is used to generate culture_info_number_formats_tests unit tests.
#include <xtd/xtd>

using namespace globalization;
using namespace text;

auto main() -> int {
  auto content = string_builder {};
  
  content.append_line("#include <xtd/globalization/culture_info>");
  content.append_line("#include <xtd/tunit/assert>");
  content.append_line("#include <xtd/tunit/collection_assert>");
  content.append_line("#include <xtd/tunit/test_class_attribute>");
  content.append_line("#include <xtd/tunit/test_method_attribute>");
  content.append_line();
  content.append_line("using namespace xtd::globalization;");
  content.append_line("using namespace xtd::tunit;");
  content.append_line();
  content.append_line("namespace xtd::globalization::tests {");
  content.append_line("  class test_class_(culture_info_number_formats_tests) {");
  
  for (auto culture : culture_info::get_cultures(culture_types::all_cultures)) {
    auto number_format = culture.number_format();
    content.append_format("    void test_method_({}) {{\n", culture.name() == "or" ? "or_" : string::is_empty(culture.name()) ? "invariant" : culture.name().replace("-", "_"));
    content.append_format("      auto number_format = culture_info {{{}}}.number_format();\n", culture.name().quoted());
    content.append_format("      assert::are_equal({}, number_format.currency_decimal_digits());\n", number_format.currency_decimal_digits());
    content.append_format("      assert::are_equal({}, number_format.currency_decimal_separator());\n", number_format.currency_decimal_separator().quoted());
    content.append_format("      assert::are_equal({}, number_format.currency_group_separator());\n", number_format.currency_group_separator().quoted());
    content.append_format("      collection_assert::are_equal({{{}}}, number_format.currency_group_sizes());\n", string::join(", ", number_format.currency_group_sizes()));
    content.append_format("      assert::are_equal({}, number_format.currency_negative_pattern());\n", number_format.currency_negative_pattern());
    content.append_format("      assert::are_equal({}, number_format.currency_positive_pattern());\n", number_format.currency_positive_pattern());
    content.append_format("      assert::are_equal({}, number_format.currency_symbol());\n", number_format.currency_symbol().quoted());
    content.append_format("      assert::are_equal({}, number_format.digit_substitution());\n", number_format.digit_substitution());
    content.append_format("      assert::are_equal({}, number_format.nan_symbol());\n", number_format.nan_symbol().quoted());
    content.append_format("      assert::are_equal({}, number_format.negative_infinity_symbol());\n", number_format.negative_infinity_symbol().quoted());
    content.append_format("      assert::are_equal({}, number_format.negative_sign());\n", number_format.negative_sign().quoted());
    content.append_format("      assert::are_equal({}, number_format.number_decimal_digits());\n", number_format.number_decimal_digits());
    content.append_format("      assert::are_equal({}, number_format.number_decimal_separator());\n", number_format.number_decimal_separator().quoted());
    content.append_format("      assert::are_equal({}, number_format.number_group_separator());\n", number_format.number_group_separator().quoted());
    content.append_format("      collection_assert::are_equal({{{}}}, number_format.number_group_sizes());\n", string::join(", ", number_format.number_group_sizes()));
    content.append_format("      assert::are_equal({}, number_format.number_negative_pattern());\n", number_format.number_negative_pattern());
    content.append_format("      assert::are_equal({}, number_format.percent_decimal_digits());\n", number_format.percent_decimal_digits());
    content.append_format("      assert::are_equal({}, number_format.percent_decimal_separator());\n", number_format.percent_decimal_separator().quoted());
    content.append_format("      assert::are_equal({}, number_format.percent_group_separator());\n", number_format.percent_group_separator().quoted());
    content.append_format("      collection_assert::are_equal({{{}}}, number_format.percent_group_sizes());\n", string::join(", ", number_format.percent_group_sizes()));
    content.append_format("      assert::are_equal({}, number_format.percent_negative_pattern());\n", number_format.percent_negative_pattern());
    content.append_format("      assert::are_equal({}, number_format.percent_positive_pattern());\n", number_format.percent_positive_pattern());
    content.append_format("      assert::are_equal({}, number_format.percent_symbol());\n", number_format.percent_symbol().quoted());
    content.append_format("      assert::are_equal({}, number_format.per_mille_symbol());\n", number_format.per_mille_symbol().quoted());
    content.append_format("      assert::are_equal({}, number_format.positive_infinity_symbol());\n", number_format.positive_infinity_symbol().quoted());
    content.append_format("      assert::are_equal({}, number_format.positive_sign());\n", number_format.positive_sign().quoted());
    content.append_line("    }");
    content.append_line();
  }
  content.remove(content.size() - 1, 1);
  content.append_line("  };");
  content.append_line("}");
  
  console::write(content);
}
