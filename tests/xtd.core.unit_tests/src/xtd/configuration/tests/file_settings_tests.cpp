#include <xtd/configuration/file_settings>
#include <xtd/io/file>
#include <xtd/io/file_not_found_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/file_assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/environment>
#include <xtd/as>

using namespace xtd;
using namespace xtd::configuration;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::configuration::tests {
  class test_class_(file_settings_tests) {
    auto test_method_(default_ctor) {
      auto fs = file_settings {};
      assert::is_false(fs.auto_save());
      assert::is_empty(fs.bottom_file_comment());
      assert::is_empty(fs.file_path());
      assert::is_empty(fs.key_values());
      assert::is_empty(fs.keys());
      assert::is_empty(fs.sections());
      assert::is_false(fs.stream().has_value());
      assert::is_empty(fs.top_file_comment());
    }
    
    auto test_method_(ctor_with_empty_string) {
      auto fs = file_settings {string::empty_string};
      assert::is_false(fs.auto_save());
      assert::is_empty(fs.bottom_file_comment());
      assert::is_empty(fs.file_path());
      assert::is_empty(fs.key_values());
      assert::is_empty(fs.keys());
      assert::is_empty(fs.sections());
      assert::is_false(fs.stream().has_value());
      assert::is_empty(fs.top_file_comment());
    }
    
    auto test_method_(ctor_with_non_existent_file_name) {
      auto file_name = "non_existent_file_name.ini";
      file_assume::does_not_exist(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save());
      assert::is_empty(fs.bottom_file_comment());
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::is_empty(fs.keys());
      assert::is_empty(fs.sections());
      assert::is_false(fs.stream().has_value());
      assert::is_empty(fs.top_file_comment());
    }
    
    auto test_method_(ctor_with_empty_file) {
      auto file_name = "empty_file.ini";
      file::write_all_text(file_name, "");
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save());
      assert::is_empty(fs.bottom_file_comment());
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::is_empty(fs.keys());
      assert::is_empty(fs.sections());
      assert::is_false(fs.stream().has_value());
      assert::is_empty(fs.top_file_comment());
      file::remove(file_name);
    }
    
    auto test_method_(ctor_with_file_containing_one_section) {
      auto file_name = "file.ini";
      auto file_content = "[section1]\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save());
      assert::is_empty(fs.bottom_file_comment());
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::is_empty(fs.key_values("section1"));
      assert::is_empty(fs.keys());
      assert::is_empty(fs.keys("section1"));
      collection_assert::are_equivalent({"section1"}, fs.sections());
      assert::is_false(fs.stream().has_value());
      assert::is_empty(fs.top_file_comment());
      file::remove(file_name);
    }
    
    auto test_method_(ctor_with_file_containing_many_sections) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "[section2]\n"
        "[section3]\n"
        "[section4]\n"
        "[section5]\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save());
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::is_empty(fs.key_values("section1"));
      assert::is_empty(fs.key_values("section2"));
      assert::is_empty(fs.key_values("section3"));
      assert::is_empty(fs.key_values("section4"));
      assert::is_empty(fs.key_values("section5"));
      assert::is_empty(fs.keys());
      assert::is_empty(fs.keys("section1"));
      assert::is_empty(fs.keys("section2"));
      assert::is_empty(fs.keys("section3"));
      assert::is_empty(fs.keys("section4"));
      assert::is_empty(fs.keys("section5"));
      collection_assert::are_equivalent({"section1", "section2", "section3", "section4", "section5"}, fs.sections());
      assert::is_false(fs.stream().has_value());
      file::remove(file_name);
    }
    
    auto test_method_(ctor_with_file_containing_one_section_and_one_key_value) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "key1=value1\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save());
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}}, fs.key_values("section1"));
      assert::is_empty(fs.keys());
      collection_assert::are_equivalent({"key1"}, fs.keys("section1"));
      collection_assert::are_equivalent({"section1"}, fs.sections());
      assert::is_false(fs.stream().has_value());
      file::remove(file_name);
    }
    
    auto test_method_(ctor_with_file_containing_one_section_and_many_key_values) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "key1=value1\n"
        "key2=value2\n"
        "key3=value3\n"
        "key4=value4\n"
        "key5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save());
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"));
      assert::is_empty(fs.keys());
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"));
      collection_assert::are_equivalent({"section1"}, fs.sections());
      assert::is_false(fs.stream().has_value());
      file::remove(file_name);
    }
    
    auto test_method_(ctor_with_file_containing_many_sections_and_many_key_values) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "key1=value1\n"
        "key2=value2\n"
        "key3=value3\n"
        "key4=value4\n"
        "key5=value5\n"
        "[section2]\n"
        "key6=value6\n"
        "key7=value7\n"
        "key8=value8\n"
        "key9=value9\n"
        "key10=value10\n"
        "[section3]\n"
        "key11=value11\n"
        "key12=value12\n"
        "key13=value13\n"
        "key14=value14\n"
        "key15=value15\n"
        "[section4]\n"
        "key16=value16\n"
        "key17=value17\n"
        "key18=value18\n"
        "key19=value19\n"
        "key20=value20\n"
        "[section5]\n"
        "key21=value21\n"
        "key22=value22\n"
        "key23=value23\n"
        "key24=value24\n"
        "key25=value25\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {file_name};
      assert::is_false(fs.auto_save());
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"));
      assert::are_equal(file_settings::string_dictionary {{"key6", "value6"}, {"key7", "value7"}, {"key8", "value8"}, {"key9", "value9"}, {"key10", "value10"}}, fs.key_values("section2"));
      assert::are_equal(file_settings::string_dictionary {{"key11", "value11"}, {"key12", "value12"}, {"key13", "value13"}, {"key14", "value14"}, {"key15", "value15"}}, fs.key_values("section3"));
      assert::are_equal(file_settings::string_dictionary {{"key16", "value16"}, {"key17", "value17"}, {"key18", "value18"}, {"key19", "value19"}, {"key20", "value20"}}, fs.key_values("section4"));
      assert::are_equal(file_settings::string_dictionary {{"key21", "value21"}, {"key22", "value22"}, {"key23", "value23"}, {"key24", "value24"}, {"key25", "value25"}}, fs.key_values("section5"));
      assert::is_empty(fs.keys());
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"));
      collection_assert::are_equivalent({"key6", "key7", "key8", "key9", "key10"}, fs.keys("section2"));
      collection_assert::are_equivalent({"key11", "key12", "key13", "key14", "key15"}, fs.keys("section3"));
      collection_assert::are_equivalent({"key16", "key17", "key18", "key19", "key20"}, fs.keys("section4"));
      collection_assert::are_equivalent({"key21", "key22", "key23", "key24", "key25"}, fs.keys("section5"));
      collection_assert::are_equivalent({"section1", "section2", "section3", "section4", "section5"}, fs.sections());
      assert::is_false(fs.stream().has_value());
      file::remove(file_name);
    }
    
    auto test_method_(ctor_with_stream_containing_one_section_and_many_key_values) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "key1=value1\n"
        "key2=value2\n"
        "key3=value3\n"
        "key4=value4\n"
        "key5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto stream = file::open(file_name, std::ios::in | std::ios::out);
      auto fs = file_settings {stream};
      assert::is_false(fs.auto_save());
      assert::is_empty(fs.file_path());
      assert::is_empty(fs.key_values());
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"));
      assert::is_empty(fs.keys());
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"));
      collection_assert::are_equivalent({"section1"}, fs.sections());
      assert::is_true(fs.stream().has_value());
      stream.close();
      file::remove(file_name);
    }
    
    auto test_method_(from_string) {
      auto fs = file_settings {};
      fs.from_string("[section1]\n"
                     "key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n"
                     "key4=value4\n"
                     "key5=value5\n");
      assert::is_empty(fs.key_values());
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"));
      assert::is_empty(fs.keys());
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"));
      collection_assert::are_equivalent({"section1"}, fs.sections());
      
      fs.from_string("[section2]\n"
                     "key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n"
                     "key4=value4\n"
                     "key5=value5\n");
      assert::is_empty(fs.key_values());
      assert::is_empty(fs.key_values("section1"));
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section2"));
      assert::is_empty(fs.keys());
      assert::is_empty(fs.keys("section1"));
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section2"));
      collection_assert::are_equivalent({"section2"}, fs.sections());
    }
    
    auto test_method_(load_file) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "key1=value1\n"
        "key2=value2\n"
        "key3=value3\n"
        "key4=value4\n"
        "key5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto fs = file_settings {};
      fs.load(file_name);
      assert::are_equal(path::combine(environment::current_directory(), file_name), fs.file_path());
      assert::is_empty(fs.key_values());
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"));
      assert::is_empty(fs.keys());
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"));
      collection_assert::are_equivalent({"section1"}, fs.sections());
      assert::is_false(fs.stream().has_value());
      file::remove(file_name);
    }
    
    auto test_method_(load_stream) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "key1=value1\n"
        "key2=value2\n"
        "key3=value3\n"
        "key4=value4\n"
        "key5=value5\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      auto stream = file::open(file_name, std::ios::in | std::ios::out);
      auto fs = file_settings {stream};
      assert::is_empty(fs.file_path());
      assert::is_empty(fs.key_values());
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}}, fs.key_values("section1"));
      assert::is_empty(fs.keys());
      collection_assert::are_equivalent({"key1", "key2", "key3", "key4", "key5"}, fs.keys("section1"));
      collection_assert::are_equivalent({"section1"}, fs.sections());
      assert::is_true(fs.stream().has_value());
      stream.close();
      file::remove(file_name);
    }
    
    auto test_method_(load_with_non_existent_file_name) {
      assert::throws<file_not_found_exception>([] {file_settings {}.load("non_existent_file_name.ini");});
    }
    
    auto test_method_(load_with_invalid_stream) {
      auto stream = std::fstream {"non_existent_file_name.ini", std::ios::in | std::ios::out};
      stream.close();
      assert::throws<io_exception>([&] {file_settings {}.load(stream);});
    }
    
    auto test_method_(read_key_with_fallback) {
      auto fs = file_settings {};
      assert::are_equal("default_value1", fs.read("key1", "default_value1"));
      assert::are_equal(42, fs.read("key2", 42));
      assert::are_equal("default_value1", fs.read("section1", "key1", "default_value1"));
      assert::are_equal(42, fs.read("section1", "key2", 42));
    }
    
    auto test_method_(read_key) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\n"
                     "key2=84\n"
                     "[section1]\n"
                     "key1=value2\n"
                     "key2=21\n");
      assert::are_equal("value1", fs.read("key1", "default_value1"));
      assert::are_equal(84, fs.read("key2", 42));
      assert::are_equal("value2", fs.read("section1", "key1", "default_value1"));
      assert::are_equal(21, fs.read("section1", "key2", 42));
    }
    
    auto test_method_(read_invalid_key) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\n");
      assert::throws<format_exception>([&] {fs.read("key1", 42);});
    }
    
    auto test_method_(remove) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys());
      fs.remove("key2");
      collection_assert::are_equivalent({"key1", "key3"}, fs.keys());
      
      fs.from_string("[section1]\n"
                     "key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys("section1"));
      fs.remove("section1", "key2");
      collection_assert::are_equivalent({"key1", "key3"}, fs.keys("section1"));
    }
    
    auto test_method_(remove_all_keys) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys());
      fs.remove_all_keys();
      collection_assert::is_empty(fs.keys());
      
      fs.from_string("[section1]\n"
                     "key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys("section1"));
      fs.remove_all_keys("section1");
      collection_assert::is_empty(fs.keys("section1"));
    }
    
    auto test_method_(reset) {
      auto fs = file_settings {};
      fs.from_string("key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n"
                     "[section1]\n"
                     "key1=value1\n"
                     "key2=value2\n"
                     "key3=value3\n");
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys());
      collection_assert::are_equivalent({"key1", "key2", "key3"}, fs.keys("section1"));
      fs.reset();
      collection_assert::is_empty(fs.keys());
      collection_assert::is_empty(fs.keys("section1"));
    }
    
    auto test_method_(save) {
      auto file_name = "file.ini";
      auto file_content =
        "[section1]\n"
        "key1=value1\n";
      file::write_all_text(file_name, file_content);
      file_assume::exists(file_name);
      
      auto fs = file_settings {file_name};
      fs.write("section1", "key2", "value2");
      fs.save();
      
      fs = file_settings {file_name};
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}}, fs.key_values("section1"));
      file::remove(file_name);
    }
    
    auto test_method_(save_as_with_file) {
      auto file_name = "file.ini";
      file_assume::does_not_exist(file_name);
      
      auto fs = file_settings {};
      fs.from_string("[section1]\n"
                     "key1=value1\n"
                     "key2=value2\n");
                     
      fs.save_as(file_name);
      
      fs = file_settings {file_name};
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}}, fs.key_values("section1"));
      file::remove(file_name);
    }
    
    auto test_method_(save_as_with_stream) {
      auto file_name = "file.ini";
      file_assume::does_not_exist(file_name);
      
      auto fs = file_settings {};
      fs.from_string("[section1]\n"
                     "key1=value1\n"
                     "key2=value2\n");
                     
      auto stream = file::create(file_name);
      fs.save_as(stream);
      stream.close();
      
      fs = file_settings {file_name};
      assert::are_equal(file_settings::string_dictionary {{"key1", "value1"}, {"key2", "value2"}}, fs.key_values("section1"));
      file::remove(file_name);
    }
    
    auto test_method_(to_string) {
      auto content =
        "[section1]\n"
        "key1 = value1\n"
        "key2 = value2\n"
        "key3 = value3\n"
        "key4 = value4\n"
        "key5 = value5\n"
        "\n"
        "[section2]\n"
        "key1 = value6\n"
        "key2 = value7\n"
        "key3 = value8\n"
        "key4 = value9\n"
        "key5 = value10\n";
      auto fs = file_settings {};
      fs.from_string(content);
      assert::are_equal(content, fs.to_string());
    }
    
    auto test_method_(to_string_empty) {
      auto fs = file_settings {};
      assert::is_empty(fs.to_string());
    }
    
    auto test_method_(to_string_with_global_key_values) {
      auto fs = file_settings {};
      fs.write("key1", "value1");
      fs.write("key2", "value2");
      assert::are_equal("key1 = value1\n"
                        "key2 = value2\n", fs.to_string());
    }
    
    auto test_method_(to_string_with_section_key_values) {
      auto fs = file_settings {};
      fs.write("section1", "key1", "value1");
      fs.write("section1", "key2", "value2");
      fs.write("section2", "key1", "value1");
      fs.write("section2", "key2", "value2");
      assert::are_equal("[section1]\n"
                        "key1 = value1\n"
                        "key2 = value2\n"
                        "\n"
                        "[section2]\n"
                        "key1 = value1\n"
                        "key2 = value2\n", fs.to_string());
    }
    
    auto test_method_(top_file_comment_on_one_line) {
      auto fs = file_settings {};
      
      fs.top_file_comment("Top file comment on one line");
      assert::are_equal("Top file comment on one line", fs.top_file_comment());
    }
    
    auto test_method_(top_file_comment_on_multi_line) {
      auto fs = file_settings {};
      
      fs.top_file_comment("Top file comment\non multi line");
      assert::are_equal("Top file comment\non multi line", fs.top_file_comment());
    }
    
    auto test_method_(write) {
      auto fs = file_settings {};
      
      fs.write("key1", "value1");
      fs.write("key2", 21);
      fs.write("section1", "key1", "value2");
      fs.write("section1", "key2", 84);
      
      assert::are_equal("value1", fs.read("key1", "default_value1"));
      assert::are_equal(21, fs.read("key2", 42));
      assert::are_equal("value2", fs.read("section1", "key1", "default_value1"));
      assert::are_equal(84, fs.read("section1", "key2", 42));
    }
    
    auto test_method_(array_operator) {
      auto fs = file_settings {};
      
      fs[""]["key1"] = "value1";
      fs[""]["key2"] = "value2";
      fs[""]["key3"] = as<string>(42);
      fs["section1"]["key1"] = "value3";
      fs["section1"]["key2"] = "value4";
      fs["section1"]["key3"] = as<string>(21);
      fs["section2"]["key1"] = "value5";
      fs["section2"]["key2"] = "value6";
      fs["section2"]["key3"] = as<string>(84);
      
      assert::are_equal("value1", fs[""]["key1"]);
      assert::are_equal("value2", fs[""]["key2"]);
      assert::are_equal(42, as<int>(fs[""]["key3"]));
      assert::are_equal("value3", fs["section1"]["key1"]);
      assert::are_equal("value4", fs["section1"]["key2"]);
      assert::are_equal(21, as<int>(fs["section1"]["key3"]));
      assert::are_equal("value5", fs["section2"]["key1"]);
      assert::are_equal("value6", fs["section2"]["key2"]);
      assert::are_equal(84, as<int>(fs["section2"]["key3"]));
    }
    
    auto test_method_(from_string_with_spaces_comments_and_escape_sequences) {
      auto content =
        "# Section 1\n"
        "[section 1]\n"
        "  key\\ 1 = value\\ \\ 1  # Comment key 1 # hoo\n"
        "  key 2 = value==2  \n"
        "  key 3 = value\\=\\=3  \n"
        "  key 4 = value  4  \n"
        "  key 5 = \"\tvalue  5  \"; Comment key 5;;;;\n"
        "\n"
        "; Section 2###\n"
        "[section 2]; Other comment for section 2\n"
        "  \"key 1\" = value  6\n"
        "  key 2 = value  7\n"
        "  key 3 = value  8\n"
        "  key 4 = value  9\n"
        "  key 5 = value 10\n";
      auto fs = file_settings {};
      fs.from_string(content);
      assert::are_equal(file_settings::string_dictionary {{"key 1", "value  1"}, {"key 2", "value==2"}, {"key 3", "value==3"}, {"key 4", "value  4"}, {"key 5", "\tvalue  5  "}}, fs.key_values("section 1"));
      assert::are_equal(file_settings::string_dictionary {{"key 1", "value  6"}, {"key 2", "value  7"}, {"key 3", "value  8"}, {"key 4", "value  9"}, {"key 5", "value 10"}}, fs.key_values("section 2"));
      fs.save_as("test.ini");
      xtd::io::file::remove("test.ini");
    }
  };
}
