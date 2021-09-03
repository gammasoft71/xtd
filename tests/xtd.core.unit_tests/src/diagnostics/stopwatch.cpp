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
      assert::is_false(s.is_running(), csf_);
      assert::are_equal(0ns, s.elapsed(), csf_);
      assert::are_equal(0, s.elapsed_milliseconds(), csf_);
      assert::are_equal(0, s.elapsed_nanoseconds(), csf_);
      assert::are_equal(0, s.elapsed_ticks(), csf_);
    }

    void test_method_(start_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      assert::is_true(s.is_running(), csf_);
      assert::is_greater_or_equal(s.elapsed(), 1000000ns, csf_);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1, csf_);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000, csf_);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000, csf_);
    }

    void test_method_(start_start_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.start();
      assert::is_true(s.is_running(), csf_);
      assert::is_greater_or_equal(s.elapsed(), 1000000ns, csf_);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1, csf_);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000, csf_);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000, csf_);
    }

    void test_method_(stop_without_start_stopwatch) {
      stopwatch s;
      s.stop();
      sleep_for(1ms);
      assert::is_false(s.is_running(), csf_);
      assert::are_equal(0ns, s.elapsed(), csf_);
      assert::are_equal(0, s.elapsed_milliseconds(), csf_);
      assert::are_equal(0, s.elapsed_nanoseconds(), csf_);
      assert::are_equal(0, s.elapsed_ticks(), csf_);
    }

    void test_method_(start_stop_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.stop();
      assert::is_false(s.is_running(), csf_);
      assert::is_greater_or_equal(s.elapsed(), 1000000ns, csf_);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1, csf_);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000, csf_);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000, csf_);
    }

    void test_method_(start_stop_reset_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.stop();
      s.reset();
      assert::is_false(s.is_running(), csf_);
      assert::are_equal(0ns, s.elapsed(), csf_);
      assert::are_equal(0, s.elapsed_milliseconds(), csf_);
      assert::are_equal(0, s.elapsed_nanoseconds(), csf_);
      assert::are_equal(0, s.elapsed_ticks(), csf_);
    }

    void test_method_(start_reset_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.reset();
      assert::is_false(s.is_running(), csf_);
      assert::are_equal(0ns, s.elapsed(), csf_);
      assert::are_equal(0, s.elapsed_milliseconds(), csf_);
      assert::are_equal(0, s.elapsed_nanoseconds(), csf_);
      assert::are_equal(0, s.elapsed_ticks(), csf_);
    }

    void test_method_(reset_stopwatch) {
      stopwatch s;
      s.reset();
      assert::is_false(s.is_running(), csf_);
      assert::are_equal(0ns, s.elapsed(), csf_);
      assert::are_equal(0, s.elapsed_milliseconds(), csf_);
      assert::are_equal(0, s.elapsed_nanoseconds(), csf_);
      assert::are_equal(0, s.elapsed_ticks(), csf_);
    }

    void test_method_(restart_stopwatch) {
      stopwatch s;
      s.restart();
      sleep_for(1ms);
      assert::is_true(s.is_running(), csf_);
      assert::is_greater_or_equal(s.elapsed(), 1000000ns, csf_);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1, csf_);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000, csf_);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000, csf_);
    }

    void test_method_(start_new_stopwatch) {
      auto s = stopwatch::start_new();
      sleep_for(1ms);
      assert::is_true(s.is_running(), csf_);
      assert::is_greater_or_equal(s.elapsed(), 1000000ns, csf_);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1, csf_);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000, csf_);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000, csf_);
    }

    void test_method_(cumulative_elapsed_stopwatch) {
      stopwatch s;
      s.start();
      sleep_for(1ms);
      s.stop();
      auto elapsed_1 = s.elapsed_milliseconds();
      assert::is_greater_or_equal(elapsed_1, 1, csf_);
      s.start();
      sleep_for(1ms);
      s.stop();
      auto elapsed_2 = s.elapsed_milliseconds();
      assert::is_greater(elapsed_2, elapsed_1, csf_);
      s.start();
      sleep_for(1ms);
      s.stop();
      auto elapsed_3 = s.elapsed_milliseconds();
      assert::is_greater(elapsed_3, elapsed_2, csf_);
    }
  };
}
