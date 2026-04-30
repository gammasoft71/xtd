/// @file
/// @brief Contains xtd::expressions::operator_precedence enum class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
//#include "../enum.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    /// @brief Specifies the operator precedence.
    /// @par Namespace
    /// xtd::expressions
    /// @par Header
    /// ```cpp
    /// #include <xtd/expressions/operator_precedence>
    /// ```
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core expressions
    /// @remarks See [operator precedence](https://en.cppreference.com/cpp/language/operator_precedence) for more information.
    enum class operator_precedence {
      /// @brief Represnets the highest operator precedence.
      highest = 0,
      /// @brief Represnets the placeholder operator precedence (`_1`).
      placeholder = 0,
      /// @brief Represnets the constant operator precedence (`42`).
      constant = 0,
      /// @brief Represnets the scope resolution operator precedence (`a::b`).
      scope_resolution = 1,
      /// @brief Represnets the postfix increment operator precedence (`a++`).
      postfix_increment = 1,
      /// @brief Represnets the postfix decrement operator precedence (`a--`).
      postfix_decrement = 1,
      /// @brief Represnets the functional cast operator precedence (`type(a)` `type {a}`).
      functional_cast = 1,
      /// @brief Represnets the function call operator precedence (`a()`).
      function_call = 2,
      /// @brief Represnets the subscript operator precedence (`a[]`).
      subscript = 2,
      /// @brief Represnets the member access operator precedence (`a.b` `a->b`).
      member_access = 2,
      /// @brief Represnets the method access operator precedence (`a.b` `a->b`).
      method_access = 2,
      /// @brief Represnets the prefix increment operator precedence (`++a`).
      prefix_increment = 2,
      /// @brief Represnets the prefix decrement operator precedence (`--a`).
      prefix_decrement = 2,
      /// @brief Represnets the unary plus operator precedence (`+a`).
      unary_plus = 2,
      /// @brief Represnets the unary minus operator precedence (`-a`).
      unary_minus = 2,
      /// @brief Represnets the logical not operator precedence (`!a`).
      logical_not = 2,
      /// @brief Represnets the bitwise not operator precedence (`~a`).
      bitwise_not = 2,
      /// @brief Represnets the c ctyle cast operator precedence (`(type)a`).
      c_ctyle_cast = 2,
      /// @brief Represnets the indirection operator precedence (`*a`).
      indirection = 2,
      /// @brief Represnets the address of operator precedence (`&a`).
      address_of = 3,
      /// @brief Represnets the reflection operator precedence (`^^a`).
      reflection = 3,
      /// @brief Represnets the size of operator precedence (`sizeof`).
      size_of = 3,
      /// @brief Represnets the await operator precedence (`co_await`).
      await = 3,
      /// @brief Represnets the new allocation operator precedence (`new`  `new[]`).
      new_allocation = 3,
      /// @brief Represnets the delete dallocation operator precedence (`delete`  `delete[]`).
      delete_dallocation = 3,
      /// @brief Represnets the pointer to member operator precedence (`a.*.b` `a->*b`).
      pointer_to_member = 4,
      /// @brief Represnets the multiplication operator precedence (`a * b`).
      multiplication = 5,
      /// @brief Represnets the division operator precedence (`a / b`).
      division = 5,
      /// @brief Represnets the modulo operator precedence (`a % b`).
      modulo = 5,
      /// @brief Represnets the addition operator precedence (`a + b`).
      addition = 6,
      /// @brief Represnets the subtraction operator precedence (`a - b`).
      subtraction = 6,
      /// @brief Represnets the bitwise left operator precedence (`a << b`).
      bitwise_left = 7,
      /// @brief Represnets the bitwise right operator precedence (`a >> b`).
      bitwise_right = 7,
      /// @brief Represnets the three way comparison operator precedence (`a <=> b`).
      three_way_comparison = 8,
      /// @brief Represnets the relational operator precedence (`a < b`,  `a <= b` `a > b` `a >= b`).
      relational = 9,
      /// @brief Represnets the less operator precedence (`a < b`).
      less = 9,
      /// @brief Represnets the less or equal operator precedence (`a <= b`).
      less_or_equal = 9,
      /// @brief Represnets the greater operator precedence (`a > b`).
      greater = 9 ,
      /// @brief Represnets the greater or equal operator precedence (`a >= b`).
      greater_or_equal = 9,
      /// @brief Represnets the equality operator precedence (`a == b` // `a != b`).
      equality = 10,
      /// @brief Represnets the equal operator precedence (`a == b`).
      equal = 10,
      /// @brief Represnets the not equal operator precedence (`a != b`).
      not_equal = 10,
      /// @brief Represnets the bitwise and operator precedence (`a & b`).
      bitwise_and = 11,
      /// @brief Represnets the bitwise xor operator precedence (`a ^ b`).
      bitwise_xor = 12,
      /// @brief Represnets the bitwise or operator precedence (`a | b`).
      bitwise_or = 13,
      /// @brief Represnets the logical and operator precedence (`a && b`).
      logical_and = 14,
      /// @brief Represnets the logical or operator precedence (`a || b`).
      logical_or = 15,
      /// @brief Represnets the ternary operator precedence (`a ? a : c`).
      ternary = 15,
      /// @brief Represnets the throws operator precedence (`throw`).
      throws = 15,
      /// @brief Represnets the yield operator precedence (`co_yield`).
      yield = 15,
      /// @brief Represnets the assignment operator precedence (`a = b`).
      assignment = 15,
      /// @brief Represnets the compound assignment operator precedence (`a += b` `a += b` `a -= b` `a *= b` `a /= b` `a %= b` `a <<= b` `a >>= b` `a &= b` `a ^= b` `a |= b`).
      compound_assignment = 16,
      /// @brief Represnets the compound sum assignment operator precedence (`a += b`).
      compound_sum_assignment = 16,
      /// @brief Represnets the compound difference assignment operator precedence (`a -= b`).
      compound_difference_assignment = 16,
      /// @brief Represnets the compound product assignment operator precedence (`a *= b`).
      compound_product_assignment = 16,
      /// @brief Represnets the compound quotient assignment operator precedence (`a /= b`).
      compound_quotient_assignment = 16,
      /// @brief Represnets the compound modulo assignment operator precedence (`a %= b`).
      compound_modulo_assignment = 16,
      /// @brief Represnets the compound bitwise left assignment operator precedence (`a <<= b`).
      compound_bitwise_left_assignment = 16,
      /// @brief Represnets the compound bitwise right assignment operator precedence (`a >>= b`).
      compound_bitwise_right_assignment = 16,
      /// @brief Represnets the compound bitwise and assignment operator precedence (`a &= b`).
      compound_bitwise_and_assignment = 16,
      /// @brief Represnets the compound bitwise xor assignment operator precedence (`a ^= b`).
      compound_bitwise_xor_assignment = 16,
      /// @brief Represnets the compound bitwise or assignment (`a |= b`) operator precedence ().
      compound_bitwise_or_assignment = 16,
      /// @brief Represnets the coma operator precedence (`a, b`).
      comma = 17,
      /// @brief Represnets the lowest operator precedence.
      lowest = 18,
    };
  }
}

/// @cond
//template<> struct xtd::enum_register<xtd::expressions::operator_precedence> {
//  explicit operator auto() const noexcept { return xtd::enum_collection<xtd::expressions::operator_precedence> {{xtd::expressions::operator_precedence::lowest, "lowest"}, {xtd::expressions::operator_precedence::equality, "equality"}, {xtd::expressions::operator_precedence::additive, "additive"}, {xtd::expressions::operator_precedence::multiplicative, "multiplicative"}, {xtd::expressions::operator_precedence::primary, "primary"}};}
//};
/// @endcond
