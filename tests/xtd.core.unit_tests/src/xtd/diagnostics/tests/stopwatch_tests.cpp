#include <xtd/diagnostics/stopwatch>
#include <xtd/threading/thread>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::diagnostics::tests {
  class test_class_(stopwatch_tests) {
    void test_method_(create_stopwatch) {
      stopwatch s;
      thread::sleep(1_ms);
      assert::is_false(s.is_running());
      assert::are_equal(0_ns, s.elapsed());
      assert::are_equal(0, s.elapsed_milliseconds());
      assert::are_equal(0, s.elapsed_nanoseconds());
      assert::are_equal(0, s.elapsed_ticks());
    }
    
    void test_method_(start_stopwatch) {
      stopwatch s;
      s.start();
      thread::sleep(1_ms);
      assert::is_true(s.is_running());
      assert::is_greater_or_equal(s.elapsed(), 1000000_ns);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000);
    }
    
    void test_method_(start_start_stopwatch) {
      stopwatch s;
      s.start();
      thread::sleep(1_ms);
      s.start();
      assert::is_true(s.is_running());
      assert::is_greater_or_equal(s.elapsed(), 1000000_ns);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000);
    }
    
    void test_method_(stop_without_start_stopwatch) {
      stopwatch s;
      s.stop();
      thread::sleep(1_ms);
      assert::is_false(s.is_running());
      assert::are_equal(0_ns, s.elapsed());
      assert::are_equal(0, s.elapsed_milliseconds());
      assert::are_equal(0, s.elapsed_nanoseconds());
      assert::are_equal(0, s.elapsed_ticks());
    }
    
    void test_method_(start_stop_stopwatch) {
      stopwatch s;
      s.start();
      thread::sleep(1_ms);
      s.stop();
      assert::is_false(s.is_running());
      assert::is_greater_or_equal(s.elapsed(), 1000000_ns);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000);
    }
    
    void test_method_(start_stop_reset_stopwatch) {
      stopwatch s;
      s.start();
      thread::sleep(1_ms);
      s.stop();
      s.reset();
      assert::is_false(s.is_running());
      assert::are_equal(0_ns, s.elapsed());
      assert::are_equal(0, s.elapsed_milliseconds());
      assert::are_equal(0, s.elapsed_nanoseconds());
      assert::are_equal(0, s.elapsed_ticks());
    }
    
    void test_method_(start_reset_stopwatch) {
      stopwatch s;
      s.start();
      thread::sleep(1_ms);
      s.reset();
      assert::is_false(s.is_running());
      assert::are_equal(0_ns, s.elapsed());
      assert::are_equal(0, s.elapsed_milliseconds());
      assert::are_equal(0, s.elapsed_nanoseconds());
      assert::are_equal(0, s.elapsed_ticks());
    }
    
    void test_method_(reset_stopwatch) {
      stopwatch s;
      s.reset();
      assert::is_false(s.is_running());
      assert::are_equal(0_ns, s.elapsed());
      assert::are_equal(0, s.elapsed_milliseconds());
      assert::are_equal(0, s.elapsed_nanoseconds());
      assert::are_equal(0, s.elapsed_ticks());
    }
    
    void test_method_(restart_stopwatch) {
      stopwatch s;
      s.restart();
      thread::sleep(1_ms);
      assert::is_true(s.is_running());
      assert::is_greater_or_equal(s.elapsed(), 1000000_ns);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000);
    }
    
    void test_method_(start_new_stopwatch) {
      auto s = stopwatch::start_new();
      thread::sleep(1_ms);
      assert::is_true(s.is_running());
      assert::is_greater_or_equal(s.elapsed(), 1000000_ns);
      assert::is_greater_or_equal(s.elapsed_milliseconds(), 1);
      assert::is_greater_or_equal(s.elapsed_nanoseconds(), 1000000);
      assert::is_greater_or_equal(s.elapsed_ticks(), 10000);
    }
    
    void test_method_(cumulative_elapsed_stopwatch) {
      stopwatch s;
      s.start();
      thread::sleep(1_ms);
      s.stop();
      auto elapsed_1 = s.elapsed_milliseconds();
      assert::is_greater_or_equal(elapsed_1, 1);
      s.start();
      thread::sleep(1_ms);
      s.stop();
      auto elapsed_2 = s.elapsed_milliseconds();
      assert::is_greater(elapsed_2, elapsed_1);
      s.start();
      thread::sleep(1_ms);
      s.stop();
      auto elapsed_3 = s.elapsed_milliseconds();
      assert::is_greater(elapsed_3, elapsed_2);
    }
  };
}
