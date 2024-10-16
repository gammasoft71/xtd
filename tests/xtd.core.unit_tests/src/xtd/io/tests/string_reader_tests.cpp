#include <xtd/io/path>
#include <xtd/io/string_reader>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(string_reader_tests) {
    void test_method_(peek_with_empty_string) {
      assert::are_equal(EOF, string_reader("").peek());
    }
    
    void test_method_(read_with_empty_string) {
      assert::are_equal(EOF, string_reader("").read());
    }
    
    void test_method_(read_buffer_with_empty_string) {
      std::vector<char> buffer(10);
      assert::are_equal(0u, string_reader("").text_reader::read(buffer, 0, 10));
      collection_assert::are_equal({'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer);
    }
    
    void test_method_(read_block_with_empty_string) {
      std::vector<char> buffer(10);
      assert::are_equal(0u, string_reader("").text_reader::read_block(buffer, 0, 10));
      collection_assert::are_equal({'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer);
    }
    
    void test_method_(read_line_with_empty_string) {
      assert::is_empty(string_reader("").read_line());
    }
    
    void test_method_(read_to_end_with_empty_string) {
      assert::is_empty(string_reader("").read_to_end());
    }
    
    void test_method_(peek_with_one_char_string) {
      assert::are_equal('a', string_reader("a").peek());
    }
    
    void test_method_(read_with_one_char_string) {
      assert::are_equal('a', string_reader("a").read());
    }
    
    void test_method_(read_buffer_with_one_char_string) {
      std::vector<char> buffer(10);
      assert::are_equal(1u, string_reader("a").text_reader::read(buffer, 0, 10));
      collection_assert::are_equal({'a', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer);
    }
    
    void test_method_(read_block_with_one_char_string) {
      std::vector<char> buffer(10);
      assert::are_equal(1u, string_reader("a").text_reader::read_block(buffer, 0, 10));
      collection_assert::are_equal({'a', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}, buffer);
    }
    
    void test_method_(read_line_with_one_char_string) {
      assert::are_equal("a", string_reader("a").read_line());
    }
    
    void test_method_(read_to_end_with_one_char_string) {
      assert::are_equal("a", string_reader("a").read_to_end());
    }
    
    void test_method_(peek_with_multi_char_string) {
      assert::are_equal('a', string_reader("abcdefghijklmno").peek());
    }
    
    void test_method_(read_with_multi_char_string) {
      assert::are_equal('a', string_reader("abcdefghijklmno").read());
    }
    
    void test_method_(read_buffer_with_multi_char_string) {
      std::vector<char> buffer(10);
      assert::are_equal(10u, string_reader("abcdefghijklmno").text_reader::read(buffer, 0, 10));
      collection_assert::are_equal({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, buffer);
    }
    
    void test_method_(read_block_with_multi_char_string) {
      std::vector<char> buffer(10);
      assert::are_equal(10u, string_reader("abcdefghijklmno").text_reader::read_block(buffer, 0, 10));
      collection_assert::are_equal({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, buffer);
    }
    
    void test_method_(read_line_with_multi_char_string) {
      assert::are_equal("abcdefghijklmno", string_reader("abcdefghijklmno").read_line());
    }
    
    void test_method_(read_to_end_with_multi_char_string) {
      assert::are_equal("abcdefghijklmno", string_reader("abcdefghijklmno").read_to_end());
    }
    
    void test_method_(peek_with_multi_line_string) {
      assert::are_equal('L', string_reader("Line 1\nLine 2\nLine 3").peek());
    }
    
    void test_method_(read_with_multi_line_string) {
      assert::are_equal('L', string_reader("Line 1\nLine 2\nLine 3").read());
    }
    
    void test_method_(read_buffer_with_multi_line_string) {
      std::vector<char> buffer(10);
      assert::are_equal(10u, string_reader("Line 1\nLine 2\nLine 3").text_reader::read(buffer, 0, 10));
      collection_assert::are_equal({'L', 'i', 'n', 'e', ' ', '1', '\n', 'L', 'i', 'n'}, buffer);
    }
    
    void test_method_(read_block_with_multi_line_string) {
      std::vector<char> buffer(10);
      assert::are_equal(10u, string_reader("Line 1\nLine 2\nLine 3").text_reader::read_block(buffer, 0, 10));
      collection_assert::are_equal({'L', 'i', 'n', 'e', ' ', '1', '\n', 'L', 'i', 'n'}, buffer);
    }
    
    void test_method_(read_line_with_multi_line_string) {
      assert::are_equal("Line 1", string_reader("Line 1\nLine 2\nLine 3").read_line());
    }
    
    void test_method_(read_to_end_with_multi_line_string) {
      assert::are_equal("Line 1\nLine 2\nLine 3", string_reader("Line 1\nLine 2\nLine 3").read_to_end());
    }
    
    void test_method_(peek_and_read) {
      string_reader sr("abcde");
      assert::are_equal('a', sr.peek());
      assert::are_equal('a', sr.read());
      assert::are_equal('b', sr.read());
      assert::are_equal('c', sr.peek());
      assert::are_equal('c', sr.read());
      assert::are_equal('d', sr.read());
      assert::are_equal('e', sr.read());
      assert::are_equal(EOF, sr.peek());
      assert::are_equal(EOF, sr.read());
    }
    
    void test_method_(read_line) {
      string_reader sr("Line 1\nLine 2\nLine 3");
      assert::are_equal("Line 1", sr.read_line());
      assert::are_equal("Line 2", sr.read_line());
      assert::are_equal("Line 3", sr.read_line());
      assert::is_empty(sr.read_line());
    }
    
    void test_method_(read_to_end) {
      string_reader sr("Line 1\nLine 2\nLine 3");
      assert::are_equal("Line 1\nLine 2\nLine 3", sr.read_to_end());
      assert::is_empty(sr.read_to_end());
    }
    
    void test_method_(read_and_read_to_end) {
      string_reader sr("Line 1\nLine 2\nLine 3");
      assert::are_equal('L', sr.read());
      assert::are_equal('i', sr.read());
      assert::are_equal("ne 1\nLine 2\nLine 3", sr.read_to_end());
      assert::are_equal(EOF, sr.read());
    }
    
  };
}
