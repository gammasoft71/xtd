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
      assert::are_equal_("", si.file_name());
      assert::are_equal_("", si.arguments());
      assert::is_true_(si.use_shell_execute());
    }
  };
}
