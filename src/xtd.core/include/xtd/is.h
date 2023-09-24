/// @file
/// @brief Contains xtd::is method.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "any"
#include "parse"
#include "types"
#include "unused"
#include <limits>
#include <memory>
#include <stdexcept>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename value_t>
  inline bool is(bool value) {return false;}
  template<typename value_t>
  inline bool is(decimal value) {return false;}
  template<typename value_t>
  inline bool is(double value) {return false;}
  template<typename value_t>
  inline bool is(float value) {return false;}
  template<typename value_t>
  inline bool is(sbyte value) {return false;}
  template<typename value_t>
  inline bool is(int16 value) {return false;}
  template<typename value_t>
  inline bool is(int32 value) {return false;}
  template<typename value_t>
  inline bool is(int64 value) {return false;}
  template<typename value_t>
  inline bool is(slong value) {return false;}
  template<typename value_t>
  inline bool is(xtd::byte value) {return false;}
  template<typename value_t>
  inline bool is(uint16 value) {return false;}
  template<typename value_t>
  inline bool is(uint32 value) {return false;}
  template<typename value_t>
  inline bool is(uint64 value) {return false;}
  template<typename value_t>
  inline bool is(xtd::ulong value) {return false;}
  /// @endcond
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   bool b = false;
  ///   std::cout << "b " << is<bool>(b) ? "is" : "isn't" << " bool" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<bool>(bool value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   decimal d = 4.2;
  ///   std::cout << "d " << is<decimal>(d) ? "is" : "isn't" << " decimal" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<decimal>(decimal value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   double d = 4.2;
  ///   std::cout << "d " << is<double>(d) ? "is" : "isn't" << " double" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<double>(double value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   float f = 4.2;
  ///   std::cout << "f " << is<float>(f) ? "is" : "isn't" << " float" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<float>(float value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   sbyte i = 42;
  ///   std::cout << "i " << is<sbyte>(i) ? "is" : "isn't" << " sbyte" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<sbyte>(sbyte value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   int16 i = 42;
  ///   std::cout << "i " << is<int16>(i) ? "is" : "isn't" << " int16" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int16>(int16 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   int32 i = 42;
  ///   std::cout << "i " << is<int32>(i) ? "is" : "isn't" << " int32" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int32>(int32 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   int64 i = 42;
  ///   std::cout << "i " << is<int64>(i) ? "is" : "isn't" << " int64" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int64>(int64 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   slong i = 42;
  ///   std::cout << "i " << is<slong>(i) ? "is" : "isn't" << " slong" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<slong>(slong value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   xtd::byte u = 42;
  ///   std::cout << "u " << is<xtd::byte>(u) ? "is" : "isn't" << " xtd::byte" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<xtd::byte>(xtd::byte value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   uint16 u = 42;
  ///   std::cout << "u " << is<uint16>(u) ? "is" : "isn't" << " uint16" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint16>(uint16 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   uint32 u = 42;
  ///   std::cout << "u " << is<uint32>(u) ? "is" : "isn't" << " uint32" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint32>(uint32 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   uint64 u = 42;
  ///   std::cout << "u " << is<uint64>(u) ? "is" : "isn't" << " uint64" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint64>(uint64 value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// auto main()->int {
  ///   xtd::ulong u = 42;
  ///   std::cout << "u " << is<xtd::ulong>(i) ? "is" : "isn't" << " xtd::ulong" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<xtd::ulong>(xtd::ulong value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t>
  bool is(std::any value) {
    try {
      std::any_cast<type_t>(value);
      return true;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<>
  inline bool is<std::any>(std::any value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(const param_t* value) {
    try {
      if (value == nullptr) return false;
      return dynamic_cast<const type_t*>(value) != nullptr;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(const param_t& value) {
    return is<type_t>(&value);
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(param_t* value) {
    try {
      if (value == nullptr) return false;
      return dynamic_cast<type_t*>(value) != nullptr;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t, typename param_t>
  bool is(param_t& value) {
    return is<type_t>(&value);
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Header
  /// @code #include <xtd/is> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t, typename current_type_t>
  bool is(std::shared_ptr<current_type_t>& value) {
    auto result = std::dynamic_pointer_cast<new_type_t>(value);
    if (result) return true;
    return false;
  }
}
