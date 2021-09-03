#include <xtd/diagnostics/process_start_info.h>
#include <xtd/xtd.tunit>
#include <thread>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_process_start_info) {
  public:
    void test_method_(create_process_start_info) {
      process_start_info si;
      assert::are_equal("", si.file_name(), csf_);
      assert::are_equal("", si.arguments(), csf_);
      assert::is_true(si.use_shell_execute(), csf_);
    }
  };
}
