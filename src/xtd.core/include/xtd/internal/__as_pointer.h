/// @file
/// @brief Contains xtd::as method.
#pragma once

/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// const button* value = new xtd::forms::button();
  /// const control& result = as<xtd::forms::control>(*value);
  /// ```
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  const new_type_t& as(const current_type_t& value) {
    thread_local static __as_enum__<new_type_t, current_type_t, typename std::is_enum<current_type_t>::type> e;
    return e.convert(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// button* value = new xtd::forms::button();
  /// control& result = as<xtd::forms::control>(*value);
  /// ```
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  new_type_t& as(current_type_t& value) {
    thread_local static __as_enum__<new_type_t, current_type_t, typename std::is_enum<current_type_t>::type> e;
    return e.convert(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// const button* value = new xtd::forms::button();
  /// const control* result = as<xtd::forms::control>(value);
  /// ```
  template<typename new_type_t, typename current_type_t>
  const new_type_t* as(const current_type_t* value) {
    return xtd::convert_pointer::to_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// button* value = new xtd::forms::button();
  /// control* result = as<xtd::forms::control>(value);
  /// ```
  template<typename new_type_t, typename current_type_t>
  new_type_t* as(current_type_t* value) {
    return xtd::convert_pointer::to_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::uptr<button> value = xtd::new_uptr<xtd::forms::button>();
  /// xtd::uptr<control> result = as<xtd::forms::control>(value);
  /// ```
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  xtd::uptr<new_type_t> as(xtd::uptr<current_type_t>& value) {
    return xtd::convert_pointer::to_unique_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::uptr<control> result = as<xtd::forms::control>(xtd::new_uptr<xtd::forms::button>());
  /// ```
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  xtd::uptr<new_type_t> as(xtd::uptr<current_type_t>&& value) {
    return xtd::convert_pointer::to_unique_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// const xtd::sptr<button> value = xtd::new_sptr<xtd::forms::button>();
  /// const xtd::sptr<control> result = as<xtd::forms::control>(value);
  /// ```
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  xtd::sptr<new_type_t> as(const xtd::sptr<current_type_t>& value) {
    return xtd::convert_pointer::to_shared_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::sptr<control> result = as<xtd::forms::control>(xtd::new_sptr<xtd::forms::button>());
  /// ```
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  xtd::sptr<new_type_t> as(xtd::sptr<current_type_t>& value) {
    return xtd::convert_pointer::to_shared_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// const xtd::sptr<button> value = xtd::new_sptr<xtd::forms::button>();
  /// const xtd::sptr<control> result = as<xtd::forms::control>(value);
  /// ```
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  xtd::sptr<new_type_t> as(xtd::sptr<current_type_t>&& value) {
    return xtd::convert_pointer::to_shared_ptr<new_type_t>(value);
  }
}
