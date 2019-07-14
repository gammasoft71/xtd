#include <sstream>
#include <xtd/diagnostics/trace_listener.hpp>
#include <xtd/xtd.tunit>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_trace_listener) {
    class trace_listener_test_implementation : public trace_listener {
    public:
      std::string result() const {return this->string_stream.str();}
      
      void close() override {}
      
      void flush() override {}
      
      void write(const std::string& message) override {this->string_stream << message;}

      void write_line(const std::string& message) override {this->string_stream << message << std::endl;}
      
      using trace_listener::need_indent;

    private:
      std::stringstream string_stream;
    };
    
  public:
    void test_method_(new_trace_listener) {
      trace_listener_test_implementation trace_listener;
      assert::are_equal_(0, trace_listener.indent_level());
      assert::are_equal_(4, trace_listener.indent_size());
      assert::is_false_(trace_listener.is_thread_safe());
      assert::is_empty_(trace_listener.name());
      assert::is_true_(trace_listener.need_indent());
      
      assert::is_empty(trace_listener.result());
    }

    void test_method_(fail_message) {
      trace_listener_test_implementation trace_listener;
      assert::does_not_throw_([&]{trace_listener.fail("invalid_argument");});
      
      assert::are_equal_("Fail: invalid_argument\n", trace_listener.result());
    }

    void test_method_(fail_detail_message) {
      trace_listener_test_implementation trace_listener;
      assert::does_not_throw_([&]{trace_listener.fail("invalid_argument", "Pointer is null");});
      
      assert::are_equal_("Fail: invalid_argument Pointer is null\n", trace_listener.result());
    }
  };
}
