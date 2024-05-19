#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/month_calendar>
#include <chrono>

using namespace std::chrono;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Month calendar example");
    month_calendar1.parent(*this);
    month_calendar1.location({10, 10});
    month_calendar1.date_changed += [&](object&, const event_args & e) {
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

auto main() -> int {
  application::run(form1 {});
}

