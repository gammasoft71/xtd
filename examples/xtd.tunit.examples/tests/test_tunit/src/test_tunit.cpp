#define __XTD_EXPERIMENTAL_GTEST_HELPERS__
#include <xtd/gtest>

#define ASSERT_TRUE2(condition) \
struct __TESTER__##__LINE__ { \
  ~__TESTER__##__LINE__() {xtd::tunit::assume::is_true(condition, message_);} \
  __TESTER__##__LINE__& operator <<(const xtd::string& message) {message_ = message; return *this;} \
  xtd::string message_; \
} __tester__##__LINE__; __tester__##__LINE__

namespace namespace1 {
  
  TEST(class1, method1) {ASSERT_TRUE2(true);}
  TEST(class1, DISABLED_method2) {ASSERT_TRUE2(true);}
  TEST(class1, method3) {//ASSERT_TRUE2(false) << "Invalid value";
    struct __TESTER__ {
      ~__TESTER__() {xtd::tunit::assume::is_true(false, message_);}
      __TESTER__& operator <<(const xtd::string& message) {message_ = message; return *this;}
      xtd::string message_;
    } __tester__;
    __tester__ << "Invalid value";
  }
  
  TEST(class2, method1) {ASSERT_TRUE2(true);}
  TEST(class2, method2) {ASSERT_TRUE2(true);}
}

auto main() -> int {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
