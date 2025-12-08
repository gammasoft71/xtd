#if defined(_WIN32)
#define NOMINMAX
#include <Windows.h>
#undef interface
#elif defined(__linux__) || defined(__APPLE__)
#include <semaphore.h>
#endif
#include <xtd/threading/wait_handle>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/argument_out_of_range_exception>
#include <xtd/environment>
#include <xtd/object_closed_exception>
#include <mutex>
#include <utility>

using namespace xtd::helpers;
using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(wait_handle_tests) {
    class unnamed_mutex : public wait_handle {
    public:
      unnamed_mutex() = default;
      
      unnamed_mutex(unnamed_mutex&&) = default;
      unnamed_mutex(const unnamed_mutex&) = default;
      unnamed_mutex& operator=(const unnamed_mutex&) = default;
      
      intptr handle() const noexcept override {return mutex_ ? reinterpret_cast<intptr>(mutex_.get()) : invalid_handle;}
      void handle(intptr value) override {mutex_.reset(reinterpret_cast<std::recursive_timed_mutex*>(value));}
      
      void release_mutex() {signal();}
      
      void close() override {if (mutex_.use_count() == 1) mutex_.reset();}
      
      bool locked() {return locked_;};
      
    protected:
      bool signal() override {
        if (!mutex_) throw_helper::throws(exception_case::object_closed);
        auto result = false;
        mutex_->unlock();
        std::swap(locked_, result);
        return result;
      }
      
      bool wait(int32_t milliseconds_timeout) override {
        if (!mutex_) throw_helper::throws(exception_case::object_closed);
        if (milliseconds_timeout < -1) throw_helper::throws(exception_case::argument_out_of_range);
        
        if (milliseconds_timeout != timeout::infinite) return (locked_ = mutex_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout}));
        mutex_->lock();
        locked_ = true;
        return locked_;
      }
      
    private:
      xtd::sptr<std::recursive_timed_mutex> mutex_ = xtd::new_sptr<std::recursive_timed_mutex>();
      bool locked_ = false;
    };
    
    auto test_method_(invalid_handle) {
      #if defined(_WIN32)
      assert::are_equal(reinterpret_cast<intptr>(INVALID_HANDLE_VALUE), wait_handle::invalid_handle);
      #elif defined(__linux__) || defined(__APPLE__)
      assert::are_equal(reinterpret_cast<intptr>(SEM_FAILED), wait_handle::invalid_handle);
      #endif
    }
    
    auto test_method_(wait_timeout) {
      assert::are_equal(std::numeric_limits<size_t>::max(), wait_handle::wait_timeout);
    }
    
    auto test_method_(handle) {
      auto m = unnamed_mutex {};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
    }
    
    auto test_method_(wait_one) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one());
      assert::is_true(m.locked());
    }
    
    auto test_method_(wait_one_and_release_mutex) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one());
      assert::does_not_throw([&] {m.release_mutex();});
      assert::is_false(m.locked());
    }
    
    auto test_method_(wait_one_and_release_mutex_and_release_mutex) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one());
      assert::does_not_throw([&] {m.release_mutex();});
      assert::does_not_throw([&] {m.release_mutex();});
      assert::is_false(m.locked());
    }
    
    auto test_method_(wait_one_and_wait_one_and_release_mutex) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one());
      assert::is_true(m.wait_one());
      assert::is_true(m.locked());
      assert::does_not_throw([&] {m.release_mutex();});
      assert::is_false(m.locked());
    }
    
    auto test_method_(close_and_wait_one) {
      auto m = unnamed_mutex {};
      m.close();
      assert::throws<object_closed_exception>([&] {m.wait_one();});
    }
    
    auto test_method_(close_and_release_mutex) {
      auto m = unnamed_mutex {};
      m.close();
      assert::are_equal(wait_handle::invalid_handle, m.handle());
      assert::throws<object_closed_exception>([&] {m.release_mutex();});
    }
    
    auto test_method_(signal_and_wait) {
      auto m1 = unnamed_mutex {};
      auto m2 = unnamed_mutex {};
      m1.wait_one();
      assert::is_true(m1.locked());
      assert::is_false(m2.locked());
      wait_handle::signal_and_wait(m1, m2);
      assert::is_false(m1.locked());
      assert::is_true(m2.locked());
    }
    
    auto test_method_(wait_all) {
      auto m1 = unnamed_mutex {};
      auto m2 = unnamed_mutex {};
      auto m3 = unnamed_mutex {};
      assert::is_true(wait_handle::wait_all({m1, m2, m3}));
    }
    
    auto test_method_(wait_any) {
      auto m1 = unnamed_mutex {};
      auto m2 = unnamed_mutex {};
      auto m3 = unnamed_mutex {};
      assert::are_equal(0ul, wait_handle::wait_any({m1, m2, m3}));
    }
  };
}
