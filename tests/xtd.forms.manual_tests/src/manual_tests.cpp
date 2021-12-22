#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;
using namespace std::chrono;
using namespace std::chrono_literals;

class manual_test_form : public form {
public:
  static void main() {
    debug_form df;
    application::run(manual_test_form());
  }

  manual_test_form() {
    text("Manual tests");
    client_size({ 640, 480 });

    month_calendar1.parent(*this);
    month_calendar1.location({ 10, 10 });
    month_calendar1.selection_range({date_time::now(), date_time::now()});
    month_calendar1.min_date(date_time::now().subtract(months(3)));
    month_calendar1.max_date(date_time::now().add(months(3)));
    month_calendar1.date_changed += [&](object&, const event_args& e) {
      debug::write_line(ustring::format("month_calendar date_changed event: [{:d}, {:d}]", month_calendar1.selection_start(), month_calendar1.selection_end()));
    };
    month_calendar1.date_selected += [&](object&, const event_args& e) {
      debug::write_line(ustring::format("month_calendar date_selected event: [{:d}, {:d}]", month_calendar1.selection_start(), month_calendar1.selection_end()));
    };
    month_calendar1.click += [&](object&, const event_args& e) {
      assert_(false);
    };
  }

private:
  month_calendar month_calendar1;
};

startup_(manual_test_form);
