#include <xtd/forms/save_file_box_options>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(save_file_box_options_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(save_file_box_options::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(save_file_box_options::none), csf_);
      assert::are_equal(save_file_box_options::none, enum_object<>::parse<save_file_box_options>("none"), csf_);
    }
    
    void test_method_(check_file_exists) {
      assert::are_equal(1, enum_object<>::to_int32(save_file_box_options::check_file_exists), csf_);
      assert::are_equal("check_file_exists", enum_object<>::to_string(save_file_box_options::check_file_exists), csf_);
      assert::are_equal(save_file_box_options::check_file_exists, enum_object<>::parse<save_file_box_options>("check_file_exists"), csf_);
    }
    
    void test_method_(dereference_link) {
      assert::are_equal(2, enum_object<>::to_int32(save_file_box_options::dereference_link), csf_);
      assert::are_equal("dereference_link", enum_object<>::to_string(save_file_box_options::dereference_link), csf_);
      assert::are_equal(save_file_box_options::dereference_link, enum_object<>::parse<save_file_box_options>("dereference_link"), csf_);
    }
    
    void test_method_(validate_names) {
      assert::are_equal(4, enum_object<>::to_int32(save_file_box_options::validate_names), csf_);
      assert::are_equal("validate_names", enum_object<>::to_string(save_file_box_options::validate_names), csf_);
      assert::are_equal(save_file_box_options::validate_names, enum_object<>::parse<save_file_box_options>("validate_names"), csf_);
    }
    
    void test_method_(restore_directory) {
      assert::are_equal(8, enum_object<>::to_int32(save_file_box_options::restore_directory), csf_);
      assert::are_equal("restore_directory", enum_object<>::to_string(save_file_box_options::restore_directory), csf_);
      assert::are_equal(save_file_box_options::restore_directory, enum_object<>::parse<save_file_box_options>("restore_directory"), csf_);
    }
    
    void test_method_(enable_auto_upgrade) {
      assert::are_equal(16, enum_object<>::to_int32(save_file_box_options::enable_auto_upgrade), csf_);
      assert::are_equal("enable_auto_upgrade", enum_object<>::to_string(save_file_box_options::enable_auto_upgrade), csf_);
      assert::are_equal(save_file_box_options::enable_auto_upgrade, enum_object<>::parse<save_file_box_options>("enable_auto_upgrade"), csf_);
    }
    
    void test_method_(show_hidden_files) {
      assert::are_equal(32, enum_object<>::to_int32(save_file_box_options::show_hidden_files), csf_);
      assert::are_equal("show_hidden_files", enum_object<>::to_string(save_file_box_options::show_hidden_files), csf_);
      assert::are_equal(save_file_box_options::show_hidden_files, enum_object<>::parse<save_file_box_options>("show_hidden_files"), csf_);
    }
    
    void test_method_(show_help) {
      assert::are_equal(64, enum_object<>::to_int32(save_file_box_options::show_help), csf_);
      assert::are_equal("show_help", enum_object<>::to_string(save_file_box_options::show_help), csf_);
      assert::are_equal(save_file_box_options::show_help, enum_object<>::parse<save_file_box_options>("show_help"), csf_);
    }
    
    void test_method_(show_preview) {
      assert::are_equal(128, enum_object<>::to_int32(save_file_box_options::show_preview), csf_);
      assert::are_equal("show_preview", enum_object<>::to_string(save_file_box_options::show_preview), csf_);
      assert::are_equal(save_file_box_options::show_preview, enum_object<>::parse<save_file_box_options>("show_preview"), csf_);
    }
    
    void test_method_(support_multi_dotted_extensions) {
      assert::are_equal(256, enum_object<>::to_int32(save_file_box_options::support_multi_dotted_extensions), csf_);
      assert::are_equal("support_multi_dotted_extensions", enum_object<>::to_string(save_file_box_options::support_multi_dotted_extensions), csf_);
      assert::are_equal(save_file_box_options::support_multi_dotted_extensions, enum_object<>::parse<save_file_box_options>("support_multi_dotted_extensions"), csf_);
    }
    
    void test_method_(all) {
      assert::are_equal(511, enum_object<>::to_int32(save_file_box_options::all), csf_);
      assert::are_equal("all", enum_object<>::to_string(save_file_box_options::all), csf_);
      assert::are_equal(save_file_box_options::all, enum_object<>::parse<save_file_box_options>("all"), csf_);
    }
  };
}
