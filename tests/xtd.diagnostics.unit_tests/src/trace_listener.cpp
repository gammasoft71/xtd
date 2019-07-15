#include <xtd/diagnostics/trace_listener.hpp>
#include <xtd/xtd.tunit>
#include <sstream>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_trace_listener) {
    class trace_listener_test_implementation : public trace_listener {
    public:
      trace_listener_test_implementation() = default;
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
      assert::are_equal_(trace_options::none, trace_listener.trace_output_options());
      assert::is_empty(trace_listener.result());
    }
    
    void test_method_(indent_level) {
      trace_listener_test_implementation trace_listener;
      trace_listener.indent_level(5);
      assert::are_equal_(5, trace_listener.indent_level());
    }
    
    void test_method_(indent_size) {
      trace_listener_test_implementation trace_listener;
      trace_listener.indent_size(8);
      assert::are_equal_(8, trace_listener.indent_size());
    }
    
    void test_method_(name) {
      trace_listener_test_implementation trace_listener;
      trace_listener.name("test_omplementation");
      assert::are_equal_("test_omplementation", trace_listener.name());
    }
    
    void test_method_(need_indent) {
      trace_listener_test_implementation trace_listener;
      trace_listener.need_indent(false);
      assert::is_false_(trace_listener.need_indent());
    }
    
    void test_method_(trace_output_options) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_output_options(trace_options::process_id | trace_options::callstack);
      assert::are_equal_(trace_options::process_id | trace_options::callstack, trace_listener.trace_output_options());
    }

    void test_method_(fail_message) {
      trace_listener_test_implementation trace_listener;
      trace_listener.fail("invalid_argument");
      assert::are_equal_("Fail: invalid_argument\n", trace_listener.result());
    }

    void test_method_(fail_detail_message) {
      trace_listener_test_implementation trace_listener;
      trace_listener.fail("invalid_argument", "Pointer is null");
      assert::are_equal_("Fail: invalid_argument Pointer is null\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_string) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "information");
      assert::are_equal_("source error: 1 : information\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_int) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, 42);
      assert::are_equal_("source error: 1 : 42\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_string_aarray) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, std::vector<std::string> {"one", "two"});
      assert::are_equal_("source error: 1 : one, two\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_string_args) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "one", "two");
      assert::are_equal_("source error: 1 : one, two\n", trace_listener.result());
    }
    
    void test_method_(trace_event) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_event(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1);
      assert::are_equal_("source error: 1\n", trace_listener.result());
    }
    
    void test_method_(trace_event_with_string) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_event(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "information");
      assert::are_equal_("source error: 1 : information\n", trace_listener.result());
    }
    
    void test_method_(trace_event_with_format) {
      trace_listener_test_implementation trace_listener;
      trace_listener.trace_event(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "informations {}, {}", 42, "84");
      assert::are_equal_("source error: 1 : informations 42, 84\n", trace_listener.result());
    }
  };
}
