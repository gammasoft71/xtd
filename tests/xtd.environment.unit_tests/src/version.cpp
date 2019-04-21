#include <xtd/version.hpp>
#include <xtd/tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_version) {
  public:
    void test_method_(create_version_with_default_constructor) {
      version version;
      assert::are_equal_(0, version.major());
      assert::are_equal_(0, version.minor());
      assert::are_equal_(-1, version.build());
      assert::are_equal_(-1, version.revision());
    }

    void test_method_(create_version_with_major_and_minor) {
      version version {1, 2};
      assert::are_equal_(1, version.major());
      assert::are_equal_(2, version.minor());
      assert::are_equal_(-1, version.build());
      assert::are_equal_(-1, version.revision());
    }

    void test_method_(create_version_with_major_minor_and_build) {
      version version {1, 2, 3};
      assert::are_equal_(1, version.major());
      assert::are_equal_(2, version.minor());
      assert::are_equal_(3, version.build());
      assert::are_equal_(-1, version.revision());
    }

    void test_method_(create_version_with_major_minor_build_and_revision) {
      version version1 {1, 2, 3, 4};
      version version2  = version1;
      assert::are_equal_(1, version2.major());
      assert::are_equal_(2, version2.minor());
      assert::are_equal_(3, version2.build());
      assert::are_equal_(4, version2.revision());
    }

    void test_method_(copy_version_with_copy_operator) {
      version version1 {1, 2, 3, 4};
      version version2;
      version2 = version1;
      assert::are_equal_(1, version2.major());
      assert::are_equal_(2, version2.minor());
      assert::are_equal_(3, version2.build());
      assert::are_equal_(4, version2.revision());
    }

    void test_method_(create_version_from_version) {
      version version {1, 2, 3, 4};
      assert::are_equal_(1, version.major());
      assert::are_equal_(2, version.minor());
      assert::are_equal_(3, version.build());
      assert::are_equal_(4, version.revision());
    }
  };
}
