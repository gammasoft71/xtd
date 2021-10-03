/// @file
/// @brief Contains xtd::is method.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <limits>
#include <memory>
#include <stdexcept>
#include "parse.h"
#include "types.h"
#include "unused.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename value_t>
  inline bool is(bool value) {return false;}
  template<typename value_t>
  inline bool is(decimal_t value) {return false;}
  template<typename value_t>
  inline bool is(double value) {return false;}
  template<typename value_t>
  inline bool is(float value) {return false;}
  template<typename value_t>
  inline bool is(int8_t value) {return false;}
  template<typename value_t>
  inline bool is(int16_t value) {return false;}
  template<typename value_t>
  inline bool is(int32_t value) {return false;}
  template<typename value_t>
  inline bool is(int64_t value) {return false;}
  template<typename value_t>
  inline bool is(llong_t value) {return false;}
  template<typename value_t>
  inline bool is(uint8_t value) {return false;}
  template<typename value_t>
  inline bool is(uint16_t value) {return false;}
  template<typename value_t>
  inline bool is(uint32_t value) {return false;}
  template<typename value_t>
  inline bool is(uint64_t value) {return false;}
  template<typename value_t>
  inline bool is(ullong_t value) {return false;}
  /// @endcond
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   bool b = false;
  ///   std::cout << "b " << is<bool>(b) ? "is" : "isn't" << " bool" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<bool>(bool value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   decimal_t d = 4.2;
  ///   std::cout << "d " << is<decimal_t>(d) ? "is" : "isn't" << " decimal_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<decimal_t>(decimal_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   double d = 4.2;
  ///   std::cout << "d " << is<double>(d) ? "is" : "isn't" << " double" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<double>(double value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   float f = 4.2;
  ///   std::cout << "f " << is<float>(f) ? "is" : "isn't" << " float" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<float>(float value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int8_t i = 42;
  ///   std::cout << "i " << is<int8_t>(i) ? "is" : "isn't" << " int8_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int8_t>(int8_t value) {
    return true;
  }

  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int16_t i = 42;
  ///   std::cout << "i " << is<int16_t>(i) ? "is" : "isn't" << " int16_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int16_t>(int16_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int32_t i = 42;
  ///   std::cout << "i " << is<int32_t>(i) ? "is" : "isn't" << " int32_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int32_t>(int32_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int64_t i = 42;
  ///   std::cout << "i " << is<int64_t>(i) ? "is" : "isn't" << " int64_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<int64_t>(int64_t value) {
    return true;
  }

  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   llong_t i = 42;
  ///   std::cout << "i " << is<llong_t>(i) ? "is" : "isn't" << " llong_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<llong_t>(llong_t value) {
    return true;
  }
 
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint8_t u = 42;
  ///   std::cout << "u " << is<uint8_t>(u) ? "is" : "isn't" << " uint8_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint8_t>(uint8_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint16_t u = 42;
  ///   std::cout << "u " << is<uint16_t>(u) ? "is" : "isn't" << " uint16_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint16_t>(uint16_t value) {
    return true;
  }
    
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint32_t u = 42;
  ///   std::cout << "u " << is<uint32_t>(u) ? "is" : "isn't" << " uint32_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint32_t>(uint32_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint64_t u = 42;
  ///   std::cout << "u " << is<uint64_t>(u) ? "is" : "isn't" << " uint64_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<uint64_t>(uint64_t value) {
    return true;
  }
  
  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int main() {
  ///   ullong_t u = 42;
  ///   std::cout << "u " << is<ullong_t>(i) ? "is" : "isn't" << " ullong_t" << endl;
  /// }
  /// @endcode
  template<>
  inline bool is<ullong_t>(ullong_t value) {
    return true;
  }

  /// @brief Checks if the result of an expression is compatible with a given type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t>
  bool is(std::any value) {
    try {
      any_cast<type_t>(value);
      return true;
    } catch (const std::bad_cast&) {
      return false;
    }
  }

  /// @brief Checks if the result of an expression is compatible with a given type.
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
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t, typename current_type_t>
  bool is(std::shared_ptr<current_type_t>& value) {
    try {
      unused_(dynamic_pointer_cast<new_type_t>(value));
      return true;
    } catch (const std::exception&) {
      return false;
    }
    return false;
  }
}
