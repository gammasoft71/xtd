#include <xtd/diagnostics/stopwatch.h>
#include <xtd/xtd.tunit>
#include <thread>

using namespace std::chrono;
using namespace std::literals;
using namespace std::this_thread;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_stopwatch) {
  public:
    void test_method_(create_stopwatch) {
      stopwatch s;
      sleep_for(1ms);
      assert::is_false_(s.is_running());
      assert::are_equal_(0ns, s.elapsed());
      assert::are_equal_(0, s.elapsed_milliseconds());
      assert::are_equal_(0, s.elapsed_nanoseconds());
      assert::are_equal_(0, s.elapsed_ticks());
    }

    void test_method_(start_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      assert::is_true_(s.is_running());
      assert::is_greater_or_equal_(s.elapsed(), 1000000ns);
      assert::is_greater_or_equal_(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal_(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal_(s.elapsed_ticks(), 10000);
    }

    void test_method_(start_start_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.start();
      assert::is_true_(s.is_running());
      assert::is_greater_or_equal_(s.elapsed(), 1000000ns);
      assert::is_greater_or_equal_(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal_(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal_(s.elapsed_ticks(), 10000);
    }

    void test_method_(stop_without_start_stopwatch) {
      stopwatch s;
      s.stop();
      sleep_for(1ms);
      assert::is_false_(s.is_running());
      assert::are_equal_(0ns, s.elapsed());
      assert::are_equal_(0, s.elapsed_milliseconds());
      assert::are_equal_(0, s.elapsed_nanoseconds());
      assert::are_equal_(0, s.elapsed_ticks());
    }

    void test_method_(start_stop_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.stop();
      assert::is_false_(s.is_running());
      assert::is_greater_or_equal_(s.elapsed(), 1000000ns);
      assert::is_greater_or_equal_(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal_(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal_(s.elapsed_ticks(), 10000);
    }

    void test_method_(start_stop_reset_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.stop();
      s.reset();
      assert::is_false_(s.is_running());
      assert::are_equal_(0ns, s.elapsed());
      assert::are_equal_(0, s.elapsed_milliseconds());
      assert::are_equal_(0, s.elapsed_nanoseconds());
      assert::are_equal_(0, s.elapsed_ticks());
    }

    void test_method_(start_reset_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.reset();
      assert::is_false_(s.is_running());
      assert::are_equal_(0ns, s.elapsed());
      assert::are_equal_(0, s.elapsed_milliseconds());
      assert::are_equal_(0, s.elapsed_nanoseconds());
      assert::are_equal_(0, s.elapsed_ticks());
    }

    void test_method_(reset_stopwatch) {
      stopwatch s;
      s.reset();
      assert::is_false_(s.is_running());
      assert::are_equal_(0ns, s.elapsed());
      assert::are_equal_(0, s.elapsed_milliseconds());
      assert::are_equal_(0, s.elapsed_nanoseconds());
      assert::are_equal_(0, s.elapsed_ticks());
    }

    void test_method_(restart_stopwatch) {
      stopwatch s;
      s.restart();
      sleep_for(1ms);
      assert::is_true_(s.is_running());
      assert::is_greater_or_equal_(s.elapsed(), 1000000ns);
      assert::is_greater_or_equal_(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal_(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal_(s.elapsed_ticks(), 10000);
    }

    void test_method_(start_new_stopwatch) {
      auto s = stopwatch::start_new();
      sleep_for(1ms);
      assert::is_true_(s.is_running());
      assert::is_greater_or_equal_(s.elapsed(), 1000000ns);
      assert::is_greater_or_equal_(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal_(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal_(s.elapsed_ticks(), 10000);
    }

    void test_method_(cumulative_elapsed_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.stop();
      auto elapsed_1 = s.elapsed_milliseconds();
      assert::is_greater_or_equal_(1, elapsed_1);
      s.start();
      sleep_for(1ms);
      s.stop();
      auto elapsed_2 = s.elapsed_milliseconds();
      assert::is_greater(elapsed_2, elapsed_1);
      s.start();
      sleep_for(1ms);
      s.stop();
      auto elapsed_3 = s.elapsed_milliseconds();
      assert::is_greater(elapsed_3, elapsed_2);
    }
  };
}
