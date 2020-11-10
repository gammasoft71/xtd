#include <xtd/xtd.delegates>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test_delegate) {
  public:
    void test_method_(create_empty_delegate_and_test_is_empty) {
      delegate<void()> d;
      assert::is_true(d.is_empty());
    }

    void test_method_(create_empty_delegate_and_invoke_it) {
      delegate<void()> d;
      assert::does_not_throw_([&] {d.invoke();});
    }

    void test_method_(create_empty_delegate_and_invoke_it_with_functor) {
      delegate<void()> d;
      assert::does_not_throw_([&] {d();});
    }

    static string static_method1() {
      return "static_method1";
    }
    
    void test_method_(create_delegate_with_static_method_and_test_is_empty) {
      delegate<string()> d(static_method1);
      assert::is_false(d.is_empty());
    }
    
    void test_method_(create_delegate_with_static_method_and_invoke_it) {
      delegate<string()> d(static_method1);
      assert::are_equal("static_method1", d.invoke());
    }
    
    void test_method_(create_delegate_with_static_method_and_invoke_it_with_functor) {
      delegate<string()> d(static_method1);
      assert::are_equal("static_method1", d());
    }
    
    class container {
    public:
      string member_method1() {
        return "member_method1";
      }
      
      string operator()() {
        return "functor_method1";
      }
    };
    
    void test_method_(create_delegate_with_member_method_and_test_is_empty) {
      container c;
      delegate<string()> d = {c, &container::member_method1};
      assert::is_false(d.is_empty());
    }
    
    void test_method_(create_delegate_with_member_method_and_invoke_it) {
      container c;
      delegate<string()> d = {c, &container::member_method1};
      assert::are_equal("member_method1", d.invoke());
    }
    
    void test_method_(create_delegate_with_member_method_and_invoke_it_with_functor) {
      container c;
      delegate<string()> d = {c, &container::member_method1};
      assert::are_equal("member_method1", d());
    }
    
    void test_method_(create_delegate_with_functor_method_and_test_is_empty) {
      container c;
      delegate<string()> d(c);
      assert::is_false(d.is_empty());
    }
    
    void test_method_(create_delegate_with_functor_method_and_invoke_it) {
      container c;
      delegate<string()> d(c);
      assert::are_equal("functor_method1", d.invoke());
    }
    
    void test_method_(create_delegate_with_functor_method_and_invoke_it_with_functor) {
      container c;
      delegate<string()> delegate(c);
      assert::are_equal("functor_method1", delegate());
    }
    
    void test_method_(create_delegate_with_lambda_expression_and_test_is_empty) {
      delegate<string()> d([]()->string {return "lambda_expression1";});
      assert::is_false(d.is_empty());
    }
    
    void test_method_(create_delegate_with_lambda_expression_and_invoke_it) {
      delegate<string()> d([]()->string {return "lambda_expression1";});
      assert::are_equal("lambda_expression1", d.invoke());
    }
    
    void test_method_(create_delegate_with_lambda_expression_and_invoke_it_with_functor) {
      delegate<string()> d([]()->string {return "lambda_expression1";});
      assert::are_equal("lambda_expression1", d());
    }
  };
}
