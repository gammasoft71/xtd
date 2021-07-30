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
      assert::is_true_(file::append_all_lines(test_file_name, {"Line 1"}));
      assert::is_true_(file::append_all_lines(test_file_name, {"Line 2", "Line 3"}));
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Line 1\nLine 2\nLine 3\n", contents);
    }

    void test_method_(append_all_text) {
      assert::is_true_(file::append_all_text(test_file_name, "This is a text "));
      assert::is_true_(file::append_all_text(test_file_name, "to append"));
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("This is a text to append", contents);
    }
    
    void test_method_(copy) {
      assert::is_true_(file::append_all_text(test_file_name, "Text"));
      std::cout << file::read_all_text(test_file_name) << std::endl;
      assert::is_true_(file::copy(test_file_name, "file2.txt"));
      
      assert::is_true_(ifstream(test_file_name).good());
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text", contents);
      ::remove("file2.txt");
    }

    void test_method_(copy_with_override) {
      ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::is_true_(file::append_all_text(test_file_name, "Text"));
      assert::is_true_(file::copy(test_file_name, "file2.txt", true));
      
      assert::is_true_(ifstream(test_file_name).good());
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(copy_with_override_false) {
      ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::is_true_(file::append_all_text(test_file_name, "Text"));
      assert::is_false_(file::copy(test_file_name, "file2.txt", false));
      
      assert::is_true_(ifstream(test_file_name).good());
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Existing", contents);
      file.close();
      ::remove("file2.txt");
    }

    void test_method_(create) {
      auto file = file::create(test_file_name);
      
      assert::is_true_(file.good());
      file.seekp(0, ios::end);
      assert::are_equal_(0, file.tellp());
    }
    
    void test_method_(create_with_override) {
      assert::is_true_(file::append_all_text(test_file_name, "Text"));
      auto file = file::create(test_file_name);
      
      assert::is_true_(file.good());
      file.seekp(0, ios::end);
      assert::are_equal_(0, file.tellp());
    }

    void test_method_(create_text) {
      auto file = file::create_text(test_file_name);
      
      assert::is_true_(file.good());
      file.seekp(0, ios::end);
      assert::are_equal_(0, file.tellp());
    }
    
    void test_method_(create_text_with_override) {
      assert::is_true_(file::append_all_text(test_file_name, "Text"));
      auto file = file::create_text(test_file_name);
      
      assert::is_true_(file.good());
      file.seekp(0, ios::end);
      assert::are_equal_(0, file.tellp());
    }

    void test_method_(exists) {
      assert::is_false_(file::exists(test_file_name));
      ofstream file(test_file_name);
      file.close();
      assert::is_true_(file::exists(test_file_name));
    }
    
    void test_method_(get_attributes_directory) {
      assert::is_true_((file::get_attributes(".") & file_attributes::directory) == file_attributes::directory);
    }
    
    void test_method_(get_attributes_normal) {
      ofstream file(test_file_name);
      file.close();
      assert::is_true_((file::get_attributes(test_file_name) & file_attributes::normal) == file_attributes::normal || (file::get_attributes(test_file_name) & file_attributes::archive) == file_attributes::archive);
    }
    
    void test_method_(move) {
      assert::is_true_(file::append_all_text(test_file_name, "Text"));
      assert::is_true_(file::move(test_file_name, "file2.txt"));
      
      assert::is_false_(ifstream(test_file_name).good());
      ifstream file("file2.txt");
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(move_on_existing_file) {
      ofstream existing_file("file2.txt");
      existing_file << "Existing";
      existing_file.close();
      assert::is_true_(file::append_all_text(test_file_name, "Text"));
      assert::is_false_(file::move(test_file_name, "file2.txt"));
      
      assert::is_true_(ifstream(test_file_name).good());
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text", contents);
      ifstream file2("file2.txt");
      contents = {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal_("Existing", contents);
      ::remove("file2.txt");
    }
    
    void test_method_(open_mode_in_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      fstream file = file::open(test_file_name, ios::in);
      
      assert::is_true_(file.good());
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text", contents);
    }
    
    void test_method_(open_mode_in_without_existing_file) {
      fstream file = file::open(test_file_name, ios::in);
      
      assert::is_false_(file.good());
    }
    
    void test_method_(open_mode_out) {
      fstream file = file::open(test_file_name, ios::out);
      
      assert::is_true_(file.good());
    }
    
    void test_method_(open_mode_out_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      fstream file = file::open(test_file_name, ios::out);
      
      assert::is_true_(file.good());
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::is_empty_(contents);
    }
    
    void test_method_(open_read_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      ifstream file = file::open_read(test_file_name);
      
      assert::is_true_(file.good());
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text", contents);
    }
    
    void test_method_(open_read_without_existing_file) {
      ifstream file = file::open_read(test_file_name);
      
      assert::is_false_(file.good());
    }
    
    void test_method_(open_text_with_existing_file) {
      ofstream existing_file(test_file_name);
      existing_file << "Text";
      existing_file.close();
      ifstream file = file::open_text(test_file_name);
      
      assert::is_true_(file.good());
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text", contents);
    }
    
    void test_method_(open_text_without_existing_file) {
      ifstream file = file::open_text(test_file_name);
      
      assert::is_false_(file.good());
    }
    
    void test_method_(open_write) {
      ofstream file = file::open_write(test_file_name);
      
      assert::is_true_(file.good());
    }
    
    void test_method_(read_all_bytes) {
      ofstream existing_file(test_file_name, ios::binary | ios::out);
      array<unsigned char, 4> b = {0x42, 0x24, 0x12, 0x84};
      existing_file.write(reinterpret_cast<char*>(b.data()), b.size());
      existing_file.close();
      std::vector<unsigned char> bytes = file::read_all_bytes(test_file_name);
      
      assert::are_equal_(4U, bytes.size());
      assert::are_equal_(0x42, bytes[0]);
      assert::are_equal_(0x24, bytes[1]);
      assert::are_equal_(0x12, bytes[2]);
      assert::are_equal_(0x84, bytes[3]);
    }
    
    void test_method_(read_all_bytes_with_unexisting_file) {
      std::vector<unsigned char> bytes = file::read_all_bytes(test_file_name);
      assert::is_empty_(bytes);
    }
    
    void test_method_(read_all_lines) {
      ofstream existing_file(test_file_name);
      existing_file << "Line 1\nLine 2\nLine 3\n";
      existing_file.close();
      std::vector<ustring> lines = file::read_all_lines(test_file_name);
      assert::are_equal_(3U, lines.size());
      assert::are_equal_("Line 1", lines[0]);
      assert::are_equal_("Line 2", lines[1]);
      assert::are_equal_("Line 3", lines[2]);
    }
    
    void test_method_(read_all_lines_with_unexisting_file) {
      std::vector<ustring> lines = file::read_all_lines(test_file_name);
      assert::is_empty_(lines);
    }
    
    void test_method_(read_all_text) {
      ofstream existing_file(test_file_name);
      existing_file << "This is a \nmultiline text";
      existing_file.close();
      std::string text = file::read_all_text(test_file_name);
      assert::are_equal_("This is a \nmultiline text", text);
    }
    
    void test_method_(read_all_text_with_unexisting_file) {
      std::string text = file::read_all_text(test_file_name);
      assert::is_empty_(text);
    }
    
    void test_method_(remove) {
      ofstream existing_file(test_file_name);
      existing_file.close();
      assert::is_true_(ifstream(test_file_name).good());
      file::remove(test_file_name);
      
      assert::is_false_(ifstream(test_file_name).good());
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
      assert::is_true_(file::replace(file_name1, file_name2, file_name3));
      
      assert::is_false_(ifstream(file_name1).good());
      assert::is_true_(ifstream(file_name2).good());
      assert::is_true_(ifstream(file_name3).good());
      ifstream file2(file_name2);
      string contents {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text1", contents);
      ifstream file3(file_name3);
      contents = {istreambuf_iterator<char> {file3}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text2", contents);
      
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
      assert::is_false_(file::replace(file_name1, file_name2, file_name3));
      
      assert::is_false_(ifstream(file_name1).good());
      assert::is_true_(ifstream(file_name2).good());
      assert::is_false_(ifstream(file_name3).good());
      ifstream file2(file_name2);
      string contents {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text2", contents);
      
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
      assert::is_false_(file::replace(file_name1, file_name2, file_name3));
      
      assert::is_true_(ifstream(file_name1).good());
      assert::is_false_(ifstream(file_name2).good());
      assert::is_false_(ifstream(file_name3).good());
      ifstream file1(file_name1);
      string contents {istreambuf_iterator<char> {file1}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text1", contents);
      
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
      assert::is_true_(file::replace(file_name1, file_name2, file_name3));
      
      assert::is_false_(ifstream(file_name1).good());
      assert::is_true_(ifstream(file_name2).good());
      assert::is_true_(ifstream(file_name3).good());
      ifstream file2(file_name2);
      string contents {istreambuf_iterator<char> {file2}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text1", contents);
      ifstream file3(file_name3);
      contents = {istreambuf_iterator<char> {file3}, istreambuf_iterator<char> {}};
      assert::are_equal_("Text2", contents);
      
      ::remove(file_name1);
      ::remove(file_name2);
      ::remove(file_name3);
    }
    
    void test_method_(write_all_lines) {
      assert::is_true_(file::write_all_lines(test_file_name, {"Line 1"}));
      assert::is_true_(file::write_all_lines(test_file_name, {"Line 2", "Line 3"}));
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("Line 2\nLine 3\n", contents);
    }

    void test_method_(write_all_text) {
      assert::is_true_(file::write_all_text(test_file_name, "This is a text "));
      assert::is_true_(file::write_all_text(test_file_name, "to write"));
      
      ifstream file(test_file_name);
      string contents {istreambuf_iterator<char> {file}, istreambuf_iterator<char> {}};
      assert::are_equal_("to write", contents);
    }
  };
}
