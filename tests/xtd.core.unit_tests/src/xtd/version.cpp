#include <sstream>
#include <xtd/version.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_version) {
  public:
    void test_method_(create_version_with_default_constructor) {
      version version;
      assert::are_equal(0, version.major(), csf_);
      assert::are_equal(0, version.minor(), csf_);
      assert::are_equal(-1, version.build(), csf_);
      assert::are_equal(-1, version.revision(), csf_);
    }

    void test_method_(create_version_with_string_that_contains_major_and_minor) {
      assert::are_equal(version(1, 2), version("1.2"), csf_);
    }

    void test_method_(create_version_with_string_that_contains_major_minor_and_build) {
      assert::are_equal(version(1, 2, 3), version("1.2.3"), csf_);
    }

    void test_method_(create_version_with_string_that_contains_major_minor_build_and_revision) {
      assert::are_equal(version(1, 2, 3, 4), version("1.2.3.4"), csf_);
    }

    void test_method_(create_version_with_string_that_contains_invalid_major_minor_build_and_revision) {
      assert::throws<argument_exception>([] {version("-1.2.3.4");}, csf_);
    }

    void test_method_(create_version_with_major_and_minor) {
      version version(1, 2);
      assert::are_equal(1, version.major(), csf_);
      assert::are_equal(2, version.minor(), csf_);
      assert::are_equal(-1, version.build(), csf_);
      assert::are_equal(-1, version.revision(), csf_);
    }

    void test_method_(create_version_with_invalid_major_and_minor) {
      assert::throws<argument_exception>([] {version version(-1, 2);}, csf_);
    }

    void test_method_(create_version_with_major_and_invalid_minor) {
      assert::throws<argument_exception>([] {version version(1, -2);}, csf_);
    }

    void test_method_(create_version_with_major_minor_and_build) {
      version version (1, 2, 3);
      assert::are_equal(1, version.major(), csf_);
      assert::are_equal(2, version.minor(), csf_);
      assert::are_equal(3, version.build(), csf_);
      assert::are_equal(-1, version.revision(), csf_);
    }

    void test_method_(create_version_with_major_minor_build_and_revision) {
      version version(1, 2, 3, 4);
      assert::are_equal(1, version.major(), csf_);
      assert::are_equal(2, version.minor(), csf_);
      assert::are_equal(3, version.build(), csf_);
      assert::are_equal(4, version.revision(), csf_);
    }

    void test_method_(copy_version_with_copy_operator) {
      version version1(1, 2, 3, 4);
      version version2;
      version2 = version1;
      assert::are_equal(1, version2.major(), csf_);
      assert::are_equal(2, version2.minor(), csf_);
      assert::are_equal(3, version2.build(), csf_);
      assert::are_equal(4, version2.revision(), csf_);
    }

    void test_method_(create_version_from_version) {
      version version1(1, 2, 3, 4);
      version version2  = version1;
      assert::are_equal(1, version2.major(), csf_);
      assert::are_equal(2, version2.minor(), csf_);
      assert::are_equal(3, version2.build(), csf_);
      assert::are_equal(4, version2.revision(), csf_);
    }

    void test_method_(equality_operator) {
      version version1(1, 2, 3, 4);
      version version2  = version1;
      version version3;
      assert::is_true(version1 == version2, csf_);
      assert::is_false(version1 == version3, csf_);
    }

    void test_method_(inequality_operator) {
      version version1(1, 2, 3, 4);
      version version2  = version1;
      version version3;
      assert::is_false(version1 != version2, csf_);
      assert::is_true(version1 != version3, csf_);
    }

    void test_method_(get_major_revision) {
      assert::are_equal(0x42, version(1, 2, 3, 0x420024).major_revision(), csf_);
    }

    void test_method_(get_minor_revision) {
      assert::are_equal(0x24, version(1, 2, 3, 0x420024).mainor_revision(), csf_);
    }

    void test_method_(parse_version_with_major) {
      assert::throws<argument_exception>([] {version::parse("1");}, csf_);
    }

    void test_method_(parse_version_with_major_and_minor) {
      assert::are_equal(version(1, 2), version::parse("1.2"), csf_);
    }

    void test_method_(parse_version_with_bad_major_and_minor) {
      assert::throws<format_exception>([] {version::parse("one.2");}, csf_);
    }

    void test_method_(parse_version_with_major_minor_and_build) {
      assert::are_equal(version(1, 2, 3), version::parse("1.2.3"), csf_);
    }

    void test_method_(parse_version_with_major_minor_build_and_revision) {
      assert::are_equal(version(1, 2, 3, 4), version::parse("1.2.3.4"), csf_);
    }

    void test_method_(parse_version_with_major_minor_build_revision_and_bad_value) {
      assert::throws<argument_exception>([] {version::parse("1.2.3.4.5");}, csf_);
    }

    void test_method_(parse_version_with_bad_value) {
      assert::throws<argument_exception>([] {version::parse("one");}, csf_);
    }

    void test_method_(try_parse_version_with_good_string_value) {
      version vers;
      assert::is_true(version::try_parse("1.2.3.4", vers), csf_);
      assert::are_equal(version(1, 2, 3, 4), vers, csf_);
    }

    void test_method_(try_parse_version_with_bad_string_value) {
      version vers;
      assert::is_false(version::try_parse("one", vers), csf_);
      assert::are_equal(version(), vers, csf_);
    }

    void test_method_(to_string_with_empty_version) {
      assert::are_equal("0.0", version().to_string(), csf_);
    }

    void test_method_(to_string_with_major_and_minor) {
      assert::are_equal("1.2", version(1, 2).to_string(), csf_);
    }

    void test_method_(to_string_with_major_minor_and_build) {
      assert::are_equal("1.2.3", version(1, 2, 3).to_string(), csf_);
    }

    void test_method_(to_string_with_major_minor_build_and_revision) {
      assert::are_equal("1.2.3.4", version(1, 2, 3, 4).to_string(), csf_);
    }

    void test_method_(to_string_field_0_with_empty_version) {
      assert::are_equal("", version().to_string(0), csf_);
    }
    
    void test_method_(to_string_field_0_with_full_version) {
      assert::are_equal("", version(1, 2, 3, 4).to_string(0), csf_);
    }

    void test_method_(to_string_field_1_with_empty_version) {
      assert::are_equal("0", version().to_string(1), csf_);
    }
    
    void test_method_(to_string_field_1_with_full_version) {
      assert::are_equal("1", version(1, 2, 3, 4).to_string(1), csf_);
    }

    void test_method_(to_string_field_2_with_empty_version) {
      assert::are_equal("0.0", version().to_string(2), csf_);
    }
    
    void test_method_(to_string_field_2_with_full_version) {
      assert::are_equal("1.2", version(1, 2, 3, 4).to_string(2), csf_);
    }

    void test_method_(to_string_field_3_with_empty_version) {
      assert::throws<argument_exception>([] {version().to_string(3);}, csf_);
    }
    
    void test_method_(to_string_field_3_with_full_version) {
      assert::are_equal("1.2.3", version(1, 2, 3, 4).to_string(3), csf_);
    }

    void test_method_(to_string_field_4_with_empty_version) {
      assert::throws<argument_exception>([] {version().to_string(4);}, csf_);
    }
    
    void test_method_(to_string_field_4_with_full_version) {
      assert::are_equal("1.2.3.4", version(1, 2, 3, 4).to_string(4), csf_);
    }

    void test_method_(to_string_field_greater_than_4) {
      assert::throws<argument_exception>([] {version().to_string(5);}, csf_);
    }

    void test_method_(ostream_operator) {
      stringstream ss;
      ss << version(1, 2, 3, 4);
      assert::are_equal("1.2.3.4", ss.str(), csf_);
    }
  };
}
