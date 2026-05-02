/// @file
/// @brief Contains xtd::expressions::expression struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "operator_precedence.hpp"
#include "../type_of.hpp"
#include <concepts>
#include <ostream>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief Provides the base class from which the classes that represent expression tree nodes are derived. It also contains static factory methods to create the various node types. This is an abstract class.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/expression>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks The following tables show the expressions by type :
    /// @remarks
    ///   | Arithmetic                                                                        | operator            |
    ///   | --------------------------------------------------------------------------------- | ------------------- |
    ///   | xtd::expressions::expression::add                                                 | <code>a + b</code>  |
    ///   | xtd::expressions::expression::subtract                                            | <code>a - b</code>  |
    ///   | xtd::expressions::expression::unary_plus                                          | <code>+a</code>     |
    ///   | xtd::expressions::expression::unary_minus<br>xtd::expressions::expression::negate | <code>-a</code>     |
    ///   | xtd::expressions::expression::multiply                                            | <code>a * b</code>  |
    ///   | xtd::expressions::expression::divide                                              | <code>a / b</code>  |
    ///   | xtd::expressions::expression::modulo                                              | <code>a % b</code>  |
    /// @remarks
    ///   | Relational                                                                                 | operator             |
    ///   | ------------------------------------------------------------------------------------------ | -------------------- |
    ///   | xtd::expressions::expression::equal                                                        | <code>a == b</code>  |
    ///   | xtd::expressions::expression::not_equal                                                    | <code>a != b</code>  |
    ///   | xtd::expressions::expression::greater_than                                                 | <code>a > b</code>   |
    ///   | xtd::expressions::expression::less_than                                                    | <code>a < b</code>   |
    ///   | xtd::expressions::expression::greater_than_or_equal                                        | <code>a >= b</code>  |
    ///   | xtd::expressions::expression::less_than_or_equal                                           | <code>a <= b</code>  |
    ///   | xtd::expressions::expression::compare_three_way<br>xtd::expressions::expression::spaceship | <code>a <=> b</code> |
    /// @remarks
    ///   | Logical                                                                             | operator              |
    ///   | ----------------------------------------------------------------------------------- | --------------------- |
    ///   | xtd::expressions::expression::logical_not                                           | <code>!a</code>       |
    ///   | xtd::expressions::expression::logical_and<br>xtd::expressions::expression::and_also | <code>a && b</code>   |
    ///   | xtd::expressions::expression::logical_or<br>xtd::expressions::expression::or_else   | <code>a \|\| b</code> |
    /// @remarks
    ///   | Bitwise                                   | operator |
    ///   | ----------------------------------------- | ------------------- |
    ///   | xtd::expressions::expression::not         | <code>~a</code>     |
    ///   | xtd::expressions::expression::and_        | <code>a & b</code>  |
    ///   | xtd::expressions::expression::or_         | <code>a \| b</code> |
    ///   | xtd::expressions::expression::xor_        | <code>a ^ b</code>  |
    ///   | xtd::expressions::expression::left_shift  | <code>a << b</code> |
    ///   | xtd::expressions::expression::right_shift | <code>a >> b</code> |
    /// @remarks
    ///   | Member and pointer                        | operator |
    ///   | ----------------------------------------- | -------- |
    ///   | xtd::expressions::expression::member      |          |
    ///   | xtd::expressions::expression::method      |          |
    /// @remarks
    ///   | Conditional                                | operator               |
    ///   | ------------------------------------------ | ---------------------- |
    ///   | xtd::expressions::expression::if_then_else | <code>a ? b : c</code> |
    /// @remarks
    ///   | Others                                    | operator |
    ///   | ----------------------------------------- | -------- |
    ///   | xtd::expressions::expression::constant    |          |
    ///   | xtd::expressions::expression::arg         |          |
    ///   | xtd::expressions::expression::placeholder |          |
    /// @par Examples
    /// The following example shos how to use xtd::expressions::expression class.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// auto main() -> int {
    ///   auto value = 30;
    ///   // auto expr1 = [](auto&& _1, auto&& _2) {return (_1 + _2) * value;};
    ///   auto expr1 = (_1 + _2) * value;
    ///   println("expr1 resutl = {}", expr1(10, 20));
    ///   println("expr1 = {}", expr1);
    ///   println("type_of(expr1) = {}", type_of(expr1));
    ///
    ///   println();
    ///   auto expr2 = expression::multiply(expression::add(_1, _2), value);
    ///   println("expr2 resutl = {}", expr2(10, 20));
    ///   println("expr2 = {}", expr2);
    ///   println("type_of(expr2) = {}", type_of(expr2));
    /// }
    ///
    /// // This code produces the following output :
    /// //
    /// // expr1 resutl = 900
    /// // expr1 = (_1 + _2) * 30
    /// // type_of(expr1) = xtd::expressions::multiply_expression<xtd::expressions::add_expression<xtd::expressions::placeholder<1ul>, xtd::expressions::placeholder<2ul>>, xtd::expressions::constant<int>>
    /// //
    /// // expr2 resutl = 900
    /// // expr2 = (_1 + _2) * 30
    /// // type_of(expr2) = xtd::expressions::multiply_expression<xtd::expressions::add_expression<xtd::expressions::placeholder<1ul>, xtd::expressions::placeholder<2ul>>, xtd::expressions::constant<int>>
    /// ```
    struct expression {
      /// @name Public Static Methods
      
      /// @{
      /// @brief Add the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of add.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::add.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto add1 = [](auto&& _) {return _ + 10;};
      ///   auto add1 = _ + 10;
      ///   println("add1 result => {}", add1(40));
      ///   auto add2 = expression::add(_, 10);
      ///   println("add2 result => {}", add2(40));
      ///   println();
      ///   // auto add3 = [](auto&& _1, auto&& _2) {return _1 + _2;};
      ///   auto add3 = _1 + _2;
      ///   println("add3 result => {}", add3(40, 20));
      ///   auto add4 = expression::add(_1, _2);
      ///   println("add4 result => {}", add4(40, 20));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // add1 result => 50
      /// // add2 result => 50
      /// //
      /// // add3 result => 60
      /// // add4 result => 60
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto add(left_t left, right_t right);
      
      /// @brief Bitwise and the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of bitwise and.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::and_.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto and1 = [](auto&& _) {return _ & 0x0F;};
      ///   auto and1 = _ & 0x0F;
      ///   println("and1 result => {:B}", and1(42));
      ///   auto and2 = expression::and_(_, 0x0F);
      ///   println("and2 result => {:B}", and2(42));
      ///   println();
      ///   // auto and3 = [](auto&& _1, auto&& _2) {return _1 & _2;};
      ///   auto and3 = _1 & _2;
      ///   println("and3 result => {:B}", and3(42, 0xF0));
      ///   auto and4 = expression::and_(_1, _2);
      ///   println("and4 result => {:B}", and4(42, 0xF0));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // and1 result => 1010
      /// // and2 result => 1010
      /// //
      /// // and3 result => 100000
      /// // and4 result => 100000
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto and_(left_t left, right_t right);
      
      /// @brief Logical and the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of logical and.
      /// @remarks xtd::expressions::expression::and_also is an alias on xtd::expressions::expression::logical_and
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::and_also.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   auto value = true;
      ///   // auto and_also1 = [value](auto&& _) {return _ && value;};
      ///   auto and_also1 = _ && value;
      ///   println("and_also1 result => {}", and_also1(42 % 2 == 0));
      ///   auto and_also2 = expression::and_also(_, value);
      ///   println("and_also2 result => {}", and_also2(42 % 2 == 0));
      ///   println();
      ///   // auto and_also3 = [](auto&& _1, auto&& _2) {return _1 && _2;};
      ///   auto and_also3 = _1 && _2;
      ///   println("and_also3 result => {}", and_also3(42 % 2 == 0, 42 % 8 == 0));
      ///   auto and_also4 = expression::and_also(_1, _2);
      ///   println("and_also4 result => {}", and_also4(42 % 2 == 0, 42 % 8 == 0));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // and_also1 result => true
      /// // and_also2 result => true
      /// //
      /// // and_also3 result => false
      /// // and_also4 result => false
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto and_also(left_t left, right_t right);
      
      /// @brief Gets the `index` argument used by expression.
      /// @remarks The index start from 1 to N.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::arg.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto placeholder1 = [](auto&& _) {return _;};
      ///   auto arg1 = _;
      ///   println("arg1 result => {}", arg1(10));
      ///   auto arg2 = _1;
      ///   println("arg2 result => {}", arg2(10));
      ///   auto arg3 = arg<1> {};
      ///   println("arg3 result => {}", arg3(10));
      ///   auto arg4 = expression::arg<1>();
      ///   println("arg4 result => {}", arg4(10));
      ///   println();
      ///   // auto expr1 = [](auto&& _1, auto&& _2, auto&& _3) {return _1 + _2 + _3;};
      ///   auto expr1 = _1 + arg<2> + expression::arg<3>();
      ///   println("expr1 result => {}", expr1(10, 20, 30));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // arg1 result => 10
      /// // arg2 result => 10
      /// // arg3 result => 10
      /// // arg4 result => 10
      /// //
      /// // expr1 result => 60
      /// ```
      template <size_t index>
      static constexpr auto arg();
      
      /// @brief Compare three way the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of compare three way.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::compare_three_way.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto compare_three_way1 = [value](auto&& _) {return _ <=> 10;};
      ///   auto compare_three_way1 = _ <=> 10;
      ///   println("compare_three_way1 result => {}", compare_three_way1(42));
      ///   auto compare_three_way2 =  expression::compare_three_way(_, 10);
      ///   println("compare_three_way2 result => {}", compare_three_way2(42));
      ///   println();
      ///   //auto compare_three_way3 = [](auto&& _1, auto&& _2) {return _1 <=> _2;};
      ///   auto compare_three_way3 = _1 <=> _2;
      ///   println("compare_three_way3 result => {}", compare_three_way3(42, 42));
      ///   auto compare_three_way4 =  expression::compare_three_way(_1, _2);
      ///   println("compare_three_way4 result => {}", compare_three_way4(42, 42));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // compare_three_way1 result => greater
      /// // compare_three_way2 result => greater
      /// //
      /// // compare_three_way3 result => equivalent
      /// // compare_three_way4 result => equivalent
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto compare_three_way(left_t left, right_t right);
      
      /// @brief Gets the constant value.
      /// @param value The constnt value.
      /// @return The constant value expression.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::constant.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto constant1 = [] {return 10;};
      ///   auto constant1 =  constant {10};
      ///   println("constant1 result => {}", constant1());
      ///   auto constant2 =  expression::constant(10);
      ///   println("constant2 result => {}", constant2());
      ///   auto value = 30;
      ///   //auto constant3 = [value] {return value;};
      ///   auto constant3 =  constant {value};
      ///   println("constant3 result => {}", constant3());
      ///   auto constant4 =  expression::constant(value);
      ///   println("constant4 result => {}", constant4());
      ///   println();
      ///   //auto expr1 = [value] {return 20 + value;};
      ///   auto expr1 = constant {20} + expression::constant(value);
      ///   println("expr1 result => {}", expr1());
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // constant1 result => 10
      /// // constant2 result => 10
      /// // constant3 result => 30
      /// // constant4 result => 30
      /// //
      /// // expr1 result => 50
      /// ```
      template <typename type_t>
      static constexpr auto constant(type_t value);

      /// @brief Divide the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of devide.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::divide.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto divide1 = [](auto&& _) {return _ / 10;};
      ///   auto divide1 = _ / 10;
      ///   println("divide1 result => {}", divide1(50));
      ///   auto divide2 = expression::divide(_, 10);
      ///   println("divide2 result => {}", divide2(50));
      ///   println();
      ///   // auto divide3 = [](auto&& _1, auto&& _2) {return _1 / _2;};
      ///   auto divide3 = _1 / _2;
      ///   println("add3 result => {}", divide3(60, 15));
      ///   auto divide4 = expression::divide(_1, _2);
      ///   println("add4 result => {}", divide4(60, 15));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // divide1 result => 5
      /// // divide2 result => 5
      /// //
      /// // divide3 result => 4
      /// // divide4 result => 4
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto divide(left_t left, right_t right);
     
      /// @brief Equal the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of equal.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::equal.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto equal1 = [](auto&& _) {return _ == 10;};
      ///   auto equal1 = _ == 10;
      ///   println("equal1 result => {}", equal1(42));
      ///   auto equal2 = expression::equal(_, 10);
      ///   println("equal2 result => {}", equal2(42));
      ///   println();
      ///   // auto equal3 = [](auto&& _1, auto&& _2) {return _1 == _2;};
      ///   auto equal3 = _1 == _2;
      ///   println("equal3 result => {}", equal3(42, 42));
      ///   auto equal4 = expression::equal(_1, _2);
      ///   println("equal4 result => {}", equal4(42, 42));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // equal1 result => false
      /// // equal2 result => false
      /// //
      /// // equal3 result => true
      /// // equal4 result => true
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto equal(left_t left, right_t right);
      
      /// @brief Greater than the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of greater than.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::greater_than.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto greater_than1 = [](auto&& _) {return _ > 10;};
      ///   auto greater_than1 = _ > 10;
      ///   println("greater_than1 result => {}", greater_than1(42));
      ///   auto greater_than2 = expression::greater_than(_, 10);
      ///   println("greater_than2 result => {}", greater_than2(42));
      ///   println();
      ///   // auto greater_than3 = [](auto&& _1, auto&& _2) {return _1 > _2;};
      ///   auto greater_than3 = _1 > _2;
      ///   println("greater_than3 result => {}", greater_than3(42, 42));
      ///   auto greater_than4 = expression::greater_than(_1, _2);
      ///   println("greater_than4 result => {}", greater_than4(42, 42));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // greater_than1 result => true
      /// // greater_than2 result => true
      /// //
      /// // greater_than3 result => false
      /// // greater_than4 result => false
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto greater_than(left_t left, right_t right);
      
      /// @brief Greater than or equzl the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of greater than or equal.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::greater_than_or_equal.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto greater_than_or_equal1 = [](auto&& _) {return _ >= 10;};
      ///   auto greater_than_or_equal1 = _ > 10;
      ///   println("greater_than_or_equal1 result => {}", greater_than_or_equal1(42));
      ///   auto greater_than_or_equal2 = expression::greater_than_or_equal(_, 10);
      ///   println("greater_than_or_equal2 result => {}", greater_than2(42));
      ///   println();
      ///   // auto greater_than_or_equal3 = [](auto&& _1, auto&& _2) {return _1 >= _2;};
      ///   auto greater_than_or_equal3 = _1 > _2;
      ///   println("greater_than_or_equal3 result => {}", greater_than_or_equal2(32, 42));
      ///   auto greater_than_or_equal4 = expression::greater_than_or_equal(_1, _2);
      ///   println("greater_than_or_equal4 result => {}", greater_than_or_equal4(32, 42));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // greater_than_or_equal1 result => true
      /// // greater_than_or_equal2 result => true
      /// //
      /// // greater_than_or_equal3 result => false
      /// // greater_than_or_equal4 result => false
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto greater_than_or_equal(left_t left, right_t right);

      /// @brief Logical and the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of logical and.
      /// @remarks xtd::expressions::expression::and_also is an alias on xtd::expressions::expression::logical_and
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::logical_and.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   auto value = true;
      ///   // auto logical_and1 = [value](auto&& _) {return _ && value;};
      ///   auto logical_and1 = _ && value;
      ///   println("logical_and1 result => {}", logical_and1(42 % 2 == 0));
      ///   auto logical_and2 = expression::logical_and(_, value);
      ///   println("logical_and2 result => {}", logical_and2(42 % 2 == 0));
      ///   println();
      ///   // auto logical_and3 = [](auto&& _1, auto&& _2) {return _1 && _2;};
      ///   auto logical_and3 = _1 && _2;
      ///   println("and_also3 result => {}", logical_and3(42 % 2 == 0, 42 % 8 == 0));
      ///   auto logical_and4 = expression::logical_and(_1, _2);
      ///   println("logical_and4 result => {}", logical_and4(42 % 2 == 0, 42 % 8 == 0));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // logical_and1 result => true
      /// // logical_and2 result => true
      /// //
      /// // logical_and3 result => false
      /// // logical_and4 result => false
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto logical_and(left_t left, right_t right);

      /// @brief Left shift the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of left shift.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::left_shift.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto left_shift1 = [](auto&& _) {return _ << 2;};
      ///   auto left_shift1 = _ << 2;
      ///   println("left_shift1 result => {}", left_shift1(42));
      ///   auto left_shift2 = expression::left_shift(_, 2);
      ///   println("left_shift2 result => {}", left_shift2(42));
      ///   println();
      ///   // auto left_shift3 = [](auto&& _1, auto&& _2) {return _1 << _2;};
      ///   auto left_shift3 = _1 << _2;
      ///   println("left_shift3 result => {}", left_shift3(42, 4));
      ///   auto left_shift4 = expression::left_shift(_1, _2);
      ///   println("left_shift4 result => {}", left_shift4(42, 4));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // left_shift1 result => 168
      /// // left_shift2 result => 168
      /// //
      /// // left_shift3 result => 672
      /// // left_shift4 result => 672
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto left_shift(left_t left, right_t right);

      /// @brief Multiply the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of multiply.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::multiply.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto multiply1 = [](auto&& _) {return _ * 10;};
      ///   auto multiply1 = _ * 10;
      ///   println("multiply1 result => {}", multiply1(5));
      ///   auto multiply2 = expression::multiply(_, 10);
      ///   println("multiply2 result => {}", multiply2(5));
      ///   println();
      ///   // auto multiply3 = [](auto&& _1, auto&& _2) {return _1 * _2;};
      ///   auto multiply3 = _1 * _2;
      ///   println("multiply3 result => {}", multiply3(4, 15));
      ///   auto multiply4 = expression::multiply(_1, _2);
      ///   println("multiply4 result => {}", multiply4(4, 15));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // mul1 result => 50
      /// // mul2 result => 50
      /// //
      /// // mul3 result => 60
      /// // mul4 result => 60
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto multiply(left_t left, right_t right);
      
      /// @brief Gets the `index` placeholder used by expression.
      /// @remarks The index start from 1 to N.
      /// @remarks Prefer the xtd::expressions::expression::arg <N> or xtd::expressions::_, xtd::expressions::_1 ... xtd::expressions::_10 instead xtd::expressions::expression::placeholder.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::placeholder.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto placeholder1 = [](auto&& _) {return _;};
      ///   auto placeholder1 = _;
      ///   println("placeholder1 result => {}", placeholder1(10));
      ///   auto placeholder2 = _1;
      ///   println("placeholder2 result => {}", placeholder2(10));
      ///   auto placeholder3 = placeholder<1> {};
      ///   println("placeholder3 result => {}", placeholder3(10));
      ///   auto placeholder4 = expression::placeholder<1>();
      ///   println("placeholder4 result => {}", placeholder4(10));
      ///   println();
      ///   // auto expr1 = [](auto&& _1, auto&& _2, auto&& _3) {return _1 + _2 + _3;};
      ///   auto expr1 = _1 + placeholder<2> {} + expression::placeholder<3>();
      ///   println("expr1 result => {}", expr1(10, 20, 30));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // placeholder1 result => 10
      /// // placeholder2 result => 10
      /// // placeholder3 result => 10
      /// // placeholder4 result => 10
      /// //
      /// // expr1 result => 60
      /// ```
      template <size_t index>
      static constexpr auto placeholder();

      /// @brief Right shift the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of right shift.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::right_shift.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto right_shift1 = [](auto&& _) {return _ >> 2;};
      ///   auto right_shift1 = _ >> 2;
      ///   println("right_shift1 result => {}", right_shift1(42));
      ///   auto right_shift2 = expression::right_shift(_, 2);
      ///   println("right_shift2 result => {}", right_shift2(42));
      ///   println();
      ///   // auto right_shift3 = [](auto&& _1, auto&& _2) {return _1 >> _2;};
      ///   auto right_shift3 = _1 >> _2;
      ///   println("right_shift3 result => {}", right_shift3(42, 4));
      ///   auto right_shift4 = expression::right_shift(_1, _2);
      ///   println("right_shift4 result => {}", right_shift4(42, 4));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // right_shift1 result => 10
      /// // right_shift2 result => 10
      /// //
      /// // right_shift3 result => 2
      /// // right_shift4 result => 2
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto right_shift(left_t left, right_t right);

      /// @brief Compare three way the specified left and right operands.
      /// @param left The left operand.
      /// @param right The right operand.
      /// @return The result of compare three way.
      /// @par Examples
      /// The following example shows how to use xtd::expressions::expression::spaceship.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// auto main() -> int {
      ///   // auto cspaceship1 = [value](auto&& _) {return _ <=> 10;};
      ///   auto cspaceship1 = _ <=> 10;
      ///   println("spaceship1 result => {}", spaceship1(42));
      ///   auto spaceship2 =  expression::spaceship(_, 10);
      ///   println("spaceship2 result => {}", spaceship(42));
      ///   println();
      ///   //auto spaceship3 = [](auto&& _1, auto&& _2) {return _1 <=> _2;};
      ///   auto spaceship3 = _1 <=> _2;
      ///   println("spaceship3 result => {}", spaceship3(42, 42));
      ///   auto spaceship4 =  expression::spaceship(_1, _2);
      ///   println("spaceship4 result => {}", spaceship4(42, 42));
      /// }
      ///
      /// // This code produces the following output :
      /// //
      /// // spaceship1 result => greater
      /// // spaceship2 result => greater
      /// //
      /// // spaceship3 result => equivalent
      /// // spaceship4 result => equivalent
      /// ```
      template <typename left_t, typename right_t>
      requires std::is_base_of_v<expression, std::decay_t<left_t>> || std::is_base_of_v<expression, std::decay_t<right_t>>
      static constexpr auto spaceship(left_t left, right_t right);
      /// @}

    protected:
      /// @name Protected Constructors
      
      /// @{
      expression() = default;
      /// @}
    };
    
    /// @cond
    template<typename type_t>
    requires std::is_base_of_v<expression, std::decay_t<type_t>>
    auto operator <<(std::ostream& os, const type_t& e) -> std::ostream& {return os << type_of(e);}
    /// @endcond
  }
}

