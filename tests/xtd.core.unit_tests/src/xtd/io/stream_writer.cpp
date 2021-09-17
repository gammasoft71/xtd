#include <xtd/io/stream_writer.h>
#include <xtd/io/stream_reader.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_stream_writer) {
  public:
    void test_method_(create_stream_writer_from_stringstream) {
      vector data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      std::stringstream s;
      
      stream_writer sw(s);
      for (auto i : data)
        sw.write(i);
      
      stream_reader sr(s);
      size_t index = 0;
      for (auto value = sr.read(); value != EOF; value = sr.read())
        assert::are_equal(data[index++], ustring::parse<int32_t>(ustring(1, static_cast<char>(value))), csf_);
      assert::are_equal(10U, index, csf_);
    }

    void test_method_(create_stream_writer_from_stringstream_without_append) {
      vector data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      std::stringstream s("abc");
      
      stream_writer sw(s);
      for (auto i : data)
        sw.write(i);
      
      stream_reader sr(s);
      size_t index = 0;
      for (auto value = sr.read(); value != EOF; value = sr.read())
        assert::are_equal(data[index++], ustring::parse<int32_t>(ustring(1, static_cast<char>(value))), csf_);
      assert::are_equal(10U, index, csf_);
    }

    void test_method_(create_stream_writer_from_stringstream_with_append) {
      vector data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      std::stringstream s("abc");
      
      stream_writer sw(s, true);
      for (auto i : data)
        sw.write(i);
      
      stream_reader sr(s);
      assert::are_equal('a', sr.read(), csf_);
      assert::are_equal('b', sr.read(), csf_);
      assert::are_equal('c', sr.read(), csf_);
      size_t index = 0;
      for (auto value = sr.read(); value != EOF; value = sr.read())
        assert::are_equal(data[index++], ustring::parse<int32_t>(ustring(1, static_cast<char>(value))), csf_);
      assert::are_equal(10U, index, csf_);
    }
  };
}
