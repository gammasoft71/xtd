/// @file
/// @brief Contains xtd::convert class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "any.hpp"
#include "argument_null_exception.hpp"
#include "invalid_cast_exception.hpp"
#include "static.hpp"
#include "types.hpp"

/// @cond
template<typename new_type, typename current_type>
new_type* __convert_value__(current_type* value);
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents API to convert pointers.
  /// @par Header
  /// ```cpp
  /// #include <xtd/convert_pointer>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  class convert_pointer static_ {
  public:
    /// @name Public Static Methods
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// const button* value = new xtd::forms::button();
    /// const control* result = convert::to_ptr<xtd::forms::control>(value);
    /// ```
    template<typename new_type, typename current_type>
    static const new_type* to_ptr(const current_type* value) {
      if (value == nullptr) return nullptr;
      return &to_ref<new_type>(*value);
    }
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// button* value = new xtd::forms::button();
    /// control* result = convert::to_ptr<xtd::forms::control>(value);
    /// ```
    template<typename new_type, typename current_type>
    static new_type* to_ptr(current_type* value) {
      if (value == nullptr) return nullptr;
      return &to_ref<new_type>(*value);
    }
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// const button* value = new xtd::forms::button();
    /// const control* result = convert::to_ptr<xtd::forms::control>(value);
    /// ```
    template<typename new_type, typename current_type>
    static const new_type* to_ptr(const current_type& value) {
      return &to_ref<new_type>(value);
    }
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// button* value = new xtd::forms::button();
    /// control* result = convert::to_ptr<xtd::forms::control>(value);
    /// ```
    template<typename new_type, typename current_type>
    static new_type* to_ptr(current_type& value) {
      return &to_ref<new_type>(value);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::ptr<new_type> to_ptr(const xtd::ptr<current_type>& value) {
      return to_shared_ptr<new_type>(value);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::ptr<new_type> to_ptr(xtd::ptr<current_type>& value) {
      return to_shared_ptr<new_type>(value);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::ptr<new_type> to_ptr(xtd::ptr<current_type>&& value) {
      return to_shared_ptr<new_type>(std::move(value));
    }
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// const button* value = new xtd::forms::button();
    /// const control& result = convert::to_ref<xtd::forms::control>(*value);
    /// ```
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    template<typename new_type, typename current_type>
    static const new_type& to_ref(const current_type& value) {
      try {
        return dynamic_cast<const new_type&>(value);
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    }
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// button* value = new xtd::forms::button();
    /// control& result = convert::to_ref<xtd::forms::control>(*value);
    /// ```
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    template<typename new_type, typename current_type>
    static new_type& to_ref(current_type& value) {
      try {
        return dynamic_cast<new_type&>(value);
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    }
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// const button* value = new xtd::forms::button();
    /// const control& result = convert::to_ref<xtd::forms::control>(value);
    /// ```
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    template<typename new_type, typename current_type>
    static const new_type& to_ref(const current_type* value) {
      if (value == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
      try {
        return dynamic_cast<const new_type&>(*value);
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    }
    
    /// @brief Casts a type into another type.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @par Examples
    /// ```cpp
    /// button* value = new xtd::forms::button();
    /// control& result = convert::to_ref<xtd::forms::control>(value);
    /// ```
    /// @exception xtd::invalid_cast_exception the parameters is bad cast.
    template<typename new_type, typename current_type>
    static new_type& to_ref(current_type* value) {
      if (value == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
      try {
        return dynamic_cast<new_type&>(*value);
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::sptr<new_type> to_shared_ptr(const xtd::sptr<current_type>& value) {
      try {
        [[maybe_unused]] auto result = dynamic_cast<new_type&>(*value.get());
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      return std::dynamic_pointer_cast<new_type>(value.pointer());
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::sptr<new_type> to_shared_ptr(xtd::sptr<current_type>& value) {
      try {
        [[maybe_unused]] auto& result = dynamic_cast<new_type&>(*value.get());
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      return std::dynamic_pointer_cast<new_type>(value.pointer());
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::sptr<new_type> to_shared_ptr(xtd::sptr<current_type>&& value) {
      try {
        [[maybe_unused]] auto& result = dynamic_cast<new_type&>(*value.get());
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      //return std::move(value);
      return std::dynamic_pointer_cast<new_type>(std::move(value.pointer()));
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::sptr<new_type> to_sptr(const xtd::sptr<current_type>& value) {
      return to_shared_ptr<new_type>(value);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::sptr<new_type> to_sptr(xtd::sptr<current_type>& value) {
      return to_shared_ptr<new_type>(value);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::sptr<new_type> to_sptr(xtd::sptr<current_type>&& value) {
      return to_shared_ptr<new_type>(std::move(value));
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::uptr<new_type> to_unique_ptr(xtd::uptr<current_type>& value) {
      auto ptr = value.release();
      try {
        return xtd::uptr<new_type>(__convert_value__<new_type>(ptr));
      } catch (const std::exception& e) {
        value = xtd::uptr<current_type>(ptr);
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::uptr<new_type> to_unique_ptr(xtd::uptr<current_type>&& value) {
      auto ptr = value.release();
      try {
        return xtd::uptr<new_type>(__convert_value__<new_type>(ptr));
      } catch (const std::exception& e) {
        value = xtd::uptr<current_type>(ptr);
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::uptr<new_type> to_uptr(xtd::uptr<current_type>& value) {
      return to_unique_ptr<new_type>(value);
    }
    
    /// @brief Casts a type into another type.
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
    static xtd::uptr<new_type> to_uptr(xtd::uptr<current_type>&& value) {
      return to_unique_ptr<new_type>(std::move(value));
    }
    /// @}
  };
}
