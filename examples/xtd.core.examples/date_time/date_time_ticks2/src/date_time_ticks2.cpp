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
    
    console::write_line("Elapsed from the beginning of the century to {0:f}:", current_date);
    console::write_line("   {0:N0} nanoseconds", elapsed_ticks.count() * 100);
    console::write_line("   {0:N0} ticks", elapsed_ticks.count());
    console::write_line("   {0:N2} seconds", duration_cast<seconds>(elapsed_ticks).count());
    console::write_line("   {0:N2} minutes", duration_cast<minutes>(elapsed_ticks).count());
    console::write_line("   {0:N0} days, {1} hours, {2} minutes, {3} seconds", duration_cast<days>(elapsed_ticks).count(), duration_cast<hours>(elapsed_ticks).count() % 24, duration_cast<minutes>(elapsed_ticks).count() % 60, duration_cast<seconds>(elapsed_ticks).count() % 60);
  }
};

startup_(program);

// This code can produces the following output:
//
// Elapsed from the beginning of the century to Tue Jan 11 23:28:42 2022:
//    663636522049162000 nanoseconds
//    6636365220491620 ticks
//    663636522.00 seconds
//    11060608.00 minutes
//    7680 days, 23 hours, 28 minutes, 42 seconds
