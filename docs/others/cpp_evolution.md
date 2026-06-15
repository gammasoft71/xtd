
# Evolution of the C++ language over 35 years

Demonstration of the evolution of C++ with a simple `max` function.

## Notes 

The `max` function is chosen for the simplicity of the demonstration only. 
Under no circumstances does it want to replace [std::max](https://en.cppreference.com/w/cpp/algorithm/max.html).

## before C++98 :

```cpp
#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {
  printf("MAX(12, 24) => %d\n", MAX(12, 24));
  printf("MAX(24, 12) => %d\n", MAX(24, 12));
  return 0;
}

// Output :
//
// MAX(12, 24) => 24
// MAX(24, 12) => 24
```

* No types
* No scope
* No security
* No clean debug
* Double evaluation possible

It was concise... but brutal.

## C++98 :

```cpp
#include <iostream>

template<class value_t>
const value_t& max(const value_t& a, const value_t& b) {return a < b ? b : a;}

int main() {
  std::cout << "max(12, 24) => " << max(12, 24) << std::endl;
  std::cout << "max(24, 12) => " << max(24, 12) << std::endl;
}

// Output :
//
// max(12, 24) => 24
// max(24, 12) => 24
```

Advantages:
* Typing
* Safe instantiation
* A real function

But we remain verbose.

## C++11 :

```cpp
#include <iostream>

template<class value_t>
constexpr auto max(const value_t& a, const value_t& b) -> const value_t& {return a < b ? b : a;}

auto main() -> int {
  std::cout << "max(12, 24) => " << max(12, 24) << std::endl;
  std::cout << "max(24, 12) => " << max(24, 12) << std::endl;
}

// Output :
//
// max(12, 24) => 24
// max(24, 12) => 24
```

Advantages:
* trailing return type
* `auto main() -> int`

The language become more expressive, more fluid.

## C++14 :

```cpp
#include <iostream>

template<class value_t>
constexpr auto max(value_t a, value_t b) {return a < b ? b : a;}

auto main() -> int {
  std::cout << "max(12, 24) => " << max(12, 24) << std::endl;
  std::cout << "max(24, 12) => " << max(24, 12) << std::endl;
}

// Output :
//
// max(12, 24) => 24
// max(24, 12) => 24
```

Advantages:
* Return `auto` without needed return type.


## C++20 :

```cpp  
#include <iostream>

[[nodiscard]] constexpr auto max(auto a, auto b) {return a < b ? b : a;}

auto main() -> int {
  std::cout << "max(12, 24.0) => " << max(12, 24.0) << std::endl;
  std::cout << "max(24.0, 12) => " << max(24.0, 12) << std::endl;
}

// Output :
//
// max(12, 24.0) => 24
// max(24.0, 12) => 24
```

There, frankly... it's beautiful.

We have: 
* genericity 
* automatic deduction 
* maximum readability

It's almost pseudo-code.

## C++23 :

```cpp  
#include <print>

[[nodiscard]] constexpr auto max(auto a, auto b) {return a < b ? b : a;}

auto main() -> int {
  std::println("max(12, 24.0) => {}", max(12, 24.0));
  std::println("max(24.0, 12) => {}", max(24.0, 12));
}

// Output :
//
// max(12, 24.0) => 24
// max(24.0, 12) => 24
```

We achieve something quite ironic:

* As concise as the pre-98
* Infinitely safer
* strong type
* Verified at compilation
* No macro and no evaluation trap

It's almost poetic.

## Remarks

For C++20 and C++23, we could have added the use of Concepts. But this could add noise for such a simple function where the compiler's error message is finally understandable.

## Synthesis of evolution

| Characteristic          | Pre-98 (Macro) | C++98 / 11 | C++20 / 23  |
| ----------------------- | -------------- | ---------- | ----------- |
| Concise syntax          | ✅ Yes          | ❌ No       | ✅ Yes       |
| Security (Types/Scope)  | ❌ No           | ✅ Yes      | ✅ Yes       |
| Heterogeneous types     | ✅ Yes          | ❌ No       | ✅ Yes       |
| Safe & simple display   | ❌ No           | ❌ No       | ✅ Yes       |
| Readability             | ⚠️ Risky        | ❌ Verbose  | ✅ Purified  |

## Author's opinion: Why 2020 changes everything

Many consider C++11 as the beginning of "modern C++". This is a mistake of perspective. C++11 saved the language by giving it basic tools, but it made it complex, intimidating and often unreadable for newcomers.

True modern C++ starts in 2020. 
It is from this version that the language finally becomes minimalist and fluid. Thanks to auto templates (Abbreviated Function Templates), concepts and std::print, we stop writing code for the compiler to finally write code for humans.

C++20 is not a simple update, it is the year when C++ became a high-level language without losing its low-level performance.

## Conclusion 

1990 → Concise but dangerous
1998 → Typed, safe, but verbose
2011-14 → Modernization and simplification
2020 → Maximum expressiveness
2023 → Conciseness + security + modernity
