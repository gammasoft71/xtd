#include <xtd/tunit>
#include <string>
#include <thread>
#include <tuple>
#include <regex>
#include <vector>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

#undef major
#undef minor

class version final {
public:
  version() = default;
  version(int major, int minor) : major_(major), minor_(minor) {}
  version(int major, int minor, int build) : major_(major), minor_(minor), build_(build) {}
  version(int major, int minor, int build, int revision) : major_(major), minor_(minor), build_(build), revision_(revision) {}
  version(const version&) = default;
  version& operator=(const version&) = default;
  
  bool operator==(const version& v) const {return this->major_ == v.major_ && this->minor_ == v.minor_ && this->build_ == v.build_ && this->revision_ == v.revision_;}
  bool operator!=(const version& v) const {return this->operator==(v);}
  
  int build() const {return this->build_;}
  int major() const {return this->major_;}
  int16_t major_revision() const {return (int16_t)((this->revision_ & 0xFFFF0000) >> 16);}
  int minor() const {return this->minor_;}
  int16_t mainor_revision() const {return (int16_t)(this->revision_ & 0x0000FFFF);}
  int revision() const {return this->revision_;}
  
  static version parse(const std::string& ver) {
    std::regex rgx("\\.");
    std::vector<std::string> versions;
    for (std::sregex_token_iterator it(ver.begin(), ver.end(), rgx, -1), end; it != end; ++it)
      versions.push_back(*it);
    
    switch (versions.size()) {
      case 2: return version(std::stoi(versions[0]), std::stoi(versions[1]));
      case 3: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]));
      case 4: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]), std::stoi(versions[3]));
    }
    throw std::invalid_argument("bad format");
  }
  
  static bool try_parse(const std::string& ver, version& result) {
    try {
      result = parse(ver);
      return true;
    } catch (...) {
      return false;
    }
  }
  
  std::string to_string() const {
    return this->to_string(2 + (this->build_ != -1 ? 1 : 0) + (this->revision_ != -1 ? 1 : 0));;
  }
  
  std::string to_string(size_t field_count) const {
    if (field_count > 4 || (field_count >= 3 && this->build_ == -1) || (field_count == 4 && this->revision_ == -1))
      throw std::invalid_argument("field_count invalid");
    std::stringstream result;
    if (field_count >= 1)
      result << std::to_string(this->major_);
    if (field_count >= 2)
      result << "." << std::to_string(this->minor_);
    if (field_count >= 3)
      result << "." << std::to_string(this->build_);
    if (field_count == 4)
      result << "." << std::to_string(this->revision_);
    return result.str();
  }
  
  friend std::ostream& operator <<(std::ostream& os, const version& ver) {
    return os << ver.to_string();
  }
  
private:
  int major_ = 0;
  int minor_ = 0;
  int build_ = -1;
  int revision_ = -1;
};

namespace xtd {
  namespace tunit {
    template<typename TValue1, typename TValue2>
    void that(const TValue1& value, void(*constraint)(const TValue1&, const TValue2&)) {
      constraint(value);
    }
    
    template<typename TValue>
    void that(TValue value, void(*constraint)(TValue)) {
      constraint(value);
    }
    
    template<typename TValue>
    void that(const TValue* value, void(*constraint)(const TValue*)) {
      constraint(value);
    }
    
    struct Is {
      template<typename TActual, typename TExpected>
      static void equal(const TExpected& expected, const TActual& actual) {
        assert::are_equal(expected, actual);
      }
      
      static void False(bool condition) {
        assert::is_false(condition);
      }
      
      template<typename TPointer>
      static void Null(const TPointer* pointer) {
        assert::is_null(pointer);
      }
      
      static void True(bool condition) {
        assert::is_true(condition);
      }
      
      struct Not {
        static void False(bool condition) {
          if (condition == !false)
            assert::succeed();
          else
            assert::fail("Expected: not false\nBut was:  false");
        }
        
        template<typename TPointer>
        static void Null(const TPointer* pointer) {
          assert::is_not_null(pointer);
        }

        static void True(bool condition) {
          if (condition == !true)
            assert::succeed();
          else
            assert::fail("Expected: not true\nBut was:  true");
        }
      };
    };
  }
}

template<typename TItem, typename TValue>
void contains(const TItem& item, const TValue& value) {
  try {
    xtd::tunit::assert::contains(item, value);
  } catch(const xtd::tunit::assert_error&) {
  }
}

namespace unit_tests {
  class test_class_(manual_test) {
  public:
    void test_method_(test_case1) {
      string_assert::matches("^Ola", "Hello, World!");
    }
    
    void test_method_(test_case2) {
      std::this_thread::sleep_for(chrono::milliseconds(1));
      //assert::are_equal(12, 42);
    }
    
    void test_method_(test_case3) {
      std::this_thread::sleep_for(chrono::milliseconds(2));
    }
  };

  class test_class_(manual_test2) {
  public:
    void test_method_(test_case1) {
      std::this_thread::sleep_for(chrono::milliseconds(1));
    }
    void test_method_(test_case2) {
      std::this_thread::sleep_for(chrono::milliseconds(2));
    }
    void ignore_test_method_(test_case3) {
      std::this_thread::sleep_for(chrono::milliseconds(1));
    }
    void test_method_(test_case4) {
      std::this_thread::sleep_for(chrono::milliseconds(1));
    }
  };
}

int main(int argc, char* argv[]) {
  settings::default_settings().output_xml(std::string(argv[0]) + ".xml");
  settings::default_settings().repeat_tests(-1);
  //settings::default_settings().list_tests(true);
  //settings::default_settings().also_run_ignored_tests(true);
  return console_unit_test(argv, argc).run();
}
