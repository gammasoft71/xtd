# Convert struct to tuple

```cpp
#include <format>
#include <print>
#include <string>
#include <tuple>
#include <type_traits>

//#if defined(__cpp_structured_bindings) && __cpp_structured_bindings >= 202411L
#if __cplusplus > 202302L
namespace xtd {
  template <typename type_t>
  constexpr auto to_tuple(const type_t& value) {
    const auto& [... members] = value;
    return std::make_tuple(members...);
  }
}

#else
namespace xtd::internal {
  struct tuple_any_type {
    template <typename type_t>
    operator type_t();
  };
  
  template <typename type_t>
  constexpr auto to_tuple(const type_t& value) {
    using value_type = std::remove_cvref_t<type_t>;
    using any_type = tuple_any_type;
    if constexpr (requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}}; } && !requires { value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};}) {
      const auto& [a1, a2, a3, a4, a5, a6, a7, a8] = value;
      return std::make_tuple(a1, a2, a3, a4, a5, a6, a7, a8);
    } else if constexpr (requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};} && !requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};}) {
      const auto& [a1, a2, a3, a4, a5, a6, a7] = value;
      return std::make_tuple(a1, a2, a3, a4, a5, a6, a7);
    } else if constexpr (requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};} && !requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};}) {
      const auto& [a1, a2, a3, a4, a5, a6] = value;
      return std::make_tuple(a1, a2, a3, a4, a5, a6);
    } else if constexpr (requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};} && !requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};}) {
      const auto& [a1, a2, a3, a4, a5] = value;
      return std::make_tuple(a1, a2, a3, a4, a5);
    } else if constexpr (requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}};} && !requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}, any_type{}};}) {
      const auto& [a1, a2, a3, a4] = value;
      return std::make_tuple(a1, a2, a3, a4);
    } else if constexpr (requires {value_type{any_type{}, any_type{}, any_type{}};} && !requires {value_type{any_type{}, any_type{}, any_type{}, any_type{}};}) {
      const auto& [a1, a2, a3] = value;
      return std::make_tuple(a1, a2, a3);
    } else if constexpr (requires {value_type{any_type{}, any_type{}};} && !requires {value_type{any_type{}, any_type{}, any_type{}};}) {
      const auto& [a1, a2] = value;
      return std::make_tuple(a1, a2);
    } else if constexpr (requires {value_type{any_type{}};} && !requires {value_type{any_type{}, any_type{}};}) {
      const auto& [a1] = value;
      return std::make_tuple(a1);
    }  else {
      return std::make_tuple();
    }
  }
}

namespace xtd {
  template <typename type_t>
  constexpr auto to_tuple(const type_t& value) {
    using value_type = std::remove_cvref_t<type_t>;
    static_assert(std::is_aggregate_v<value_type>, "The type must be an aggregate.");
    return internal::to_tuple(value);
  }
}
#endif

auto main() -> int {
  struct my_struct {
    int i;
    short s;
  };
  
  auto s = my_struct {
    .i = 10,
    .s = 11
  };
  
  auto t = xtd::to_tuple(s);
  
  std::println("t = {}", t);
}

// This code produces the following output:
//
// t = (10, 11)
```
