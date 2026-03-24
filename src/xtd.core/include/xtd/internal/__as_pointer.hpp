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
  template<typename new_type, typename current_type>
  [[nodiscard]] auto as(const current_type& value) -> const new_type& {
    thread_local static __as_enum__<new_type, current_type, typename std::is_enum<current_type>::type> e;
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
  template<typename new_type, typename current_type>
  requires (!std::is_null_pointer_v<new_type>)
  [[nodiscard]] auto as(current_type& value) -> new_type& {
    thread_local static __as_enum__<new_type, current_type, typename std::is_enum<current_type>::type> e;
    return e.convert(value);
  }
  
  /// @cond
  template<typename new_type, typename current_type>
  requires std::is_null_pointer_v<new_type>
  [[nodiscard]] auto as(current_type& value) -> new_type& {
    if (!std::is_null_pointer_v<current_type>) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    return value;
  }
  /// @endcond

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
  template<typename new_type, typename current_type>
  [[nodiscard]] inline auto as(const current_type* value) -> const new_type* {
    return xtd::convert_pointer::to_ptr<new_type>(value);
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
  template<typename new_type, typename current_type>
  [[nodiscard]] auto as(current_type* value) -> new_type* {
    return xtd::convert_pointer::to_ptr<new_type>(value);
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
  template<typename new_type, typename current_type>
  [[nodiscard]] auto as(xtd::uptr<current_type>& value) -> xtd::uptr<new_type> {
    return xtd::convert_pointer::to_unique_ptr<new_type>(value);
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
  template<typename new_type, typename current_type>
  [[nodiscard]] auto as(xtd::uptr<current_type>&& value) -> xtd::uptr<new_type> {
    return xtd::convert_pointer::to_unique_ptr<new_type>(value);
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
  template<typename new_type, typename current_type>
  [[nodiscard]] auto as(const xtd::sptr<current_type>& value) -> xtd::sptr<new_type> {
    return xtd::convert_pointer::to_shared_ptr<new_type>(value);
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
  template<typename new_type, typename current_type>
  [[nodiscard]] auto as(xtd::sptr<current_type>& value) -> xtd::sptr<new_type> {
    return xtd::convert_pointer::to_shared_ptr<new_type>(value);
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
  template<typename new_type, typename current_type>
  [[nodiscard]] auto as(xtd::sptr<current_type>&& value) -> xtd::sptr<new_type> {
    return xtd::convert_pointer::to_shared_ptr<new_type>(value);
  }
}
