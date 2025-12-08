#include <xtd/iasync_result>
#include <xtd/invalid_operation_exception>
#include <xtd/threading/auto_reset_event>
#include <xtd/threading/thread>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(iasync_result_tests) {
    class test_async_result : public iasync_result {
    public:
      test_async_result() = default;
      test_async_result(const any_object& state) : state_(state) {}
      
      any_object async_state() const noexcept override {return state_;}
      void async_state(const any_object& value) noexcept {state_ = value;}
      
      xtd::threading::wait_handle& async_wait_handle() noexcept override {return async_wait_handle_;}
      
      bool completed_synchronously() const noexcept override {return false;}
      
      bool is_completed() const noexcept override {return completed_;}
      void is_completed(bool value) noexcept {completed_ = value;}
      
    private:
      xtd::threading::auto_reset_event async_wait_handle_;
      any_object state_;
      bool completed_ = false;
    };
    
    class test_async_runner {
    public:
      ~test_async_runner() {
        if (thread_.joinable()) thread_.join();
      }
      
      iasync_result& start() {
        if (result_.async_state().has_value()) throw_helper::throws(exception_case::invalid_operation, "Already started");
        result_.async_state("Started");
        result_.is_completed(false);
        thread_ = threading::thread {[this] {
            threading::thread::sleep(2_ms);
            result_.async_state("Ended");
            result_.is_completed(true);
            as<xtd::threading::auto_reset_event>(result_.async_wait_handle()).set();
          }};
        thread_.start();
        return result_;
      }
      
      void wait(iasync_result& result) {
        if (&result != &result_) throw_helper::throws(exception_case::invalid_operation, "iasync_result not valid");
        result.async_wait_handle().wait_one();
      }
      
    private:
      threading::thread thread_;
      test_async_result result_;
    };
    
    auto test_method_(test_async_result_ctor) {
      test_async_result ar;
      
      assert::is_false(ar.async_state().has_value());
      assert::is_false(ar.completed_synchronously());
      assert::is_false(ar.is_completed());
      assert::is_false(ar.async_wait_handle().wait_one(0));
    }
    
    auto test_method_(execute_test_async_runner) {
      test_async_runner runner;
      auto& result = runner.start();
      assert::are_equal("Started", as<string>(result.async_state()));
      assert::is_false(result.is_completed());
      runner.wait(result);
      assert::are_equal("Ended", as<string>(result.async_state()));
      assert::is_true(result.is_completed());
    }
  };
}
