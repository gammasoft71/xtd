#include <xtd/console.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_generic_stream_output) {
  public:
    void test_method_(write_array) {
      stringstream result;
      console::set_out(result);
      console::write(std::array<std::string, 3> {"One", "Two", "Three"});
      assert::are_equal_("[One, Two, Three]", result.str());
    }
    
    void test_method_(write_bool_true) {
      stringstream result;
      console::set_out(result);
      console::write(true);
      assert::are_equal_("true", result.str());
    }
    
    void test_method_(write_bool_false) {
      stringstream result;
      console::set_out(result);
      console::write(false);
      assert::are_equal_("false", result.str());
    }
    
    /// @todo Does nott work on linux with tunit but it's correct with xtd.core...
    /// Mismatch with ostream operator << between xtd.core and xtd.tunit
    /// To debug when integration of xtd.core in xtd.tunit will done.
    /*
    void test_method_(write_invalid_argument) {
      stringstream result;
      console::set_out(result);
      console::write(std::invalid_argument("Invalid format"));
      std::cout << result.str() << std::endl;
      assert::are_equal_("exception: Invalid format", result.str());
    }*/

    void test_method_(write_deque) {
      stringstream result;
      console::set_out(result);
      console::write(std::deque<std::string> {"One", "Two", "Three"});
      assert::are_equal_("[One, Two, Three]", result.str());
    }

    void test_method_(write_duration) {
      stringstream result;
      console::set_out(result);
      console::write(std::chrono::hours(3) + std::chrono::minutes(32) + std::chrono::seconds(24) + std::chrono::nanoseconds(54300));
      assert::are_equal_("03:32:24:000054300", result.str());
    }

    void test_method_(write_forward_list) {
      stringstream result;
      console::set_out(result);
      console::write(std::forward_list<std::string> {"One", "Two", "Three"});
      assert::are_equal_("[One, Two, Three]", result.str());
    }

    void test_method_(write_initializer_list) {
      stringstream result;
      console::set_out(result);
      console::write({"One", "Two", "Three"});
      assert::are_equal_("[One, Two, Three]", result.str());
    }

    void test_method_(write_list) {
      stringstream result;
      console::set_out(result);
      console::write(std::list<std::string> {"One", "Two", "Three"});
      assert::are_equal_("[One, Two, Three]", result.str());
    }

    void test_method_(write_map) {
      stringstream result;
      console::set_out(result);
      console::write(std::map<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      assert::are_equal_("{(One, 1), (Three, 3), (Two, 2)}", result.str());
    }

    void test_method_(write_multimap) {
      stringstream result;
      console::set_out(result);
      console::write(std::multimap<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      assert::are_equal_("{(One, 1), (Three, 3), (Two, 2)}", result.str());
    }

    void test_method_(write_multiset) {
      stringstream result;
      console::set_out(result);
      console::write(std::multiset<std::string> {"One", "Two", "Three"});
      assert::are_equal_("{One, Three, Two}", result.str());
    }
    
    void test_method_(write_optional_without_value) {
      stringstream result;
      console::set_out(result);
      console::write(std::optional<int>());
      assert::are_equal_("(null)", result.str());
    }
    
    void test_method_(write_optional_with_value) {
      stringstream result;
      console::set_out(result);
      console::write(std::optional<int>(42));
      assert::are_equal_("(42)", result.str());
    }
    
    void test_method_(write_pair) {
      stringstream result;
      console::set_out(result);
      console::write(std::make_pair("One", 2));
      assert::are_equal_("(One, 2)", result.str());
    }

    void test_method_(write_set) {
      stringstream result;
      console::set_out(result);
      console::write(std::set<std::string> {"One", "Two", "Three"});
      assert::are_equal_("{One, Three, Two}", result.str());
    }

    void test_method_(write_tuple) {
      stringstream result;
      console::set_out(result);
      console::write(std::make_tuple("One", 2, 3.0));
      assert::are_equal_("(One, 2, 3)", result.str());
    }
    
    void test_method_(write_unordered_map) {
      stringstream result;
      console::set_out(result);
      console::write(std::unordered_map<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      //result.str() can be equal to : "{(One, 1), (Two, 2), (Three, 3)}" or other sort depend of std::hash...
      string_assert::contains("(One, 1)", result.str());
      string_assert::contains("(Two, 2)", result.str());
      string_assert::contains("(Three, 3)", result.str());
    }

    void test_method_(write_unordered_multimap) {
      stringstream result;
      console::set_out(result);
      console::write(std::unordered_multimap<std::string, int> {{"One", 1}, {"Two", 2}, {"Three", 3}});
      //result.str() can be equal to : "{(One, 1), (Two, 2), (Three, 3)}" or other sort depend of std::hash...
      string_assert::contains("(One, 1)", result.str());
      string_assert::contains("(Two, 2)", result.str());
      string_assert::contains("(Three, 3)", result.str());
    }

    void test_method_(write_unordered_multiset) {
      stringstream result;
      console::set_out(result);
      console::write(std::unordered_multiset<std::string> {"One", "Two", "Three"});
      string_assert::contains("One", result.str());
      string_assert::contains("Two", result.str());
      string_assert::contains("Three", result.str());
    }
    
    void test_method_(write_unordered_set) {
      stringstream result;
      console::set_out(result);
      console::write(std::unordered_set<std::string> {"One", "Two", "Three"});
      string_assert::contains("One", result.str());
      string_assert::contains("Two", result.str());
      string_assert::contains("Three", result.str());
    }
    
    void test_method_(write_valarray) {
      stringstream result;
      console::set_out(result);
      console::write(std::valarray<int> {1, 2, 3});
      assert::are_equal_("[1, 2, 3]", result.str());
    }
    
    void test_method_(write_vector) {
      stringstream result;
      console::set_out(result);
      console::write(std::vector<int> {1, 2, 3});
      assert::are_equal_("[1, 2, 3]", result.str());
    }
  };
}
