#include <xtd/net/ip_host_entry.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_ip_host_entry) {
  public:
    void test_method_(create_with_default_constructor) {
      ip_host_entry host_entry;
      collection_assert::is_empty(host_entry.address_list(), csf_);
      collection_assert::is_empty(host_entry.aliases(), csf_);
      assert::is_empty(host_entry.host_name());
    }

    void test_method_(create_and_set_params) {
      ip_host_entry host_entry;
      host_entry.address_list({ip_address(172, 16, 12, 24), ip_address(172, 16, 12, 25)});
      host_entry.aliases({"alias 1", "alias 2", "alias 3"});
      host_entry.host_name("gammasoft_computer");

      collection_assert::are_equal({ip_address(172, 16, 12, 24), ip_address(172, 16, 12, 25)}, host_entry.address_list(), csf_);
      collection_assert::are_equal({"alias 1", "alias 2", "alias 3"}, host_entry.aliases(), csf_);
      assert::are_equal("gammasoft_computer", host_entry.host_name());
    }
  };
}
