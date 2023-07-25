#include <xtd/threading/wait_handle.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(wait_handle_tests) {
    class mutex_wait_handle : public wait_handle {
    public:
      mutex_wait_handle() = default;

      void release_mutex() {signal();}
      
      void close() override {mutex_.reset();}
      
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
    
  public:
    void test_method_(invalid_handle) {
      assert::are_equal(0, wait_handle::invalid_handle, csf_);
    }

    void test_method_(wait_timeout) {
      assert::are_equal(-1, wait_handle::wait_timeout, csf_);
    }

    void test_method_(wait_one) {
      auto m = mutex_wait_handle {};
      assert::is_true(m.wait_one(), csf_);
      assert::is_true(m.locked(), csf_);
    }

    void test_method_(wait_one_and_release_mutex) {
      auto m = mutex_wait_handle {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::is_false(m.locked(), csf_);
    }

    void test_method_(wait_one_and_release_mutex_and_release_mutex) {
      auto m = mutex_wait_handle {};
      assert::is_true(m.wait_one(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::is_false(m.locked(), csf_);
    }

    void test_method_(wait_one_and_wait_one_and_release_mutex) {
      auto m = mutex_wait_handle {};
      assert::is_true(m.wait_one(), csf_);
      assert::is_true(m.wait_one(), csf_);
      assert::is_true(m.locked(), csf_);
      assert::does_not_throw([&] {m.release_mutex();}, csf_);
      assert::is_false(m.locked(), csf_);
    }

    void test_method_(close_and_wait_one) {
      auto m = mutex_wait_handle {};
      m.close();
      assert::throws<object_closed_exception>([&] {m.wait_one();}, csf_);
    }

    void test_method_(close_and_release_mutex) {
      auto m = mutex_wait_handle {};
      m.close();
      assert::throws<object_closed_exception>([&] {m.release_mutex();}, csf_);
    }
    
    void test_method_(signal_and_wait) {
      auto m1 = mutex_wait_handle {};
      auto m2 = mutex_wait_handle {};
      m1.wait_one();
      assert::is_true(m1.locked());
      assert::is_false(m2.locked());
      wait_handle::signal_and_wait(m1, m2);
      assert::is_false(m1.locked());
      assert::is_true(m2.locked());
    }
  };
}
