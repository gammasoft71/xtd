#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;
using namespace std::chrono;
using namespace std::chrono_literals;

class manual_test_form : public form {
public:
  static void main() {
    application::run(manual_test_form());
  }

  manual_test_form() {
    text("Manual tests");
    client_size({400, 220});

    month_calendar1.parent(*this);
    month_calendar1.location({10, 10});
    month_calendar1.date_changed += [&](object&, const event_args& e) {
      label1.text(ustring::format("selection range: [{:d}, {:d}]", month_calendar1.selection_start(), month_calendar1.selection_end()));
    };
    month_calendar1.selection_range({date_time::now(), date_time::now()});
    month_calendar1.min_date(date_time::now().subtract(months(3)));
    month_calendar1.max_date(date_time::now().add(months(3)));

    label1.parent(*this);
    label1.auto_size(true);
    label1.location({10, 180});
    label1.text(ustring::format("selection range: [{:d}, {:d}]", month_calendar1.selection_start(), month_calendar1.selection_end()));
  }

private:
  month_calendar month_calendar1;
  label label1;
};

startup_(manual_test_form);
