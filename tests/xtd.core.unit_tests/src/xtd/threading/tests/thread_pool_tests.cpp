#include <xtd/threading/thread_pool.h>
#include <xtd/xtd.tunit>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(thread_pool_tests) {
  public:
    void test_method_(get_max_threads) {
      size_t worker_threads = 0;
      size_t completion_port_threads = 0;
      thread_pool::get_max_threads(worker_threads, completion_port_threads);
      assert::are_equal(800ul, worker_threads, csf_);
      assert::are_equal(800ul, completion_port_threads, csf_);
    }
    
    void test_method_(get_min_threads) {
      size_t worker_threads = 0;
      size_t completion_port_threads = 0;
      thread_pool::get_min_threads(worker_threads, completion_port_threads);
      assert::are_equal(environment::processor_count(), worker_threads, csf_);
      assert::are_equal(environment::processor_count(), completion_port_threads, csf_);
    }
  };
}
