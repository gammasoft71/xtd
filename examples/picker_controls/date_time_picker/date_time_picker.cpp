#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Date time picker example");
     controls().push_back_range({picker1, label1, picker2, label2});
    
    picker1.location({10, 10});
    picker1.value_changed += [&] {
      label1.text(strings::format("{:d}", picker1.value()));
    };
    picker1.max_date(std::chrono::system_clock::now());
    picker1.min_date({0, 0, 0, 4, 3, 75, 0, 0, 0, 0, nullptr});
    picker1.value({0, 0, 0, 4, 3, 75, 0, 0, 0, 0, nullptr});

    label1.location({10, 50});
    label1.size({380, 340});
    
    picker2.location({10, 90});
    picker2.format(date_time_picker_format::time);
    picker2.value_changed += [&] {
      label2.text(strings::format("{:t}", picker2.value()));
    };
    picker2.max_date({0, 58, 23, 1, 0, 70, 0, 0, 0, 0, nullptr});
    picker2.min_date({0, 0, 10, 1, 0, 70, 0, 0, 0, 0, nullptr});
    picker2.value({56, 34, 12, 1, 0, 70, 0, 0, 0, 0, nullptr});

    label2.location({10, 130});
    label2.size({380, 340});
  }
 
private:
  date_time_picker picker1;
  label label1;
  date_time_picker picker2;
  label label2;
};

int main() {
  application::run(form1());
}

