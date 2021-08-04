#include <xtd/diagnostics/trace_listener.h>
#include <xtd/xtd.tunit>
#include <sstream>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_trace_listener) {
    class unit_test_trace_listener : public trace_listener {
    public:
      unit_test_trace_listener() = default;
      xtd::ustring result() const {return string_stream.str();}
      
      void close() override {}
      void flush() override {}
      
      using trace_listener::write;
      void write(const xtd::ustring& message) override {
        if (need_indent())
          write_indent();
        string_stream << message;
      }

      using trace_listener::write_line;
      void write_line(const xtd::ustring& message) override {
        write(message);
        string_stream << std::endl;
        need_indent(true);
      }
      
      using trace_listener::need_indent;

    private:
      std::stringstream string_stream;
    };
    
  public:
    void test_method_(new_trace_listener) {
      unit_test_trace_listener trace_listener;
      assert::are_equal_(0U, trace_listener.indent_level());
      assert::are_equal_(4U, trace_listener.indent_size());
      assert::is_false_(trace_listener.is_thread_safe());
      assert::is_empty_(trace_listener.name());
      assert::is_true_(trace_listener.need_indent());
      assert::are_equal_(trace_options::none, trace_listener.trace_output_options());
      assert::is_empty(trace_listener.result());
    }
    
    void test_method_(indent_level) {
      unit_test_trace_listener trace_listener;
      trace_listener.indent_level(5);
      assert::are_equal_(5U, trace_listener.indent_level());
    }
    
    void test_method_(indent_size) {
      unit_test_trace_listener trace_listener;
      trace_listener.indent_size(8);
      assert::are_equal_(8U, trace_listener.indent_size());
    }
    
    void test_method_(name) {
      unit_test_trace_listener trace_listener;
      trace_listener.name("test_omplementation");
      assert::are_equal_("test_omplementation", trace_listener.name());
    }
    
    void test_method_(need_indent) {
      unit_test_trace_listener trace_listener;
      trace_listener.need_indent(false);
      assert::is_false_(trace_listener.need_indent());
    }
    
    void test_method_(trace_output_options) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_output_options(trace_options::process_id | trace_options::callstack);
      assert::are_equal_(trace_options::process_id | trace_options::callstack, trace_listener.trace_output_options());
    }

    void test_method_(fail_message) {
      unit_test_trace_listener trace_listener;
      trace_listener.fail("invalid_argument");
      assert::are_equal_("Fail: invalid_argument\n", trace_listener.result());
    }

    void test_method_(fail_detail_message) {
      unit_test_trace_listener trace_listener;
      trace_listener.fail("invalid_argument", "Pointer is null");
      assert::are_equal_("Fail: invalid_argument Pointer is null\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_string) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "information");
      assert::are_equal_("source error: 1 : information\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_int) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, 42);
      assert::are_equal_("source error: 1 : 42\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_string_aarray) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, std::vector<xtd::ustring> {"one", "two"});
      assert::are_equal_("source error: 1 : one, two\n", trace_listener.result());
    }
    
    void test_method_(trace_data_with_string_args) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_data(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "one", "two");
      assert::are_equal_("source error: 1 : one, two\n", trace_listener.result());
    }
    
    void test_method_(trace_event) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_event(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1);
      assert::are_equal_("source error: 1\n", trace_listener.result());
    }
    
    void test_method_(trace_event_with_string) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_event(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "information");
      assert::are_equal_("source error: 1 : information\n", trace_listener.result());
    }
    
    void test_method_(trace_event_with_format) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_event(xtd::diagnostics::trace_event_cache(), "source", xtd::diagnostics::trace_event_type::error, 1, "informations {}, {}", 42, "84");
      assert::are_equal_("source error: 1 : informations 42, 84\n", trace_listener.result());
    }
    
    void test_method_(trace_transfert) {
      unit_test_trace_listener trace_listener;
      trace_listener.trace_transfer(xtd::diagnostics::trace_event_cache(), "source", 1, "message", "10203040-5060-7080-90a0-b0c0d0e0f001");
      assert::are_equal_("source transfert: 1 : message, related_activity_id=10203040-5060-7080-90a0-b0c0d0e0f001\n", trace_listener.result());
    }
    
    void test_method_(write_string) {
      unit_test_trace_listener trace_listener;
      trace_listener.write("string");
      assert::are_equal_("string", trace_listener.result());
    }
    
    void test_method_(write_int) {
      unit_test_trace_listener trace_listener;
      trace_listener.write(42);
      assert::are_equal_("42", trace_listener.result());
    }
    
    void test_method_(write_line_string) {
      unit_test_trace_listener trace_listener;
      trace_listener.write_line("string");
      assert::are_equal_("string\n", trace_listener.result());
    }
    
    void test_method_(write_line_int) {
      unit_test_trace_listener trace_listener;
      trace_listener.write_line(42);
      assert::are_equal_("42\n", trace_listener.result());
    }
    
    void test_method_(write_stream_string) {
      unit_test_trace_listener trace_listener;
      trace_listener << "string";
      assert::are_equal_("string\n", trace_listener.result());
    }
    
    void test_method_(write_stream_int) {
      unit_test_trace_listener trace_listener;
      trace_listener << 42;
      assert::are_equal_("42\n", trace_listener.result());
    }
    
    void test_method_(write_string_with_one_indent_level) {
      unit_test_trace_listener trace_listener;
      trace_listener.indent_level(1);
      trace_listener << "string";
      assert::are_equal_("    string\n", trace_listener.result());
    }
    
    void test_method_(write_string_with_two_indent_level) {
      unit_test_trace_listener trace_listener;
      trace_listener.indent_size(8);
      trace_listener.indent_level(2);
      trace_listener << "string";
      assert::are_equal_("                string\n", trace_listener.result());
    }
  };
}
