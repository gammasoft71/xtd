#include <xtd/delegate>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(delegate_tests) {
    class container {
    public:
      ustring member_method1() {
        return "member_method1";
      }
      void member_method2(ustring& result) {
        result += "member_method2;";
      }
      
      ustring operator()() {
        return "functor_method1";
      }
      void operator()(ustring& result) {
        result += "functor_method1;";
      }
    };
    
    static ustring static_method1() {
      return "static_method1";
    }
    
    static void static_method2(ustring & result) {
      result += "static_method2;";
    }
    
    void test_method_(create_empty_delegate_and_test_is_empty) {
      delegate<void()> d;
      assert::is_true(d.is_empty(), csf_);
    }
    
    void test_method_(create_empty_delegate_and_invoke_it) {
      delegate<void()> d;
      assert::does_not_throw([&] {d.invoke();}, csf_);
    }
    
    void test_method_(create_empty_delegate_and_invoke_it_with_functor) {
      delegate<void()> d;
      assert::does_not_throw([&] {d();}, csf_);
    }
    
    void test_method_(create_delegate_with_static_method_and_test_is_empty) {
      delegate<ustring()> d(static_method1);
      assert::is_false(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_static_method_and_invoke_it) {
      delegate<ustring()> d(static_method1);
      assert::are_equal("static_method1", d.invoke(), csf_);
    }
    
    void test_method_(create_delegate_with_static_method_and_invoke_it_with_functor) {
      delegate<ustring()> d(static_method1);
      assert::are_equal("static_method1", d(), csf_);
    }
    
    void test_method_(create_delegate_with_static_method_and_remove_it) {
      delegate<ustring()> d(static_method1);
      d = delegate<ustring()>::remove(d, {static_method1});
      assert::is_true(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_member_method_and_test_is_empty) {
      container c;
      delegate<ustring()> d = {c, &container::member_method1};
      assert::is_false(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_member_method_and_invoke_it) {
      container c;
      delegate<ustring()> d = {c, &container::member_method1};
      assert::are_equal("member_method1", d.invoke(), csf_);
    }
    
    void test_method_(create_delegate_with_member_method_and_remove_it) {
      container c;
      delegate<ustring()> d = {c, &container::member_method1};
      d = delegate<ustring()>::remove(d, {c, &container::member_method1});
      assert::is_true(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_member_method_and_invoke_it_with_functor) {
      container c;
      delegate<ustring()> d = {c, &container::member_method1};
      assert::are_equal("member_method1", d(), csf_);
    }
    
    void test_method_(create_delegate_with_functor_method_and_test_is_empty) {
      container c;
      delegate<ustring()> d(c);
      assert::is_false(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_functor_method_and_invoke_it) {
      container c;
      delegate<ustring()> d(c);
      assert::are_equal("functor_method1", d.invoke(), csf_);
    }
    
    void test_method_(create_delegate_with_functor_method_and_remove_it) {
      container c;
      delegate<ustring()> d(c);
      d = delegate<ustring()>::remove(d, {c});
      assert::is_true(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_functor_method_and_invoke_it_with_functor) {
      container c;
      delegate<ustring()> delegate(c);
      assert::are_equal("functor_method1", delegate(), csf_);
    }
    
    void test_method_(create_delegate_with_lambda_expression_and_test_is_empty) {
      delegate<ustring()> d([]()->ustring {return "lambda_expression1";});
      assert::is_false(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_lambda_expression_and_invoke_it) {
      delegate<ustring()> d([]()->ustring {return "lambda_expression1";});
      assert::are_equal("lambda_expression1", d.invoke(), csf_);
    }
    
    void test_method_(create_delegate_with_lambda_expression_and_remove_it) {
      auto l = []()->ustring {return "lambda_expression1";};
      delegate<ustring()> d(l);
      d = delegate<ustring()>::remove(d, {l});
      assert::is_true(d.is_empty(), csf_);
    }
    
    void test_method_(create_delegate_with_lambda_expression_and_invoke_it_with_functor) {
      delegate<ustring()> d([]()->ustring {return "lambda_expression1";});
      assert::are_equal("lambda_expression1", d(), csf_);
    }
    
    void test_method_(create_delegate_add_with_with_static_method_member_method_functor_method_lambda_expression_and_invoke_it) {
      container c;
      auto l = [](ustring & result) {result += "lambda_expression2;";};
      delegate<void(ustring&)> d;
      d += delegate<void(ustring&)> {static_method2};
      d += delegate<void(ustring&)> {c, &container::member_method2};
      d += delegate<void(ustring&)> {l};
      assert::are_equal(3_z, d.size());
      ustring result;
      d.invoke(result);
      assert::are_equal("static_method2;member_method2;lambda_expression2;", result, csf_);
    }
    
    void test_method_(create_delegate_add_with_with_static_method_member_method_functor_method_lambda_expression_and_invoke_it_with_functor) {
      container c;
      auto l = [](ustring & result) {result += "lambda_expression2;";};
      delegate<void(ustring&)> d;
      d += delegate<void(ustring&)> {static_method2};
      d += delegate<void(ustring&)> {c, &container::member_method2};
      d += delegate<void(ustring&)> {l};
      assert::are_equal(3_z, d.size());
      ustring result;
      d(result);
      assert::are_equal("static_method2;member_method2;lambda_expression2;", result, csf_);
    }
    
    void test_method_(create_delegate_add_with_with_static_method_member_method_functor_method_lambda_expression_and_remove_static_method) {
      container c;
      auto l = [](ustring & result) {result += "lambda_expression2;";};
      delegate<void(ustring&)> d;
      d += delegate<void(ustring&)> {static_method2};
      d += delegate<void(ustring&)> {c, &container::member_method2};
      d += delegate<void(ustring&)> {l};
    
      d = delegate<void(ustring&)>::remove(d, {static_method2});
      
      assert::are_equal(2_z, d.size());
      ustring result;
      d(result);
      assert::are_equal("member_method2;lambda_expression2;", result, csf_);
    }
    
    void test_method_(create_delegate_add_with_with_static_method_member_method_functor_method_lambda_expression_and_remove_member_method) {
      container c;
      auto l = [](ustring & result) {result += "lambda_expression2;";};
      delegate<void(ustring&)> d;
      d += delegate<void(ustring&)> {static_method2};
      d += delegate<void(ustring&)> {c, &container::member_method2};
      d += delegate<void(ustring&)> {l};
      
      d = delegate<void(ustring&)>::remove(d, {c, &container::member_method2});
      
      assert::are_equal(2_z, d.size());
      ustring result;
      d(result);
      assert::are_equal("static_method2;lambda_expression2;", result, csf_);
    }
    
    void test_method_(create_delegate_add_with_with_static_method_member_method_functor_method_lambda_expression_and_remove_lambda_expression) {
      container c;
      auto l = [](ustring & result) {result += "lambda_expression2;";};
      delegate<void(ustring&)> d;
      d += delegate<void(ustring&)> {static_method2};
      d += delegate<void(ustring&)> {c, &container::member_method2};
      d += delegate<void(ustring&)> {l};
      
      d = delegate<void(ustring&)>::remove(d, {l});
      
      assert::are_equal(2_z, d.size());
      ustring result;
      d(result);
      assert::are_equal("static_method2;member_method2;", result, csf_);
    }
    
    void test_method_(create_delegate_add_with_with_static_method_member_method_functor_method_lambda_expression_and_reset_it) {
      container c;
      auto l = [](ustring & result) {result += "lambda_expression2;";};
      delegate<void(ustring&)> d;
      d += delegate<void(ustring&)> {static_method2};
      d += delegate<void(ustring&)> {c, &container::member_method2};
      d += delegate<void(ustring&)> {l};
      
      d = delegate<void(ustring&)> {};
      assert::is_true(d.is_empty(), csf_);
    }
  };
}
