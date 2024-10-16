#include <xtd/forms/month_calendar>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(month_calendar_hit_area_tests) {
  public:
    void test_method_(nowhere) {
      assert::are_equal(0, enum_object<>::to_int32(month_calendar::hit_area::nowhere));
      assert::are_equal("nowhere", enum_object<>::to_string(month_calendar::hit_area::nowhere));
      assert::are_equal(month_calendar::hit_area::nowhere, enum_object<>::parse<month_calendar::hit_area>("nowhere"));
    }
    
    void test_method_(title_background) {
      assert::are_equal(1, enum_object<>::to_int32(month_calendar::hit_area::title_background));
      assert::are_equal("title_background", enum_object<>::to_string(month_calendar::hit_area::title_background));
      assert::are_equal(month_calendar::hit_area::title_background, enum_object<>::parse<month_calendar::hit_area>("title_background"));
    }
    
    void test_method_(title_month) {
      assert::are_equal(2, enum_object<>::to_int32(month_calendar::hit_area::title_month));
      assert::are_equal("title_month", enum_object<>::to_string(month_calendar::hit_area::title_month));
      assert::are_equal(month_calendar::hit_area::title_month, enum_object<>::parse<month_calendar::hit_area>("title_month"));
    }
    
    void test_method_(title_year) {
      assert::are_equal(3, enum_object<>::to_int32(month_calendar::hit_area::title_year));
      assert::are_equal("title_year", enum_object<>::to_string(month_calendar::hit_area::title_year));
      assert::are_equal(month_calendar::hit_area::title_year, enum_object<>::parse<month_calendar::hit_area>("title_year"));
    }
    
    void test_method_(next_month_button) {
      assert::are_equal(4, enum_object<>::to_int32(month_calendar::hit_area::next_month_button));
      assert::are_equal("next_month_button", enum_object<>::to_string(month_calendar::hit_area::next_month_button));
      assert::are_equal(month_calendar::hit_area::next_month_button, enum_object<>::parse<month_calendar::hit_area>("next_month_button"));
    }
    
    void test_method_(prev_month_button) {
      assert::are_equal(5, enum_object<>::to_int32(month_calendar::hit_area::prev_month_button));
      assert::are_equal("prev_month_button", enum_object<>::to_string(month_calendar::hit_area::prev_month_button));
      assert::are_equal(month_calendar::hit_area::prev_month_button, enum_object<>::parse<month_calendar::hit_area>("prev_month_button"));
    }
    
    void test_method_(calendar_background) {
      assert::are_equal(6, enum_object<>::to_int32(month_calendar::hit_area::calendar_background));
      assert::are_equal("calendar_background", enum_object<>::to_string(month_calendar::hit_area::calendar_background));
      assert::are_equal(month_calendar::hit_area::calendar_background, enum_object<>::parse<month_calendar::hit_area>("calendar_background"));
    }
    
    void test_method_(date) {
      assert::are_equal(7, enum_object<>::to_int32(month_calendar::hit_area::date));
      assert::are_equal("date", enum_object<>::to_string(month_calendar::hit_area::date));
      assert::are_equal(month_calendar::hit_area::date, enum_object<>::parse<month_calendar::hit_area>("date"));
    }
    
    void test_method_(next_month_date) {
      assert::are_equal(8, enum_object<>::to_int32(month_calendar::hit_area::next_month_date));
      assert::are_equal("next_month_date", enum_object<>::to_string(month_calendar::hit_area::next_month_date));
      assert::are_equal(month_calendar::hit_area::next_month_date, enum_object<>::parse<month_calendar::hit_area>("next_month_date"));
    }
    
    void test_method_(prev_month_date) {
      assert::are_equal(9, enum_object<>::to_int32(month_calendar::hit_area::prev_month_date));
      assert::are_equal("prev_month_date", enum_object<>::to_string(month_calendar::hit_area::prev_month_date));
      assert::are_equal(month_calendar::hit_area::prev_month_date, enum_object<>::parse<month_calendar::hit_area>("prev_month_date"));
    }
    
    void test_method_(day_of_week) {
      assert::are_equal(10, enum_object<>::to_int32(month_calendar::hit_area::day_of_week));
      assert::are_equal("day_of_week", enum_object<>::to_string(month_calendar::hit_area::day_of_week));
      assert::are_equal(month_calendar::hit_area::day_of_week, enum_object<>::parse<month_calendar::hit_area>("day_of_week"));
    }
    
    void test_method_(week_numbers) {
      assert::are_equal(11, enum_object<>::to_int32(month_calendar::hit_area::week_numbers));
      assert::are_equal("week_numbers", enum_object<>::to_string(month_calendar::hit_area::week_numbers));
      assert::are_equal(month_calendar::hit_area::week_numbers, enum_object<>::parse<month_calendar::hit_area>("week_numbers"));
    }
    
    void test_method_(today_link) {
      assert::are_equal(12, enum_object<>::to_int32(month_calendar::hit_area::today_link));
      assert::are_equal("today_link", enum_object<>::to_string(month_calendar::hit_area::today_link));
      assert::are_equal(month_calendar::hit_area::today_link, enum_object<>::parse<month_calendar::hit_area>("today_link"));
    }
  };
}
