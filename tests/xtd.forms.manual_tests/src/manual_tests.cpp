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
		client_size({ 640, 480 });

		m_month_calendar.parent(*this);
		m_month_calendar.location({ 10, 10 });
		m_month_calendar.value(system_clock::now());
		m_month_calendar.min_date(system_clock::now() - months(3));
		m_month_calendar.max_date(system_clock::now() + months(3));
		m_month_calendar.value_changed += [this](object&, const event_args& e) {
			message_box::show(ustring::format("month_calendar value_changed event: {}", stringify_date(m_month_calendar.value())));
		};
		m_month_calendar.click += [this]() {
			message_box::show(ustring::format("month_calendar click event: {}", stringify_date(m_month_calendar.value())));
		};
	}

	ustring stringify_date(const system_clock::time_point& date, const ustring& format = "%Y-%m-%d %H:%M:%S") {
		std::time_t tt = std::chrono::system_clock::to_time_t(date);
		std::tm tm = *std::gmtime(&tt); //GMT (UTC)
		std::ostringstream ss{};
		ss << std::put_time(&tm, format.c_str());
		return ss.str();
	}

private:
	month_calendar m_month_calendar;
};

startup_(manual_test_form);
