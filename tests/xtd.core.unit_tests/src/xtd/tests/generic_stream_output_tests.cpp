#include <xtd/console>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(generic_stream_output_tests) {
    struct console_output {
      explicit console_output(const std::stringstream& out) {console::set_out(out);}
      ~console_output() {console::set_out(console::open_standard_output());}
    };
    
    void test_method_(write_array) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::array<std::string, 3> {"One", "Two", "Three"});
      assert::are_equal("[One, Two, Three]", result.str());
    }
    
    void test_method_(write_bool_true) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(true);
      assert::are_equal("true", result.str());
    }
    
    void test_method_(write_bool_false) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(false);
      assert::are_equal("false", result.str());
    }
    
    /// @todo Does not work on linux with tunit but it's correct with xtd.core...
    /// Mismatch with ostream operator << between xtd.core and xtd.tunit
    /// To debug when integration of xtd.core in xtd.tunit will done.
    /*
    void test_method_(write_invalid_argument) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::invalid_argument("Invalid format"));
      std::cout << result.str() << std::endl;
      assert::are_equal("exception: Invalid format", result.str());
    }*/
    
    void test_method_(write_deque) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::deque<std::string> {"One", "Two", "Three"});
      assert::are_equal("[One, Two, Three]", result.str());
    }
    
    void test_method_(write_duration) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::chrono::hours(3) + std::chrono::minutes(32) + std::chrono::seconds(24) + std::chrono::nanoseconds(54300));
      assert::are_equal("03:32:24:000054300", result.str());
    }
    
    void test_method_(write_forward_list) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::forward_list<std::string> {"One", "Two", "Three"});
      assert::are_equal("[One, Two, Three]", result.str());
    }
    
    void test_method_(write_initializer_list) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write({"One", "Two", "Three"});
      assert::are_equal("[One, Two, Three]", result.str());
    }
    
    void test_method_(write_list) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::list<std::string> {"One", "Two", "Three"});
      assert::are_equal("[One, Two, Three]", result.str());
    }
    
    void test_method_(write_map) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::map<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      assert::are_equal("{(One, 1), (Three, 3), (Two, 2)}", result.str());
    }
    
    void test_method_(write_multimap) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::multimap<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      assert::are_equal("{(One, 1), (Three, 3), (Two, 2)}", result.str());
    }
    
    void test_method_(write_multiset) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::multiset<std::string> {"One", "Two", "Three"});
      assert::are_equal("{One, Three, Two}", result.str());
    }
    
    void test_method_(write_optional_without_value) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::optional<int>());
      assert::are_equal("(null)", result.str());
    }
    
    void test_method_(write_optional_with_value) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::optional<int>(42));
      assert::are_equal("(42)", result.str());
    }
    
    void test_method_(write_pair) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::make_pair("One", 2));
      assert::are_equal("(One, 2)", result.str());
    }
    
    void test_method_(write_set) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::set<std::string> {"One", "Two", "Three"});
      assert::are_equal("{One, Three, Two}", result.str());
    }
    
    void test_method_(write_tuple) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::make_tuple("One", 2, 3.0));
      assert::are_equal("(One, 2, 3)", result.str());
    }
    
    void test_method_(write_unordered_map) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::unordered_map<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      //result.str() can be equal to : "{(One, 1), (Two, 2), (Three, 3)}" or other sort depend of std::hash...
      string_assert::contains("(One, 1)", result.str());
      string_assert::contains("(Two, 2)", result.str());
      string_assert::contains("(Three, 3)", result.str());
    }
    
    void test_method_(write_unordered_multimap) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::unordered_multimap<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      //result.str() can be equal to : "{(One, 1), (Two, 2), (Three, 3)}" or other sort depend of std::hash...
      string_assert::contains("(One, 1)", result.str());
      string_assert::contains("(Two, 2)", result.str());
      string_assert::contains("(Three, 3)", result.str());
    }
    
    void test_method_(write_unordered_multiset) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::unordered_multiset<std::string> {"One", "Two", "Three"});
      string_assert::contains("One", result.str());
      string_assert::contains("Two", result.str());
      string_assert::contains("Three", result.str());
    }
    
    void test_method_(write_unordered_set) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::unordered_set<std::string> {"One", "Two", "Three"});
      string_assert::contains("One", result.str());
      string_assert::contains("Two", result.str());
      string_assert::contains("Three", result.str());
    }
    
    void test_method_(write_valarray) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::valarray<int> {1, 2, 3});
      assert::are_equal("[1, 2, 3]", result.str());
    }
    
    void test_method_(write_vector) {
      auto result = std::stringstream {};
      auto co = console_output {result};
      console::write(std::vector<int> {1, 2, 3});
      assert::are_equal("[1, 2, 3]", result.str());
    }
  };
}
