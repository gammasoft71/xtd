#include <xtd/xtd.forms>

using namespace xtd;
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
    client_size({640, 480});
     
    m_month_calendar.parent(*this);
    m_month_calendar.location({ 10, 10 });
    m_month_calendar.size({ 250, 200 });
    m_month_calendar.value(system_clock::now());
    m_month_calendar.range_date(system_clock::now() - months(3), system_clock::now() + months(3));
    m_month_calendar.value_changed += [](object&, const event_args& e) {
      message_box::show(ustring::format("month_calendar value changed: {}", e.to_string()));
    };
  }

private:
  month_calendar m_month_calendar;
};

startup_(manual_test_form);
