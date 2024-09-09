/// @file
/// @brief Contains xtd::array_object class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <array> or <array.h> instead."
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief Base object that represent array.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  class array_object : public xtd::object {
    template<typename type_t, typename allocator_t>
    friend class basic_array;
    
  public:
    array_object() = default;
  };
}
