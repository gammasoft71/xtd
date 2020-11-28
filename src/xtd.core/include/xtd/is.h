#pragma once
#include <limits>
#include <stdexcept>
#include "parse.h"
#include "strings.h"
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename T>
  inline bool is(bool value) {return false;}
  template<typename T>
  inline bool is(decimal_t value) {return false;}
  template<typename T>
  inline bool is(double value) {return false;}
  template<typename T>
  inline bool is(float value) {return false;}
  template<typename T>
  inline bool is(int8_t value) {return false;}
  template<typename T>
  inline bool is(int16_t value) {return false;}
  template<typename T>
  inline bool is(int32_t value) {return false;}
  template<typename T>
  inline bool is(int64_t value) {return false;}
  template<typename T>
  inline bool is(intptr_t value) {return false;}
  template<typename T>
  inline bool is(uint8_t value) {return false;}
  template<typename T>
  inline bool is(uint16_t value) {return false;}
  template<typename T>
  inline bool is(uint32_t value) {return false;}
  template<typename T>
  inline bool is(uint64_t value) {return false;}
  template<typename T>
  inline bool is(uintptr_t value) {return false;}
  /// @endcond
  
  /// @brief Return true if specified value is the specified bool. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   bool b = false;
  ///   std::cout << "b " << is<bool>(b) ? "is" : "isn't" << " bool" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<bool>(bool value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified decimal_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   decimal_t d = 4.2;
  ///   std::cout << "d " << is<decimal_t>(d) ? "is" : "isn't" << " decimal_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<decimal_t>(decimal_t value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified double. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   double d = 4.2;
  ///   std::cout << "d " << is<double>(d) ? "is" : "isn't" << " double" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<double>(double value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified float. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   float f = 4.2;
  ///   std::cout << "f " << is<float>(f) ? "is" : "isn't" << " float" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<float>(float value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified int8_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int8_t i = 42;
  ///   std::cout << "i " << is<int8_t>(i) ? "is" : "isn't" << " int8_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<int8_t>(int8_t value) {
    return true;
  }

  /// @brief Return true if specified value is the specified int16_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int16_t i = 42;
  ///   std::cout << "i " << is<int16_t>(i) ? "is" : "isn't" << " int16_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<int16_t>(int16_t value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified int32_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int32_t i = 42;
  ///   std::cout << "i " << is<int32_t>(i) ? "is" : "isn't" << " int32_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<int32_t>(int32_t value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified int64_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   int64_t i = 42;
  ///   std::cout << "i " << is<int64_t>(i) ? "is" : "isn't" << " int64_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<int64_t>(int64_t value) {
    return true;
  }

  /// @brief Return true if specified value is the specified intptr_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   intptr_t i = 42;
  ///   std::cout << "i " << is<intptr_t>(i) ? "is" : "isn't" << " intptr_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<intptr_t>(intptr_t value) {
    return true;
  }
 
  /// @brief Return true if specified value is the specified uint8_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint8_t u = 42;
  ///   std::cout << "u " << is<uint8_t>(u) ? "is" : "isn't" << " uint8_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<uint8_t>(uint8_t value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified uint16_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint16_t u = 42;
  ///   std::cout << "u " << is<uint16_t>(u) ? "is" : "isn't" << " uint16_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<uint16_t>(uint16_t value) {
    return true;
  }
    
  /// @brief Return true if specified value is the specified uint32_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint32_t u = 42;
  ///   std::cout << "u " << is<uint32_t>(u) ? "is" : "isn't" << " uint32_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<uint32_t>(uint32_t value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified uint64_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uint64_t u = 42;
  ///   std::cout << "u " << is<uint64_t>(u) ? "is" : "isn't" << " uint64_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<uint64_t>(uint64_t value) {
    return true;
  }
  
  /// @brief Return true if specified value is the specified uintptr_t. A Is expression takes the following form:
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// int main() {
  ///   uintptr_t u = 42;
  ///   std::cout << "u " << is<uintptr_t>(i) ? "is" : "isn't" << " uintptr_t" << endl;
  /// }
  /// @endcode
  /// @ingroup xtd_core
  template<>
  inline bool is<uintptr_t>(uintptr_t value) {
    return true;
  }

  template<typename type_t, typename param_t>
  bool is(const param_t* value) {
    try {
      if (value == nullptr) return false;
      return dynamic_cast<const type_t*>(value) != nullptr;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  template<typename type_t, typename param_t>
  bool is(const param_t& value) {
    return is<type_t>(&value);
  }
  
  template<typename type_t, typename param_t>
  bool is(param_t* value) {
    try {
      if (value == nullptr) return false;
      return dynamic_cast<const type_t*>(value) != nullptr;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  template<typename type_t, typename param_t>
  bool is(param_t& value) {
    return is<type_t>(&value);
  }
}
