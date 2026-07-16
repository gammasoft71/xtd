/// @file
/// @brief Contains xtd::string alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.hpp"
#include "collections/generic/enumerable_generator.hpp"
#include "collections/generic/key_value_pair.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::string object is a sequential collection of char that represent a string; a char corresponds to a UTF-8 code unit. The value of the xtd::string object is the content of the sequential collection of char, and unlike [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::string_builder class.
  /// @remarks xtd::string implements xtd::basic_string and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string).
  using string = xtd::basic_string<char>;
  
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::string object is a sequential collection of char that represent a string; a char corresponds to a UTF-8 code unit. The value of the xtd::string object is the content of the sequential collection of char, and unlike [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::string_builder class.
  /// @remarks xtd::string implements xtd::basic_string and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string).
  /// @deprecated Replaced by xtd::string - Will be removed in version 1.2.0.
  using ustring [[deprecated("Replaced by xtd::string - Will be removed in version 1.2.0.")]] = xtd::string;
  
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(int val) -> xtd::string;
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(unsigned val) -> xtd::string;
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(long val) -> xtd::string;
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(unsigned long val) -> xtd::string;
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(long long val) -> xtd::string;
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(unsigned long long val) -> xtd::string;
  /// @brief Converts a floating point to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(float val) -> xtd::string;
  /// @brief Converts a floating point integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(double val) -> xtd::string;
  /// @brief Converts a floating point to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  [[nodiscard]] auto to_string(long double val) -> xtd::string;
  /// @brief Converts a type_t to xtd::string.
  /// @param val A type_t value to convert.
  /// @return A string holding the converted value.
  template<typename type_t>
  [[nodiscard]] inline auto to_string(type_t val) -> xtd::string {
    return string::format("{}", val);
  }
  
  /// @brief Converts a type_t to xtd::string.
  /// @param val A type_t value to convert.
  /// @return A string holding the converted value.
  /// @deprecated Replaced by xtd::to_string - Will be removed in version 1.2.0.
  template<typename type_t>
  [[deprecated("Replaced by xtd::to_string - Will be removed in version 1.2.0.")]]
  [[nodiscard]] inline auto to_ustring(type_t val) -> xtd::string {
    return to_string(val);
  }

  /// @cond
  namespace collections {
    namespace generic {
      template<typename type_t>
      auto enumerable_generator<type_t>::to_string() const noexcept -> xtd::string {
        auto result = xtd::string {"["};
        for (auto item : self_)
          result += xtd::string::format("{}{}", result != "[" ? ", " : "", item);
        return result + "]";
      }
    }
  }
  /// @endcond
}

/*
/// @cond
/// Needed for std::format
#if defined(__xtd__cpp_lib_format)
template <>
struct std::formatter<xtd::string> : std::formatter<std::string> {
  template<typename object_t, typename format_context_t>
  auto format(const object_t& obj, format_context_t& ctx) const {return std::format_to(ctx.out(), "{}", std::string {obj.to_string()});}
};
#endif
/// @endcond
*/

/// @cond
template<typename type_t>
[[nodiscard]] inline auto __to_string_istringable_to_string(const xtd::istringable<type_t>* obj) -> std::string {
  return obj->to_string();
}

template<typename key_t, typename value_t>
[[nodiscard]] inline auto xtd::collections::generic::key_value_pair<key_t, value_t>::to_string() const noexcept -> xtd::string {return xtd::string::format("({}, {})", first, second);}

template<typename type_t>
[[nodiscard]] inline auto __opaque_xtd_linq_enumerable_collection__<type_t>::to_string() const -> xtd::string {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}

template<typename type_t, typename param_t>
[[nodiscard]] inline auto __opaque_xtd_linq_lazy_enumerable__<type_t, param_t>::to_string() const -> xtd::string {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}

template<typename type_t>
[[nodiscard]] inline auto xtd::reference_wrapper_object<type_t>::to_string() const noexcept -> xtd::string {return xtd::string::format("{} [value={}]", xtd::object::to_string(), !ref_.has_value() ? "(null)" : string::format("{}", get()));}

template<typename type_t>
[[nodiscard]] inline auto xtd::shared_ptr_object<type_t>::to_string() const noexcept -> xtd::string {return xtd::string::format("{} [pointer={}]", xtd::object::to_string(), ptr_ == xtd::null ? "null"  : string::format("0x{:X16}, use_count={}", get(), use_count()));}

template<typename type_t, typename deleter_t>
[[nodiscard]] inline auto xtd::unique_ptr_object<type_t, deleter_t>::to_string() const noexcept -> xtd::string {return xtd::string::format("{} [pointer={}]", xtd::object::to_string(), ptr_ == xtd::null ? "null"  : string::format("0x{:X16}", get()));}
/// @endcond

#include "literals/string.hpp"
