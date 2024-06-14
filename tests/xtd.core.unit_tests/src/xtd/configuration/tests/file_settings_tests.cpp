#include <xtd/configuration/file_settings>
#include <xtd/io/file>
#include <xtd/io/file_not_found_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/file_assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::configuration;
using namespace xtd::io;
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
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
    }

    void test_method_(ctor_with_empty_file) {
      auto file_name = "empty_file.ini";
      file::write_all_text(file_name, "");
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_one_section) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_many_sections) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\n[section2]\n[section3]\n[section4]\n[section5]\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
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
      file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_one_section_and_one_key_value) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\nkey1=value1\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_one_section_and_many_key_values) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      file::remove(file_name);
    }

    void test_method_(ctor_with_file_containing_many_sections_and_many_key_values) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n"
      "[section2]\nkey6=value6\nkey7=value7\nkey8=value8\nkey9=value9\nkey10=value10\n"
      "[section3]\nkey11=value11\nkey12=value12\nkey13=value13\nkey14=value14\nkey15=value15\n"
      "[section4]\nkey16=value16\nkey17=value17\nkey18=value18\nkey19=value19\nkey20=value20\n"
      "[section5]\nkey21=value21\nkey22=value22\nkey23=value23\nkey24=value24\nkey25=value25\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save(), csf_);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
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
      file::remove(file_name);
    }

    void test_method_(ctor_with_stream_containing_one_section_and_many_key_values) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto stream = file::open(file_name, ios::in|ios::out);
      auto fs = file_settings {stream};
      assert::is_false(fs.auto_save(), csf_);
      assert::is_empty(fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_true(fs.stream().has_value(), csf_);
      file::remove(file_name);
    }
    
    void test_method_(from_string) {
      auto fs = file_settings {};
      fs.from_string("[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n");
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);

      fs.from_string("[section2]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n");
      assert::is_empty(fs.key_values(), csf_);
      assert::is_empty(fs.key_values("section1"), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section2"), csf_);
      assert::is_empty(fs.keys(), csf_);
      assert::is_empty(fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section2"), csf_);
      collection_assert::are_equivalent({"section2"}, fs.sections(), csf_);
    }

    void test_method_(load_file) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {};
      fs.load(file_name);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_false(fs.stream().has_value(), csf_);
      file::remove(file_name);
    }

    void test_method_(load_stream) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto stream = file::open(file_name, ios::in|ios::out);
      auto fs = file_settings {stream};
      assert::is_empty(fs.file_path(), csf_);
      assert::is_empty(fs.key_values(), csf_);
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"), csf_);
      assert::is_empty(fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"), csf_);
      collection_assert::are_equivalent({"section1"}, fs.sections(), csf_);
      assert::is_true(fs.stream().has_value(), csf_);
      file::remove(file_name);
    }

    void test_method_(load_with_non_existent_file_name) {
      assert::throws<file_not_found_exception>([] {file_settings {}.load("non_existent_file_name.ini");}, csf_);
    }

    void test_method_(load_with_invalid_stream) {
      auto stream = fstream {"non_existent_file_name.ini", ios::in|ios::out};
      stream.close();
      assert::throws<io_exception>([&] {file_settings {}.load(stream);}, csf_);
    }
    
    void test_method_(read_key_with_fallback) {
      auto fs = file_settings {};
      assert::are_equal("default_value1", fs.read("key1", "default_value1"), csf_);
      assert::are_equal(42, fs.read("key2", 42), csf_);
      assert::are_equal("default_value1", fs.read("section1", "key1", "default_value1"), csf_);
      assert::are_equal(42, fs.read("section1", "key2", 42), csf_);
    }
    
    void test_method_(read_key) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\nkey2=84\n[section1]\nkey1=value2\nkey2=21\n");
      assert::are_equal("value1", fs.read("key1", "default_value1"), csf_);
      assert::are_equal(84, fs.read("key2", 42), csf_);
      assert::are_equal("value2", fs.read("section1", "key1", "default_value1"), csf_);
      assert::are_equal(21, fs.read("section1", "key2", 42), csf_);
    }
    
    void test_method_(read_invalid_key) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\n");
      assert::throws<format_exception>([&] {fs.read("key1", 42);}, csf_);
    }
    
    void test_method_(remove) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\nkey2=value2\nkey3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys(), csf_);
      fs.remove("key2");
      collection_assert::are_equivalent({"key1", "key3"}, fs.keys(), csf_);
      
      fs.from_string("[section1]\nkey1=value1\nkey2=value2\nkey3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys("section1"), csf_);
      fs.remove("section1", "key2");
      collection_assert::are_equivalent({"key1", "key3"}, fs.keys("section1"), csf_);
    }
    
    void test_method_(remove_all_keys) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\nkey2=value2\nkey3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys(), csf_);
      fs.remove_all_keys();
      collection_assert::is_empty(fs.keys(), csf_);
      
      fs.from_string("[section1]\nkey1=value1\nkey2=value2\nkey3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys("section1"), csf_);
      fs.remove_all_keys("section1");
      collection_assert::is_empty(fs.keys("section1"), csf_);
    }
    
    void test_method_(reset) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\nkey2=value2\nkey3=value3\n[section1]\nkey1=value1\nkey2=value2\nkey3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys(), csf_);
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys("section1"), csf_);
      fs.reset();
      collection_assert::is_empty(fs.keys(), csf_);
      collection_assert::is_empty(fs.keys("section1"), csf_);
    }

    void test_method_(save) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\nkey1=value1\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);

      auto fs = file_settings {file_name};
      fs.write("section1", "key2", "value2");
      fs.save();
      
      fs = file_settings {file_name};
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}}, fs.key_values("section1"), csf_);
      file::remove(file_name);
    }

    void test_method_(save_as_with_file) {
      auto file_name = "file.ini";
      file_assume::does_not_exist(file_name);

      auto fs = file_settings {};
      fs.from_string("[section1]\nkey1=value1\nkey2=value2\n");
      
      fs.save_as(file_name);
      
      fs = file_settings {file_name};
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}}, fs.key_values("section1"), csf_);
      file::remove(file_name);
    }

    void test_method_(save_as_with_stream) {
      auto file_name = "file.ini";
      file_assume::does_not_exist(file_name);

      auto fs = file_settings {};
      fs.from_string("[section1]\nkey1=value1\nkey2=value2\n");
      
      auto stream = file::create(file_name);
      fs.save_as(stream);
      stream.close();
      
      fs = file_settings {file_name};
      assert::are_equal(file_settings::string_map {{"key1", "value1"}, {"key2", "value2"}}, fs.key_values("section1"), csf_);
      file::remove(file_name);
    }

    void test_method_(to_string) {
      auto content = "[section1]\nkey1=value1\nkey2=value2\nkey3=value3\nkey4=value4\nkey5=value5\n\n[section2]\nkey1=value6\nkey2=value7\nkey3=value8\nkey4=value9\nkey5=value10\n";
      auto fs = file_settings {};
      fs.from_string(content);
      assert::are_equal(content, fs.to_string(), csf_);
    }
  };
}
