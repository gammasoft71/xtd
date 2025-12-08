#include <xtd/threading/thread>
#include <xtd/threading/thread_interrupted_exception>
#include <xtd/threading/thread_state_exception>
#include <xtd/threading/interlocked>
#include <xtd/diagnostics/stopwatch>
#include <xtd/collections/generic/list>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/diagnostics/debugger>
#include <thread>

using namespace xtd::collections::generic;
using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(thread_tests) {
    auto test_method_(constructor_empty) {
      auto thread = threading::thread {};
      assert::are_equal(threading::thread::invalid_handle, thread.handle());
      assert::is_false(thread.is_alive());
      assert::is_false(thread.is_background());
      assert::is_false(thread.is_thread_pool_thread());
      assert::is_false(thread.joinable());
      assert::is_zero(thread.managed_thread_id());
      assert::is_empty(thread.name());
      assert::are_equal(threading::thread::invalid_thread_id, thread.thread_id());
      assert::are_equal(thread_priority::normal, thread.priority());
      assert::are_equal(thread_state::unstarted, thread.thread_state());
    }
    
    auto test_method_(constructor_with_empty_thread_start) {
      assert::throws<argument_exception>([] {thread t {thread_start {}};});
    }
    
    auto test_method_(constructor_with_thread_start_and_negative_max_stack_size) {
      assert::throws<argument_exception>([] {thread t {thread_start {[] {}}, -1};});
    }
    
    auto test_method_(constructor_with_thread_start) {
      auto thread = threading::thread {thread_start {[] {}}};
      assert::are_equal(threading::thread::invalid_handle, thread.handle());
      assert::is_false(thread.is_alive());
      assert::is_false(thread.is_background());
      assert::is_false(thread.is_thread_pool_thread());
      assert::is_false(thread.joinable());
      assert::is_not_zero(thread.managed_thread_id());
      assert::is_empty(thread.name());
      assert::are_equal(thread::invalid_thread_id, thread.thread_id());
      assert::are_equal(thread_priority::normal, thread.priority());
      assert::are_equal(thread_state::unstarted, thread.thread_state());
    }
    
    auto test_method_(constructor_with_empty_parameterized_thread_start) {
      assert::throws<argument_exception>([] {thread t {parameterized_thread_start {}};});
    }
    
    auto test_method_(constructor_with_parameterized_thread_start_and_negative_max_stack_size) {
      assert::throws<argument_exception>([] {thread t {parameterized_thread_start {[](const any_object&) {}}, -1};});
    }
    
    auto test_method_(constructor_with_parameterized_thread_start) {
      auto thread = threading::thread {parameterized_thread_start {[](const any_object&) {}}};
      assert::are_equal(threading::thread::invalid_handle, thread.handle());
      assert::is_false(thread.is_alive());
      assert::is_false(thread.is_background());
      assert::is_false(thread.is_thread_pool_thread());
      assert::is_false(thread.joinable());
      assert::is_not_zero(thread.managed_thread_id());
      assert::is_empty(thread.name());
      assert::are_equal(threading::thread::invalid_thread_id, thread.thread_id());
      assert::are_equal(thread_priority::normal, thread.priority());
      assert::are_equal(thread_state::unstarted, thread.thread_state());
    }
    
    auto test_method_(main_as_current_thread) {
      auto thread = threading::thread::current_thread();
      assert::are_not_equal(threading::thread::invalid_handle, thread.handle());
      assert::is_true(thread.is_alive());
      assert::is_false(thread.is_background());
      assert::is_false(thread.is_thread_pool_thread());
      assert::is_true(thread.joinable());
      assert::are_equal(1, thread.managed_thread_id());
      assert::is_empty(thread.name());
      assert::are_not_equal(threading::thread::invalid_thread_id, thread.thread_id());
      assert::are_equal(thread_priority::normal, thread.priority());
      assert::are_equal(thread_state::running, thread.thread_state());
    }
    
    auto test_method_(std_thread_as_current_thread) {
      bool thread_ran = false;
      auto thread = std::thread {[&] {
          thread_ran = true;
          auto thread = threading::thread::current_thread();
          assert::are_not_equal(threading::thread::invalid_handle, thread.handle());
          assert::is_true(thread.is_alive());
          assert::is_true(thread.is_background());
          assert::is_false(thread.is_thread_pool_thread());
          assert::is_false(thread.joinable());
          assert::are_equal(0, thread.managed_thread_id());
          assert::is_empty(thread.name());
          assert::are_not_equal(threading::thread::invalid_thread_id, thread.thread_id());
          assert::are_equal(thread_priority::normal, thread.priority());
          //assert::is_true(thread.thread_state() == threading::thread_state::background || thread.thread_state() == (threading::thread_state::background | threading::thread_state::wait_sleep_join));
        }};
      if (thread.joinable()) thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(xtd_threading_as_current_thread) {
      bool thread_ran = false;
      auto thread = threading::thread {thread_start {[&] {
            thread_ran = true;
            auto thread = threading::thread::current_thread();
            assert::are_not_equal(threading::thread::invalid_handle, thread.handle());
            assert::is_true(thread.is_alive());
            assert::is_false(thread.is_background());
            assert::is_false(thread.is_thread_pool_thread());
            assert::is_true(thread.joinable());
            assert::are_not_equal(0, thread.managed_thread_id());
            assert::are_not_equal(1, thread.managed_thread_id());
            assert::is_empty(thread.name());
            assert::are_not_equal(threading::thread::invalid_thread_id, thread.thread_id());
            assert::are_equal(thread_priority::normal, thread.priority());
            assert::is_true(thread.thread_state() == threading::thread_state::running || thread.thread_state() == threading::thread_state::wait_sleep_join);
          }}};
      thread.start();
      if (thread.joinable()) thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(handle) {
      assert::is_not_zero(threading::thread::current_thread().handle());
      assert::are_not_equal(threading::thread::invalid_handle, threading::thread::current_thread().thread_id());
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::are_equal(threading::thread::invalid_handle, thread.handle());
      auto thread2 = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::are_equal(threading::thread::invalid_handle, thread2.handle());
      thread.start();
      assert::are_not_equal(threading::thread::invalid_handle, thread.handle());
      thread2.start();
      assert::are_not_equal(threading::thread::invalid_handle, thread2.handle());
      assert::are_not_equal(thread.thread_id(), thread2.handle());
    }
    
    auto test_method_(is_alive) {
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_false(thread.is_alive());
      thread.start();
      assert::is_true(thread.is_alive());
      thread.join();
      assert::is_false(thread.is_alive());
    }
    
    auto test_method_(is_background) {
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_false(thread.is_background());
      thread.is_background(true);
      assert::is_true(thread.is_background());
      thread.is_background(false);
      assert::is_false(thread.is_background());
    }
    
    auto test_method_(is_main_thread) {
      assert::is_true(threading::thread::current_thread().is_main_thread());
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      thread.start();
      assert::is_false(thread.is_main_thread());
    }
    
    auto test_method_(is_thread_pool_thread) {
      assert::is_false(threading::thread::current_thread().is_thread_pool_thread());
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      thread.start();
      assert::is_false(thread.is_thread_pool_thread());
    }
    
    auto test_method_(joinable) {
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_false(thread.joinable());
      thread.start();
      assert::is_true(thread.joinable());
      thread.join();
      assert::is_false(thread.joinable());
    }
    
    auto test_method_(managed_thread_id) {
      assert::are_equal(1, threading::thread::current_thread().managed_thread_id());
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      auto thread2 = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_greater(thread.managed_thread_id(), 1);
      assert::are_equal(thread.managed_thread_id() + 1, thread2.managed_thread_id());
    }
    
    auto test_method_(name) {
      auto thread = threading::thread {thread_start {[] {
            threading::thread::current_thread().name("other");
            assert::are_equal("other", threading::thread::current_thread().name());
            
          }}};
      assert::is_empty(thread.name());
      thread.name("thread");
      assert::are_equal("thread", thread.name());
      thread.start();
      thread.join();
      assert::are_equal("other", thread.name());
    }
    
    auto test_method_(priority) {
      auto thread = threading::thread {thread_start {[] {
            assert::are_equal(thread_priority::normal, threading::thread::current_thread().priority());
            threading::thread::current_thread().priority(xtd::threading::thread_priority::lowest);
            assert::are_equal(thread_priority::lowest, threading::thread::current_thread().priority());
            threading::thread::current_thread().priority(xtd::threading::thread_priority::below_normal);
            assert::are_equal(thread_priority::below_normal, threading::thread::current_thread().priority());
            threading::thread::current_thread().priority(xtd::threading::thread_priority::above_normal);
            assert::are_equal(thread_priority::above_normal, threading::thread::current_thread().priority());
            threading::thread::current_thread().priority(xtd::threading::thread_priority::highest);
            assert::are_equal(thread_priority::highest, threading::thread::current_thread().priority());
            threading::thread::current_thread().priority(xtd::threading::thread_priority::normal);
            assert::are_equal(thread_priority::normal, threading::thread::current_thread().priority());
            threading::thread::current_thread().priority(xtd::threading::thread_priority::above_normal);
          }}};
      assert::are_equal(thread_priority::normal, thread.priority());
      thread.priority(xtd::threading::thread_priority::lowest);
      assert::are_equal(thread_priority::lowest, thread.priority());
      thread.priority(xtd::threading::thread_priority::below_normal);
      assert::are_equal(thread_priority::below_normal, thread.priority());
      thread.priority(xtd::threading::thread_priority::above_normal);
      assert::are_equal(thread_priority::above_normal, thread.priority());
      thread.priority(xtd::threading::thread_priority::highest);
      assert::are_equal(thread_priority::highest, thread.priority());
      thread.priority(xtd::threading::thread_priority::normal);
      assert::are_equal(thread_priority::normal, thread.priority());
      thread.start();
      thread.join();
      assert::are_equal(thread_priority::above_normal, thread.priority());
    }
    
    auto test_method_(priority_argument_exception) {
      auto thread = threading::thread {thread_start {[] {}}};
      assert::throws<argument_exception>([&] {thread.priority(as<xtd::threading::thread_priority>(10));});
    }
    
    auto test_method_(priority_thread_state_exception) {
      auto thread = threading::thread {thread_start {[] {}}};
      thread.start();
      thread.join();
      assert::throws<thread_state_exception>([&] {thread.priority(xtd::threading::thread_priority::lowest);});
    }
    
    auto test_method_(thread_id) {
      assert::is_not_zero(threading::thread::current_thread().thread_id());
      assert::are_not_equal(threading::thread::invalid_handle, threading::thread::current_thread().thread_id());
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::are_equal(threading::thread::invalid_handle, thread.thread_id());
      auto thread2 = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::are_equal(threading::thread::invalid_handle, thread2.thread_id());
      thread.start();
      assert::are_not_equal(threading::thread::invalid_handle, thread.thread_id());
      thread2.start();
      assert::are_not_equal(threading::thread::invalid_handle, thread2.thread_id());
      assert::are_not_equal(thread.thread_id(), thread2.thread_id());
    }
    
    auto test_method_(thread_state) {
      assert::are_equal(threading::thread_state::running, threading::thread::current_thread().thread_state());
      auto thread = threading::thread {thread_start {[] {
            assert::is_true(threading::thread::current_thread().thread_state() == threading::thread_state::running || threading::thread::current_thread().thread_state() == threading::thread_state::wait_sleep_join);
            thread::sleep(50);
          }}};
      assert::are_equal(threading::thread_state::unstarted, thread.thread_state());
      thread.start();
      thread::sleep(20);
      thread.join();
      assert::are_equal(threading::thread_state::stopped, thread.thread_state());
    }
    
    auto test_method_(current_thread) {
      assert::is_true(threading::thread::current_thread().is_alive());
      assert::is_false(threading::thread::current_thread().is_background());
      assert::is_true(threading::thread::current_thread().is_main_thread());
      assert::is_false(threading::thread::current_thread().is_thread_pool_thread());
      assert::is_true(threading::thread::current_thread().joinable());
      assert::are_equal(1, threading::thread::current_thread().managed_thread_id());
      assert::is_empty(threading::thread::current_thread().name());
      assert::are_equal(thread_priority::normal, threading::thread::current_thread().priority());
      assert::are_equal(threading::thread::current_thread().thread_id(), threading::thread::current_thread().thread_id());
      assert::are_equal(threading::thread_state::running, threading::thread::current_thread().thread_state());
      
      threading::thread thread2;
      threading::thread thread = threading::thread {thread_start {[&] {
            assert::are_equal(thread.thread_id(), threading::thread::current_thread().thread_id());
            assert::is_false(threading::thread::current_thread().is_background());
            assert::is_false(threading::thread::current_thread().is_main_thread());
            assert::is_false(threading::thread::current_thread().is_thread_pool_thread());
            assert::is_true(threading::thread::current_thread().joinable());
            assert::is_greater_or_equal(threading::thread::current_thread().managed_thread_id(), 2);
            assert::is_empty(threading::thread::current_thread().name());
            assert::are_equal(thread_priority::normal, threading::thread::current_thread().priority());
            assert::are_equal(threading::thread::current_thread().thread_id(), threading::thread::current_thread().thread_id());
            assert::is_true(threading::thread::current_thread().thread_state() == threading::thread_state::running || threading::thread::current_thread().thread_state() == threading::thread_state::wait_sleep_join);
            thread2 = threading::thread::current_thread();
          }}};
      thread.start();
      thread.join();
      assert::are_equal(thread2.thread_id(), thread.thread_id());
    }
    
    auto test_method_(main_thread) {
      assert::are_equal(threading::thread::current_thread().handle(), threading::thread::main_thread().handle());
      assert::is_true(threading::thread::main_thread().is_alive());
      assert::is_false(threading::thread::main_thread().is_background());
      assert::is_true(threading::thread::main_thread().is_main_thread());
      assert::is_false(threading::thread::main_thread().is_thread_pool_thread());
      assert::is_true(threading::thread::main_thread().joinable());
      assert::are_equal(1, threading::thread::main_thread().managed_thread_id());
      assert::is_empty(threading::thread::main_thread().name());
      assert::are_equal(thread_priority::normal, threading::thread::main_thread().priority());
      assert::are_equal(threading::thread::current_thread().thread_id(), threading::thread::main_thread().thread_id());
      assert::are_equal(threading::thread_state::running, threading::thread::main_thread().thread_state());
    }
    
    auto test_method_(abort) {
      if (environment::os_version().is_windows()) assert::ignore("Ignore \"abort\" unit test on Windows (The timing is not constant)");
      
      bool thread_aborted = false;
      auto thread = threading::thread {thread_start {[&] {
            thread_aborted = true;
            thread::sleep(20);
            thread_aborted = false;
          }}};
      thread.start();
      assert::is_false(thread_aborted);
      thread::sleep(1);
      thread.abort();
      thread::sleep(30);
      assert::is_true(thread_aborted);
    }
    
    auto test_method_(abort_main_thread) {
      if (diagnostics::debugger::is_attached()) assert::ignore("Ignore \"abort_main_thread\" test when debugger is attached");
      
      bool main_thread_aborted = false;
      auto on_signal_event = signal_cancel_event_handler {[&](signal_cancel_event_args & e) {
        main_thread_aborted = e.signal() == signal::abnormal_termination;
        e.cancel(e.signal() == signal::abnormal_termination);
      }};
      
      assert::is_false(main_thread_aborted);
      environment::cancel_signal += on_signal_event;
      threading::thread::current_thread().abort();
      environment::cancel_signal -= on_signal_event;
      assert::is_true(main_thread_aborted);
    }
    
    auto test_method_(abort_state_exception) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      assert::throws<thread_state_exception>([&] {thread.abort();});
    }
    
    auto test_method_(detach) {
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_false(thread.is_background());
      thread.detach();
      assert::is_true(thread.is_background());
    }
    
    auto test_method_(interrupt) {
      if (environment::os_version().is_windows()) assert::ignore("Ignore \"interrupt\" unit test on Windows (The timing is not constant)");
      bool thread_interrupted = false;
      auto thread = threading::thread {thread_start {[&] {
            try {
              for (auto index = 0; index < 30; ++index)
                thread::sleep(1);
                
            } catch (const thread_interrupted_exception&) {
              thread_interrupted = true;
            }
          }}};
      thread.start();
      assert::is_false(thread_interrupted);
      thread::sleep(1);
      thread.interrupt();
      thread::sleep(10);
      assert::is_true(thread_interrupted);
    }
    
    auto test_method_(interrupt_main_thread) {
      if (diagnostics::debugger::is_attached()) assert::ignore("Ignore \"interrupt_main_thread\" test when debugger is attached");
      
      bool thread_interrupted = false;
      assert::is_false(thread_interrupted);
      threading::thread::current_thread().interrupt();
      auto on_signal_event = signal_cancel_event_handler {[&](signal_cancel_event_args & e) {
        thread_interrupted = e.signal() == signal::interrupt;
        e.cancel(e.signal() == signal::interrupt);
      }};
      
      environment::cancel_signal += on_signal_event;
      thread::sleep(1);
      environment::cancel_signal -= on_signal_event;
      assert::is_true(thread_interrupted);
    }
    
    auto test_method_(join) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      thread.start();
      assert::does_not_throw([&] {thread.join();});
    }
    
    auto test_method_(join_and_join) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      thread.start();
      assert::does_not_throw([&] {thread.join();});
      assert::does_not_throw([&] {thread.join();});
    }
    
    auto test_method_(join_with_milliseconds_timeout) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(50);}}};
      thread.start();
      thread::sleep(3);
      assert::is_false(thread.join(5));
      thread.join();
    }
    
    auto test_method_(join_with_timeout) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(50);}}};
      thread.start();
      thread::sleep(3);
      assert::is_false(thread.join(time_span::from_milliseconds(5.0)));
      thread.join();
    }
    
    auto test_method_(join_without_start) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      assert::throws<thread_state_exception>([&] {thread.join();});
    }
    
    auto test_method_(resume) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      thread.start();
      thread.suspend();
      assert::is_true(enum_object<threading::thread_state> {thread.thread_state()}.has_flag(threading::thread_state::suspended));
      thread.resume();
      assert::is_false(enum_object<threading::thread_state> {thread.thread_state()}.has_flag(threading::thread_state::suspended));
      thread.join();
    }
    
    auto test_method_(resume_without_start) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      assert::throws<thread_state_exception>([&] {thread.resume();});
    }
    
    auto test_method_(resume_without_suspend) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      thread.start();
      assert::throws<thread_state_exception>([&] {thread.resume();});
      thread.join();
    }
    
    auto test_method_(start) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      assert::does_not_throw([&] {thread.start();});
      thread.join();
    }
    
    auto test_method_(start_with_parameterized_thread_start) {
      auto thread = threading::thread {parameterized_thread_start {[&] {thread::sleep(2);}}};
      assert::does_not_throw([&] {thread.start();});
    }
    
    auto test_method_(start_without_thread_start) {
      auto thread = threading::thread {};
      assert::throws<invalid_operation_exception>([&] {thread.start();});
    }
    
    auto test_method_(start_any) {
      auto thread = threading::thread {parameterized_thread_start {[&] {thread::sleep(2);}}};
      assert::does_not_throw([&] {thread.start(0);});
      thread.join();
    }
    
    auto test_method_(start_any_with_thread_start) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      assert::throws<invalid_operation_exception>([&] {thread.start(0);});
    }
    
    auto test_method_(suspend) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      thread.start();
      thread.suspend();
      assert::is_true(enum_object<threading::thread_state> {thread.thread_state()}.has_flag(threading::thread_state::suspended));
      thread.resume();
      assert::is_false(enum_object<threading::thread_state> {thread.thread_state()}.has_flag(threading::thread_state::suspended));
      thread.join();
    }
    
    auto test_method_(suspend_without_start) {
      auto thread = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      assert::throws<thread_state_exception>([&] {thread.suspend();});
    }
    
    auto test_method_(join_all) {
      auto thread1 = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      auto thread2 = threading::thread {thread_start {[&] {thread::sleep(2);}}};
      thread1.start();
      thread2.start();
      assert::does_not_throw([&] {threading::thread::join_all();});
    }
    
    auto test_method_(join_all_without_thread) {
      assert::does_not_throw([&] {threading::thread::join_all();});
    }
    
    auto test_method_(join_all_with_milliseconds_timeout) {
      auto thread1 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      auto thread2 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      thread1.start();
      thread2.start();
      assert::is_false(threading::thread::join_all(5));
      threading::thread::join_all();
    }
    
    auto test_method_(join_all_with_timeout) {
      auto thread1 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      auto thread2 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      thread1.start();
      thread2.start();
      assert::is_false(threading::thread::join_all(time_span::from_milliseconds(5.0)));
      threading::thread::join_all();
    }
    
    auto test_method_(join_all_with_collection) {
      auto thread1 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      auto thread2 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      thread1.start();
      thread2.start();
      assert::does_not_throw([&] {threading::thread::join_all({thread1, thread2});});
    }
    
    auto test_method_(join_all_with_collection_and_milliseconds_timeout) {
      auto thread1 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      auto thread2 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      thread1.start();
      thread2.start();
      assert::is_false(threading::thread::join_all({thread1, thread2}, 5));
      threading::thread::join_all({thread1, thread2});
    }
    
    auto test_method_(join_all_with_collection_and_timeout) {
      auto thread1 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      auto thread2 = threading::thread {thread_start {[&] {thread::sleep(10);}}};
      thread1.start();
      thread2.start();
      assert::is_false(threading::thread::join_all({thread1, thread2}, time_span::from_milliseconds(5.0)));
      threading::thread::join_all({thread1, thread2});
    }
    
    auto test_method_(join_all_with_vector) {
      list<thread> threads;
      threads.add(thread {thread_start {[&] {thread::sleep(10);}}});
      threads[threads.count() - 1].start();
      threads.add(thread {thread_start {[&] {thread::sleep(10);}}});
      threads[threads.count() - 1].start();
      assert::does_not_throw([&] {threading::thread::join_all(threads);});
    }
    
    auto test_method_(join_all_with_vector_and_milliseconds_timeout) {
      list<thread> threads;
      threads.add(thread {thread_start {[&] {thread::sleep(20);}}});
      threads[threads.count() - 1].start();
      threads.add(thread {thread_start {[&] {thread::sleep(20);}}});
      threads[threads.count() - 1].start();
      assert::is_false(threading::thread::join_all(threads, 5));
      threading::thread::join_all(threads);
    }
    
    auto test_method_(join_all_with_vector_and_timeout) {
      list<thread> threads;
      threads.add(thread {thread_start {[&] {thread::sleep(10);}}});
      threads[threads.count() - 1].start();
      threads.add(thread {thread_start {[&] {thread::sleep(10);}}});
      threads[threads.count() - 1].start();
      assert::is_false(threading::thread::join_all(threads, time_span::from_milliseconds(5.0)));
      threading::thread::join_all(threads);
    }
    
    auto test_method_(sleep_milliseconds_timeout) {
      auto sw = diagnostics::stopwatch::start_new();
      thread::sleep(10);
      assert::is_greater_or_equal(sw.elapsed_milliseconds(), 10);
    }
    
    auto test_method_(sleep_timeout) {
      auto sw = diagnostics::stopwatch::start_new();
      thread::sleep(time_span::from_milliseconds(10.0));
      assert::is_greater_or_equal(sw.elapsed_milliseconds(), 10);
    }
    
    auto test_method_(start_new) {
      auto thread = threading::thread::start_new(thread_start {[&] {thread::sleep(2);}});
      assert::are_not_equal(threading::thread::invalid_handle, thread.handle());
      thread.join();
    }
    
    auto test_method_(start_new_with_arg) {
      auto thread = threading::thread::start_new(parameterized_thread_start {[&] {thread::sleep(2);}}, 0);
      assert::are_not_equal(threading::thread::invalid_handle, thread.handle());
      thread.join();
    }
    
    auto test_method_(yield) {
      assert::is_true(thread::yield());
    }
    
    auto test_method_(create_many_threads) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
          interlocked::increment(counter);
        }};
        
      constexpr auto max_count_thread = 1000ul;
      auto threads = list<thread> {};
      
      for (auto index = 0_z; index < max_count_thread; ++index)
        threads.add(thread {thread_proc});
        
      for (auto& thread : threads)
        thread.start();
      for (auto& thread : threads)
        thread.join();
        
      assert::are_equal(max_count_thread, as<size_t>(counter));
    }
    
    auto test_method_(create_many_threads_with_join_all) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
          interlocked::increment(counter);
        }};
        
      constexpr auto max_count_thread = 1000ul;
      auto threads = list<thread> {};
      
      for (auto index = 0_z; index < max_count_thread; ++index)
        threads.add(thread::start_new(thread_proc));
        
      thread::join_all(threads);
      
      assert::are_equal(max_count_thread, as<size_t>(counter));
    }
    
    auto test_method_(create_many_threads_with_join_all_global) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
          interlocked::increment(counter);
        }};
        
      constexpr auto max_count_thread = 1000ul;
      for (auto index = 0_z; index < max_count_thread; ++index)
        thread::start_new(thread_proc);
        
      thread::sleep(40);
      thread::join_all();
      
      assert::are_equal(max_count_thread, as<size_t>(counter));
    }
  };
}
