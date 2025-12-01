#include <xtd/io/file>
#include <xtd/io/file_not_found_exception>
#include <array>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(file_tests) {
    static constexpr auto test_file_name = "file.txt";
    
    static void test_initialize_(test_initialize) {
      if (std::ifstream(test_file_name).good())
        ::remove(test_file_name);
    }
    
    static void test_cleanup_(test_clean_up) {
      if (std::ifstream(test_file_name).good())
        ::remove(test_file_name);
    }
    
    void test_method_(append_all_lines) {
      assert::does_not_throw([] {file::append_all_lines(test_file_name, {"Line 1"});});
      assert::does_not_throw([] {file::append_all_lines(test_file_name, {"Line 2", "Line 3"});});
      
      std::ifstream file(test_file_name);
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Line 1\nLine 2\nLine 3\n", contents);
    }
    
    void test_method_(append_all_text) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "This is a text ");});
      assert::does_not_throw([] {file::append_all_text(test_file_name, "to append");});
      
      std::ifstream file(test_file_name);
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("This is a text to append", contents);
    }
    
    void test_method_(copy) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");});
      //std::cout << file::read_all_text(test_file_name) << std::endl;
      assert::does_not_throw([] {file::copy(test_file_name, "file2.txt");});
      
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(copy_with_override) {
      std::ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");});
      assert::does_not_throw([] {file::copy(test_file_name, "file2.txt", true);});
      
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(copy_with_override_false) {
      std::ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");});
      assert::throws<io_exception>([] {file::copy(test_file_name, "file2.txt", false);});
      
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Existing", contents);
      file.close();
      ::remove("file2.txt");
    }
    
    void test_method_(create) {
      auto file = file::create(test_file_name);
      
      assert::is_true(file.good());
      file.seekp(0, std::ios::end);
      assert::are_equal(0, file.tellp());
    }
    
    void test_method_(create_with_override) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");});
      auto file = file::create(test_file_name);
      
      assert::is_true(file.good());
      file.seekp(0, std::ios::end);
      assert::are_equal(0, file.tellp());
    }
    
    void test_method_(create_text) {
      auto file = file::create_text(test_file_name);
      
      assert::is_true(file.good());
      file.seekp(0, std::ios::end);
      assert::are_equal(0, file.tellp());
    }
    
    void test_method_(create_text_with_override) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");});
      auto file = file::create_text(test_file_name);
      
      assert::is_true(file.good());
      file.seekp(0, std::ios::end);
      assert::are_equal(0, file.tellp());
    }
    
    void test_method_(exists) {
      assert::is_false(file::exists(test_file_name));
      std::ofstream file(test_file_name);
      file.close();
      assert::is_true(file::exists(test_file_name));
    }
    
    void test_method_(get_attributes_directory) {
      assert::is_true((file::get_attributes(".") & file_attributes::directory) == file_attributes::directory);
    }
    
    void test_method_(get_attributes_normal) {
      std::ofstream file(test_file_name);
      file.close();
      assert::is_true((file::get_attributes(test_file_name) & file_attributes::normal) == file_attributes::normal || (file::get_attributes(test_file_name) & file_attributes::archive) == file_attributes::archive);
    }
    
    void test_method_(move) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");});
      assert::does_not_throw([] {file::move(test_file_name, "file2.txt");});
      
      assert::is_false(std::ifstream(test_file_name).good());
      std::ifstream file("file2.txt");
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(move_on_existing_file) {
      std::ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");});
      assert::throws<io_exception>([] {file::move(test_file_name, "file2.txt");});
      
      assert::is_true(std::ifstream(test_file_name).good());
      std::ifstream file(test_file_name);
      std::string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
      std::ifstream file2("file2.txt");
      contents = {std::istreambuf_iterator<char> {file2}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Existing", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(open_mode_in_with_existing_file) {
      std::ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      std::fstream file = file::open(test_file_name, std::ios::in);
      
      assert::is_true(file.good());
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
    }
    
    void test_method_(open_mode_in_without_existing_file) {
      assert::throws<file_not_found_exception>([] {file::open(test_file_name, std::ios::in);});
    }
    
    void test_method_(open_mode_out) {
      std::fstream file = file::open(test_file_name, std::ios::out);
      
      assert::is_true(file.good());
    }
    
    void test_method_(open_mode_out_with_existing_file) {
      std::ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      std::fstream file = file::open(test_file_name, std::ios::out);
      
      assert::is_true(file.good());
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::is_empty(contents);
    }
    
    void test_method_(open_read_with_existing_file) {
      std::ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      std::ifstream file = file::open_read(test_file_name);
      
      assert::is_true(file.good());
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
    }
    
    void test_method_(open_read_without_existing_file) {
      assert::throws<file_not_found_exception>([] {file::open_read(test_file_name);});
    }
    
    void test_method_(open_text_with_existing_file) {
      std::ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      std::ifstream file = file::open_text(test_file_name);
      
      assert::is_true(file.good());
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents);
    }
    
    void test_method_(open_text_without_existing_file) {
      assert::throws<file_not_found_exception>([] {file::open_text(test_file_name);});
    }
    
    void test_method_(open_write) {
      std::ofstream file = file::open_write(test_file_name);
      
      assert::is_true(file.good());
    }
    
    void test_method_(read_all_bytes) {
      std::ofstream existing_file(test_file_name, std::ios::binary | std::ios::out);
      array<byte> b = {0x42, 0x24, 0x12, 0x84};
      existing_file.write(reinterpret_cast<char*>(b.data()), b.length());
      existing_file.close();
      auto bytes = file::read_all_bytes(test_file_name);
      
      assert::are_equal(4_z, bytes.length());
      assert::are_equal(0x42, bytes[0]);
      assert::are_equal(0x24, bytes[1]);
      assert::are_equal(0x12, bytes[2]);
      assert::are_equal(0x84, bytes[3]);
    }
    
    void test_method_(read_all_bytes_with_unexisting_file) {
      assert::throws<file_not_found_exception>([] {file::read_all_bytes(test_file_name);});
    }
    
    void test_method_(read_all_lines) {
      std::ofstream existing_file(test_file_name);
      existing_file << "Line 1\nLine 2\nLine 3\n";
      existing_file.close();
      auto lines = file::read_all_lines(test_file_name);
      assert::are_equal(3_z, lines.length());
      assert::are_equal("Line 1", lines[0]);
      assert::are_equal("Line 2", lines[1]);
      assert::are_equal("Line 3", lines[2]);
    }
    
    void test_method_(read_all_lines_with_unexisting_file) {
      assert::throws<file_not_found_exception>([] {file::read_all_lines(test_file_name);});
    }
    
    void test_method_(read_all_text) {
      std::ofstream existing_file(test_file_name);
      existing_file << "This is a \nmultiline text";
      existing_file.close();
      std::string text = file::read_all_text(test_file_name);
      assert::are_equal("This is a \nmultiline text", text);
    }
    
    void test_method_(read_all_text_with_unexisting_file) {
      assert::throws<file_not_found_exception>([] {file::read_all_text(test_file_name);});
    }
    
    void test_method_(remove) {
      std::ofstream existing_file(test_file_name);
      existing_file.close();
      assert::is_true(std::ifstream(test_file_name).good());
      assert::does_not_throw([] {file::remove(test_file_name);});
      
      assert::is_false(std::ifstream(test_file_name).good());
    }
    
    void test_method_(replace) {
      auto file_name1 = "file1.txt";
      std::ofstream existing_file1(file_name1);
      existing_file1 << "Text1";
      existing_file1.close();
      auto file_name2 = "file2.txt";
      std::ofstream existing_file2(file_name2);
      existing_file2 << "Text2";
      existing_file2.close();
      auto file_name3 = "file2.bak";
      assert::does_not_throw([&] {file::replace(file_name1, file_name2, file_name3);});
      
      assert::is_false(std::ifstream(file_name1).good());
      assert::is_true(std::ifstream(file_name2).good());
      assert::is_true(std::ifstream(file_name3).good());
      std::ifstream file2(file_name2);
      string contents {std::istreambuf_iterator<char> {file2}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text1", contents);
      std::ifstream file3(file_name3);
      contents = string {std::istreambuf_iterator<char> {file3}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text2", contents);
      
      file2.close();
      file3.close();
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(replace_without_source) {
      auto file_name1 = "file1.txt";
      auto file_name2 = "file2.txt";
      std::ofstream existing_file2(file_name2);
      existing_file2 << "Text2";
      existing_file2.close();
      auto file_name3 = "file2.bak";
      assert::throws<file_not_found_exception>([&] {file::replace(file_name1, file_name2, file_name3);});
      
      assert::is_false(std::ifstream(file_name1).good());
      assert::is_true(std::ifstream(file_name2).good());
      assert::is_false(std::ifstream(file_name3).good());
      std::ifstream file2(file_name2);
      string contents {std::istreambuf_iterator<char> {file2}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text2", contents);
      
      file2.close();
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(replace_without_destination) {
      auto file_name1 = "file1.txt";
      std::ofstream existing_file1(file_name1);
      existing_file1 << "Text1";
      existing_file1.close();
      auto file_name2 = "file2.txt";
      auto file_name3 = "file2.bak";
      assert::throws<file_not_found_exception>([&] {file::replace(file_name1, file_name2, file_name3);});
      
      assert::is_true(std::ifstream(file_name1).good());
      assert::is_false(std::ifstream(file_name2).good());
      assert::is_false(std::ifstream(file_name3).good());
      std::ifstream file1(file_name1);
      string contents {std::istreambuf_iterator<char> {file1}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text1", contents);
      
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(replace_with_existing_destination_backuo) {
      auto file_name1 = "file1.txt";
      std::ofstream existing_file1(file_name1);
      existing_file1 << "Text1";
      existing_file1.close();
      auto file_name2 = "file2.txt";
      std::ofstream existing_file2(file_name2);
      existing_file2 << "Text2";
      existing_file2.close();
      auto file_name3 = "file2.bak";
      std::ofstream existing_file3(file_name3);
      existing_file3 << "Text3";
      existing_file3.close();
      assert::does_not_throw([&] {file::replace(file_name1, file_name2, file_name3);});
      
      assert::is_false(std::ifstream(file_name1).good());
      assert::is_true(std::ifstream(file_name2).good());
      assert::is_true(std::ifstream(file_name3).good());
      std::ifstream file2(file_name2);
      string contents {std::istreambuf_iterator<char> {file2}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text1", contents);
      std::ifstream file3(file_name3);
      contents = string {std::istreambuf_iterator<char> {file3}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Text2", contents);
      
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(write_all_lines) {
      assert::does_not_throw([] {file::write_all_lines(test_file_name, {"Line 1"});});
      assert::does_not_throw([] {file::write_all_lines(test_file_name, {"Line 2", "Line 3"});});
      
      std::ifstream file(test_file_name);
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("Line 2\nLine 3\n", contents);
    }
    
    void test_method_(write_all_text) {
      assert::does_not_throw([] {file::write_all_text(test_file_name, "This is a text ");});
      assert::does_not_throw([] {file::write_all_text(test_file_name, "to write");});
      
      std::ifstream file(test_file_name);
      string contents {std::istreambuf_iterator<char> {file}, std::istreambuf_iterator<char> {}};
      assert::are_equal("to write", contents);
    }
  };
}
