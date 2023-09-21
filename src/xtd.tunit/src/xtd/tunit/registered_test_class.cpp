#include "../../../include/xtd/tunit/registered_test_class"

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

registered_test_class::registered_test_class(const string& name, shared_ptr<xtd::tunit::test_class> test_class) noexcept : tc_(test_class) {
  tc_->name_ = ustring(name).replace(' ', '_');
}

const shared_ptr<xtd::tunit::test_class>& registered_test_class::test() const noexcept {
  return tc_;
}
