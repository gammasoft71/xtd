#include <xtd/io/stream_writer>
#include <xtd/io/stream_reader>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(stream_writer_tests) {
    void test_method_(create_stream_writer_from_stringstream) {
      array data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      std::stringstream s;
      
      stream_writer sw(s);
      for (auto i : data)
        sw.write(i);
        
      stream_reader sr(s);
      size_t index = 0;
      for (auto value = sr.read(); value != EOF; value = sr.read())
        assert::are_equal(data[index++], string::parse<int32>(string(static_cast<char>(value), 1)));
      assert::are_equal(10u, index);
    }
    
    void test_method_(create_stream_writer_from_stringstream_without_append) {
      array data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      std::stringstream s("abc");
      
      stream_writer sw(s);
      for (auto i : data)
        sw.write(i);
        
      stream_reader sr(s);
      size_t index = 0;
      for (auto value = sr.read(); value != EOF; value = sr.read())
        assert::are_equal(data[index++], string::parse<int32>(string(static_cast<char>(value), 1)));
      assert::are_equal(10u, index);
    }
    
    void test_method_(create_stream_writer_from_stringstream_with_append) {
      array data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      std::stringstream s("abc");
      
      stream_writer sw(s, true);
      for (auto i : data)
        sw.write(i);
        
      stream_reader sr(s);
      assert::are_equal('a', sr.read());
      assert::are_equal('b', sr.read());
      assert::are_equal('c', sr.read());
      size_t index = 0;
      for (auto value = sr.read(); value != EOF; value = sr.read())
        assert::are_equal(data[index++], string::parse<int32>(string(static_cast<char>(value), 1)));
      assert::are_equal(10u, index);
    }
  };
}
