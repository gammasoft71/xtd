#include <xtd/threading/wait_handle>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/argument_out_of_range_exception>
#include <xtd/environment>
#include <xtd/object_closed_exception>
#include <mutex>
#include <utility>
#if defined(_WIN32)
#define NOMINMAX
#include <Windows.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <semaphore.h>
#endif

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
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
        if (!mutex_) throw object_closed_exception {csf_};
        auto result = false;
        mutex_->unlock();
        std::swap(locked_, result);
        return result;
      }
      
      bool wait(int32_t milliseconds_timeout) override {
        if (!mutex_) throw object_closed_exception {csf_};
        if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};

        if (milliseconds_timeout != timeout::infinite) return (locked_ = mutex_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout}));
        mutex_->lock();
        locked_ = true;
        return locked_;
      }

    private:
      std::shared_ptr<std::recursive_timed_mutex> mutex_ = std::make_shared<std::recursive_timed_mutex>();
      bool locked_ = false;
    };
    
    void test_method_(invalid_handle) {
#if defined(_WIN32)
      assert::are_equal(reinterpret_cast<intptr>(INVALID_HANDLE_VALUE), wait_handle::invalid_handle, csf_);
#elif defined(__linux__) || defined(__APPLE__)
      assert::are_equal(reinterpret_cast<intptr>(SEM_FAILED), wait_handle::invalid_handle, csf_);
#endif
    }

    void test_method_(wait_timeout) {
      assert::are_equal(std::numeric_limits<size_t>::max(), wait_handle::wait_timeout, csf_);
    }
    
    void test_method_(handle) {
      auto m = unnamed_mutex {};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle(), csf_);
    }
    
    void test_method_(wait_one) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::is_true(m.locked(), csf_);
    }

    void test_method_(wait_one_and_release_mutex) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::is_false(m.locked(), csf_);
    }

    void test_method_(wait_one_and_release_mutex_and_release_mutex) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::is_false(m.locked(), csf_);
    }

    void test_method_(wait_one_and_wait_one_and_release_mutex) {
      auto m = unnamed_mutex {};
      assert::is_true(m.wait_one(), csf_);
      assert::is_true(m.wait_one(), csf_);
      assert::is_true(m.locked(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::is_false(m.locked(), csf_);
    }

    void test_method_(close_and_wait_one) {
      auto m = unnamed_mutex {};
      m.close();
      assert::throws<object_closed_exception>([&] {m.wait_one();}, csf_);
    }

    void test_method_(close_and_release_mutex) {
      auto m = unnamed_mutex {};
      m.close();
      assert::are_equal(wait_handle::invalid_handle, m.handle(), csf_);
      assert::throws<object_closed_exception>([&] {m.release_mutex();}, csf_);
    }
    
    void test_method_(signal_and_wait) {
      auto m1 = unnamed_mutex {};
      auto m2 = unnamed_mutex {};
      m1.wait_one();
      assert::is_true(m1.locked());
      assert::is_false(m2.locked());
      wait_handle::signal_and_wait(m1, m2);
      assert::is_false(m1.locked());
      assert::is_true(m2.locked());
    }
    
    void test_method_(wait_all) {
      auto m1 = unnamed_mutex {};
      auto m2 = unnamed_mutex {};
      auto m3 = unnamed_mutex {};
      assert::is_true(wait_handle::wait_all({m1, m2, m3}), csf_);
    }
    
    void test_method_(wait_any) {
      auto m1 = unnamed_mutex {};
      auto m2 = unnamed_mutex {};
      auto m3 = unnamed_mutex {};
      assert::are_equal(0ul, wait_handle::wait_any({m1, m2, m3}), csf_);
    }
  };
}
