/// @file
/// @brief Contains xtd::expressions::operator_precedence enum class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
//#include "../enum.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::expressions namespace provides a lightweight, composable expression template framework for building and evaluating lazy, strongly-typed functional expressions from arbitrary callables
  namespace expressions {
    enum class operator_precedence {
      // https://en.cppreference.com/cpp/language/operator_precedence
      highest = 0,
      placeholder = 0,                        // `_1`
      constant = 0,                           // 42
      scope_resolution = 1,                   // `a::b`
      postfix_increment = 1,                  // `a++`
      postfix_decrement = 1,                  // `a--`
      functional_cast = 1,                    // `type(a)` `type {a}`
      function_call = 2,                      // `a()`
      subscript = 2,                          // `a[]`
      member_access = 2,                      // `a.b` `a->b`
      method_access = 2,                      // `a.b` `a->b`
      prefix_increment = 2,                   // `++a`
      prefix_decrement = 2,                   // `--a`
      unary_plus = 2,                         // `+a`
      unary_minus = 2,                        // `-a`
      logical_not = 2,                        // `!a`
      bitwise_not = 2,                        // `~a`
      c_ctyle_cast = 2,                       // `(type)a`
      indirection = 2,                        // `*a`
      address_of = 3,                         // `&a`
      reflection = 3,                         // `^^a`
      size_of = 3,                            // `sizeof`
      await = 3,                              // `co_await`
      new_allocation = 3,                     // `new`  `new[]`
      delete_dallocation = 3,                 // `delete`  `delete[]`
      pointer_to_member = 4,                  // `a.*.b` `a->*b`
      multiplication = 5,                     // `a * b`
      division = 5,                           // `a / b`
      remainder = 5,                          // `a % b`
      addition = 6,                           // `a + b`
      subtraction = 6,                        // `a - b`
      bitwise_left = 7,                       // `a << b`
      bitwise_right = 7,                      // `a >> b`
      three_way_comparison = 8,               // `a <=> b`
      relational = 9,                         // `a < b`,  `a <= b` `a > b` `a >= b`
      less = 9,                               // `a < b`
      less_or_equal = 9,                      // `a <= b`
      greater = 9 ,                           // `a > b`
      greater_or_equal = 9,                   // `a >= b`
      equality = 10,                          // `a == b` // `a != b`
      equal = 10,                             // `a == b`
      not_equal = 10,                         // `a != b`
      bitwise_and = 11,                       // `a & b`
      bitwise_xor = 12,                       // `a ^ b`
      bitwise_or = 13,                        // `a | b`
      logical_and = 14,                       // `a && b`
      logical_or = 15,                        // `a || b`
      ternary = 15,                           // `a ? a : c`
      throws = 15,                            // `throw`
      yield = 15,                             // `co_yield`
      assignment = 15,                        // `a = b`
      compound_assignment = 16,               // `a += b` `a += b` `a -= b` `a *= b` `a /= b` `a %= b` `a <<= b` `a >>= b` `a &= b` `a ^= b` `a |= b`
      compound_sum_assignment = 16,           // `a += b`
      compound_difference_assignment = 16,    // `a -= b`
      compound_product_assignment = 16,       // `a *= b`
      compound_quotient_assignment = 16,      // `a /= b`
      compound_remainder_assignment = 16,     // `a %= b`
      compound_bitwise_left_assignment = 16,  // `a <<= b`
      compound_bitwise_right_assignment = 16, // `a >>= b`
      compound_bitwise_and_assignment = 16,   // `a &= b`
      compound_bitwise_xor_assignment = 16,   // `a ^= b`
      compound_bitwise_or_assignment = 16,    // `a |= b`
      comma = 17,                             // `a, b`
      lowest = 18,
    };
  }
}

/// @cond
//template<> struct xtd::enum_register<xtd::expressions::operator_precedence> {
//  explicit operator auto() const noexcept { return xtd::enum_collection<xtd::expressions::operator_precedence> {{xtd::expressions::operator_precedence::lowest, "lowest"}, {xtd::expressions::operator_precedence::equality, "equality"}, {xtd::expressions::operator_precedence::additive, "additive"}, {xtd::expressions::operator_precedence::multiplicative, "multiplicative"}, {xtd::expressions::operator_precedence::primary, "primary"}};}
//};
/// @endcond
