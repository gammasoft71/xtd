#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

class my_object {
public:
  my_object() = default;
  my_object(const my_object&) = default;
  my_object(int a, int b) : value_a_(a), value_b_(b) {}
  
  int value_a() const {return this->value_a_;}
  int value_b() const {return this->value_b_;}
  
  template<typename Char>
  friend std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, const my_object& value) {
    os << Char('[');
    os << value.value_a();
    os << Char(' ');
    os << value.value_b();
    os << Char(']');
    return os;
  }
  
private:
  int value_a_ = 0;
  int value_b_ = 0;
};

namespace xtd {
  template<>
  std::string to_string(const my_object& value, const std::string& fmt, const std::locale& loc) {
    if (fmt.size() > 1) throw std::invalid_argument("Format can contains only one character.");
    std::stringstream ss;
    ss << "[";
    ss << value.value_a();
    ss << fmt[0];
    ss << value.value_b();
    ss << "]";
    return ss.str();
  }
}

namespace unit_tests {
  class test_class_(test_string_object_format) {
  public:
    void test_method_(format_my_object_with_default_argument) {
      assert::are_equal("[42 24]", xtd::strings::format("{0}", my_object(42, 24)));
    }
    
    void test_method_(format_my_object_with_left_alignment) {
      assert::are_equal("   [42 24]", strings::format("{0,10}", my_object(42, 24)));
    }
    
    void test_method_(format_my_object_with_right_alignment) {
      assert::are_equal("[42 24]   ", strings::format("{0, -10}", my_object(42, 24)));
    }
    
    void test_method_(format_my_object_with_zero_alignment) {
      assert::are_equal("[42 24]", strings::format("{0,0}", my_object(42, 24)));
    }
    
    void test_method_(format_my_object_with_one_character_argument) {
      assert::are_equal("[42,24]", xtd::strings::format("{0:,}", my_object(42, 24)));
    }
    
    void test_method_(format_my_object_with_invalid_argument) {
      assert::throws<std::invalid_argument>([]{xtd::strings::format("{0:, }", my_object(42, 24));});
    }
  };
}
