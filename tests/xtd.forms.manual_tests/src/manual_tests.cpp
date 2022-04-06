#include <xtd/xtd.forms.h>
#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/forms/button_renderer.h>
#include <xtd/forms/text_renderer.h>

using namespace std::chrono;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
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
   //month_calendar1.selection_range({date_time::now(), date_time::now()});
   month_calendar1.back_color(color::blue);
   month_calendar1.selection_range({date_time(2022, 5, 8), date_time(2022, 5, 8)});
   month_calendar1.min_date(date_time::now().subtract(months(3)));
   month_calendar1.max_date(date_time::now().add(months(3)));
   month_calendar1.annually_bolded_dates({date_time(2022, 4, 1), date_time(2022, 4, 2), date_time(2022, 4, 3)});
   month_calendar1.bolded_dates({date_time(2022, 4, 27)});
   month_calendar1.show_week_numbers(true);
   month_calendar1.today_date(date_time(2022, 4, 17));

   label1.parent(*this);
   label1.auto_size(true);
   label1.location({10, 180});
   label1.text(ustring::format("selection range: [{:d}, {:d}]", month_calendar1.selection_start(), month_calendar1.selection_end()));
  }
  
private:
  month_calendar month_calendar1;
  label label1;
};

int main() {
  application::run(form1());
}

