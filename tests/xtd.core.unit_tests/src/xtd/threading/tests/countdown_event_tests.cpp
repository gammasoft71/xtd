#include <xtd/threading/countdown_event>
#include <xtd/threading/manual_reset_event>
#include <xtd/threading/thread>
#include <xtd/threading/interlocked>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/as>
#include <xtd/object_closed_exception>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(countdown_event_tests) {
    void test_method_(constructor_default) {
      auto ce = countdown_event {};
      assert::is_zero(ce.current_count(), csf_);
      assert::is_zero(ce.initial_count(), csf_);
      assert::is_true(ce.is_set(), csf_);
      assert::is_instance_of<manual_reset_event>(ce.wait_handle(), csf_);
    }
    
    void test_method_(constructor_with_0) {
      auto ce = countdown_event {0};
      assert::is_zero(ce.current_count(), csf_);
      assert::is_zero(ce.initial_count(), csf_);
      assert::is_true(ce.is_set(), csf_);
      assert::is_instance_of<manual_reset_event>(ce.wait_handle(), csf_);
    }
    
    void test_method_(constructor_with_param) {
      auto ce = countdown_event {10};
      assert::are_equal(10, ce.current_count(), csf_);
      assert::are_equal(10, ce.initial_count(), csf_);
      assert::is_false(ce.is_set(), csf_);
      assert::is_instance_of<manual_reset_event>(ce.wait_handle(), csf_);
    }
    
    void test_method_(constructor_with_invalid_param) {
      assert::throws<argument_out_of_range_exception>([] {countdown_event {-1};}, csf_);
    }
    
    void test_method_(copy_constructor) {
      auto ce1 = countdown_event {10};
      auto ce2 = ce1;
      assert::are_equal(10, ce2.current_count(), csf_);
      assert::are_equal(10, ce2.initial_count(), csf_);
      assert::is_false(ce2.is_set(), csf_);
      assert::is_instance_of<manual_reset_event>(ce2.wait_handle(), csf_);
    }
    
    void test_method_(copy_operator) {
      auto ce1 = countdown_event {10};
      auto ce2 = countdown_event {};
      ce2 = ce1;
      assert::are_equal(10, ce2.current_count(), csf_);
      assert::are_equal(10, ce2.initial_count(), csf_);
      assert::is_false(ce2.is_set(), csf_);
      assert::is_instance_of<manual_reset_event>(ce2.wait_handle(), csf_);
    }
    
    void test_method_(add_count) {
      auto ce = countdown_event {1};
      ce.add_count();
      assert::are_equal(2, ce.current_count(), csf_);
      assert::are_equal(1, ce.initial_count(), csf_);
      assert::is_false(ce.is_set(), csf_);
    }
    
    void test_method_(add_count_with_param) {
      auto ce = countdown_event {5};
      ce.add_count(3);
      assert::are_equal(8, ce.current_count(), csf_);
      assert::are_equal(5, ce.initial_count(), csf_);
      assert::is_false(ce.is_set(), csf_);
    }
    
    void test_method_(add_count_with_invalid_param) {
      auto ce = countdown_event {5};
      assert::throws<argument_out_of_range_exception>([&] {ce.add_count(-1);}, csf_);
    }
    
    void test_method_(add_count_when_coutdown_event_is_set) {
      auto ce = countdown_event {0};
      assert::throws<invalid_operation_exception>([&] {ce.add_count();}, csf_);
    }
    
    void test_method_(add_count_wth_param_when_coutdown_event_is_set) {
      auto ce = countdown_event {0};
      assert::throws<invalid_operation_exception>([&] {ce.add_count(5);}, csf_);
    }
    
    void test_method_(close) {
      auto ce = countdown_event {0};
      ce.close();
      assert::throws<object_closed_exception>([&] {ce.current_count();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.initial_count();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.is_set();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.wait_handle();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.add_count();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.add_count(2);}, csf_);
      assert::throws<object_closed_exception>([&] {ce.reset();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.signal();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.signal(2);}, csf_);
      assert::throws<object_closed_exception>([&] {ce.wait();}, csf_);
      assert::throws<object_closed_exception>([&] {ce.wait(0);}, csf_);
      assert::throws<object_closed_exception>([&] {ce.wait(time_span {0});}, csf_);
    }
    
    void test_method_(reset) {
      auto ce = countdown_event {10};
      ce.add_count(20);
      ce.signal(30);
      ce.reset();
      assert::are_equal(10, ce.current_count(), csf_);
      assert::are_equal(10, ce.initial_count(), csf_);
      assert::is_false(ce.is_set(), csf_);
    }
    
    void test_method_(signal) {
      auto ce = countdown_event {10};
      assert::are_equal(10, ce.current_count(), csf_);
      assert::are_equal(10, ce.initial_count(), csf_);
      ce.signal();
      assert::are_equal(9, ce.current_count(), csf_);
      assert::are_equal(10, ce.initial_count(), csf_);
    }
    
    void test_method_(signal_with_param) {
      auto ce = countdown_event {10};
      assert::are_equal(10, ce.current_count(), csf_);
      assert::are_equal(10, ce.initial_count(), csf_);
      ce.signal(4);
      assert::are_equal(6, ce.current_count(), csf_);
      assert::are_equal(10, ce.initial_count(), csf_);
    }
    
    void test_method_(signal_with_negative_param) {
      auto ce = countdown_event {10};
      assert::throws<argument_out_of_range_exception>([&] {ce.signal(-1);}, csf_);
    }
    
    void test_method_(signal_with_greater_param_than_intial_count) {
      auto ce = countdown_event {10};
      assert::throws<argument_out_of_range_exception>([&] {ce.signal(11);}, csf_);
    }
    
    void test_method_(wait) {
      countdown_event ce {2};
      assert::is_false(ce.wait(0), csf_);
      ce.signal();
      assert::is_false(ce.wait(0), csf_);
      ce.signal();
      assert::is_true(ce.wait(0), csf_);
    }
    
    void test_method_(wait_five_threads) {
      auto threads = std::vector<thread> {};
      auto ce = countdown_event {5};
      auto thread_action = [&] {ce.signal();};
      for (auto i = 0; i < 5; ++i)
        threads.push_back(thread::start_new(thread_action));
      assert::is_true(ce.wait(300), csf_);
      thread::join_all(threads);
    }
  };
}
