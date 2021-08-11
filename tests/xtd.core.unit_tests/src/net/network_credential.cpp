#include <xtd/net/network_credential.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_network_credential) {
  public:
    void test_method_(create_with_default_constructor) {
      network_credential nc;
      assert::is_empty(nc.user_name(), line_info_);
      assert::is_empty(nc.password(), line_info_);
      assert::is_empty(nc.secure_password(), line_info_);
      assert::is_empty(nc.domain(), line_info_);
    }

    void test_method_(create_with_user_name_and_password) {
      network_credential nc("gammasoft", "sysadmin!nimdasys");
      assert::are_equal("gammasoft", nc.user_name(), line_info_);
      assert::are_equal("sysadmin!nimdasys", nc.password(), line_info_);
      // assert::is_empty(nc.secure_password(), line_info_);
      assert::is_empty(nc.domain(), line_info_);
    }

    void test_method_(create_with_user_name_password_and_domain) {
      network_credential nc("gammasoft", "sysadmin!nimdasys", "domain");
      assert::are_equal("gammasoft", nc.user_name(), line_info_);
      assert::are_equal("sysadmin!nimdasys", nc.password(), line_info_);
      // assert::is_empty(nc.secure_password(), line_info_);
      assert::are_equal("domain", nc.domain(), line_info_);
    }
  };
}
