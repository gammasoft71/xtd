#include <xtd/threading/auto_reset_event>
#include <xtd/threading/timer>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace timer_example {
  class status_checker {
  private:
    int invoke_count = 0;
    int max_count = 0;
    
  public:
    status_checker(int count) {
      invoke_count = 0;
      max_count = count;
    }
    
    // This method is called by the timer delegate.
    void check_status(std::any state_info) {
      auto auto_event = as<auto_reset_event>(state_info);
      auto now = date_time::now();
      console::write_line("{:t}.{:D3} Checking status {,2}.",
                          now, now.millisecond(),
                          ++invoke_count);
      
      if (invoke_count == max_count) {
        // Reset the counter and signal the waiting thread.
        invoke_count = 0;
        auto_event.set();
      }
    }
  };

  class program {
  public:
    static void main() {
      // Create an auto_reset_event to signal the timeout threshold in the
      // timer callback has been reached.
      auto auto_event = auto_reset_event {false};
      
      auto status_checker = timer_example::status_checker {10};
      
      // Create a timer that invokes check_status after one second,
      // and every 1/4 second thereafter.
      auto now = date_time::now();
      console::write_line("{:t}.{:D3} Creating timer.\n",
                          now, now.millisecond());
      auto state_timer = timer {{status_checker, &timer_example::status_checker::check_status},
                                auto_event, 1000, 250};
      
      // When auto_event signals, change the period to every half second.
      auto_event.wait_one();
      state_timer.change(0, 500);
      console::write_line("\nChanging period to .5 seconds.\n");
      
      // When auto_event signals the second time, dispose of the timer.
      auto_event.wait_one();
      state_timer.close();
      console::write_line("\nDestroying timer.");
    }
  };
}

startup_(timer_example::program);

// This example produces output similar to the following:
//
// 10:37:37.167 Creating timer.
//
// 10:37:38.172 Checking status  1.
// 10:37:38.426 Checking status  2.
// 10:37:38.679 Checking status  3.
// 10:37:38.932 Checking status  4.
// 10:37:39.185 Checking status  5.
// 10:37:39.439 Checking status  6.
// 10:37:39.691 Checking status  7.
// 10:37:39.946 Checking status  8.
// 10:37:40.200 Checking status  9.
// 10:37:40.455 Checking status 10.
//
// Changing period to .5 seconds.
//
// 10:37:40.719 Checking status  1.
// 10:37:41.220 Checking status  2.
// 10:37:41.725 Checking status  3.
// 10:37:42.229 Checking status  4.
// 10:37:42.733 Checking status  5.
// 10:37:43.235 Checking status  6.
// 10:37:43.740 Checking status  7.
// 10:37:44.245 Checking status  8.
// 10:37:44.746 Checking status  9.
// 10:37:45.249 Checking status 10.
//
// Destroying timer.
