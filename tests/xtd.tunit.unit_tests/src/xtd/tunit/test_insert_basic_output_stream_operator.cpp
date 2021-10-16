#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <array>
#include <deque>
#include <exception>
#include <forward_list>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <optional>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace unit_tests {
  void test_(test_insert_basic_output_stream_operator, test_bool) {
    bool b = true;
    std::stringstream ss;
    ss << std::boolalpha << b;
    assert_value_("true", ss.str());
    ss.str("");
    ss << std::noboolalpha << b;
    assert_value_("1", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_int) {
    int i = 42;
    std::stringstream ss;
    ss << i;
    assert_value_("42", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_const_char_pointer) {
    const char* s = "42";
    std::stringstream ss;
    ss << s;
    assert_value_("42", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_string) {
    std::string s = "42";
    std::stringstream ss;
    ss << s;
    assert_value_("42", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_exception) {
    std::exception e;
    std::stringstream ss;
    ss << e;
    assert_value_(0U, ss.str().find("exception: "));
  }
  
  void test_(test_insert_basic_output_stream_operator, test_optional_without_value) {
    std::optional<int> o;
    std::stringstream ss;
    ss << o;
    assert_value_("(null)", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_optional_with_value) {
    std::optional<int> o = 42;
    std::stringstream ss;
    ss << o;
    assert_value_("(42)", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_pair) {
    auto p = std::make_pair("string", 42);
    std::stringstream ss;
    ss << p;
    assert_value_("(string, 42)", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_tuple) {
    auto t = std::make_tuple("string", 42);
    std::stringstream ss;
    ss << t;
    assert_value_("(string, 42)", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_array) {
    std::array<int, 4> a = {1, 2, 3, 4};
    std::stringstream ss;
    ss << a;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_array_with_const_char_pointer) {
    std::array<const char*, 4> a = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << a;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_array_with_string) {
    std::array<std::string, 4> a = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << a;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_deque) {
    std::deque d = {1, 2, 3, 4};
    std::stringstream ss;
    ss << d;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_deque_with_const_char_pointer) {
    std::deque d = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << d;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_deque_with_string) {
    std::deque<std::string> d = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << d;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_forward_list) {
    std::forward_list fl = {1, 2, 3, 4};
    std::stringstream ss;
    ss << fl;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_forward_list_with_const_char_pointer) {
    std::forward_list fl = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << fl;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_forward_list_with_string) {
    std::forward_list<std::string> fl = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << fl;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_List) {
    std::list l = {1, 2, 3, 4};
    std::stringstream ss;
    ss << l;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_list_with_const_char_pointer) {
    std::list l = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << l;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_list_with_string) {
    std::list<std::string> l = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << l;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_vector) {
    std::vector v = {1, 2, 3, 4};
    std::stringstream ss;
    ss << v;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_vector_with_const_char_pointer) {
    std::vector v = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << v;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_vector_with_string) {
    std::vector<std::string> v = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << v;
    assert_value_("[1, 2, 3, 4]", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_map) {
    std::map<int, int> m = {{1, 10}, {2, 20}, {3, 30}, {4, 40}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_map_with_const_char_pointer) {
    std::map<int, const char*> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_map_with_string) {
    std::map<int, std::string> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multimap) {
    std::multimap<int, int> m = {{1, 10}, {2, 20}, {3, 30}, {4, 40}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multimap_with_const_char_pointer) {
    std::multimap<int, const char*> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multimap_with_string) {
    std::multimap<int, std::string> m = {{1, "10"}, {2, "20"}, {3, "30"}, {4, "40"}};
    std::stringstream ss;
    ss << m;
    assert_value_("{(1, 10), (2, 20), (3, 30), (4, 40)}", ss.str());
  }

  void test_(test_insert_basic_output_stream_operator, test_multiset) {
    std::multiset<int> s = {1, 2, 3, 4};
    std::stringstream ss;
    ss << s;
    // Order is not guaranteed on every OS.
    //assert_value_("{1, 2, 3, 4}", ss.str());
    assert_value_('{', ss.str()[0]);
    assert_value_(',', ss.str()[2]);
    assert_value_(' ', ss.str()[3]);
    assert_value_(',', ss.str()[5]);
    assert_value_(' ', ss.str()[6]);
    assert_value_(',', ss.str()[8]);
    assert_value_(' ', ss.str()[9]);
    assert_value_('}', ss.str()[11]);
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multiset_with_const_char_pointer) {
    std::multiset<const char*> s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    // Order is not guaranteed on every OS.
    //assert_value_("{1, 2, 3, 4}", ss.str());
    assert_value_('{', ss.str()[0]);
    assert_value_(',', ss.str()[2]);
    assert_value_(' ', ss.str()[3]);
    assert_value_(',', ss.str()[5]);
    assert_value_(' ', ss.str()[6]);
    assert_value_(',', ss.str()[8]);
    assert_value_(' ', ss.str()[9]);
    assert_value_('}', ss.str()[11]);
  }
  
  void test_(test_insert_basic_output_stream_operator, test_multiset_with_string) {
    std::multiset<std::string> s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    // Order is not guaranteed on every OS.
    //assert_value_("{1, 2, 3, 4}", ss.str());
    assert_value_('{', ss.str()[0]);
    assert_value_(',', ss.str()[2]);
    assert_value_(' ', ss.str()[3]);
    assert_value_(',', ss.str()[5]);
    assert_value_(' ', ss.str()[6]);
    assert_value_(',', ss.str()[8]);
    assert_value_(' ', ss.str()[9]);
    assert_value_('}', ss.str()[11]);
  }

  void test_(test_insert_basic_output_stream_operator, test_set) {
    std::set s = {1, 2, 3, 4};
    std::stringstream ss;
    ss << s;
    // Order is not guaranteed on every OS.
    //assert_value_("{1, 2, 3, 4}", ss.str());
    assert_value_('{', ss.str()[0]);
    assert_value_(',', ss.str()[2]);
    assert_value_(' ', ss.str()[3]);
    assert_value_(',', ss.str()[5]);
    assert_value_(' ', ss.str()[6]);
    assert_value_(',', ss.str()[8]);
    assert_value_(' ', ss.str()[9]);
    assert_value_('}', ss.str()[11]);
  }
  
  void test_(test_insert_basic_output_stream_operator, test_set_with_const_char_pointer) {
    std::set s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    // Order is not guaranteed on every OS.
    //assert_value_("{1, 2, 3, 4}", ss.str());
    assert_value_('{', ss.str()[0]);
    assert_value_(',', ss.str()[2]);
    assert_value_(' ', ss.str()[3]);
    assert_value_(',', ss.str()[5]);
    assert_value_(' ', ss.str()[6]);
    assert_value_(',', ss.str()[8]);
    assert_value_(' ', ss.str()[9]);
    assert_value_('}', ss.str()[11]);
  }
  
  void test_(test_insert_basic_output_stream_operator, test_set_with_string) {
    std::set<std::string> s = {"1", "2", "3", "4"};
    std::stringstream ss;
    ss << s;
    // Order is not guaranteed on every OS.
    //assert_value_("{1, 2, 3, 4}", ss.str());
    assert_value_('{', ss.str()[0]);
    assert_value_(',', ss.str()[2]);
    assert_value_(' ', ss.str()[3]);
    assert_value_(',', ss.str()[5]);
    assert_value_(' ', ss.str()[6]);
    assert_value_(',', ss.str()[8]);
    assert_value_(' ', ss.str()[9]);
    assert_value_('}', ss.str()[11]);
  }
  
  class class_without_insert_stream_operator {
  public:
    class_without_insert_stream_operator() = default;
    explicit class_without_insert_stream_operator(int value) : value_(value) {}
    
    int value() const noexcept {return value_;}
    
  private:
    int value_ = 0;
  };
  
  void test_(test_insert_basic_output_stream_operator, test_class_without_insert_stream_operator) {
    class_without_insert_stream_operator c(42);
    std::stringstream ss;
    ss << c;
    assert_value_("4-byte object <2A-00 00-00>", ss.str());
  }
  
  class class_with_insert_stream_operator {
  public:
    class_with_insert_stream_operator() = default;
    explicit class_with_insert_stream_operator(int value) : value_(value) {}
    
    int value() const noexcept {return value_;}
    
    friend std::ostream& operator<<(std::ostream& os, const class_with_insert_stream_operator& c) {
      return os << "(value = " << c.value_ << ")";
    }
    
  private:
    int value_ = 0;
  };
  
  void test_(test_insert_basic_output_stream_operator, test_class_with_insert_stream_operator) {
    class_with_insert_stream_operator c(42);
    std::stringstream ss;
    ss << c;
    assert_value_("(value = 42)", ss.str());
  }
}
