# xtd::expressions operetors

## Arithmetic

| operator | Available |
| -------- | --------- |
| `a + b`  | 🟢         |
| `a - b`  | 🟢         |
| `+a`     | 🟢         |
| `-a`     | 🟢         |
| `a * b`  | 🟢         |
| `a / b`  | 🟢         |
| `a % b`  | 🟢         |
| `++a`    | 🔴         |
| `a++`    | 🔴         |
| `--a`    | 🔴         |
| `a--`    | 🔴         |

## Relational

| operator  | Available |
| --------- | --------- |
| `a == b`  | 🟢         |
| `a != b`  | 🟢         |
| `a > b`   | 🟢         |
| `a < b`   | 🟢         |
| `a >= b`  | 🟢         |
| `a <= b`  | 🟢         |
| `a <=> b` | 🟢         |

## Logical

| operator | Available |
| -------- | --------- |
| `!a`     | 🟢         |
| `a && b` | 🟢         |
| `a || b` | 🟢         |

## Bitwise

| operator  | Available |
| --------- | --------- |
| `~a`      | 🟢         |
| `a & b`   | 🟢         |
| `a | b`   | 🟢         |
| `a ^ b`   | 🟢         |
| `a << b`  | 🟢         |
| `a >> b`  | 🟢         |

## Assignment

| operator  | Available |
| --------- | --------- |
| `a = b`   | 🔴         |
| `a += b`  | 🔴         |
| `a -= b`  | 🔴         |
| `a *= b`  | 🔴         |
| `a /= b`  | 🔴         |
| `a %= b`  | 🔴         |
| `a &= b`  | 🔴         |
| `a |= b`  | 🔴         |
| `a ^= b`  | 🔴         |
| `a <<= b` | 🔴         |
| `a >>= b` | 🔴         |

## Member and pointer

| operator      | Available |
| ------------- | --------- |
| `a[b] a<:b:>` | 🟡         |
| `*a`          | 🔴         |
| `&a`          | 🔴         |
| `a->b`        | 🔴         |
| `a.b`         | 🔴         |
| `a->*b`       | 🔴         |
| `a.*b`        | 🟡         |

## Other

| operator                 | Available |
| ------------------------ | --------- |
| `a(a1, a2)`              | 🟡         |
| `a, b`                   | 🔴         |
| `a ?b : c`               | 🟡         |
| `a::b`                   | 🔴         |
| `"a"_b`                  | 🔴         |
| `sizeof a`               | 🔴         |
| `sizeof T`               | 🔴         |
| `sizeof...(Args)`        | 🔴         |
| `alignof T`              | 🔴         |
| `typeof a`               | 🔴         |
| `typeof T`               | 🔴         |
| `decltype(a)`            | 🔴         |
| `decltype(T)`            | 🔴         |
| `typeid(a)`              | 🔴         |
| `typeid(T)`              | 🔴         |
| `(T)a`                   | 🔴         |
| `T(a)`                   | 🔴         |
| `T {a}`                  | 🔴         |
| `auto(a)`                | 🔴         |
| `auto {a}`               | 🔴         |
| `static_cast<T>(a)`      | 🔴         |
| `dynamic_cast<T>(a)`     | 🔴         |
| `const_cast<T>(a)`       | 🔴         |
| `reinterpret_cast<T>(a)` | 🔴         |
| `new T`                  | 🔴         |
| `new T[n]`               | 🔴         |
| `delete a`               | 🔴         |
| `delete[] a`             | 🔴         |
| `noexcept(a)`            | 🔴         |
| `^^a`                    | 🔴         |

# xtd::expressions

## Architecture struct

