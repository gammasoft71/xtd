#include <xtd/configuration/file_settings>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert.h>
#include <xtd/tunit/file_assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::configuration;
using namespace xtd::tunit;

namespace xtd::configuration::tests {
  class test_class_(file_settings_tests) {
    void test_method_(default_ctor) {
      auto fs = file_settings {};
      assert::is_false(fs.auto_save(), csf_);
      assert::is_empty(fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
    }

    void test_method_(ctor_with_empty_string) {
      auto fs = file_settings {ustring::empty_string};
      assert::is_false(fs.auto_save(), csf_);
      assert::is_empty(fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
    }

    void test_method_(ctor_with_non_existent_file_name) {
      auto file_name = "non_existent_file_name.ini";
      file_assume::does_not_exist(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(io::path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
    }

    void test_method_(ctor_with_empty_file) {
      auto file_name = "empty_file.ini";
      io::file::write_all_text(file_name, "");
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(io::path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      io::file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_one_section) {
      auto file_name = "empty_file.ini";
      auto file_content = "[section1]\n";
      io::file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(io::path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      io::file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_many_sections) {
      auto file_name = "empty_file.ini";
      auto file_content = "[section1]\n[section2]\n[section3]\n[section4]\n[section5]\n";
      io::file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(io::path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.key_values("section1"), csf_);
      assert::is_empty(fs.key_values("section2"), csf_);
      assert::is_empty(fs.key_values("section3"), csf_);
      assert::is_empty(fs.key_values("section4"), csf_);
      assert::is_empty(fs.key_values("section5"), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.keys("section1"), csf_);
      assert::is_empty(fs.keys("section2"), csf_);
      assert::is_empty(fs.keys("section3"), csf_);
      assert::is_empty(fs.keys("section4"), csf_);
      assert::is_empty(fs.keys("section5"), csf_);
      collection_assert::are_equivalent({"section1", "section2", "section3", "section4", "section5"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      io::file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_one_section_and_one_key_value) {
      auto file_name = "empty_file.ini";
      auto file_content = "[section1]\nkey1=value1\n";
      io::file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(io::path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      io::file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_one_section_and_many_key_values) {
      auto file_name = "empty_file.ini";
      auto file_content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n";
      io::file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(io::path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      io::file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_many_sections_and_many_key_values) {
      auto file_name = "empty_file.ini";
      auto file_content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n"
      "[section2]\nkey6=value6\nkey7=value7\nkey8=value8\nkey9=value9\nkey10=value10\n"
      "[section3]\nkey11=value11\nkey12=value12\nkey13=value13\nkey14=value14\nkey15=value15\n"
      "[section4]\nkey16=value16\nkey17=value17\nkey18=value18\nkey19=value19\nkey20=value20\n"
      "[section5]\nkey21=value21\nkey22=value22\nkey23=value23\nkey24=value24\nkey25=value25\n";
      io::file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(io::path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"), csf_);
      assert::are_equal(file_settings::string_map {{"key6", "value6"}, {"key7", "value7"}, {"key8", "value8"}, {"key9", "value9"}, {"key10", "value10"}}, fs.key_values("section2"), csf_);
      assert::are_equal(file_settings::string_map {{"key11", "value11"}, {"key12", "value12"}, {"key13", "value13"}, {"key14", "value14"}, {"key15", "value15"}}, fs.key_values("section3"), csf_);
      assert::are_equal(file_settings::string_map {{"key16", "value16"}, {"key17", "value17"}, {"key18", "value18"}, {"key19", "value19"}, {"key20", "value20"}}, fs.key_values("section4"), csf_);
      assert::are_equal(file_settings::string_map {{"key21", "value21"}, {"key22", "value22"}, {"key23", "value23"}, {"key24", "value24"}, {"key25", "value25"}}, fs.key_values("section5"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"key6", "key7", "key8", "key9", "key10"}, fs.keys("section2"), csf_);
      collection_assert::are_equivalent({"key11", "key12", "key13", "key14", "key15"}, fs.keys("section3"), csf_);
      collection_assert::are_equivalent({"key16", "key17", "key18", "key19", "key20"}, fs.keys("section4"), csf_);
      collection_assert::are_equivalent({"key21", "key22", "key23", "key24", "key25"}, fs.keys("section5"), csf_);
      collection_assert::are_equivalent({"section1", "section2", "section3", "section4", "section5"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      io::file::remove(file_name);
    }
  };
}
