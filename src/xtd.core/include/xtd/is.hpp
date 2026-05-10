/// @file
/// @brief Contains xtd::is method.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "any.hpp"
#include "parse.hpp"
#include "types.hpp"
#include <limits>
#include <memory>
#include <stdexcept>
#include <variant>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename value_t>
  [[nodiscard]] inline auto is(bool value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(char value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(char16 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(char32 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(char8 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(wchar value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(decimal value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(double value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(float value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(sbyte value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(int16 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(int32 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(int64 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(slong value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(xtd::byte value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(uint16 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(uint32 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(uint64 value) -> bool {return false;}
  template<typename value_t>
  [[nodiscard]] inline auto is(xtd::ulong value) -> bool {return false;}
  /// @endcond
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   bool b = false;
  ///   std::cout << "b " << is<bool>(b) ? "is" : "isn't" << " bool" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<bool>(bool value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   char c = 'a';
  ///   std::cout << "c " << is<char>(c) ? "is" : "isn't" << " char" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<char>(char value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   char16 c = u'a';
  ///   std::cout << "c " << is<char16>(c) ? "is" : "isn't" << " char16" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<char16>(char16 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   char32 c = U'a';
  ///   std::cout << "c " << is<char32>(c) ? "is" : "isn't" << " char32" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<char32>(char32 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   char8 c = u8'a';
  ///   std::cout << "c " << is<char8>(c) ? "is" : "isn't" << " char8" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<char8>(char8 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   wchar c = L'a';
  ///   std::cout << "c " << is<wchar>(c) ? "is" : "isn't" << " wchar" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<wchar>(wchar value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   decimal d = 4.2;
  ///   std::cout << "d " << is<decimal>(d) ? "is" : "isn't" << " decimal" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<decimal>(decimal value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   double d = 4.2;
  ///   std::cout << "d " << is<double>(d) ? "is" : "isn't" << " double" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<double>(double value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   float f = 4.2;
  ///   std::cout << "f " << is<float>(f) ? "is" : "isn't" << " float" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<float>(float value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   sbyte i = 42;
  ///   std::cout << "i " << is<sbyte>(i) ? "is" : "isn't" << " sbyte" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<sbyte>(sbyte value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   int16 i = 42;
  ///   std::cout << "i " << is<int16>(i) ? "is" : "isn't" << " int16" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<int16>(int16 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   int32 i = 42;
  ///   std::cout << "i " << is<int32>(i) ? "is" : "isn't" << " int32" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<int32>(int32 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   int64 i = 42;
  ///   std::cout << "i " << is<int64>(i) ? "is" : "isn't" << " int64" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<int64>(int64 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   slong i = 42;
  ///   std::cout << "i " << is<slong>(i) ? "is" : "isn't" << " slong" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<slong>(slong value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   xtd::byte u = 42;
  ///   std::cout << "u " << is<xtd::byte>(u) ? "is" : "isn't" << " xtd::byte" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<xtd::byte>(xtd::byte value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   uint16 u = 42;
  ///   std::cout << "u " << is<uint16>(u) ? "is" : "isn't" << " uint16" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<uint16>(uint16 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   uint32 u = 42;
  ///   std::cout << "u " << is<uint32>(u) ? "is" : "isn't" << " uint32" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<uint32>(uint32 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   uint64 u = 42;
  ///   std::cout << "u " << is<uint64>(u) ? "is" : "isn't" << " uint64" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<uint64>(uint64 value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// auto main() -> int {
  ///   xtd::ulong u = 42;
  ///   std::cout << "u " << is<xtd::ulong>(i) ? "is" : "isn't" << " xtd::ulong" << endl;
  /// }
  /// ```
  template<>
  [[nodiscard]] inline auto is<xtd::ulong>(xtd::ulong value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t>
  [[nodiscard]] auto is(xtd::any value) -> bool {
    try {
      xtd::any_cast<type_t>(value);
      return true;
    } catch (const std::bad_cast&) {
      return false;
    }
  }

  /// @cond
  template<>
  [[nodiscard]] inline auto is<xtd::null_ptr>(xtd::any value) -> bool {
    return !value.has_value();
  }
  /// @endcond

  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  [[nodiscard]] inline auto is<xtd::any>(xtd::any value) -> bool {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  [[nodiscard]] auto is(const param_t* value) -> bool {
    try {
      if (value == nullptr) return false;
      return dynamic_cast<const type_t*>(value) != nullptr;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  [[nodiscard]] auto is(const param_t& value) -> bool {
    return is<type_t>(&value);
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  requires (std::is_polymorphic_v<type_t> && std::is_polymorphic_v<param_t> && !std::is_null_pointer_v<type_t>)
  [[nodiscard]] auto is(param_t* value) -> bool {
    if (value == nullptr) return false;
    return dynamic_cast<type_t*>(value) != nullptr;
  }

  /// @cond
  template<typename type_t, typename param_t>
  requires ((!std::is_polymorphic_v<type_t> || !std::is_polymorphic_v<param_t>) && !std::is_null_pointer_v<type_t>)
  [[nodiscard]] auto is(param_t* value) -> bool {
    if (value == nullptr) return false;
    return typeid(type_t).name() == typeid(param_t).name();
  }
  
  template<typename type_t, typename param_t>
  requires std::is_null_pointer_v<type_t>
  [[nodiscard]] auto is(param_t* value) -> bool {
    return value == nullptr;
  }

  template<typename type_t, typename ...args_t>
  [[nodiscard]] inline auto is(const std::variant<args_t...>& value) -> bool {
    auto result = false;
    std::visit([&](auto&& arg) {if constexpr (std::is_same_v<std::remove_cvref_t<std::decay_t<decltype(arg)>>, std::remove_cvref_t<type_t>>) result = true;}, value);
    return result;
  }
  
  template<typename type_t, typename ...args_t>
  [[nodiscard]] inline auto is(std::variant<args_t...>& value) -> bool {
    auto result = false;
    std::visit([&](auto&& arg) {if constexpr (std::is_same_v<std::remove_cvref_t<std::decay_t<decltype(arg)>>, std::remove_cvref_t<type_t>>) result = true;}, value);
    return result;
  }
  /// @endcond

  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  [[nodiscard]] auto is(param_t& value) -> bool {
    return is<type_t>(&value);
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/is>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type, typename current_type>
  [[nodiscard]] auto is(xtd::sptr<current_type>& value) -> bool {
    auto result = std::dynamic_pointer_cast<new_type>(value.pointer());
    if (result) return true;
    return false;
  }
}
