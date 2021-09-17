#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Date time picker example");
     controls().push_back_range({picker1, label1, picker2, label2});
    
    picker1.location({10, 10});
    picker1.value_changed += [&] {
      label1.text(ustring::format("{:d}", picker1.value()));
    };
    picker1.max_date(std::chrono::system_clock::now());
    picker1.min_date(1975, 4, 4);
    picker1.value(1975, 4, 4);

    label1.location({10, 50});
    label1.size({380, 340});
    
    picker2.location({10, 90});
    picker2.format(date_time_picker_format::time);
    picker2.value_changed += [&] {
      label2.text(ustring::format("{:t}", picker2.value()));
    };
    picker2.max_date(1970, 1, 1, 13, 59, 59);
    picker2.min_date(1970, 1, 1, 12, 0, 0);
    picker2.value(1970, 1, 1, 13, 0, 0);

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