```
|- 🟢 expression 
   |- 🟢 binary_expression
   |  |- 🟢 add_expression [a + b]
   |  |- 🟢 and_expression [a & b]
   |  |- 🟢 compare_three_way_expression (spaceship) [a <=> b]
   |  |- 🟢 divide_expression [a / b]
   |  |- 🟢 equal_expression [a == b]
   |  |- 🟢 greater_than_expression [a > b]
   |  |- 🟢 greater_than_or_equal_expression [a >= b]
   |  |- 🟢 left_shift_expression [a << b]
   |  |- 🟢 less_than_expression [a < b]
   |  |- 🟢 less_than_or_equal_expression [a <= b]
   |  |- 🟢 logical_and (and_also_expression) [a && b]
   |  |- 🟢 logical_or (or_else_expression) [a || b]
   |  |- 🟢 modulo_expression [a % b]
   |  |- 🟢 multiply_expression [a * b]
   |  |- 🟢 not_equal_expression [a != b]
   |  |- 🟢 or_expression [a | b]
   |  |- 🟢 right_shift_expression [a >> b]
   |  |- 🟢 subtract_expression [a - b]
   |  |- 🟢 xor_expression [a ^ b]
   |- 🟢 conditional_expression
   |  |- 🟡 if_then_else_expression [a ? b : c]
   |- 🟢 value_expression
   |  |- 🟢 constant
   |  |- 🟢 value
   |- 🟢 invocation_expression
   |  |- 🟢 method_call_expression
   |     |- 🟢 method
   |- 🟢 member_expression
   |  |- 🟢 member
   |- 🟢 placeholder_expression
   |  |- 🟢 placeholder (args)
   |- 🟢 unary_expression
      |- 🟢 logical_not_expression [!a]
      |- 🟢 not_expression [~a]
      |- 🟢 unary_minus_expression (negate) [-a]
      |- 🟢 unary_plus_expression [+a]
```

## Static expression methods

* 🟢 xtd::expressions::expression::add
* 🟢 xtd::expressions::expression::and_
* 🟢 xtd::expressions::expression::and_also (alias on logical_and)
* 🟢 xtd::expressions::expression::arg
* 🟢 xtd::expressions::expression::compare_three_way
* 🟢 xtd::expressions::expression::constant
* 🟢 xtd::expressions::expression::divide
* 🟢 xtd::expressions::expression::equal
* 🟢 xtd::expressions::expression::greater_than
* 🟢 xtd::expressions::expression::greater_than_or_equal
* 🟡 xtd::expressions::expression::if_then_else
* 🟢 xtd::expressions::expression::left_shift
* 🟢 xtd::expressions::expression::less_than
* 🟢 xtd::expressions::expression::less_than_or_equal
* 🟢 xtd::expressions::expression::logical_and
* 🟢 xtd::expressions::expression::logical_not
* 🟢 xtd::expressions::expression::logical_or
* 🟡 xtd::expressions::expression::member
* 🟡 xtd::expressions::expression::method_call
* 🟢 xtd::expressions::expression::modulo
* 🟢 xtd::expressions::expression::multiply
* 🟢 xtd::expressions::expression::negate (alias on unary_minus)
* 🟢 xtd::expressions::expression::not_
* 🟢 xtd::expressions::expression::not_equal
* 🟢 xtd::expressions::expression::or_
* 🟢 xtd::expressions::expression::or_else (alias on logical_or)
* 🟢 xtd::expressions::expression::placeholder
* 🟢 xtd::expressions::expression::right_shift
* 🟢 xtd::expressions::expression::spaceship (alias on compare_three_way)
* 🟢 xtd::expressions::expression::subtract
* 🟢 xtd::expressions::expression::unary_minus
* 🟢 xtd::expressions::expression::unary_plus
* 🟢 xtd::expressions::expression::value
* 🟢 xtd::expressions::expression::xor_

## Next implementation

List of priorities of future operators that should be supported by xtd::expressions :
1. `a(a1, a2)` → Essential
2. `a ? b : c` → Very useful
3. `a[b]` → Coziness
4. `a.b` → Big long-term bonus

## Legends

🟢 Already implemented
🟡 To be implemented
🔴 Will not be implemented
