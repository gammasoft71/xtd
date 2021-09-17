#include <xtd/io/file.h>
#include <xtd/xtd.tunit>
#include <array>

using namespace std;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_file) {
  public:
    static constexpr auto test_file_name = "file.txt";

    void test_initialize_(test_initialize) {
      if (ifstream(test_file_name).good())
        ::remove(test_file_name);
    }
    
    void test_cleanup_(test_clean_up) {
      if (ifstream(test_file_name).good())
        ::remove(test_file_name);
    }

    void test_method_(append_all_lines) {
      assert::does_not_throw([] {file::append_all_lines(test_file_name, {"Line 1"});}, csf_);
      assert::does_not_throw([] {file::append_all_lines(test_file_name, {"Line 2", "Line 3"});}, csf_);
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Line 1\nLine 2\nLine 3\n", contents, csf_);
    }

    void test_method_(append_all_text) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "This is a text ");}, csf_);
      assert::does_not_throw([] {file::append_all_text(test_file_name, "to append");}, csf_);
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("This is a text to append", contents, csf_);
    }
    
    void test_method_(copy) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");}, csf_);
      std::cout << file::read_all_text(test_file_name) << std::endl;
      assert::does_not_throw([] {file::copy(test_file_name, "file2.txt");}, csf_);
      
      assert::is_true(ifstream(test_file_name).good(), csf_);
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents, csf_);
      ::remove("file2.txt");
    }

    void test_method_(copy_with_override) {
      ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");}, csf_);
      assert::does_not_throw([] {file::copy(test_file_name, "file2.txt", true);}, csf_);
      
      assert::is_true(ifstream(test_file_name).good(), csf_);
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents, csf_);
      ::remove("file2.txt");
    }
    
    void test_method_(copy_with_override_false) {
      ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");}, csf_);
      assert::throws<argument_exception>([] {file::copy(test_file_name, "file2.txt", false);}, csf_);
      
      assert::is_true(ifstream(test_file_name).good(), csf_);
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Existing", contents, csf_);
      file.close();
      ::remove("file2.txt");
    }

    void test_method_(create) {
      auto file = file::create(test_file_name);
      
      assert::is_true(file.good(), csf_);
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp(), csf_);
    }
    
    void test_method_(create_with_override) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");}, csf_);
      auto file = file::create(test_file_name);
      
      assert::is_true(file.good(), csf_);
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp(), csf_);
    }

    void test_method_(create_text) {
      auto file = file::create_text(test_file_name);
      
      assert::is_true(file.good(), csf_);
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp(), csf_);
    }
    
    void test_method_(create_text_with_override) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");}, csf_);
      auto file = file::create_text(test_file_name);
      
      assert::is_true(file.good(), csf_);
      file.seekp(0, ios::end);
      assert::are_equal(0, file.tellp(), csf_);
    }

    void test_method_(exists) {
      assert::is_false(file::exists(test_file_name), csf_);
      ofstream file(test_file_name);
      file.close();
      assert::is_true(file::exists(test_file_name), csf_);
    }
    
    void test_method_(get_attributes_directory) {
      assert::is_true((file::get_attributes(".") & file_attributes::directory) == file_attributes::directory, csf_);
    }
    
    void test_method_(get_attributes_normal) {
      ofstream file(test_file_name);
      file.close();
      assert::is_true((file::get_attributes(test_file_name) & file_attributes::normal) == file_attributes::normal || (file::get_attributes(test_file_name) & file_attributes::archive) == file_attributes::archive, csf_);
    }
    
    void test_method_(move) {
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");}, csf_);
      assert::does_not_throw([] {file::move(test_file_name, "file2.txt");}, csf_);
      
      assert::is_false(ifstream(test_file_name).good(), csf_);
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents, csf_);
      ::remove("file2.txt");
    }
    
    void test_method_(move_on_existing_file) {
      ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::does_not_throw([] {file::append_all_text(test_file_name, "Text");}, csf_);
      assert::throws<argument_exception>([] {file::move(test_file_name, "file2.txt");}, csf_);
      
      assert::is_true(ifstream(test_file_name).good(), csf_);
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents, csf_);
      ifstream file2("file2.txt");
      contents = {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal("Existing", contents, csf_);
      ::remove("file2.txt");
    }
    
    void test_method_(open_mode_in_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      fstream file = file::open(test_file_name, ios::in);
      
      assert::is_true(file.good(), csf_);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents, csf_);
    }
    
    void test_method_(open_mode_in_without_existing_file) {
      assert::throws<file_not_found_exception>([] {file::open(test_file_name, ios::in);}, csf_);
    }
    
    void test_method_(open_mode_out) {
      fstream file = file::open(test_file_name, ios::out);
      
      assert::is_true(file.good(), csf_);
    }
    
    void test_method_(open_mode_out_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      fstream file = file::open(test_file_name, ios::out);
      
      assert::is_true(file.good(), csf_);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::is_empty(contents, csf_);
    }
    
    void test_method_(open_read_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      ifstream file = file::open_read(test_file_name);
      
      assert::is_true(file.good(), csf_);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents, csf_);
    }
    
    void test_method_(open_read_without_existing_file) {
      assert::throws<file_not_found_exception>([] {file::open_read(test_file_name);}, csf_);
    }
    
    void test_method_(open_text_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      ifstream file = file::open_text(test_file_name);
      
      assert::is_true(file.good(), csf_);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Text", contents, csf_);
    }
    
    void test_method_(open_text_without_existing_file) {
      assert::throws<file_not_found_exception>([] {file::open_text(test_file_name);}, csf_);
    }
    
    void test_method_(open_write) {
      ofstream file = file::open_write(test_file_name);
      
      assert::is_true(file.good(), csf_);
    }
    
    void test_method_(read_all_bytes) {
      ofstream existing_file(test_file_name, ios::binary | ios::out);
      array<unsigned char, 4> b = {0x42, 0x24, 0x12, 0x84};
      existing_file.write(reinterpret_cast<char*>(b.data()), b.size());
      existing_file.close();
      std::vector<unsigned char> bytes = file::read_all_bytes(test_file_name);
      
      assert::are_equal(4U, bytes.size(), csf_);
      assert::are_equal(0x42, bytes[0], csf_);
      assert::are_equal(0x24, bytes[1], csf_);
      assert::are_equal(0x12, bytes[2], csf_);
      assert::are_equal(0x84, bytes[3], csf_);
    }
    
    void test_method_(read_all_bytes_with_unexisting_file) {
      assert::throws<file_not_found_exception>([] {file::read_all_bytes(test_file_name);}, csf_);
    }
    
    void test_method_(read_all_lines) {
      ofstream existing_file(test_file_name);
      existing_file << "Line 1\nLine 2\nLine 3\n";
      existing_file.close();
      std::vector<ustring> lines = file::read_all_lines(test_file_name);
      assert::are_equal(3U, lines.size(), csf_);
      assert::are_equal("Line 1", lines[0], csf_);
      assert::are_equal("Line 2", lines[1], csf_);
      assert::are_equal("Line 3", lines[2], csf_);
    }
    
    void test_method_(read_all_lines_with_unexisting_file) {
      assert::throws<file_not_found_exception>([] {file::read_all_lines(test_file_name);}, csf_);
    }
    
    void test_method_(read_all_text) {
      ofstream existing_file(test_file_name);
      existing_file << "This is a \nmultiline text";
      existing_file.close();
      std::string text = file::read_all_text(test_file_name);
      assert::are_equal("This is a \nmultiline text", text, csf_);
    }
    
    void test_method_(read_all_text_with_unexisting_file) {
      assert::throws<file_not_found_exception>([] {file::read_all_text(test_file_name);}, csf_);
    }
    
    void test_method_(remove) {
      ofstream existing_file(test_file_name);
      existing_file.close();
      assert::is_true(ifstream(test_file_name).good(), csf_);
      assert::does_not_throw([] {file::remove(test_file_name);}, csf_);
      
      assert::is_false(ifstream(test_file_name).good(), csf_);
    }
    
    void test_method_(replace) {
      auto file_name1 = "file1.txt";
      ofstream existing_file1(file_name1);
      existing_file1 << "Text1";
      existing_file1.close();
      auto file_name2 = "file2.txt";
      ofstream existing_file2(file_name2);
      existing_file2 << "Text2";
      existing_file2.close();
      auto file_name3 = "file2.bak";
      assert::does_not_throw([&] {file::replace(file_name1, file_name2, file_name3);}, csf_);
      
      assert::is_false(ifstream(file_name1).good(), csf_);
      assert::is_true(ifstream(file_name2).good(), csf_);
      assert::is_true(ifstream(file_name3).good(), csf_);
      ifstream file2(file_name2);
      string contents {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal("Text1", contents, csf_);
      ifstream file3(file_name3);
      contents = {istreambuf_iterator<char> {file3}, istreambuf_iterator<char> {}};
      assert::are_equal("Text2", contents, csf_);
      
      file2.close();
      file3.close();
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(replace_without_source) {
      auto file_name1 = "file1.txt";
      auto file_name2 = "file2.txt";
      ofstream existing_file2(file_name2);
      existing_file2 << "Text2";
      existing_file2.close();
      auto file_name3 = "file2.bak";
      assert::throws<file_not_found_exception>([&] {file::replace(file_name1, file_name2, file_name3);}, csf_);
      
      assert::is_false(ifstream(file_name1).good(), csf_);
      assert::is_true(ifstream(file_name2).good(), csf_);
      assert::is_false(ifstream(file_name3).good(), csf_);
      ifstream file2(file_name2);
      string contents {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal("Text2", contents, csf_);
      
      file2.close();
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(replace_without_destination) {
      auto file_name1 = "file1.txt";
      ofstream existing_file1(file_name1);
      existing_file1 << "Text1";
      existing_file1.close();
      auto file_name2 = "file2.txt";
      auto file_name3 = "file2.bak";
      assert::throws<file_not_found_exception>([&] {file::replace(file_name1, file_name2, file_name3);}, csf_);
      
      assert::is_true(ifstream(file_name1).good(), csf_);
      assert::is_false(ifstream(file_name2).good(), csf_);
      assert::is_false(ifstream(file_name3).good(), csf_);
      ifstream file1(file_name1);
      string contents {istreambuf_iterator<char> {file1}, istreambuf_iterator<char> {}};
      assert::are_equal("Text1", contents, csf_);
      
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(replace_with_existing_destination_backuo) {
      auto file_name1 = "file1.txt";
      ofstream existing_file1(file_name1);
      existing_file1 << "Text1";
      existing_file1.close();
      auto file_name2 = "file2.txt";
      ofstream existing_file2(file_name2);
      existing_file2 << "Text2";
      existing_file2.close();
      auto file_name3 = "file2.bak";
      ofstream existing_file3(file_name3);
      existing_file3 << "Text3";
      existing_file3.close();
      assert::does_not_throw([&] {file::replace(file_name1, file_name2, file_name3);}, csf_);
      
      assert::is_false(ifstream(file_name1).good(), csf_);
      assert::is_true(ifstream(file_name2).good(), csf_);
      assert::is_true(ifstream(file_name3).good(), csf_);
      ifstream file2(file_name2);
      string contents {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal("Text1", contents, csf_);
      ifstream file3(file_name3);
      contents = {istreambuf_iterator<char> {file3}, istreambuf_iterator<char> {}};
      assert::are_equal("Text2", contents, csf_);
      
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(write_all_lines) {
      assert::does_not_throw([] {file::write_all_lines(test_file_name, {"Line 1"});}, csf_);
      assert::does_not_throw([] {file::write_all_lines(test_file_name, {"Line 2", "Line 3"});}, csf_);
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("Line 2\nLine 3\n", contents, csf_);
    }

    void test_method_(write_all_text) {
      assert::does_not_throw([] {file::write_all_text(test_file_name, "This is a text ");}, csf_);
      assert::does_not_throw([] {file::write_all_text(test_file_name, "to write");}, csf_);
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal("to write", contents, csf_);
    }
  };
}
