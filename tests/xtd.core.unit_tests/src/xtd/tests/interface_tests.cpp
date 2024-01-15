#include <xtd/interface>
#include <xtd/ustring>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(interface_tests) {
    class iinterface_test interface_ {
    public:
      virtual int value() const noexcept = 0;
    };
    
    class interface_test : public iinterface_test {
    public:
      interface_test() = default;
      interface_test(interface_test&&) = default;
      interface_test(const interface_test&) = default;
      interface_test& operator =(const interface_test&) = default;
      interface_test(int value) : value_(value) {}
      
      int value() const noexcept override {return value_;}
      
    private:
      int value_ = 0;
    };
    
    void test_method_(interface_test_value) {
      interface_test it {42};
      assert::are_equal(42, it.value(), csf_);
      assert::are_equal(42, as<iinterface_test>(it).value(), csf_);
    }
    
    void test_method_(iinterface_test_value) {
      interface_test it {42};
      iinterface_test& iit = it;
      assert::are_equal(42, it.value(), csf_);
      assert::are_equal(42, iit.value(), csf_);
      assert::are_equal(42, as<interface_test>(iit).value(), csf_);
    }
    
    void test_method_(interface_value) {
      interface_test it {42};
      interface& i = it;
      assert::are_equal(42, it.value(), csf_);
      assert::are_equal(42, as<iinterface_test>(i).value(), csf_);
      assert::are_equal(42, as<interface_test>(i).value(), csf_);
    }
  };
}
