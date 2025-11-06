#include <xtd/xtd>

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

// This code can produce the following output :
//
// Elapsed from the beginning of the century to Wednesday, November 5, 2025 9:16 PM:
//    784070197635266048 nanoseconds
//    7840701976352660 ticks
//    784070197.64 seconds
//    13067836.63 minutes
//    9074 days, 21 hours, 16 minutes, 37 seconds
