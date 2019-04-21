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
      version version(1, 2);
      assert::are_equal_(1, version.major());
      assert::are_equal_(2, version.minor());
      assert::are_equal_(-1, version.build());
      assert::are_equal_(-1, version.revision());
    }

    void test_method_(create_version_with_major_minor_and_build) {
      version version (1, 2, 3);
      assert::are_equal_(1, version.major());
      assert::are_equal_(2, version.minor());
      assert::are_equal_(3, version.build());
      assert::are_equal_(-1, version.revision());
    }

    void test_method_(create_version_with_major_minor_build_and_revision) {
      version version(1, 2, 3, 4);
      assert::are_equal_(1, version.major());
      assert::are_equal_(2, version.minor());
      assert::are_equal_(3, version.build());
      assert::are_equal_(4, version.revision());
    }

    void test_method_(copy_version_with_copy_operator) {
      version version1(1, 2, 3, 4);
      version version2;
      version2 = version1;
      assert::are_equal_(1, version2.major());
      assert::are_equal_(2, version2.minor());
      assert::are_equal_(3, version2.build());
      assert::are_equal_(4, version2.revision());
    }

    void test_method_(create_version_from_version) {
      version version1(1, 2, 3, 4);
      version version2  = version1;
      assert::are_equal_(1, version2.major());
      assert::are_equal_(2, version2.minor());
      assert::are_equal_(3, version2.build());
      assert::are_equal_(4, version2.revision());
    }

    void test_method_(equality_operator) {
      version version1(1, 2, 3, 4);
      version version2  = version1;
      version version3;
      assert::is_true_(version1 == version2);
      assert::is_false_(version1 == version3);
    }

    void test_method_(inequality_operator) {
      version version1(1, 2, 3, 4);
      version version2  = version1;
      version version3;
      assert::is_false_(version1 != version2);
      assert::is_true_(version1 != version3);
    }

    void test_method_(get_major_revision) {
      assert::are_equal_(0x42, version(1, 2, 3, 0x420024).major_revision());
    }

    void test_method_(get_minor_revision) {
      assert::are_equal_(0x24, version(1, 2, 3, 0x420024).mainor_revision());
    }

    void test_method_(parse_version_with_major) {
      assert::throws_(invalid_argument, [] {version::parse("1");});
    }

    void test_method_(parse_version_with_major_and_minor) {
      assert::are_equal_(version(1, 2), version::parse("1.2"));
    }

    void test_method_(parse_version_with_bad_major_and_minor) {
      assert::throws_(invalid_argument, [] {version::parse("one.2");});
    }

    void test_method_(parse_version_with_major_minor_and_build) {
      assert::are_equal_(version(1, 2, 3), version::parse("1.2.3"));
    }

    void test_method_(parse_version_with_major_minor_build_and_revision) {
      assert::are_equal_(version(1, 2, 3, 4), version::parse("1.2.3.4"));
    }

    void test_method_(parse_version_with_major_minor_build_revision_and_bad_value) {
      assert::throws_(invalid_argument, [] {version::parse("1.2.3.4.5");});
    }

    void test_method_(parse_version_with_bad_value) {
      assert::throws_(invalid_argument, [] {version::parse("one");});
    }
  };
}
