#include <xtd/console>
#include <xtd/startup>
#include <xtd/date_time>
#include <xtd/time_span>

using namespace xtd;

namespace uri_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      // Define two dates.
      auto date1 = date_time {2010, 1, 1, 8, 0, 15};
      auto date2 = date_time {2010, 8, 18, 13, 30, 30};
      
      // Calculate the interval between the two dates.
      time_span interval = date2 - date1;
      console::write_line("{0} - {1} = {2}", date2, date1, interval.to_string());
      
      // Display individual properties of the resulting TimeSpan object.
      console::write_line("   {0,-35} {1,20}", "Value of Days Component:", interval.days());
      console::write_line("   {0,-35} {1,20}", "Total Number of Days:", interval.total_days());
      console::write_line("   {0,-35} {1,20}", "Value of Hours Component:", interval.hours());
      console::write_line("   {0,-35} {1,20}", "Total Number of Hours:", interval.total_hours());
      console::write_line("   {0,-35} {1,20}", "Value of Minutes Component:", interval.minutes());
      console::write_line("   {0,-35} {1,20}", "Total Number of Minutes:", interval.total_minutes());
      console::write_line("   {0,-35} {1,20:N0}", "Value of Seconds Component:", interval.seconds());
      console::write_line("   {0,-35} {1,20:N0}", "Total Number of Seconds:", interval.total_seconds());
      console::write_line("   {0,-35} {1,20:N0}", "Value of Milliseconds Component:", interval.milliseconds());
      console::write_line("   {0,-35} {1,20:N0}", "Total Number of Milliseconds:", interval.total_milliseconds());
      console::write_line("   {0,-35} {1,20:N0}", "Ticks:", interval.ticks());
    }
  };
}

startup_(uri_example::program);

// This code produces the following output:
//
// Wed Aug 18 13:30:30 2010 - Fri Jan  1 08:00:15 2010 = 229.05:30:15
//    Value of Days Component:                             229
//    Total Number of Days:                   229.229340277778
//    Value of Hours Component:                              5
//    Total Number of Hours:                  5501.50416666667
//    Value of Minutes Component:                           30
//    Total Number of Minutes:                       330090.25
//    Value of Seconds Component:                           15
//    Total Number of Seconds:                      19,805,415
//    Value of Milliseconds Component:                       0
//    Total Number of Milliseconds:             19,805,415,000
//    Ticks:                               198,054,150,000,000
