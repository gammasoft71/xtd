#include <xtd/threading/barrier>
#include <xtd/threading/thread>
#include <xtd/threading/interlocked>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(barrier_tests) {
    void test_method_(ctr_default) {
      barrier b;
      assert::is_zero(b.participant_count(), csf_);
    }

    void test_method_(ctr_with_participant) {
      barrier b {5};
      assert::are_equal(5, b.participant_count(), csf_);
    }
    
    void test_method_(ctr_with_invalid_participant) {
      assert::throws<argument_exception>([] {barrier b {-1};}, csf_);
    }

    void test_method_(ctr_with_participant_and_post_phase_action) {
      barrier b {5, [&]()->barrier& {return b;}};
      assert::are_equal(5, b.participant_count(), csf_);
    }
    
    void test_method_(ctr_with_invalid_participant_and_post_phase_action) {
      assert::throws<argument_exception>([] {barrier b {-1, [&]()->barrier& {return b;}};}, csf_);
    }

    void test_method_(participant_count) {
      assert::is_zero(barrier {}.participant_count(), csf_);
      assert::are_equal(5, barrier {5}.participant_count(), csf_);
    }

    void test_method_(current_phase_number) {
      assert::is_zero(barrier {}.current_phase_number(), csf_);
      assert::is_zero(barrier {5}.current_phase_number(), csf_);
    }

    void test_method_(participants_remaining) {
      assert::is_zero(barrier {}.participants_remaining(), csf_);
      assert::are_equal(5, barrier {5}.participants_remaining(), csf_);
    }

    void test_method_(add_participant) {
      barrier b {5};
      assert::are_equal(5, b.participant_count(), csf_);
      assert::are_equal(5, b.participants_remaining(), csf_);
      b.add_participant();
      assert::are_equal(6, b.participant_count(), csf_);
      assert::are_equal(6, b.participants_remaining(), csf_);
      b.add_participant();
      assert::are_equal(7, b.participant_count(), csf_);
      assert::are_equal(7, b.participants_remaining(), csf_);
    }

    void test_method_(add_participants) {
      barrier b {5};
      assert::are_equal(5, b.participant_count(), csf_);
      assert::are_equal(5, b.participants_remaining(), csf_);
      b.add_participants(3);
      assert::are_equal(8, b.participant_count(), csf_);
      assert::are_equal(8, b.participants_remaining(), csf_);
      b.add_participants(10);
      assert::are_equal(18, b.participant_count(), csf_);
      assert::are_equal(18, b.participants_remaining(), csf_);
      b.add_participants(0);
      assert::are_equal(18, b.participant_count(), csf_);
      assert::are_equal(18, b.participants_remaining(), csf_);
    }
    
    void test_method_(add_participants_invalid) {
      barrier b {5};
      assert::throws<argument_exception>([&] {b.add_participants(-1);}, csf_);
      assert::throws<argument_exception>([&] {b.add_participants(32763);}, csf_);
    }
    
    void test_method_(remove_participant) {
      barrier b {20};
      assert::are_equal(20, b.participant_count(), csf_);
      assert::are_equal(20, b.participants_remaining(), csf_);
      b.remove_participant();
      assert::are_equal(19, b.participant_count(), csf_);
      assert::are_equal(19, b.participants_remaining(), csf_);
      b.remove_participant();
      assert::are_equal(18, b.participant_count(), csf_);
      assert::are_equal(18, b.participants_remaining(), csf_);
    }
    
    void test_method_(remove_participants) {
      barrier b {20};
      assert::are_equal(20, b.participant_count(), csf_);
      assert::are_equal(20, b.participants_remaining(), csf_);
      b.remove_participants(5);
      assert::are_equal(15, b.participant_count(), csf_);
      assert::are_equal(15, b.participants_remaining(), csf_);
      b.remove_participants(7);
      assert::are_equal(8, b.participant_count(), csf_);
      assert::are_equal(8, b.participants_remaining(), csf_);
      b.remove_participants(0);
      assert::are_equal(8, b.participant_count(), csf_);
      assert::are_equal(8, b.participants_remaining(), csf_);
    }
    
    void test_method_(remove_participants_invalid) {
      barrier b {5};
      assert::throws<argument_exception>([&] {b.remove_participants(-1);}, csf_);
      assert::throws<argument_exception>([&] {b.remove_participants(6);}, csf_);
    }
    
    void test_method_(signal_and_wait_with_one_participant) {
      barrier b {1};
      assert::are_equal(0, b.current_phase_number(), csf_);
      assert::is_true(b.signal_and_wait(0), csf_);
      assert::are_equal(1, b.current_phase_number(), csf_);
      assert::is_true(b.signal_and_wait(0), csf_);
      assert::are_equal(2, b.current_phase_number(), csf_);
    }
    
    void test_method_(signal_and_wait_with_one_participant_and_post_phase_action) {
      auto post_phase_action_count = 0;
      barrier b {1, [&] {++post_phase_action_count;}};
      assert::is_zero(post_phase_action_count, csf_);
      assert::are_equal(0, b.current_phase_number(), csf_);
      assert::is_true(b.signal_and_wait(0), csf_);
      assert::are_equal(1, b.current_phase_number(), csf_);
      assert::are_equal(1, post_phase_action_count, csf_);
      assert::is_true(b.signal_and_wait(0), csf_);
      assert::are_equal(2, b.current_phase_number(), csf_);
      assert::are_equal(2, post_phase_action_count, csf_);
    }
    
    void test_method_(signal_and_wait_with_participants) {
      barrier b {3};
      auto thread_ran_count = 0;
      auto thread_action = [&] {
        interlocked::increment(thread_ran_count);
        assert::is_true(b.signal_and_wait(50), csf_);
      };
      auto t1 = thread::start_new(thread_action);
      auto t2 = thread::start_new(thread_action);
      assert::are_equal(0, b.current_phase_number(), csf_);
      assert::is_true(b.signal_and_wait(50), csf_);
      thread::join_all({t1, t2});
      assert::are_equal(1, b.current_phase_number(), csf_);
      assert::are_equal(2, thread_ran_count, csf_);
    }
    
    void test_method_(signal_and_wait_with_participants_and_post_phase_action) {
      auto post_phase_action_count = 0;
      auto thread_ran_count = 0;
      barrier b {3, [&] {
        ++post_phase_action_count;
        assert::are_equal(2, thread_ran_count, csf_);
      }
      };
      auto thread_action = [&] {
        interlocked::increment(thread_ran_count);
        assert::is_true(b.signal_and_wait(50), csf_);
      };
      auto t1 = thread::start_new(thread_action);
      auto t2 = thread::start_new(thread_action);
      assert::are_equal(0, b.current_phase_number(), csf_);
      assert::is_true(b.signal_and_wait(50), csf_);
      thread::join_all({t1, t2});
      assert::are_equal(1, b.current_phase_number(), csf_);
      assert::are_equal(2, thread_ran_count, csf_);
      assert::are_equal(1, post_phase_action_count, csf_);
    }
  };
}
