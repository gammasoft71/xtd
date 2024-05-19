#include <chrono>
#include <xtd/forms/application>
#include <xtd/forms/date_time_picker>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace std::chrono;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Date time picker example");
    controls().push_back_range({picker1, label1, picker2, label2});
    
    picker1.location({30, 30});
    picker1.format(date_time_picker_format::short_format);
    picker1.value_changed += [&] {
      label1.text(picker1.value().to_short_date_string());
    };
    picker1.value(date_time::now());
    picker1.max_date(picker1.value().add(months(3)));
    picker1.min_date(picker1.value().add(months(-3)));
    
    label1.location({30, 70});
    label1.size({380, 30});
    
    picker2.location({30, 110});
    picker2.format(date_time_picker_format::time);
    picker2.value_changed += [&] {
      label2.text(picker2.value().to_long_time_string());
    };
    picker2.value(date_time::now());
    picker2.max_date(picker2.value().add(hours(3)));
    picker2.min_date(picker2.value().add(hours(-3)));
    
    label2.location({30, 150});
    label2.size({380, 30});
  }
  
private:
  date_time_picker picker1;
  label label1;
  date_time_picker picker2;
  label label2;
};

auto main() -> int {
  application::run(form1 {});
}

