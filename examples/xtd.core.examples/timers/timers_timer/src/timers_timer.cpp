#include <xtd/timers/timer>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::timers;

namespace timer_example {
  class program {
  public:
    static void main() {
      set_timer();
      
      console::write_line("\nPress the Enter key to exit the application...\n");
      console::write_line("The application started at {:t}.{:d3}", date_time::now(), date_time::now().millisecond());
      console::read_line();
      a_timer.stop();
      a_timer.close();
      
      console::write_line("Terminating the application...");
    }
     
    static void set_timer() {
      // Hook up the elapsed event for the timer.
      a_timer.elapsed += on_timed_event;
      a_timer.auto_reset(true);
      a_timer.enabled(true);
    }
    
    static void on_timed_event(object& source, const elapsed_event_args& e) {
      console::write_line("The elapsed event was raised at {:t}.{:d3}",
                          e.signal_time(), e.signal_time().millisecond());
    }
    
  private:
    // Create a timer with a two second interval.
    inline static timer a_timer {2'000};
  };
}

startup_(timer_example::program);

// This example produces output similar to the following:
//
// Press the Enter key to exit the application...
//
// The application started at 22:12:37.523
// The elapsed event was raised at 22:12:39.531
// The elapsed event was raised at 22:12:41.537
// The elapsed event was raised at 22:12:43.543
// The elapsed event was raised at 22:12:45.548
// The elapsed event was raised at 22:12:47.553
// The elapsed event was raised at 22:12:49.557
// The elapsed event was raised at 22:12:51.560
// The elapsed event was raised at 22:12:53.565
// The elapsed event was raised at 22:12:55.570
//
// Terminating the application...
