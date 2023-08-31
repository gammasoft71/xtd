#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace std::chrono;
using namespace xtd;

class program {
public:
  static auto main() {
    auto century_begin = date_time {2001, 1, 1};
    auto current_date = date_time::now();
    
    auto elapsed_ticks = current_date.ticks() - century_begin.ticks();
    auto elapsed_span = time_span {elapsed_ticks};

    console::write_line("Elapsed from the beginning of the century to {:f}:", current_date);
    console::write_line("   {:N0} nanoseconds", elapsed_ticks * 100);
    console::write_line("   {:N0} ticks", elapsed_ticks);
    console::write_line("   {:N2} seconds", elapsed_span.total_seconds());
    console::write_line("   {:N2} minutes", elapsed_span.total_minutes());
    console::write_line("   {:N0} days, {} hours, {} minutes, {} seconds", elapsed_span.days(), elapsed_span.hours(),
                        elapsed_span.minutes(), elapsed_span.seconds());
  }
};

startup_(program::main);

// This code can produces the following output:
//
// Elapsed from the beginning of the century to Wed Aug 16 22:46:16 2023:
//    713918776070706048 nanoseconds
//    7139187760707060 ticks
//    713918776.07 seconds
//    11898646.27 minutes
//    8262 days, 22 hours, 46 minutes, 16 seconds
