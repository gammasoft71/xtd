/// @file
/// @brief Contains xtd::array_abstract_object class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/array> or <xtd/array.h> instead."
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief Abstract object that represent array.
  /// @par Definition
  /// ```cpp
  /// class array_abstract_object abstract_;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/array>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  class array_abstract_object abstract_ {
    template<typename type_t, typename allocator_t>
    friend class basic_array;
    
  private:
    array_abstract_object() = default;
  };
}
