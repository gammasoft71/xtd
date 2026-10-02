#include <format>
#include <print>
#include <string>

#if __cplusplus > 202302L
#include <tuple>
namespace xtd {
  template<typename type_t>
  constexpr auto to_tuple(const type_t& value) {
    const auto& [... members] = value;
    return std::make_tuple(members...);
  }
}
#else
#include <tuple>
#include <type_traits>
struct ___xtd_tuple_any_type___ {
  template <typename type_t> operator type_t();
};

template <typename type_t>
constexpr auto ___xtd_to_tuple___(const type_t& value) {
  if constexpr (requires {{type_t{___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}}};}) {
    const auto& [a1, a2, a3, a4, a5, a6, a7, a8] = value;
    return std::make_tuple(a1, a2, a3, a4, a5, a6, a7, a8);
  } else if constexpr (requires {{type_t{___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}}};}) {
    const auto& [a1, a2, a3, a4, a5, a6, a7] = value;
    return std::make_tuple(a1, a2, a3, a4, a5, a6, a7);
  } else if constexpr (requires {{type_t{___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}}};}) {
    const auto& [a1, a2, a3, a4, a5, a6] = value;
    return std::make_tuple(a1, a2, a3, a4, a5, a6);
  } else if constexpr (requires {{type_t{___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}}};}) {
    const auto& [a1, a2, a3, a4, a5] = value;
    return std::make_tuple(a1, a2, a3, a4, a5);
  } else if constexpr (requires {{type_t{___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}}};}) {
    const auto& [a1, a2, a3, a4] = value;
    return std::make_tuple(a1, a2, a3, a4);
  } else if constexpr (requires {{type_t{___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}}};}) {
    const auto& [a1, a2, a3] = value;
    return std::make_tuple(a1, a2, a3);
  } else if constexpr (requires {{type_t{___xtd_tuple_any_type___{}, ___xtd_tuple_any_type___{}}};}) {
    const auto& [a1, a2] = value;
    return std::make_tuple(a1, a2);
  } else if constexpr (requires {{type_t{___xtd_tuple_any_type___{}}};}) {
    const auto& [a1] = value;
    return std::make_tuple(a1);
  } else return std::make_tuple();
}

namespace xtd {
  template <typename type_t>
  constexpr auto to_tuple(const type_t& value) {
    static_assert(std::is_aggregate_v<type_t>, "The type must be an aggregate.");
    return ___xtd_to_tuple___(value);
  }
}
#endif

auto main() -> int {
  struct my_struct {int i; short s;};
  auto s = my_struct {.i = 10, .s = 11};
  auto t = xtd::to_tuple(s);

  std::println("t = {}", t);
}

// This code produces the following output :
//
// t = (10, 11)
