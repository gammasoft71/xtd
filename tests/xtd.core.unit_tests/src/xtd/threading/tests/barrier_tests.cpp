#include <xtd/threading/barrier>
#include <xtd/threading/thread>
#include <xtd/threading/interlocked>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(barrier_tests) {
    auto test_method_(ctr_default) {
      barrier b;
      assert::is_zero(b.participant_count());
    }
    
    auto test_method_(ctr_with_participant) {
      barrier b {5};
      assert::are_equal(5_z, b.participant_count());
    }
    
    auto test_method_(ctr_with_invalid_participant) {
      assert::throws<argument_exception>([] {barrier b {32768};});
    }
    
    auto test_method_(ctr_with_participant_and_post_phase_action) {
      barrier b {5, [&]()->barrier& {return b;}};
      assert::are_equal(5_z, b.participant_count());
    }
    
    auto test_method_(ctr_with_invalid_participant_and_post_phase_action) {
      assert::throws<argument_exception>([] {barrier b {32768, [&]()->barrier& {return b;}};});
    }
    
    auto test_method_(participant_count) {
      assert::is_zero(barrier {}.participant_count());
      assert::are_equal(5_z, barrier {5}.participant_count());
    }
    
    auto test_method_(current_phase_number) {
      assert::is_zero(barrier {}.current_phase_number());
      assert::is_zero(barrier {5}.current_phase_number());
    }
    
    auto test_method_(participants_remaining) {
      assert::is_zero(barrier {}.participants_remaining());
      assert::are_equal(5_z, barrier {5}.participants_remaining());
    }
    
    auto test_method_(add_participant) {
      barrier b {5};
      assert::are_equal(5_z, b.participant_count());
      assert::are_equal(5_z, b.participants_remaining());
      b.add_participant();
      assert::are_equal(6_z, b.participant_count());
      assert::are_equal(6_z, b.participants_remaining());
      b.add_participant();
      assert::are_equal(7_z, b.participant_count());
      assert::are_equal(7_z, b.participants_remaining());
    }
    
    auto test_method_(add_participants) {
      barrier b {5};
      assert::are_equal(5_z, b.participant_count());
      assert::are_equal(5_z, b.participants_remaining());
      b.add_participants(3);
      assert::are_equal(8_z, b.participant_count());
      assert::are_equal(8_z, b.participants_remaining());
      b.add_participants(10);
      assert::are_equal(18_z, b.participant_count());
      assert::are_equal(18_z, b.participants_remaining());
      b.add_participants(0);
      assert::are_equal(18_z, b.participant_count());
      assert::are_equal(18_z, b.participants_remaining());
    }
    
    auto test_method_(add_participants_invalid) {
      barrier b {5};
      assert::throws<argument_exception>([&] {b.add_participants(32763);});
    }
    
    auto test_method_(remove_participant) {
      barrier b {20};
      assert::are_equal(20_z, b.participant_count());
      assert::are_equal(20_z, b.participants_remaining());
      b.remove_participant();
      assert::are_equal(19_z, b.participant_count());
      assert::are_equal(19_z, b.participants_remaining());
      b.remove_participant();
      assert::are_equal(18_z, b.participant_count());
      assert::are_equal(18_z, b.participants_remaining());
    }
    
    auto test_method_(remove_participants) {
      barrier b {20};
      assert::are_equal(20_z, b.participant_count());
      assert::are_equal(20_z, b.participants_remaining());
      b.remove_participants(5);
      assert::are_equal(15_z, b.participant_count());
      assert::are_equal(15_z, b.participants_remaining());
      b.remove_participants(7);
      assert::are_equal(8_z, b.participant_count());
      assert::are_equal(8_z, b.participants_remaining());
      b.remove_participants(0);
      assert::are_equal(8_z, b.participant_count());
      assert::are_equal(8_z, b.participants_remaining());
    }
    
    auto test_method_(remove_participants_invalid) {
      barrier b {5};
      assert::throws<argument_exception>([&] {b.remove_participants(32763);});
      assert::throws<argument_exception>([&] {b.remove_participants(6);});
    }
    
    auto test_method_(signal_and_wait_with_one_participant) {
      barrier b {1};
      assert::is_zero(b.current_phase_number());
      assert::is_true(b.signal_and_wait(0));
      assert::are_equal(1_z, b.current_phase_number());
      assert::is_true(b.signal_and_wait(0));
      assert::are_equal(2_z, b.current_phase_number());
    }
    
    auto test_method_(signal_and_wait_with_one_participant_and_post_phase_action) {
      auto post_phase_action_count = 0_z;
      barrier b {1, [&] {++post_phase_action_count;}};
      assert::is_zero(post_phase_action_count);
      assert::is_zero(b.current_phase_number());
      assert::is_true(b.signal_and_wait(0));
      assert::are_equal(1_z, b.current_phase_number());
      assert::are_equal(1_z, post_phase_action_count);
      assert::is_true(b.signal_and_wait(0));
      assert::are_equal(2_z, b.current_phase_number());
      assert::are_equal(2_z, post_phase_action_count);
    }
    
    auto test_method_(signal_and_wait_with_participants) {
      barrier b {3};
      auto thread_ran_count = 0;
      auto thread_action = [&] {
        interlocked::increment(thread_ran_count);
        assert::is_true(b.signal_and_wait(50));
      };
      auto t1 = thread::start_new(thread_action);
      auto t2 = thread::start_new(thread_action);
      assert::is_zero(b.current_phase_number());
      assert::is_true(b.signal_and_wait(50));
      thread::join_all({t1, t2});
      assert::are_equal(1_z, b.current_phase_number());
      assert::are_equal(2, thread_ran_count);
    }
    
    auto test_method_(signal_and_wait_with_participants_and_post_phase_action) {
      auto post_phase_action_count = 0_z;
      auto thread_ran_count = 0;
      barrier b {3, [&] {
          ++post_phase_action_count;
          assert::are_equal(2, thread_ran_count);
        }
      };
      auto thread_action = [&] {
        interlocked::increment(thread_ran_count);
        assert::is_true(b.signal_and_wait(50));
      };
      auto t1 = thread::start_new(thread_action);
      auto t2 = thread::start_new(thread_action);
      assert::is_zero(b.current_phase_number());
      assert::is_true(b.signal_and_wait(50));
      thread::join_all({t1, t2});
      assert::are_equal(1_z, b.current_phase_number());
      assert::are_equal(1_z, post_phase_action_count);
      assert::are_equal(2, thread_ran_count);
    }
  };
}
