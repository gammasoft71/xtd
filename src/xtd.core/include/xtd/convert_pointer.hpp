/// @file
/// @brief Contains xtd::convert class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "any.hpp"
#include "argument_null_exception.hpp"
#include "invalid_cast_exception.hpp"
#include "static.hpp"
#include "types.hpp"
#include "unused.hpp"

/// @cond
template<class new_type_t, class current_type_t>
new_type_t* __convert_value__(current_type_t* value);
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
    template<class new_type_t, class current_type_t>
    inline static const new_type_t* to_ptr(const current_type_t* value) {
      if (value == nullptr) return nullptr;
      return &to_ref<new_type_t>(*value);
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
    template<class new_type_t, class current_type_t>
    inline static new_type_t* to_ptr(current_type_t* value) {
      if (value == nullptr) return nullptr;
      return &to_ref<new_type_t>(*value);
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
    template<class new_type_t, class current_type_t>
    inline static const new_type_t* to_ptr(const current_type_t& value) {
      return &to_ref<new_type_t>(value);
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
    template<class new_type_t, class current_type_t>
    inline static new_type_t* to_ptr(current_type_t& value) {
      return &to_ref<new_type_t>(value);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::ptr<new_type_t> to_ptr(const xtd::ptr<current_type_t>& value) {
      return to_shared_ptr<new_type_t>(value);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::ptr<new_type_t> to_ptr(xtd::ptr<current_type_t>& value) {
      return to_shared_ptr<new_type_t>(value);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::ptr<new_type_t> to_ptr(xtd::ptr<current_type_t>&& value) {
      return to_shared_ptr<new_type_t>(std::move(value));
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
    template<class new_type_t, class current_type_t>
    inline static const new_type_t& to_ref(const current_type_t& value) {
      try {
        return dynamic_cast<const new_type_t&>(value);
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
    template<class new_type_t, class current_type_t>
    inline static new_type_t& to_ref(current_type_t& value) {
      try {
        return dynamic_cast<new_type_t&>(value);
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
    template<class new_type_t, class current_type_t>
    inline static const new_type_t& to_ref(const current_type_t* value) {
      if (value == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
      try {
        return dynamic_cast<const new_type_t&>(*value);
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
    template<class new_type_t, class current_type_t>
    inline static new_type_t& to_ref(current_type_t* value) {
      if (value == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
      try {
        return dynamic_cast<new_type_t&>(*value);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::sptr<new_type_t> to_shared_ptr(const xtd::sptr<current_type_t>& value) {
      try {
        unused_(dynamic_cast<new_type_t&>(*value.get()));
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      return std::dynamic_pointer_cast<new_type_t>(value.pointer());
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
    template<class new_type_t, class current_type_t>
    inline static xtd::sptr<new_type_t> to_shared_ptr(xtd::sptr<current_type_t>& value) {
      try {
        unused_(dynamic_cast<new_type_t&>(*value.get()));
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      return std::dynamic_pointer_cast<new_type_t>(value.pointer());
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
    template<class new_type_t, class current_type_t>
    inline static xtd::sptr<new_type_t> to_shared_ptr(xtd::sptr<current_type_t>&& value) {
      try {
        unused_(dynamic_cast<new_type_t&>(*value.get()));
      } catch (const std::exception& e) {
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }
      //return std::move(value);
      return std::dynamic_pointer_cast<new_type_t>(std::move(value.pointer()));
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
    template<class new_type_t, class current_type_t>
    inline static xtd::sptr<new_type_t> to_sptr(const xtd::sptr<current_type_t>& value) {
      return to_shared_ptr<new_type_t>(value);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::sptr<new_type_t> to_sptr(xtd::sptr<current_type_t>& value) {
      return to_shared_ptr<new_type_t>(value);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::sptr<new_type_t> to_sptr(xtd::sptr<current_type_t>&& value) {
      return to_shared_ptr<new_type_t>(std::move(value));
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
    template<class new_type_t, class current_type_t>
    inline static xtd::uptr<new_type_t> to_unique_ptr(xtd::uptr<current_type_t>& value) {
      auto ptr = value.release();
      try {
        return xtd::uptr<new_type_t>(__convert_value__<new_type_t>(ptr));
      } catch (const std::exception& e) {
        value = xtd::uptr<current_type_t>(ptr);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::uptr<new_type_t> to_unique_ptr(xtd::uptr<current_type_t>&& value) {
      auto ptr = value.release();
      try {
        return xtd::uptr<new_type_t>(__convert_value__<new_type_t>(ptr));
      } catch (const std::exception& e) {
        value = xtd::uptr<current_type_t>(ptr);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::uptr<new_type_t> to_uptr(xtd::uptr<current_type_t>& value) {
      return to_unique_ptr<new_type_t>(value);
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
    template<class new_type_t, class current_type_t>
    inline static xtd::uptr<new_type_t> to_uptr(xtd::uptr<current_type_t>&& value) {
      return to_unique_ptr<new_type_t>(std::move(value));
    }
    /// @}
  };
}
