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

    m_month_calendar.parent(*this);
    m_month_calendar.location({ 10, 10 });
    m_month_calendar.value(system_clock::now());
    m_month_calendar.min_date(system_clock::now() - months(3));
    m_month_calendar.max_date(system_clock::now() + months(3));
    m_month_calendar.date_changed += [&](object&, const event_args& e) {
      debug::write_line(ustring::format("month_calendar date_changed event: {:d}", m_month_calendar.value()));
    };
    m_month_calendar.date_selected += [&](object&, const event_args& e) {
      debug::write_line(ustring::format("month_calendar date_selected event: {:d}", m_month_calendar.value()));
      debug::write_line("month_calendar date selected");
    };
    m_month_calendar.click += [&](object&, const event_args& e) {
      debug::write_line("Click must not trigged!!!");
    };
  }

private:
  month_calendar m_month_calendar;
};

startup_(manual_test_form);
