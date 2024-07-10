#include "../../../include/xtd/tunit/registered_test_class.h"

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

registered_test_class::registered_test_class(const ustring& name, xtd::sptr<test_class> test_class) noexcept : tc_(test_class) {
  tc_->name_ = ustring(name).replace(' ', '_');
}

const xtd::sptr<test_class>& registered_test_class::test() const noexcept {
  return tc_;
}
