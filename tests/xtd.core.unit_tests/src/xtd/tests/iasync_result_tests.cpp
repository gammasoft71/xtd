#include <xtd/iasync_result>
#include <xtd/invalid_operation_exception>
#include <xtd/threading/thread.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(iasync_result_tests) {
    class test_async_result : public iasync_result {
    public:
      test_async_result() = default;
      test_async_result(any state) : state_(state) {}
      
      any async_state() const noexcept override {return state_;}
      void async_state(any value) noexcept {state_ = value;}
      
      timed_mutex& async_mutex() noexcept override {return mutex_;}
      
      bool completed_synchronously() const noexcept override {return false;}
      
      bool is_completed() const noexcept override {return completed_;}
      void is_completed(bool value) noexcept {completed_ = value;}
      
    private:
      timed_mutex mutex_;
      any state_;
      bool completed_ = false;
    };
    
    class test_async_runner {
    public:
      ~test_async_runner() {
        if (thread_.joinable()) thread_.join();
      }
      
      iasync_result& start() {
        if (result_.async_state().has_value()) throw invalid_operation_exception("Already started", csf_);
        result_.async_state("Started");
        result_.is_completed(false);
        result_.async_mutex().lock();
        thread_ = threading::thread {thread_start {[this] {
          threading::thread::sleep(2_ms);
          result_.async_state("Ended");
          result_.is_completed(true);
          result_.async_mutex().unlock();
        }}};
        thread_.start();
        return result_;
      }
      
      void wait(iasync_result& result) {
        if (&result != &result_) throw invalid_operation_exception("iasync_result not valid", csf_);
        if (!result.async_state().has_value() || as<ustring>(result.async_state()) != "Started") throw invalid_operation_exception("Not started", csf_);
        lock_guard<timed_mutex> lock {result.async_mutex()};
      }
      
    private:
      threading::thread thread_;
      test_async_result result_;
    };
    
  public:
     void test_method_(test_async_result_ctor) {
     test_async_result ar;
     
     assert::is_false(ar.async_state().has_value(), csf_);
     assert::is_false(ar.completed_synchronously(), csf_);
     assert::is_false(ar.is_completed(), csf_);
     assert::is_true(ar.async_mutex().try_lock(), csf_);
     }
    
    void test_method_(execute_test_async_runner) {
      test_async_runner runner;
      auto& result = runner.start();
      assert::are_equal("Started", as<ustring>(result.async_state()), csf_);
      assert::is_false(result.is_completed(), csf_);
      runner.wait(result);
      assert::are_equal("Ended", as<ustring>(result.async_state()), csf_);
      assert::is_true(result.is_completed(), csf_);
    }
  };
}
