// The following code is used to generate culture_info_date_time_formats_tests unit tests.
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
  content.append_line("  class test_class_(culture_info_date_time_formats_tests) {");
  
  for (auto culture : culture_info::get_cultures(culture_types::all_cultures)) {
    content.append_format("    void test_method_({}) {{\n", culture.name() == "or" ? "or_" : string::is_empty(culture.name()) ? "invariant" : culture.name().replace("-", "_"));
    content.append_format("      auto date_time_format = culture_info {{{}}}.date_time_format();\n", culture.name().quoted());
    content.append_format("      collection_assert::are_equal({{{}}}, date_time_format.abreviated_day_names());\n", string::join(", ", culture.date_time_format().abreviated_day_names().select([](auto value) {return value.quoted();})));
    content.append_format("      collection_assert::are_equal({{{}}}, date_time_format.abreviated_month_genitive_names());\n", string::join(", ", culture.date_time_format().abreviated_month_genitive_names().select([](auto value) {return value.quoted();})));
    content.append_format("      collection_assert::are_equal({{{}}}, date_time_format.abreviated_month_names());\n", string::join(", ", culture.date_time_format().abreviated_month_names().select([](auto value) {return value.quoted();})));
    content.append_format("      assert::are_equal({}, date_time_format.am_designator());\n", culture.date_time_format().am_designator().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.date_separator());\n", culture.date_time_format().date_separator().quoted());
    content.append_format("      collection_assert::are_equal({{{}}}, date_time_format.day_names());\n", string::join(", ", culture.date_time_format().day_names().select([](auto value) {return value.quoted();})));
    content.append_format("      assert::are_equal(day_of_week::{}, date_time_format.first_day_of_week());\n", culture.date_time_format().first_day_of_week());
    content.append_format("      assert::are_equal({}, date_time_format.full_date_time_pattern());\n", culture.date_time_format().full_date_time_pattern().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.long_date_pattern());\n", culture.date_time_format().long_date_pattern().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.long_time_pattern());\n", culture.date_time_format().long_time_pattern().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.month_day_pattern());\n", culture.date_time_format().month_day_pattern().quoted());
    content.append_format("      collection_assert::are_equal({{{}}}, date_time_format.month_genitive_names());\n", string::join(", ", culture.date_time_format().month_genitive_names().select([](auto value) {return value.quoted();})));
    content.append_format("      collection_assert::are_equal({{{}}}, date_time_format.month_names());\n", string::join(", ", culture.date_time_format().month_names().select([](auto value) {return value.quoted();})));
    content.append_format("      assert::are_equal({}, date_time_format.native_calendar_name());\n", culture.date_time_format().native_calendar_name().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.pm_designator());\n", culture.date_time_format().pm_designator().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.rfc_1123_pattern());\n", culture.date_time_format().rfc_1123_pattern().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.short_date_pattern());\n", culture.date_time_format().short_date_pattern().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.short_time_pattern());\n", culture.date_time_format().short_time_pattern().quoted());
    content.append_format("      collection_assert::are_equal({{{}}}, date_time_format.shortest_day_names());\n", string::join(", ", culture.date_time_format().shortest_day_names().select([](auto value) {return value.quoted();})));
    content.append_format("      assert::are_equal({}, date_time_format.sortable_date_time_pattern());\n", culture.date_time_format().sortable_date_time_pattern().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.time_separator());\n", culture.date_time_format().time_separator().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.universal_sortable_date_time_pattern());\n", culture.date_time_format().universal_sortable_date_time_pattern().quoted());
    content.append_format("      assert::are_equal({}, date_time_format.year_month_pattern());\n", culture.date_time_format().year_month_pattern().quoted());
    content.append_line("    }");
    content.append_line();
  }
  content.remove(content.size() - 1, 1);
  content.append_line("  };");
  content.append_line("}");
  
  console::write(content);
}
