#include <xtd/io/path.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_string_reader) {
  public:
    void test_method_(peek_with_empty_string) {
      assert::are_equal(EOF, string_reader("").peek(), line_info_);
    }
    
    void test_method_(read_with_empty_string) {
      assert::are_equal(EOF, string_reader("").read(), line_info_);
    }
    
    void test_method_(read_buffer_with_empty_string) {
      vector<char> buffer(10);
      assert::are_equal(0U, string_reader("").text_reader::read(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer, line_info_);
    }
    
    void test_method_(read_block_with_empty_string) {
      vector<char> buffer(10);
      assert::are_equal(0U, string_reader("").text_reader::read_block(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer, line_info_);
    }
    
    void test_method_(read_line_with_empty_string) {
      assert::are_equal("", string_reader("").read_line(), line_info_);
    }
    
    void test_method_(read_to_end_with_empty_string) {
      assert::are_equal("", string_reader("").read_to_end(), line_info_);
    }
    
    void test_method_(peek_with_one_char_string) {
      assert::are_equal('a', string_reader("a").peek(), line_info_);
    }
    
    void test_method_(read_with_one_char_string) {
      assert::are_equal('a', string_reader("a").read(), line_info_);
    }
    
    void test_method_(read_buffer_with_one_char_string) {
      vector<char> buffer(10);
      assert::are_equal(1U, string_reader("a").text_reader::read(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'a', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer, line_info_);
    }
    
    void test_method_(read_block_with_one_char_string) {
      vector<char> buffer(10);
      assert::are_equal(1U, string_reader("a").text_reader::read_block(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'a', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer, line_info_);
    }
    
    void test_method_(read_line_with_one_char_string) {
      assert::are_equal("a", string_reader("a").read_line(), line_info_);
    }
    
    void test_method_(read_to_end_with_one_char_string) {
      assert::are_equal("a", string_reader("a").read_to_end(), line_info_);
    }
    
    void test_method_(peek_with_multi_char_string) {
      assert::are_equal('a', string_reader("abcdefghijklmno").peek(), line_info_);
    }
    
    void test_method_(read_with_multi_char_string) {
      assert::are_equal('a', string_reader("abcdefghijklmno").read(), line_info_);
    }
    
    void test_method_(read_buffer_with_multi_char_string) {
      vector<char> buffer(10);
      assert::are_equal(10U, string_reader("abcdefghijklmno").text_reader::read(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, buffer, line_info_);
    }
    
    void test_method_(read_block_with_multi_char_string) {
      vector<char> buffer(10);
      assert::are_equal(10U, string_reader("abcdefghijklmno").text_reader::read_block(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, buffer, line_info_);
    }
    
    void test_method_(read_line_with_multi_char_string) {
      assert::are_equal("abcdefghijklmno", string_reader("abcdefghijklmno").read_line(), line_info_);
    }
    
    void test_method_(read_to_end_with_multi_char_string) {
      assert::are_equal("abcdefghijklmno", string_reader("abcdefghijklmno").read_to_end(), line_info_);
    }
    
    void test_method_(peek_with_multi_line_string) {
      assert::are_equal('L', string_reader("Line 1\nLine 2\nLine 3").peek(), line_info_);
    }
    
    void test_method_(read_with_multi_line_string) {
      assert::are_equal('L', string_reader("Line 1\nLine 2\nLine 3").read(), line_info_);
    }
    
    void test_method_(read_buffer_with_multi_line_string) {
      vector<char> buffer(10);
      assert::are_equal(10U, string_reader("Line 1\nLine 2\nLine 3").text_reader::read(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'L', 'i', 'n', 'e', ' ', '1', '\n', 'L', 'i', 'n'}, buffer, line_info_);
    }
    
    void test_method_(read_block_with_multi_line_string) {
      vector<char> buffer(10);
      assert::are_equal(10U, string_reader("Line 1\nLine 2\nLine 3").text_reader::read_block(buffer, 0, 10), line_info_);
      collection_assert::are_equal({'L', 'i', 'n', 'e', ' ', '1', '\n', 'L', 'i', 'n'}, buffer, line_info_);
    }
    
    void test_method_(read_line_with_multi_line_string) {
      assert::are_equal("Line 1", string_reader("Line 1\nLine 2\nLine 3").read_line(), line_info_);
    }
    
    void test_method_(read_to_end_with_multi_line_string) {
      assert::are_equal("Line 1\nLine 2\nLine 3", string_reader("Line 1\nLine 2\nLine 3").read_to_end(), line_info_);
    }

    void test_method_(peek_and_read) {
      string_reader sr("abcde");
      assert::are_equal('a', sr.peek(), line_info_);
      assert::are_equal('a', sr.read(), line_info_);
      assert::are_equal('b', sr.read(), line_info_);
      assert::are_equal('c', sr.peek(), line_info_);
      assert::are_equal('c', sr.read(), line_info_);
      assert::are_equal('d', sr.read(), line_info_);
      assert::are_equal('e', sr.read(), line_info_);
      assert::are_equal(EOF, sr.peek(), line_info_);
      assert::are_equal(EOF, sr.read(), line_info_);
    }
    
    void test_method_(read_line) {
      string_reader sr("Line 1\nLine 2\nLine 3");
      assert::are_equal("Line 1", sr.read_line(), line_info_);
      assert::are_equal("Line 2", sr.read_line(), line_info_);
      assert::are_equal("Line 3", sr.read_line(), line_info_);
      assert::are_equal("", sr.read_line(), line_info_);
    }
    
    void test_method_(read_to_end) {
      string_reader sr("Line 1\nLine 2\nLine 3");
      assert::are_equal("Line 1\nLine 2\nLine 3", sr.read_to_end(), line_info_);
      assert::are_equal("", sr.read_to_end(), line_info_);
    }
    
    void test_method_(read_and_read_to_end) {
      string_reader sr("Line 1\nLine 2\nLine 3");
      assert::are_equal('L', sr.read(), line_info_);
      assert::are_equal('i', sr.read(), line_info_);
      assert::are_equal("ne 1\nLine 2\nLine 3", sr.read_to_end(), line_info_);
      assert::are_equal(EOF, sr.read(), line_info_);
    }

  };
}
