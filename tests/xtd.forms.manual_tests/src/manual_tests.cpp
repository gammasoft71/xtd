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
    m_month_calendar.value(system_clock::now()); // WORKING
    m_month_calendar.date_range(system_clock::now() - months(3), system_clock::now() + months(3));
    m_month_calendar.value_changed += [this](object&, const event_args& e) {
     message_box::show(ustring::format("month_calendar value changed event: {}", e.to_string()));
      //auto [from_date, to_date] = m_month_calendar.date_range();
      //message_box::show(ustring::format("from_date: {}\nto_date: {}", stringify_date(from_date, "%Y-%m-%d %H:%M:%S"), stringify_date(to_date, "%Y-%m-%d %H:%M:%S")));
     // message_box::show(ustring::format("month_calendar value changed: {}", e.to_string()));
    }; 
    m_month_calendar.click += [this]() {
     message_box::show("month_calendar click event");
    }; 


    m_button.parent(*this)
      .location({ 250, 250 })
      .text("click")
      .click += [this]()
    {
      auto [from_date, to_date] = m_month_calendar.date_range();
      message_box::show(ustring::format("from_date: {}\nto_date: {}", stringify_date(from_date, "%Y-%m-%d %H:%M:%S"), stringify_date(to_date, "%Y-%m-%d %H:%M:%S")));

    };
  }
  ustring stringify_date(const system_clock::time_point& time, const ustring& format)
  {
    std::time_t tt = std::chrono::system_clock::to_time_t(time);
    std::tm tm = *std::gmtime(&tt); //GMT (UTC)
    std::ostringstream ss;
    ss << std::put_time(&tm, format.c_str());
    return ss.str();
  }


private:
  month_calendar m_month_calendar;
  button m_button;
};

startup_(manual_test_form);
