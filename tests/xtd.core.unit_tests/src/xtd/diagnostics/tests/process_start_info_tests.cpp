#include <xtd/diagnostics/process_start_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace xtd::diagnostics::tests {
  class test_class_(process_start_info_tests) {
  public:
    void test_method_(create_process_start_info) {
      process_start_info si;
      assert::is_empty(si.file_name(), csf_);
      assert::is_empty(si.arguments(), csf_);
      assert::is_true(si.use_shell_execute(), csf_);
    }
  };
}
